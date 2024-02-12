#include "scene_pool.h"
#include<QFile>
//#include"scene.h"
#include<iostream>
#include<fstream>
#include"pointattribute.h"
#include<QDebug>
#include<QDataStream>
constexpr auto SCENE_POOL_HEADER = "hwqi";//常量表达式“hwqi”
constexpr auto SCENE_HEADER = "hwoneshow";

scene_pool::scene_pool(QWidget *parent)
    :m_scene(nullptr),
      m_effect(nullptr)
{

}

scene_pool::~scene_pool()
{
    this->clearup();
}

void scene_pool::read(QUrl url)
{
    this->clear();
    total_page = 0;
    QString filepath=url.path();
    filepath.remove(0,1);
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
        char file_header[128]={0};
        strin.read(file_header,str_len);
        if(0==strcmp(file_header,SCENE_POOL_HEADER))
        {
            while(!strin.eof()&&this->size()<40)//如果strin没结束并且未到达40个scene就继续读
            {
                m_scene=new single_scene();
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
                str_len=0;
                strin.read((char*)&str_len,sizeof(unsigned char));
                char scene_name[128] = { 0 };
                strin.read(scene_name,str_len);
                m_scene->setname(scene_name);
                int effect_count = 0;
                strin.read((char*)&effect_count, sizeof(int));
                for (int i = 0; i < effect_count; i++)
                {
                      EffectType type=EffectType::ET_PICTURE;//初始化一个type
                      int idx = 0;
                      int start_frame_index = 0;
                      int frame_length = 0;
                      strin.read((char*)&type,sizeof(int));
                      strin.read((char*)&idx,sizeof(int));
                      strin.read((char*)&start_frame_index,sizeof(int));
                      strin.read((char*)&frame_length,sizeof(int));
                      PictureInfo temp_var(type,idx);
                      m_effect=effect::CreateEffect(&temp_var);
                    if(m_effect !=nullptr)
                    {
                        strin.read((char*)&m_effect->Param.param_data[0],sizeof(int));
                        strin.read((char*)&m_effect->Param.param_data[1],sizeof(int));
                        strin.read((char*)&m_effect->Param.param_data[2],sizeof(int));
                        strin.read((char*)&m_effect->Param.param_data[3],sizeof(int));
                        int picture_count=0;
                        strin.read((char*)&picture_count, sizeof(int));//读图片数量，.isw文件里有的
                        m_effect->Load();
                        CJImage m_pictures=m_effect->get_pictures();
                        for (int k = 0; k < picture_count; k++)
                        {
                            int point_count = 0;//读第一幅图点的数量
                            strin.read((char*)&point_count, sizeof(int));
                            CJSection list;//定义点属性列表（一张图的所有点）
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
                                PointAttribute tempVar(x, y, 0, r, g, b);//把读到的点的信息存入临时点的属性对象
                                list.push_back(tempVar);
                            }
                            m_pictures.push_back(list);
                        }
                        m_effect->set_pictures(m_pictures);
                        m_effect->set_type(type);
                        m_effect->set_index(idx);
                        m_effect->set_start_index(start_frame_index);
                        m_effect->set_frame_length(frame_length);
                        m_pictures.clear();
                    }
                    m_scene->push_back(m_effect);
                }
                this->push_back(m_scene);
            }
            total_page++;
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
                    total_page++;
                }
            }
            if(scene_count!=0)
                total_page++;
        }
    }
    strin.close();
}

