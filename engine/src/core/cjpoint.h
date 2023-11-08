#ifndef CJPOINT_H
#define CJPOINT_H


class CJPoint
{
public:
    CJPoint();
    CJPoint(int x, int y);
    int X;
    int Y;
    bool operator==(CJPoint&_that);
    CJPoint& operator=(CJPoint& _that);
    void zoom(double z);
};

#endif // CJPOINT_H
