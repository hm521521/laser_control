#ifndef LASER_DEVICE_MANAGER_H
#define LASER_DEVICE_MANAGER_H
#include<QString>
#include<QVector>
#include<QMutex>
#include<QObject>
#include<QtNetwork>
#include<QSettings>

#define UDP_SERVER_PORT		1200
#define UDP_TARGET_PORT     7654
//#include"hardware.h"
#include"laser_device.h"
QString getLocalIP();
enum laser_type
{
    lt_ishow=0, //i show 3.0
    lt_edv2=1 //ether dream v2
};
Q_DECLARE_METATYPE(laser_type)


class laser_device_manager:public QObject //用于接收下位机发送的连接请求，创建并管理所有已连接设备
{
    Q_OBJECT
public:
    laser_device_manager(QObject *parent=nullptr);
    ~laser_device_manager();
    laser_device* get_default_device();
    laser_device* add_device(QString addr);
    std::vector<laser_device*> get_device_list();
    int get_device_number();
    void udp_broadcast();
public slots:
    void refresh_laser_device();
    void delete_device(QString tcp_addr);
    void read_udp_reply();
    void new_tcpConnection();
private:
    QUdpSocket *m_udpsocket;
    std::mutex m_lock_obj;
    std::vector<laser_device*> m_device_list;//设备列表
    QSettings *settings;
    void load_hardware_list();
    QTcpServer *m_tcpserver;
    QTimer* m_timer;
signals:
    void manager_changed(std::vector<laser_device*> device_list);
    void new_device(laser_device* dev);
};

#endif // LASER_DEVICE_MANAGER_H
