#include "delete_projection_zone_dialog.h"
#include "ui_delete_projection_zone_dialog.h"

delete_projection_zone_Dialog::delete_projection_zone_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_projection_zone_Dialog)
{
    ui->setupUi(this);
}

delete_projection_zone_Dialog::~delete_projection_zone_Dialog()
{
    delete ui;
}




void delete_projection_zone_Dialog::on_buttonBox_accepted()
{
    emit delete_zone();
    close();
}


void delete_projection_zone_Dialog::on_buttonBox_rejected()
{
    close();
}

