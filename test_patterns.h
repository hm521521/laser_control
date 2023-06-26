#ifndef TEST_PATTERNS_H
#define TEST_PATTERNS_H

#include <QMainWindow>
#include<QGraphicsView>
#include<QCoreApplication>
#include"laser_setting.h"

namespace Ui {
class test_patterns;
}


class test_patterns : public QMainWindow
{
    Q_OBJECT

public:
    explicit test_patterns(QWidget *parent = nullptr);
    ~test_patterns();
    laser_device_table *m_device_table;

private:
    Ui::test_patterns *ui;
    QString m_list_path="/system/test_list.txt";
};

#endif // TEST_PATTERNS_H
