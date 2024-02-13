#ifndef SYSTEM_DEVICESMANAGER_H
#define SYSTEM_DEVICESMANAGER_H

#include <QObject>
#include "control/laser_device_manager.h"
#include "control/stage.h"
#include"control/stageslist.h"

//! 硬件控制系统.
/*!
  todo
*/
class System_DevicesManager : public QObject
{
    Q_OBJECT
public:
    explicit System_DevicesManager(QObject *parent = nullptr);
private:
    StagesList m_stagesList;
    laser_device_manager *m_laser_device_manager;
    Configuration *m_conf;
signals:
public slots:
    void refresh_stages(std::vector<laser_device*> device_list);

};

#endif // SYSTEM_DEVICESMANAGER_H
