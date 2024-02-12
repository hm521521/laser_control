#include "setup_administrator_mode.h"
#include "ui_setup_administrator_mode.h"

setup_Administrator_mode::setup_Administrator_mode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setup_Administrator_mode)
{
    ui->setupUi(this);
}

setup_Administrator_mode::~setup_Administrator_mode()
{
    delete ui;
}
