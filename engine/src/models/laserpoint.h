#ifndef LASERPOINT_H
#define LASERPOINT_H

#include <QColor>

class LaserPoint
{
public:
    LaserPoint(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b);
    LaserPoint(int x, int y, int z);
    int X;
    int Y;
    int Z;
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

#endif // LASERPOINT_H
