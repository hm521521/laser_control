#include "project_panel.h"
#define TICK_PANEL_HEIGHT		30
#define MEDIA_PANEL_HEIGHT		60
#define LASER_PANEL_HEIGHT		60
#define PANEL_INTERVAL_HEIGHT	5
#define HEADER_INTERVAL_WIDTH	5
#define TICK_INTERVAL_WIDTH    50//一个格代表2秒
#define DEFAULT_FRAME_RATE  40//默认帧率
#include<QGraphicsSceneDragDropEvent>
#include<QMimeData>
#include"dnd_scene_data_object.h"
//#include<QUrl>
//#include "windows.h"

//project_panel::project_panel(QWidget *parent):QGraphicsView(parent)
//{
//    m_track_panel =new track_panel(this);
//}

//project_panel::~project_panel()
//{
//    QList<QGraphicsItem *> item_list_p=m_graphicsScene->items();
//    for(int i=0;i<item_list_p.size();++i)
//    {
//        m_graphicsScene->removeItem(item_list_p[i]);
//        delete item_list_p[i];
//    }
//    m_graphicsScene->clear();
//    delete m_graphicsScene;
//}



//void project_panel::update_panel(QRectF rec)
//{
//    scene()->setSceneRect(rec);
//}

//void project_panel::set_scene(QGraphicsScene *scene)
//{
//    this->setScene(scene);
//    m_graphicsScene=scene;
//
//    m_graphicsScene->addItem(m_track_panel);
//    m_track_panel->update();//刷新面板会产生窗口重绘事件
//}

//void project_panel::play()
//{
//    m_track_panel->play();
//}

//void project_panel::stop()
//{
//    m_track_panel->stop();
//}

//void project_panel::update_show(CJSection *out_picture)
//{
//    m_track_panel->update_show(out_picture);
//}

//void project_panel::mousePressEvent(QMouseEvent *event)
//{
//    QGraphicsView::mousePressEvent(event);
//}




//track_panel::track_panel(project_panel *parent)
//    :m_parent(parent)
//    ,m_play_start(0)
//{
//    Init();
//    setAcceptDrops(true);
//
//}


//track_panel::~track_panel()
//{
//
//}

//QRectF track_panel::boundingRect() const
//{
//    QRectF tem(m_parent->pos().x(),m_parent->pos().y(),m_width,m_height);
//    return tem;
//}

//void track_panel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    int width,height;
//    if (m_width<m_parent->width())
//        m_width=m_parent->width();
//    if(m_height<m_parent->height())
//        m_height=m_parent->height();
//    width=m_width;
//    height=m_height;
//    if(width<100||height<10)
//        return;
//    int track_start_x=m_header_width + HEADER_INTERVAL_WIDTH;//80+5
//    painter->setPen(Qt::lightGray);
//    painter->setBrush(Qt::lightGray);
//    painter->drawRect(track_start_x,0,width - track_start_x, TICK_PANEL_HEIGHT);
//    {
//        {
//            painter->setPen(0xFFFF4D);
//            painter->setBrush(QBrush(0xFFFF4D));
//            painter->drawRect(0,0,20,TICK_PANEL_HEIGHT);
//        }
//        {
//            painter->setPen(0x0080FF);
//            painter->setBrush(QBrush(0x0080FF));
//            painter->drawRect(20,0,20,TICK_PANEL_HEIGHT);
//        }
//        {
//            painter->setPen(0xFF8000);
//            painter->setBrush(QBrush(0xFF8000));
//            painter->drawRect(40,0,20,TICK_PANEL_HEIGHT);
//        }
//        {
//            painter->setPen(0x63F563);
//            painter->setBrush(QBrush(0x63F563));
//            painter->drawRect(60,0,20,TICK_PANEL_HEIGHT);
//        }
//        painter->setPen(Qt::white);
//        painter->setFont(QFont("Times",6,QFont::Bold));
//        painter->drawText(QRect(0,0,20,10),Qt::AlignCenter,"h");
//        painter->drawText(QRect(20,0,20,10),Qt::AlignCenter,"m");
//        painter->drawText(QRect(40,0,20,10),Qt::AlignCenter,"s");
//        painter->drawText(QRect(60,0,20,10),Qt::AlignCenter,"ms");
//        int ms = (m_play_pos * this->m_show_model.get_interval() + this->m_show_model.get_x_end());
//        int s=ms/1000;
//        QString time_h = QString::asprintf("%02d",s/3600);
//        QString time_m = QString::asprintf("%02d",s%3600/60);
//        QString time_s = QString::asprintf("%02d",s%60);
//        QString time_hms = QString::asprintf("%03d",ms/1000);
//        painter->drawText(QRect(0,10,20,20),Qt::AlignCenter,time_h);
//        painter->drawText(QRect(20,10,20,20),Qt::AlignCenter,time_m);
//        painter->drawText(QRect(40,10,20,20),Qt::AlignCenter,time_s);
//        painter->drawText(QRect(60,10,20,20),Qt::AlignCenter,time_hms);
//    }
//    for (int i = track_start_x; i < width; i++)//画刻度
//    {
//        int pos=(i-track_start_x)+ this->m_show_model.get_x_end() / this->m_show_model.get_interval();
//        if(pos%100==0)
//        {
//            painter->setPen(QColor(255,0,0));
//            painter->drawLine(i,TICK_PANEL_HEIGHT - 10, i, TICK_PANEL_HEIGHT);
//            int num = ((i - track_start_x) * this->m_show_model.get_interval() + this->m_show_model.get_x_end()) / 1000;
//            QString s = QString::asprintf("%02d:%02d:%02d", num / 3600, num % 3600 / 60, num % 60);
//            painter->drawText(i, TICK_PANEL_HEIGHT / 2,s);
//        }
//        else if(pos%10==0)
//        {
//            painter->setPen(QColor(0, 255, 0));
//            painter->drawLine(i, TICK_PANEL_HEIGHT - 5, i, TICK_PANEL_HEIGHT);
//        }
//    }
//    for (int i = 0; i < m_media_track_count; i++)
//    {
//        int media_start_y = get_media_start_y(i);
//        painter->setPen(Qt::gray);
//        painter->setBrush(Qt::gray);
//        painter->drawRect(0, media_start_y, m_header_width, MEDIA_PANEL_HEIGHT);
//        painter->drawRect(track_start_x, media_start_y, width - track_start_x, MEDIA_PANEL_HEIGHT);
//        painter->setPen(Qt::black);
//        QString title=QString::asprintf("Media %d", i);
//        painter->drawText(QRect(0, media_start_y, m_header_width, MEDIA_PANEL_HEIGHT),Qt::AlignCenter,title);
//        for(int i = 0; i < m_medias.size(); i++)
//        {
//            if(m_medias.at(i)->m_track_index==i)
//            {
//                int meidia_width = m_medias.at(i)->get_frame_length()*40/m_show_model.get_interval();
//                m_medias.at(i)->draw_level(painter,track_start_x, media_start_y, meidia_width, MEDIA_PANEL_HEIGHT);
//
//            }
//        }
//    }
//    for(int i=0;i<m_scene_track_count;i++)
//    {
//        int media_start_y=get_laser_start_y(i);
//        painter->setPen(Qt::lightGray);
//        painter->setBrush(Qt::lightGray);
//        painter->drawRect(0,media_start_y,m_header_width,LASER_PANEL_HEIGHT);
//        painter->drawRect(track_start_x, media_start_y, width - track_start_x, LASER_PANEL_HEIGHT);
//        QString title=QString::asprintf("轨道%d",i);
//        painter->setPen(Qt::black);
//        painter->drawText(QRect(0,media_start_y, m_header_width, MEDIA_PANEL_HEIGHT),Qt::AlignCenter,title);
//        for (int j = 0; j < m_scenes.size(); ++j)
//        {
//            if (m_scenes.at(j).m_track_index == i)
//            {
//                painter->setPen(Qt::green);
//                painter->setBrush(Qt::green);
//                painter->drawRect(m_scenes.at(j).m_start_x, media_start_y, m_scenes.at(j).m_end_x - m_scenes.at(j).m_start_x, LASER_PANEL_HEIGHT);
//
////                //画scene缩略图
//                CJSection section;
//                m_scenes.at(j).m_scene->render(&section, 0);
//                section.draw_picture(painter, m_scenes.at(j).m_start_x+LASER_PANEL_HEIGHT/2, media_start_y+LASER_PANEL_HEIGHT/2, LASER_PANEL_HEIGHT, LASER_PANEL_HEIGHT);
////                painter->drawText(m_scenes.at(j).m_start_x + LASER_PANEL_HEIGHT, media_start_y,m_scenes.at(j).m_scene->get_name());
//            }
//        }
//    }
//    //播放位置
//    painter->setPen(Qt::yellow);
//    painter->drawLine(track_start_x + m_play_pos, 0, track_start_x + m_play_pos, height);
//    if(m_laser_x!=-1)
//    {
//        if(m_mouse_move_mode != MOUSE_MOVE_MODE::MMM_NONE)
//        {
//            int left=-1;
//            int right=-1;
//            if (m_mouse_move_mode == MOUSE_MOVE_MODE::MMM_MEDIA_DRAG)
//            {
//                for(int i=0;i<m_medias.size();++i)
//                {
//                    if (m_medias.at(i)->m_track_index == m_current_index)
//                    {
//                        left = m_medias.at(i)->m_start_x;
//                        right = m_medias.at(i)->m_start_x + m_medias.at(i)->get_frame_length() * 40 / this->m_show_model.get_interval();
//                        break;
//                    }
//                }
//            }
//            else
//            {
//                scene_info si = m_scenes.at(m_current_index);
//                left = si.m_start_x;
//                right = si.m_end_x;
//            }
//            //左
//            if(left!=-1)
//            {
//                painter->setPen(Qt::yellow);
//                painter->drawLine(left, 0, left, height);
//            }
//            //右
//            if(right!=-1)
//            {
//                painter->setPen(Qt::yellow);
//                painter->drawLine(right, 0, right, height);
//            }
//        }
//    }
//}

