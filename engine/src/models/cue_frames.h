#ifndef CUE_FRAMES_H
#define CUE_FRAMES_H

#include "cuebase.h"
#include <QObject>

//! 序列帧动画Cue.
/*!

*/
class Cue_Frames : public CueBase
{
    Q_OBJECT
    BASIC_Q_PROPERTY(QVector<LaserFrame> ,frames);
public:
    explicit Cue_Frames(QObject *parent = nullptr);
    LaserFrame getRawFrame(const float& timeInSec);

};
Q_DECLARE_METATYPE(Cue_Frames*)

#endif // CUE_FRAMES_H
