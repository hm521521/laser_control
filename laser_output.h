#ifndef LASER_OUTPUT_H
#define LASER_OUTPUT_H
#include "laser_device_manager.h"
//#include"ed_laser_output.h"


class ishow_laser_device : public laser_device//ishow激光设备
{

public:
    ishow_laser_device()=delete;
    ishow_laser_device(QString tcp_addr);
    virtual ~ishow_laser_device();
public:
    bool is_connected() override;
    void try_connect() override;
    bool is_create_by(QString mac) override;
    void send_data(unsigned char *settings_data, QVector<unsigned char> &data) override;

    unsigned char* get_settings_data();
//    QString get_name() override;
private:
    QTcpSocket *m_tcp_client;
//    QString m_tcp_addr;
};


#endif // LASER_OUTPUT_H
