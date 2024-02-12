#include "main_panel.h"
#include<QPainter>
#include<QGraphicsScene>
#include"scene_tool_box.h"
#include<QGraphicsSceneHoverEvent>
#include<QDebug>
#include<QDir>
#include<QDrag>
#include<QTimer>
#include<QGridLayout>
#include<QThread>
//#include<QDropEvent>

//main_panel::main_panel(QWidget *parent)//:QWidget(parent)
//{
//    m_scene_pool=new scene_pool();
//}

//main_panel::~main_panel()
//{
//    m_scene_panels.clear();

//}

//void main_panel::set_data_model(scene_pool *sp, Scene_Stack *stack, Scene_Tool_Box *book,bool flag)
//{
//    m_scene_pool=sp;
//    if(flag)
//        m_scene_panels.clear();
//   if (m_scene_pool == nullptr)
//       return;

//   book->setMaximumWidth(100);
//   book->setMaximumHeight(300);

//   int scenes_count=m_scene_pool->size();
//   int page_count=(scenes_count + 39) / 40;//每页有40个Scene,获取应该有多少页
//   for(int i=0;i<page_count;i++)
//   {
//       QWidget *wid=new QWidget();
//       stack->addWidget(wid);
//       QGridLayout *grid_sizer = new QGridLayout(wid);
//       grid_sizer->setHorizontalSpacing(0);
//       grid_sizer->setVerticalSpacing(0);
//       for (int row=0;row<5;row++)
//       {
//           for(int col=0;col<8;col++)
//           {
//               m_panel=new scene_panel(wid);
//               grid_sizer->addWidget(m_panel,row,col,1,1);
//               QRect scenerect=grid_sizer->cellRect(row,col);
//               m_panel->resize(scenerect.width(),scenerect.height());
//               m_panel->m_graphicsScene=new QGraphicsScene(scenerect);
//               m_panel->setScene(m_panel->m_graphicsScene);
//               m_scene_panels.push_back(m_panel);
//               int idx = i * 40 + row * 8 + col; //获得当前scene的index
//               if (idx<scenes_count)
//               {
//                   m_panel->set_data_model(m_scene_pool->at(idx));
//                   m_panel->do_draw(true);
//               }

//           }
//       }
//    wid->setLayout(grid_sizer);
//    QWidget * page_1 = new QWidget();
//    page_1->setObjectName(QString::fromUtf8("page_")+QString::number(i));
//    book->addItem(page_1, QString::fromUtf8("page_")+QString::number(i));
//    }
//}

//void main_panel::update_scene(CJSection *out_picture)
//{

//    for(int i=0;i<m_scene_panels.size();++i)
//    {
//        m_scene_panels.at(i)->do_draw(false);
//        if(m_scene_panels.at(i)->is_selected()&&out_picture)
//        {
//            CJSection* picture=m_scene_panels.at(i)->get_picture();
//            if(picture->size()>0)
//            {
//                out_picture->insert(out_picture->end(),picture->begin(),picture->end());
//            }
//        }
//    }
//}

