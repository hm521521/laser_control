#ifndef MAIN_PANEL_H
#define MAIN_PANEL_H
#include"scene_pool.h"
#include<QToolBox>
#include<QGraphicsView>
#include<QGraphicsItem>
//#include "ui_mainwindow1.h"
#include<scene_tool_box.h>
#include "dnd_scene_data_object.h"
#include "yls_play_event.h"
#include"output_panel.h"

class scene_panel;

class scene_item:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    scene_item(scene_panel *parent=nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    CJSection *item_section;
    bool show_point;
    bool show_selected;
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
//    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
//    void dragEnterEvent(QGraphicsSceneDragDropEvent *e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    scene_panel *m_parent;
    QPointF m_startPos;
signals:
    void mouse_enter(bool flag);
    void selected();
    void mouse_move();
    void pause();
};

class scene_panel:public QGraphicsView
{
    Q_OBJECT
public:
    scene_panel(QWidget *parent=0);
    ~scene_panel();
    void set_data_model(single_scene *s);
    void do_draw(bool flag);
    QGraphicsScene *m_graphicsScene;
    bool is_selected();
    bool is_mouse_enter();
    CJSection * get_picture();
    int m_frame_index;
    single_scene* get_scene();
    void update_scene(CJSection * out_picture);
    void setIndex(int idx);
private:
    single_scene* m_scene;
    CJSection m_section;
    bool m_mouse_enter;
    int m_index;
    bool m_selected;
    bool m_pause;
    QTimer *m_select_timer;
    int order=0;
public slots:
    void mouse_enter_event(bool flag);
    void selected_event();
    void on_thread_update();
    void mouse_move_event();
    void pause_event();
signals:
    void panel_index(int idx);
    void show_panel_index(int idx);
};

//class main_panel:public QObject
//{
//    Q_OBJECT
//public:
//    main_panel(QWidget *parent=0);
//    ~main_panel();
//    void set_data_model(scene_pool* sp, Scene_Stack *stack=0, Scene_Tool_Box *book=0,bool flag=true);
//    void out_to_ild();
//private:
//    scene_pool* m_scene_pool;
//    std::vector<scene_panel*> m_scene_panels;
//    scene_panel *m_panel;
//};

#endif // MAIN_PANEL_H
