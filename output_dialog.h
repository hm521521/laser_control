#ifndef OUTPUT_DIALOG_H
#define OUTPUT_DIALOG_H

#include <QDialog>

namespace Ui {
class output_Dialog;
}

class output_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit output_Dialog(QWidget *parent = nullptr);
    ~output_Dialog();

private:
    Ui::output_Dialog *ui;
signals:
    void output_way(int id);
public slots:
    void dealwithclose();
};

#endif // OUTPUT_DIALOG_H
