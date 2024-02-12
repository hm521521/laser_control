#include "laser_output.h"


ishow_laser_device::ishow_laser_device(QString tcp_addr)
    :laser_device("ishow")
{
    m_tcp_client=new QTcpSocket();
    m_tcp_addr=tcp_addr;
}

ishow_laser_device::~ishow_laser_device()
{
    m_tcp_client->destroyed();
}

bool ishow_laser_device::is_connected()
{
    return m_tcp_client->state()==QAbstractSocket::ConnectedState;
}

void ishow_laser_device::try_connect()
{
    if(this->m_tcp_client!=nullptr)
        return;
    QString ipv4_addr=m_tcp_addr.mid(7,m_tcp_addr.length()-7);
    m_tcp_client->connectToHost(ipv4_addr,TCP_SERVER_PORT,QAbstractSocket::ReadWrite, QAbstractSocket::IPv4Protocol);
}

bool ishow_laser_device::is_create_by(QString tcp_addr)
{
    return tcp_addr==m_tcp_addr;
}

//QString ishow_laser_device::get_name()
//{
//    return m_tcp_addr;
//}

void ishow_laser_device::send_data(unsigned char *settings_data, std::vector<unsigned char> &data,send_data_state flag,int posnum)
{

}

void ishow_laser_device::set_socket(QTcpSocket* socket)
{
}


