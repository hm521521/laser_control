#ifndef SYSTEM_CUEWSMANAGER_H
#define SYSTEM_CUEWSMANAGER_H

#include <QObject>
#include "macros.h"
#include "system_cuemanager.h"
#include "models/cueworkspace.h"

//! Cue Workspace控制系统.
/*!
  在这里生产和管理Workspace实例和其中的category、page
*/
class System_CueWsManager : public QObject
{
    Q_OBJECT
    BASIC_INIT_Q_PROPERTY(CueWorkspace*, workspace, nullptr)
public:
    explicit System_CueWsManager(System_CueManager* cueMgr, QObject *parent = nullptr);

    void clearWorkspace(CueWorkspace* ws=nullptr);

    CueCategory* addCategory(QString name=QString("Undefined"), CueWorkspace* ws=nullptr);
    void removeCategory(const int index, CueWorkspace* ws=nullptr);

    CuePage* addPage(QString name=QString("Undefined"), CueCategory* cat=nullptr);
    void removePage(const int index, CueCategory* cat=nullptr);
    void clearPage(CuePage* page);

    void setCue(CuePage* page, const int index, CueBase* cue=nullptr);
    void clearCue(CuePage* page, const int index);

signals:

private:
    System_CueManager* m_cueManager;

};

#endif // SYSTEM_CUEWSMANAGER_H
