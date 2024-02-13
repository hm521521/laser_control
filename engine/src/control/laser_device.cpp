#include "laser_device.h"
laser_device::laser_device(QString tcp_addr):
    m_send_data{0}
     ,m_recv_data{0}
{
    m_tcp_addr=tcp_addr;
    m_socket = nullptr;
    m_timer = new QTimer(this);
    m_timer->setInterval(100);
    connect(m_timer, &QTimer::timeout, [=]() {
        if (m_recv_data.size() != 8 && m_recv_data.size() != 29)
        {
            m_connected = false;
            delete_device(get_name());
            if (m_timer->isActive())
                m_timer->stop();
        }
        });
    m_timer->start();
}

laser_device::~laser_device()
{
    if(m_socket->state()!=QAbstractSocket::UnconnectedState){
        qDebug() << "current m_socket state:" << m_socket->state();
        m_socket->disconnectFromHost();
        m_socket->waitForDisconnected();
    }
    m_socket->close();
    m_socket->abort();
    this->m_socket=nullptr;
}

bool laser_device::is_connected()
{
    return m_socket->state()==QAbstractSocket::ConnectedState;
}

void laser_device::try_connect()
{

    QString ipv4_addr=m_tcp_addr.mid(7,m_tcp_addr.length()-7);
    this->m_socket->connectToHost(ipv4_addr,TCP_SERVER_PORT,QAbstractSocket::ReadWrite, QAbstractSocket::IPv4Protocol);
    return;

}

bool laser_device::is_create_by(QString mac)
{
    return mac==m_tcp_addr;
}

void laser_device::set_socket(QTcpSocket* socket)
{
    if (socket == nullptr)
        return;
    m_socket = socket;
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(on_socket_event()));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
}

QString laser_device::get_name()
{
    return m_tcp_addr;
}

void laser_device::send_data(unsigned char *settings_data, std::vector<unsigned char> &data,send_data_state flag,int posnum)
{

    m_posnum=posnum;
    std::vector<ishow_data> id;
    for(int i=0;i<(int)(data.size()/sizeof (ishow_data));++i)
    {
        ishow_data d;
        d.x=data[i*sizeof (ishow_data)];
        d.y=data[i*sizeof (ishow_data)+1];
        d.red=data[i*sizeof (ishow_data)+2];
        d.gray=data[i*sizeof (ishow_data)+3];
        d.blue=data[i*sizeof (ishow_data)+4];
        d.green=data[i*sizeof (ishow_data)+5];
        id.push_back(d);
    }
    write_data(id,flag);
}

void laser_device::tcpError(QAbstractSocket::SocketError error)
{
    return;
}

void laser_device::addildahead(std::vector<ishow_data>& data) //加上32字节的文件头
{
    char header[]="ILDA";
    send_data_pre.append(header,4);
    char format[3];
    int a=0;
    memcpy(format,&a,3);
    send_data_pre.append(format,3);
    a=5;
    char format1[1];
    memcpy(format1,&a,1);
    send_data_pre.append(format1,1);
    char framename[]="Frame";
    send_data_pre.append(framename,8);
    char companyname[]="yls";
    send_data_pre.append(companyname,8);
    a = m_posnum;
    char numpoints[2];
    memcpy(numpoints, &a, 2);
    send_data_pre.append(numpoints, 2);
    char framenum[2];
    a=0;
    memcpy(framenum,&a,2);
    send_data_pre.append(framenum,2);
    char totalframes[2];
    a=0;
    memcpy(totalframes,&a,2);
    send_data_pre.append(totalframes,2);
    char pronum[1];
    a=0;
    memcpy(pronum,&a,sizeof(pronum));
    send_data_pre.append(pronum,1);
    char reserved[1];
    a=0;
    memcpy(reserved,&a,1);
    send_data_pre.append(reserved,1);
}

void laser_device::query_firmware()
{

}

void laser_device::write_data(std::vector<ishow_data> &data,send_data_state flag)//把数据发出去
{
    send_data_pre.clear();
    if(flag==send_data_state::sd_begin||flag==send_data_state::sd_begin_end)
        addildahead(data);
    int scale=4000/256;
    int a=0;
    for(int i=0;i<data.size();++i)
    {
        auto& d=data.at(i);
        a=d.x*scale;
        char secA[1];
        memcpy(secA,&a,2);
        send_data_pre.append(secA,2);
        a=d.y*scale;
        memcpy(secA,&a,2);
        send_data_pre.append(secA,2);
        char ch[1];
        a=0;
        if (d.blue==0&&d.green==0&&d.red==0)
            a=1<<6;
        memcpy(ch,&a,1);
        send_data_pre.append(ch,1);
        a=d.red;
        memcpy(ch,&a,sizeof(ch));
        send_data_pre.append(ch,1);
        a=d.green;
        memcpy(ch,&a,sizeof(ch));
        send_data_pre.append(ch,1);
        a=d.blue;
        memcpy(ch,&a,sizeof(ch));
        send_data_pre.append(ch,1);
    }
    m_send_data=send_data_pre;
    this->send_command();
}

