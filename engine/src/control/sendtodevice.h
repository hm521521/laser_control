#ifndef SENDTODEVICE_H
#define SENDTODEVICE_H
#include<QObject>
#include"stageslist.h"
#include"models/laserframe.h"

//当需要将数据下发时创建此类对象，并用调用dataSend
class sendToDevice:public QObject
{
    Q_OBJECT
public:
    sendToDevice(StagesList &sl,QObject *parent=0);
public slots:
    void dataSend(LaserFrame &lf);
private:
    StagesList m_stageslist;
    Configuration *m_config;
};

#endif // SENDTODEVICE_H
