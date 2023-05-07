#ifndef MAIN_PANEL_H
#define MAIN_PANEL_H
#include"scene_pool.h"
#include<QToolBox>
#include<QGraphicsView>
#include<QGraphicsItem>
#include "ui_mainwindow1.h"
#include "dnd_scene_data_object.h"

class scene_panel;

class scene_item:public QGraphicsItem
{

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
    CJSection * get_picture();
    bool m_selected;
    bool m_mouse_enter;
    int m_frame_index;
    single_scene* get_scene();
//    scene_item *m_item;
//    bool focusNextPrevChild(bool next) override;
private:
    single_scene* m_scene;
    CJSection m_section;

//    void on_mouse_enter();
protected:
//    void drawBackground(QPainter *painter, const QRectF &rect);
//    void mouseMoveEvent(QMouseEvent *event) override;

};

class main_panel:public QObject
{
    Q_OBJECT
public:
    main_panel(QWidget *parent=0);
    ~main_panel();
//    void set_data_model(scene_pool* sp, Ui::MainWindow1 *ui=0);
    void set_data_model(scene_pool* sp, Scene_Stack *stack=0, Scene_Tool_Box *book=0,bool flag=true);
    void update_scene(CJSection * out_picture);
    void out_to_ild();
private:
    scene_pool* m_scene_pool;
//    QToolBox* m_toolbox;
    QVector<scene_panel*> m_scene_panels;
    scene_panel *m_panel;
    QWidget *m_parent;
//    QList<scene_panel* > m_panel_list;

};

#endif // MAIN_PANEL_H
