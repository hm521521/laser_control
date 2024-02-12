#include "mygraphicsview.h"
#include<QGraphicsRectItem>
#include<QDebug>
#include<QTime>
mygraphicsview::mygraphicsview(QWidget *parent) : QGraphicsView(parent)
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));//定时调用绘制事件函数
    timer->start(1000);//开启定时器，执行周期为1秒针
}

void mygraphicsview::drawclock(QPainter *painter)
{
    Init_Parameter();
    Draw_Dial(painter);
    Draw_Pointer(painter);
}

void mygraphicsview::drawTextclock(QPainter *painter)
{
    Draw_Textclock(painter);
}

void mygraphicsview::Init_Parameter()
{
    Center_pos = QPoint(this->width()/2,this->height()/2);//以窗体中心为圆心
    R_Edge = this->height()/2;//以窗体高度的一半为半径
    R_Inside = R_Edge-10;
    R_Center = 15;
    R_Pointer = 6;
    QTime Time = QTime::currentTime();//获取当前系统时间

    H=Time.hour();//分别设置时、分、秒
    M=Time.minute();
    S=Time.second();
}

void mygraphicsview::Draw_Dial(QPainter *painter)
{
    painter->save();

    for(int Loop = 0; Loop <= Div_Max*Div_Min; Loop++)
    {
        float Angle = BaseAngle + (360 / (Div_Max * Div_Min))*Loop;//从基础仰角开始绘制的每条刻度线对应的角度
        int R = R_Inside-1;
        int x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
        int y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

        if(Loop % Div_Min == 0)//判断是否为大刻度
        {
            QPen pen(Qt::black);
            pen.setWidth(4);
            painter->setPen(pen);
            R = R_Inside-20;
        }
        else  //判断是否为小刻度
        {
            QPen pen(Qt::black);
            pen.setWidth(2);
            painter->setPen(pen);
            R = R_Inside-15;
        }

        int x_end = Center_pos.x() + R * cos((Angle / 180) * PI);
        int y_end = Center_pos.y() + R * sin((Angle / 180) * PI);

        painter->drawLine(QPoint(x_start,y_start),QPoint(x_end,y_end));//绘制刻度线
    }


    painter->restore();
}

void mygraphicsview::Draw_Pointer(QPainter *painter)
{
    painter->save();

    QBrush qBrush = QBrush(QColor(Qt::black));
    painter->setBrush(qBrush);
    QPen qPen(Qt::black);
    qPen.setWidth(2);   //设置画笔的粗细
    painter->setPen(qPen);
//**********绘制秒针***********************************************************************************
    float Angle = BaseAngle + (360 / (Div_Max * Div_Min))*S;
    float RightAngle = Angle + 90;//右侧角度
    float LeftAngle = Angle - 90;//左侧角度
    int R = R_Inside-1;
    int x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
    int y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

    R = R_Pointer-1;
    int x_end1 = Center_pos.x() + R * cos(RightAngle * 3.14 / 180);//过圆心的右侧切点
    int y_end1 = Center_pos.y() + R * sin(RightAngle * 3.14 / 180);
    int x_end2 = Center_pos.x() + R * cos(LeftAngle * 3.14 / 180);//过圆心的左侧切点
    int y_end2 = Center_pos.y() + R * sin(LeftAngle * 3.14 / 180);

    QPointF qTriangle_S[3] = {QPoint(x_start,y_start),QPoint(x_end1,y_end1),QPoint(x_end2,y_end2)};
    painter->drawPolygon(qTriangle_S,3);
//**********绘制分针***********************************************************************************
    Angle = BaseAngle + (360 / (Div_Max * Div_Min))*M;
    RightAngle = Angle + 90;//右侧角度
    LeftAngle = Angle - 90;//左侧角度
    R = R_Inside-60;
    x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
    y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

    R = R_Pointer-1;
    x_end1 = Center_pos.x() + R * cos(RightAngle * 3.14 / 180);//过圆心的右侧切点
    y_end1 = Center_pos.y() + R * sin(RightAngle * 3.14 / 180);
    x_end2 = Center_pos.x() + R * cos(LeftAngle * 3.14 / 180);//过圆心的左侧切点
    y_end2 = Center_pos.y() + R * sin(LeftAngle * 3.14 / 180);

    QPointF qTriangle_M[3] = {QPoint(x_start,y_start),QPoint(x_end1,y_end1),QPoint(x_end2,y_end2)};
    painter->drawPolygon(qTriangle_M,3);
//**********绘制时针***********************************************************************************
    Angle = BaseAngle + (360 / Div_Max)*H;
    RightAngle = Angle + 90;//右侧角度
    LeftAngle = Angle - 90;//左侧角度
    R = R_Inside-120;
    x_start = Center_pos.x() + R * cos((Angle / 180) * PI);
    y_start = Center_pos.y() + R * sin((Angle / 180) * PI);

    R = R_Pointer-1;
    x_end1 = Center_pos.x() + R * cos(RightAngle * 3.14 / 180);//过圆心的右侧切点
    y_end1 = Center_pos.y() + R * sin(RightAngle * 3.14 / 180);
    x_end2 = Center_pos.x() + R * cos(LeftAngle * 3.14 / 180);//过圆心的左侧切点
    y_end2 = Center_pos.y() + R * sin(LeftAngle * 3.14 / 180);

    QPointF qTriangle_H[3] = {QPoint(x_start,y_start),QPoint(x_end1,y_end1),QPoint(x_end2,y_end2)};
    painter->drawPolygon(qTriangle_H,3);

    painter->restore();
}

