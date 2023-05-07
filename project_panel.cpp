#include "project_panel.h"
#define TICK_PANEL_HEIGHT		30
#define MEDIA_PANEL_HEIGHT		40
#define LASER_PANEL_HEIGHT		40
#define PANEL_INTERVAL_HEIGHT	5
#define HEADER_INTERVAL_WIDTH	5
#include<QGraphicsSceneDragDropEvent>
#include<QMimeData>
#include"dnd_scene_data_object.h"
//#include<QUrl>
#include "windows.h"

project_panel::project_panel(QWidget *parent):QGraphicsView(parent)
{
    m_track_panel =new track_panel(this);
}

project_panel::~project_panel()
{
    QList<QGraphicsItem *> item_list_p=m_graphicsScene->items();
    for(int i=0;i<item_list_p.size();++i)
    {
        m_graphicsScene->removeItem(item_list_p[i]);
        delete item_list_p[i];
    }
    m_graphicsScene->clear();
    delete m_graphicsScene;
}



void project_panel::update_panel(QRectF rec)
{
    scene()->setSceneRect(rec);
}

void project_panel::set_scene(QGraphicsScene *scene)
{
    this->setScene(scene);
    m_graphicsScene=scene;

    m_graphicsScene->addItem(m_track_panel);
    m_track_panel->update();//刷新面板会产生窗口重绘事件
}

void project_panel::play()
{
    m_track_panel->play();
}

void project_panel::stop()
{
    m_track_panel->stop();
}

void project_panel::update_show(CJSection *out_picture)
{
    m_track_panel->update_show(out_picture);
}




track_panel::track_panel(project_panel *parent)
    :m_parent(parent)
    ,m_play_start(0)
{
    Init();
    m_width=m_parent->width();
    m_height=m_parent->height();
//    setFlags(QGraphicsItem::ItemIsMovable);
    setAcceptDrops(true);

}


track_panel::~track_panel()
{

}

QRectF track_panel::boundingRect() const
{
    QRectF tem(m_parent->pos().x(),m_parent->pos().y(),m_width,m_height);
    return tem;
}

void track_panel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int width,height;
    if (m_width<m_parent->width())
        m_width=m_parent->width();
    if(m_height<m_parent->height())
        m_height=m_parent->height();
    width=m_width;
    height=m_height;
    if(width<100||height<10)
        return;
    int track_start_x=m_header_width + HEADER_INTERVAL_WIDTH;//80+5
