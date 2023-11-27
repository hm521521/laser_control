#include "system_cuewsmanager.h"

System_CueWsManager::System_CueWsManager(System_CueManager* cueMgr,QObject *parent)
    : QObject{parent}
{
    m_workspace = new CueWorkspace;
    m_cueManager = cueMgr;
}

void System_CueWsManager::clearWorkspace(CueWorkspace *ws)
{
    if(ws==nullptr) ws = m_workspace;
    if(ws==nullptr) return;
    for(int i=ws->categories().size()-1;i>=0;i--)
        removeCategory(i,ws);
}

CueCategory * System_CueWsManager::addCategory(QString name,CueWorkspace *ws)
{
    if(ws==nullptr) ws = m_workspace;
    if(ws==nullptr) return nullptr;
    auto cats = ws->categories();
    auto cat = new CueCategory();
    cat->setname(name);
    cats.append(cat);
    ws->setcategories(cats);
    return cat;
}

void System_CueWsManager::removeCategory(const int index, CueWorkspace *ws)
{
    if(ws==nullptr) ws = m_workspace;
    if(ws==nullptr) return;
    auto cats = ws->categories();

    auto cat = cats.at(index);
    for(int i=cat->pages().size()-1;i>=0;i--)
        removePage(i,cat);
    delete cat;

    cats.remove(index);
    ws->setcategories(cats);
}

CuePage* System_CueWsManager::addPage(QString name,CueCategory *cat)
{
    if(cat==nullptr) return nullptr;
    auto ps = cat->pages();
    auto p = new CuePage();
    p->setname(name);
    ps.append(p);
    cat->setpages(ps);
    return p;
}

void System_CueWsManager::removePage(const int index, CueCategory *cat)
{
    auto ps = cat->pages();
    auto p = ps.at(index);
    clearPage(p);
    delete p;
    ps.remove(index);
    cat->setpages(ps);
}

void System_CueWsManager::clearPage(CuePage *page)
{
    auto cues = page->cues();
    for(int i=0;i<cues.size();i++){
        auto lastCue = cues.at(i);
        if(lastCue!=nullptr) m_cueManager->destroyCue(lastCue);
        cues[i] = nullptr;
    }
    page->setcues(cues);
}

void System_CueWsManager::setCue(CuePage *page, const int index, CueBase *cue)
{
    auto cues = page->cues();
    auto lastCue = cues.at(index);
    if(lastCue!=nullptr)
        m_cueManager->destroyCue(lastCue);
    cues[index] = cue;
    page->setcues(cues);
}

void System_CueWsManager::clearCue(CuePage *page, const int index)
{
    setCue(page, index);
}