//void track_panel::Init()
//{
//    m_media_track_count = 1;
//    m_scene_track_count = 3;
//    m_header_width = 80;
//    m_play_pos = 0.f;
//    m_last_x = -1;
//    m_mouse_move_mode = MOUSE_MOVE_MODE::MMM_NONE;
//    m_current_index = -1;
//    m_frame_index = 0;
//}

//void track_panel::dropEvent(QGraphicsSceneDragDropEvent *event)
//{
//    int width,height;
//    width=m_parent->width();
//    height=m_parent->height();
//    QPointF p(event->pos().x(),event->pos().y());
//    if(p.x()<(m_header_width+HEADER_INTERVAL_WIDTH))
//        return;
//    int media_track_index=on_media_track(p.y());
//
//    if(-1!=media_track_index)
//    {
//        //判断该位置上是否有media，如果有，退出
//        for(int i=0;i<m_medias.size();++i)
//        {
//            if(m_medias.at(i)->m_track_index==media_track_index)
//            {
//                return;
//            }
//        }
//        if(event->mimeData()->hasUrls())
//        {
//            QList<QUrl> urls=event->mimeData()->urls();
//            if(urls.isEmpty())
//            {
//                return;
//            }
//
//            QString filename=urls.first().toLocalFile();
//            media_info* mi=new media_info(p.x(),media_track_index,this);
//            if(mi->load_file(filename))
//            {
//                m_medias.push_back(mi);
//            }
//            else
//            {
//                delete mi;
//            }
//        }
//
//    }
//    int scene_track_index=on_scene_track(p.y());
//    if(-1!=scene_track_index)
//    {
//        if((dnd_scene_data_object*)event->mimeData())
//        {
//            dnd_scene_data_object* scene_data=(dnd_scene_data_object*)event->mimeData();
//            add_scene(p.x(),p.y(),scene_data->m_scene);
//        }
//        else
//        {
//            return;
//        }
//     }
//
//
//}

//void track_panel::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
//{
//    if (event->mimeData()->hasUrls()) {
//        event->acceptProposedAction();  // 3. 有拖拽文件时设置接受
//    }
//    else if((dnd_scene_data_object*)event->mimeData())
//    {
//        event->acceptProposedAction();
//    }
//}

//void track_panel::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (event->button()==Qt::LeftButton)
//    {
//        int x=event->pos().x();
//        int y=event->pos().y();
//        int start_x=m_header_width+HEADER_INTERVAL_WIDTH;
//        if(x<start_x)
//            return;
//        if(on_tick_panel(y))
//        {
//            m_play_pos=x-start_x;
//            update();
//            return;
//        }
//        else
//        {
//            int media_idx=on_media_track(y);
//            if(-1!=media_idx)
//            {
//                if(get_media(x,y)!=nullptr)
//                {
//                    m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_MEDIA_DRAG;
//                    m_current_index=media_idx;
//                    m_last_x=x;
//                    update();
//                    return;
//                }
//
//            }
//            else
//            {
//                int laser_index=on_scene_track(y);
//                if(-1!=laser_index)
//                {
//                    m_last_x=x;
//                    set_selected_scene(laser_index);
//                    update();
//                    return;
//                }
//            }
//        }
//        m_current_index=-1;
//        m_last_x=-1;
//        m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_NONE;
//
//    }
//    else if(event->button()==Qt::RightButton)
//    {
//        m_menu=new QMenu();
//        del=new QAction("删除");
//        m_menu->addAction(del);
//        m_menu->exec(QCursor::pos());

//        int x=event->pos().x();
//        int y=event->pos().y();
//        int start_x=m_header_width+HEADER_INTERVAL_WIDTH;
//        if(x<start_x)
//            return;
//        if(on_tick_panel(y))
//        {
//            return;
//        }
//        else
//        {
//            int media_idx=on_media_track(y);
//            if(-1!=media_idx)
//            {
//                if(get_media(x,y)!=nullptr)
//                {
////                    m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_MEDIA_DRAG;
//                    m_current_index=media_idx;
//                    m_last_x=x;
//                    update();
//                    return;
//                }

//            }
//        }

//        pMenu->popup(event->pos());
//    }
//}
//void track_panel::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
//{
//    m_menu=new QMenu();
//    del=new QAction("删除");
//    m_menu->addAction(del);
//    right_click_pos=QCursor::pos();
//    m_menu->exec(QCursor::pos());
//    connect(del,SIGNAL(triggered(bool)),this,SLOT(slotRemoveItem(bool)));
//}

//void track_panel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    if(event->button()==Qt::LeftButton)
//    {
//        m_current_index = -1;
//        m_last_x = -1;
//        m_mouse_move_mode = MOUSE_MOVE_MODE::MMM_NONE;
//        update();
//    }
//}

//void track_panel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
   /* int x=event->pos().x();
    int y=event->pos().y();
    int start_x = m_header_width + HEADER_INTERVAL_WIDTH;

        if(m_mouse_move_mode==MOUSE_MOVE_MODE::MMM_MEDIA_DRAG)
        {
            media_info* mi=nullptr;
            for(int i=0;i<m_medias.size();++i)
            {
                if(m_medias.at(i)->m_track_index==m_current_index)
                {
                    mi=m_medias.at(i);
                    break;
                }
            }
            if(mi!=nullptr)
            {
                if(m_last_x!=-1)
                {
                    mi->m_start_x+=(x-m_last_x);
                    if(mi->m_start_x<start_x)
                    {
                        mi->m_start_x=start_x;
                    }
                    if(x-m_last_x>0)
                    {
                        update_width();
                    }
                }
                m_last_x=x;
                update();
            }
            return;
        }
        else if(m_mouse_move_mode == MOUSE_MOVE_MODE::MMM_SCENE_DRAG)
        {
            scene_info obj = this->m_scenes.at(m_current_index);
            if(m_last_x != -1)
            {
                int x_pos = obj.m_start_x + (x - m_last_x);
                if (x_pos < start_x)
                    x_pos = start_x;
                obj.m_end_x+=(x_pos-obj.m_start_x);
                obj.m_start_x=x_pos;
                update_width(obj.m_end_x);
            }
            m_last_x=x;
            update();
            return;

        }
        else if(m_mouse_move_mode == MOUSE_MOVE_MODE::MMM_SCENE_LEFT_MOVE)
        {
            scene_info obj=m_scenes.at(m_current_index);
            obj.m_start_x=x;
            if(obj.m_start_x<start_x)
            {
                obj.m_start_x=start_x;
            }
            else if((obj.m_start_x+1)>=obj.m_end_x)
            {
                obj.m_start_x=(obj.m_end_x-1);
            }
            update();
            return;
        }
        else if(m_mouse_move_mode == MOUSE_MOVE_MODE::MMM_SCENE_RIGHT_MOVE)
        {
            scene_info obj=m_scenes.at(m_current_index);
            obj.m_end_x = x;
            if((obj.m_start_x+1)>=obj.m_end_x)
                obj.m_end_x=(obj.m_start_x+1);
            update_width(obj.m_end_x);
            update();
            return;

        }*/
//}

//bool track_panel::on_tick_panel(int y)
//{
//    return y >= 0 && y <= TICK_PANEL_HEIGHT;
//}

