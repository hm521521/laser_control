#include "fb4_files_viewer.h"
#include "ui_fb4_files_viewer.h"

FB4_Files_viewer::FB4_Files_viewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FB4_Files_viewer)
{
    ui->setupUi(this);
}

FB4_Files_viewer::~FB4_Files_viewer()
{
    delete ui;
}