//void laser_device::on_recv_data(unsigned char *data, int len)
//{
//    if(len!=sizeof(dac_response))
//    {
//        return;
//    }
//    dac_response* response=(dac_response*)data;
//    switch (response->response)
//    {
//    case 0x61: //ACK, The previous command was accepted.
//        switch (response->command)
//        {
//        case 0x00: //emergency stop
//        case 0xFF:
//            break;
//        case 0x3F: //ping
//            break;
//        case 0x73: //stop
//            break;
//        case 0x63: //clear e-stop
//            break;
//        default:
//            break;
//        }
//        break;
//    case 0x46: //NAK, The write command could not be performed because there was not enough buffer space when it was received.
//        break;
//    case 0x49: //NAK, The command contained an invalid command byte or parameters.
//        break;
//    case 0x21: //NAK, An emergency-stop condition still exists.
//        break;
//    default:
//        break;
//    }
//}



void laser_device::send_command()
{
    if(!m_connected)
    {
        return;
    }
    if(m_recv_data.size() != 8 && m_recv_data.size() != 29)
    {
        if(!this->m_socket->waitForReadyRead(100))
        {
            return;
        }
    }
    if(m_send_data.size()==0)
    {
        return;
    }
    if(!m_connected)
    {
        return;
    }
   
    QMetaObject::invokeMethod(m_socket, std::bind( static_cast<qint64(QTcpSocket::*)(const QByteArray &)>( &QTcpSocket::write ), m_socket, m_send_data ) );
    this->m_socket->flush();
    m_send_data.clear();
    m_recv_data.clear();
}


void laser_device::on_socket_event()
{
    m_recv_data=m_socket->readAll();
        
}

void laser_device::onSocketStateChange(QAbstractSocket::SocketState state)
{
    switch(state)
    {
        case QAbstractSocket::UnconnectedState:
        {
            this->m_connected=false;
            emit delete_device(m_tcp_addr);
            break;
        }
        case QAbstractSocket::ConnectedState:
        {
            this->m_connected = true;
            break;
        }
        default:
        {
            break;
        }
    }
}

//laser_device_finder::laser_device_finder(laser_device_manager *manager)
//    :m_manager(manager)
//    ,m_socket(nullptr)
//{
//    m_socket=new QUdpSocket(this);
//    connect(m_socket,SIGNAL(readyRead()),
//            this,SLOT(on_socket_event()));
//    timer=new QTimer(this);
//    connect(timer,&QTimer::timeout,this,[=](){
//        if(m_manager->get_device_number()!=0)
//            timer->stop();
//            broadcast();
//    });
//    if(m_socket->bind(UDP_SERVER_PORT))
//    {
//        broadcast();
//        timer->start(1000);
//    }

//}

//laser_device_finder::~laser_device_finder()
//{
//    if(this->m_socket!=nullptr)
//    {
//        this->m_socket->deleteLater();
//    }
//}

//bool laser_device_finder::broadcast()//向udp设备的7654端口发送消息
//{
//    QString msg("multicast_msg");
//    msg.append(getLocalIP());
//    msg.append(":");
//    msg.append(QString::number(TCP_SERVER_PORT,10));
//    qDebug()<<"broadcast_size"<<msg.size();
//    m_socket->writeDatagram(msg.toUtf8().data(),QHostAddress::Broadcast,UDP_TARGET_PORT);
//    return true;
//}



//void laser_device_finder::on_socket_event()//发送UDP从7654到1200端口发送消息F81654B39D77000000000000000000000000
//{

//    QHostAddress    remote_addr;
//    quint16 peerPort;
//    QByteArray   datagram;
//    datagram.resize(m_socket->pendingDatagramSize());
//    this->m_socket->readDatagram(datagram.data(),datagram.size(),&remote_addr,&peerPort);

//    qDebug()<<"recieve size:"<<sizeof(datagram.data())<<"from: "<< remote_addr.toString();
//    if(datagram.size()==sizeof(j4cDAC_broadcast)+2)
//    {

//        if(m_manager)
//            m_manager->add_device(laser_type::lt_edv2, remote_addr.toString());
//    }
//}