//void track_panel::set_selected_scene(int track_index)
//{
//    int idx=0;
//    for(int i=0;i<m_scenes.size();++i)
//    {
//        auto m=m_scenes.at(i);
//        if(m.m_track_index==track_index)
//        {
//            if(m.is_moving(m_last_x))
//            {
//                m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_SCENE_DRAG;
//                m_current_index=idx;
//                return;
//            }
//            else if(m.on_start_pos(m_last_x))
//            {
//                m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_SCENE_LEFT_MOVE;
//                m_current_index=idx;
//                return;
//            }
//            else if(m.on_end_pos(m_last_x))
//            {
//                m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_SCENE_RIGHT_MOVE;
//                m_current_index=idx;
//                return;
//            }
//        }
//        idx++;
//    }
//}

//int track_panel::on_scene_track(int y)
//{
//    for(int i=0;i<m_scene_track_count;i++)
//    {
//        int start_y=get_laser_start_y(i);
//        if(y>=start_y&&y<=(start_y+MEDIA_PANEL_HEIGHT))
//        {
//            return i;
//        }
//    }
//    return -1;
//}

//float track_panel::get_stop_postion()
//{
    /*float pos=0.f;
    for(int i=0;i<m_medias.size();++i)
    {
        if(pos<(m_medias.at(i)->m_start_x+m_medias.at(i)->get_frame_length()))
            pos=(m_medias.at(i)->m_start_x+m_medias.at(i)->get_frame_length());
    }
    for(int i=0;i<m_scenes.size();++i)
    {
        auto s=m_scenes.at(i);
        if(pos<s.m_end_x)
            pos=s.m_end_x;
    }
    return pos;*/
    //return 0;
//}

//void track_panel::slotRemoveItem(bool flag)
//{
//    int x=right_click_pos.x();
//    int y=right_click_pos.y();
//    int start_x=m_header_width+HEADER_INTERVAL_WIDTH;
//    if(x<start_x)
//        return;
//    if(on_tick_panel(y))
//    {
//        return;
//    }
//    else
//    {
//        int media_idx=on_media_track(y);
//        if(-1!=media_idx)
//        {
//            auto medi=get_media(x,y);
//            if(medi!=nullptr)
//            {
//                for(int i=0;i<m_medias.size();i++)
//                {
//                    if(m_medias.at(i)==medi)
////                        m_medias.erase(m_medias.begin()+i);
//                        m_medias.remove(i);
//                }
//                update();//画图
//                return;
//            }
//
//        }
//    }
//
//}


//int track_panel::get_media_start_y(int idx)//idx代表第几条轨道
//{
//    int y=0;
//    if(idx>=0&&idx<m_media_track_count)
//        y = TICK_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT //media区域y开始位置
//        + idx * (MEDIA_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT);//每增加一个media，高度增加media高度+间隔高度
//    return y;
//}

//int track_panel::get_laser_start_y(int idx)
//{
//    int y=0;
//    if(idx>=0 && idx<m_scene_track_count)
//        y = TICK_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT //media区域开始高度
//                + m_media_track_count * (MEDIA_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT) //laser区域y开始位置
//                + idx * (LASER_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT);//每增加一个laser，高度增加laser高度+间隔高度
//    return y;
//}

//media_info *track_panel::get_media(int x, int y)
//{
  /*  media_info* mi=nullptr;
    int idx=on_media_track(y);
    if(-1!=idx)
    {
        for(int i=0;i<m_medias.size();++i)
        {
            if(m_medias.at(i)->m_track_index==idx)
            {
                mi=m_medias.at(i);
                break;
            }
        }
    }
    if(mi!=nullptr)
    {
        if(x>=mi->m_start_x&&x<=(mi->m_start_x+mi->get_frame_length()))
            return mi;
    }
    return nullptr;*/
    //return nullptr;
//}

//int track_panel::on_media_track(int y)
//{
//    for(int i=0;i<m_media_track_count;i++)
//    {
//        int start_y=get_media_start_y(i); //返回轨道的开始高度
//        if (y>=start_y&&y<=(start_y+MEDIA_PANEL_HEIGHT))//判断drop的点是否在当前媒体轨道上
//        {
//            return i;
//        }
//    }
//    return -1;
//}

//void track_panel::update_width()
//{
   /* int w=this->boundingRect().width();
    int h=this->boundingRect().height();
    int max_width=w;
    for(int i=0;i<m_medias.count();++i)
    {
        int media_length=m_medias.at(i)->get_frame_length()*40/this->m_show_model.get_interval();
        int width=m_medias.at(i)->m_start_x+media_length;
        if(width>max_width)
            max_width=width;
    }
    if(max_width>w)
    {
        m_width=max_width;
    }
    QRectF rec=this->scene()->sceneRect();
    rec.setWidth(m_width);
    m_parent->update_panel(rec);*/
//}

//void track_panel::update_width(int x)
//{
//    int w=m_width;
//    int h=m_height;
//    if(x>w)
//    {
//        m_width=x;
//        QRectF rec=this->scene()->sceneRect();
//        rec.setWidth(m_width);
//        m_parent->update_panel(rec);
//        scroll(w,-1);
//    }
//}

//void track_panel::play()
//{
//
//}

//void track_panel::stop()
//{
//    m_frame_index=0;
//    for(int i=0;i<m_medias.size();++i)
//    {
//        m_medias.at(i)->m_mp3_player->stop();
//        m_medias.at(i)->m_play_flag=false;
//    }
//}

//void track_panel::update_show(CJSection *out_picture)
//{
    //int start_x = m_header_width + HEADER_INTERVAL_WIDTH;
    ////帧率是25，即一次播放40ms，指示器位置移动40毫秒，除以刻度单位，即移动的长度
    //m_play_pos += (40.0 / this->m_show_model.get_interval());

    //if ((m_play_pos + start_x) > get_stop_postion())
    //{
    //    m_play_pos=0;
    //}
    //for(int i=0;i<m_medias.size();++i)
    //{
    //    auto m=m_medias.at(i);
    //    int idx = (m_play_pos + start_x - m->m_start_x);
    //    //10像素=40ms
    //    m->m_mp3_player->setPosition(idx*40);
    //    if(!m->m_play_flag)
    //    {
    //        m->m_mp3_player->play();
    //        m->m_play_flag=true;
    //    }

    //}
    //for(int i=0;i<m_scenes.size();++i)
    //{
    //    auto s=m_scenes.at(i);
    //    if((m_play_pos+start_x)>=s.m_start_x&&(m_play_pos+start_x)<=s.m_end_x)
    //    {
    //        int idx=(m_play_pos+start_x-s.m_start_x);
    //        idx=idx%s.m_scene->max_frame_length();
    //        s.m_scene->render(out_picture,idx);
    //    }
    //}
    //update();
    //m_frame_index++;
//}

//void track_panel::add_scene(int x, int y, single_scene *scene)
//{
//    if(x < (m_header_width + HEADER_INTERVAL_WIDTH))
//        return;
//    if(scene)
//    {
//        int track_index=this->on_scene_track(y);
//        if(track_index != -1)
//        {
//            int width=scene->max_frame_length()*40/this->m_show_model.get_interval();
//            m_scenes.push_back(scene_info(scene,x,x+width,track_index));
//            update();
//        }
//    }
//}

//scene_info::scene_info(single_scene *scene, int start_x, int end_x, int track_index)
//    :m_start_x(start_x)
//    ,m_end_x(end_x)
//    ,m_track_index(track_index)
//{
//    m_scene=new single_scene();
//    for(int i=0;i<scene->size();++i)
//    {
//            effect *m_effect=nullptr;
//            switch(scene->at(i)->get_type())
//            {
//                case EffectType::ET_PICTURE:
//                {
//                    m_effect=new point_effect();
//                    m_effect->Param.point_param.m_start_index=scene->at(i)->Param.point_param.m_start_index;
//                    m_effect->Param.point_param.m_end_index = scene->at(i)->Param.point_param.m_end_index;//给m_end_index初始化
//                    break;
//                }
//                case EffectType::ET_TEXT:
//                {
//                    m_effect = new text_effect();
//                    break;
//                }
//                case EffectType::ET_TIME:
//                {
//                    m_effect = new time_effect();
//                    break;
//                }
//                case EffectType::ET_BLACK:
//                {
//                m_effect = new BlackEffect();
//                    break;
//            }
//            case EffectType::ET_COLOR:
//             {
//                m_effect = new color_effect();
//                    break;
//            }
//            case EffectType::ET_X_MOVE:
//             {
//                m_effect = new XMoveEffect();
//                    break;
//            }
//            case EffectType::ET_Y_MOVE:
//             {
//                m_effect = new YMoveEffect();
//                    break;
//            }
//            case EffectType::ET_Z_MOVE:
//             {
//                m_effect = new ZMoveEffect();
//                    break;
//            }
//            case EffectType::ET_X_ROTATE:
//             {
//                m_effect = new XRotateEffect();
//                    break;
//            }
//            case EffectType::ET_Y_ROTATE:
//             {
//                m_effect = new YRotateEffect();
//                    break;
//            }
//            case EffectType::ET_Z_ROTATE:
//             {
//                m_effect = new ZRotateEffect();
//                    break;
//            }
//            case EffectType::ET_X_SIZE:
//             {
//                m_effect = new XSizeEffect();
//                    break;
//            }
//            case EffectType::ET_Y_SIZE:
//             {
//                m_effect = new YSizeEffect();
//                    break;
//            }
//            case EffectType::ET_X_INVERT:
//             {
//                m_effect = new XInvertEffect();
//                    break;
//            }
//            case EffectType::ET_Y_INVERT:
//             {
//                m_effect = new YInvertEffect();
//                    break;
//            }
//            case EffectType::ET_XY_SIZE:
//             {
//                m_effect = new xy_size_effect();
//                    break;
//            }
//            case EffectType::ET_GRADUALLY_RENDER:
//             {
//                m_effect = new gradually_render_effect();
//                    break;
//            }
//            }
////        m_scene->at(i)->set_type(scene->at(i)->get_type());
//
//        m_effect->set_pictures(scene->at(i)->get_pictures());
//        m_effect->set_index(scene->at(i)->get_index());
//        m_effect->set_start_index(scene->at(i)->get_start_index());
//        m_effect->set_frame_length(scene->at(i)->get_frame_length());
//        m_effect->Param=scene->at(i)->Param;
//        m_scene->push_back(m_effect);
//    }
//
//
//}




