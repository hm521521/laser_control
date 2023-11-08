#include "dialog_setpassword.h"
#include "ui_dialog_setpassword.h"

Dialog_Setpassword::Dialog_Setpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Setpassword)
{
    ui->setupUi(this);
}

Dialog_Setpassword::~Dialog_Setpassword()
{
    delete ui;
}
