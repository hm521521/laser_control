#include "system_fileio.h"

#include <QUrl>
#include <QDebug>
#include <fstream>
#include "constants.h"

System_FileIO::System_FileIO(System_CueWsManager* wsMgr, System_CueManager* cueMgr, QObject *parent)
    : QObject{parent}
{
    m_cueWsManager = wsMgr;
    m_cueManager = cueMgr;
}

void System_FileIO::loadWorkspace(QUrl url)
{
    QString filepath=url.path();
    loadWorkspace(filepath);
}

void System_FileIO::loadWorkspace(QString filepath)
{
    qDebug()<<filepath;
    std::ifstream strin;
    strin.open(filepath.toStdString(),std::ios::in | std::ios::binary);
    if(!strin.is_open())
    {
        return;
    }
    unsigned char str_len=0;
    strin>>str_len;
    if(str_len==strlen(SCENE_POOL_HEADER))
    {
        m_cueWsManager->clearWorkspace();//清空当前工作区
        char file_header[128]={0};
        //        in>>file_header;
        //        strin.readRawData(file_header,str_len);
        strin.read(file_header,str_len);
        if(0==strcmp(file_header,SCENE_POOL_HEADER))
        {
            int cnt = 0;
            auto category = m_cueWsManager->addCategory();
            while(!strin.eof()&&cnt<40)//如果strin没结束并且未到达40个scene就继续读
            {
                //                try{
                int str_len=0;
                strin.read((char*)&str_len,sizeof(unsigned char));
                if(str_len!=strlen(SCENE_HEADER))
                {
                    continue;
                }

                char scene_header[128]={0};
                strin.read(scene_header,str_len);
                if(0 != strcmp(scene_header, SCENE_HEADER))
                {
                    continue;
                }
                //                qDebug()<<strcmp(scene_header, SCENE_HEADER);
                str_len=0;
                strin.read((char*)&str_len,sizeof(unsigned char));
                char scene_name[128] = { 0 };
                strin.read(scene_name,str_len);

                auto page = m_cueWsManager->addPage(QString(scene_name),category);
                int effect_count = 0;
                strin.read((char*)&effect_count, sizeof(int));
                qDebug()<<effect_count;
                for (int i = 0; i < effect_count; i++)
                {
                    //                    effect* m_effect = effect::LoadEffect(br);
                    //                    this->push_back(effect);
                    //EffectType type=EffectType::ET_PICTURE;//初始化一个type
                    int type;
                    int idx = 0;
                    int start_frame_index = 0;
                    int frame_length = 0;
                    strin.read((char*)&type,sizeof(int));
                    strin.read((char*)&idx,sizeof(int));
                    strin.read((char*)&start_frame_index,sizeof(int));
                    strin.read((char*)&frame_length,sizeof(int));
                    //PictureInfo temp_var(type,idx);
                    //m_effect=effect::CreateEffect(&temp_var);
                    //if(m_effect !=nullptr)


                    int param;
                    strin.read((char*)&param,sizeof(int));
                    strin.read((char*)&param,sizeof(int));
                    strin.read((char*)&param,sizeof(int));
                    strin.read((char*)&param,sizeof(int));
                    int picture_count=0;
                    strin.read((char*)&picture_count, sizeof(int));//读图片数量，.isw文件里有的
                    qDebug()<<"pic "<<picture_count;
                    //m_effect->Load();
                    //                        m_effect->get_pictures().clear();//把当前效果对象的m_pictures清空，m_pictures是CJImage类型，CJImage是容器

                    //CJImage m_pictures=m_effect->get_pictures();

                    QVector<LaserFrame> frames;
                    for (int k = 0; k < picture_count; k++)
                    {
                        LaserFrame  frame;
                        int point_count = 0;//读第一幅图点的数量
                        strin.read((char*)&point_count, sizeof(int));
                        qDebug()<<"     p "<<point_count;
                        //CJSection list;//定义点属性列表（一张图的所有点）
                        for (int l = 0; l < point_count; l++)//读每个点的信息
                        {

                            int x = 0;//点的横坐标
                            int y = 0;//点的纵坐标
                            //点的三个通道的值
                            unsigned char r = 0;
                            unsigned char g = 0;
                            unsigned char b = 0;
                            strin.read((char*)&x, sizeof(int));
                            strin.read((char*)&y, sizeof(int));
                            strin.read((char*)&r, sizeof(unsigned char));
                            strin.read((char*)&g, sizeof(unsigned char));
                            strin.read((char*)&b, sizeof(unsigned char));
                            //PointAttribute tempVar(x, y, 0, r, g, b);//把读到的点的信息存入临时点的属性对象
                            //list.push_back(tempVar);
                            frame.push_back(LaserPoint(x,y,0,r,g,b));
                        }
                        frames.push_back(frame);
                    }
                    //                        m_effect->set_pictures(m_pictures);
                    //                        m_effect->set_type(type);
                    //                        m_effect->set_index(idx);
                    //                        m_effect->set_start_index(start_frame_index);
                    //                        m_effect->set_frame_length(frame_length);
                    //                        m_pictures.clear();


                    //                    m_scene->push_back(m_effect);
                    auto cue = m_cueManager->createCue(frames);
                    m_cueWsManager->setCue(page, i, cue);

                }
                //this->push_back(m_scene);
                cnt++;
            }
            //total_page++;
            int scene_count=0;
            while(!strin.eof())
            {
                strin.ignore(4096,strlen(SCENE_HEADER));
                char scene_header[128]={0};
                strin.read(scene_header,strlen(SCENE_HEADER));
                if(0 != strcmp(scene_header, SCENE_HEADER))
                {
                    continue;
                }
                scene_count++;
                if(scene_count>40)
                {
                    scene_count=1;
                    //total_page++;
                }
            }
            //if(scene_count!=0)
            //total_page++;
        }
    }
    strin.close();
    emit m_cueWsManager->workspaceChanged();
}
