#include "configuration.h"
#include<QCoreApplication>
#include<QFile>
//#include<iostream>
//#include<fstream>
#include<QDataStream>
#include<QFileDialog>
#include<QObject>
constexpr auto CONFIG_HEADER = "hwstaticconfig";
inline unsigned char get_color_value(float value)
{
    if (value > 255.0f)
    {
        return 255;
    }
    else if (value < 0.0f)
    {
        return 0;
    }
    else
    {
        return static_cast<unsigned char>(value);
    }
}

Configuration::Configuration(QObject* parent)
{
    Loop = true;
    x_invert = false;
    y_invert = false;
    xy_swap = false;
    x_size = 1.0f;
    y_size = 1.0f;
    xy_locked = true;
    x_offset = 0;
    y_offset = 0;
    adjust_r = true;
    red = 1.0f;
    adjust_g = true;
    green = 1.0f;
    adjust_b = true;
    blue = 1.0f;
    moORsu = true;
    Ybi = 1.0f;
    Speed = 20;
    PointGap = 10;
    Delay = 1;
    lang = "zh-CN";
    m_path=QCoreApplication::applicationDirPath();
    m_path.append("/system/de.config");
}

void Configuration::Reset()
{
    this->x_invert = false;
    this->y_invert = false;
    this->xy_swap = false;
    this->x_size = 1.0f;
    this->y_size = 1.0f;
    this->xy_locked = true;
    this->x_offset = 0;
    this->y_offset = 0;
}

void Configuration::Save()
{
    QFile file(this);
    file.setFileName(m_path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        QDataStream binaryWriter(&file);
        int len = strlen(CONFIG_HEADER);
        binaryWriter.writeRawData((char*)&len, 1);
        binaryWriter.writeRawData(CONFIG_HEADER, len);
        binaryWriter.writeRawData((char*)&Loop, 1);
        binaryWriter.writeRawData((char*)&x_invert, 1);
        binaryWriter.writeRawData((char*)&y_invert, 1);
        binaryWriter.writeRawData((char*)&xy_swap, 1);
        binaryWriter.writeRawData((char*)&x_size, 4);
        binaryWriter.writeRawData((char*)&y_size, 4);
        binaryWriter.writeRawData((char*)&xy_locked, 1);
        binaryWriter.writeRawData((char*)&x_offset, 4);
        binaryWriter.writeRawData((char*)&y_offset, 4);
        binaryWriter.writeRawData((char*)&adjust_r, 1);
        binaryWriter.writeRawData((char*)&red, 4);
        binaryWriter.writeRawData((char*)&adjust_g, 1);
        binaryWriter.writeRawData((char*)&green, 4);
        binaryWriter.writeRawData((char*)&adjust_b, 1);
        binaryWriter.writeRawData((char*)&blue, 4);
        binaryWriter.writeRawData((char*)&moORsu, 1);
        binaryWriter.writeRawData((char*)&Ybi, 4);
        binaryWriter.writeRawData((char*)&Speed, 4);
        binaryWriter.writeRawData((char*)&PointGap, 4);
        binaryWriter.writeRawData((char*)&Delay, 1);
        int lang_len=lang.length();
        binaryWriter.writeRawData((char*)&lang_len, 1);
        binaryWriter.writeRawData(lang.c_str(), lang_len);
        file.close();
}
}