//    painter->translate(-(width)/2,-(height)/2);
    painter->setPen(Qt::lightGray);
    painter->setBrush(Qt::lightGray);
    painter->drawRect(track_start_x,0,width - track_start_x, TICK_PANEL_HEIGHT);
    {
        {
            painter->setPen(0xFFFF4D);
            painter->setBrush(QBrush(0xFFFF4D));
            painter->drawRect(0,0,20,TICK_PANEL_HEIGHT);
        }
        {
            painter->setPen(0x0080FF);
            painter->setBrush(QBrush(0x0080FF));
            painter->drawRect(20,0,20,TICK_PANEL_HEIGHT);
        }
        {
            painter->setPen(0xFF8000);
            painter->setBrush(QBrush(0xFF8000));
            painter->drawRect(40,0,20,TICK_PANEL_HEIGHT);
        }
        {
            painter->setPen(0x63F563);
            painter->setBrush(QBrush(0x63F563));
            painter->drawRect(60,0,20,TICK_PANEL_HEIGHT);
        }
        painter->setPen(Qt::white);
        painter->setFont(QFont("Times",7,QFont::Bold));
        painter->drawText(QRect(0,0,20,10),Qt::AlignCenter,"h");
        painter->drawText(QRect(20,0,20,10),Qt::AlignCenter,"m");
        painter->drawText(QRect(40,0,20,10),Qt::AlignCenter,"s");
        painter->drawText(QRect(60,0,20,10),Qt::AlignCenter,"ms");
        int ms = (m_play_pos * this->m_show_model.get_interval() + this->m_show_model.get_x_end());
        int s=ms/1000;
        QString time_h = QString::asprintf("%02d",s/3600);
        QString time_m = QString::asprintf("%02d",s%3600/60);
        QString time_s = QString::asprintf("%02d",s%60);
        QString time_hms = QString::asprintf("%03d",ms/1000);
        painter->drawText(QRect(0,10,20,20),Qt::AlignCenter,time_h);
        painter->drawText(QRect(20,10,20,20),Qt::AlignCenter,time_m);
        painter->drawText(QRect(40,10,20,20),Qt::AlignCenter,time_s);
        painter->drawText(QRect(60,10,20,20),Qt::AlignCenter,time_hms);
    }
    for (int i = track_start_x; i < width; i++)//画刻度
    {
        int pos=(i-track_start_x)+ this->m_show_model.get_x_end() / this->m_show_model.get_interval();
        if(pos%100==0)
        {
            painter->setPen(QColor(255,0,0));
            painter->drawLine(i,TICK_PANEL_HEIGHT - 10, i, TICK_PANEL_HEIGHT);
            int num = ((i - track_start_x) * this->m_show_model.get_interval() + this->m_show_model.get_x_end()) / 1000;
            QString s = QString::asprintf("%02d:%02d:%02d", num / 3600, num % 3600 / 60, num % 60);
            painter->drawText(i, TICK_PANEL_HEIGHT / 2,s);
        }
        else if(pos%10==0)
        {
            painter->setPen(QColor(0, 255, 0));
            painter->drawLine(i, TICK_PANEL_HEIGHT - 5, i, TICK_PANEL_HEIGHT);
        }
    }
    for (int i = 0; i < m_media_track_count; i++)
    {
        int media_start_y = get_media_start_y(i);
        painter->setPen(Qt::gray);
        painter->setBrush(Qt::gray);
        painter->drawRect(0, media_start_y, m_header_width, MEDIA_PANEL_HEIGHT);
        painter->drawRect(track_start_x, media_start_y, width - track_start_x, MEDIA_PANEL_HEIGHT);
        painter->setPen(Qt::black);
        QString title=QString::asprintf("Media %d", i);
        painter->drawText(QRect(0, media_start_y, m_header_width, MEDIA_PANEL_HEIGHT),Qt::AlignCenter,title);
        for(int i = 0; i < m_medias.size(); i++)
        {
            if(m_medias.at(i)->m_track_index==i)
            {
                int meidia_width = m_medias.at(i)->get_frame_length()*40/m_show_model.get_interval();
//                int count=m_parent->m_buffer.sampleCount();
                m_medias.at(i)->draw_level(painter,track_start_x, media_start_y, meidia_width, MEDIA_PANEL_HEIGHT);

            }
        }
    }
    for(int i=0;i<m_laser_track_count;i++)
    {
        int media_start_y=get_laser_start_y(i);
        painter->setPen(Qt::lightGray);
        painter->setBrush(Qt::lightGray);
        painter->drawRect(0,media_start_y,m_header_width,LASER_PANEL_HEIGHT);
        painter->drawRect(track_start_x, media_start_y, width - track_start_x, LASER_PANEL_HEIGHT);
        QString title=QString::asprintf("轨道%d",i);
        painter->setPen(Qt::black);
        painter->drawText(QRect(0,media_start_y, m_header_width, MEDIA_PANEL_HEIGHT),Qt::AlignCenter,title);
        for (int j = 0; j < m_scenes.size(); ++j)
        {
            if (m_scenes.at(j).m_track_index == i)
            {
                painter->setPen(Qt::green);
                painter->setBrush(Qt::green);
                painter->drawRect(m_scenes.at(j).m_start_x, media_start_y, m_scenes.at(j).m_end_x - m_scenes.at(j).m_start_x, LASER_PANEL_HEIGHT);

//                //画scene缩略图
                CJSection section;
                m_scenes.at(j).m_scene->render(&section, 0);
                section.draw_picture(painter, m_scenes.at(j).m_start_x+LASER_PANEL_HEIGHT/2, media_start_y+LASER_PANEL_HEIGHT/2, LASER_PANEL_HEIGHT, LASER_PANEL_HEIGHT);
//                painter->drawText(m_scenes.at(j).m_start_x + LASER_PANEL_HEIGHT, media_start_y,m_scenes.at(j).m_scene->get_name());
            }
        }
    }
    //播放位置
    painter->setPen(Qt::yellow);
    painter->drawLine(track_start_x + m_play_pos, 0, track_start_x + m_play_pos, height);
    if(m_laser_x!=-1)
    {
        if(m_mouse_move_mode != MOUSE_MOVE_MODE::MMM_NONE)
        {
            int left=-1;
            int right=-1;
            if (m_mouse_move_mode == MOUSE_MOVE_MODE::MMM_MEDIA_DRAG)
            {
                for(int i=0;i<m_medias.size();++i)
                {
                    if (m_medias.at(i)->m_track_index == m_current_index)
                    {
                        left = m_medias.at(i)->m_start_x;
                        right = m_medias.at(i)->m_start_x + m_medias.at(i)->get_frame_length() * 40 / this->m_show_model.get_interval();
                        break;
                    }
                }
            }
            else
            {
                scene_info si = m_scenes.at(m_current_index);
                left = si.m_start_x;
                right = si.m_end_x;
            }
            //左
            if(left!=-1)
            {
                painter->setPen(Qt::yellow);
                painter->drawLine(left, 0, left, height);
            }
            //右
            if(right!=-1)
            {
                painter->setPen(Qt::yellow);
                painter->drawLine(right, 0, right, height);
            }
        }
    }
}

