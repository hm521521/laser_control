#include "osc_settings.h"
#include "ui_osc_settings.h"

osc_settings::osc_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::osc_settings)
{
    ui->setupUi(this);
}

osc_settings::~osc_settings()
{
    delete ui;
}
