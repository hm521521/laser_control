#include "output_dialog.h"
#include "ui_output_dialog.h"

output_Dialog::output_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::output_Dialog)
{
    ui->setupUi(this);
    ui->buttonGroup->setId(ui->ed_radioButton,0);
    ui->buttonGroup->setId(ui->artnet_radioButton,1);
    connect(ui->buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){ emit output_way(id); });
}

output_Dialog::~output_Dialog()
{
    delete ui;
}

void output_Dialog::dealwithclose()
{
    close();
}
