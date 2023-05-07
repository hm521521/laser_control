#include "pointattribute.h"
#include "configuration.h"


PointAttribute::PointAttribute(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b)
   : X(x), Y(y), Z(z), R(r), G(g), B(b), Selected(false)
{

}

PointAttribute::PointAttribute(int x, int y, int z)
    : X(x), Y(y), Z(z),R(0), G(0), B(0), Selected(false)
{


}

void PointAttribute::ClearColor()
{
    this->R=0;
    this->G=0;
    this->B=0;
}

Point PointAttribute::Zoom(double s)//调整点的位置
{
    return {static_cast<int>(static_cast<double>(this->X*s)),static_cast<int>(static_cast<double>(Y*s))};
}

void PointAttribute::move_by_z2()
{
    double num=(512+static_cast<double>(this->Z))/512;
    this->X=static_cast<int>(static_cast<double>(this->X-128)*num+128);
    this->Y=static_cast<int>(static_cast<double>(this->Y-128)*num+128);
}
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
void PointAttribute::get_color(Configuration *config, unsigned char &r, unsigned char &g, unsigned char &b, unsigned char &gray)
{
    float red = static_cast<float>(this->R);
    float green = static_cast<float>(this->G);
    float blue = static_cast<float>(this->B);
    if (config->adjust_r && !config->adjust_g && !config->adjust_b)
    {
        red = red + green / 2.0f + blue / 2.0f;
        green = 0.0f;
        blue = 0.0f;
    }
    else if (!config->adjust_r && config->adjust_g && !config->adjust_b)
    {
        green = red / 2.0f + green + blue / 2.0f;
        red = 0.0f;
        blue = 0.0f;
    }
    else if (!config->adjust_r && !config->adjust_g && config->adjust_b)
    {
        blue = red / 2.0f + green / 2.0f + blue;
        red = 0.0f;
        green = 0.0f;
    }
    else if (config->adjust_r && config->adjust_g && !config->adjust_b)
    {
        red += blue / 2.0f;
        green += blue / 2.0f;
        blue = 0.0f;
    }
    else if (config->adjust_r && !config->adjust_g && config->adjust_b)
    {
        red += green / 2.0f;
        blue += green / 2.0f;
        green = 0.0f;
    }
    else if (!config->adjust_r && config->adjust_g && config->adjust_b)
    {
        green += red / 2.0f;
        blue += red / 2.0f;
        red = 0.0f;
    }
    else if (!config->adjust_r && !config->adjust_g && !config->adjust_b)
    {
        green = 0.0f;
        blue = 0.0f;
        red = 0.0f;
    }
    if (config->moORsu)
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
        float num5 = (1.0f - config->Ybi) * num4;
        red = red * config->red - num5;
        green = green * config->green - num5;
        blue = blue * config->blue - num5;
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
        float num5 = (1.0f - config->Ybi) * num6;
        red = red * config->red - num5;
        green = green * config->green - num5;
        blue = blue * config->blue - num5;
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

Point PointAttribute::get_point_by_config(Configuration *config, int &mix, int &miy)
{
    float fx = static_cast<float>(this->X);
    float fy = static_cast<float>(this->Y);
    if (config->xy_locked)
    {
        fx = (fx - 127.5f) * config->x_size + 127.5f + static_cast<float>(config->x_offset);
        fy = (fy - 127.5f) * config->x_size + 127.5f + static_cast<float>(config->y_offset);
    }
    else
    {
        fx = (fx - 127.5f) * config->x_size + 127.5f + static_cast<float>(config->x_offset);
        fy = (fy - 127.5f) * config->y_size + 127.5f + static_cast<float>(config->y_offset);
    }
    if (config->x_invert)
    {
        fx = (fx - 127.5f) * -1.0f + 127.5f;
    }
    if (config->y_invert)
    {
        fy = (fy - 127.5f) * -1.0f + 127.5f;
    }

    if (config->xy_swap)
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
    return { miy, mix };
}

Point PointAttribute::get_point_by_config(Configuration *config)
{
    float fx = static_cast<float>(this->X);
    float fy = static_cast<float>(this->Y);
    if (config->xy_locked)
    {
        fx = (fx - 127.5f) * config->x_size + 127.5f + static_cast<float>(config->x_offset);
        fy = (fy - 127.5f) * config->x_size + 127.5f + static_cast<float>(config->y_offset);
    }
    else
    {
        fx = (fx - 127.5f) * config->x_size + 127.5f + static_cast<float>(config->x_offset);
        fy = (fy - 127.5f) * config->y_size + 127.5f + static_cast<float>(config->y_offset);
    }
    if (config->x_invert)
    {
        fx = (fx - 127.5f) * -1.0f + 127.5f;
    }

    if (config->y_invert)
    {
        fy = (fy - 127.5f) * -1.0f + 127.5f;
    }
    //ishow的xy是反的，所以交换的等于没交换，没交换的要交换
    if(config->xy_swap)
    {
        return { static_cast<int>(fx), static_cast<int>(fy) };
    }
    else
    {
        return { static_cast<int>(fy), static_cast<int>(fx) };
    }

}