scene_info::scene_info(single_scene* scene):
    m_scene(scene)
{
    
}

void scene_info::load_scene(float start_time, int frame_length, float relative_rate)
{
    m_start_time = start_time;
    m_time_length = timeLength(frame_length, relative_rate);
}

//bool scene_info::operator==(scene_info &other)
//{
//    return this->m_start_x == other.m_start_x
//            && this->m_end_x == other.m_end_x
//            && this->m_scene == other.m_scene
//            && this->m_track_index == other.m_track_index;
//}

//bool scene_info::is_moving(int x)
//{
//    return x>m_start_x&&x<m_end_x;
//}

//bool scene_info::on_start_pos(int x)
//{
//    return x==m_start_x;
//}

//bool scene_info::on_end_pos(int x)
//{
//    return x==m_end_x;
//}
media_info::media_info(QWidget *parent):
    m_mp3_player(new QMediaPlayer(this))
  ,m_decoder(new QAudioDecoder(this))
  ,m_play_flag(false)

{
    
    m_playlist = new QMediaPlaylist(this);//
    m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce); //循环模式
    m_mp3_player->setPlaylist(m_playlist);
    /*m_wavePlot=addGraph();*/
    connect(m_mp3_player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMediaPlayer::State)));
    connect(m_mp3_player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));
    connect(m_mp3_player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
    connect(m_playlist,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));
    connect(m_decoder,SIGNAL(bufferReady()),this,SLOT(setBuffer()));//将解码结束的信号由setBuffer接受
    connect(m_decoder,SIGNAL(finished()),this,SLOT(plot()));

}
media_info::~media_info()
{
    if(m_mp3_player)
        delete m_mp3_player;
    m_mp3_player=nullptr;
}
bool media_info::load_file(float start_time, const QString &name)
{
    m_start_time = start_time;
    m_filename=name;
    m_mp3_player->setMedia(QUrl::fromLocalFile(name));
    QMediaPlayer::Error err=m_mp3_player->error();
    m_sample.clear();
    QAudioFormat format;
    format.setSampleRate(44100);//设置采样率 mps默认采样率44100Hz
    format.setSampleSize(16);
    //format.setSampleType(QAudioFormat::SignedInt);
    format.setCodec("audio/pcm");
    m_decoder->setAudioFormat(format);
    m_decoder->setSourceFilename(name);
    m_decoder->start();
    if (err)
        return false;
    return true;
}

int media_info::get_frame_length()
{
    int length=m_sample.size();

    return length;
}

void media_info::draw_level(QPainter *painter, int x, int y, int width, int height)
{
    //float scale=(double)width/m_sample.size();
    //painter->setPen(Qt::yellow);
    //painter->setBrush(Qt::yellow);
    //painter->drawRect(m_start_x,y,width,height);//2个像素画1个点
    //painter->setPen(Qt::black);
    //painter->drawText(1,0,m_filename);
    //painter->setPen(Qt::red);
    //float y_center=height/2.0;
    //for(int i=0;i<width;i++)
    //{
    //    int idx=i/scale;
    //    if(idx<(int)m_sample.size())
    //    {
    //        int value=m_sample.at(idx);
    //        painter->drawLine(m_start_x+i,y+y_center-value,m_start_x+i,y+y_center+value);
    //    }
    //}

}

void media_info::onStateChanged(QMediaPlayer::State)
{

}

void media_info::onPositionChanged(qint64)
{

}

void media_info::onDurationChanged(qint64)
{

}

void media_info::onPlaylistChanged(int)
{

}



qreal media_info::getPeakValue(const QAudioFormat &format)
{
    qreal ret(0);
        if (format.isValid()){
            switch (format.sampleType()) {
                case QAudioFormat::Unknown:
                break;
                case QAudioFormat::Float:
                    if (format.sampleSize() != 32) // other sample formats are not supported
                        ret = 0;
                    else
                        ret = 1.00003;
                break;
                case QAudioFormat::SignedInt:
                    if (format.sampleSize() == 32)
    #ifdef Q_OS_WIN
                        ret = INT_MAX;
    #endif
    #ifdef Q_OS_UNIX
                        ret = SHRT_MAX;
    #endif
                    else if (format.sampleSize() == 16)
                        ret = SHRT_MAX;
                    else if (format.sampleSize() == 8)
                        ret = CHAR_MAX;
                    break;
                case QAudioFormat::UnSignedInt:
                    if (format.sampleSize() == 32)
                        ret = UINT_MAX;
                    else if (format.sampleSize() == 16)
                        ret = USHRT_MAX;
                    else if (format.sampleSize() == 8)
                        ret = UCHAR_MAX;
                break;
            default:
                break;
            }
        }
        return ret;
}

void media_info::setBuffer()//处理解码结果
{
    if(!m_decoder->bufferAvailable()) return;
    m_buffer=m_decoder->read();
    m_buffer_length += m_buffer.duration();
    m_time_length = m_buffer_length / 1000000;
    //m_time_length = m_buffer.duration()/1000000;
    //qreal peak=getPeakValue(m_buffer.format());
    //const quint16 *data=m_buffer.constData<quint16>();
    //int count=m_buffer.sampleCount()/2;
    //for(int i=0;i<count;i++)
    //{
    //    double val=data[i]/peak;
    //    m_sample.push_back(val);
    //}
}

void media_info::plot()
{
    //m_track_panel->update_width();
    //m_track_panel->update();
}

//media_panel::media_panel(project_panel* parent)
//{
//}

//QRectF media_panel::boundingRect() const
//{
//    return QRectF();
//}

//void media_panel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
//{
//
//}




track_list_widget::track_list_widget(QWidget *parent, Qt::WindowFlags f)
{
    media_track* mt = new media_track("media_track_1",m_interval_prop,this);
    mt->setObjectName("media_track_1");
    connect(mt, SIGNAL(set_Width(int)), this, SLOT(resetWidth(int)));
    connect(mt, SIGNAL(setCurrentTime(float)), this, SLOT(setCurrent(float)));
    connect(mt, SIGNAL(deleteInfo(int)), this, SLOT(infoDeleted(int)));
    mt->setIndex(0);
    media_track_list.push_back(mt);
    for (int i = 0; i < 3; i++)
    {
        QString str = "scene_track_"+QString("%1").arg(i+1);
        scene_track* lt = new scene_track(str, this);
        lt->setObjectName(str);
        connect(lt, SIGNAL(set_Width(int)), this, SLOT(resetWidth(int)));
        connect(lt, SIGNAL(setCurrentTime(float)), this, SLOT(setCurrent(float)));
        connect(lt, SIGNAL(deleteInfo(int)), this, SLOT(infoDeleted(int)));
        scene_track_list.push_back(lt);
        lt->setIndex(media_track_list.size()+scene_track_list.size()-1);        
    }
    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true); 
    setPalette(pal);
    setFixedWidth(150);
    setFixedHeight(media_track_list.size() * MEDIA_PANEL_HEIGHT + scene_track_list.size() * LASER_PANEL_HEIGHT+30);
    emit set_Height(this->height());
    m_context_menu = new QMenu(this);
    QAction* add_media_track = new QAction("add_media_track", this);
    connect(add_media_track, SIGNAL(triggered(bool)), this, SLOT(addMediaTrack(bool)));
    m_context_menu->addAction(add_media_track);
    QAction* add_scene_track = new QAction("add_scene_track", this);
    connect(add_scene_track, SIGNAL(triggered(bool)), this, SLOT(addSceneTrack(bool)));
    m_context_menu->addAction(add_scene_track);

}

