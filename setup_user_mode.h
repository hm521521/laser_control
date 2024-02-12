#ifndef SETUP_USER_MODE_H
#define SETUP_USER_MODE_H

#include <QDialog>

namespace Ui {
class setup_user_mode;
}

class setup_user_mode : public QDialog
{
    Q_OBJECT

public:
    explicit setup_user_mode(QWidget *parent = nullptr);
    ~setup_user_mode();

private:
    Ui::setup_user_mode *ui;
};

#endif // SETUP_USER_MODE_H
