#include "dmax_output_dialog.h"
#include "ui_dmax_output_dialog.h"
#include<QDebug>


dmax_output_Dialog::dmax_output_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dmax_output_Dialog)
{
    ui->setupUi(this);
    settings=new QSettings("./artnet_config.ini", QSettings::IniFormat);
    settings->beginGroup("dmax_output");
    output_universes[0]=settings->value("output1_universe").toInt();
    output_universes[1]=settings->value("output2_universe").toInt();
    output_universes[2]=settings->value("output3_universe").toInt();
    output_universes[3]=settings->value("output4_universe").toInt();
    settings->endGroup();
    buttongroup=new QButtonGroup(this);
    buttongroup->addButton(ui->disabled_radioButton,0);
    buttongroup->addButton(ui->ArtNet_radioButton,1);
    buttongroup->addButton(ui->sACN_radioButton,2);
    buttongroup->setExclusive(true);
    connect(buttongroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
        emit dmax_output_way(output_id,id);
        if(id!=1)
        {
            close();
            return;
        }
            dmax_out_artnet_Dialog *doad=new dmax_out_artnet_Dialog(this);
        doad->setModal(true);
        int i=this->output_id;
        if(i<(sizeof(output_universes)/sizeof(char)))
        {
            doad->setid(i);
            doad->setuniverse(output_universes[i]);
        }
        connect(doad,SIGNAL(artnetsettings(int,int)),this,SLOT(saveuniverse(int,int)));
        doad->show();
        close();
         });
}

dmax_output_Dialog::~dmax_output_Dialog()
{
    delete ui;
}

void dmax_output_Dialog::set_output_id(int id)
{
    this->output_id=id;
}

int dmax_output_Dialog::get_output_id(int id)
{
    if(id<(sizeof(output_universes)/sizeof(char)))
        return output_universes[id];
}

void dmax_output_Dialog::set_output_way(int way_id)
{
    buttongroup->button(way_id)->setChecked(true);
}

void dmax_output_Dialog::saveuniverse(int id, int universe)
{
    if(id<(sizeof(output_universes)/sizeof(char)))
        output_universes[id]=universe;
    settings->beginGroup("dmax_output");
    settings->setValue("output1_universe", output_universes[0]);
    settings->setValue("output2_universe", output_universes[1]);
    settings->setValue("output3_universe", output_universes[2]);
    settings->setValue("output4_universe", output_universes[3]);
    settings->endGroup();
}
