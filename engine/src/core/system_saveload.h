#ifndef SYSTEM_SAVELOAD_H
#define SYSTEM_SAVELOAD_H

#include <QObject>

class System_SaveLoad : public QObject
{
    Q_OBJECT
public:
    explicit System_SaveLoad(QObject *parent = nullptr);

signals:

};

#endif // SYSTEM_SAVELOAD_H
