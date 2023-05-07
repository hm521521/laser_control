#include "ed_laser_output.h"



ed_v2_device::ed_v2_device(QString tcp_addr)
    :laser_device("edv2")
    ,m_socket(nullptr)
    ,m_connected(false)
    ,m_recv_data{0}
    ,m_send_data{0}
{
    m_tcp_addr=tcp_addr;
    m_socket=new QTcpSocket(this);
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(on_socket_event()));
    connect(m_socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
//    onSocketStateChange(m_socket->state());

}

ed_v2_device::~ed_v2_device()
{
//    this->m_socket->close();
//    delete this->m_socket;
    m_socket->disconnectFromHost();
    if(m_socket->state()!=QAbstractSocket::UnconnectedState){
        m_socket->waitForDisconnected();
    }
    m_socket->close();
    m_socket->abort();
    this->m_socket=nullptr;
}

bool ed_v2_device::is_connected()
{
    return m_socket->state()==QAbstractSocket::ConnectedState;
}

void ed_v2_device::try_connect()
{
//    if(this->m_socket!=nullptr)
//        return;
//    this->m_socket=new QTcpSocket();
    do
    {
        QHostAddress remote_addr(m_tcp_addr);
        this->m_socket->connectToHost(m_tcp_addr,TCP_SERVER_PORT);
        return;
    }
    while(0);
    this->m_socket->close();
    delete this->m_socket;
    this->m_socket=nullptr;
}

bool ed_v2_device::is_create_by(QString mac)
{
    return mac==m_tcp_addr;
}

void ed_v2_device::send_data(unsigned char *settings_data, QVector<unsigned char> &data)
{
//    send_command(settings_data, 8);
    QVector<ishow_data> id;
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
    write_data(id);
}

void ed_v2_device::query_firmware()
{

}

void ed_v2_device::write_data(QVector<ishow_data> &data)//把数据发出去
{
    QByteArray send_data;
    send_data.clear();
//    int i=0;
    char header[]="ILDA";
    send_data.append(header,sizeof (header));
    char format[3];
    int a=0;
    memcpy(format,&a,sizeof(format));
    send_data.append(format,sizeof (format));
    a=5;
    char format1[1];
    memcpy(format1,&a,sizeof(format1));
    send_data.append(format1,sizeof (format1));
    char frame[]="Frame";
    send_data.append(frame,sizeof (frame));
    char framename[3];
    a=0;
    memcpy(framename,&a,3);
    send_data.append(framename,sizeof(framename));
    char companyname[]="yls";
    send_data.append(companyname,8);
    a=data.size();
    char numpoints[2];
    memcpy(numpoints,&a,sizeof(numpoints));
    send_data.append(numpoints,2);
    char framenum[2];
    a=0;
    memcpy(framenum,&a,sizeof(framenum));
    send_data.append(framenum,2);
    char totalframes[2];
    a=0;
    memcpy(totalframes,&a,sizeof(totalframes));
    send_data.append(totalframes,2);
    char pronum[1];
    a=0;
    memcpy(pronum,&a,sizeof(pronum));
    send_data.append(pronum,1);
    char reserved[1];
    a=0;
    memcpy(reserved,&a,sizeof(reserved));
    send_data.append(reserved,1);
    for(int i=0;i<data.size();++i)
    {
        auto& d=data.at(i);
        a=d.x;
        char secA[2];
        memcpy(secA,&a,sizeof(secA));
        send_data.append(secA,2);
        a=d.y;
        memcpy(secA,&a,sizeof(secA));
        send_data.append(secA,2);
        char ch[1];
        a=0;
        if (d.blue==0&&d.green==0&&d.red==0)
            a=1<<6;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
        a=d.blue;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
        a=d.green;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
        a=d.red;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
    }
//    auto dc_command=0x64;
//    char command[1];
//    memcpy(command,&dc_command,sizeof(command));
//    send_data.append(command);
//    int dc_npoints=data.size();
//    memcpy(command,&dc_npoints,sizeof (command));
//    send_data.append(command);
//    for(int i=0;i<dc_npoints;++i)
//    {
//        if(send_data.size()+sizeof (dac_point)>1021)
//        {
//            send_data.append("\0");
//            m_send_data=send_data;
//            this->send_command();
//            send_data.clear();
//        }
//        auto& d=data.at(i);
//        int dp_control=0;
//        memcpy(command,&dp_control,sizeof (dp_control));
//        send_data.append(command);
//        int dp_x=d.x;
//        memcpy(command,&dp_x,sizeof (dp_x));
//        send_data.append(command);
//        int dp_y=d.y;
//        memcpy(command,&dp_y,sizeof (dp_y));
//        send_data.append(command);
//        int dp_r=d.red;
//        memcpy(command,&dp_r,sizeof(dp_r));
//        send_data.append(command);
//        int dp_g=d.green;
//        memcpy(command,&dp_g,sizeof(dp_g));
//        send_data.append(command);
//        int dp_b=d.blue;
//        memcpy(command,&dp_b,sizeof(dp_b));
//        send_data.append(command);
//        int dp_i=0;
//        memcpy(command,&dp_i,sizeof(dp_i));
//        send_data.append(command);
//        int dp_u1=0;
//        memcpy(command,&dp_u1,sizeof(dp_u1));
//        send_data.append(command);
//        int dp_u2=0;
//        memcpy(command,&dp_u2,sizeof(dp_u2));
//        send_data.append(command);
//    }
//    send_data.append("\0");
    send_data.append(header,sizeof (header));
    send_data.append(format,sizeof (format));
    send_data.append(format1,sizeof (format1));
    send_data.append(frame,sizeof (frame));
    send_data.append(framename,sizeof(framename));
    send_data.append(companyname,8);
    send_data.append(numpoints,2);
    send_data.append(framenum,2);
    send_data.append(totalframes,2);
    send_data.append(pronum,1);
    send_data.append(reserved,1);
    m_send_data=send_data;
    this->send_command();
//    send_data.clear();
}

