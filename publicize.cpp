#include "publicize.h"
#include "ui_publicize.h"
#include<QFileDialog>
using namespace cv;
using namespace std;
publicize::publicize(QWidget *parent) :
    SubWindow(),
    ui(new Ui::publicize)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->public_panel_1->setScene(scene);
    QGraphicsScene *scene1=new QGraphicsScene(this);
    ui->public_panel_2->setScene(scene1);
}

publicize::~publicize()
{
    delete ui;
}

void publicize::datainit()
{
    ui->public_panel_1->scene()->clear();
    ui->public_panel_2->scene()->clear();
//    this->reduced=0;
//    img_reduced.remove(0,img_reduced.length());
//    img_traced.remove(0,img_reduced.length());
//    ui->slider_rank->setMinimum(0);
//    ui->slider_rank->setMaximum(255);
//    ui->slider_rank->setValue(128);
//    ui->slider_size->setMinimum(0);
//    ui->slider_size->setMaximum(200);
//    ui->slider_size->setValue(100);
    init_sliderAndspin(ui->distance_horizontalSlider, ui->distance_SpinBox, 0, 50, 1, 0.1, 0);
//    ui->check_space->setChecked(true);
    setAllbtn_style();
}

void publicize::init_sliderAndspin(QSlider *slider, QDoubleSpinBox *spin, int min, int max, int step1, int step2, int basevalue)
{
    slider->setMinimum(min);
    slider->setMaximum(max);
    slider->setSingleStep(step1);
    spin->setMinimum(min);
    spin->setMaximum(max);
    spin->setSingleStep(step2);
    slider->setValue(basevalue);
    spin->setValue(basevalue);
}

void publicize::setAllbtn_style()
{
    QString buttonStyle ="QPushButton:focus { outline: none; }";
    setbtn_style(ui->btn_open,buttonStyle);
    setbtn_style(ui->btn_output,buttonStyle);
    setbtn_style(ui->btn_play,buttonStyle);
    setbtn_style(ui->btn_process,buttonStyle);
}

void publicize::setbtn_style(QPushButton *button, QString buttonStyle)
{
    button->setCheckable(true);
    button->setStyleSheet(buttonStyle);  // 应用样式表
}

QString publicize::getMyType()
{
    return m_type;
}


void publicize::on_btn_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "",tr("Image Files (*.png *.jpg *.bmp)"));
    if(fileName.isEmpty())
        return ;
    if(fileName!=img_src)//判断是否更换图片了
    {
        datainit();//各项数据初始化函数
    }
    Mat img=imread(fileName.toStdString(),0);
    Mat dst;
    auto srcmaxsize=max(img.size().width,img.size().height);
    auto graphicminsize=min(ui->public_panel_1->width(),ui->public_panel_1->height());
    double scale=srcmaxsize/graphicminsize;
    cv::resize(img,dst,Size(img.size().width/scale,img.size().height/scale),0,0);//调整大小
//    QFile file(fileName);
//    QFileInfo fileinfo(file);
//    qDebug()<<fileinfo.baseName();
//    QString save=save_dir+fileinfo.baseName()+"_resized.bmp";
//    imwrite(save.toStdString(),dst);
//    img_src=save;
    Mat dst1;
    adaptiveThreshold(dst,dst1,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,5,5);
    imshow("gaussian",dst1);
}

