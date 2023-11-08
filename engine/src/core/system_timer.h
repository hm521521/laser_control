#ifndef SYSTEM_TIMER_H
#define SYSTEM_TIMER_H

#include <QObject>

class System_Timer : public QObject
{
    Q_OBJECT
public:
    explicit System_Timer(QObject *parent = nullptr);

signals:

};

#endif // SYSTEM_TIMER_H