void ed_v2_device::on_recv_data(unsigned char *data, int len)
{
    if(len!=sizeof(dac_response))
    {
        return;
    }
    dac_response* response=(dac_response*)data;
    switch (response->response)
    {
    case 0x61: //ACK, The previous command was accepted.
        switch (response->command)
        {
        case 0x00: //emergency stop
        case 0xFF:
            break;
        case 0x3F: //ping
            break;
        case 0x73: //stop
            break;
        case 0x63: //clear e-stop
            break;
        default:
            break;
        }
        break;
    case 0x46: //NAK, The write command could not be performed because there was not enough buffer space when it was received.
        break;
    case 0x49: //NAK, The command contained an invalid command byte or parameters.
        break;
    case 0x21: //NAK, An emergency-stop condition still exists.
        break;
    default:
        break;
    }
}

void ed_v2_device::send_command()
{
    if (this->m_connected == false)
        return;
//    int num=0;
//    QByteArray data;
//    int i=sizeof (m_send_data.data());
//    while (num<m_send_data.size())
//    {
//        data=m_send_data.mid(num,1024);
        this->m_socket->write(m_send_data);
        this->m_socket->flush();
//        msleep(40);
//        if(!m_socket->waitForBytesWritten(10000))
//            return;
//        num=num+1024;
//    }
}


void ed_v2_device::on_socket_event()
{
//    m_socket->read((char*)m_recv_data,1024);
//    this->on_recv_data(m_recv_data,m_socket->pendingDatagramSize());

//    m_socket->readDatagram(m_recv_data,1024,&peerAddr,&peerPort);

}

void ed_v2_device::onSocketStateChange(QAbstractSocket::SocketState state)
{
    switch(state)
    {
    case QAbstractSocket::UnconnectedState:
    {
        this->m_connected=false;
        try_connect();
        break;
    }
    case QAbstractSocket::ConnectedState:
    {
        this->m_connected=true;
        break;
    }
    default:
    {
        break;
    }
    }
}

ed_v2_device_finder::ed_v2_device_finder(laser_device_manager *manager)
    :m_manager(manager)
    ,m_socket(nullptr)
{
    m_socket=new QUdpSocket(this);
    connect(m_socket,SIGNAL(readyRead()),
            this,SLOT(on_socket_event()));
    if(m_socket->bind(UDP_SERVER_PORT))
    {
        broadcast();
    }
}

ed_v2_device_finder::~ed_v2_device_finder()
{
    if(this->m_socket!=nullptr)
    {
        this->m_socket->deleteLater();
    }
}

bool ed_v2_device_finder::broadcast()//向udp设备的7654端口发送消息
{
    QString msg("multicast_msg");
    msg.append(getLocalIP());
    msg.append(":");
    msg.append(QString::number(TCP_SERVER_PORT,10));
    m_socket->writeDatagram(msg.toUtf8().data(),QHostAddress::Broadcast,UDP_TARGET_PORT);
    return true;
}

QString ed_v2_device_finder::getLocalIP()
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

void ed_v2_device_finder::on_socket_event()//发送UDP从7654到1200端口发送消息F81654B39D77000000000000000000000000
{
//    unsigned char data[1024];
    QHostAddress    remote_addr;
    quint16 peerPort;
    QByteArray   datagram;
    datagram.resize(m_socket->pendingDatagramSize());
    this->m_socket->readDatagram(datagram.data(),datagram.size(),&remote_addr,&peerPort);
    int a=sizeof(j4cDAC_broadcast);
    if(datagram.size()==sizeof(j4cDAC_broadcast))
    {
        j4cDAC_broadcast* msg=(j4cDAC_broadcast*)datagram.data();
        int count=msg->status.point_count;
        if(m_manager)
            m_manager->add_device(laser_type::lt_edv2, remote_addr.toString());
    }
}
