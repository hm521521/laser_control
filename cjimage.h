#ifndef CJIMAGE_H
#define CJIMAGE_H
#include "cjsection.h"
#include<QVector>


class CJImage:public QVector<CJSection>
{
public:
    CJImage(QWidget* parent=0);
//    ~CJImage();
};

#endif // CJIMAGE_H
