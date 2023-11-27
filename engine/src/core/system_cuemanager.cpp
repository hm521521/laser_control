#include "system_cuemanager.h"

#include <models/cue_frames.h>

System_CueManager::System_CueManager(QObject *parent)
    : QObject{parent}
{

}

CueBase *System_CueManager::createCue(QVector<LaserFrame> frames)
{
    Cue_Frames* cue = new Cue_Frames;
    cue->setframes(frames);
    m_createdCues.append(cue);
    return cue;
}

void System_CueManager::destroyCue(CueBase *cue)
{
    m_createdCues.remove(m_createdCues.indexOf(cue));
    delete cue;
}
