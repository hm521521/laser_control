#include "effect.h"
#include<QTime>
#include"gdiplus_helper.h"
//#include<QPainterPath>
//#include<QFont>
#include <QDateTime>
#include<time.h>
#include<random>
#include"common.h"

effect::effect()
    : Param{{0,0,0,0}},
      m_type(EffectType::ET_PICTURE),
      m_pictures(),
      m_index(0),
      m_start_frame_index(0),
      m_frame_length(0)
{

}

effect::~effect()
{

}



effect* effect::CreateEffect(PictureInfo *pi)
{
    effect *m_effect=nullptr;
    switch(pi->get_type())
    {
        case EffectType::ET_PICTURE:
        {
            m_effect=new point_effect();
            m_effect->Param.point_param.m_start_index=pi->get_index();
            m_effect->Param.point_param.m_end_index = pi->get_index();//给m_end_index初始化
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
    return m_effect;
}

effect *effect::Load()
{
    m_pictures.clear();
    return this;
}

CJImage effect::get_pictures()
{
    return m_pictures;
}

void effect::set_pictures(CJImage pic)
{
    m_pictures=pic;
}

void effect::set_type(EffectType type)
{
    m_type=type;
}

void effect::set_index(int ind)
{
    m_index=ind;
}

void effect::set_start_index(int start)
{
    m_start_frame_index=start;
}

void effect::set_frame_length(int len)
{
    m_frame_length=len;
}

EffectType effect::get_type()
{
    return m_type;
}

int effect::get_index()
{
    return m_index;
}

int effect::get_start_index()
{
    return m_start_frame_index;
}

int effect::get_frame_length()
{
    return m_frame_length;
}

PictureInfo::PictureInfo(EffectType t, int i)//把效果类型幅值给m_type,把idx幅值给m_index
    : m_type(t), m_index(i)
{
}

EffectType PictureInfo::get_type() const
{
    return m_type;
}

int PictureInfo::get_index() const
{
    return m_index;
}

point_effect::point_effect()
{
    this->m_type=EffectType::ET_PICTURE;
}

void point_effect::render(CJSection &section, int time)
{
    if (this->m_pictures.empty()) return;
    if (time <this->m_start_frame_index||time>this->m_start_frame_index+this->m_frame_length)
    {
        return;
    }
    double num=static_cast<double>(time-this->m_start_frame_index);
    double num2=num/static_cast<double>(this->m_frame_length);//求已经过去的时间占整个时长的比例
    int picture_index=static_cast<int>(static_cast<double>(this->m_pictures.size())*num2);
    if(this->Param.point_param.m_loop==1)
    {
        if(num<0.0||num>static_cast<double>(this->m_frame_length)) return;
//        num2=((int)num%this->Param.point_param.m_loop_time)/static_cast<double>(this->Param.point_param.m_loop_time);
        num2 = ((int)num % this->Param.point_param.m_loop_time) / static_cast<double>(this->Param.point_param.m_loop_time) * static_cast<double>(this->m_pictures.size());
        picture_index=static_cast<int>(num2);
    }

    if(picture_index>-1&&picture_index<this->m_pictures.size())
    {
        for(int i=0; i<(int)this->m_pictures[picture_index].size(); i++)
        {
            section.push_back(this->m_pictures[picture_index][i]);//把每张图都存入section
        }
        if(section.size()>0)
        {
            section.back().ClearColor();
        }
    }
}

text_effect::text_effect()
    :m_invert(false)
{
    this->m_type=EffectType::ET_TEXT;
    CJSection tempVar;
    this->m_pictures.push_back(tempVar);
    CJSection tempVar2;
    this->m_pictures.push_back(tempVar2);
    CJSection tempVar3;
    this->m_pictures.push_back(tempVar3);
    this->Param.text_param.m_r=0;
    this->Param.text_param.m_g=255;
    this->Param.text_param.m_b=0;
    this->Param.text_param.m_font_size=50;
}

void text_effect::render(CJSection &section, int time)
{
    if (time >= this->m_start_frame_index && time <= this->m_frame_length + this->m_start_frame_index)
    {
        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            section.push_back(this->m_pictures[0][i]);
        }
    }
}

time_effect::time_effect()
    :color(0,255,0)
{
    this->m_type=EffectType::ET_TIME;
}

void time_effect::render(CJSection &section, int time)
{
    if (time >= this->m_start_frame_index && time <= this->m_frame_length + this->m_start_frame_index)
    {
        time_t time=QDateTime::currentDateTime().toTime_t();//获取时间戳秒级
        tm tt;
        localtime_s(&tt,&time);
        QString txt=QString("%2:").arg(tt.tm_hour)+QString("%2:").arg(tt.tm_min)+QString("%2").arg(tt.tm_sec);
        gdiplus_helper::get_point_from_text(txt, section, this->color.R, this->color.G, this->color.B);
    }
}

BlackEffect::BlackEffect()
{
    this->m_type=EffectType::ET_BLACK;

}

void BlackEffect::render(CJSection &section, int time)
{
    if (time >= this->m_start_frame_index && time <= this->m_frame_length + this->m_start_frame_index)
                //如果时间这个常数大于开始索引并且小于等于effect开始的索引加上持续的帧数
    {
        section.clear();//把section的size设为0；
    }
}

color_effect::color_effect()
    :m_r(0)
    ,m_g(0)
    ,m_b(0)
{
    this->m_type=EffectType::ET_COLOR;
    CJSection tempVar;
    this->m_pictures.push_back(tempVar);//0, list
    CJSection tempVar2;
    tempVar2.emplace_back(PointAttribute{0,2,0,std::numeric_limits<unsigned char>::max(),0,0});
    tempVar2.emplace_back(PointAttribute{128, 2, 0, 0, std::numeric_limits<unsigned char>::max(), 0 });
    tempVar2.emplace_back(PointAttribute{ 256, 2, 0, 0, 0, std::numeric_limits<unsigned char>::max() });
    this->m_pictures.push_back(tempVar2);//1, color list
    this->Param.color_param.m_mode = 2;
    this->Param.color_param.m_r = 0;
    this->Param.color_param.m_g = 255;
    this->Param.color_param.m_b = 0;
}

void color_effect::render(CJSection &section, int time)
{
    if (time >= this->m_start_frame_index && time <= this->m_frame_length + this->m_start_frame_index)
            {
                this->GenerateColor();//随机产生颜色信息

                for (auto& point : section)//遍历section里的所有点并给每个点的颜色变量赋值
                {
                    if (this->Param.color_param.m_mode == 0) //随机颜色
                    {
                        if (point.R != 0 || point.G != 0 || point.B != 0)
                        {
                            point.R += this->m_r;
                            point.G += this->m_g;
                            point.B += this->m_b;
                        }
                    }
                    else if (this->Param.color_param.m_mode == 1) //单色
                    {
                        if (point.R != 0 || point.G != 0 || point.B != 0)
                        {
                            point.R = static_cast<unsigned char>(this->Param.color_param.m_r);
                            point.G = static_cast<unsigned char>(this->Param.color_param.m_g);
                            point.B = static_cast<unsigned char>(this->Param.color_param.m_b);
                        }
                    }
                    else if (this->Param.color_param.m_mode == 2) //渐变色
                    {
                        if (point.X >= 0 && point.X < 256 && (point.R != 0 || point.G != 0 || point.B != 0))
                        {
                            point.R = this->m_pictures[0][point.X].R;
                            point.G = this->m_pictures[0][point.X].G;
                            point.B = this->m_pictures[0][point.X].B;
                        }
                        else if (point.X < 0 && (point.R != 0 || point.G != 0 || point.B != 0))
                        {
                            point.R = this->m_pictures[0][0].R;
                            point.G = this->m_pictures[0][0].G;
                            point.B = this->m_pictures[0][0].B;
                        }
                        else if (point.X > 255 && (point.R != 0 || point.G != 0 || point.B != 0))
                        {
                            point.R = this->m_pictures[0][255].R;
                            point.G = this->m_pictures[0][255].G;
                            point.B = this->m_pictures[0][255].B;
                        }
                    }
                }
    }
}
int color_effect::rametimetiem=0;
void color_effect::GenerateColor()
{
    Color c;
    color_effect::rametimetiem++;
    if (color_effect::rametimetiem<this->rametime)
    {
        return;
    }
    color_effect::rametimetiem=0;
    std::mt19937 rng;//产生随机数
    rng.seed(std::random_device()());//设置随机数种子
    std::uniform_int_distribution<std::mt19937::result_type> dist255(0,255);//定义了分布对象，它返回的是均勻分布在闭合范围[a，b]内的随机整数
    m_r=static_cast<unsigned char>(dist255(rng));
    m_g=static_cast<unsigned char>(dist255(rng));
    m_b=static_cast<unsigned char>(dist255(rng));

}

XMoveEffect::XMoveEffect()
{
    this->m_type=EffectType::ET_X_MOVE;
    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{0,0,0});
    tempVar.emplace_back(PointAttribute{800,255,0});
    this->m_pictures.push_back(tempVar);
}

void XMoveEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }
    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);
    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;

        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            else if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        int num7 = static_cast<int>(num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y) - 128.0) * 2;

        for (int j = 0; j <(int)section.size(); j++)
        {
            section[j].X = section[j].X + num7;
        }
    }
}

YMoveEffect::YMoveEffect()
{
    this->m_type=EffectType::ET_Y_MOVE;
    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{800,255,0});
    this->m_pictures.push_back(tempVar);
}

void YMoveEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }
    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);
    if(num3>=0&&num3<=800)
    {
        int index=0;
        int index2=0;
        for (int i=0;i<(int)this->m_pictures[0].size();i++)
        {
            if(this->m_pictures[0][i].X<=num3)
            {
                index=i;
            }
            else if (this->m_pictures[0][i].X>num3)
            {
                index2=i;
                break;
            }
        }
        double num4=static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5=static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6=static_cast<double>(num3 - this->m_pictures[0][index].X);
        int num7=static_cast<int>(num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y) - 128.0) * 2;
        for (int j=0;j<(int)section.size();j++)
        {
            section[j].Y=section[j].Y+num7;
        }
    }
}

ZMoveEffect::ZMoveEffect()
{
    this->m_type=EffectType::ET_Z_MOVE;
    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void ZMoveEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }

    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);
    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;

        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        int num7 = static_cast<int>(num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y) - 128.0) * 2;

        for (int j = 0; j <(int)section.size(); j++)
        {
            section[j].Z = section[j].Z + num7;
        }
    }
}