void track_list_widget::paintEvent(QPaintEvent* event)
{
    QPainter* painter = new QPainter(this);
    int width, height;
    width = this->width();
    height = this->height();
    if (width < 100 || height < 10)
        return;
    painter->setPen(Qt::lightGray);
    painter->setBrush(Qt::lightGray);
    
    painter->setFont(QFont("Times", 8, QFont::Bold));
    for (int i = 0; i < media_track_list.size(); i++)
    {
        QPen pen = painter->pen();
        QBrush brush = painter->brush();
        int index = media_track_list.at(i)->getIndex();
        brush.setColor(Qt::GlobalColor((index + 7) % 20));
        pen.setColor(Qt::lightGray);

        painter->setOpacity(0.3);
        pen.setWidth(2);
        painter->setPen(pen);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(0,i * MEDIA_PANEL_HEIGHT, width, MEDIA_PANEL_HEIGHT);//整个大框
        painter->setBrush(QBrush(Qt::GlobalColor((index + 7) % 20)));
        painter->drawRect(0,i * MEDIA_PANEL_HEIGHT, 20, MEDIA_PANEL_HEIGHT - 10);//左窄框
        painter->setOpacity(0.2);
        painter->drawRect(0, (i + 1) * MEDIA_PANEL_HEIGHT - 10, width, 10);//下横框
        painter->setOpacity(1);
        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(QRect(20, i * MEDIA_PANEL_HEIGHT, width, MEDIA_PANEL_HEIGHT / 3), Qt::AlignLeft, "A/V Media");

    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        QPen pen = painter->pen();
        QBrush brush = painter->brush();
        int index = scene_track_list.at(i)->getIndex();
        brush.setColor(Qt::GlobalColor((index + 7) % 20));
        pen.setColor(Qt::lightGray);
        painter->setOpacity(0.3);
        pen.setWidth(2);
        painter->setPen(pen);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(0, media_track_list.size() * MEDIA_PANEL_HEIGHT + i * LASER_PANEL_HEIGHT, width, LASER_PANEL_HEIGHT);//整个大框
        painter->setBrush(QBrush(Qt::GlobalColor((index + 7) % 20)));
        painter->drawRect(0, media_track_list.size() * MEDIA_PANEL_HEIGHT + i * LASER_PANEL_HEIGHT, 20, LASER_PANEL_HEIGHT - 10);//左窄框
        painter->setOpacity(0.2);
        painter->drawRect(0, (media_track_list.size() + 1) * MEDIA_PANEL_HEIGHT - 10 + i * LASER_PANEL_HEIGHT, width, 10);//下横框
        painter->setOpacity(1);
        pen.setColor(Qt::white);
        painter->setPen(pen);

        painter->drawText(QRect(20, media_track_list.size() * MEDIA_PANEL_HEIGHT + i * LASER_PANEL_HEIGHT, width, MEDIA_PANEL_HEIGHT / 3), Qt::AlignLeft, QString("轨道%1").arg(i + 1));

    }
    QRectF target(5, media_track_list.size() * MEDIA_PANEL_HEIGHT + scene_track_list.size() * LASER_PANEL_HEIGHT, 30.0, 30.0);
    QRectF source(0.0, 0.0, 30, 30);
    QImage image("plus.png");

    painter->drawImage(target, image, source);
    delete painter;
}

void track_list_widget::setMarginWidth(const int&)
{
}

void track_list_widget::seResizable(bool)
{
}

void track_list_widget::setCurrentTime(int time_interval)
{
    if (time_interval == 0)
        m_current_time = 0;
    else
        m_current_time += (float)time_interval / 1000;
    for (int i = 0; i < media_track_list.size(); i++)
    {
        auto mt = media_track_list.at(i);
        mt->m_current_time = m_current_time;
        mt->update();

    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        auto mt = scene_track_list.at(i);
        mt->m_current_time = m_current_time;
        mt->update();
    }
    update();

}

void track_list_widget::play(bool flag)
{
    for (int i = 0; i < media_track_list.size(); i++)
    {
        media_track*mtl=media_track_list.at(i);
        mtl->play(flag);
    }
    
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        scene_track* stl = scene_track_list.at(i);
        stl->play(flag);
    }
}

void track_list_widget::updateOutputScene(CJSection* picture)
{
    picture->clear();
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        auto st = scene_track_list.at(i);
        st->udateOutputScene(picture);
    }
}

bool track_list_widget::hasinfo()
{
    for (int i = 0; i < media_track_list.size(); i++)
    {
        if (media_track_list.at(i)->info_list.size() > 0)
            return true;
    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        if (scene_track_list.at(i)->info_list.size() > 0)
            return true;
    }
    return false;
}

void track_list_widget::mousePressEvent(QMouseEvent* event)
{
    int current_height = media_track_list.size() * MEDIA_PANEL_HEIGHT + scene_track_list.size() * LASER_PANEL_HEIGHT;
    if (event->pos().y() > current_height && event->pos().y() < current_height + LASER_PANEL_HEIGHT)
    {
        m_context_menu->exec(QCursor::pos());
    }
}

void track_list_widget::setCurrent(float ct)
{
    if (hasinfo())
    {
        m_current_time = ct;
        
    }
    else
    {
        m_current_time = 0;
    }
    for (int i = 0; i < media_track_list.size(); i++)
    {
        media_track_list.at(i)->m_current_time = m_current_time;
        media_track_list.at(i)->update();
    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        scene_track_list.at(i)->m_current_time = m_current_time;
        scene_track_list.at(i)->update();
    }
    emit setCurrentTime(m_current_time);
    update();
}

void track_list_widget::infoDeleted(int index)
{
    if (!hasinfo())
    {
        setCurrent(0);
    }
    
    for (int i = 0; i < media_track_list.size(); i++)
    {
        if (media_track_list.at(i)->m_index == index && media_track_list.size() > 1&&media_track_list.at(i)->info_list.size()==0)
        {
            auto mt = media_track_list.at(i);
            media_track_list.erase(media_track_list.begin() + i);
            mt->deleteLater();
            setFixedHeight(this->height()-MEDIA_PANEL_HEIGHT);
            qDebug() << "set_Height(this->height()-MEDIA_PANEL_HEIGHT)" << this->height() - MEDIA_PANEL_HEIGHT;
            emit set_Height(this->height());
            return;
        }
    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        if (scene_track_list.at(i)->m_index == index && scene_track_list.size() > 1&&scene_track_list.at(i)->info_list.size()==0)
        {
            auto mt = scene_track_list.at(i);
            scene_track_list.erase(scene_track_list.begin() + i);
            mt->deleteLater();
            setFixedHeight(this->height() - LASER_PANEL_HEIGHT);
            emit set_Height(this->height());
            return;
        }
    }
    
    
}

void track_list_widget::addMediaTrack(bool)
{
    QString str = "media_track_" + QString("%1").arg(media_track_list.size() + 1);
    media_track* mt = new media_track(str, m_interval_prop, this);
    mt->setObjectName(str);
    connect(mt, SIGNAL(set_Width(int)), this, SLOT(resetWidth(int)));
    connect(mt, SIGNAL(setCurrentTime(float)), this, SLOT(setCurrent(float)));
    connect(mt, SIGNAL(deleteInfo(int)), this, SLOT(infoDeleted(int)));
    media_track_list.push_back(mt);
    std::vector<int> indexlist;
    for (int i = 0; i < media_track_list.size(); i++)
    {
        indexlist.push_back(media_track_list.at(i)->m_index);
    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        indexlist.push_back(scene_track_list.at(i)->m_index);
    }
    int index = 0;
    for (int i = 0; i < media_track_list.size() + scene_track_list.size(); i++)
    {
        if (std::find(indexlist.begin(), indexlist.end(), i) == indexlist.end())
        {
            index = i;
            break;
        }
    }
    mt->setIndex(index);
    emit addTrack(0);
    this->setFixedHeight(this->height()+MEDIA_PANEL_HEIGHT);
    emit set_Height(this->height());
    update();
    
}

