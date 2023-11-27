#ifndef EFFECTBASE_H
#define EFFECTBASE_H

#include "models/laserframe.h"
#include "core/macros.h"
#include <QObject>

//! effect抽象类.
/*!

*/
class EffectBase : public QObject
{
    Q_OBJECT
    BASIC_INIT_Q_PROPERTY(float ,fps, 30);
public:
    explicit EffectBase(QObject *parent = nullptr);
    virtual LaserFrame getFrame(const float& timeInSeconds, LaserFrame frame) = 0;
    //LaserFrame getFrame(const float& timeInSeconds, LaserFrame frame);


signals:

};
Q_DECLARE_METATYPE(EffectBase*)

#endif // EFFECTBASE_H
