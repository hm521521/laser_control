#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H
#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QRect>
#include <QPainter>
#include <QPolygon>
#include <QList>

enum STATE_FLAG{
    DEFAULT_FLAG=0,
    MOV_LEFT_LINE,//标记当前为用户按下矩形的左边界区域
    MOV_TOP_LINE,//标记当前为用户按下矩形的上边界区域
    MOV_RIGHT_LINE,//标记当前为用户按下矩形的右边界区域
    MOV_BOTTOM_LINE,//标记当前为用户按下矩形的下边界区域
    MOV_RIGHTBOTTOM_RECT,//标记当前为用户按下矩形的右下角
    MOV_RECT,//标记当前为鼠标拖动图片移动状态
    ROTATE//标记当前为旋转状态
};



class graphicsrectitem:public QGraphicsItem
{
//    Q_OBJECT
public:
    graphicsrectitem(QGraphicsView *parent=nullptr);
    QRectF  boundingRect() const;
    ~graphicsrectitem();
    void setRectSize(QRectF mrect,bool bResetRotateCenter = true);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void checkOutBound(QRectF mrect);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event);
    void SetRotate(qreal RotateAngle,QPointF ptCenter=QPointF(-999,-999));
    QPointF getRotatePoint(QPointF ptCenter, QPointF ptIn, qreal angle);//获取旋转后的点
    QList<QPointF> getRotatePoints(QPointF ptCenter,QList<QPointF> ptIns,qreal angle);//获取多个旋转后的点
    QPolygonF getRotatePolygonFromRect(QPointF ptCenter,QRectF rectIn,qreal angle);//将矩形旋转之后返回多边形
    QRectF getCrtPosRectToSceen();
    QRectF m_SmallRotateRect;//矩形顶部用来表示旋转的标记的矩形
    QPolygonF m_SmallRotatePolygon;//矩形顶部用来表示旋转的标记的矩形旋转后形成的多边形
    QPointF getSmallRotateRectCenter(QPointF ptA,QPointF ptB);//获取旋转时候矩形正上方的旋转标记矩形
    QRectF  getSmallRotateRect(QPointF ptA,QPointF ptB);
    bool    m_bRotate;
    qreal   m_RotateAngle;
    QPointF m_RotateCenter;
    QPointF getdPoint();
    void setdPoint(QPointF dp);
    STATE_FLAG getStageFlag();

//    void setRealPos(QPointF p);


private:
    QRectF  m_oldRect;
    QPolygonF m_oldRectPolygon;
    QRectF  m_RotateAreaRect;
    bool    m_bResize;
    QPolygonF m_insicedPolygon;
    QRectF  m_insicedRectf;
    QPolygonF m_leftPolygon;
    QRectF  m_leftRectf;
    QPolygonF m_topPolygon;
    QRectF  m_topRectf;
    QPolygonF m_rightPolygon;
    QRectF  m_rightRectf;
    QPolygonF m_bottomPolygon;
    QRectF  m_bottomRectf;
    QPolygonF m_rbPolygon;
    QRectF  m_rbRectf;
    QPointF m_startPos;
    STATE_FLAG m_StateFlag;
    QPointF *pPointFofSmallRotateRect;
    QPointF m_dPoint;
//    QPointF m_realPos;

};



#endif // GRAPHICSRECTITEM_H