XRotateEffect::XRotateEffect()
{
    this->m_type = EffectType::ET_X_ROTATE;

    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void XRotateEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }
    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);
    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;
        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        int num7 = static_cast<int>((num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y) - 128.0) / 255.0 * 360.0) * 2;
        double num8 = static_cast<double>(num7) * PIOVER180;
        if(this->Param.rotate_param.m_mode==1)
        {
            float num9=static_cast<float>(section[0].Y);
            float num10 = static_cast<float>(section[0].Y);
            for (auto& point:section)
            {
                if(static_cast<float>(point.Y)>num9)
                {
                    num9=static_cast<float>(point.Y);
                }
                if(static_cast<float>(point.Y)<num10)
                {
                    num10=static_cast<float>(point.Y);
                }

            }
            float num11=num9-num10;
            float num12 = num11 / 2.0f + num10;
            float num13 = 1.0f;
            for (int j = 0; j < (int)section.size(); j++)
            {
                float num14 = (static_cast<float>(section[j].Y) - num12) / (num11 / 2.0f);
                if (num11 == 0.0f)
                {
                    num14 = 0.0f;
                }

                float num15 = num14 * 100.0f;
                if (std::abs(num15) == 100.0f)
                {
                    num13 *= -1.0f;
                }
                double d = std::asin(static_cast<double>(num14));
                double num16 = std::cos(d) * 100.0 * static_cast<double>(num13);
                double num17 = std::cos(num8);
                double num18 = std::sin(num8);
                double num19 = static_cast<double>(num15) * num17 + num16 * num18;
                double num20 = static_cast<double>(num15) * -num18 + num16 * num17;
                section[j].Y = static_cast<int>(num19 + static_cast<double>(num12));
                section[j].Z = static_cast<int>(num20);
            }
        }
        else
        {
            for (int k = 0; k <(int) section.size(); k++)
            {
                int num21 = section[k].Y - 128;
                int z = section[k].Z;
                double num22 = std::cos(num8);
                double num23 = std::sin(num8);
                double num24 = static_cast<double>(num21) * num22 + static_cast<double>(z) * num23;
                double num25 = static_cast<double>(num21) * -num23 + static_cast<double>(z) * num22;
                section[k].Y = static_cast<int>(num24) + 128;
                section[k].Z = static_cast<int>(num25);
            }
        }
    }
}

