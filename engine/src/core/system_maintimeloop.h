#ifndef SYSTEM_MAINTIMELOOP_H
#define SYSTEM_MAINTIMELOOP_H

#include <QObject>
#include <QTimer>


//! 主循环系统.
/*!
  目前，这里会在每一次主循环时发送一个update信号，接收该信号的脚本会据此更新时间；
  考虑到后续会有时间同步的系统，所以目前先这样
*/
class System_MainTimeLoop : public QObject
{
    Q_OBJECT
public:
    explicit System_MainTimeLoop(QObject *parent = nullptr);
    void addListener(QObject* obj);

signals:
    void update();
private:
    QTimer m_timer;
};



#endif // SYSTEM_MAINTIMELOOP_H
