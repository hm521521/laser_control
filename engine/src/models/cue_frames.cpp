#include "cue_frames.h"
#include <QDebug>

Cue_Frames::Cue_Frames(QObject *parent)
    : CueBase{parent}
{

}

LaserFrame Cue_Frames::getRawFrame(const float& timeInSec)
{
    return m_frames.at((int(timeInSec*fps())) % m_frames.size());
}
