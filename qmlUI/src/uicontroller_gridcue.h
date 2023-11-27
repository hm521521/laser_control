#ifndef UICONTROLLER_GRIDCUE_H
#define UICONTROLLER_GRIDCUE_H

#include <QObject>
#include "core/macros.h"
#include "core/system_cueanimator.h"

class UIController_GridCue : public QObject
{
    Q_OBJECT
    BASIC_Q_PROPERTY(QVector<qreal>, pointsData)
    BASIC_Q_PROPERTY(float, time);
    BASIC_Q_PROPERTY(QString, shortcut);
    Q_PROPERTY(CueBase* cue READ cue WRITE setCue NOTIFY cueChanged)
public:
    explicit UIController_GridCue(CueAnimator* c=nullptr, QObject *parent = nullptr);

    void setCue(CueBase*cue);
    CueBase* cue();
    Q_SIGNAL void cueChanged();
    Q_INVOKABLE void preview();
    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    Q_SLOT void onUpdateFrame(const LaserFrame& frame);

signals:

private:
    CueBase* m_cue;
    CueAnimator* m_animator;
    int m_state;//0:none;1:preview;2:playing;3:paused
};
Q_DECLARE_METATYPE(UIController_GridCue*)
#endif // UICONTROLLER_GRIDCUE_H