void track_panel::Init()
{
    m_media_track_count = 1;
    m_laser_track_count = 3;
    m_header_width = 80;
    m_play_pos = 0.f;
    m_last_x = -1;
    m_mouse_move_mode = MOUSE_MOVE_MODE::MMM_NONE;
    m_current_index = -1;
    m_frame_index = 0;
}

void track_panel::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    int width,height;
    width=m_parent->width();
    height=m_parent->height();
    QPointF p(event->pos().x(),event->pos().y());
    if(p.x()<(m_header_width+HEADER_INTERVAL_WIDTH))
        return;
    int media_track_index=on_media_track(p.y());

    if(-1!=media_track_index)
    {
        //判断该位置上是否有media，如果有，退出
        for(int i=0;i<m_medias.size();++i)
        {
            if(m_medias.at(i)->m_track_index==media_track_index)
            {
                return;
            }
        }
        if(event->mimeData()->hasUrls())
        {
            QList<QUrl> urls=event->mimeData()->urls();
            if(urls.isEmpty())
            {
                return;
            }

            QString filename=urls.first().toLocalFile();
            media_info* mi=new media_info(p.x(),media_track_index,this);
            if(mi->load_file(filename))
            {
                m_medias.push_back(mi);
            }
            else
            {
                delete mi;
            }
        }

    }
    int laser_track_index=on_laser_track(p.y());
    if(-1!=laser_track_index)
    {
//        for(int i=0;i<m_scenes.size();++i)
//        {
//            if(m_scenes.at(i).m_track_index==laser_track_index)
//            {
//                return;
//            }
//        }
        if((dnd_scene_data_object*)event->mimeData())
        {
            dnd_scene_data_object* scene_data=(dnd_scene_data_object*)event->mimeData();
            add_scene(p.x(),p.y(),scene_data->m_scene);
        }
        else
        {
            return;
        }
     }


}

void track_panel::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();  // 3. 有拖拽文件时设置接受
    }
    else if((dnd_scene_data_object*)event->mimeData())
    {
        event->acceptProposedAction();
    }
}

