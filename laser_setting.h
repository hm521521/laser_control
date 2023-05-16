#ifndef LASER_SETTING_H
#define LASER_SETTING_H
//#include "mainwindow1.h"
#include "hardware.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "graphicsrectitem.h"


namespace Ui {
class laser_setting;
}
enum POS_FLAG{
    POS_DEFAULT=0,
    POS_MOV_RECT,
    POS_MOV_XP,
    POS_MOV_YP
};
enum COLOR_TYPE{
    TTL,
    LINEAR_RESPONSE,
    LOG_RESPONSE
};
class MyGraphicsView:public QGraphicsView
{
  Q_OBJECT;
protected:
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
public:
    MyGraphicsView(QWidget *parent=0);
    graphicsrectitem* getItem();
signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);

private:
    QGraphicsScene *scene_size;
    void iniGraphicsSystem();
    graphicsrectitem *m_item;
    static const int ItemId=1;
protected:
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void flagchanged();


};


class laser_setting_data: public QObject
{
    Q_OBJECT
public:
    laser_setting_data(QWidget *parent=0);
    ~laser_setting_data();
    void setColorMode(QString str);
    void setColorType(COLOR_TYPE ct);
    void setSingleU(int a,int b);
    void setMultiU(int redMin,int redMax,int greenMin,int greenMax,int blueMin,int blueMax);
private:
    QString m_colorMode;
    COLOR_TYPE m_colorType;
    int m_redMinU;
    int m_redMaxU;
    int m_greenMinU;
    int m_greenMaxU;
    int m_blueMinU;
    int m_blueMaxU;
    int m_singleMinU;
    int m_singleMaxU;

};

class laser_setting : public SubWindow
{
    Q_OBJECT

public:
    explicit laser_setting(QWidget *parent = nullptr);
    ~laser_setting();
     QString getMyType();
private:
    Ui::laser_setting *ui;
//    MainWindow1 *m_parent;
    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;
    void xsizechange(int position);
    void ysizechange(int position);
    void postionchange(int position,POS_FLAG pf);
    POS_FLAG m_posFlag;
    QPointF m_lastpos;
    void checkComboBox(QString str);
    QString m_type;
protected:
    Configuration* m_config;
//    bool eventFilter(QObject *watched,QEvent *event);
//    void mouseMove();
//    void showResize();
//    void resizeEvent(QResizeEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void dragEvent(QDragMoveEvent *event);


private slots:
    void refresh();
    void on_xsize_Slider_sliderMoved(int position);
    void on_xspinBox_valueChanged(int arg1);
    void onflagchanged();

    void on_ysize_Slider_sliderMoved(int position);
    void on_yspinBox_valueChanged(int arg1);
    void on_xposition_Slider_sliderMoved(int position);
    void on_xp_spinBox_valueChanged(int arg1);
    void on_yposition_Slider_sliderMoved(int position);
    void on_yp_spinBox_valueChanged(int arg1);
    void on_comboBox_activated(const QString &arg1);
    void on_TTL_pushButton_clicked();
    void on_linearRes_pushButton_clicked();
    void on_logRes_pushButton_clicked();
    void on_singleMinU_horizontalSlider_sliderMoved(int position);
    void on_singleMinU_spinBox_valueChanged(int arg1);
    void on_singleMaxU_horizontalSlider_sliderMoved(int position);
    void on_singleMaxU_spinBox_valueChanged(int arg1);
    void on_redMinU_horizontalSlider_sliderMoved(int position);
    void on_redMinU_spinBox_valueChanged(int arg1);
    void on_redMaxU_horizontalSlider_sliderMoved(int position);
    void on_redMaxU_spinBox_valueChanged(int arg1);
    void on_greenMinU_horizontalSlider_sliderMoved(int position);
    void on_greenMinU_spinBox_valueChanged(int arg1);
    void on_greenMaxU_horizontalSlider_sliderMoved(int position);
    void on_greenMaxU_spinBox_valueChanged(int arg1);
    void on_blueMinU_horizontalSlider_sliderMoved(int position);
    void on_blueMinU_spinBox_valueChanged(int arg1);
    void on_blueMaxU_horizontalSlider_sliderMoved(int position);
    void on_blueMaxU_spinBox_valueChanged(int arg1);
    void refresh_laser_device(QVector<laser_device*> laser_device);
    void on_OpenConfigButton_clicked();
    void on_actionopensettins_triggered();
    void on_saveConfigButton_clicked();
    void on_actionsavesettings_triggered();
    void on_saveAsConfigButton_clicked();
};




#endif // LASER_SETTING_H