//void main_panel::out_to_ild()
//{
//    QString dir_str="./test2/";
//    QDir dir;
//    float scale=4095/32767;
//    if(!dir.exists(dir_str))
//    {
//        dir.mkpath(dir_str);
//    }
//    for(int i=0;i<m_scene_panels.size();i++)
//    {
//        if(m_scene_panels.at(i)->get_scene()==nullptr)
//        {
//            continue;
//        }
//        int m_frame_index=0;
//        QString pi=QString::number(i);
//        QString filedir=dir_str+pi+".ild";
//        QFile myfile(filedir);
//        bool ret=myfile.open(QIODevice::NewOnly|QIODevice::Truncate);
//        bool ret1=myfile.open(QIODevice::WriteOnly|QIODevice::Truncate);
//        if(!ret&&!ret1)
//        {
//            continue;
//        }
//        else
//        {
//            QDataStream aStream(&myfile);
//            if(m_scene_panels.at(i)->get_scene()==nullptr)
//            {
//                continue;
//            }
//            while(m_frame_index<m_scene_panels.at(i)->get_scene()->max_frame_length())
//            {
//                char header[]="ILDA";
//                aStream.writeRawData(header,4);
//                char format[3];
//                int a=0;
//                memcpy(format,&a,sizeof(format));
//                aStream.writeRawData(format,3);
//                a=5;
//                char format1[1];
//                memcpy(format1,&a,sizeof(format1));
//                aStream.writeRawData(format1,1);
//                char frame[]="Frame";
//                aStream.writeRawData(frame,5);
//                char framename[3];
//                a=m_frame_index;
//                memcpy(framename,&a,3);
//                aStream.writeRawData(framename,sizeof(framename));
//                char companyname[]="yls";
//                aStream.writeRawData(companyname,8);
//                CJSection m_section;
//                m_scene_panels.at(i)->get_scene()->render(&m_section,m_frame_index);
//                m_frame_index++;
//                if(m_section.size()==0) continue;
//                a=m_section.size();
//                char numpoints[2];
//                memcpy(numpoints,&a,sizeof(numpoints));
//                aStream.writeRawData(numpoints,2);
//                char framenum[2];
//                a=i;
//                memcpy(framenum,&a,sizeof(framenum));
//                aStream.writeRawData(framenum,2);
//                char totalframes[2];
//                a=m_scene_panels.at(i)->get_scene()->size();
//                memcpy(totalframes,&a,sizeof(totalframes));
//                aStream.writeRawData(totalframes,2);
//                char pronum[1];
//                a=0;
//                memcpy(pronum,&a,sizeof(pronum));
//                aStream.writeRawData(pronum,1);
//                char reserved[1];
//                a=0;
//                memcpy(reserved,&a,sizeof(reserved));
//                aStream.writeRawData(reserved,1);
//                for(int j=0;j<(int)m_section.size();j++)
//                {
//                    a=m_section.at(j).X*scale;
//                    char secA[2];
//                    memcpy(secA,&a,sizeof(secA));
//                    aStream.writeRawData(secA,2);
//                    a=m_section.at(j).Y*scale;
//                    memcpy(secA,&a,sizeof(secA));
//                    aStream.writeRawData(secA,2);
//                    char ch[1];
//                    a=0;
//                    if (m_section.at(j).B==0&&m_section.at(j).G==0&&m_section.at(j).R==0)
//                    a=1<<6;
//                    memcpy(ch,&a,sizeof(ch));
//                    aStream.writeRawData(ch,1);
//                    a=m_section.at(j).B;
//                    memcpy(ch,&a,sizeof(ch));
//                    aStream.writeRawData(ch,1);
//                    a=m_section.at(j).G;
//                    memcpy(ch,&a,sizeof(ch));
//                    aStream.writeRawData(ch,1);
//                    a=m_section.at(j).R;
//                    memcpy(ch,&a,sizeof(ch));
//                    aStream.writeRawData(ch,1);

//                }
//            }

//            myfile.close();
//        }
//    }
//}

