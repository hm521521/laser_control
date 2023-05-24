#ifndef CLOCKEDIT_H
#define CLOCKEDIT_H

#include <QMainWindow>
#include<QSlider>
#include<QSpinBox>
#include<QButtonGroup>
#include<QDebug>
#include<mygraphicsview.h>
namespace Ui {
class ClockEdit;
}

class ClockEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClockEdit(QWidget *parent = nullptr);
    ~ClockEdit();
    void connectSpinAndSlider(QSlider *slider,QSpinBox *spin,int min,int max,int step,int basevalue);
private slots:

    void slot_RtnGroupChanged(int id);

private:
    Ui::ClockEdit *ui;
    QButtonGroup bg;
signals:



};

#endif // CLOCKEDIT_H