void Configuration::Load()
{
    QFile file(m_path);
    if(!file.open(QIODevice::ReadOnly))
        return;
    QDataStream binaryReader(&file);
    unsigned char header_len=0;
    binaryReader.readRawData((char*)header_len,sizeof(header_len));
    if(header_len==strlen(CONFIG_HEADER))
    {
        char header[128]={0};
        binaryReader.readRawData(header,header_len);
        if(0 == strcmp(header, CONFIG_HEADER))
        {
            binaryReader.readRawData((char*)&this->Loop, 1);
            binaryReader.readRawData((char*)&this->x_invert, 1);
            binaryReader.readRawData((char*)&this->y_invert, 1);
            binaryReader.readRawData((char*)&this->xy_swap, 1);
            binaryReader.readRawData((char*)&this->x_size, 4);
            binaryReader.readRawData((char*)&this->y_size, 4);
            binaryReader.readRawData((char*)&this->xy_locked, 1);
            binaryReader.readRawData((char*)&this->x_offset, sizeof(int));
            binaryReader.readRawData((char*)&this->y_offset, sizeof(int));
            binaryReader.readRawData((char*)&this->adjust_r, sizeof(bool));
            binaryReader.readRawData((char*)&this->red, sizeof(float));
            binaryReader.readRawData((char*)&this->adjust_g, sizeof(bool));
            binaryReader.readRawData((char*)&this->green, sizeof(float));
            binaryReader.readRawData((char*)&this->adjust_b, sizeof(bool));
            binaryReader.readRawData((char*)&this->blue, sizeof(float));
            binaryReader.readRawData((char*)&this->moORsu, sizeof(bool));
            binaryReader.readRawData((char*)&this->Ybi, sizeof(float));
            binaryReader.readRawData((char*)&this->Speed, sizeof(int));
            binaryReader.readRawData((char*)&this->PointGap, sizeof(int));
            binaryReader.readRawData((char*)&this->Delay, sizeof(unsigned char));
            int size = 0;
            binaryReader.readRawData((char*)&size, sizeof(char));
            this->lang.resize(size);
            binaryReader.readRawData((char*)this->lang.data(), size);
        }

    }
}

void Configuration::SaveAs()
{
    QString filename="";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream binaryWriter(&file);
        int len = strlen(CONFIG_HEADER);
        binaryWriter.writeRawData((char*)&len, 1);
        binaryWriter.writeRawData(CONFIG_HEADER, len);
        binaryWriter.writeRawData((char*)&Loop, 1);
        binaryWriter.writeRawData((char*)&x_invert, 1);
        binaryWriter.writeRawData((char*)&y_invert, 1);
        binaryWriter.writeRawData((char*)&xy_swap, 1);
        binaryWriter.writeRawData((char*)&x_size, 4);
        binaryWriter.writeRawData((char*)&y_size, 4);
        binaryWriter.writeRawData((char*)&xy_locked, 1);
        binaryWriter.writeRawData((char*)&x_offset, 4);
        binaryWriter.writeRawData((char*)&y_offset, 4);
        binaryWriter.writeRawData((char*)&adjust_r, 1);
        binaryWriter.writeRawData((char*)&red, 4);
        binaryWriter.writeRawData((char*)&adjust_g, 1);
        binaryWriter.writeRawData((char*)&green, 4);
        binaryWriter.writeRawData((char*)&adjust_b, 1);
        binaryWriter.writeRawData((char*)&blue, 4);
        binaryWriter.writeRawData((char*)&moORsu, 1);
        binaryWriter.writeRawData((char*)&Ybi, 4);
        binaryWriter.writeRawData((char*)&Speed, 4);
        binaryWriter.writeRawData((char*)&PointGap, 4);
        binaryWriter.writeRawData((char*)&Delay, 1);
        int lang_len=lang.length();
        binaryWriter.writeRawData((char*)&lang_len, 1);
        binaryWriter.writeRawData(lang.c_str(), lang_len);
        file.close();
    }

}

bool Configuration::getLoop() const
{
    return Loop;
}

void Configuration::setLoop(bool value)
{
    Loop=value;
}

