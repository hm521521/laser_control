#ifndef CUEBASE_H
#define CUEBASE_H

#include <QObject>

class CueBase : public QObject
{
    Q_OBJECT
public:
    explicit CueBase(QObject *parent = nullptr);

signals:

};

#endif // CUEBASE_H
