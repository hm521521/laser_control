#include "picture_trace.h"
#include "ui_picture_trace.h"
#include<math.h>
#include<qmath.h>
#include<QMessageBox>
#include<QFileDialog>
#include<QTimer>
#include<QDebug>
#include<fstream>
using namespace cv;
using namespace std;
Picture_trace::Picture_trace(QWidget *parent) :
    SubWindow(),
    ui(new Ui::Picture_trace),
    m_type("pic_trace")
{
    ui->setupUi(this);
    setWindowTitle("图片示踪剂");
     QGraphicsScene *scene = new QGraphicsScene(this);
     ui->graphicsView->setScene(scene);

     buttonGroup1->addButton(ui->btn_reduced);
     buttonGroup1->addButton(ui->btn_src);
     buttonGroup1->addButton(ui->btn_traced);
     buttonGroup2->addButton(ui->btn_color_separa);
     buttonGroup2->addButton(ui->btn_centerline);
     buttonGroup2->addButton(ui->btn_highlight_separa);
     buttonGroup2->addButton(ui->btn_raster);
     buttonGroup2->addButton(ui->btn_none);
     buttonGroup1->setExclusive(true);
     buttonGroup2->setExclusive(true);
     QTimer* timer = new QTimer(this);
     timer->start(10);//开启定时器，执行周期为1秒针
     datainit();//232312312312

     //选择图片
     connect(ui->btn_img,SIGNAL(clicked()),this,SLOT(btn_img_slot()));
    //分别显示三种不同图片 1.原图 2.简化图 3.示踪图
//    connect(ui->btn_src,SIGNAL(clicked()),this,SLOT(btn_src_slot()));
//    connect(ui->btn_reduced,SIGNAL(clicked()),this,SLOT(btn_reduced_slot()));
//    connect(ui->btn_traced,SIGNAL(clicked()),this,SLOT(btn_traced_slot()));
    //模糊处理
    connect(ui->btn_blur,SIGNAL(clicked()),this,SLOT(btn_blur_slot()));
    //显示当前图片
    connect(timer,&QTimer::timeout,this,[=](){
        scene->clear();
        if(ui->btn_src->isChecked())
            now_dir=img_src;
        else if(ui->btn_reduced->isChecked())
            now_dir=img_reduced;
        else
            now_dir=img_traced;
        scene->addPixmap(QPixmap(now_dir));
        ui->graphicsView->show();
    });
    connect(ui->slider_rank,&QSlider::valueChanged,ui->label_rank,[=](){
        QString k="分离等级："+QString::number(ui->slider_rank->value());
        ui->label_rank->clear();
        ui->label_rank->setText(k);
    });
    connect(buttonGroup1, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(handleButtonClicked1(QAbstractButton *)));
    connect(buttonGroup2, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(handleButtonClicked2(QAbstractButton *)));
    // 连接
    connectSliderAndSpin(ui->distance_slider,ui->distance_SpinBox);
    connectSliderAndSpin(ui->offset_slider,ui->offset_SpinBox);
    connect(ui->slider_rank,SIGNAL(sliderReleased()),this,SLOT(slider_rank_slot()));
    //调整图片大小
    connect(ui->btn_out,SIGNAL(clicked()),this,SLOT(btn_out_slot()));
    connect(ui->btn_bigger,SIGNAL(clicked()),this,SLOT(btn_bigger_slot()));
    connect(ui->btn_smaller,SIGNAL(clicked()),this,SLOT(btn_smaller_slot()));
    connect(ui->slider_size,SIGNAL(valueChanged(int)),this,SLOT(img_resize_slot()));
    //connect()
     connect(ui->check_space,SIGNAL(stateChanged(int)), this, SLOT(filter_slot(int))) ;
}