void scene_pool::readSinglePage(QUrl url, int page)
{
    this->clear();
    int temp=page*40;
    QString filepath=url.path();
    filepath.remove(0,1);
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
        char file_header[128]={0};
        strin.read(file_header,str_len);
        if(0!=strcmp(file_header,SCENE_POOL_HEADER))
            return;
        int scene_count=0;
        while (!strin.eof())
        {
            if(scene_count<temp)
            {
                strin.ignore(4096,strlen(SCENE_HEADER));
                char scene_header[128]={0};
                strin.read(scene_header,strlen(SCENE_HEADER));
                if(0 != strcmp(scene_header, SCENE_HEADER))
                {
                    continue;
                }
                scene_count++;
            }
            else if(scene_count<temp+40)
            {
                strin.ignore(4096, strlen(SCENE_HEADER));
                m_scene=new single_scene();
                char scene_header[128] = { 0 };
                strin.read(scene_header, strlen(SCENE_HEADER));
                if (0 != strcmp(scene_header, SCENE_HEADER))
                {
                    continue;
                }
                str_len=0;
                strin.read((char*)&str_len,sizeof(unsigned char));
                char scene_name[128] = { 0 };
                strin.read(scene_name,str_len);
                m_scene->setname(scene_name);
                int effect_count = 0;
                strin.read((char*)&effect_count, sizeof(int));
                for (int i = 0; i < effect_count; i++)
                {
                      EffectType type=EffectType::ET_PICTURE;//初始化一个type
                      int idx = 0;
                      int start_frame_index = 0;
                      int frame_length = 0;
                      strin.read((char*)&type,sizeof(int));
                      strin.read((char*)&idx,sizeof(int));
                      strin.read((char*)&start_frame_index,sizeof(int));
                      strin.read((char*)&frame_length,sizeof(int));
                      PictureInfo temp_var(type,idx);
                      m_effect=effect::CreateEffect(&temp_var);
                    if(m_effect !=nullptr)
                    {
                        strin.read((char*)&m_effect->Param.param_data[0],sizeof(int));
                        strin.read((char*)&m_effect->Param.param_data[1],sizeof(int));
                        strin.read((char*)&m_effect->Param.param_data[2],sizeof(int));
                        strin.read((char*)&m_effect->Param.param_data[3],sizeof(int));
                        int picture_count=0;
                        strin.read((char*)&picture_count, sizeof(int));//读图片数量，.isw文件里有的
                        m_effect->Load();
                        CJImage m_pictures=m_effect->get_pictures();
                        for (int k = 0; k < picture_count; k++)
                        {
                            int point_count = 0;//读第一幅图点的数量
                            strin.read((char*)&point_count, sizeof(int));
                            CJSection list;//定义点属性列表（一张图的所有点）
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
                                PointAttribute tempVar(x, y, 0, r, g, b);//把读到的点的信息存入临时点的属性对象
                                list.push_back(tempVar);
                            }
                            m_pictures.push_back(list);
                        }
                        m_effect->set_pictures(m_pictures);
                        m_effect->set_type(type);
                        m_effect->set_index(idx);
                        m_effect->set_start_index(start_frame_index);
                        m_effect->set_frame_length(frame_length);
                        m_pictures.clear();
                    }
                    m_scene->push_back(m_effect);
                }
                this->push_back(m_scene);
                scene_count++;
            }
            else
            {
                break;
            }
        }
    }
    strin.close();
}

void scene_pool::clearup()
{
    for (auto& scene : *this)
    {
        delete scene;
    }
    this->clear();

}


single_scene::single_scene()
{

}

single_scene::~single_scene()
{
    this->clearup();
}

void single_scene::setname(QString name)
{
    m_name=name;
}

void single_scene::render(CJSection *section, int time)//保存数据到section,最终根据z2调整section中所有点的X值和Y值，time代表当前的索引值
{
    if (section==nullptr)
        return;

    CJSection temp_section;
    int num=0;
    for (int i=0;i<this->size();i++)
    {
        effect *m_effect=this->at(i);
        if (m_effect->get_type()<EffectType::ET_BLACK)
        {
            if(num!=m_effect->get_index())
            {
                num=m_effect->get_index();
                section->insert(section->end(),temp_section.begin(),temp_section.end());
                temp_section.clear();
            }
            m_effect->render(temp_section,time);
        }
        else
        {
            m_effect->render(temp_section,time);
        }
    }
    //如果获取到的索引是0，就是说this->size()=0
    section->insert(section->end(),temp_section.begin(),temp_section.end());
    for(int j=0;j<section->size();j++)
    {
        section->at(j).move_by_z2();
    }

}

int single_scene::max_frame_length()
{
    int num=0;
    for(int i=0; i<this->size(); i++)
    {
        if(this->at(i)->max_frame_length()>num)
        {
            num=this->at(i)->max_frame_length();
        }
    }
    return num;
}

QString single_scene::get_name()
{
    return m_name;
}

void single_scene::clearup()
{
    for (auto& obj : *this)
    {
        delete obj;
    }
    this->clear();
}



