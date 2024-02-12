#include "setup_user_mode.h"
#include "ui_setup_user_mode.h"

setup_user_mode::setup_user_mode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setup_user_mode)
{
    ui->setupUi(this);
}

setup_user_mode::~setup_user_mode()
{
    delete ui;
}
