#ifndef DMAX_OUTPUT_DIALOG_H
#define DMAX_OUTPUT_DIALOG_H

#include <QDialog>
#include"dmax_out_artnet_dialog.h"
#include<QSettings>
#include<QButtonGroup>

namespace Ui {
class dmax_output_Dialog;
}

class dmax_output_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dmax_output_Dialog(QWidget *parent = nullptr);
    ~dmax_output_Dialog();
    void set_output_id(int id);
    int get_output_id(int id);
    void set_output_way(int way_id);
private:
    Ui::dmax_output_Dialog *ui;
    char output_universes[4]={0,0,0,0};
    int output_id;
    QSettings *settings;
    QButtonGroup *buttongroup;
public slots:
    void saveuniverse(int id,int universe);
signals:
    void dmax_output_way(int output_id,int way_id);

};

#endif // DMAX_OUTPUT_DIALOG_H