void track_list_widget::addSceneTrack(bool)
{
    QString str = "scene_track_" + QString("%1").arg(scene_track_list.size() + 1);
    scene_track* lt = new scene_track(str, this);
    lt->setObjectName(str);
    connect(lt, SIGNAL(set_Width(int)), this, SLOT(resetWidth(int)));
    connect(lt, SIGNAL(setCurrentTime(float)), this, SLOT(setCurrent(float)));
    connect(lt, SIGNAL(deleteInfo(int)), this, SLOT(infoDeleted(int)));
    scene_track_list.push_back(lt);
    std::vector<int> indexlist;
    for (int i = 0; i < media_track_list.size(); i++)
    {
        indexlist.push_back(media_track_list.at(i)->m_index);
    }
    for (int i = 0; i < scene_track_list.size(); i++)
    {
        indexlist.push_back(scene_track_list.at(i)->m_index);
    }
    int index = 0;
    for (int i = 0; i < media_track_list.size() + scene_track_list.size(); i++)
    {
        if (std::find(indexlist.begin(), indexlist.end(), i) == indexlist.end())
        {
            index = i;
            break;
        }
    }
    lt->setIndex(index);    
    emit addTrack(1);
    this->setFixedHeight(this->height() + LASER_PANEL_HEIGHT);
    emit set_Height(this->height());
    update();
}

scene_track::scene_track(QString name, QWidget* parent, Qt::WindowFlags f)
    :common_track(parent),m_name(name)
{
    setFixedHeight(LASER_PANEL_HEIGHT);
    this->setAcceptDrops(true);
    m_menu = new QMenu(this);
    QAction* del = new QAction("delete", this);
    connect(del, SIGNAL(triggered(bool)), this, SLOT(delete_info(bool)));
    m_menu->addAction(del);
    outputSection = new CJSection(this);
}

void scene_track::paintEvent(QPaintEvent* event)
{
    QPainter* painter = new QPainter(this);
    QPen pen = painter->pen();
    QBrush brush = painter->brush();
    brush.setColor(Qt::GlobalColor((m_index + 7) % 20));
    pen.setColor(Qt::lightGray);
    painter->setOpacity(0.3);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(0,0, width(), LASER_PANEL_HEIGHT);//整个大框
    painter->setBrush(QBrush(Qt::GlobalColor((m_index + 7) % 20)));
    painter->setOpacity(0.2);
    painter->drawRect(0, LASER_PANEL_HEIGHT-10, width(), 10);//下横框
    
    for (int i = 0; i < info_list.size(); i++)
    {
        painter->setBrush(QBrush(Qt::GlobalColor((m_index + 7) % 20)));
        painter->setOpacity(1);
        scene_info * si = (scene_info*)info_list.at(i);

        int time_length = si->m_time_length;

        int newWidth = XConversion(time_length + si->m_start_time, m_interval_prop);
        if (newWidth > width())
        {
            this->resize(QSize(newWidth, height()));//修改media_track的宽度
            emit set_Width(newWidth);
        }
        painter->drawRect(XConversion(si->m_start_time,m_interval_prop),0,XConversion(si->m_time_length,m_interval_prop),LASER_PANEL_HEIGHT);
        CJSection cj;
        si->m_scene->render(&cj, 0);
        painter->translate(LASER_PANEL_HEIGHT/2, LASER_PANEL_HEIGHT/2);
        cj.draw_picture(painter, XConversion(si->m_start_time, m_interval_prop), 0, LASER_PANEL_HEIGHT, LASER_PANEL_HEIGHT);
        painter->translate(-LASER_PANEL_HEIGHT / 2, -LASER_PANEL_HEIGHT / 2);
    }
    painter->setOpacity(1);
    pen.setColor(Qt::green);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawLine(XConversion(m_current_time, m_interval_prop), 0, XConversion(m_current_time, m_interval_prop), this->height());
    delete painter;
}

QString scene_track::getName()
{
    return m_name;
}

void scene_track::setIndex(int idx)
{
    m_index = idx;
}

bool scene_track::hasInfo(scene_info* mi)
{
    for (int i = 0; i < info_list.size(); i++)
    {
        auto mili = info_list.at(i);
        if (mi->m_start_time > mili->m_start_time &
            mi->m_start_time < mili->m_start_time + mili->m_time_length)
            return true;
        else if (mi->m_start_time + mi->m_time_length > mili->m_start_time & mi->m_start_time + mi->m_time_length  < mili->m_start_time + mili->m_time_length)
            return true;
    }
    return false;
    
}

void scene_track::play(bool flag)
{
    if (outputSection)
    {
        outputSection->clear();
        for (int i = 0; i < info_list.size(); i++)
        {
            auto si = info_list.at(i);
            CJSection pic;
            if (flag)
            {
                if (si->m_start_time < m_current_time && m_current_time < (si->m_start_time + si->m_time_length))
                {
                    si->m_scene->render(&pic, frameLength(m_current_time - si->m_start_time, relative_frame_rate));
                    outputSection->insert(outputSection->end(), pic.begin(), pic.end());
                }
            }
        }
    }
}

void scene_track::udateOutputScene(CJSection* picture)
{
    for (int i = 0; i < info_list.size(); i++)
    {
        auto si = info_list.at(i);
        if(outputSection->size()>0)
        picture->insert(picture->end(), outputSection->begin(), outputSection->end());
    }
}

int scene_track::getIndex()
{
    return m_index;
}



void scene_track::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();  // 3. 有拖拽文件时设置接受

}

void scene_track::dropEvent(QDropEvent* event)
{
    QPointF p(event->pos().x(), event->pos().y());
    if (p.x() < 0)
        return;
    if ((dnd_scene_data_object*)event->mimeData()&& !event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();  // 3. 有拖拽文件时设置接受
        //scene_info* scene_data=(scene_info*)event->mimeData();
        dnd_scene_data_object* sd = (dnd_scene_data_object*)event->mimeData();
        scene_info* scene_data=new scene_info(sd->m_scene);
        float start_time = timeConversion(p.x(), m_interval_prop);
        
        scene_data->load_scene(start_time,scene_data->m_scene->max_frame_length(),relative_frame_rate);
        if (!hasInfo(scene_data))
        {

            info_list.push_back(scene_data);
            update();
        }
    }
    else
    {
        return;
    }
    
}

void scene_track::dragMoveEvent(QDragMoveEvent* event)
{
    event->acceptProposedAction();  // 3. 有拖拽文件时设置接受
}

void scene_track::mouseMoveEvent(QMouseEvent* event)
{
    for (int i = 0; i < info_list.size(); i++)
    {
        auto mi = info_list.at(i);
        if (current_pos.x() > XConversion(mi->m_start_time, m_interval_prop) & current_pos.x() < XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop))
        {
            m_MMM = MOUSE_MOVE_MODE::MMM_DRAG;
            return;
        }
    }
    m_MMM = MOUSE_MOVE_MODE::MMM_NONE;
}

void scene_track::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton & m_MMM == MOUSE_MOVE_MODE::MMM_DRAG)
    {
        int d = event->pos().x() - current_pos.x();//获取拖拽距离
        for (int i = 0; i < info_list.size(); i++)
        {
            auto mi = info_list.at(i);
            if (current_pos.x() > XConversion(mi->m_start_time, m_interval_prop) & current_pos.x() < XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop))
            {
                for (int j = 0; j < info_list.size(); j++)
                {
                    if (i == j) continue;
                    if (mi->m_start_time + timeConversion(d, m_interval_prop) + mi->m_time_length > info_list.at(j)->m_start_time & mi->m_start_time < info_list.at(j)->m_start_time)
                    {

                        mi->m_start_time = info_list.at(j)->m_start_time - (mi->m_time_length);//判断如果拖拽后的媒体大于其他媒体的开始时间，就把其他媒体的开始时间设置为结束时间
                        update();
                        return;
                    }
                    if (mi->m_start_time + timeConversion(d, m_interval_prop) < (info_list.at(j)->m_start_time + info_list.at(j)->m_time_length) & mi->m_start_time > info_list.at(j)->m_start_time)
                    {
                        d = XConversion((info_list.at(j)->m_start_time + info_list.at(j)->m_time_length) - mi->m_start_time, m_interval_prop);
                        mi->m_start_time = mi->m_start_time + timeConversion(d, m_interval_prop);
                        update();
                        return;//判断如果拖拽后的媒体的开始时间小于其他媒体的结束时间，就把开始时间设置为其他媒体的结束时间
                    }
                }
                mi->m_start_time = mi->m_start_time + timeConversion(d, m_interval_prop);
                if (XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop) > this->width())
                {
                    resize(XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop), this->height());
                    emit set_Width(XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop));
                }
                current_pos = event->pos();
                update();
                return;
            }
        }
    }
    else if (event->button() == Qt::LeftButton)
    {
        m_current_time = timeConversion(current_pos.x(), m_interval_prop);
        emit setCurrentTime(m_current_time);
        update();
    }
}

