#ifndef PUBLICIZE_H
#define PUBLICIZE_H


#include "hardware.h"
#include<QDoubleSpinBox>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include"cjimage.h"
#include"output_panel.h"
#include"scene_pool.h"
namespace Ui {
class publicize;
}

class publicize : public SubWindow
{
    Q_OBJECT

public:
    explicit publicize(QWidget *parent = nullptr);
    ~publicize();
    void datainit();
    void init_sliderAndspin(QSlider *slider, QSpinBox *spin,int min, int max, int step1, int step2, int basevalue);
//    void handleButtonClicked1(QAbstractButton *button);
    void setAllbtn_style();
    void setbtn_style(QPushButton * button,QString buttonStyle);
    QString getMyType();
    void connectSliderAndSpin(QSlider * slider, QSpinBox * spin);

private slots:
    void on_btn_open_clicked();
    void on_btn_process_clicked();
    void on_btn_play_clicked();

private:
    Ui::publicize *ui;
    QString img_src;
    QString save_dir="./publicize/";
    QString m_type="publicize";
    int point_distance(cv::Point p1, cv::Point p2);
    double distance = 10;
    cv::Mat thresh_dst;
    cv::Mat src_dst;
    std::vector<std::vector<cv::Point>> contours;
    int image_num=4;
    int thresh=127;
//    CJImage m_image;
//    CJSection m_section;
    single_scene *m_scene;//一组动画的所有信息
    int laser_row_num=1;
    int laser_column_num=2;
    QVector<output_panel*> m_output_panels;
    QVector<CJPoint> position;
    void addeffect();

//    QRect scenerect;
};

#endif // PUBLICIZE_H
