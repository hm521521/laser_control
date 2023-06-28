#ifndef DMX_SETUP_H
#define DMX_SETUP_H

#include <QDialog>

namespace Ui {
class DMX_setup;
}

class DMX_setup : public QDialog
{
    Q_OBJECT

public:
    explicit DMX_setup(QWidget *parent = nullptr);
    ~DMX_setup();

private:
    Ui::DMX_setup *ui;
};

#endif // DMX_SETUP_H
