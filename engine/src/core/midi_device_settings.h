#ifndef MIDI_DEVICE_SETTINGS_H
#define MIDI_DEVICE_SETTINGS_H

#include <QDialog>

namespace Ui {
class midi_device_settings;
}

class midi_device_settings : public QDialog
{
    Q_OBJECT

public:
    explicit midi_device_settings(QWidget *parent = nullptr);
    ~midi_device_settings();

private:
    Ui::midi_device_settings *ui;
};

#endif // MIDI_DEVICE_SETTINGS_H
