#ifndef DMAX_OUT_ARTNET_DIALOG_H
#define DMAX_OUT_ARTNET_DIALOG_H

#include <QDialog>

namespace Ui {
class dmax_out_artnet_Dialog;
}

class dmax_out_artnet_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dmax_out_artnet_Dialog(QWidget *parent = nullptr);
    ~dmax_out_artnet_Dialog();
    void setid(int id);
    void setuniverse(int universe);

private slots:
    void accept() override;

private:
    Ui::dmax_out_artnet_Dialog *ui;
    int id=0;
signals:
    void artnetsettings(int id, int universe);
};

#endif // DMAX_OUT_ARTNET_DIALOG_H
