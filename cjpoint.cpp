#include "cjpoint.h"

CJPoint::CJPoint()
{

}

CJPoint::CJPoint(int x, int y)
    :X(x),Y(y)
{

}

bool CJPoint::operator==(CJPoint &_that)
{
    return this->X==_that.X&&this->Y==_that.Y;

}

CJPoint &CJPoint::operator=(CJPoint &_that)
{
    this->X=_that.X;
    this->Y=_that.Y;
    return *this;
}

void CJPoint::zoom(double z)
{
    X=static_cast<int>(static_cast<double>(X*z));
    Y=static_cast<int>(static_cast<double>(Y*z));
}
