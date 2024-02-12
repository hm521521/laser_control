#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include<QGraphicsView>
#include<QTimer>
#include<QtMath>
#define PI 3.1415926
class mygraphicsview : public QGraphicsView
{
    Q_OBJECT
public:
    explicit mygraphicsview(QWidget *parent = nullptr);
    void drawclock(QPainter *painter);
    void drawTextclock(QPainter *painter);
    void Init_Parameter();//初始化参数函数
    //void Draw_Clock(QPainter *painter);//绘制时钟
//    void Draw_Broad(QPainter *painter);//绘制时钟盘
    void Draw_Dial(QPainter *painter);//绘制刻度盘
//    void Draw_Text(QPainter *painter);//绘制刻度值
   void Draw_Pointer(QPainter *painter);//绘制指针
   void Draw_Textclock(QPainter * painter);
   void settype(int type);
   void setXsize(int value);
   void setYsize(int value);
   void setXoffset(int value);
   void setYoffset(int value);
   void setFontsize(int value);
   void setH_M(QString value);
   void setM_S(QString value);

protected:
    void paintEvent(QPaintEvent*event) Q_DECL_OVERRIDE;

private:
    QGraphicsScene* s;
    QTimer *timer;
    QPoint Center_pos;//时钟圆心坐标
    int R_Edge;//外部圆半径
    int R_Inside;//内部圆半径
    int R_Center;//中心小圆半径
    int R_Pointer;//中心指针圆半径
    QColor Color_Edge = QColor(0,0,0,255);//外部圆颜色
    QColor Color_Inside = QColor(255,255,255,255);//内部圆颜色
    QColor Color_Center = QColor(0,0,0,255);//中心小圆颜色
    int Div_Max = 12;//大刻度值
    int Div_Min = 5;//小刻度值
    float BaseAngle = 270;//基础仰角
    int H;//时
    int M;//分
    int S ;//秒
    int type=1;
    int X_size=100;
    int Y_size=100;
    int X_offsetvalue=0;
    int Y_offsetvalue=0;
    QString H_M=":";//时分间隔符
    QString M_S=":";//分秒间隔符
    int Fontsize=28;
private slots:
   // void setH_M()
signals:

};

#endif // MYGRAPHICSVIEW_H
