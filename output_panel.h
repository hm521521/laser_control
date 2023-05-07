#ifndef OUTPUT_PANEL_H
#define OUTPUT_PANEL_H
#include<QGraphicsView>
#include<QGraphicsItem>
#include"cjsection.h"

class output_item:public QGraphicsItem
{
public:
    output_item(QGraphicsView *parent=0);
    ~output_item();
    QRectF boundingRect() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void paint(QPainter *painter,
                              const QStyleOptionGraphicsItem *option,
                              QWidget *widget=nullptr) override;
    CJSection *item_section;
private:
    QGraphicsView *m_parent;
};
class output_panel:public QGraphicsView
{
public:
    output_panel(QWidget *parent = nullptr);
    ~output_panel();
    void update_panel();
    CJSection m_picture;
//protected:
    void do_draw();
private:
    QGraphicsScene *m_graphicsScene;
    output_item *m_output_item;
};




#endif // OUTPUT_PANEL_H
