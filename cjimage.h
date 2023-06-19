#ifndef CJIMAGE_H
#define CJIMAGE_H
#include "cjsection.h"
//#include<QVector>


class CJImage:public std::vector<CJSection>//一张动画的所有图
{
public:
    CJImage(QWidget* parent=0);
//    ~CJImage();
};

#endif // CJIMAGE_H
