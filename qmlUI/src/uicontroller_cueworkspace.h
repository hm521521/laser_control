#ifndef UICONTROLLER_CUEWORKSPACE_H
#define UICONTROLLER_CUEWORKSPACE_H

#include "core/macros.h"
#include "uicontroller_gridcue.h"
#include <QObject>

#include <models/cueworkspace.h>

class UIController_CueWorkspace : public QObject
{
    Q_OBJECT
    BASIC_INIT_Q_PROPERTY(CueWorkspace*,workspace, nullptr)
    BASIC_Q_PROPERTY(QVector<UIController_GridCue*>, gridCues)
    BASIC_INIT_Q_PROPERTY(int, controlledGridIndex, 0)
public:
    explicit UIController_CueWorkspace(System_CueAnimator* sys_ca, QObject *parent = nullptr);

    Q_INVOKABLE void setGridCuesByPage(CuePage* page);
    //Q_INVOKABLE void selectGrid(int index);
private:
    System_CueAnimator* m_cueAnimator;
};
Q_DECLARE_METATYPE(UIController_CueWorkspace*)

#endif // UICONTROLLER_CUEWORKSPACE_H
