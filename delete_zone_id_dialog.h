#ifndef DELETE_ZONE_ID_DIALOG_H
#define DELETE_ZONE_ID_DIALOG_H

#include <QDialog>

namespace Ui {
class delete_zone_id_Dialog;
}

class delete_zone_id_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit delete_zone_id_Dialog(QWidget *parent = nullptr);
    ~delete_zone_id_Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::delete_zone_id_Dialog *ui;

signals:
    void delete_id();

};

#endif // DELETE_ZONE_ID_DIALOG_H
