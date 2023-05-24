#include "clockedit.h"
#include "ui_clockedit.h"

ClockEdit::ClockEdit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClockEdit)
{
    ui->setupUi(this);
    //将Sinder与box相连
    connectSpinAndSlider(ui->Slider_sizeX,ui->spinBox_sizeX,10,100,1,100);
    connectSpinAndSlider(ui->Slider_sizeY,ui->spinBox_sizeY,10,100,1,100);
    connectSpinAndSlider(ui->Slider_locX,ui->spinBox_locX,-100,100,1,0);
    connectSpinAndSlider(ui->Slider_locY,ui->spinBox_locY,-100,100,1,0);
    connectSpinAndSlider(ui->Slider_fontsize,ui->spinBox_fontsize,16,128,1,64);
    connectSpinAndSlider(ui->Slider_fgap,ui->spinBox_fgap,-50,200,1,0);
    //尺寸，偏移，字体大小设置
    connect(ui->Slider_sizeX, &QSlider::valueChanged,
            this,[=](){
        ui->graphicsView->setXsize(ui->Slider_sizeX->value());
    });
    connect(ui->Slider_sizeY, &QSlider::valueChanged,
            this,[=](){
        ui->graphicsView->setYsize(ui->Slider_sizeY->value());
    });
    connect(ui->Slider_locX, &QSlider::valueChanged,
            this,[=](){
        ui->graphicsView->setXoffset(ui->Slider_locX->value());
    });
    connect(ui->Slider_locY, &QSlider::valueChanged,
            this,[=](){
        ui->graphicsView->setYoffset(ui->Slider_locY->value());
    });
    connect(ui->Slider_fontsize, &QSlider::valueChanged,
            this,[=](){
        ui->graphicsView->setFontsize(ui->Slider_fontsize->value());
    });
    //默认小时分钟秒可查看。
    ui->view_hour->setChecked(true);
    ui->view_min->setChecked(true);
    ui->view_sec->setChecked(true);
    ui->radioButton->setChecked(true);
    bg.addButton(ui->radioButton,1);
    bg.addButton(ui->radioButton_2,2);
    bg.addButton(ui->radioButton_3,3);
    bg.addButton(ui->radioButton_4,4);
    bg.addButton(ui->radioButton_5,5);
    bg.addButton(ui->radioButton_6,6);
    connect(&bg,SIGNAL(buttonClicked(int)),this,SLOT(slot_RtnGroupChanged(int)));

//    connect(ui->radioButton,&QRadioButton::toggled,this,[=](){
//       if(ui->radioButton->isChecked())
//          ui->radioButton->update();
//    });
    ui->min_sec_gapchar->setMaxLength(1);
    ui->hour_min_gapchar->setMaxLength(1);
    ui->min_sec_gapchar->setText(":");
    ui->hour_min_gapchar->setText(":");

    connect(ui->min_sec_gapchar,&QLineEdit::textEdited,this,[=](){
       ui->graphicsView->setM_S(ui->min_sec_gapchar->text());
    });
//     connect(ui->hour_min_gapchar,SIGNAL(textEdited(const QString )),this,SLOT((slot_setFengefu(QString))));
    connect(ui->hour_min_gapchar,&QLineEdit::textEdited,this,[=](){
       ui->graphicsView->setH_M(ui->hour_min_gapchar->text());
    });


}

ClockEdit::~ClockEdit()
{
    delete ui;
}

void ClockEdit::connectSpinAndSlider(QSlider *slider, QSpinBox* spin,int min,int max,int step,int basevalue)
{
    slider->setMinimum(min);
    slider->setMaximum(max);
    slider->setSingleStep(step);
    spin->setMinimum(min);
    spin->setMaximum(max);
    spin->setSingleStep(step);
    connect(slider, &QSlider::valueChanged,
                    spin, &QSpinBox::setValue);
        connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                slider, &QSlider::setValue);
    spin->setValue(basevalue);

}

void ClockEdit::slot_RtnGroupChanged(int id)
{
    ui->graphicsView->settype(id);
    ui->graphicsView->update();
}



