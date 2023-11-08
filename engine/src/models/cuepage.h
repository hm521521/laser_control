#ifndef CUEPAGE_H
#define CUEPAGE_H

#include "cuebase.h"
#include <QObject>

class CuePage : public QObject
{
    Q_OBJECT
public:
    explicit CuePage(QObject *parent = nullptr);

signals:

private:
    QString m_name;
    QVector<CueBase> m_cues;

};

#endif // CUEPAGE_H
