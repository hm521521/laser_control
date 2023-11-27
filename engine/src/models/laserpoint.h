#ifndef LASERPOINT_H
#define LASERPOINT_H

#include <QColor>

//typedef int LaserPoint;
//! 点.
/*!
    一个点包含的数据，（z有必要吗?xy可以变为float吗?
*/
class LaserPoint
{
public:
    LaserPoint();
    LaserPoint(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b);
    LaserPoint(int x, int y, int z);
    bool operator==(const LaserPoint&o)const {return X==o.X && Y==o.Y && Z==o.Z && R==o.R && G==o.G && B==o.B;}
    bool operator<(const LaserPoint&o)const{return Z<o.Z || Y<o.Y || X<o.X;}
    int X;
    int Y;
    int Z;
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

#endif // LASERPOINT_H
