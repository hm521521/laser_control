#include "dmx_setup.h"
#include "ui_dmx_setup.h"

DMX_setup::DMX_setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMX_setup)
{
    ui->setupUi(this);
}

DMX_setup::~DMX_setup()
{
    delete ui;
}
