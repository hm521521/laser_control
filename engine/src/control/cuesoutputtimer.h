#ifndef CUESOUTPUTTIMER_H
#define CUESOUTPUTTIMER_H
#include<QTimer>


//输出数据到下位机的线程

class cuesOutputTimer: public QObject
{
    Q_OBJECT
public:
    explicit cuesOutputTimer(QObject *parent = nullptr);
private:
    QTimer *m_timer;
signals:
    void outputTimeout();

};

#endif // CUESOUTPUTTIMER_H
