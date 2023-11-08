#ifndef SYSTEM_DEVICESMANAGER_H
#define SYSTEM_DEVICESMANAGER_H

#include <QObject>

class System_DevicesManager : public QObject
{
    Q_OBJECT
public:
    explicit System_DevicesManager(QObject *parent = nullptr);

signals:

};

#endif // SYSTEM_DEVICESMANAGER_H