void track_panel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        int x=event->pos().x();
        int y=event->pos().y();
        int start_x=m_header_width+HEADER_INTERVAL_WIDTH;
        if(x<start_x)
            return;
        if(on_tick_panel(y))
        {
            m_play_pos=x-start_x;
            update();
            return;
        }
        else
        {
            int media_idx=on_media_track(y);
            if(-1!=media_idx)
            {
                if(get_media(x,y)!=nullptr)
                {
                    m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_MEDIA_DRAG;
                    m_current_index=media_idx;
                    m_last_x=x;
                    update();
                    return;
                }

            }
            else
            {
                int laser_index=on_laser_track(y);
                if(-1!=laser_index)
                {
                    m_last_x=x;
                    set_selected_scene(laser_index);
                    update();
                    return;
                }
            }
        }
        m_current_index=-1;
        m_last_x=-1;
        m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_NONE;

    }
}

void track_panel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_current_index = -1;
        m_last_x = -1;
        m_mouse_move_mode = MOUSE_MOVE_MODE::MMM_NONE;
        update();
    }
}

void track_panel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    int x=event->pos().x();
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

        }
}

bool track_panel::on_tick_panel(int y)
{
    return y >= 0 && y <= TICK_PANEL_HEIGHT;
}

void track_panel::set_selected_scene(int track_index)
{
    int idx=0;
    for(int i=0;i<m_scenes.size();++i)
    {
        auto m=m_scenes.at(i);
        if(m.m_track_index==track_index)
        {
            if(m.is_moving(m_last_x))
            {
                m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_SCENE_DRAG;
                m_current_index=idx;
                return;
            }
            else if(m.on_start_pos(m_last_x))
            {
                m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_SCENE_LEFT_MOVE;
                m_current_index=idx;
                return;
            }
            else if(m.on_end_pos(m_last_x))
            {
                m_mouse_move_mode=MOUSE_MOVE_MODE::MMM_SCENE_RIGHT_MOVE;
                m_current_index=idx;
                return;
            }
        }
        idx++;
    }
}

int track_panel::on_laser_track(int y)
{
    for(int i=0;i<m_laser_track_count;i++)
    {
        int start_y=get_laser_start_y(i);
        if(y>=start_y&&y<=(start_y+MEDIA_PANEL_HEIGHT))
        {
            return i;
        }
    }
    return -1;
}

float track_panel::get_stop_postion()
{
    float pos=0.f;
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
    return pos;
}

int track_panel::get_media_start_y(int idx)//idx代表第几条轨道
{
    int y=0;
    if(idx>=0&&idx<m_media_track_count)
        y = TICK_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT //media区域y开始位置
        + idx * (MEDIA_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT);//每增加一个media，高度增加media高度+间隔高度
    return y;
}

int track_panel::get_laser_start_y(int idx)
{
    int y=0;
    if(idx>=0 && idx<m_laser_track_count)
        y = TICK_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT //media区域开始高度
                + m_media_track_count * (MEDIA_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT) //laser区域y开始位置
                + idx * (LASER_PANEL_HEIGHT + PANEL_INTERVAL_HEIGHT);//每增加一个laser，高度增加laser高度+间隔高度
    return y;
}

media_info *track_panel::get_media(int x, int y)
{
    media_info* mi=nullptr;
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
    return nullptr;

}

int track_panel::on_media_track(int y)
{
    for(int i=0;i<m_media_track_count;i++)
    {
        int start_y=get_media_start_y(i); //返回轨道的开始高度
        if (y>=start_y&&y<=(start_y+MEDIA_PANEL_HEIGHT))//判断drop的点是否在当前媒体轨道上
        {
            return i;
        }
    }
    return -1;
}

void track_panel::update_width()
{
    int w=this->boundingRect().width();
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
//    scene()->update(rec);
    m_parent->update_panel(rec);
}

void track_panel::update_width(int x)
{
    int w=m_width;
    int h=m_height;
    if(x>w)
    {
        m_width=x;
        QRectF rec=this->scene()->sceneRect();
        rec.setWidth(m_width);
        m_parent->update_panel(rec);
        scroll(w,-1);
    }
}

void track_panel::play()
{

}

