#ifndef SETUP_ADMINISTRATOR_MODE_H
#define SETUP_ADMINISTRATOR_MODE_H

#include <QDialog>

namespace Ui {
class setup_Administrator_mode;
}

class setup_Administrator_mode : public QDialog
{
    Q_OBJECT

public:
    explicit setup_Administrator_mode(QWidget *parent = nullptr);
    ~setup_Administrator_mode();

private:
    Ui::setup_Administrator_mode *ui;
};

#endif // SETUP_ADMINISTRATOR_MODE_H
