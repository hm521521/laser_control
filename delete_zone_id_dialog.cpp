#include "delete_zone_id_dialog.h"
#include "ui_delete_zone_id_dialog.h"

delete_zone_id_Dialog::delete_zone_id_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_zone_id_Dialog)
{
    ui->setupUi(this);
}

delete_zone_id_Dialog::~delete_zone_id_Dialog()
{
    delete ui;
}

void delete_zone_id_Dialog::on_buttonBox_accepted()
{
    emit delete_id();
    close();
}



void delete_zone_id_Dialog::on_buttonBox_rejected()
{
    close();
}