YRotateEffect::YRotateEffect()
{
    this->m_type = EffectType::ET_Y_ROTATE;

    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void YRotateEffect::render(CJSection &section, int time)
{
    if(section.empty())
    {
        return;
    }
    int num=time-this->m_start_frame_index;
    double num2=static_cast<double>(this->m_frame_length)/800.0;
    int num3=static_cast<int>(static_cast<double>(num)/num2);
    if (num3>-1&&num3<=800)
    {
        int index = 0;
        int index2 = 0;
        for (int i = 0; i <(int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }
        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        int num7 = static_cast<int>((num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y) - 128.0) / 255.0 * 360.0) * 2;
        double num8 = static_cast<double>(num7) * PIOVER180;
        if (this->Param.rotate_param.m_mode == 1)
        {
            float num9 = static_cast<float>(section[0].X);
            float num10 = static_cast<float>(section[0].X);

            for (auto& point : section)
            {
                if (static_cast<float>(point.X) > num9)
                {
                    num9 = static_cast<float>(point.X);
                }
                if (static_cast<float>(point.X) < num10)
                {
                    num10 = static_cast<float>(point.X);
                }
            }

            float num11 = num9 - num10;
            float num12 = num11 / 2.0f + num10;
            float num13 = 1.0f;

            for (int j = 0; j < (int)section.size(); j++)
            {
                float num14 = (static_cast<float>(section[j].X) - num12) / (num11 / 2.0f);
                if (num11 == 0.0f)
                {
                    num14 = 0.0f;
                }
                float num15 = num14 * 100.0f;
                if (std::abs(num15) == 100.0f)
                {
                    num13 *= -1.0f;
                }
                double d = std::asin(static_cast<double>(num14));
                double num16 = std::cos(d) * 100.0 * static_cast<double>(num13);
                double num17 = std::cos(num8);
                double num18 = std::sin(num8);
                double num19 = static_cast<double>(num15) * num17 + num16 * num18;
                double num20 = static_cast<double>(num15) * -num18 + num16 * num17;
                section[j].X = static_cast<int>(num19 + static_cast<double>(num12));
                section[j].Z = static_cast<int>(num20);
            }
        }
        else
        {
            for (int k = 0; k < (int)section.size(); k++)
            {
                int num21 = section[k].X - 128;
                int z = section[k].Z;
                double num22 = std::cos(num8);
                double num23 = std::sin(num8);
                double num24 = static_cast<double>(num21) * num22 + static_cast<double>(z) * num23;
                double num25 = static_cast<double>(num21) * -num23 + static_cast<double>(z) * num22;
                section[k].X = static_cast<int>(num24) + 128;
                section[k].Z = static_cast<int>(num25);
            }
        }
    }
}

ZRotateEffect::ZRotateEffect()
{
    this->m_type = EffectType::ET_Z_ROTATE;
    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void ZRotateEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }

    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);

    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;

        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        int num7 = static_cast<int>((num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y) - 128.0) / 255.0 * 360.0) * 2;
        double num8 = static_cast<double>(num7) * PIOVER180;

        for (int j = 0; j < (int)section.size(); j++)
        {
            int num9 = section[j].Y - 128;
            int num10 = section[j].X - 128;
            double num11 = std::cos(num8);
            double num12 = std::sin(num8);
            double num13 = static_cast<double>(num10) * num11 + static_cast<double>(num9) * num12;
            double num14 = static_cast<double>(num10) * -num12 + static_cast<double>(num9) * num11;
            section[j].X = static_cast<int>(num13) + 128;
            section[j].Y = static_cast<int>(num14) + 128;
        }
    }
}

