#include "publicize.h"
#include "ui_publicize.h"
#include<QFileDialog>
#include"cjpoint.h"
using namespace cv;
using namespace std;
publicize::publicize(QWidget *parent) :
    SubWindow(),
    ui(new Ui::publicize)
{
    ui->setupUi(this);
    ui->publicize_gridLayout->setHorizontalSpacing(0);
    ui->publicize_gridLayout->setVerticalSpacing(0);
    m_scene=new single_scene();
    for(int row=0;row<laser_row_num;row++)
    {
        ui->publicize_gridLayout->setRowMinimumHeight(row,200);
        for(int col=0;col<laser_column_num;col++)
        {
            ui->publicize_gridLayout->setColumnMinimumWidth(col,200);
            output_panel *panel=new output_panel(this);
            ui->publicize_gridLayout->addWidget(panel,row,col,1,1);
            QRect scenerect=ui->publicize_gridLayout->cellRect(row,col);
            panel->resize(scenerect.width(),scenerect.height());
            QGraphicsScene *scene=new QGraphicsScene(scenerect);
            panel->setScene(scene);
            m_output_panels.push_back(panel);
        }
    }
//    int wid=0;
//    int hei=0;
//    for(int row=0;row<laser_row_num;row++)
//    {
//        for(int col=0;col<laser_column_num;col++)
//        {
//            QRect scenerect=ui->publicize_gridLayout->cellRect(row,col);
//            wid=wid+scenerect.width();
//            hei=hei+scenerect.height();
//        }
//    }
//    ui->public_panel_1->setScene(scene);
//    QGraphicsScene *scene1=new QGraphicsScene(this);
//    ui->public_panel_2->setScene(scene1);
    connectSliderAndSpin(ui->distance_horizontalSlider,ui->distance_spinBox);
    connectSliderAndSpin(ui->image_num_horizontalSlider,ui->image_num_spinBox);
    connectSliderAndSpin(ui->thresh_horizontalSlider,ui->thresh_spinBox);
    publicize_worker *worker=new publicize_worker();
    worker->moveToThread(&thread);
    connect(&thread,&QThread::finished,&thread,&QThread::deleteLater);
    connect(this,&publicize::playpause,[=](){worker->pause();});
    connect(this,&publicize::operate,worker,&publicize_worker::run);
//    connect(worker,&publicize_worker::play,this,&publicize::on_thread_update);
//    connect(worker,&publicize_worker::stop,&thread,&QThread::quit);
//    thread.start();
}

publicize::~publicize()
{
    delete ui;
}

void publicize::datainit()
{
//    ui->public_panel_1->scene()->clear();
//    ui->public_panel_2->scene()->clear();
    init_sliderAndspin(ui->distance_horizontalSlider, ui->distance_spinBox, 0, 50, 1, 1, 3);
    init_sliderAndspin(ui->image_num_horizontalSlider, ui->image_num_spinBox, 1, 8, 1, 1, 1);
    setAllbtn_style();
//    ui->distance_horizontalSlider->setValue(distance);
    contours.clear();
    position.clear();
    m_scene->clear();
}

void publicize::init_sliderAndspin(QSlider *slider, QSpinBox *spin, int min, int max, int step1, int step2, int basevalue)
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

void publicize::connectSliderAndSpin(QSlider *slider, QSpinBox *spin)
{
    connect(slider, &QSlider::valueChanged,
                  spin, &QSpinBox::setValue);
    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider, &QSlider::setValue);
    connect(spin,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,[=](){
        if(spin->objectName()=="distance_spinBox")
            this->distance = spin->value();
        else if(spin->objectName()=="image_num_spinBox")
            this->image_num=spin->value()*6;
        else if(spin->objectName()=="thresh_spinBox")
            this->thresh=spin->value();
        if(ui->btn_process->getValue())
            on_btn_process_clicked();
    });
}

void publicize::update_show(CJSection *section, int i)
{
//    m_output_panels.at(i)->m_picture.clear();
    CJSection *output_picture=section;
    if(ui->btn_play->isChecked())
    {
        CJSection picture;
//            int pic_dx=-(i%laser_column_num)*(m_output_panels.at(i)->rect().width()+m_output_panels.at(i)->rect().width()*2/ui->image_num_horizontalSlider->value());
        int pic_dx=0;
        if(i%laser_column_num!=0)
            pic_dx=ui->publicize_gridLayout->cellRect(0,0).x()-ui->publicize_gridLayout->cellRect(i/laser_column_num,i%laser_column_num).x()-ui->publicize_gridLayout->cellRect(0,0).width()/6;
        int pic_dy=0;
        m_scene->render(&picture,m_frame_index);//从m_scene里获取到的CJsection
        for(int j=0;j<picture.size();j++)
        {
            picture[j]=picture[j].translate(pic_dx,pic_dy);
        }
        if(picture.size()>0)
        {
            output_picture->insert(output_picture->end(),picture.begin(),picture.end());
        }

    }
    if(i==laser_column_num*laser_row_num-1)
    {
        m_frame_index++;
        if(m_frame_index==image_num)
            m_frame_index=0;
    }
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
    Mat img=imread(fileName.toStdString());
    m_scene->setname(fileName);
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
//    Mat orc_dst;
    auto srcmaxsize=max(img.size().width,img.size().height);
    auto graphicminsize=min(ui->publicize_gridLayout->cellRect(0,0).width(),ui->publicize_gridLayout->cellRect(0,0).height());
    double scale=srcmaxsize/graphicminsize;
//    Mat dst;
    cv::resize(gray,src_dst,Size(img.size().width/scale,img.size().height/scale),0,0);//调整大小
//    GaussianBlur(dst,src_dst,Size(3,3),5);
//    Mat dst1;
}