void Configuration::get_color(LaserPoint lp,unsigned char &r, unsigned char &g, unsigned char &b,unsigned char &gray)
{
    float red = static_cast<float>(lp.R);
    float green = static_cast<float>(lp.G);
    float blue = static_cast<float>(lp.B);
    if (this->adjust_r && !this->adjust_g && !this->adjust_b)
    {
        red = red + green / 2.0f + blue / 2.0f;
        green = 0.0f;
        blue = 0.0f;
    }
    else if (!this->adjust_r && this->adjust_g && !this->adjust_b)
    {
        green = red / 2.0f + green + blue / 2.0f;
        red = 0.0f;
        blue = 0.0f;
    }
    else if (!this->adjust_r && !this->adjust_g && this->adjust_b)
    {
        blue = red / 2.0f + green / 2.0f + blue;
        red = 0.0f;
        green = 0.0f;
    }
    else if (this->adjust_r && this->adjust_g && !this->adjust_b)
    {
        red += blue / 2.0f;
        green += blue / 2.0f;
        blue = 0.0f;
    }
    else if (this->adjust_r && !this->adjust_g && this->adjust_b)
    {
        red += green / 2.0f;
        blue += green / 2.0f;
        green = 0.0f;
    }
    else if (!this->adjust_r && this->adjust_g && this->adjust_b)
    {
        green += red / 2.0f;
        blue += red / 2.0f;
        red = 0.0f;
    }
    else if (!this->adjust_r && !this->adjust_g && !this->adjust_b)
    {
        green = 0.0f;
        blue = 0.0f;
        red = 0.0f;
    }
    if (this->moORsu)
    {
        float num4 = red;
        if (blue > num4)
        {
            num4 = blue;
        }
        if (green > num4)
        {
            num4 = green;
        }
        float num5 = (1.0f - this->Ybi) * num4;
        red = red * this->red - num5;
        green = green * this->green - num5;
        blue = blue * this->blue - num5;
        num5 = (red * 299.0f + green * 587.0f + blue * 114.0f) / 1000.0f;
        r = get_color_value(red);
        g = get_color_value(green);
        b = get_color_value(blue);
        gray = get_color_value(num5);
    }
    else
    {
        float num6 = red;
        if (blue > num6)
        {
            num6 = blue;
        }
        if (green > num6)
        {
            num6 = green;
        }
        float num5 = (1.0f - this->Ybi) * num6;
        red = red * this->red - num5;
        green = green * this->green - num5;
        blue = blue * this->blue - num5;
        num5 = (red * 299.0f + green * 587.0f + blue * 114.0f) / 1000.0f;
        if (red > 0.0f)
        {
            r = 255;
        }
        else
        {
            r = 0;
        }

        if (green > 0.0f)
        {
            g = 255;
        }
        else
        {
            g = 0;
        }

        if (blue > 0.0f)
        {
            b = 255;
        }
        else
        {
            b = 0;
        }

        if (num5 > 0.0f)
        {
            gray = 255;
        }
        else
        {
            gray = 0;
        }
    }
}

LaserPoint Configuration::get_point_by_config(LaserPoint lp,int &mix, int &miy)
{
    float fx = static_cast<float>(lp.X);
    float fy = static_cast<float>(lp.Y);
    if (this->xy_locked)
    {
        fx = (fx - 127.5f) * this->x_size + 127.5f + static_cast<float>(this->x_offset);
        fy = (fy - 127.5f) * this->y_size + 127.5f + static_cast<float>(this->y_offset);
    }
    else
    {
        fx = (fx - 127.5f) * this->x_size + 127.5f + static_cast<float>(this->x_offset);
        fy = (fy - 127.5f) * this->y_size + 127.5f + static_cast<float>(this->y_offset);
    }
    if (this->x_invert)
    {
        fx = (fx - 127.5f) * -1.0f + 127.5f;
    }
    if (this->y_invert)
    {
        fy = (fy - 127.5f) * -1.0f + 127.5f;
    }

    if (this->xy_swap)
    {
        mix = static_cast<int>(fy);
        miy = static_cast<int>(fx);
    }
    else
    {
        mix = static_cast<int>(fx);
        miy = static_cast<int>(fy);
    }

    //ishow的xy是反的
    return LaserPoint( miy, mix, 0);
}

LaserPoint Configuration::get_point_by_config(LaserPoint lp)
{
    float fx = static_cast<float>(lp.X);
    float fy = static_cast<float>(lp.Y);
    if (this->xy_locked)
    {
        fx = (fx - 127.5f) * this->x_size + 127.5f + static_cast<float>(this->x_offset);
        fy = (fy - 127.5f) * this->y_size + 127.5f + static_cast<float>(this->y_offset);
    }
    else
    {
        fx = (fx - 127.5f) * this->x_size + 127.5f + static_cast<float>(this->x_offset);
        fy = (fy - 127.5f) * this->y_size + 127.5f + static_cast<float>(this->y_offset);
    }
    if (this->x_invert)
    {
        fx = (fx - 127.5f) * -1.0f + 127.5f;
    }

    if (this->y_invert)
    {
        fy = (fy - 127.5f) * -1.0f + 127.5f;
    }
    //ishow的xy是反的，所以交换的等于没交换，没交换的要交换
    if(this->xy_swap)
    {
        return LaserPoint(static_cast<int>(fx), static_cast<int>(fy),0);
    }
    else
    {
        return LaserPoint(static_cast<int>(fy), static_cast<int>(fx),0);
    }
}
