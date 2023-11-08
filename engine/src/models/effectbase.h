#ifndef EFFECTBASE_H
#define EFFECTBASE_H

#include <QObject>

class EffectBase : public QObject
{
    Q_OBJECT
public:
    explicit EffectBase(QObject *parent = nullptr);

signals:

};

#endif // EFFECTBASE_H
