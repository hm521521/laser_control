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
    void update_show(CJSection* section,int i);
    QVector<output_panel*> m_output_panels;
private slots:
    void on_btn_open_clicked();
    void on_btn_process_clicked();
    void on_btn_play_clicked();
    void on_thresh_checkBox_stateChanged(int arg1);
    void on_thread_update();
private:
    Ui::publicize *ui;
    QString img_src;
    QString save_dir="./publicize/";
    QString m_type="publicize";
    int point_distance(cv::Point p1, cv::Point p2);
    double distance = 3;
    cv::Mat thresh_dst;//保存结果的图片
    cv::Mat src_dst;
    std::vector<std::vector<cv::Point>> contours;//保存轮廓的向量
    int image_num=6;
    int thresh=127;
//    CJImage m_image;
//    CJSection m_section;
    single_scene *m_scene;//一组动画的所有信息
    CJSection m_section;
    int laser_row_num=1;
    int laser_column_num=2;

    QVector<CJPoint> position;
    void addeffect(int idx,int start_idx,single_scene *scene);
    void display();
    void SetSliderAndSpinEnable(QSlider *slider,QSpinBox *spin,bool flag);
    QRect gridrect;
    QThread thread;//处理显示和数据下发的子线程
    int m_frame_index=0;
signals:
    void operate();
    void playpause();
};

class publicize_worker:public QObject
{
    Q_OBJECT
public:
    explicit publicize_worker(QObject *parent=nullptr);
    ~publicize_worker();
public slots:
    void run();
    void pause();
signals:
    void play();
    void stop();
private:
    bool m_start;
    bool m_pause;

};

#endif // PUBLICIZE_H
