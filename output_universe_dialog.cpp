#include "output_universe_dialog.h"
#include "ui_output_universe_dialog.h"
#include<QButtonGroup>
#include<QSettings>
#include"artnetcontroller.h"

output_universe_Dialog::output_universe_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::output_universe_Dialog)
{
    ui->setupUi(this);
    QButtonGroup *output_univese_group=new QButtonGroup(this);
    output_univese_group->addButton(ui->radioButton,0);
    output_univese_group->addButton(ui->radioButton_2,1);
    output_univese_group->addButton(ui->radioButton_3,2);
    output_univese_group->addButton(ui->radioButton_4,3);
    output_univese_group->setExclusive(true);
    QSettings* settings=new QSettings("./artnetconfig.ini",QSettings::IniFormat);
    QString key="output_universe";
    universe_index=settings->value(key).toInt();
    output_univese_group->button(universe_index)->setChecked(true);
    connect(output_univese_group,SIGNAL(buttonClicked(int)),this,SLOT(universe_changed(int)));
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&output_universe_Dialog::accept);
}

output_universe_Dialog::~output_universe_Dialog()
{
    delete ui;
}

void output_universe_Dialog::accept()
{
    QSettings* settings=new QSettings("./artnetconfig.ini",QSettings::IniFormat);
    QString key="output_universe";
    settings->setValue(key,universe_index);
    key="ArtNetPlugin/outputs";
    int num=settings->value(key).toInt();
    for(int i=0;i<num;i++)
    {
        key=QString("ArtNetPlugin/Output%1").arg(i);
        QString str=settings->value(key).toString().split("#").at(0);
        if(str==artgetLocalIP())
        {
            settings->setValue(key,str.append(QString("#%1").arg(universe_index)));
            break;
        }
    }
    QDialog::accept();
}

void output_universe_Dialog::universe_changed(int id)
{
    universe_index=id;
}


