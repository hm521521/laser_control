#include "system_devicesmanager.h"

System_DevicesManager::System_DevicesManager(QObject *parent)
    : QObject{parent}
{
    m_laser_device_manager=new laser_device_manager(this);
    //创建一个硬件管理器
    m_conf=new Configuration();//投影区域配置
    m_conf->Load();
    stage *s=new stage(this);
    s->set_config(m_conf);
    s->set_device(m_laser_device_manager->get_default_device());
    if(s->get_device()!=nullptr)
    {
        m_stagesList.push_back(s);
    }
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector)),this,SLOT(refresh_stage(std::vector)));
}

void System_DevicesManager::refresh_stages(std::vector<laser_device *> device_list)
{
    m_stagesList.clear();
    for(int i=0;i<device_list.size();i++)
    {
        stage *s=new stage(this);
        s->set_config(m_conf);
        s->set_device(device_list.at(i));
        m_stagesList.push_back(s);
    }
}