void mygraphicsview::Draw_Textclock(QPainter *painter)
{
     painter->save();
//     QBrush qBrush = QBrush(QColor(Qt::black));
//     painter->setBrush(qBrush);
//     QPen qPen(Qt::black);
//     qPen.setWidth(2);   //设置画笔的粗细
//     painter->setPen(qPen);
//     painter->drawLine(QPoint(0,0),QPoint(100,100));
     QRect rect(0,0,this->width(),this->height());
      QTime Time = QTime::currentTime();
      H=Time.hour();//分别设置时、分、秒
      M=Time.minute();
      S=Time.second();
      QString _H;
      QString _M;
      QString _S;
      if(H<10)
           _H='0'+QString::number(H,10);
      else
           _H=QString::number(H,10);
      if(M<10)
           _M='0'+QString::number(M,10);
      else
           _M=QString::number(M,10);
      if(S<10)
           _S='0'+QString::number(S,10);
      else
           _S=QString::number(S,10);
      QString time= _H + H_M + _M+ M_S + _S;
//     QString time="18:30";
                     QFont font;
                     font.setPixelSize(Fontsize);
                     QPen pen(Qt::black);
                     pen.setWidth(4);
                     painter->setPen(pen);
                     painter->setFont(font);
                     painter->drawText(rect,Qt::AlignCenter,time);
//                     painter->drawText(50,50,time);

     painter->restore();

}

void mygraphicsview::settype(int type)
{
    this->type=type;
}

void mygraphicsview::setXsize(int value)
{
    this->X_size=value;
}

void mygraphicsview::setYsize(int value)
{
    this->Y_size=value;
}

void mygraphicsview::setXoffset(int value)
{
    this->X_offsetvalue=value;
}

void mygraphicsview::setYoffset(int value)
{
    this->Y_offsetvalue=value;
}

void mygraphicsview::setFontsize(int value)
{
    this->Fontsize=value;
}

void mygraphicsview::setH_M(QString value)
{
    this->H_M=value;
}

void mygraphicsview::setM_S(QString value)
{
    this->M_S=value;
}



void mygraphicsview::paintEvent(QPaintEvent *)
{   QPainter painter(this->viewport());

    if(type==1){

        float y=(this->height()/2)/100*(100-X_size);
        float x=(this->width()/2)/100*(100-Y_size);
        float X_offset=this->width()/2/50*X_offsetvalue;
        float Y_offset=this->height()/2/50*Y_offsetvalue;
        painter.setViewport(x-X_offset,y-Y_offset,this->width()-2*x,this->height()-2*y);
        painter.setWindow(0,0,this->width(),this->height());
        QRectF rect(-100,-100,100,100);
        s=new QGraphicsScene(rect);
        this->setScene(s);
        painter.setRenderHints(QPainter::Antialiasing);
        this->setAlignment(Qt::AlignLeft|Qt::AlignTop);


        drawclock(&painter);


    }
    else if(type==0)
         qDebug()<<"绘画事件调用";
    else if(type==2){
//        qDebug()<<"2";
//        QRectF rect(-100,-100,100,100);
//                s=new QGraphicsScene(rect);
//              //  painter.setViewport(x-X_offset,y-Y_offset,this->width()-2*x,this->height()-2*y);

//                painter.setWindow(0,0,this->width(),this->height());
//                 this->setScene(s);
//                QString time="18:30";
//                QFont font;
//                font.setPixelSize(25);
//                QPen pen(Qt::black);
//                pen.setWidth(4);
//                painter.setPen(pen);
//                painter.setFont(font);
//                painter.drawText(rect,time);
//                qDebug()<<"绘画事件调用";
        float y=(this->height()/2)/100*(100-X_size);
        float x=(this->width()/2)/100*(100-Y_size);
        float X_offset=this->width()/2/50*X_offsetvalue;
        float Y_offset=this->height()/2/50*Y_offsetvalue;
        painter.setViewport(x-X_offset,y-Y_offset,this->width()-2*x,this->height()-2*y);
        painter.setWindow(0,0,this->width(),this->height());
        QRectF rect(-100,-100,100,100);
        s=new QGraphicsScene(rect);
        this->setScene(s);
        drawTextclock(&painter);
    }
    else if(type==3){
        qDebug()<<"3";
    }
    else if(type==4){
        qDebug()<<"4";
    }
    else if(type==5){
        qDebug()<<"5";
    }
    else if(type==6){
        qDebug()<<"6";
    }

}

