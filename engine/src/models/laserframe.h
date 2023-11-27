#ifndef LASERFRAME_H
#define LASERFRAME_H

#include <QObject>
#include <QVector>
#include "laserpoint.h"

//! 帧.
/*!
    一帧画面的数据，包含多个点
*/
typedef QVector<LaserPoint> LaserFrame;

#endif // LASERFRAME_H
