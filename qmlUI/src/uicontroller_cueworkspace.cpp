#include "uicontroller_cueworkspace.h"
#include "core/constants.h"
#include "qdebug.h"

UIController_CueWorkspace::UIController_CueWorkspace(System_CueAnimator*ca ,QObject *parent)
    : QObject{parent}
{
    m_cueAnimator = ca;
    QVector<UIController_GridCue*> g;
    for(int i=0;i<CUE_GRID_COUNT;i++){
        auto gc = new UIController_GridCue(m_cueAnimator->createAnimator());
        gc->setshortcut(QString(CUE_SHORTCUTS[i]));
        g.append(gc);
    }
    setgridCues(g);
}

void UIController_CueWorkspace::setGridCuesByPage(CuePage *page)
{
    auto g =gridCues();
    auto cues = page->cues();
    for(int i=0;i<CUE_GRID_COUNT;i++){
        g.at(i)->setCue(cues.at(i));
    }
}
