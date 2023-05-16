#include "stage.h"
//#include<QMutexLocker>



//stage::stage(Configuration *config)
//    :OutputDebug(false)
//    ,m_laser_device(nullptr)
//    ,m_config(config)

//{
//    m_work_thread=new stage_work_thread(this);
//    m_work_thread->start();
//    if(!m_work_thread->isRunning())
//    {
//        delete m_work_thread;
//        m_work_thread=nullptr;
//    }
//    if(m_work_thread)
//        m_work_thread->pause();
//}

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
    QVector<unsigned char> send_data;
    send_data.clear();
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
//            if(this->m_output_data_list.size()>0)

                    auto& d=this->m_output_data_list.front();
                    for(int i=0;i<d.size();++i)
                    {
                        auto _d=d.at(i);
                        send_data.push_back(_d.x);
                        send_data.push_back(_d.y);
                        send_data.push_back(_d.red);
                        send_data.push_back(_d.gray);
                        send_data.push_back(_d.blue);
                        send_data.push_back(_d.green);
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
        if(send_data.size()<1024)
            m_laser_device->send_data(settings_data, send_data);
        else
        {
            int times=send_data.size()/1024;
            for(int i=0;i<times+1;i++)
            {
                QVector<unsigned char> send_data_i=send_data.mid(i*1024,1024);
                m_laser_device->send_data(settings_data,send_data_i);
            }
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



