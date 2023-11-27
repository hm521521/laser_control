#ifndef CUEBASE_H
#define CUEBASE_H

#include <QObject>
#include "effectbase.h"
#include "laserframe.h"
#include "core/macros.h"
#include "core/enums.h"

//! Cue抽象类.
/*!

*/
class CueBase : public QObject
{
    Q_OBJECT
    /*! 基本属性 */
    BASIC_INIT_Q_PROPERTY(float ,fps, 30);
    BASIC_INIT_Q_PROPERTY(QString ,name, "Undefined");
    /*! 基本变换(区分于effects) */
    BASIC_INIT_Q_PROPERTY(float, sizeX, 1);
    BASIC_INIT_Q_PROPERTY(float, sizeY, 1);
    BASIC_INIT_Q_PROPERTY(float, rotation, 0);
    BASIC_INIT_Q_PROPERTY(float, positionX, 0);
    BASIC_INIT_Q_PROPERTY(float, positionY, 0);
    /*! 用户定义的effects列表 */
    BASIC_Q_PROPERTY(QVector<EffectBase*>, effects);
    //BASIC_Q_PROPERTY(yel::CUE_TYPE ,cueType);
public:
    explicit CueBase(QObject *parent = nullptr);
    //! 根据时间得到对应内容.
    /*! Cue本身不会管理播放和时间，但是可以依据时间得到对应画面 */
    LaserFrame getFrame(const float& timeInSeconds);
    virtual LaserFrame getRawFrame(const float& timeInSeconds) = 0;

    //virtual CueBase* clone()=0;

signals:

};
Q_DECLARE_METATYPE(CueBase*)

#endif // CUEBASE_H
