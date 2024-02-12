#include "add_id_dialog.h"
#include "ui_add_id_dialog.h"

add_id_dialog::add_id_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_id_dialog)
{
    ui->setupUi(this);
}

add_id_dialog::~add_id_dialog()
{
    delete ui;
}

void add_id_dialog::on_okButton_clicked()
{
    QString m_name=ui->lineEdit->text();
    if (m_name.isEmpty()|m_name.isNull())
    {
        this->close();
    }
    else
    {
        emit id_name(m_name);
        this->close();
    }
}


void add_id_dialog::on_cancelButton_clicked()
{
    this->close();
}

