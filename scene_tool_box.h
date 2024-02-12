#ifndef SCENE_TOOL_BOX_H
#define SCENE_TOOL_BOX_H
#include<QToolBox>
#include <QObject>
#include <QStackedWidget>

class Scene_Tool_Box:public QToolBox
{
    Q_OBJECT
public:
    explicit Scene_Tool_Box(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
protected:
    //bool event(QEvent *e) override;
    //void mouseReleaseEvent(QMouseEvent* event) override;
    //void keyReleaseEvent(QKeyEvent* event) override;
    //void changeEvent(QEvent* ev) override;
signals:
    void cur_index(int index);

};

class Scene_Stack:public QStackedWidget
{
public:
    Scene_Stack(QWidget *parent = nullptr);
//public slots:
//    void setCurIndex(int index);

};

#endif // SCENE_TOOL_BOX_H
