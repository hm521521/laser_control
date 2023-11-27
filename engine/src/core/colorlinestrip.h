#ifndef COLORLINESTRIP_H
#define COLORLINESTRIP_H

#include <QOpenGLShaderProgram>
#include <QQuickItem>
#include <qopenglfunctions.h>
#include <qquickframebufferobject.h>
#include <QQuickWindow>
#include <QRunnable>
#include <QOpenGLExtraFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFramebufferObjectFormat>


//! 线条的渲染器.
/*!
  在这里面进行opengl到FBO的绘制
*/
class ColorLineStripRenderer : public QQuickFramebufferObject::Renderer
{
public:
    ColorLineStripRenderer();

    void render() override;
    void synchronize(QQuickFramebufferObject *item) override;

    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override ;
private:
    QOpenGLFunctions m_func;
    QOpenGLShaderProgram m_program;
    QVector<qreal> m_points;
    qreal m_width;
    qreal m_height;
    qreal m_scale;
    qreal m_wscale, m_hscale;
    bool m_needUpdate;
    qreal m_offsetX;
    qreal m_offsetY;
    bool m_linesOnly;
};
//! 渲染线条到FBO，然后作为QML_ELEMENT显示到qml
/*!
    除了线条还可以绘制各个点，点的部分颜色控制未做
*/
class ColorLineStrip : public QQuickFramebufferObject
{
    Q_OBJECT
    QML_ELEMENT
    /*! 需要绘制的点数据，一个点包括(x,y,r,g,b,a)六个浮点数，每个值都是0~1*/
    Q_PROPERTY(QVector<qreal> pointsData READ pointsData WRITE setPointsData NOTIFY pointsDataChanged)
    /*! 缩放控制 */
    Q_PROPERTY(qreal scale READ scale WRITE setScale NOTIFY scaleChanged)
    /*! X偏移控制 */
    Q_PROPERTY(qreal offsetX READ offsetX WRITE setOffsetX NOTIFY offsetXChanged)
    /*! Y偏移控制 */
    Q_PROPERTY(qreal offsetY READ offsetY WRITE setOffsetY NOTIFY offsetYChanged)
    /*! 是否只显示线条 */
    Q_PROPERTY(bool linesOnly READ linesOnly WRITE setLinesOnly NOTIFY linesOnlyChanged)
public:
    ColorLineStrip(QQuickItem*p=nullptr);
    Renderer *createRenderer() const;
    QVector<qreal> pointsData(){return m_points;}
    void setPointsData(const QVector<qreal> vec){
        m_points=vec;
        update(); //=>synchronize() of renderer
        emit pointsDataChanged();
    }
    qreal scale(){return m_scale;}
    void setScale(const qreal scale){
        m_scale=scale;
        update(); //=>synchronize() of renderer
        emit scaleChanged();
    }
    qreal offsetX(){return m_offsetX;}
    void setOffsetX(const qreal x){
        m_offsetX=x;
        update(); //=>synchronize() of renderer
        emit offsetXChanged();
    }
    qreal offsetY(){return m_offsetY;}
    void setOffsetY(const qreal y){
        m_offsetY=y;
        update(); //=>synchronize() of renderer
        emit offsetYChanged();
    }
    bool linesOnly(){return m_linesOnly;}
    void setLinesOnly(const bool y){
        m_linesOnly=y;
        update(); //=>synchronize() of renderer
        emit linesOnlyChanged();
    }
signals:
    void pointsDataChanged();
    void scaleChanged();
    void offsetXChanged();
    void offsetYChanged();
    void linesOnlyChanged();
private:
    QVector<qreal> m_points;
    qreal m_scale=1;
    qreal m_offsetX=0;
    qreal m_offsetY=0;
    bool m_linesOnly = true;
};


#endif // COLORLINESTRIP_H
