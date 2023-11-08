#include "programgroupinfo.h"
#include "ui_programgroupinfo.h"

ProgramGroupInfo::ProgramGroupInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgramGroupInfo)
{
    ui->setupUi(this);
}

ProgramGroupInfo::~ProgramGroupInfo()
{
    delete ui;
}
