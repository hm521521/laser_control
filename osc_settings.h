#ifndef OSC_SETTINGS_H
#define OSC_SETTINGS_H

#include <QDialog>

namespace Ui {
class osc_settings;
}

class osc_settings : public QDialog
{
    Q_OBJECT

public:
    explicit osc_settings(QWidget *parent = nullptr);
    ~osc_settings();

private:
    Ui::osc_settings *ui;
};

#endif // OSC_SETTINGS_H