void track_panel::stop()
{
    m_frame_index=0;
    for(int i=0;i<m_medias.size();++i)
    {
        m_medias.at(i)->m_mp3_player->stop();
        m_medias.at(i)->m_play_flag=false;
    }
}

void track_panel::update_show(CJSection *out_picture)
{
    int start_x = m_header_width + HEADER_INTERVAL_WIDTH;
    //帧率是25，即一次播放40ms，指示器位置移动40毫秒，除以刻度单位，即移动的长度
    m_play_pos += (40.0 / this->m_show_model.get_interval());

    if ((m_play_pos + start_x) > get_stop_postion())
    {
        m_play_pos=0;
    }
    for(int i=0;i<m_medias.size();++i)
    {
        auto m=m_medias.at(i);
        int idx = (m_play_pos + start_x - m->m_start_x);
        //10像素=40ms
        m->m_mp3_player->setPosition(idx*40);
        if(!m->m_play_flag)
        {
            m->m_mp3_player->play();
            m->m_play_flag=true;
        }

    }
    for(int i=0;i<m_scenes.size();++i)
    {
        auto s=m_scenes.at(i);
        if((m_play_pos+start_x)>=s.m_start_x&&(m_play_pos+start_x)<=s.m_end_x)
        {
            int idx=(m_play_pos+start_x-s.m_start_x);
            idx=idx%s.m_scene->max_frame_length();
            s.m_scene->render(out_picture,idx);
        }
    }
    update();
    m_frame_index++;
}

void track_panel::add_scene(int x, int y, single_scene *scene)
{
    if(x < (m_header_width + HEADER_INTERVAL_WIDTH))
        return;
    if(scene)
    {
        int track_index=this->on_laser_track(y);
        if(track_index != -1)
        {
            int width=scene->max_frame_length()*40/this->m_show_model.get_interval();
            m_scenes.push_back(scene_info(scene,x,x+width,track_index));
            update();
        }
    }
}

scene_info::scene_info(single_scene *scene, int start_x, int end_x, int track_index)
    :m_start_x(start_x)
    ,m_end_x(end_x)
    ,m_track_index(track_index)
{
//    m_scene(scene);
    m_scene=new single_scene();
//    m_scene->resize(scene->size());
    for(int i=0;i<scene->size();++i)
    {
            effect *m_effect=nullptr;
            switch(scene->at(i)->get_type())
            {
                case EffectType::ET_PICTURE:
                {
                    m_effect=new point_effect();
                    m_effect->Param.point_param.m_start_index=scene->at(i)->Param.point_param.m_start_index;
                    m_effect->Param.point_param.m_end_index = scene->at(i)->Param.point_param.m_end_index;//给m_end_index初始化
                    break;
                }
                case EffectType::ET_TEXT:
                {
                    m_effect = new text_effect();
                    break;
                }
                case EffectType::ET_TIME:
                {
                    m_effect = new time_effect();
                    break;
                }
                case EffectType::ET_BLACK:
                {
                m_effect = new BlackEffect();
                    break;
            }
            case EffectType::ET_COLOR:
             {
                m_effect = new color_effect();
                    break;
            }
            case EffectType::ET_X_MOVE:
             {
                m_effect = new XMoveEffect();
                    break;
            }
            case EffectType::ET_Y_MOVE:
             {
                m_effect = new YMoveEffect();
                    break;
            }
            case EffectType::ET_Z_MOVE:
             {
                m_effect = new ZMoveEffect();
                    break;
            }
            case EffectType::ET_X_ROTATE:
             {
                m_effect = new XRotateEffect();
                    break;
            }
            case EffectType::ET_Y_ROTATE:
             {
                m_effect = new YRotateEffect();
                    break;
            }
            case EffectType::ET_Z_ROTATE:
             {
                m_effect = new ZRotateEffect();
                    break;
            }
            case EffectType::ET_X_SIZE:
             {
                m_effect = new XSizeEffect();
                    break;
            }
            case EffectType::ET_Y_SIZE:
             {
                m_effect = new YSizeEffect();
                    break;
            }
            case EffectType::ET_X_INVERT:
             {
                m_effect = new XInvertEffect();
                    break;
            }
            case EffectType::ET_Y_INVERT:
             {
                m_effect = new YInvertEffect();
                    break;
            }
            case EffectType::ET_XY_SIZE:
             {
                m_effect = new xy_size_effect();
                    break;
            }
            case EffectType::ET_GRADUALLY_RENDER:
             {
                m_effect = new gradually_render_effect();
                    break;
            }
            }
//        m_scene->at(i)->set_type(scene->at(i)->get_type());

        m_effect->set_pictures(scene->at(i)->get_pictures());
        m_effect->set_index(scene->at(i)->get_index());
        m_effect->set_start_index(scene->at(i)->get_start_index());
        m_effect->set_frame_length(scene->at(i)->get_frame_length());
        m_effect->Param=scene->at(i)->Param;
        m_scene->push_back(m_effect);
    }


}

