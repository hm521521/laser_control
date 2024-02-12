#ifndef OUTPUT_UNIVERSE_DIALOG_H
#define OUTPUT_UNIVERSE_DIALOG_H

#include <QDialog>
#include<QAbstractButton>

namespace Ui {
class output_universe_Dialog;
}

class output_universe_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit output_universe_Dialog(QWidget *parent = nullptr);
    ~output_universe_Dialog();
private slots:
    void accept();
    void universe_changed(int id);
private:
    Ui::output_universe_Dialog *ui;
    int universe_index=0;

};

#endif // OUTPUT_UNIVERSE_DIALOG_H
