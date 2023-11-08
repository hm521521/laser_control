#include "add_zones_dialog.h"
#include "ui_add_zones_dialog.h"

add_zones_dialog::add_zones_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_zones_dialog)
{
    ui->setupUi(this);

}

add_zones_dialog::~add_zones_dialog()
{
    delete ui;
}

void add_zones_dialog::on_cancel_pushButton_clicked()
{
    this->close();
}


void add_zones_dialog::on_OK_pushButton_clicked()
{
    QString m_name=ui->lineEdit->text();
    if (m_name.isEmpty()|m_name.isNull())
    {
        this->close();
    }
    else
    {
        emit zone_name(m_name);
        this->close();
    }

}

