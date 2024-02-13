#include "cuesoutputtimer.h"

cuesOutputTimer::cuesOutputTimer(QObject *parent)
{
    m_timer=new QTimer(this);
    connect(m_timer,&QTimer::timeout,[=](){
        emit outputTimeout();
    });
}


