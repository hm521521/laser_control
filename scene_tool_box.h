#ifndef SCENE_TOOL_BOX_H
#define SCENE_TOOL_BOX_H
#include<QToolBox>
#include <QObject>
#include <QStackedWidget>

class Scene_Tool_Box:public QToolBox
{
public:
    explicit Scene_Tool_Box(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
protected:
    bool event(QEvent *e) override;

};

class Scene_Stack:public QStackedWidget{
public:
    Scene_Stack(QWidget *parent = nullptr);

};

#endif // SCENE_TOOL_BOX_H
