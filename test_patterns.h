#ifndef TEST_PATTERNS_H
#define TEST_PATTERNS_H

#include <QMainWindow>
#include<QGraphicsView>
#include<QCoreApplication>
#include"laser_setting.h"
#include<QListView>

namespace Ui {
class test_patterns;
}

class my_list_view:public QListView
{
    Q_OBJECT
public:
    my_list_view(QWidget *parent=nullptr);
    ~my_list_view();
    void setup(QString list_path);
private:
    QString m_list_path;

protected:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
signals:
    void sendSection(CJSection section);

};



class test_patterns : public QMainWindow
{
    Q_OBJECT

public:
    explicit test_patterns(QWidget *parent = nullptr);
    ~test_patterns();
    laser_device_table *m_device_table;

private:
    Ui::test_patterns *ui;
    QString m_path="/system/test_list.txt";
public slots:
    void show_test_view(QModelIndex current);
    void receiveSection(CJSection section);
signals:
    void sendSection(CJSection section);
    void on_enable_output();

private slots:
    void on_output_pushButton_clicked();
};

#endif // TEST_PATTERNS_H
