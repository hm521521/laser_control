#include "cuebase.h"
#include "qdebug.h"

#include <QTransform>

CueBase::CueBase(QObject *parent)
    : QObject{parent}
{

}

LaserFrame CueBase::getFrame(const float &timeInSeconds)
{
    auto frame = getRawFrame(timeInSeconds);
    // basic static effect
    float midNum = 0.5*255;
    for(LaserPoint& pt:frame){
        QTransform t = QTransform().translate(m_positionX, m_positionY).translate(midNum,midNum).rotate(m_rotation).scale(m_sizeX,m_sizeY).translate(-midNum,-midNum);
        QPointF o = t.map(QPointF(pt.X, pt.Y));
        pt.X=o.x();
        pt.Y=o.y();
    }
    return frame;
}


