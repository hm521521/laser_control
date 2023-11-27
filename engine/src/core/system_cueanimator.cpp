#include "system_cueanimator.h"
#include "qdebug.h"
#include <QThread>

System_CueAnimator::System_CueAnimator(System_MainTimeLoop* loop,QObject *parent)
    : QObject{parent}
{
    m_sysLoop = loop;
}

CueAnimator *System_CueAnimator::createAnimator(CueBase *cue)
{
    auto ca = new CueAnimator(cue);
    m_sysLoop->addListener(ca);
    return ca;
}

CueAnimator::CueAnimator(CueBase* cue, QObject *parent)
: QObject{parent}
{
    m_lastUpdateTime = 0;
    m_cue = cue;
    reset();
}

void CueAnimator::reset()
{
    settime(0);
    setisPlaying(false);
    update();
    m_lastUpdateTime = m_startTime = QDateTime::currentMSecsSinceEpoch();
}

void CueAnimator::play()
{
    setisPlaying(true);
}

void CueAnimator::pause()
{
    setisPlaying(false);
}


LaserFrame CueAnimator::currentFrame()
{
    return m_currentFrame;
}

void CueAnimator::update()
{
    if(m_cue) {
        auto effects = m_cue->effects();
        m_currentFrame = m_cue->getFrame(m_time);
        for(auto effect:effects){
            m_currentFrame = effect->getFrame(m_time, m_currentFrame);
        }
    }else{
        m_currentFrame.clear();
    }
    emit updateFrame(m_currentFrame);
}

void CueAnimator::onUpdate()
{
    if(!m_cue || !m_isPlaying)return;

    auto curTime = QDateTime::currentMSecsSinceEpoch();
    auto newTime = (curTime - m_startTime)/1000.0;
    if(newTime - m_time>0.01) settime(newTime);

    auto effects = m_cue->effects();
    float maxFps = m_cue->fps();
    for(auto effect:effects){
        maxFps = fmax(maxFps, effect->fps());
    }
    if(curTime - m_lastUpdateTime<1000.0/maxFps) return;
    m_lastUpdateTime = curTime;

    update();
}