scene_info::~scene_info()
{

}

bool scene_info::operator==(scene_info &other)
{
    return this->m_start_x == other.m_start_x
            && this->m_end_x == other.m_end_x
            && this->m_scene == other.m_scene
            && this->m_track_index == other.m_track_index;
}

bool scene_info::is_moving(int x)
{
    return x>m_start_x&&x<m_end_x;
}

bool scene_info::on_start_pos(int x)
{
    return x==m_start_x;
}

bool scene_info::on_end_pos(int x)
{
    return x==m_end_x;
}
media_info::media_info(int x, int idx, track_panel *panel,QWidget *parent):QCustomPlot(parent)
  ,m_mp3_player(new QMediaPlayer(this))
  ,m_start_x(x)
  ,m_track_index(idx)
  ,m_decoder(new QAudioDecoder(this))
  ,m_track_panel(panel)
  ,m_play_flag(false)

{
    m_playlist = new QMediaPlaylist(this);//
    m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce); //循环模式
    m_mp3_player->setPlaylist(m_playlist);
    m_wavePlot=addGraph();
    connect(m_mp3_player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMediaPlayer::State)));
    connect(m_mp3_player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));
    connect(m_mp3_player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
    connect(m_playlist,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));
    connect(m_decoder,SIGNAL(bufferReady()),this,SLOT(setBuffer()));
    connect(m_decoder,SIGNAL(finished()),this,SLOT(plot()));

}
media_info::~media_info()
{
    if(m_mp3_player)
        delete m_mp3_player;
    m_mp3_player=nullptr;
}
bool media_info::load_file(const QString &name)
{
    m_filename=name;
    m_mp3_player->setMedia(QUrl::fromLocalFile(name));
    QMediaPlayer::Error err=m_mp3_player->error();
    m_sample.clear();
    QAudioFormat format;
    format.setSampleRate(50);
    format.setSampleSize(16);
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
    float scale=(double)width/m_sample.size();
    painter->setPen(Qt::yellow);
    painter->setBrush(Qt::yellow);
    painter->drawRect(m_start_x,y,width,height);//2个像素画1个点
    painter->setPen(Qt::black);
    painter->drawText(1,0,m_filename);
    painter->setPen(Qt::red);
    float y_center=height/2.0;
    for(int i=0;i<width;i++)
    {
        int idx=i/scale;
        if(idx<(int)m_sample.size())
        {
            int value=m_sample.at(idx);
            painter->drawLine(m_start_x+i,y+y_center-value,m_start_x+i,y+y_center+value);
        }
    }

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

void media_info::setBuffer()
{
    if(!m_decoder->bufferAvailable()) return;
    m_buffer=m_decoder->read();
    qreal peak=getPeakValue(m_buffer.format());
    const quint16 *data=m_buffer.constData<quint16>();
    int count=m_buffer.sampleCount()/2;
    for(int i=0;i<count;i++)
    {
        double val=data[i]/peak;
        m_sample.append(val);
    }
}

void media_info::plot()
{
    m_track_panel->update_width();
    m_track_panel->update();
}






