#ifndef SYSTEM_CUEANIMATOR_H
#define SYSTEM_CUEANIMATOR_H

#include "core/macros.h"
#include "models/cue_frames.h"
#include "models/cuebase.h"
#include "system_maintimeloop.h"
#include <QObject>
#include <QSharedPointer>
#include <QDateTime>

//! Cue动画控制器.
/*!
  可以把cue理解成一段动画，这个类就是控制该动画的播放
*/
class CueAnimator : public QObject
{
    Q_OBJECT
    BASIC_INIT_Q_PROPERTY(float, time, 0)
    BASIC_INIT_Q_PROPERTY(bool, isPlaying, false)
    BASIC_INIT_Q_PROPERTY(CueBase*, cue, nullptr)
public:
    explicit CueAnimator(CueBase* cue=nullptr, QObject *parent = nullptr);
    void reset();
    void play();
    void pause();
    LaserFrame currentFrame();
    void update();

public slots:
    void onUpdate();

signals:
    void updateFrame(const LaserFrame& frame);
private:
    LaserFrame m_currentFrame;
    int m_currentFrameIndex;
    qint64 m_lastUpdateTime, m_startTime;
};

//! Cue动画控制器系统.
/*!
  在这里生产和管理动画控制器
*/
class System_CueAnimator : public QObject
{
    Q_OBJECT
public:
    explicit System_CueAnimator(System_MainTimeLoop* loop, QObject *parent = nullptr);
    CueAnimator* createAnimator(CueBase* cue=nullptr);

signals:
private:
    System_MainTimeLoop* m_sysLoop;
};

#endif // SYSTEM_CUEANIMATOR_H
