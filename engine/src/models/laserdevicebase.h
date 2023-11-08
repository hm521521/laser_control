#ifndef LASERDEVICEBASE_H
#define LASERDEVICEBASE_H

#include <QObject>

class LaserDeviceBase : public QObject
{
    Q_OBJECT
public:
    explicit LaserDeviceBase(QObject *parent = nullptr);

signals:

};

#endif // LASERDEVICEBASE_H
