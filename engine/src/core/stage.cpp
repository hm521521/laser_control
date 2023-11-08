#include "stage.h"
#include <cmath>

stage::stage(QWidget *parent)
    :m_laser_device(nullptr)
    ,OutputDebug(false)
{

}

void stage::set_config(Configuration *config)
{
    m_config=config;
}

void stage::set_device(laser_device *dev)
{
    if(m_laser_device!=nullptr)
    {
        m_laser_device=nullptr;
    }
    m_laser_device=dev;

//    if(m_laser_device==nullptr)
//    {
//        stage_thread.quit();
//    }
}

void stage::add_send_data(std::vector<ishow_data> &list)
{
    if(m_laser_device==nullptr||OutputDebug)
        return;
    this->m_output_data_list.push_back(list);
//    this->moveToThread(&stage_thread);
//    connect(&stage_thread,&QThread::started,this,&stage::do_send_data);
//    connect(this,&stage::stage_finish,&stage_thread,&QThread::quit);
//    stage_thread.start();
    do_send_data();
}

stage::~stage()
{

}

void stage::do_send_data()//发送数据给下位机
{
    unsigned char settings_data[8]={0};
    std::vector<unsigned char> send_data;
    send_data.clear();
    int dst=0;//从3个像素抽一个点增加，每次增加1个像素
    {
        if(this->OutputDebug)
        {
            for(int i=0;i<m_debug_data_list.size();++i)
            {
                auto _d=m_debug_data_list.at(i);
                send_data.push_back(_d.x);
                send_data.push_back(_d.y);
                send_data.push_back(_d.red);
                send_data.push_back(_d.gray);
                send_data.push_back(_d.blue);
                send_data.push_back(_d.green);
            }
        }
        else
        {
            if(this->m_output_data_list.size()>0)
            {
                if(this->m_output_data_list[0].size()<1)
                {
                    this->m_output_data_list.erase(this->m_output_data_list.begin());
                }
                else
                {
                    auto& d=this->m_output_data_list.front();
                    auto _d=d.at(0);
//                    int n=0;
//                    if(abs(_d.x-last_send_data.at(0))>100||abs(_d.y-last_send_data.at(1))>100)//与前一个点距离超过25个像素就加消隐点
//                        n=std::max(_d.x,_d.y)/100;
//                    if(n>1)//一帧的初始点增加n插值点
//                    {
//                        for(int i=0;i<n;i++)
//                        {
//                            float pro=(float)i/n;
//                            float pro_x=pro*(_d.x-last_send_data.at(0));
//                            float pro_y=pro*(_d.y-last_send_data.at(1));
//                            send_data.push_back(last_send_data.at(0)+pro_x);
//                            send_data.push_back(last_send_data.at(1)+pro_y);
//                            send_data.push_back(0);
//                            send_data.push_back(0);
//                            send_data.push_back(0);
//                            send_data.push_back(0);
//                        }
                    last_send_data={_d.x,_d.y,_d.red,_d.gray,_d.blue,_d.green};
//                    }
                    for(int i=0;i<d.size();++i)
                    {
                        auto _d=d.at(i);
                        int n=0;
                        if(abs(_d.x-last_send_data.at(0))>25||abs(_d.y-last_send_data.at(1))>25)//与前一个点距离超过25个像素就加消隐点
//                            n=std::max(_d.x,_d.y)/25;
                            n=2;
                        if(n>1)//一帧的初始点增加插值点
                        {
                            for(int j=1;j<n;j++)
                            {
                                float pro=(float)j/n;
                                float pro_x=pro*(_d.x-last_send_data.at(0));
                                float pro_y=pro*(_d.y-last_send_data.at(1));
                                send_data.push_back(last_send_data.at(0)+pro_x);
                                send_data.push_back(last_send_data.at(1)+pro_y);
                                send_data.push_back(0);
                                send_data.push_back(0);
                                send_data.push_back(0);
                                send_data.push_back(0);
                            }
                        }
                        send_data.push_back(_d.x);
                        send_data.push_back(_d.y);
                        send_data.push_back(_d.red);
                        send_data.push_back(_d.gray);
                        send_data.push_back(_d.blue);
                        send_data.push_back(_d.green);
//                        if(i==d.size()-1)
                        last_send_data={_d.x,_d.y,_d.red,_d.gray,_d.blue,_d.green};
                    }
                    this->m_output_data_list.erase(this->m_output_data_list.begin());
                }
            }
        }
    }
    if(send_data.size()!=0)
    {
        settings_data[0] = static_cast<unsigned char>(m_config->Speed * 2);
        settings_data[1] = static_cast<unsigned char>(m_config->PointGap);
        settings_data[2] = m_config->Delay;
        settings_data[3] = 0;
        int posnum=send_data.size();
        do
        {
            if(send_data.size()>1620*2)//点数超过270的二倍，就隔几个点抽一次
            {
                float temp=send_data.size()/6;
                int ratio=floor(temp/270);
                for(int i=send_data.size()/6-1;i>-1;i--)
                {
                    if((send_data.at(i*6+2)==0)&&(send_data.at(i*6+3)==0)&&(send_data.at(i*6+4)==0)&&(send_data.at(i*6+5)==0))//保证消隐点不被减掉
                        continue;
                    if(i%ratio==0)
                    {
                        for(int j=5;j>-1;j--)
                        {
                            send_data.erase(send_data.begin()+i*6+j);
                        }
                    }
                }
             }
            else//点数不超过270的按点的距离抽点
            {
                CJPoint lp;
                lp.X=send_data.at(send_data.size()-6);
                lp.Y=send_data.at(send_data.size()-6+1);
                CJPoint cp;
                for(int i=send_data.size()/6-1;i>-1;i--)
                {
                    cp.X=send_data.at(i*6);
                    cp.Y=send_data.at(i*6+1);
                    if((send_data.at(i*6+2)==0)&&(send_data.at(i*6+3)==0)&&(send_data.at(i*6+4)==0)&&(send_data.at(i*6+5)==0))
                        continue;
                    if(abs(cp.X-lp.X)<3+dst&&abs(cp.Y-lp.Y)<3+dst)
                    {
                        for(int j=5;j>-1;j--)
                        {
                            send_data.erase(send_data.begin()+i*6+j);
                        }
                    }
                    else
                    {
                        lp=cp;
                    }
                }
            }
            dst++;
        }while(send_data.size()>1620);
        if((send_data.size()<1620)&&(send_data.size()>5))//如果一帧数据少于270个点
        {
            for(int i=send_data.size()/6;i<270;i++)//不够270个点补齐
            {
                for(int j=0;j<6;j++)
                {
                    unsigned char x=send_data.at((i-1)*6+j);
                    send_data.push_back(x);
                }
            }
            m_laser_device->send_data(settings_data, send_data,send_data_state::sd_begin_end,posnum);
            send_data.erase(send_data.begin(),send_data.begin()+1620);
        }


    }
//    stage_thread.quit();
}

bool stage::test_output()
{
    return this->OutputDebug;
}

laser_device *stage::get_device()
{
    return m_laser_device;
}

///////////////////////////////////////////////////////
//stage_work_thread::stage_work_thread(stage *output)
//    :m_stage(output)
//{

//}

//stage_work_thread::~stage_work_thread()
//{
//    requestInterruption();
//    quit();
//    wait();
//}

//void stage_work_thread::run()
//{
////    double next_frame=0;

//    while (!isInterruptionRequested()) {
//        m_stage->do_send_data();//发送一个点
//    }

//}

//void stage_work_thread::pause()
//{
//    m_lock.lock();
////    QMutexLocker locker(&m_lock);
//}

//void stage_work_thread::resume()
//{
//    m_lock.unlock();
//}



