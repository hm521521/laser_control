#ifndef DIALOG_FB4_EXPORT_H
#define DIALOG_FB4_EXPORT_H

#include <QDialog>
#include<QListWidget>
namespace Ui {
class Dialog_FB4_Export;
}

class Dialog_FB4_Export : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_FB4_Export(QWidget *parent = nullptr);
    ~Dialog_FB4_Export();

private slots:


    void on_listWidget_FB4_Ex_itemClicked(QListWidgetItem *item);

private:
    Ui::Dialog_FB4_Export *ui;
};

#endif // DIALOG_FB4_EXPORT_H