void Picture_trace::datainit()
{
    ui->graphicsView->scene()->clear();
    this->reduced=0;
    img_reduced.remove(0,img_reduced.length());
    img_traced.remove(0,img_reduced.length());
    ui->slider_rank->setMinimum(0);
    ui->slider_rank->setMaximum(255);
    ui->slider_rank->setValue(128);
    ui->slider_size->setMinimum(0);
    ui->slider_size->setMaximum(200);
    ui->slider_size->setValue(100);
    init_sliderAndspin(ui->distance_slider, ui->distance_SpinBox, 0, 50, 1, 0.1, 0);
    init_sliderAndspin(ui->offset_slider, ui->offset_SpinBox, 0, 50, 1, 0.1, 0);
    ui->check_space->setChecked(true);
    setAllbtn_style();

}

void Picture_trace::init_sliderAndspin(QSlider *slider, QDoubleSpinBox *spin, int min, int max, int step1, int step2, int basevalue)
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

int Picture_trace::point_distance(cv::Point p1, cv::Point p2)
{   float ans=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    return qFloor(ans);
}

void Picture_trace::connectSliderAndSpin(QSlider *slider, QDoubleSpinBox *spin)
{

    connect(slider, &QSlider::valueChanged,
                  spin, &QDoubleSpinBox::setValue);
        connect(spin, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
                slider, &QSlider::setValue);
        connect(spin,static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[=](){
            this->distance = spin->value();
        });
}

Picture_trace::~Picture_trace()
{
    delete ui;
}

void Picture_trace::btn_img_slot()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "",tr("Image Files (*.png *.jpg *.bmp)"));
    if(fileName.isEmpty())
        return ;
    if(fileName!=img_src)//判断是否更换图片了
    {
        datainit();//各项数据初始化函数

    }
    Mat img=imread(fileName.toStdString());
    Mat dst;
    cv::resize(img,dst,Size(ui->graphicsView->width(),ui->graphicsView->height()),0,0);
    QFile file(fileName);
    QFileInfo fileinfo(file);
    qDebug()<<fileinfo.baseName();
    QString save=save_dir+fileinfo.baseName()+"_resized.bmp";
    imwrite(save.toStdString(),dst);

//    now_dir=save;
    img_src=save;
    img_reduced=save;

//       scene->addPixmap(QPixmap(fileName));
//       //借助graphicsView（QGraphicsView类）控件显示容器的内容
//       ui->graphicsView->setScene(scene);
//       //开始显示
//       ui->graphicsView->show();
    //       cur_img=imread(fileName.toStdString());
}

void Picture_trace::btn_blur_slot()
{
//    if(!now_dir.isEmpty()){
//        btn_blur=!btn_blur;
//        if(btn_blur){
//            Mat src;
//            Mat blur_img;
//            src=imread(now_dir.toStdString());
//            GaussianBlur(src,blur_img,Size(5,5),15);
//            QFile file(now_dir);
//            QFileInfo fileinfo(file);
//            qDebug()<<fileinfo.baseName();
//            QString save=save_dir+fileinfo.baseName()+"_blur.bmp";
//            if(!imwrite(save.toStdString(),blur_img))
//                qDebug()<<"保存失败";
//            now_dir=save;
//        }
//        else{
//           //删除
//        }
//    }
//    btn_blur=!btn_blur;

    if(ui->btn_blur->isChecked()){
    if(ui->btn_highlight_separa->isChecked()){
        Mat img;
        img=imread(img_src.toStdString());
        Mat dst;
        Mat imgblur;
        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);
        threshold(gray,dst,ui->slider_rank->value(),255,THRESH_BINARY);
        GaussianBlur(dst,imgblur,Size(5,5),15);
        QFile file(img_src);
        QFileInfo fileinfo(file);
        qDebug()<<fileinfo.baseName();
        QString save=save_dir+fileinfo.baseName()+"_highlightSepara_blur.bmp";
        imwrite(save.toStdString(),dst);
        img_reduced=save;
    }
    else{

        Mat img;
        img=imread(img_src.toStdString());
        Mat imgblur;
        GaussianBlur(img,imgblur,Size(5,5),15);
        QFile file(img_src);
        QFileInfo fileinfo(file);
        qDebug()<<fileinfo.baseName();
        QString save=save_dir+fileinfo.baseName()+"_blur.bmp";
        imwrite(save.toStdString(),imgblur);
        img_blur=save;
        img_reduced=save;

    }
    }
    if(img_reduced.isEmpty()){

    }
}

