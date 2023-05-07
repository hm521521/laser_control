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
    m_tcp_client->connectToHost(m_tcp_addr,TCP_SERVER_PORT);
}

bool ishow_laser_device::is_create_by(QString tcp_addr)
{
    return tcp_addr==m_tcp_addr;
}

void ishow_laser_device::send_data(unsigned char *settings_data, QVector<unsigned char> &data)
{

}


