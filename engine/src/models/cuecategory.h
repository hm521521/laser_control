#ifndef CUECATEGORY_H
#define CUECATEGORY_H

#include "cuepage.h"

#include <QObject>

class CueCategory : public QObject
{
    Q_OBJECT
public:
    explicit CueCategory(QObject *parent = nullptr);

signals:

private:
    QString m_name;
    QVector<CuePage> m_pages;


};

#endif // CUECATEGORY_H
