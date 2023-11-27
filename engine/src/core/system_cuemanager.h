#ifndef SYSTEM_CUEMANAGER_H
#define SYSTEM_CUEMANAGER_H

#include <QObject>

#include "models/cuebase.h"


//! Cue控制系统.
/*!
  在这里生产和管理Cue实例
*/
class System_CueManager : public QObject
{
    Q_OBJECT
public:
    explicit System_CueManager(QObject *parent = nullptr);

    CueBase* createCue(QVector<LaserFrame> frames);
    void destroyCue(CueBase* cue);

signals:

private:
    QVector<CueBase*> m_createdCues;

};

#endif // SYSTEM_CUEMANAGER_H
