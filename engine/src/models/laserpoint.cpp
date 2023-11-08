#include "laserpoint.h"

LaserPoint::LaserPoint(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b)
    : X(x), Y(y), Z(z), R(r), G(g), B(b)
{

}

LaserPoint::LaserPoint(int x, int y, int z)
    : X(x), Y(y), Z(z),R(0), G(0), B(0)
{


}