void media_track::delete_info(bool)
{
    if (info_list.size() == 0) emit deleteInfo(m_index);;
    for (int i = info_list.size()-1; i >-1; i--)
    {
        auto mili = info_list.at(i);
        if (timeConversion(context_pos.x(), m_interval_prop) > mili->m_start_time &
            timeConversion(context_pos.x(), m_interval_prop) < mili->m_start_time + mili->m_time_length)
        {
            if(info_list.at(i)->m_mp3_player->state()==QMediaPlayer::PlayingState)
                info_list.at(i)->m_mp3_player->stop();
            info_list.erase(info_list.begin() + i);
            emit deleteInfo(-1);
            update();
            return;
        }

            
        
    }
}
void scene_track::delete_info(bool)
{
    if (info_list.size() == 0)
    {
        emit deleteInfo(m_index);
    }
    for (int i = info_list.size() - 1; i > -1; i--)
    {
        auto mili = info_list.at(i);
        if (timeConversion(context_pos.x(), m_interval_prop) > mili->m_start_time &
            timeConversion(context_pos.x(), m_interval_prop) < mili->m_start_time + mili->m_time_length)
        {
            info_list.erase(info_list.begin() + i);
            update();
            emit deleteInfo(-1);
            return;
        }        
    }
}
media_track::media_track(QString name, float interval_prop, QWidget* parent, Qt::WindowFlags f)
    :common_track(parent), 
    m_name(name),
    m_interval_prop(interval_prop),
    temp_buffer_length(-1000)
{
    
    setFixedHeight(MEDIA_PANEL_HEIGHT);
    setAcceptDrops(true);
    m_menu = new QMenu(this);
    QAction* del = new QAction("delete", this);
    connect(del, SIGNAL(triggered(bool)), this, SLOT(delete_info(bool)));
    m_menu->addAction(del);

}

void media_track::paintEvent(QPaintEvent* event)
{
    QPainter* painter = new QPainter(this);
    QPen pen = painter->pen();
    QBrush brush = painter->brush();
    brush.setColor(Qt::GlobalColor((m_index + 7) % 20));
    pen.setColor(Qt::lightGray);

    painter->setOpacity(0.3);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(0,  0, width(), MEDIA_PANEL_HEIGHT);//整个大框
    painter->setBrush(QBrush(Qt::GlobalColor((m_index + 7) % 20)));
    painter->setOpacity(0.2);
    painter->drawRect(0, MEDIA_PANEL_HEIGHT - 10, width(), 10);//下横框
    painter->setOpacity(1);
    //pen.setColor(Qt::white);
    //painter->setPen(pen);
    //画媒体轨道上的媒体
    for (int i = 0; i < info_list.size(); i++)
    {
        media_info* mi = (media_info*)info_list.at(i);
        int time_length = mi->m_time_length;
        
        int newWidth=XConversion(time_length + mi->m_start_time, m_interval_prop);
        if ( newWidth> width())
        {
            this->resize(QSize(newWidth, height()));//修改media_track的宽度
            emit set_Width(newWidth);
        }
        painter->drawRect(XConversion(mi->m_start_time,m_interval_prop),0, XConversion(time_length, m_interval_prop),MEDIA_PANEL_HEIGHT-10);
    
    }
    painter->setOpacity(1);
    pen.setColor(Qt::green);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawLine(XConversion(m_current_time, m_interval_prop), 0, XConversion(m_current_time, m_interval_prop), this->height());
    delete painter;
}

void media_track::setIndex(int idx)
{
    m_index = idx;
}

bool media_track::hasInfo(media_info *mi)
{
    for (int i = 0; i < info_list.size(); i++)
    {
        auto mili = info_list.at(i);
        if (mi->m_start_time > mili->m_start_time &
            mi->m_start_time < mili->m_start_time + mili->m_time_length)
            return true;
        else if (mi->m_start_time + mi->m_time_length > mili->m_start_time & mi->m_start_time + mi->m_time_length < mili->m_start_time + mili->m_time_length)
            return true;
    }
    return false;
}

void media_track::play(bool flag)
{

    for (int i = 0; i < info_list.size(); i++)
    {
        auto mi = info_list.at(i);
        if (flag)
        {            
            if (mi->m_start_time < m_current_time && m_current_time<(mi->m_start_time+mi->m_time_length))
            {
                if (mi->m_mp3_player->state() == QMediaPlayer::PlayingState)
                    continue;
                else if (mi->m_mp3_player->state() == QMediaPlayer::StoppedState)
                {
                    mi->m_mp3_player->setPosition((m_current_time - mi->m_start_time)*1000);
                    mi->m_mp3_player->play();
                }
            }
        }
        else 
        {
            if (mi->m_start_time < m_current_time && m_current_time < (mi->m_start_time + mi->m_time_length))
            {
                if (mi->m_mp3_player->state() == QMediaPlayer::PlayingState)
                    mi->m_mp3_player->stop();
                else 
                    continue;
            }
            else
            {
                if (!mi->m_mp3_player->state() == QMediaPlayer::StoppedState)
                {
                    mi->m_mp3_player->stop();
                }
            }
        }
    }
}

int media_track::getIndex()
{
    return m_index;
}


void media_track::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();  // 3. 有拖拽文件时设置接受
    }
}

void media_track::dropEvent(QDropEvent* event)
{
    QPointF p(event->pos().x(), event->pos().y());
    if (p.x() < 0)
        return;
    if (event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
        QList<QUrl> urls = event->mimeData()->urls();
        if (urls.isEmpty())
        {
            return;
        }

        QString filename = urls.first().toLocalFile();
        float start_time=timeConversion(p.x(), m_interval_prop);

        media_info *new_media = new media_info(this);
        new_media->load_file(start_time,filename);
        
        QTimer* timer = new QTimer(this);
        timer->setInterval(50);
        connect(timer, &QTimer::timeout, [=]() {
            if (new_media->m_buffer_length == temp_buffer_length)
            {
                if (!hasInfo(new_media))
                {
                    info_list.push_back(new_media);
                    temp_buffer_length = -100;
                    update();
                }
                if (timer->isActive())
                {
                    timer->stop();
                }
            }
            else
            {
                temp_buffer_length = new_media->m_buffer_length;
                
            }
                
            });
        timer->start();
    }
}


void media_track::dragMoveEvent(QDragMoveEvent* event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();  // 3. 有拖拽文件时设置接受
    }
}

void scene_track::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        current_pos = event->pos();
    }
    else if(event->button() == Qt::RightButton)
    {
        context_pos = event->pos();
        this->m_menu->exec(QCursor::pos());
        
    }
}
void media_track::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        current_pos = event->pos();
    }
    else if (event->button() == Qt::RightButton)
    {
        context_pos = event->pos();
        this->m_menu->exec(QCursor::pos());

    }
}
common_track::common_track(QWidget* parent, Qt::WindowFlags f)
{


}

void media_track::mouseMoveEvent(QMouseEvent* event)
{
    for (int i = 0; i < info_list.size(); i++)
    {
        auto mi = info_list.at(i);
        if (current_pos.x() > XConversion(mi->m_start_time, m_interval_prop) & current_pos.x() < XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop))
        {
            m_MMM = MOUSE_MOVE_MODE::MMM_DRAG;
            return;
        }
    }
    m_MMM = MOUSE_MOVE_MODE::MMM_NONE;
}

void media_track::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton&m_MMM==MOUSE_MOVE_MODE::MMM_DRAG)
    {
        int d = event->pos().x() - current_pos.x();//获取拖拽距离
        for (int i = 0; i < info_list.size(); i++)
        {
            auto mi = info_list.at(i);
            if (current_pos.x() > XConversion(mi->m_start_time, m_interval_prop) & current_pos.x() < XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop))
            {
                for (int j = 0; j < info_list.size(); j++)
                {
                    if (i == j) continue;
                    if (mi->m_start_time + timeConversion(d, m_interval_prop) + mi->m_time_length > info_list.at(j)->m_start_time & mi->m_start_time<info_list.at(j)->m_start_time)
                    {
                        
                        mi->m_start_time = info_list.at(j)->m_start_time - (mi->m_time_length);//判断如果拖拽后的媒体大于其他媒体的开始时间，就把其他媒体的开始时间设置为结束时间
                        update();
                        return;
                    }
                    if (mi->m_start_time + timeConversion(d, m_interval_prop) < (info_list.at(j)->m_start_time + info_list.at(j)->m_time_length) & mi->m_start_time > info_list.at(j)->m_start_time)
                    {
                        d = XConversion((info_list.at(j)->m_start_time + info_list.at(j)->m_time_length) - mi->m_start_time,m_interval_prop);
                        mi->m_start_time=mi->m_start_time+ timeConversion(d, m_interval_prop);
                        update();
                        return;//判断如果拖拽后的媒体的开始时间小于其他媒体的结束时间，就把开始时间设置为其他媒体的结束时间
                    }
                }
                mi->m_start_time = mi->m_start_time+timeConversion(d, m_interval_prop);
                if (XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop) > this->width())
                {
                    resize(XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop), this->height());
                    emit set_Width(XConversion(mi->m_start_time + mi->m_time_length, m_interval_prop));
                }
                current_pos = event->pos();
                update();
                return;
            }
        }
    }
    else if (event->button() == Qt::LeftButton)
    {
        m_current_time = timeConversion(current_pos.x(), m_interval_prop);
        emit setCurrentTime(m_current_time);
        update();
    }
}


