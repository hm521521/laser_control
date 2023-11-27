#include "uicontroller_gridcue.h"
#include "qdebug.h"

UIController_GridCue::UIController_GridCue(CueAnimator* c,QObject *parent)
    : QObject{parent}
{
    m_cue = (nullptr);
    m_animator = c;
    QObject::connect(m_animator, &CueAnimator::updateFrame, this, &UIController_GridCue::onUpdateFrame, Qt::UniqueConnection);
    QObject::connect(m_animator, &CueAnimator::timeChanged, this, [=](){
            this->settime(this->m_animator->time());
        }, Qt::UniqueConnection);
}

void UIController_GridCue::setCue(CueBase *cue)
{
    if(m_cue==cue) return;
    m_cue = cue;
    if(m_animator && m_animator->cue()!=m_cue){
        m_animator->setcue(m_cue);
        m_animator->reset();
    }
    emit cueChanged();
}

CueBase *UIController_GridCue::cue()
{
    return m_cue;
}

void UIController_GridCue::preview()
{
    if(m_animator){
        //qDebug()<<" -prev";
        m_animator->reset();
        m_animator->play();
    }
}


void UIController_GridCue::play()
{
    if(m_animator){
        //qDebug()<<" -play";
        m_animator->play();
    }
}

void UIController_GridCue::start()
{
    if(m_animator){
        //qDebug()<<" -start";
        m_animator->reset();
        m_animator->play();
    }
}

void UIController_GridCue::pause()
{
    if(m_animator){
        //qDebug()<<" -pause";
        m_animator->pause();
    }
}

void UIController_GridCue::stop()
{
    if(m_animator){
        //qDebug()<<" -stop";
        m_animator->reset();
    }
}

void UIController_GridCue::onUpdateFrame(const LaserFrame &frame)
{
    m_pointsData.clear();
    for(const LaserPoint& pt: frame){
        m_pointsData.append({
            pt.X/256.0, pt.Y/256.0,
            pt.R/256.0, pt.G/256.0, pt.B/256.0, 1.0
        });
    }
    //qDebug()<<"pointsDataChanged";
    emit pointsDataChanged();
}
