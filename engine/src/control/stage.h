#ifndef STAGE_H
#define STAGE_H
#include <vector>
#include<QThread>
#include<QMutex>
#include<QObject>
#include"configuration.h"
#include"laser_device.h"
#include"models/laserframe.h"


class stage:public QObject//处理发送数据的抽点算法，分包并发送；对准备发送的数据进行全局处理
{
    Q_OBJECT
public:
    stage(QObject *parent=0);
    void set_config(Configuration* config);
    void set_device(laser_device * dev);
    void add_send_data(std::vector<ishow_data>& list);
    ~stage();
    bool test_output();
    laser_device * get_device();
    std::vector<ishow_data> globalprocessing(LaserFrame &lf);//数据发送前的全局处理
private:
    bool OutputDebug;
    laser_device *m_laser_device;
    std::vector<ishow_data> m_debug_data_list;
    std::vector<std::vector<ishow_data>> m_output_data_list;
    Configuration* m_config;
    std::vector<unsigned char> last_send_data={0,0,0,0,0,0};//上一幅图的最后一个点的信息
    unsigned char settings_data[8]={0};
public slots:
    void do_send_data();
signals:
    void resultReady(const int result);
    void stage_finish();

};

#endif // STAGE_H
