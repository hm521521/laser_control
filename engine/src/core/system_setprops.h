#ifndef SYSTEM_SETPROPS_H
#define SYSTEM_SETPROPS_H

#include <QObject>

//! 属性设置系统.
/*!
  todo.
  属性设置应该经过这一层，这样后续才好加入undo/redo系统
*/
class System_SetProps : public QObject
{
    Q_OBJECT
public:
    explicit System_SetProps(QObject *parent = nullptr);

signals:

};

#endif // SYSTEM_SETPROPS_H
