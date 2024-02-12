#include "dmax_out_artnet_dialog.h"
#include "ui_dmax_out_artnet_dialog.h"

dmax_out_artnet_Dialog::dmax_out_artnet_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dmax_out_artnet_Dialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&dmax_out_artnet_Dialog::accept);
    connect(ui->buttonBox,&QDialogButtonBox::rejected,this,&QDialog::reject);
    connect(ui->sim_universe_spinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                 [=](int i){
        ui->universe_spinBox_2->setValue(i%16);
        ui->subnet_spinBox->setValue(i/16);
    });
    connect(ui->universe_spinBox_2, QOverload<int>::of(&QSpinBox::valueChanged),
                 [=](int i){
        int subnet=ui->subnet_spinBox->value();
        ui->sim_universe_spinBox->setValue(i+subnet*16);
    });
    connect(ui->subnet_spinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                 [=](int i){
        int universe=ui->universe_spinBox_2->value();
        ui->sim_universe_spinBox->setValue(i*16+universe);
    });
}

dmax_out_artnet_Dialog::~dmax_out_artnet_Dialog()
{
    delete ui;
}

void dmax_out_artnet_Dialog::setid(int id)
{
    this->id=id;
}

void dmax_out_artnet_Dialog::setuniverse(int universe)
{
    ui->sim_universe_spinBox->setValue(universe);
}

void dmax_out_artnet_Dialog::accept()
{
    int universe=ui->sim_universe_spinBox->value();
    emit artnetsettings(id,universe);
    QDialog::accept();
}


