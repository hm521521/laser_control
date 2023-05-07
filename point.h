#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(int x, int y);
    int X;
    int Y;
    bool operator==(Point&_that);
    Point& operator=(Point& _that);
    void zoom(double z);
};

#endif // POINT_H
