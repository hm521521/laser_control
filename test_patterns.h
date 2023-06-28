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
public:
    my_list_view(QWidget *parent=nullptr);
    ~my_list_view();
    void setup(QString list_path);
private:
    QString m_list_path;
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
};

#endif // TEST_PATTERNS_H
