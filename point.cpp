#include "point.h"

Point::Point(int x, int y)
    :X(x),Y(y)
{

}

bool Point::operator==(Point &_that)
{
    return this->X==_that.X&&this->Y==_that.Y;

}

Point &Point::operator=(Point &_that)
{
    this->X=_that.X;
    this->Y=_that.Y;
    return *this;
}

void Point::zoom(double z)
{
    X=static_cast<int>(static_cast<double>(X*z));
    Y=static_cast<int>(static_cast<double>(Y*z));
}
