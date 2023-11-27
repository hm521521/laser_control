#ifndef LASERDEVICEBASE_H
#define LASERDEVICEBASE_H

#include <QObject>

//! 硬件抽象类.
/*!
    todo
*/
class LaserDeviceBase : public QObject
{
    Q_OBJECT
public:
    explicit LaserDeviceBase(QObject *parent = nullptr);

signals:

};

#endif // LASERDEVICEBASE_H
