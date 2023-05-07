#include "cjsection.h"
#include "point.h"
#include <QPainter>


int get_intersection(Point a, Point b, Point c, Point d, Point& intersection)//获取交叉点
{
    if (std::abs(b.X - a.Y) + std::abs(b.X - a.X) + std::abs(d.Y - c.Y) + std::abs(d.X - c.X) == 0)
    {
        return 0;
    }

    if (std::abs(b.Y - a.Y) + std::abs(b.X - a.X) == 0)
    {
        return 0;
    }

    if (std::abs(d.Y - c.Y) + std::abs(d.X - c.X) == 0)
    {
        return 0;
    }

    if ((b.Y - a.Y) * (c.X - d.X) - (b.X - a.X) * (c.Y - d.Y) == 0)
    {
        return 0;
    }

    intersection.X = ((b.X - a.X) * (c.X - d.X) * (c.Y - a.Y) - c.X * (b.X - a.X) * (c.Y - d.Y) + a.X * (b.Y - a.Y) * (c.X - d.X)) / ((b.Y - a.Y) * (c.X - d.X) - (b.X - a.X) * (c.Y - d.Y));
    intersection.Y = ((b.Y - a.Y) * (c.Y - d.Y) * (c.X - a.X) - c.Y * (b.Y - a.Y) * (c.X - d.X) + a.Y * (b.X - a.X) * (c.Y - d.Y)) / ((b.X - a.X) * (c.Y - d.Y) - (b.Y - a.Y) * (c.X - d.X));

    if ((intersection.X - a.X) * (intersection.X - b.X) <= 0 && (intersection.X - c.X) * (intersection.X - d.X) <= 0 && (intersection.Y - a.Y) * (intersection.Y - b.Y) <= 0 && (intersection.Y - c.Y) * (intersection.Y - d.Y) <= 0)
    {
        return 1;
    }

    return -1;
}

CJSection::CJSection(QGraphicsView *parent)
{
    m_parent=parent;
}



void CJSection::draw_picture(QPainter *painter, int x, int y, int width, int height, bool show_point, bool show_selected)
{
    float x_offset = 0;//x偏差
    float y_offset = 0;//y偏差
//    int width,height;
//    width=this->boundingRect().width();
//    height=this->boundingRect().height();
    int length = std::min(width,height);
    if (width != length)//panel的宽度比要绘制的大
    {
        x_offset = (double)(width - length) / 2.0;
    }
    else if (height != length)//panel的高度比要绘制的大
    {
        y_offset = (double)(height - length) / 2.0;
    }

    painter->setBrush(Qt::black);
//    painter->drawRect(this->boundingRect());
    double scale=(double)length/256.0;//把length分成256份
//    painter->translate(x_offset-15*scale,y_offset-92*scale);
    painter->translate(x+x_offset-(width)/2,y+y_offset-(height)/2);
    painter->drawRect(-x_offset,-y_offset,width+x_offset,height+x_offset);
    if(this->size()>1)
    {
        for(int i=1;i<(int)this->size();i++)
        {
            PointAttribute& p1=this->at(i-1);//取出每一个点
            Point pt1=p1.Zoom(scale);//调整点p1的位置，把位置保存在Point类对象中
            QColor color=QColor(p1.R,p1.G,p1.B);

            painter->setPen(color);
            painter->setBrush(color);
            PointAttribute & p2=this->at(i);//取出当前点的下一个点
            Point pt2=p2.Zoom(scale);
            if(color.red()!=0||color.green()!=0||color.blue()!=0)
            {
                if(pt2==pt1)
                {
                    painter->drawPoint(pt2.X,pt2.Y);
                    if(show_point)
                    {
                        painter->drawEllipse(QRectF(pt2.X-1,pt2.Y-1,2,2));
                    }
                    if(show_selected)
                    {
                        if(p2.Selected)
                        {
                            painter->drawEllipse(QRectF(pt2.X-1.5,pt2.Y-1.5,3,3));
                        }

                    }

                }
                else
                {
                    painter->drawLine(QLineF(QPointF(pt1.X,pt2.Y),QPointF(pt2.X,pt2.Y)));
                    if(show_point)
                    {
                        painter->drawEllipse(QRectF(pt1.X-1,pt1.Y-1,2,2));
                        painter->drawEllipse(QRectF(pt2.X-1,pt2.Y-1,2,2));
                    }
                    if(show_selected)
                    {
                        if(p1.Selected)
                        {
                            painter->drawEllipse(QRectF(pt1.X-1.5,pt1.Y-1.5,3,3));
                        }
                        if(p2.Selected)
                        {
                            painter->drawEllipse(QRectF(pt2.X-1.5,pt2.Y-1.5,3,3));
                        }
                    }
                }
            }
        }
    }
    painter->translate(-(x+x_offset-(width)/2),-(y+y_offset-(height)/2));
}

