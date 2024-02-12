#ifndef YLS_PLAY_EVENT_H
#define YLS_PLAY_EVENT_H
#include<QEvent>
#include<QString>

static const QEvent::Type ylsEVT_TOOLBAR_PLAY_EVENT=(QEvent::Type)QEvent::registerEventType();
static const QEvent::Type ylsEVT_TOOLBAR_ENABLE_OUTPUT_EVENT=(QEvent::Type)QEvent::registerEventType();
class yls_play_event:public QEvent//播放事件类
{
public:
    yls_play_event(QEvent::Type type=QEvent::None,QString id=0);
    yls_play_event(const yls_play_event& e);
    bool get_state();
    void set_state(bool b);
private:
    bool m_state;
};

#endif // YLS_PLAY_EVENT_H
