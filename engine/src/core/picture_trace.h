#ifndef PICTURE_TRACE_H
#define PICTURE_TRACE_H

#include <QMainWindow>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<QSlider>
#include<ildafile.h>
#include<QDoubleSpinBox>
#include<QPushButton>
#include<QButtonGroup>
#include"hardware.h"

namespace Ui {
class Picture_trace;
}

class Picture_trace : public SubWindow
{
    Q_OBJECT

public:
    explicit Picture_trace(QWidget *parent = nullptr);
    void datainit();
    void init_sliderAndspin(QSlider *slider, QDoubleSpinBox *spin,int min, int max, int step1, int step2, int basevalue);
    bool is_filer();
    int point_distance(cv::Point p1,cv::Point p2);
    void connectSliderAndSpin(QSlider * slider, QDoubleSpinBox * spin);
    void setbtn_style(QPushButton * button,QString buttonStyle);
    void setAllbtn_style();
    short ReverseUshort(short value);
    short zuobiaochulix(short zuobiao,short pianyi);
    short zuobiaochuliy(short zuobiao, short pianyi);
    QString getMyType();
    ~Picture_trace();
   private slots:
//    void btn_traced_slot();
//    void btn_reduced_slot();
//    void btn_src_slot();
    void btn_img_slot();
    void btn_blur_slot();
    void slider_rank_slot();
//    void btn_color_separa_slot();
//    void btn_highlight_separa_slot();
//    void btn_centerline_slot();
//    void btn_raster_slot();
    void btn_bigger_slot();
    void btn_smaller_slot();
    void btn_out_slot();
    void img_resize_slot();
    void filter_slot(int state);
    void ildafile(const QString file );
    void handleButtonClicked1(QAbstractButton *button);
    void handleButtonClicked2(QAbstractButton *button);


protected:
    virtual void resizeEvent(QResizeEvent *event) override;

signals:

private:
    Ui::Picture_trace *ui;
    cv::Mat cur_img;
    QString save_dir="./trace/";
    QString now_dir;//展示的图片 定时事件
    int reduced=0;
    //点击三个按钮分别呈现 三种情况，
//     1.原图
//     2.简化图
//     3.示踪图
    QString img_src;
    QString img_reduced;
    QString img_traced;
    QString img_blur;
//    QButtonGroup *buttonGroup1;
//    QButtonGroup *buttonGroup2;
    //分离等级值
    bool btn_src=true;
    bool btn_reduced=false;
    bool btn_traced=false;
    bool btn_color_separation=true;
    bool btn_highlight_separation=false;
    bool btn_centerline=false;
    bool btn_raster=false;
    bool btn_blur=false;
    //点距离值
    double distance = 0;
    QButtonGroup *buttonGroup1 = new QButtonGroup(this);
    QButtonGroup *buttonGroup2 = new QButtonGroup(this);
    QString m_type;
};

#endif // PICTURE_TRACE_H
