#include "stage.h"
#include <cmath>
#include"models/laserpoint.h"


int get_intersection(LaserPoint a, LaserPoint b, LaserPoint c, LaserPoint d, LaserPoint& intersection)//获取交叉点
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
stage::stage(QObject *parent)
    :OutputDebug(false)
    ,m_laser_device(nullptr)
{

}

void stage::set_config(Configuration *config)
{
    m_config=config;
}

void stage::set_device(laser_device *dev)
{
    if(m_laser_device!=nullptr)
    {
        m_laser_device=nullptr;
    }
    m_laser_device=dev;
}

void stage::add_send_data(std::vector<ishow_data> &list)
{
    if(m_laser_device==nullptr||OutputDebug)
        return;
    this->m_output_data_list.push_back(list);
    do_send_data();
}

stage::~stage()
{
    m_debug_data_list.clear();
    m_output_data_list.clear();
}

void stage::do_send_data()//发送数据给下位机
{
    unsigned char settings_data[8]={0};
    std::vector<unsigned char> send_data;
    send_data.clear();
    int dst=0;//从3个像素抽一个点增加，每次增加1个像素
    {
        if(this->OutputDebug)
        {
            for(int i=0;i<m_debug_data_list.size();++i)
            {
                auto _d=m_debug_data_list.at(i);
                send_data.push_back(_d.x);
                send_data.push_back(_d.y);
                send_data.push_back(_d.red);
                send_data.push_back(_d.gray);
                send_data.push_back(_d.blue);
                send_data.push_back(_d.green);
            }
        }
        else
        {
            if(this->m_output_data_list.size()>0)
            {
                if(this->m_output_data_list[0].size()<1)
                {
                    this->m_output_data_list.erase(this->m_output_data_list.begin());
                }
                else
                {
                    auto& d=this->m_output_data_list.front();
                    auto _d=d.at(0);
                    last_send_data={_d.x,_d.y,_d.red,_d.gray,_d.blue,_d.green};
                    for(int i=0;i<d.size();++i)
                    {
                        auto _d=d.at(i);
                        int n=0;
                        if(n>1)//一帧的初始点增加插值点
                        {
                            for(int j=1;j<n;j++)
                            {
                                send_data.push_back(_d.x);
                                send_data.push_back(_d.y);
                                send_data.push_back(0);
                                send_data.push_back(0);
                                send_data.push_back(0);
                                send_data.push_back(0);
                            }
                        }
                        send_data.push_back(_d.x);
                        send_data.push_back(_d.y);
                        send_data.push_back(_d.red);
                        send_data.push_back(_d.gray);
                        send_data.push_back(_d.blue);
                        send_data.push_back(_d.green);
                        last_send_data={_d.x,_d.y,_d.red,_d.gray,_d.blue,_d.green};
                    }
                    this->m_output_data_list.erase(this->m_output_data_list.begin());
                }
            }
        }
    }
    if(send_data.size()!=0)
    {
        settings_data[0] = static_cast<unsigned char>(m_config->Speed * 2);
        settings_data[1] = static_cast<unsigned char>(m_config->PointGap);
        settings_data[2] = m_config->Delay;
        settings_data[3] = 0;
        int maxposnum=800;
        do
        {
            if(send_data.size()>maxposnum*6*2)//点数超过405的二倍，就隔几个点抽一次
            {
                float temp=send_data.size()/6;
                int ratio=floor(temp/maxposnum);
                for(int i=send_data.size()/6-1;i>-1;i--)
                {
                    if((send_data.at(i*6+2)==0)&&(send_data.at(i*6+3)==0)&&(send_data.at(i*6+4)==0)&&(send_data.at(i*6+5)==0))//保证消隐点不被减掉
                        continue;
                    if(i%ratio==0)
                    {
                        for(int j=5;j>-1;j--)
                        {
                            send_data.erase(send_data.begin()+i*6+j);
                        }
                    }
                }
             }
            else//点数不超过405的按点的距离抽点
            {
                LaserPoint lp;
                lp.X=send_data.at(send_data.size()-6);
                lp.Y=send_data.at(send_data.size()-6+1);
                LaserPoint cp;
                for(int i=send_data.size()/6-1;i>-1;i--)
                {

                    cp.X=send_data.at(i*6);
                    cp.Y=send_data.at(i*6+1);
                    if((send_data.at(i*6+2)==0)&&(send_data.at(i*6+3)==0)&&(send_data.at(i*6+4)==0)&&(send_data.at(i*6+5)==0))
                        continue;
                    if(abs(cp.X-lp.X)<3+dst&&abs(cp.Y-lp.Y)<3+dst&& abs(cp.X - lp.X) >0&& abs(cp.Y - lp.Y)>0)
                    {
                        for(int j=5;j>-1;j--)
                        {
                            send_data.erase(send_data.begin()+i*6+j);
                        }
                    }
                    else
                    {
                        lp=cp;
                    }
                }
            }
            dst++;
            if (dst > 10)
                break;
        }while(send_data.size()>maxposnum*6);


        int posnum = send_data.size() / 6;
        if((send_data.size()<maxposnum*6)&&(send_data.size()>5))//如果一帧数据少于405个点
        {
            for(int i=send_data.size()/6;i<maxposnum;i++)//不够405个点补齐
            {
                for(int j=0;j<6;j++)
                {
                    unsigned char x=send_data.at((i-1)*6+j);
                    send_data.push_back(x);
                }
            }
            m_laser_device->send_data(settings_data, send_data,send_data_state::sd_begin_end,posnum);
            send_data.erase(send_data.begin(),send_data.begin()+maxposnum*6);
        }
    }
}

