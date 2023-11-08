#include "fb4_settings.h"
#include "ui_fb4_settings.h"

FB4_Settings::FB4_Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FB4_Settings)
{
    ui->setupUi(this);
}

FB4_Settings::~FB4_Settings()
{
    delete ui;
}