scene_panel::scene_panel(QWidget *parenet):QGraphicsView(parenet),
    m_graphicsScene(nullptr),
    m_selected(false),
    m_mouse_enter(false),
    m_frame_index(0),
    m_scene(nullptr),
    m_pause(false)
{
//    setDragMode(QGraphicsView::RubberBandDrag);
    setAcceptDrops(false);
//    m_enter_timer=new QTimer(this);
//    connect(m_enter_timer,SIGNAL(timeout()),this,SLOT(on_thread_update()));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

scene_panel::~scene_panel()
{
    m_graphicsScene->clear();
    delete m_graphicsScene;
}

void scene_panel::set_data_model(single_scene *s)
{
    this->m_scene=s;
}


void scene_panel::do_draw(bool flag)
{
    if(flag||(m_selected||m_mouse_enter))
    {
        m_section.clear();
        if(this->m_scene!=nullptr)
            this->m_scene->render(&m_section,m_frame_index);
        if(this->m_section.size()==0) return;
        scene_item *item=new scene_item(this);
        connect(item,SIGNAL(mouse_enter(bool)),this,SLOT(mouse_enter_event(bool)));
        connect(item, SIGNAL(mouse_move()), this, SLOT(mouse_move_event()));
        connect(item,SIGNAL(selected()),this,SLOT(selected_event()));
        connect(item, SIGNAL(pause()), this, SLOT(pause_event()));
        this->m_graphicsScene->addItem(item);
        item->item_section=&m_section;
//        temp->update();//刷新面板会产生窗口重绘事件
        if(!m_pause)
            m_frame_index++;
        if(this->m_scene==nullptr||m_frame_index>=m_scene->max_frame_length())
        {
            m_frame_index=0;
        }

    }
}

bool scene_panel::is_selected()
{
    return m_selected;
}

bool scene_panel::is_mouse_enter()
{
    return m_mouse_enter;
}

CJSection* scene_panel::get_picture()
{
    return &m_section;
}

single_scene *scene_panel::get_scene()
{
    return m_scene;
}

void scene_panel::update_scene(CJSection *out_picture)
{
    do_draw(false);
    if(m_selected&&out_picture)
    {
        CJSection* picture=get_picture();
        if(picture->size()>0)
        {
            out_picture->insert(out_picture->end(),picture->begin(),picture->end());
        }
    }
}

void scene_panel::setIndex(int idx)
{
    m_index=idx;
}

void scene_panel::mouse_enter_event(bool flag)//鼠标移入决定开启线程
{
    m_mouse_enter=flag;
    if(m_mouse_enter)
        emit show_panel_index(m_index);
}

void scene_panel::selected_event()
{
    mouse_enter_event(true);
    m_selected=!m_selected;
}

void scene_panel::on_thread_update()
{
    if(m_selected)
    {
        emit panel_index(m_index);
//        do_draw(true);
    }
    else if(m_mouse_enter)//当没被选中，但鼠标还在框内
    {
        emit panel_index(m_index-40);
        do_draw(false);
    }
    else if(!m_mouse_enter)
    {
        m_frame_index=0;
        do_draw(true);
        emit panel_index(m_index-40);//如果index=-1,意味播放停止
    }
}

void scene_panel::mouse_move_event()
{
    selected_event();
    
}

void scene_panel::pause_event()
{
    m_pause = !m_pause;
}



scene_item::scene_item(scene_panel *parent):
    item_section(nullptr),
    show_point(false),
    show_selected(false),
    m_startPos(0,0)
{
    m_parent=parent;
    setAcceptHoverEvents(true);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
//    setAcceptDrops(true);
//    setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF scene_item::boundingRect() const
{
    QRectF tem((-m_parent->width()+2)/2,(-m_parent->height()+2)/2,m_parent->width()-2,m_parent->height()-2);
    return tem;
}

void scene_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int width,height;
    width=this->boundingRect().width();
    height=this->boundingRect().height();
    item_section->draw_picture(painter,0,0,width,height);
    if (m_parent->is_selected())
    {
        painter->setBrush(Qt::gray);
        painter->translate(-(width) / 2, -(height) / 2);
        painter->drawRect(0,height-15,width,15);//灰色控制条
        painter->setBrush(Qt::black);
        QPixmap pixmap1("首页 icon-24_选中1-停止.png");
        painter->drawPixmap(3,height-12,pixmap1,0,0,9,9);
        painter->translate((width) / 2, (height) / 2);
    }
}

void scene_item::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit mouse_enter(true);
    QGraphicsItem::hoverEnterEvent(event);
}

void scene_item::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit mouse_enter(false);
    QGraphicsItem::hoverLeaveEvent(event);
}

void scene_item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {

        if (m_parent->is_selected())
        {
            qDebug() << "event->pos().y()+boundingRect().height() / 2 :" << event->pos().y() + boundingRect().height() / 2;
            qDebug() << "boundingRect().height() - 15:" << boundingRect().height() - 15;
            if (event->pos().y()+boundingRect().height() / 2 > boundingRect().height() - 15)
            {
                qDebug()<< "event->pos().x()+ boundingRect().width() / 2 :" << event->pos().x() + boundingRect().width() / 2 ;
                if (event->pos().x()+ boundingRect().width() / 2 > 15)
                {
                    emit pause();
                    return;
                }
            }
        }
        m_startPos = event->pos();
        emit selected();
    }
    
}

void scene_item::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if(m_parent->get_scene())
    {
        dnd_scene_data_object *scene_data=new dnd_scene_data_object(m_parent->get_scene());
        QDrag *dg=new QDrag((QObject*)event->widget());
        dg->setMimeData(scene_data);
        Qt::DropAction action=dg->exec(Qt::MoveAction|Qt::CopyAction,Qt::LinkAction);
        emit mouse_move();
        emit mouse_enter(false);
    }
}

void scene_item::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {

    }
}









