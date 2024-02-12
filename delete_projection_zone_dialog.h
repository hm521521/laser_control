#ifndef DELETE_PROJECTION_ZONE_DIALOG_H
#define DELETE_PROJECTION_ZONE_DIALOG_H

#include <QDialog>

namespace Ui {
class delete_projection_zone_Dialog;
}

class delete_projection_zone_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit delete_projection_zone_Dialog(QWidget *parent = nullptr);
    ~delete_projection_zone_Dialog();


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::delete_projection_zone_Dialog *ui;
signals:
    void delete_zone();
};

#endif // DELETE_PROJECTION_ZONE_DIALOG_H
