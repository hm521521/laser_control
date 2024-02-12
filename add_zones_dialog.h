#ifndef ADD_ZONES_DIALOG_H
#define ADD_ZONES_DIALOG_H

#include <QDialog>

namespace Ui {
class add_zones_dialog;
}

class add_zones_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_zones_dialog(QWidget *parent = nullptr);
    ~add_zones_dialog();

private slots:
    void on_cancel_pushButton_clicked();

    void on_OK_pushButton_clicked();

private:
    Ui::add_zones_dialog *ui;
signals:
    void zone_name(QString str);
};

#endif // ADD_ZONES_DIALOG_H