void Picture_trace::slider_rank_slot()
{
    if(btn_color_separation){

    }
    if(ui->btn_highlight_separa->isChecked()){
        if(ui->btn_blur->isChecked()){
             Mat img;
            img=imread(img_blur.toStdString());
            Mat dst;
            Mat gray;
            cvtColor(img, gray, COLOR_BGR2GRAY);
            threshold(gray,dst,ui->slider_rank->value(),255,THRESH_BINARY);

            QFile file(img_blur);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_highlightSepara.bmp";
            imwrite(save.toStdString(),dst);
            img_reduced=save;
        }
        else{
            Mat img;
            img=imread(img_src.toStdString());
            Mat dst;
            Mat gray;
            cvtColor(img, gray, COLOR_BGR2GRAY);
            threshold(gray,dst,ui->slider_rank->value(),255,THRESH_BINARY);
            QFile file(img_src);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_highlightSepara.bmp";
            imwrite(save.toStdString(),dst);
            img_reduced=save;
        }
    }
}


void Picture_trace::btn_bigger_slot()
{
    int k=ui->slider_size->value()/25;
    if(k<8){
        ui->slider_size->setValue((k+1)*25);
    }


}

void Picture_trace::btn_smaller_slot()
{
     int k=ui->slider_size->value()/25;
     if(k>1)
         ui->slider_size->setValue((k-1)*25);
     else
         ui->slider_size->setValue(0);
}

void Picture_trace::btn_out_slot()
{
    QString file="./trace/position.txt";
    if(!img_traced.isEmpty())
        ildafile(file);

}

void Picture_trace::img_resize_slot()
{
    this->resize(this->width(),this->height());
}

void Picture_trace::filter_slot(int state)
{
    if(state==0){
        ui->distance_slider->setEnabled(false);
         ui->distance_SpinBox->setEnabled(false);
          ui->offset_slider->setEnabled(false);
           ui->offset_SpinBox->setEnabled(false);
           distance=0;

    }
    else if(state==2){
        ui->distance_slider->setEnabled(true);
         ui->distance_SpinBox->setEnabled(true);
          ui->offset_slider->setEnabled(true);
           ui->offset_SpinBox->setEnabled(true);
           distance=ui->distance_SpinBox->value();
    }
}

void Picture_trace::ildafile(const QString file)
{
    //输入输出流
    ifstream ifs;
    ofstream ild;
    ILDAFILEHEADER ild_fileheader;

    short xoff = ui->graphicsView->width()/2;
    short yoff = ui->graphicsView->height()/2;
    ifs.open(file.toStdString(), ios::in);
    ild.open("./trace/EFF001.ild",ios::out|ios::binary);
    //写入ild文件头
    ild.write((char *)&ild_fileheader,sizeof(ILDAFILEHEADER));
    while(!ifs.eof()){
        short _x=0;
        short _y=0;
        short _status=0;
        ifs>>_x>>_y>>_status;
        ILDAINFODATA ildaIndata;
        //对原始坐标进行处理，xoff和yoff分别为图像尺寸x方向和y方向的一半
        ildaIndata.X = ReverseUshort(zuobiaochulix(_x,xoff));
        ildaIndata.Y = ReverseUshort(zuobiaochuliy(_y,yoff));
        if(_status){
            ildaIndata.Status = 0x80;
            ildaIndata.green = 0;
        }
        else{
            ildaIndata.Status = 0x40;
            ildaIndata.green = 0;
        }
        //写入ild数据部分
//        qDebug()<<ildaIndata.X <<" "<<ildaIndata.Y<<endl;
        ild.write((char*)&ildaIndata, sizeof(ILDAINFODATA));
    }
    ifs.close();
    ILDAFILEHEADER ildafh;
    ildafh.a = 0;
    ildafh.b = 0;
    ildafh.FoCPalette_Number = 0x0100;
    ild.write((char*)&ildafh, sizeof(ILDAFILEHEADER));
    ild.close();


}