XSizeEffect::XSizeEffect()
{
    this->m_type = EffectType::ET_X_SIZE;
    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void XSizeEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }

    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);

    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;

        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        double num7 = (num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y)) / 128.0;

        for (int j = 0; j < (int)section.size(); j++)
        {
            section[j].X = static_cast<int>(static_cast<double>(section[j].X - 128) * num7 + 128.0);
        }
    }
}

YSizeEffect::YSizeEffect()
{
    this->m_type = EffectType::ET_Y_SIZE;

    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 0, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void YSizeEffect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }

    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);

    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;

        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        double num7 = (num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y)) / 128.0;

        for (int j = 0; j <(int) section.size(); j++)
        {
            section[j].Y = static_cast<int>(static_cast<double>(section[j].Y - 128) * num7 + 128.0);
        }
    }
}

XInvertEffect::XInvertEffect()
{
    this->m_type = EffectType::ET_X_INVERT;
}

void XInvertEffect::render(CJSection &section, int time)
{
    if (time >= this->m_start_frame_index && time <= this->m_start_frame_index + this->m_frame_length)
    {
        for (int i = 0; i < (int)section.size(); i++)
        {
            section[i].X = (section[i].X - 128) * -1 + 128;
        }
    }
}

YInvertEffect::YInvertEffect()
{
    this->m_type = EffectType::ET_X_INVERT;
}

void YInvertEffect::render(CJSection &section, int time)
{
    if (time >= this->m_start_frame_index && time <= this->m_start_frame_index + this->m_frame_length)
    {
        for (int i = 0; i < (int)section.size(); i++)
        {
            section[i].Y = (section[i].Y - 128) * -1 + 128;
        }
    }
}

xy_size_effect::xy_size_effect()
{
    this->m_type = EffectType::ET_XY_SIZE;

    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{ 0, 1, 0 });
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void xy_size_effect::render(CJSection &section, int time)
{
    if (section.empty())
    {
        return;
    }

    int num = time - this->m_start_frame_index;
    double num2 = static_cast<double>(this->m_frame_length) / 800.0;
    int num3 = static_cast<int>(static_cast<double>(num) / num2);

    if (num3 > -1 && num3 <= 800)
    {
        int index = 0;
        int index2 = 0;

        for (int i = 0; i < (int)this->m_pictures[0].size(); i++)
        {
            if (this->m_pictures[0][i].X <= num3)
            {
                index = i;
            }
            else if (this->m_pictures[0][i].X > num3)
            {
                index2 = i;
                break;
            }
        }

        double num4 = static_cast<double>(this->m_pictures[0][index2].X - this->m_pictures[0][index].X);
        double num5 = static_cast<double>(this->m_pictures[0][index2].Y - this->m_pictures[0][index].Y);
        double num6 = static_cast<double>(num3 - this->m_pictures[0][index].X);
        double num7 = (num6 * num5 / num4 + static_cast<double>(this->m_pictures[0][index].Y)) / 128.0;

        for (int j = 0; j < (int)section.size(); j++)
        {
            section[j].X = static_cast<int>(static_cast<double>(section[j].X - 128) * num7 + 128.0);
            section[j].Y = static_cast<int>(static_cast<double>(section[j].Y - 128) * num7 + 128.0);
        }
    }
}

gradually_render_effect::gradually_render_effect()
    :starpoint(0)
    ,indexstar(0)
{
    this->m_type = EffectType::ET_GRADUALLY_RENDER;
    CJSection tempVar;
    tempVar.emplace_back(PointAttribute{0, 0, 0});
    tempVar.emplace_back(PointAttribute{ 800, 255, 0 });
    this->m_pictures.push_back(tempVar);
}

