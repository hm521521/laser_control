#ifndef CUEPAGE_H
#define CUEPAGE_H

#include "cuebase.h"
#include "core/macros.h"
#include <QObject>

//! 页.
/*!
    包含10*6个cue
*/
class CuePage : public QObject
{
    Q_OBJECT
    BASIC_Q_PROPERTY(QVector<CueBase*>, cues)
    BASIC_Q_PROPERTY(QString, name)
public:
    explicit CuePage(QObject *parent = nullptr);

signals:


};
Q_DECLARE_METATYPE(CuePage*)

#endif // CUEPAGE_H

