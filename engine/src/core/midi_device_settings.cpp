#include "midi_device_settings.h"
#include "ui_midi_device_settings.h"

midi_device_settings::midi_device_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::midi_device_settings)
{
    ui->setupUi(this);
}

midi_device_settings::~midi_device_settings()
{
    delete ui;
}
