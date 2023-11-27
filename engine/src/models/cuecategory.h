#ifndef CUECATEGORY_H
#define CUECATEGORY_H

#include "cuepage.h"
#include "core/macros.h"
#include <QObject>

//! 目录.
/*!
    包含多个page
*/
class CueCategory : public QObject
{
    Q_OBJECT
    BASIC_Q_PROPERTY(QVector<CuePage*>, pages)
    BASIC_Q_PROPERTY(QString, name)
public:
    explicit CueCategory(QObject *parent = nullptr);

signals:



};
Q_DECLARE_METATYPE(CueCategory*)


#endif // CUECATEGORY_H
