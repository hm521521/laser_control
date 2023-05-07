#ifndef STAGE_H
#define STAGE_H
#include <vector>
#include"cjsection.h"
#include"laser_device_manager.h"
#include<QThread>
#include<QMutex>
#include<QObject>

class stage:public QObject//worker
{
    Q_OBJECT
    QThread stage_thread;
public:

//    stage(Configuration* config);
    stage(QWidget *parent=0);
    void set_config(Configuration* config);
    void set_device(laser_device * dev);
    void add_send_data(std::vector<ishow_data>& list);
    ~stage();
    bool test_output();
    laser_device * get_device();
private:
//    stage_work_thread *m_work_thread;
    bool OutputDebug;
    laser_device *m_laser_device;
    std::vector<ishow_data> m_debug_data_list;
    std::vector<std::vector<ishow_data>> m_output_data_list;
    Configuration* m_config;
public:
    void do_send_data();
signals:
    void resultReady(const int result);
    void stage_finish();
};


//class stage_work_thread:public QThread
//{
//public:
//    stage_work_thread(stage*output);
//    ~stage_work_thread();
//    void pause();
//    void resume();
//protected:
//    void run();
//private:
//    stage* m_stage;
//    QMutex m_lock;

//};

#endif // STAGE_H
