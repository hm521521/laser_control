#ifndef LASER_DEVICE_H
#define LASER_DEVICE_H
// #include "cjsection.h"
//#include "ildafile.h"
#define TCP_SERVER_PORT		7765
#include<QObject>


#include<QtNetwork>
#include <cstdint>

struct ishow_data
{
    unsigned char x;
    unsigned char y;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char gray;
};


enum class send_data_state
{
    sd_begin,
    sd_middle,
    sd_end,
    sd_begin_end
};

struct dac_status
{
    uint8_t protocol;
    uint8_t light_engine_state;
    uint8_t playback_state;
    uint8_t source;
    uint16_t light_engine_flags;
    uint16_t playback_flags;
    uint16_t source_flags; //source_type
    uint16_t buffer_fullness;
    uint32_t point_rate;
    uint32_t point_count;
};//20

struct dac_response
{
    uint8_t response;
    uint8_t command;
    struct dac_status status;
};//22
struct j4cDAC_broadcast
{
    uint8_t mac_address[6];
    uint16_t hw_revision;
    uint16_t sw_revision;
    uint16_t buffer_capacity;
    uint32_t max_point_rate;
    struct dac_status status;
};//36

struct dac_point
{
    uint16_t control;
    int16_t x;
    int16_t y;
    uint16_t r;
    uint16_t g;
    uint16_t b;
    uint16_t i;
    uint16_t u1;
    uint16_t u2;
    const dac_point operator=(const dac_point *d)
    {
        control=d->control;
        x=d->x;
        y=d->y;
        r=d->r;
        g=d->g;
        b=d->b;
        i=d->i;
        u1=d->u1;
        u2=d->u2;
        return *this;
    }
};

struct data_command
{
    uint8_t command; /* ‘d’ (0x64) */
    uint16_t nsection;
    uint16_t npoints;
    struct dac_point data[1000];
};

class laser_device :public QObject//用于保存下位机的地址，与stage对象一一对应，与其对应的stage配合发送数据，
{
    Q_OBJECT
public:
    laser_device()=delete;
    laser_device(QString tcp_addr);
    virtual ~laser_device();
    bool is_connected();
    void try_connect();
    bool is_create_by(QString mac);
    void query_firmware();//询问固件
    void prepare_stream();
    void begin_playback();
    void queue_rate_change();
    void write_data(std::vector<ishow_data>& data,send_data_state flag);
    void set_socket(QTcpSocket* socket);
    QString get_name();
    QTcpSocket *m_socket;
    bool m_connected;
private slots:
    void send_command();
public slots:
    void on_socket_event();
    void onSocketStateChange(QAbstractSocket::SocketState state);
    void send_data(unsigned char *settings_data, std::vector<unsigned char> &data,send_data_state flag,int posnum);//flag位0代表开始，1代表中间，2代表结束，3代表
    void tcpError(QAbstractSocket::SocketError error);
private:
    QByteArray m_send_data;//发送缓冲区
    QByteArray m_recv_data;//接收缓冲区

    void addildahead(std::vector<ishow_data>& data);
    QByteArray send_data_pre;
    int m_posnum=0;
    int m_try_connect=0;
    QTimer* m_timer;
    QString m_tcp_addr;

signals:
    void delete_device(QString tcp_addr);
    void device_connected(QString tcp_addr);
};


//class ed_v2_device_finder:QObject
//{
//    Q_OBJECT
//public:
//    ed_v2_device_finder(laser_device_manager* manager);
//    ~ed_v2_device_finder();
//    bool broadcast();
//    QString getLocalIP();
//private:
//    laser_device_manager* m_manager;
//    QUdpSocket * m_socket;
//    QTimer *timer;
//public slots:
//    void on_socket_event();
//};
#endif // LASER_DEVICE_H
