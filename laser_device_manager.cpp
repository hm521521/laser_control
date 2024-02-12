#include "laser_device_manager.h"
//#include "laser_output.h"
#include "ed_laser_output.h"

QString getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            localIP=aHost.toString();
            break;
        }
    }
    return localIP;
}


laser_device_manager::laser_device_manager(QObject *parent):
    m_udpsocket(nullptr),
    m_tcpserver(nullptr)
{
    m_udpsocket=new QUdpSocket(this);
    connect(m_udpsocket,SIGNAL(readyRead()),this,SLOT(read_udp_reply()));
    m_tcpserver=new QTcpServer(this);
    connect(m_tcpserver,SIGNAL(newConnection()),this,SLOT(new_tcpConnection()));
    m_tcpserver->listen(QHostAddress::Any,TCP_SERVER_PORT);
    udp_broadcast();
    m_timer = new QTimer(this);
    m_timer->setInterval(30000);
    connect(m_timer, &QTimer::timeout, [=]() {
        udp_broadcast();
        });
    m_timer->start();
}

laser_device_manager::~laser_device_manager()
{
    settings=new QSettings("./system/hardware_list.ini",QSettings::IniFormat);
    int size=settings->value("hardware_list/size").toInt();
    if (m_device_list.size()==0)
    {
        for(int i=0;i<size;++i)
        {
            //qDebug()<<s->value("laser_type").value<laser_type>();
            qDebug()<<"删除："<<settings->contains(QString("hardware_list/tcp_addr_%1").arg(i));
            qDebug()<<"删除："<<settings->contains(QString("hardware_list/laser_type_%1").arg(i));
            settings->remove(QString("hardware_list/tcp_addr_%1").arg(i));
            settings->remove(QString("hardware_list/laser_type_%1").arg(i));
        }
        settings->remove("hardware_list/size");
        settings->sync();
    }
    settings->beginWriteArray("hardware_list");
    for(int i=0;i<m_device_list.size();++i)
    {
        settings->setValue(QString("tcp_addr_%1").arg(i),m_device_list[i]->get_name());
        int it=m_device_list[i]->get_laser_type();
        settings->setValue(QString("laser_type_%1").arg(i),it);
    }
    settings->setValue("size",m_device_list.size());
    settings->endArray();

}
void laser_device_manager::load_hardware_list()
{
    QSettings *s=new QSettings("./system/hardware_list.ini",QSettings::IniFormat);
    s->beginReadArray("hardware_list");
    int size=s->value("size").toInt();
//    std::vector<laser_device*> m_device_list;
    for(int i=0;i<size;++i)
    {

        //qDebug()<<s->value("laser_type").value<laser_type>();
        if(s->value(QString("laser_type_%1").arg(i)).value<laser_type>()==laser_type::lt_edv2)//添加设备并连接该设备的7765端口
        {
            ed_v2_device* dev=new ed_v2_device(s->value(QString("tcp_addr_%1").arg(i)).toString());
            m_device_list.push_back(dev);
            connect(dev,SIGNAL(delete_device(QString)),this,SLOT(delete_device(QString)));
            dev->try_connect();
        }
        //else if(s->value(QString("laser_type_%1").arg(i)).value<laser_type>()==laser_type::lt_ishow)
        //{
        //    ishow_laser_device* dev=new ishow_laser_device(s->value(QString("tcp_addr_%1").arg(i)).toString());
        //    m_device_list.push_back(dev);
        //    connect(dev,SIGNAL(delete_device(QString)),this,SLOT(delete_device(QString)));
        //    dev->try_connect();
        //}
    }
    s->endArray();
}

laser_device *laser_device_manager::get_default_device()
{
    if(m_device_list.size()>0)
        return m_device_list[0];
    return nullptr;
}

laser_device* laser_device_manager::add_device(laser_type t, QString addr)
{
    if(t==laser_type::lt_edv2)//添加设备
    {
        ed_v2_device* dev=new ed_v2_device(addr);
        dev->set_laser_type(laser_type::lt_edv2);
        connect(dev,SIGNAL(delete_device(QString)),this,SLOT(delete_device(QString)));
        m_device_list.push_back(dev);
        emit manager_changed(m_device_list);
        return dev;
    }
    return nullptr;
}

std::vector<laser_device *> laser_device_manager::get_device_list()
{
    return m_device_list;
}

int laser_device_manager::get_device_number()
{
    return m_device_list.size();
}

void laser_device_manager::udp_broadcast()
{
    QString msg("multicast_msg");
    msg.append(getLocalIP());
    msg.append(":");
    msg.append(QString::number(TCP_SERVER_PORT,10));
    qDebug()<<"broadcast_size"<<msg.size();
    m_udpsocket->writeDatagram(msg.toUtf8().data(),QHostAddress::Broadcast,UDP_TARGET_PORT);
}

void laser_device_manager::refresh_laser_device()
{
    udp_broadcast();
}

void laser_device_manager::delete_device(QString tcp_addr)
{
    for(int i=0;i<m_device_list.size();i++)
    {
        if(m_device_list[i]->get_name()==tcp_addr)
        {
            ed_v2_device* m_device = (ed_v2_device*)m_device_list.at(i);
            m_device_list.erase(m_device_list.begin()+i);
            m_device->deleteLater();
        }
        break;
    }
    emit manager_changed(m_device_list);
    if(m_device_list.size()==0&!m_timer->isActive())
        m_timer->start();
}

void laser_device_manager::read_udp_reply()
{
    QHostAddress    remote_addr;
    quint16 peerPort;
    QByteArray   datagram;
    datagram.resize(m_udpsocket->pendingDatagramSize());
    this->m_udpsocket->readDatagram(datagram.data(),datagram.size(),&remote_addr,&peerPort);
    qDebug()<<"recieve size:"<<sizeof(datagram.data())<<"from: "<< remote_addr.toString();

}

void laser_device_manager::new_tcpConnection()
{
    QTcpSocket *socket=m_tcpserver->nextPendingConnection();
    if(socket->state()==QAbstractSocket::ConnectedState)
    {
        QHostAddress remote_addr=socket->peerAddress();
        for(int i=0;i<m_device_list.size();i++)
        {
            auto dev=m_device_list.at(i);
            if(dev->get_name()==remote_addr.toString())
                return;
        }
        auto dev=add_device(laser_type::lt_edv2,remote_addr.toString());
        if (dev != nullptr)
        {
            dev->set_socket(socket);
            dev->m_connected= true;
        }
    }
    if (m_timer->isActive())
        m_timer->stop();

}


laser_device::laser_device(QString name)
    :m_name(name),
    m_connected(false)
{
    m_tcp_addr = name;
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




