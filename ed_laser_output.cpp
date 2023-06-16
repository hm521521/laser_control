#include "ed_laser_output.h"



ed_v2_device::ed_v2_device(QString tcp_addr)
    :laser_device("edv2")
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

void ed_v2_device::send_data(unsigned char *settings_data, QVector<unsigned char> &data,bool flag)
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
    write_data(id,flag);
}

void ed_v2_device::query_firmware()
{

}

void ed_v2_device::write_data(QVector<ishow_data> &data,bool flag)//把数据发出去
{
    QByteArray send_data;
    send_data.clear();
//    int i=0;
    char header[]="ILDA";
    send_data.append(header,4);
    char format[3];
    int a=0;
    memcpy(format,&a,3);
    send_data.append(format,3);
    a=5;
    char format1[1];
    memcpy(format1,&a,1);
    send_data.append(format1,1);
    char framename[]="Frame";
    send_data.append(framename,8);
//    char framename[2];
//    a=0;
//    memcpy(framename,&a,2);
//    send_data.append(framename,sizeof(framename));
    char companyname[]="yls";
    send_data.append(companyname,8);
    a=data.size();
    char numpoints[2];
    memcpy(numpoints,&a,2);
    send_data.append(numpoints,2);
    char framenum[2];
    a=0;
    memcpy(framenum,&a,2);
    send_data.append(framenum,2);
    char totalframes[2];
    a=0;
    memcpy(totalframes,&a,2);
    send_data.append(totalframes,2);
    char pronum[1];
    a=0;
    memcpy(pronum,&a,sizeof(pronum));
    send_data.append(pronum,1);
    char reserved[1];
    a=0;
    memcpy(reserved,&a,1);
    send_data.append(reserved,1);
    int scale=4096/256;
    for(int i=0;i<data.size();++i)
    {
        auto& d=data.at(i);
        a=d.x*scale;
        char secA[1];
        memcpy(secA,&a,2);
        send_data.append(secA,2);
        a=d.y*scale;
        memcpy(secA,&a,2);
        send_data.append(secA,2);
        char ch[1];
        a=0;
        if (d.blue==0&&d.green==0&&d.red==0)
            a=1<<6;
        memcpy(ch,&a,1);
        send_data.append(ch,1);
        a=d.red;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
        a=d.green;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
        a=d.blue;
        memcpy(ch,&a,sizeof(ch));
        send_data.append(ch,1);
    }
//    send_data.append(header,sizeof (header));
//    send_data.append(format,sizeof (format));
//    send_data.append(format1,sizeof (format1));
//    send_data.append(framename,sizeof(framename));
//    send_data.append(companyname,8);
//    send_data.append(numpoints,2);
//    send_data.append(framenum,2);
//    send_data.append(totalframes,2);
//    send_data.append(pronum,1);
//    send_data.append(reserved,1);

    if(flag)
    {
        int num=0;
        int pos=0;
        for(int i=0;i<data.size();i++)
        {
            auto& d=data.at(i);
            if(d.x==0&&d.y==0)
                num++;
            if(num>2)
            {
                pos=i;
                break;
            }

        }
        QByteArray head=send_data.mid(0,32);
        send_data.replace(pos*8+32,32,head);
    }
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
    if(m_recv_data!="Recv OK!")
        this->m_socket->waitForReadyRead();
//    int num=0;
//    QByteArray data;
//    int i=sizeof (m_send_data.data());
//    while (num<m_send_data.size())
//    {
//        data=m_send_data.mid(num,1024);
//        this->m_socket->write(m_send_data);
    if(m_send_data.size()==0)
        return;
    QMetaObject::invokeMethod(m_socket, std::bind( static_cast<qint64(QTcpSocket::*)(const QByteArray &)>( &QTcpSocket::write ), m_socket, m_send_data ) );
    this->m_socket->flush();
//    if(m_socket->read(8).data()!="recv ok!")
//        emit send_continue();
    m_send_data.clear();
    m_recv_data.clear();
//
}


void ed_v2_device::on_socket_event()
{
    m_recv_data=m_socket->readAll();
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