track_project_panel::track_project_panel(QWidget* parent, Qt::WindowFlags f)
{
    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(pal);
}

void track_project_panel::paintEvent(QPaintEvent* event)
{
    QPainter *painter = new QPainter(this);
    
    QPen pen = painter->pen();
    painter->setOpacity(1);
    pen.setColor(Qt::green);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawLine(XConversion(m_current_time, m_interval_prop), 0, XConversion(m_current_time, m_interval_prop), this->height());
    delete painter;
}

void track_project_panel::setTrackList(track_list_widget* tlw)
{
    m_track_list = tlw;
    connect(tlw, SIGNAL(set_Width(int)), this, SLOT(set_Width(int)));
    this->setFixedHeight(m_track_list->height());
    QVBoxLayout *m_verticallayout = new QVBoxLayout(this);
    m_verticallayout->setSpacing(0);
    m_verticallayout->setMargin(0);
    this->setContentsMargins(0, 0, 0, 0);
    for (int i = 0; i < m_track_list->media_track_list.size(); i++)
    {
        auto mtl = m_track_list->media_track_list.at(i);
        connect(mtl, SIGNAL(set_Width(int)), this, SLOT(set_Width(int)));
        m_verticallayout->addWidget(m_track_list->media_track_list.at(i));
    }
    for (int i = 0; i < m_track_list->scene_track_list.size(); i++)
    {
        auto mtl = m_track_list->scene_track_list.at(i);
        connect(mtl, SIGNAL(set_Width(int)), this, SLOT(set_Width(int)));
        m_verticallayout->addWidget(m_track_list->scene_track_list.at(i));
    }
    QSpacerItem* verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_verticallayout->addSpacerItem(verticalSpacer_3);
    this->setLayout(m_verticallayout);
    update();
}

void track_project_panel::updateTracks()
{

}

void track_project_panel::deleteItem(int index)
{
    QLayoutItem* item = this->layout()->takeAt(index); // 取出要删除的项
    if (item) {
        QWidget* widget = item->widget(); // 如果该项是 QWidget，取出指向该 QWidget 的指针
        if (widget) {
            widget->deleteLater(); // 删除该 QWidget
        }
        else {
            delete item; // 如果该项不是 QWidget，直接删除该项
        }
    }
}

void track_project_panel::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_current_time = timeConversion(event->pos().x(), m_interval_prop);
        if (m_track_list->hasinfo())
            m_track_list->setCurrent(m_current_time);
        else
            m_track_list->setCurrent(0);
    }
}


void track_project_panel::set_Height(int height)
{
    setFixedHeight(height);
}

void track_project_panel::setCurrent(float ct)
{
    m_current_time = ct;
    update();
}

void track_project_panel::acceptAddTrack(bool flag)
{
       
    if (flag)//如果是scene_track
    {
        //this->setFixedHeight(this->height()+LASER_PANEL_HEIGHT);
        deleteItem(this->layout()->count()-1);
        this->layout()->addWidget(m_track_list->scene_track_list.at(m_track_list->scene_track_list.size() - 1));
        QSpacerItem* verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        auto lay = (QVBoxLayout*)this->layout();
        lay->addSpacerItem(verticalSpacer_3);
    }
    else
    {
        //this->setFixedHeight(this->height() + MEDIA_PANEL_HEIGHT);
        deleteItem(this->layout()->count() - 1);
        auto lay = (QVBoxLayout*)this->layout();
        lay->insertWidget(m_track_list->media_track_list.size() - 1, m_track_list->media_track_list.at(m_track_list->media_track_list.size() - 1));
                     
        QSpacerItem* verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        
        lay->addSpacerItem(verticalSpacer_3);
    }
}

tick_panel::tick_panel( QWidget* parent, Qt::WindowFlags f)
{
    setFixedHeight(TICK_PANEL_HEIGHT);
}
void tick_panel::resizeWidth(int width)
{
    this->resize(width,this->height());
}
void tick_panel::paintEvent(QPaintEvent* event)
{
    QPainter* painter = new QPainter(this);
    painter->setBrush(Qt::gray);
    painter->drawRect(0, 0, width(), TICK_PANEL_HEIGHT);
    for (int i = 0; i < width(); i++)//画刻度
    {
        int pos = i;
        if (pos % int(2 * m_interval_prop * TICK_INTERVAL_WIDTH) == 0)
        {
            painter->setPen(QColor(255, 0, 0));
            painter->drawLine(pos , TICK_PANEL_HEIGHT - 10, pos, TICK_PANEL_HEIGHT);//画10个像素长的竖线

            int num = pos * 4 / (2 * m_interval_prop * TICK_INTERVAL_WIDTH);
            QString s;
            if (num / 3600 == 0)
                s = QString::asprintf("%02d:%02d", num % 3600 / 60, num % 60);
            else
                s = QString::asprintf("%02d:%02d:%02d", num / 3600, num % 3600 / 60, num % 60);
            painter->setPen(Qt::white);
            painter->setFont(QFont("Times", 7));
            painter->drawText(i, TICK_PANEL_HEIGHT / 2, s);
        }
        else if (pos % int(m_interval_prop * TICK_INTERVAL_WIDTH) == 0)
        {
            painter->setPen(QColor(0, 255, 0));
            painter->drawLine(pos , TICK_PANEL_HEIGHT - 5, pos , TICK_PANEL_HEIGHT);//画5个像素长的短线
        }
    }
    delete painter;
}

float timeConversion(int x, float invertal_prop)
{
    float time = (x) / (TICK_INTERVAL_WIDTH * invertal_prop) * 2;
    return time;
}

int XConversion(float time, float invertal_prop)
{
    int start_x = time/2 * TICK_INTERVAL_WIDTH * invertal_prop;
    return start_x;
}

float timeLength(int frame_length, float frame_rate)
{
    float time = frame_length / (frame_rate*DEFAULT_FRAME_RATE);
    return time;
}

int frameLength(float time_length, float frame_rate)
{
    int frame_length = time_length * (frame_rate*DEFAULT_FRAME_RATE);
    return frame_length;
}

void track_project_panel::set_Width(int width)
{
    this->resize(width,this->height());
}

list_tick::list_tick(QWidget* parent, Qt::WindowFlags f)
{
}

void list_tick::paintEvent(QPaintEvent* event)
{
    QPainter* painter = new QPainter(this);
    int width, height;
    width = this->width();
    height = this->height();
    if (width < 100 || height < 10)
        return;
    painter->setPen(Qt::lightGray);
    painter->setBrush(Qt::lightGray);
    int headwidth = 30;//四个彩色方块的宽度
    painter->drawRect(0, 0, width, TICK_PANEL_HEIGHT);
    {
        {
            painter->setPen(0xFFFF4D);
            painter->setBrush(QBrush(0xFFFF4D));
            painter->drawRect(0, 0, headwidth, TICK_PANEL_HEIGHT);
        }
        {
            painter->setPen(0x0080FF);
            painter->setBrush(QBrush(0x0080FF));
            painter->drawRect(headwidth, 0, headwidth, TICK_PANEL_HEIGHT);
        }
        {
            painter->setPen(0xFF8000);
            painter->setBrush(QBrush(0xFF8000));
            painter->drawRect(headwidth * 2, 0, headwidth, TICK_PANEL_HEIGHT);
        }
        {
            painter->setPen(0x63F563);
            painter->setBrush(QBrush(0x63F563));
            painter->drawRect(headwidth * 3, 0, headwidth, TICK_PANEL_HEIGHT);
        }
        painter->setPen(Qt::white);
        painter->setFont(QFont("Times", 6, QFont::Bold));
        painter->drawText(QRect(0, 0, headwidth, TICK_PANEL_HEIGHT), Qt::AlignCenter, "h");
        painter->drawText(QRect(headwidth, 0, headwidth, TICK_PANEL_HEIGHT), Qt::AlignCenter, "m");
        painter->drawText(QRect(headwidth * 2, 0, headwidth, TICK_PANEL_HEIGHT), Qt::AlignCenter, "s");
        painter->drawText(QRect(headwidth * 3, 0, headwidth, TICK_PANEL_HEIGHT), Qt::AlignCenter, "ms");
    }
    delete painter;
}

void track_list_widget::resetWidth(int width)
{
    emit set_Width(width);
}