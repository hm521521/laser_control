#ifndef LASER_DEVICE_MANAGER_H
#define LASER_DEVICE_MANAGER_H
#include<QString>
#include<QVector>
#include<QMutex>
#include<QObject>
#include<QtNetwork>
#include<QSettings>
#define TCP_SERVER_PORT		7765
#define UDP_SERVER_PORT		1200
#define UDP_TARGET_PORT     7654
//#include"hardware.h"
//#include"ed_laser_output.h"

class ed_v2_device_finder;
enum laser_type
{
    lt_ishow=0, //i show 3.0
    lt_edv2=1 //ether dream v2
};
Q_DECLARE_METATYPE(laser_type)

enum class send_data_state
{
    sd_begin,
    sd_middle,
    sd_end,
    sd_begin_end
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
    laser_type get_laser_type();
    void set_laser_type(laser_type lt);
public slots:
    virtual void send_data(unsigned char settings_data[8],std::vector<unsigned char>& data,send_data_state flag,int posnum)=0;
protected:
    QString m_name;
    QString m_mac;
    QString m_tcp_addr;
    laser_type m_laser_type;
//signals:
//    void no_receive();
};


class laser_device_manager:public QObject
{
    Q_OBJECT
public:
    laser_device_manager(QObject *parent=nullptr);
    ~laser_device_manager();
    laser_device* get_default_device();
    void add_device(laser_type t,QString addr);
    std::vector<laser_device*> get_device_list();
    int get_device_number();
public slots:
    void refresh_laser_device();
//    void get_laser_devices();
private:
    ed_v2_device_finder* m_device_finder;
    std::mutex m_lock_obj;
    std::vector<laser_device*> m_device_list;
    QSettings *settings;
    void load_hardware_list();
signals:
    void manager_changed(std::vector<laser_device*> device_list);
    void new_device(laser_device* dev);
};

#endif // LASER_DEVICE_MANAGER_H