void gradually_render_effect::render(CJSection &section, int time)
{
    if (time <= this->m_start_frame_index)
    {
        this->starpoint = 0;
        this->indexstar = 0;
    }

    if (section.empty())
    {
        return;
    }

    if (time < this->m_start_frame_index || time > this->m_start_frame_index + this->m_frame_length)
    {
        return;
    }

    if (this->indexstar >=(int) section.size() - 1)
    {
        return;
    }

    size_t count = section.size();
    int num = this->indexstar % count;
    int num2 = this->starpoint + 1;
    int num3 = 0;
    CJSection list;

    for (int i = 0; i < (int)count; i++)
    {
        if (i < num)
        {
            list.push_back(section[i]);
        }
        else
        {
            list.push_back(section[i]);
            if (num == (int)count - 1 || i == (int)count - 1)
            {
                list.push_back(section[i]);
                section.clear();
                section.insert(section.end(), list.begin(), list.end());

                return;
            }

            PointAttribute& hwpointcolor = section[i];
            PointAttribute& hwpointcolor2 = section[i + 1];
            int x = hwpointcolor.X;
            int x2 = hwpointcolor2.X;
            int y = hwpointcolor.Y;
            int y2 = hwpointcolor2.Y;
            int num4 = std::abs(x2 - x);
            int num5 = std::abs(y2 - y);
            if (std::abs(y2 - y) > std::abs(x2 - x))
            {
                num4 = std::abs(y2 - y);
                num5 = std::abs(x2 - x);
            }
            int num6 = -num4;
            int num7 = x;
            int num8 = y;

            if (std::abs(y2 - y) > std::abs(x2 - x))
            {
                for (int j = 0; j < num4; j++, num3++)
                {
                    bool flag = false;

                    num6 += 2 * num5;
                    if (num6 >= 0)
                    {
                        flag = true;
                        num6 -= 2 * num4;
                    }

                    if (flag)
                    {
                        if (x > x2)
                        {
                            num7--;
                        }
                        else if (x < x2)
                        {
                            num7++;
                        }

                        if (y > y2)
                        {
                            num8--;
                        }
                        else if (y < y2)
                        {
                            num8++;
                        }
                    }
                    else
                    {
                        if (y > y2)
                        {
                            num8--;
                        }
                        else if (y < y2)
                        {
                            num8++;
                        }
                    }

                    if (num3 > num2)
                    {
                        PointAttribute tempVar(num7, num8, 0);
                        list.push_back(tempVar);
                        section.clear();
                        section.insert(section.end(), list.begin(), list.end());
                        if (i > this->indexstar)
                        {
                            this->indexstar = i;
                            this->starpoint = j;
                        }
                        else
                        {
                            this->starpoint += 10;
                        }
                        return;
                    }
                }
            }
            else
            {
                for (int k = 0; k < num4; k++, num3++)
                {
                    bool flag = false;
                    num6 += 2 * num5;
                    if (num6 >= 0)
                    {
                        flag = true;
                        num6 -= 2 * num4;
                    }

                    if (flag)
                    {
                        if (x > x2)
                        {
                            num7--;
                        }
                        else if (x < x2)
                        {
                            num7++;
                        }

                        if (y > y2)
                        {
                            num8--;
                        }
                        else if (y < y2)
                        {
                            num8++;
                        }
                    }
                    else
                    {
                        if (x > x2)
                        {
                            num7--;
                        }
                        else if (x < x2)
                        {
                            num7++;
                        }
                    }

                    if (num3 >= num2)
                    {
                        PointAttribute tempVar2(num7, num8, 0);
                        list.push_back(tempVar2);
                        section.clear();
                        section.insert(section.end(), list.begin(), list.end());
                        if (i > this->indexstar)
                        {
                            this->indexstar = i;
                            this->starpoint = k;
                        }
                        else
                        {
                            this->starpoint += 10;
                        }

                        return;
                    }
                }
            }
        }
    }
}






