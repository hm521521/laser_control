#ifndef CUEWORKSPACE_H
#define CUEWORKSPACE_H

#include "cuecategory.h"

#include <QObject>

class CueWorkspace : public QObject
{
    Q_OBJECT
public:
    explicit CueWorkspace(QObject *parent = nullptr);

signals:
private:
    QString m_name;
    QVector<CueCategory> m_categories;

};

#endif // CUEWORKSPACE_H