void Picture_trace::handleButtonClicked1(QAbstractButton *button)
{

    if(button->text()=="src"){

    }
    else if(button->text()=="reduced"){

    }
    else if(button->text()=="Traced"){
        if(img_reduced.isEmpty())
               return ;
        if(!btn_traced){
            btn_traced=!btn_traced;
            btn_src=false;
            btn_reduced=false;
        }
        Mat img, traced_img;
        Mat gray,gray_blur;
        img=imread(img_reduced.toStdString());
        qDebug()<<img_reduced;
    //    traced_img=img;
        cvtColor(img, traced_img, COLOR_BGR2GRAY);
    //    GaussianBlur(gray, gray_blur, Size(3, 3), 3, 3);
    //    threshold(gray, traced_img, 50, 255, THRESH_BINARY);
    //    now_dir=img_traced;
        vector<vector<cv::Point>> contours;
        vector<Vec4i> hierarchy;
    //    vector<vector<float>>pos;
        findContours(traced_img, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

        int sum=0;
        Mat kongbai = Mat::zeros(Size(traced_img.cols,traced_img.rows),CV_8UC3);
        ofstream postion;
        postion.open("./trace/position.txt",ios::out);
    //    postion<<"X  Y   status"<<endl;
        for(uint i=0;i<contours.size();i++){
            cv::Point pre=contours[i][0];
            cv::circle(kongbai,pre,1,cv::Scalar(0, 255, 0), 2);
    //        postion<<"第"<<i<<"个轮廓"<<endl;
            for(uint j=1;j<contours[i].size();j++){
                cv::Point now=contours[i][j];
                if(point_distance(pre,now)>distance||j+1==contours[i].size()){
                    if(j+1==contours[i].size()){
                        postion<<pre.x<<" "<<pre.y<<" "<<0<<endl;
                        postion<<now.x<<" "<<now.y<<" "<<1<<endl;
                    }
                    else{
                        postion<<pre.x<<" "<<pre.y<<" "<<0<<endl;
                    }
                    cv::line(kongbai,pre,now,cv::Scalar(0, 255, 0), 1);
                    cv::circle(kongbai,now,1,cv::Scalar(0,255, 0), 2);
                    pre=now;
                    sum++;
                }

            }
        }
        postion.close();

    //    if(sum>2000)
    //        QMessageBox::warning(this,"警告","图像过于复杂");
        QFile file(img_src);
        QFileInfo fileinfo(file);
        qDebug()<<fileinfo.baseName();
        QString save=save_dir+fileinfo.baseName()+"_traced.bmp";
        imwrite(save.toStdString(),kongbai);
        img_traced=save;

        qDebug()<<"调用";
        qDebug()<<sum;
    }
}

void Picture_trace::handleButtonClicked2(QAbstractButton *button)
{
//    enum buttontext {颜色分离,高光分离, 中心线,Raster,取消设置};
    QString buttonText = button->text();

    if(buttonText=="颜色分离"){
            img_reduced=img_src;
    }
    else if(buttonText=="高光分离"){
        if(ui->btn_blur->isChecked()){
             Mat img;
            img=imread(img_blur.toStdString());
            Mat dst;
            Mat gray;
            cvtColor(img, gray, COLOR_BGR2GRAY);
            threshold(gray,dst,ui->slider_rank->value(),255,THRESH_BINARY);

            QFile file(img_blur);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_highlightSepara.bmp";
            imwrite(save.toStdString(),dst);
            img_reduced=save;
        }
        else{
            Mat img;
            img=imread(img_src.toStdString());
            Mat dst;
            Mat gray;
            cvtColor(img, gray, COLOR_BGR2GRAY);
            threshold(gray,dst,ui->slider_rank->value(),255,THRESH_BINARY);
            QFile file(img_src);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_highlightSepara.bmp";
            imwrite(save.toStdString(),dst);
            img_reduced=save;
          }
    }
    else if(buttonText=="Raster"){
        img_reduced=img_src;
    }
    else if(buttonText=="中心线"){
        img_reduced=img_src;
    }
    else {
        img_reduced=img_src;
    }
    qDebug() << "Button clicked:" << buttonText;
}

void Picture_trace::setbtn_style(QPushButton *button, QString buttonStyle)
{
    button->setCheckable(true);
    button->setStyleSheet(buttonStyle);  // 应用样式表
}

void Picture_trace::setAllbtn_style()
{
//    QString buttonStyle =
//            "QPushButton:checked {"
//                "background-color: red;"

//            "}";
    QString buttonStyle ="QPushButton:focus { outline: none; }";
    setbtn_style(ui->btn_color_separa,buttonStyle);
    setbtn_style(ui->btn_centerline,buttonStyle);
    setbtn_style(ui->btn_highlight_separa,buttonStyle);
    setbtn_style(ui->btn_raster,buttonStyle);
    setbtn_style(ui->btn_blur,buttonStyle);
    setbtn_style(ui->btn_src,buttonStyle);
    setbtn_style(ui->btn_reduced,buttonStyle);
    setbtn_style(ui->btn_traced,buttonStyle);
    setbtn_style(ui->btn_none,buttonStyle);

}


//处理坐标，换位
short Picture_trace::ReverseUshort(short value)
   {
       return (short)((value & 0x00FFU) << 8 | (value & 0xFF00U) >> 8);
   }
short Picture_trace::zuobiaochulix(short zuobiao,short pianyi) {
       int temp_point = zuobiao - pianyi;
       temp_point = int(temp_point * (32768 / pianyi));
       return temp_point;
   }
short Picture_trace::zuobiaochuliy(short zuobiao, short pianyi) {
       int temp_point = zuobiao - pianyi;
       temp_point = int(temp_point * (32768 / pianyi));
       return temp_point;
}

QString Picture_trace::getMyType()
{
    return m_type;
}

void Picture_trace::resizeEvent(QResizeEvent *event)
{
    Mat img;
    Mat dst;
    float rat=float(ui->slider_size->value())/100;
    qDebug()<<qCeil(ui->graphicsView->width()*rat);
    qDebug()<<qCeil(ui->graphicsView->height()*rat);
    cv::Size dsize(int(ui->graphicsView->width()*rat),int(ui->graphicsView->height()*rat));
    if(!img_src.isEmpty()){
        if(ui->graphicsView->width()>0&&ui->graphicsView->height()>0){
            img=imread(img_src.toStdString());
            cv::resize(img,dst,dsize);
            QFile file(img_src);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_resized.bmp";
            imwrite(save.toStdString(),dst);
            img_src=save;
        }

    }
    if(!img_reduced.isEmpty()){
        if(ui->graphicsView->width()>0&&ui->graphicsView->height()>0){
            img=imread(img_reduced.toStdString());
            cv::resize(img,dst,dsize);
            QFile file(img_reduced);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_resized.bmp";
            imwrite(save.toStdString(),dst);
            img_reduced=save;
        }

    }
    if(!img_traced.isEmpty()){
        if(ui->graphicsView->width()>0&&ui->graphicsView->height()>0){
            img=imread(img_traced.toStdString());
            cv::resize(img,dst,dsize);
            QFile file(img_traced);
            QFileInfo fileinfo(file);
            qDebug()<<fileinfo.baseName();
            QString save=save_dir+fileinfo.baseName()+"_resized.bmp";
            imwrite(save.toStdString(),dst);
            img_traced=save;
        }
    }
}