bool stage::test_output()
{
    return this->OutputDebug;
}

laser_device *stage::get_device()
{
    return m_laser_device;
}

std::vector<ishow_data> stage::globalprocessing(LaserFrame &lf)//数据发送前的全局处理
{
    m_config->Load();
    std::vector<ishow_data> out_data;
    if(lf.size()<2)
    {
        return out_data;
    }
    std::vector<LaserPoint> array = {LaserPoint(0, 0,0), LaserPoint(0, 255,0), LaserPoint(255, 255,0), LaserPoint(255, 0,0), LaserPoint(0, 0,0)};
    LaserPoint item=LaserPoint(0,0,0);
    for(int i=0;i<lf.size();i++)
    {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char gray;
        m_config->get_color(lf.at(i),red,green,blue,gray);//把配置读到red,green等四个参数里
        int mix=lf.at(i).X;
        int miy=lf.at(i).Y;
        LaserPoint pt = m_config->get_point_by_config(lf.at(i), mix,miy);//从config里获取点
        pt.R=red;
        pt.G=green;
        pt.B=blue;
        if (pt.X > -1 && pt.X < 256 && pt.Y > -1 && pt.Y < 256)//如果是可显示的点
        {

            if (i == 0)//如果是第一帧，加四个消隐点
            {
                for (int disn = 0; disn < 4; disn++)
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(pt.X), static_cast<unsigned char>(pt.Y), 0,0,0,0 });
            }
            out_data.emplace_back(ishow_data{ static_cast<unsigned char>(pt.X), static_cast<unsigned char>(pt.Y), red, green, blue, gray });
            if (i == lf.size() - 1)
            {
                break;
            }
            LaserPoint b4 = m_config->get_point_by_config(lf.at(i + 1));//获取下一个点
            if ((b4.X <0) || (b4.X > 255) ||( b4.Y < 0) ||( b4.Y > 255))
            {
                for (int j = 0; j < array.size() - 1; j++)
                {
                    if (get_intersection(pt, b4, array[j], array[j + 1], item) == 1)
                    {
                        out_data.emplace_back(ishow_data{ static_cast<unsigned char>(item.X), static_cast<unsigned char>(item.Y), 0, 0, 0, 0 });
                    }
                }
            }
            else
            {
                if(abs(pt.X-b4.X)>15||abs(pt.Y-b4.Y)>15)//如果下一个点的距离较远，就增加下一个点坐标上的消隐点
                {
                    int disnum = std::max(abs(pt.X - b4.X), abs(pt.Y - b4.Y)) / 5;
                    out_data.emplace_back(ishow_data{ static_cast<unsigned char>(pt.X), static_cast<unsigned char>(pt.Y), 0, 0, 0, 0 });

                    for (int n=0;n<disnum;n++)
                        out_data.emplace_back(ishow_data{ static_cast<unsigned char>(b4.X), static_cast<unsigned char>(b4.Y), 0, 0, 0, 0 });
                }
            }
        }
        else if (i == lf.size() - 1) //最后的点
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
            LaserPoint b4 = m_config->get_point_by_config(lf.at(i + 1));
            std::vector<LaserPoint> list;
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
        unsigned char redt;
        unsigned char greent;
        unsigned char bluet;
        unsigned char grayt;

        m_config->get_color(lf.at(0), redt, greent, bluet, grayt);//把配置读到red,green等四个参数里

        //从config里获取点
        int mix=lf.at(0).X;
        int miy=lf.at(0).Y;
        LaserPoint pttemp = m_config->get_point_by_config(lf.at(0), mix,miy);
        out_data.emplace_back(ishow_data{ static_cast<unsigned char>(pttemp.X), static_cast<unsigned char>(pttemp.Y), redt, greent, bluet, grayt });
        out_data.emplace_back(ishow_data{ static_cast<unsigned char>(pttemp.X), static_cast<unsigned char>(pttemp.Y), redt, greent, bluet, grayt });
        auto& last = out_data.at(out_data.size() - 1);
        last.red = 0;
        last.gray = 0;
        last.blue = 0;
        last.green = 0;
    }
    return out_data;
}



