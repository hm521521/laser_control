#ifndef PUBLICIZE_H
#define PUBLICIZE_H


#include "hardware.h"
#include<QDoubleSpinBox>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

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
    void init_sliderAndspin(QSlider *slider, QDoubleSpinBox *spin,int min, int max, int step1, int step2, int basevalue);
//    void handleButtonClicked1(QAbstractButton *button);
    void setAllbtn_style();
    void setbtn_style(QPushButton * button,QString buttonStyle);
    QString getMyType();
private slots:
    void on_btn_open_clicked();

private:
    Ui::publicize *ui;
    QString img_src;
    QString save_dir="./publicize/";
    QString m_type;
};

#endif // PUBLICIZE_H