int publicize::point_distance(cv::Point p1, cv::Point p2)
{   float ans=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    return qFloor(ans);
}

void publicize::addeffect(int idx,int start_idx,single_scene *scene)
{
//    int effect_count = image_num;
//      int x_off=(ui->publicize_gridLayout->cellRect(0,0).width()/(image_num/4))*(idx-image_num/2);
//    int x_off=ui->publicize_gridLayout->cellRect(0,0).width()+(ui->publicize_gridLayout->cellRect(0,0).width()*4/image_num)*(idx-image_num/2);
    int x_off=ui->publicize_gridLayout->cellRect(0,0).width()+(600/image_num)*(idx-image_num/2);
    effect *m_effect;
//                    effect* m_effect = effect::LoadEffect(br);
//                    this->push_back(effect);
    EffectType type=EffectType::ET_PICTURE;//初始化一个type
//      int idx = 0;
    int start_frame_index = start_idx;
    int frame_length = 0;
    PictureInfo temp_var(type,idx);
      m_effect=effect::CreateEffect(&temp_var);
    if(m_effect !=nullptr)
    {
        m_effect->Param.param_data[0]=0;
        m_effect->Param.param_data[1]=image_num;
        m_effect->Param.param_data[2]=1;
        m_effect->Param.param_data[3]=1;
        int picture_count=image_num;
//            strin.readRawData((char*)&picture_count, sizeof(int));//读图片数量，.isw文件里有的
        m_effect->Load();
//                        m_effect->get_pictures().clear();//把当前效果对象的m_pictures清空，m_pictures是CJImage类型，CJImage是容器

        CJImage m_pictures=m_effect->get_pictures();

        for (int k = 0; k < picture_count; k++)
        {
            int point_count = position.size();//读第一幅图点的数量

            CJSection list;//定义点属性列表（一张图的所有点）
            for (int l = 0; l < point_count; l++)//读每个点的信息
            {
                double graphicminsize=max(ui->publicize_gridLayout->cellRect(0,0).width(),ui->publicize_gridLayout->cellRect(0,0).height());
                double scenesize=min(ui->pub_scene_panel->size().width(),ui->pub_scene_panel->size().height());
                double scale=graphicminsize/scenesize;
                auto x = position.at(l).X*scale+x_off;//点的横坐标
                auto y = position.at(l).Y*scale;//点的纵坐标
                //点的三个通道的值
                unsigned char r = 0;
                unsigned char g = 255;
                unsigned char b = 0;
                PointAttribute tempVar(x, y, 0, r, g, b);//把读到的点的信息存入临时点的属性对象
                list.push_back(tempVar);
            }
            m_pictures.push_back(list);
        }
        m_effect->set_pictures(m_pictures);
        m_effect->set_type(type);
        m_effect->set_index(idx);
        m_effect->set_start_index(start_frame_index);
        m_effect->set_frame_length(frame_length);
        m_pictures.clear();
    }
    scene->push_back(m_effect);
}

