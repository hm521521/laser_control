#ifndef ED_LASER_OUTPUT_H
#define ED_LASER_OUTPUT_H
#include "laser_device_manager.h"
#include "cjsection.h"
//#include "ildafile.h"


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

class ed_v2_device:public laser_device
{
    Q_OBJECT
public:
    ed_v2_device()=delete;
    ed_v2_device(QString tcp_addr);
    virtual ~ed_v2_device();
    bool is_connected() override;
    void try_connect() override;
    bool is_create_by(QString mac) override;
    void query_firmware();//询问固件
    void prepare_stream();
    void begin_playback();
    void queue_rate_change();
    void write_data(std::vector<ishow_data>& data,send_data_state flag);
    void on_recv_data(unsigned char* data,int len);
//    QString get_name() override;
private slots:
    void send_command();
public slots:
    void on_socket_event();
    void onSocketStateChange(QAbstractSocket::SocketState state);
    void send_data(unsigned char *settings_data, std::vector<unsigned char> &data,send_data_state flag,int posnum) override;//flag位0代表开始，1代表中间，2代表结束，3代表
    void tcpError(QAbstractSocket::SocketError error);
    //    void connect_server();

private:
//    QTcpSocket *m_socket;
//    QString m_remote_addr;
    bool m_connected;
    QByteArray m_recv_data;//接收缓冲区
    QByteArray m_send_data;//发送缓冲区
    void addildahead();
    QByteArray send_data_pre;
    int m_posnum=0;

};

class ed_v2_device_finder:QObject
{
    Q_OBJECT
public:
    ed_v2_device_finder(laser_device_manager* manager);
    ~ed_v2_device_finder();
    bool broadcast();
    QString getLocalIP();
private:
    laser_device_manager* m_manager;
    QUdpSocket * m_socket;
    QTimer *timer;
public slots:
    void on_socket_event();
};
#endif // ED_LASER_OUTPUT_H
