#ifndef CJSECTION_H
#define CJSECTION_H
#include<QVector>
#include "pointattribute.h"
#include<QPainter>
#include<QGraphicsView>
#include"configuration.h"
#include<QPainter>
//#include"main_panel.h"
//class scene_panel;

struct ishow_data
{
    unsigned char x;
    unsigned char y;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char gray;
};

class CJSection:public std::vector<PointAttribute>//一帧画面的所有点
{
public:
    CJSection(QGraphicsView *parent=0);
    void draw_picture(QPainter *painter,int x,int y, int width,int height,bool show_point=false,bool show_selected=false);
    std::vector<ishow_data> globalprocessing(Configuration *config);
private:
    QGraphicsView *m_parent;
};

#endif // CJSECTION_H
