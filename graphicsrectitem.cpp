#include "graphicsrectitem.h"
#include <QPen>
#include<QtMath>



graphicsrectitem::graphicsrectitem(QGraphicsView *parent):
    m_bRotate(false),
    m_RotateAngle(0),
    m_oldRect(0,0,10,10),
    m_bResize(false),
    m_StateFlag(DEFAULT_FLAG),
    m_dPoint(0,0)
{

    setFlag(QGraphicsItem::ItemIsMovable);
    pPointFofSmallRotateRect = new QPointF[4];
    SetRotate(0);
    setFlag(QGraphicsItem::ItemIsSelectable);//
    setAcceptHoverEvents(true);

}
QPointF graphicsrectitem::getdPoint()
{
    return m_dPoint;
}
void graphicsrectitem::setdPoint(QPointF dp)
{
    m_dPoint=dp;
}

STATE_FLAG graphicsrectitem::getStageFlag()
{
    return m_StateFlag;
}

QRectF graphicsrectitem::boundingRect() const
{
    QRectF boundingRectF = m_oldRectPolygon.boundingRect();
    return QRectF(boundingRectF.x(),boundingRectF.y(),boundingRectF.width(),boundingRectF.height());
}

graphicsrectitem::~graphicsrectitem()
{
    delete []pPointFofSmallRotateRect;
    pPointFofSmallRotateRect = nullptr;
}

void graphicsrectitem::setRectSize(QRectF mrect, bool bResetRotateCenter)
{
    m_oldRect=mrect;
    if(bResetRotateCenter)
    {
        m_RotateCenter.setX(m_oldRect.x()+m_oldRect.width()/2);
        m_RotateCenter.setY(m_oldRect.y()+m_oldRect.height()/2);
    }
    m_oldRectPolygon = getRotatePolygonFromRect(m_RotateCenter,m_oldRect,m_RotateAngle);
    m_insicedRectf = QRectF(m_oldRect.x()+8,m_oldRect.y()+8,m_oldRect.width()-16,m_oldRect.height()-16);
    m_insicedPolygon =getRotatePolygonFromRect(m_RotateCenter,m_insicedRectf,m_RotateAngle);
    m_leftRectf = QRectF(m_oldRect.x(),m_oldRect.y(),8,m_oldRect.height()-8);
    m_leftPolygon = getRotatePolygonFromRect(m_RotateCenter,m_leftRectf,m_RotateAngle);
    m_topRectf = QRectF(m_oldRect.x()+8,m_oldRect.y(),m_oldRect.width()-8,8);
    m_topPolygon = getRotatePolygonFromRect(m_RotateCenter,m_topRectf,m_RotateAngle);
    m_rightRectf = QRectF(m_oldRect.right()-8,m_oldRect.y()+8,8,m_oldRect.height()-16);
    m_rightPolygon = getRotatePolygonFromRect(m_RotateCenter,m_rightRectf,m_RotateAngle);
    m_bottomRectf = QRectF(m_oldRect.x(),m_oldRect.bottom()-8,m_oldRect.width()-8,8);
    m_bottomPolygon = getRotatePolygonFromRect(m_RotateCenter,m_bottomRectf,m_RotateAngle);
    m_SmallRotateRect = getSmallRotateRect(mrect.topLeft(),mrect.topRight());//矩形正上方的旋转标记矩形
    m_SmallRotatePolygon = getRotatePolygonFromRect(m_RotateCenter,m_SmallRotateRect,m_RotateAngle);

}

void graphicsrectitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen mPen = QPen(Qt::darkBlue);
    painter->setPen(mPen);
     //绘制旋转后的矩形
    painter->drawPolygon(m_oldRectPolygon);
        //绘制旋转圆形

    int xin=m_oldRectPolygon.at(0).x();
    int yin=m_oldRectPolygon.at(0).y();
    int xs=(m_oldRectPolygon.at(2).x()-m_oldRectPolygon.at(0).x())/2;
    int ys=(m_oldRectPolygon.at(3).y()-m_oldRectPolygon.at(1).y())/2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if (i*j==1) continue;
            painter->drawRect(xin+i*xs-6,yin+j*ys-6,12,12);
        }
    }