std::vector<ishow_data> CJSection::globalprocessing(Configuration *config)
{
    std::vector<ishow_data> out_data;
    if(this->size()<2)
    {
        return out_data;
    }
    std::vector<Point> array = {Point(0, 0), Point(0, 255), Point(255, 255), Point(255, 0), Point(0, 0)};
    Point item=Point(0,0);
    for(int i=0;i<this->size();i++)
    {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char gray;
        this->at(i).get_color(config,red,green,blue,gray);//把配置读到red,green等四个参数里
        Point pt = (*this)[i].get_point_by_config(config, (*this)[i].X, (*this)[i].Y);//从config里获取点
        (*this)[i].R = red;
        (*this)[i].G = green;
        (*this)[i].B = blue;
        if (pt.X > -1 && pt.X < 256 && pt.Y > -1 && pt.Y < 256)
        {
            out_data.emplace_back(ishow_data{ static_cast<unsigned char>(pt.X), static_cast<unsigned char>(pt.Y), red, green, blue, gray });
            if (i == this->size() - 1)
            {
                break;
            }
            Point b4 = (*this)[i + 1].get_point_by_config(config);
            if (b4.X < 0 || b4.X > 255 || b4.Y < 0 || b4.Y > 255)
            {
                for (int j = 0; j < array.size() - 1; j++)
                {
                    if (get_intersection(pt, b4, array[j], array[j + 1], item) == 1)
                    {
                        out_data.emplace_back(ishow_data{ static_cast<unsigned char>(item.X), static_cast<unsigned char>(item.Y), 0, 0, 0, 0 });
                    }
                }
            }
        }
        else if (i == this->size() - 1) //最后的点
        {
            if (out_data.size() != 0)
            {
                auto& last = out_data.at(out_data.size() - 1);
                last.red = 0;
                last.gray = 0;
                last.blue = 0;
                last.green = 0;

                break;
            }
            break;
        }
        else
        {
            Point b4 = (*this)[i + 1].get_point_by_config(config);
            std::vector<Point> list;
            for (int k = 0; k < array.size() - 1; k++)
            {
                if (get_intersection(pt, b4, array[k], array[k + 1], item) == 1)
                {
                    list.push_back(item);
                }
            }
            if (list.size() == 1)
            {
                out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[0].X), static_cast<unsigned char>(list[0].Y), 0, 0, 0, 0 });
                out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[0].X), static_cast<unsigned char>(list[0].Y), red, green, blue, gray });
            }
            else if (list.size() == 2)
            {
                double num5 = std::sqrt(static_cast<double>((pt.X - list[0].X) * (pt.X - list[0].X) + (pt.Y - list[0].Y) * (pt.Y - list[0].Y)));
                double num6 = std::sqrt(static_cast<double>((pt.X - list[1].X) * (pt.X - list[1].X) + (pt.Y - list[1].Y) * (pt.Y - list[1].Y)));
                if (num5 < num6)
                {
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[0].X), static_cast<unsigned char>(list[0].Y), 0, 0, 0, 0 });
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[0].X), static_cast<unsigned char>(list[0].Y), red, green, blue, gray });
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[1].X), static_cast<unsigned char>(list[1].Y), 0, 0, 0, 0 });

                }
                else
                {
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[1].X), static_cast<unsigned char>(list[1].Y), red, green, blue, gray });
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(list[0].X), static_cast<unsigned char>(list[0].Y), 0, 0, 0, 0 });

                }
            }
            list.clear();
            list.swap(list);
        }


    }
    array.clear();
    array.swap(array);
    if (out_data.size() > 0)
    {
        auto& last = out_data.at(out_data.size() - 1);
        last.red = 0;
        last.gray = 0;
        last.blue = 0;
        last.green = 0;

        out_data.emplace_back(ishow_data{ last.x, last.y, 0, 0, 0, 0 });

    }
    return out_data;
}

//void CJSection::draw_picture(scene_item *temp,int x, int y, int width, int height,bool show_point,bool show_selected)
//{



//}
