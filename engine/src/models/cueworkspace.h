#ifndef CUEWORKSPACE_H
#define CUEWORKSPACE_H

#include "cuecategory.h"
#include "core/macros.h"
#include <QObject>

//! 工作区.
/*!
    包含多个目录
*/
class CueWorkspace : public QObject
{
    Q_OBJECT
    BASIC_Q_PROPERTY(QVector<CueCategory*>, categories)
    BASIC_Q_PROPERTY(QString, name)
public:
    explicit CueWorkspace(QObject *parent = nullptr);

signals:
private:

};
Q_DECLARE_METATYPE(CueWorkspace*)

#endif // CUEWORKSPACE_H