//    painter->drawEllipse(m_dPoint.x(),m_dPoint.y(),20,20);

}

void graphicsrectitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
          {
              m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
              if(m_SmallRotatePolygon.containsPoint(m_startPos,Qt::WindingFill))//旋转矩形
              {
                  setCursor(Qt::PointingHandCursor);
                  m_StateFlag = ROTATE;
              }
              else if(m_insicedPolygon.containsPoint(m_startPos,Qt::WindingFill))//在矩形内框区域时按下鼠标，则可拖动图片
              {
                  setCursor(Qt::ClosedHandCursor);   //改变光标形状,手的形状
                  m_StateFlag = MOV_RECT;//标记当前为鼠标拖动图片移动状态
              }
             else if(m_leftPolygon.containsPoint(m_startPos,Qt::WindingFill))
             {
                 setCursor(Qt::SizeHorCursor);
                 m_StateFlag = MOV_LEFT_LINE;//标记当前为用户按下矩形的左边界区域
             }
             else if(m_rightPolygon.containsPoint(m_startPos,Qt::WindingFill))
             {
                 setCursor(Qt::SizeHorCursor);
                 m_StateFlag = MOV_RIGHT_LINE;//标记当前为用户按下矩形的右边界区域
             }
             else if(m_topPolygon.containsPoint(m_startPos,Qt::WindingFill))
             {
                 setCursor(Qt::SizeVerCursor);
                 m_StateFlag = MOV_TOP_LINE;//标记当前为用户按下矩形的上边界区域
             }
             else if(m_bottomPolygon.containsPoint(m_startPos,Qt::WindingFill))
             {
                 setCursor(Qt::SizeVerCursor);
                 m_StateFlag = MOV_BOTTOM_LINE;//标记当前为用户按下矩形的下边界区域
             }
     //        else if(m_rbPolygon.containsPoint(m_startPos,Qt::WindingFill))
     //        {
     //            setCursor(Qt::SizeFDiagCursor);
     //            m_StateFlag = MOV_RIGHTBOTTOM_RECT;//标记当前为用户按下矩形的右下角
     //        }
             else
             {
                m_StateFlag = DEFAULT_FLAG;
             }
         }
         else
         {
             QGraphicsItem::mousePressEvent(event);
    }
}

void graphicsrectitem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{

        if ((event->pos().y()<m_oldRect.y()+10)&&(event->pos().y()>m_oldRect.y()-20))
            setCursor(Qt::SizeVerCursor);
        else if ((event->pos().x()<m_oldRect.x()+10)&&(event->pos().x()>m_oldRect.x()-20))
            setCursor(Qt::SizeHorCursor);
        else if ( (event->pos().y()>m_oldRect.bottom()-10)&&(event->pos().y()<m_oldRect.bottom()+20) )
            setCursor(Qt::SizeVerCursor);
        else if ( (event->pos().x()>m_oldRect.right()-10)&&(event->pos().x()<m_oldRect.right()+20) )
            setCursor(Qt::SizeHorCursor);
        else
        {
            setCursor(Qt::PointingHandCursor);
        }

}
//void graphicsrectitem::checkOutBound(QRectF mrect)
//{

//}

