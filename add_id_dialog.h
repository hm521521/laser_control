#ifndef ADD_ID_DIALOG_H
#define ADD_ID_DIALOG_H

#include <QDialog>

namespace Ui {
class add_id_dialog;
}

class add_id_dialog : public QDialog
{
    Q_OBJECT
public:
    explicit add_id_dialog(QWidget *parent = nullptr);
    ~add_id_dialog();
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
private:
    Ui::add_id_dialog *ui;
signals:
    void id_name(QString idname);
};

#endif // ADD_ID_DIALOG_H
