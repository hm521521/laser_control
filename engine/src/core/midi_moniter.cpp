#include "midi_moniter.h"
#include "ui_midi_moniter.h"

midi_moniter::midi_moniter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::midi_moniter)
{
    ui->setupUi(this);
}

midi_moniter::~midi_moniter()
{
    delete ui;
}