void graphicsrectitem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_StateFlag == ROTATE)
         {
            int nRotateAngle = atan2((event->pos().x()-m_RotateCenter.x()),(event->pos().y()-m_RotateCenter.y()))*180/M_PI;
            SetRotate(180-nRotateAngle);
            setRectSize(m_oldRect);
            //qDebug()<<nRotateAngle;
         }
         else if(m_StateFlag == MOV_RECT)
        {
             QPointF point = (event->pos() - m_startPos);

             if (m_dPoint.x()+point.x()<-245+187)
                 point.setX(-245+187-m_dPoint.x());
             if(m_dPoint.x()+point.x()>490-m_oldRect.width()-58)
                 point.setX(490-m_oldRect.width()-58-m_dPoint.x());
             if(m_dPoint.y()+point.y()<-245+187)
                 point.setY(-245+187-m_dPoint.y());
             if(m_dPoint.y()+point.y()>490-m_oldRect.height()-58)
                 point.setY(490-m_oldRect.height()-58-m_dPoint.y());
             moveBy(point.x(),point.y());
             m_dPoint+=point;

             setRectSize(m_oldRect);
//             m_realPos+=point;
             scene()->update();
         }
         else if(m_StateFlag == MOV_LEFT_LINE)
         {
             QPointF pf = QPointF((m_oldRectPolygon.at(1).x()+m_oldRectPolygon.at(2).x())/2,((m_oldRectPolygon.at(1).y()+m_oldRectPolygon.at(2).y())/2));
             //计算到右侧边中点的距离

             qreal dis = sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x()) +(event->pos().y()-pf.y())*(event->pos().y()-pf.y()));
             qreal dis2LT = sqrt((event->pos().x()-m_oldRectPolygon.at(0).x())*(event->pos().x()-m_oldRectPolygon.at(0).x()) +(event->pos().y()-m_oldRectPolygon.at(0).y())*(event->pos().y()-m_oldRectPolygon.at(0).y()));
             qreal dis2RT = sqrt((event->pos().x()-m_oldRectPolygon.at(1).x())*(event->pos().x()-m_oldRectPolygon.at(1).x()) +(event->pos().y()-m_oldRectPolygon.at(1).y())*(event->pos().y()-m_oldRectPolygon.at(1).y()));
             if(dis<16||dis2LT>dis2RT)
             {
                 return;
             }
             else
             {
//                 qreal temx=(-490/2-pf.x());
//                 qreal temy=(event->pos().y()-pf.y());
//                 qreal dismax=sqrt(temx*temx+temy*temy);
//                 if (dis>dismax)
//                 {
//                     dis=sqrt(temx*temx+temy*temy);

//                 }
                 QRectF newRect(m_oldRect);
                 newRect.setLeft(m_oldRect.right()-dis);
                 newRect.setRight(m_oldRect.right());
//                 m_dPoint.setX(m_dPoint.x()+newRect.left()-m_oldRect.left());
                 if((m_dPoint.x()+newRect.left()-m_oldRect.left())<-245+187)
                 {
//                     dis=sqrt((-245-pf.x())*(-245-pf.x())+(event->pos().y()-pf.y())*(event->pos().y()-pf.y()) );
//                     dis=-(-245+187-m_dPoint.x()+m_oldRect.left())
                     newRect.setLeft(-245+187-m_dPoint.x()+m_oldRect.left());
                     newRect.setRight(m_oldRect.right());
                 }
                 m_dPoint.setX(m_dPoint.x()+newRect.left()-m_oldRect.left());
                 setRectSize(newRect,false);
                 m_RotateCenter=QPointF((m_oldRectPolygon.at(0).x()+m_oldRectPolygon.at(2).x())/2,(m_oldRectPolygon.at(0).y()+m_oldRectPolygon.at(2).y())/2);
//                 m_dPoint.setX(m_dPoint.x()+m_RotateCenter.x()-m_oldRect.center().x());
                 m_oldRect.moveCenter(m_RotateCenter);
                 setRectSize(m_oldRect);
//                 qreal temd=(sqrt(dis*dis-temy*temy)-m_oldRect.width());
//                 m_realPos.setX(m_oldRect.right()-sqrt(dis*dis-temy*temy));
//                 QPointF point=event->pos()-m_startPos;
//                 m_realPos.setX(event->pos().x());
                 scene()->update();//必须要用scene()->update()，不能用update();否则会出现重影
             }
         }
         else if(m_StateFlag == MOV_TOP_LINE)
         {
             //底边中点
             QPointF pf = QPointF((m_oldRectPolygon.at(2).x()+m_oldRectPolygon.at(3).x())/2,((m_oldRectPolygon.at(2).y()+m_oldRectPolygon.at(3).y())/2));
             //计算到底边中点的距离
             qreal dis = sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x()) +(event->pos().y()-pf.y())*(event->pos().y()-pf.y()));
             qreal dis2LT = sqrt((event->pos().x()-m_oldRectPolygon.at(0).x())*(event->pos().x()-m_oldRectPolygon.at(0).x()) +(event->pos().y()-m_oldRectPolygon.at(0).y())*(event->pos().y()-m_oldRectPolygon.at(0).y()));
             qreal dis2LB = sqrt((event->pos().x()-m_oldRectPolygon.at(3).x())*(event->pos().x()-m_oldRectPolygon.at(3).x()) +(event->pos().y()-m_oldRectPolygon.at(3).y())*(event->pos().y()-m_oldRectPolygon.at(3).y()));
             if(dis<16||dis2LT>dis2LB)
             {
                 return;
             }
             else
             {
                 QRectF newRect(m_oldRect);
                 newRect.setTop(m_oldRect.bottom()-dis);
                 newRect.setBottom(m_oldRect.bottom());
                 if((m_dPoint.y()+newRect.top()-m_oldRect.top())<-245+187)
                 {
//                     dis=sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x())+(-245-pf.y())*(-245-pf.y()) );
                     newRect.setTop(-245+187+m_oldRect.top()-m_dPoint.y());
                     newRect.setBottom(m_oldRect.bottom());
                 }
                 m_dPoint.setY(m_dPoint.y()+newRect.top()-m_oldRect.top());
                 setRectSize(newRect,false);
                 m_RotateCenter=QPointF((m_oldRectPolygon.at(0).x()+m_oldRectPolygon.at(2).x())/2,(m_oldRectPolygon.at(0).y()+m_oldRectPolygon.at(2).y())/2);
//                 m_dPoint.setY(m_dPoint.y()+m_RotateCenter.y()-m_oldRect.center().y());
                 m_oldRect.moveCenter(m_RotateCenter);
                 setRectSize(m_oldRect);
                 scene()->update();//必须要用scene()->update()，不能用update();否则会出现重影
             }
         }
         else if(m_StateFlag == MOV_RIGHT_LINE)
         {
             QPointF pf = QPointF((m_oldRectPolygon.at(0).x()+m_oldRectPolygon.at(3).x())/2,((m_oldRectPolygon.at(0).y()+m_oldRectPolygon.at(3).y())/2));
             //计算到左侧边中点的距离
             qreal dis = sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x()) +(event->pos().y()-pf.y())*(event->pos().y()-pf.y()));
             qreal dis2LT = sqrt((event->pos().x()-m_oldRectPolygon.at(0).x())*(event->pos().x()-m_oldRectPolygon.at(0).x()) +(event->pos().y()-m_oldRectPolygon.at(0).y())*(event->pos().y()-m_oldRectPolygon.at(0).y()));
             qreal dis2RT = sqrt((event->pos().x()-m_oldRectPolygon.at(1).x())*(event->pos().x()-m_oldRectPolygon.at(1).x()) +(event->pos().y()-m_oldRectPolygon.at(1).y())*(event->pos().y()-m_oldRectPolygon.at(1).y()));
            if(dis<16||dis2LT<dis2RT)
             {
                 return;
             }
             else
             {
                 QRectF newRect(m_oldRect);
                 newRect.setLeft(m_oldRect.left());
                 newRect.setRight(m_oldRect.left()+dis);
                 if((m_dPoint.x()+newRect.right()-m_oldRect.right())>490-m_oldRect.width()-58)
                 {
//                     dis=sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x())+(-245-pf.y())*(-245-pf.y()) );
                     newRect.setRight(490-m_oldRect.width()-58-m_dPoint.x()+m_oldRect.right());
                     newRect.setLeft(m_oldRect.left());
                 }
                 m_dPoint.setX(m_dPoint.x()+newRect.left()-m_oldRect.left());
                 setRectSize(newRect,false);
                 m_RotateCenter=QPointF((m_oldRectPolygon.at(0).x()+m_oldRectPolygon.at(2).x())/2,(m_oldRectPolygon.at(0).y()+m_oldRectPolygon.at(2).y())/2);
//                 m_dPoint.setX(m_dPoint.x()+m_RotateCenter.x()-m_oldRect.center().x());
                 m_oldRect.moveCenter(m_RotateCenter);
                 setRectSize(m_oldRect);
                 scene()->update();//必须要用scene()->update()，不能用update();否则会出现重影
             }
         }
         else if(m_StateFlag == MOV_BOTTOM_LINE)
         {
          //顶边中点
             QPointF pf = QPointF((m_oldRectPolygon.at(0).x()+m_oldRectPolygon.at(1).x())/2,((m_oldRectPolygon.at(0).y()+m_oldRectPolygon.at(1).y())/2));
             //计算到底边中点的距离
             qreal dis = sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x()) +(event->pos().y()-pf.y())*(event->pos().y()-pf.y()));
             qreal dis2LT = sqrt((event->pos().x()-m_oldRectPolygon.at(0).x())*(event->pos().x()-m_oldRectPolygon.at(0).x()) +(event->pos().y()-m_oldRectPolygon.at(0).y())*(event->pos().y()-m_oldRectPolygon.at(0).y()));
             qreal dis2LB = sqrt((event->pos().x()-m_oldRectPolygon.at(3).x())*(event->pos().x()-m_oldRectPolygon.at(3).x()) +(event->pos().y()-m_oldRectPolygon.at(3).y())*(event->pos().y()-m_oldRectPolygon.at(3).y()));
             if(dis<16||dis2LT<dis2LB)
             {
                 return;
             }
             else
             {
                 QRectF newRect(m_oldRect);
                 newRect.setTop(m_oldRect.top());
                 newRect.setBottom(m_oldRect.top()+dis);
                 if((m_dPoint.y()+newRect.bottom()-m_oldRect.bottom())>490-m_oldRect.height()-58)
                 {
//                     dis=sqrt((event->pos().x()-pf.x())*(event->pos().x()-pf.x())+(-245-pf.y())*(-245-pf.y()) );
                     newRect.setBottom(490-m_oldRect.height()-58-m_dPoint.y()+m_oldRect.bottom());
                     newRect.setTop(m_oldRect.top());
                 }
                 m_dPoint.setY(m_dPoint.y()+newRect.top()-m_oldRect.top());
                 setRectSize(newRect,false);
                 m_RotateCenter=QPointF((m_oldRectPolygon.at(0).x()+m_oldRectPolygon.at(2).x())/2,(m_oldRectPolygon.at(0).y()+m_oldRectPolygon.at(2).y())/2);
//                 m_dPoint.setY(m_dPoint.y()+m_RotateCenter.y()-m_oldRect.center().y());
                 m_oldRect.moveCenter(m_RotateCenter);
                 setRectSize(m_oldRect);
                 scene()->update();//必须要用scene()->update()，不能用update();否则会出现重影
          }
    }
}

void graphicsrectitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
    if(m_StateFlag == MOV_RECT)
    {
        m_StateFlag = DEFAULT_FLAG;
    }
    else
    {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

//bool graphicsrectitem::sceneEventFilter(QGraphicsItem *watched, QEvent *event)
//{
//    if (event->type()==QEvent::HoverEnter)
//        return true;
//}



void graphicsrectitem::SetRotate(qreal RotateAngle, QPointF ptCenter)
{
    m_bRotate = true;
    if(ptCenter.x()==-999 && ptCenter.y()==-999)
    {
        m_RotateCenter = QPointF(m_oldRect.x()+m_oldRect.width()/2,m_oldRect.y()+m_oldRect.height()/2);
    }
    else
    {
        m_RotateCenter = ptCenter;
    }
    m_RotateAngle = RotateAngle;
    this->update();
}

QPointF graphicsrectitem::getRotatePoint(QPointF ptCenter, QPointF ptIn, qreal angle)
{
    double dx = ptCenter.x();
    double dy = ptCenter.y();
    double x = ptIn.x();
    double y = ptIn.y();
    double xx,yy;
    xx = (x-dx)*cos(angle*M_PI/180)-(y-dy)*sin(angle*M_PI/180)+dx;
    yy = (x-dx)*sin(angle*M_PI/180)+(y-dy)*cos(angle*M_PI/180)+dy;
    return QPointF(xx,yy);
}

QList<QPointF> graphicsrectitem::getRotatePoints(QPointF ptCenter, QList<QPointF> ptIns, qreal angle)
{
    QList<QPointF> lstPt;
    for(int i = 0;i<ptIns.count();i++)
    {
        lstPt.append(getRotatePoint(ptCenter,ptIns.at(i),angle));
    }
    return lstPt;
}

QPolygonF graphicsrectitem::getRotatePolygonFromRect(QPointF ptCenter, QRectF rectIn, qreal angle)
{
    QVector<QPointF> vpt;
    QPointF pf = getRotatePoint(ptCenter,rectIn.topLeft(),angle);
    vpt.append(pf);
    pf = getRotatePoint(ptCenter,rectIn.topRight(),angle);
    vpt.append(pf);
    pf = getRotatePoint(ptCenter,rectIn.bottomRight(),angle);
    vpt.append(pf);
    pf = getRotatePoint(ptCenter,rectIn.bottomLeft(),angle);
    vpt.append(pf);
    pf = getRotatePoint(ptCenter,rectIn.topLeft(),angle);
    vpt.append(pf);
    return QPolygonF(vpt);
}

QRectF graphicsrectitem::getCrtPosRectToSceen()
{
    QRectF retRect = QRectF(m_oldRect.x()+pos().x(),m_oldRect.y()+pos().y(),m_oldRect.width(),m_oldRect.height());
    return retRect;
}

QRectF graphicsrectitem::getSmallRotateRect(QPointF ptA, QPointF ptB)
{
    QPointF pt = getSmallRotateRectCenter(ptA,ptB);
    return QRectF(pt.x()-10,pt.y()-10,20,20);
}

//void graphicsrectitem::setRealPos(QPointF p)
//{
//    m_realPos=p;
//}



QPointF graphicsrectitem::getSmallRotateRectCenter(QPointF ptA, QPointF ptB)
{
    QPointF ptCenter = QPointF((ptA.x()+ptB.x())/2,(ptA.y()+ptB.y())/2);//A,B点的中点C
   //中垂线方程式为 y=x*k + b;
    qreal x,y;//旋转图标矩形的中心
    if(abs(ptB.y()-ptA.y())<0.1)
    {
    if(ptA.x()<ptB.x())//矩形左上角在上方
    {
        x = ptCenter.x();
        y = ptCenter.y()-20;
    }
    else//矩形左上角在下方
             {
                 x = ptCenter.x();
                 y = ptCenter.y()+20;
             }
         }
    else if(ptB.y()>ptA.y())//顺时针旋转0-180
         {
             qreal k = (ptA.x()-ptB.x())/(ptB.y()-ptA.y());//中垂线斜率
             qreal b = (ptA.y()+ptB.y())/2-k*(ptA.x()+ptB.x())/2;
             //求AB线中垂线上离AB中点20个像素的点C的坐标
             x = 20*cos(atan(k))+ptCenter.x();
             y = k*x+b;
         }
         else if(ptB.y()<ptA.y())//顺时针旋转180-360
        {
             qreal k = (ptA.x()-ptB.x())/(ptB.y()-ptA.y());//中垂线斜率
            qreal b = (ptA.y()+ptB.y())/2-k*(ptA.x()+ptB.x())/2;
             //求AB线中垂线上离AB中点20个像素的点C的坐标
             x = -20*cos(atan(k))+ptCenter.x();
             y = k*x+b;
         }
         return QPointF(x,y);
}

