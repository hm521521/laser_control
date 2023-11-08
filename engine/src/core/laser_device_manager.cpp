#include "laser_device_manager.h"
#include "laser_output.h"
#include "ed_laser_output.h"


laser_device_manager::laser_device_manager(QObject *parent)
    :m_device_finder(nullptr)
{
//    m_device_list.push_back(new ishow_laser_device(0));//建一个ishow_laser_device接收tcpsocket
    m_device_finder=new ed_v2_device_finder(this);
    settings=new QSettings("./system/hardware_list.ini",QSettings::IniFormat);
    load_hardware_list();
}

laser_device_manager::~laser_device_manager()
{

}
void laser_device_manager::load_hardware_list()
{
    QSettings *s=new QSettings("./system/hardware_list.ini",QSettings::IniFormat);
    int size=s->beginReadArray("hardware_list");
//    std::vector<laser_device*> m_device_list;
    for(int i=0;i<size;++i)
    {
        s->setArrayIndex(i);
        qDebug()<<s->value("laser_type").value<laser_type>();
        if(s->value("laser_type").value<laser_type>()==laser_type::lt_edv2)//添加设备并连接该设备的7765端口
        {
            ed_v2_device* dev=new ed_v2_device(s->value("tcp_addr").toString());
            m_device_list.push_back(dev);
            dev->try_connect();
        }
        else if(s->value("laser_type").value<laser_type>()==laser_type::lt_ishow)
        {
            ishow_laser_device* dev=new ishow_laser_device(s->value("tcp_addr").toString());
            m_device_list.push_back(dev);
            dev->try_connect();
        }
    }
    s->endArray();
}

laser_device *laser_device_manager::get_default_device()
{
    std::lock_guard<std::mutex> lock(this->m_lock_obj);
    if(m_device_list.size()>0)
        return m_device_list[0];
    return nullptr;
}

void laser_device_manager::add_device(laser_type t, QString addr)
{
//    std::lock_guard<std::mutex> lock(this->m_lock_obj);
//    emit manager_changed(m_device_list);
    for(int i=0;i<m_device_list.size();++i)
    {
        auto obj=m_device_list.at(i);
        if(obj!=nullptr)
        {
            if(obj->is_create_by(addr))
            {
                //断线重发现，连接
                if(obj->is_connected()==false)
                    obj->try_connect();
                return;
            }
        }
    }
    if(t==laser_type::lt_edv2)//添加设备并连接该设备的7765端口
    {
        ed_v2_device* dev=new ed_v2_device(addr);
        dev->set_laser_type(laser_type::lt_edv2);
        m_device_list.push_back(dev);
        dev->try_connect();
        emit manager_changed(m_device_list);
        emit new_device(dev);
    }
    if(!settings)
        return;
    settings->beginWriteArray("hardware_list");
    for(int i=0;i<m_device_list.size();++i)
    {
        settings->setArrayIndex(i);
        settings->setValue("tcp_addr",m_device_list[i]->get_name());
        int it=m_device_list[i]->get_laser_type();
        settings->setValue("laser_type",it);
    }
    settings->endArray();
}

std::vector<laser_device *> laser_device_manager::get_device_list()
{
    return m_device_list;
}

int laser_device_manager::get_device_number()
{
    return m_device_list.size();
}

void laser_device_manager::refresh_laser_device()
{
    m_device_finder->broadcast();
}


laser_device::laser_device(QString name)
    :m_name(name)
{

}

laser_device::~laser_device()
{

}

QString laser_device::get_name()
{
    return m_tcp_addr;

}

laser_type laser_device::get_laser_type()
{
    return m_laser_type;
}

void laser_device::set_laser_type(laser_type lt)
{
    m_laser_type=lt;
}


