#ifndef LASER_DEVICE_MANAGER_H
#define LASER_DEVICE_MANAGER_H
#include<QString>
#include<QVector>
#include<QMutex>
#include<QObject>
#include<QtNetwork>
#define TCP_SERVER_PORT		7765
#define UDP_SERVER_PORT		1200
#define UDP_TARGET_PORT     7654
//#include"hardware.h"
//#include"ed_laser_output.h"

class ed_v2_device_finder;
enum class laser_type
{
    lt_ishow, //i show 3.0
    lt_edv2,  //ether dream v2
};
enum class send_data_state
{
    sd_begin,
    sd_middle,
    sd_end,
    sd_begin_end,
};

class laser_device:public QObject
{
Q_OBJECT
public:
    laser_device()=delete;
    laser_device(QString name);
    virtual ~laser_device();

    virtual bool is_create_by(QString mac)=0;
    virtual bool is_connected()=0;
    virtual void try_connect()=0;

    QString get_name();
//    void send_data(char setting_data[8],QVector<char>& data);
    QTcpSocket *m_socket;
public slots:
    virtual void send_data(unsigned char settings_data[8],QVector<unsigned char>& data,send_data_state flag,int posnum)=0;
protected:
    QString m_name;
    QString m_mac;
    QString m_tcp_addr;
//    bool m_connected;
//    projection_zones_manager* m_projection_zones;
signals:
    void send_continue();
};


class laser_device_manager:public QObject
{
    Q_OBJECT
public:
    laser_device_manager(QObject *parent=nullptr);
    ~laser_device_manager();
    laser_device* get_default_device();
    void add_device(laser_type t,QString addr);
    QVector<laser_device*> get_device_list();
public slots:
    void refresh_laser_device();
private:
    ed_v2_device_finder* m_device_finder;
    std::mutex m_lock_obj;
    QVector<laser_device*> m_device_list;
signals:
    void manager_changed(QVector<laser_device*> device_list);
    void new_device(laser_device* dev);
};

#endif // LASER_DEVICE_MANAGER_H
