#include "output_panel.h"
#include"main_panel.h"

output_panel::output_panel(QWidget *parent):QGraphicsView(parent)
{
    m_graphicsScene=new QGraphicsScene(this);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_graphicsScene->setBackgroundBrush(Qt::black);

}

output_panel::~output_panel()
{
//    QList<QGraphicsItem *> item_list_p;
//    if(m_graphicsScene)
//        item_list_p=m_graphicsScene->items();
//    for(int i=0;i<item_list_p.size();++i)
//    {
//        m_graphicsScene->removeItem(item_list_p[i]);
//        delete item_list_p[i];
//    }
//    m_graphicsScene->clear();
//    delete m_graphicsScene;
}


void output_panel::do_draw()
{
//    int actual_width=this->size().width();
//    int actual_height=this->size().height();
//    QRectF scenerect=QRectF(this->pos().x(),this->pos().y(),this->width()-5,this->height()-5);
    m_graphicsScene=new QGraphicsScene(this);
    this->setScene(m_graphicsScene);
    m_output_item=new output_item(this);
    m_graphicsScene->addItem(m_output_item);
    m_output_item->item_section=&m_picture;
//    m_output_item->update();//刷新面板会产生窗口重绘事件
}


output_item::output_item(QGraphicsView *parent)
    :m_parent(parent)
{

}

output_item::~output_item()
{

}

QRectF output_item::boundingRect() const
{
    QRectF tem((-m_parent->width()+2)/2,(-m_parent->height()+2)/2,m_parent->width()-2,m_parent->height()-2);
    return tem;
}

void output_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int width,height;
    width=this->boundingRect().width();
    height=this->boundingRect().height();
    item_section->draw_picture(painter,-5,-5,width,height);

}

split_panel::split_panel(QWidget *parent)
{

}

split_panel::~split_panel()
{

}

void split_panel::do_draw()
{
    m_output_item=new output_item(this);
    m_graphicsScene->addItem(m_output_item);
    m_output_item->item_section=&m_picture;
//    m_output_item->update();//刷新面板会产生窗口重绘事件
}

void split_panel::setGraphicsScene(QGraphicsScene *scene)
{
    m_graphicsScene=scene;
}
