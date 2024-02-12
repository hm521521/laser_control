#include "gdiplus_helper.h"
#include"pointattribute.h"
#include<QPainterPath>
#include<QFont>

void gdiplus_helper::get_point_from_text(QString txt, CJSection &section, unsigned char r, unsigned char g, unsigned char b)
{
    QPainterPath painter_path;
    painter_path.addText(QPointF(128,128),QFont("Times New Roman"),txt);

    CJSection list;
    for(int i=0;i<painter_path.elementCount();i++)
    {
        PointAttribute temp_var(static_cast<int>(qRound(painter_path.elementAt(i).x)),static_cast<int>(qRound(painter_path.elementAt(i).y)),0,r,g,b);
        list.push_back(temp_var);
        section.insert(section.end(),list.begin(),list.end());
        list.clear();
}
//    for (int i=0;i<path_data.count;i++)
}
