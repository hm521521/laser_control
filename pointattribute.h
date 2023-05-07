#ifndef POINTATTRIBUTE_H
#define POINTATTRIBUTE_H
#include "point.h"

class Configuration;
class PointAttribute
{
public:
    PointAttribute(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b);
    PointAttribute(int x, int y, int z);
    int X;
    int Y;
    int Z;
    unsigned char R;
    unsigned char G;
    unsigned char B;
    bool Selected;
    void ClearColor();
    Point Zoom(double s);
    void move_by_z2();
    void get_color(Configuration *config,unsigned char &r,unsigned char&g,unsigned char &b,unsigned char &gray);
    Point get_point_by_config(Configuration *config,int &mix, int &miy);
    Point get_point_by_config(Configuration *config);
};

#endif // POINTATTRIBUTE_H