void publicize::display()
{
    single_scene *temp_scene=new single_scene();
    m_scene->clear();
    if(ui->thresh_checkBox->isChecked())
        adaptiveThreshold(src_dst,thresh_dst,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,3,5);
    else
        threshold(src_dst,thresh_dst,thresh,255,THRESH_BINARY);
//    imshow("gaussian",thresh_dst);
    vector<Vec4i> hierarchy;
    findContours(thresh_dst, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    int sum=0;
    Mat kongbai = Mat::zeros(Size(thresh_dst.cols,thresh_dst.rows),CV_8UC3);
//    CJSection temp_sec;
    for(uint i=0;i<contours.size();i++)
    {
        cv::Point pre=contours[i][0];
        cv::circle(kongbai,pre,1,cv::Scalar(0, 255, 0), 2);
//        postion<<"第"<<i<<"个轮廓"<<endl;
//        vector<CJPoint> position;
//        PointAttribute point;
        for(uint j=1;j<contours[i].size();j++)
        {
            cv::Point now=contours[i][j];
            if(point_distance(pre,now)>distance||j+1==contours[i].size())
            {
                if(j+1==contours[i].size()){
                    position.push_back(CJPoint(pre.x,pre.y));
                    position.push_back(CJPoint(pre.x+1,pre.y));
                    position.push_back(CJPoint(now.x,now.y));
                }
                else{
                    position.push_back(CJPoint(pre.x,pre.y));
                    position.push_back(CJPoint(pre.x+1,pre.y));
                }
                cv::line(kongbai,pre,now,cv::Scalar(0, 255, 0), 1);
                cv::circle(kongbai,now,1,cv::Scalar(0,255, 0), 2);
                pre=now;
                sum++;
            }
            for(int k=0;k<image_num;k++)
                addeffect(k,k,m_scene);
            addeffect(image_num/2-image_num/6-image_num/6,0,temp_scene);
            position.clear();
        }
    }
//    imshow("kongbai",kongbai);
//    addeffect();
    ui->pub_scene_panel->m_graphicsScene=new QGraphicsScene(this);
    ui->pub_scene_panel->setScene(ui->pub_scene_panel->m_graphicsScene);

    ui->pub_scene_panel->set_data_model(temp_scene);
    ui->pub_scene_panel->do_draw(true);
}

void publicize::SetSliderAndSpinEnable(QSlider *slider, QSpinBox *spin, bool flag)
{
    slider->setEnabled(flag);
    spin->setEnabled(flag);
}

void publicize::on_btn_process_clicked()
{
    if(ui->btn_process->isChecked())
    {
//        SetSliderAndSpinEnable(ui->distance_horizontalSlider,ui->distance_spinBox,false);
//        SetSliderAndSpinEnable(ui->thresh_horizontalSlider,ui->thresh_spinBox,false);
        display();
    }
    else
    {
//        SetSliderAndSpinEnable(ui->distance_horizontalSlider,ui->distance_spinBox,true);
//        SetSliderAndSpinEnable(ui->thresh_horizontalSlider,ui->thresh_spinBox,true);
    }//        ui->distance_horizontalSlider->setEnabled(false);
}


void publicize::on_btn_play_clicked()
{
    if(ui->btn_play->isChecked())
    {
        m_frame_index=0;
        emit operate();
        ui->btn_play->setText("stop");
        SetSliderAndSpinEnable(ui->image_num_horizontalSlider,ui->image_num_spinBox,false);
    }
    else
    {
//        thread.quit();
        emit playpause();
        ui->btn_play->setText("play");
        SetSliderAndSpinEnable(ui->image_num_horizontalSlider,ui->image_num_spinBox,true);
    }

}


void publicize::on_thresh_checkBox_stateChanged(int arg1)
{
    if(arg1==2)
    {
        ui->thresh_horizontalSlider->setEnabled(false);
        ui->thresh_spinBox->setEnabled(false);
        on_btn_process_clicked();
    }
    else if(arg1==0)
    {
        ui->thresh_horizontalSlider->setEnabled(true);
        ui->thresh_spinBox->setEnabled(true);
        on_btn_process_clicked();
    }

}

void publicize::on_thread_update()
{

    for(int i=0;i<m_output_panels.size();i++)
    {
        m_output_panels.at(i)->m_picture.clear();
        this->update_show(&m_output_panels.at(i)->m_picture,i);
//        CJSection *output_picture=&m_output_panels.at(i)->m_picture;
//        if(ui->btn_play->isChecked())
//        {
//            CJSection picture;
////            int pic_dx=-(i%laser_column_num)*(m_output_panels.at(i)->rect().width()+m_output_panels.at(i)->rect().width()*2/ui->image_num_horizontalSlider->value());
//            int pic_dx=0;
//            if(i%laser_column_num!=0)
//                pic_dx=ui->publicize_gridLayout->cellRect(0,0).x()-ui->publicize_gridLayout->cellRect(i/laser_column_num,i%laser_column_num).x()-ui->publicize_gridLayout->cellRect(0,0).width()/4;
//            int pic_dy=0;
//            m_scene->render(&picture,m_frame_index);//从m_scene里获取到的CJsection
//            for(int j=0;j<picture.size();j++)
//            {
//                picture[j]=picture[j].translate(pic_dx,pic_dy);
//            }
//            if(picture.size()>0)
//            {
//                output_picture->insert(output_picture->end(),picture.begin(),picture.end());
//            }

//        }
        m_output_panels.at(i)->do_draw();
    }
//    m_frame_index++;
//    if(m_frame_index==image_num)
//        m_frame_index=0;
}



publicize_worker::publicize_worker(QObject *parent)
{

}

publicize_worker::~publicize_worker()
{

}

void publicize_worker::run()
{
    m_start=true;
    m_pause=false;
    while(m_start)
    {
        if(m_pause)
        {
            m_start=false;
        }
        emit play();
        QThread::msleep(100);
    }
    emit stop();
}

void publicize_worker::pause()
{
    m_pause=true;
}

