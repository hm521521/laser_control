#include "system_maintimeloop.h"
#include "qdebug.h"

System_MainTimeLoop::System_MainTimeLoop(QObject *parent)
    : QObject{parent}
{
    m_timer.start(0);
}

void System_MainTimeLoop::addListener(QObject *obj)
{
    QObject::connect(&m_timer, SIGNAL(timeout()), obj, SLOT(onUpdate()));
}
