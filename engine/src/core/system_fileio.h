#ifndef SYSTEM_FILEIO_H
#define SYSTEM_FILEIO_H

#include "system_cuewsmanager.h"

#include <QObject>
//! 文件IO系统.
/*!
  在这里读取workspace文件并加载到对应系统
*/
class System_FileIO : public QObject
{
    Q_OBJECT
public:
    explicit System_FileIO(System_CueWsManager* wsMgr, System_CueManager* cueMgr, QObject *parent = nullptr);
    void loadWorkspace(QUrl u);
    Q_SLOT void loadWorkspace(QString u);

signals:

private:
    System_CueWsManager* m_cueWsManager;
    System_CueManager* m_cueManager;
};

#endif // SYSTEM_FILEIO_H
