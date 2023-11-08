#ifndef DIALOG_SETPASSWORD_H
#define DIALOG_SETPASSWORD_H

#include <QDialog>

namespace Ui {
class Dialog_Setpassword;
}

class Dialog_Setpassword : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Setpassword(QWidget *parent = nullptr);
    ~Dialog_Setpassword();

private:
    Ui::Dialog_Setpassword *ui;
};

#endif // DIALOG_SETPASSWORD_H
