#include "yls_play_event.h"

yls_play_event::yls_play_event(QEvent::Type type, QString id):QEvent(type)
  ,m_state(false)
{

}

yls_play_event::yls_play_event(const yls_play_event &e):QEvent(e)
,m_state(e.m_state)
{

}

bool yls_play_event::get_state()
{
    return m_state;
}

void yls_play_event::set_state(bool b)
{
    m_state=b;
}
