/********************************************************************************
** Form generated from reading UI file 'test_patterns.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_PATTERNS_H
#define UI_TEST_PATTERNS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <laser_setting.h>
#include <test_patterns.h>
#include "toggle_button.h"

QT_BEGIN_NAMESPACE

class Ui_test_patterns
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *horizontalSlider;
    my_list_view *test_list;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    toggle_button *output_pushButton;
    QPushButton *pushButton_2;
    laser_device_table *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *test_patterns)
    {
        if (test_patterns->objectName().isEmpty())
            test_patterns->setObjectName(QString::fromUtf8("test_patterns"));
        test_patterns->resize(628, 549);
        centralwidget = new QWidget(test_patterns);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(300, 0));
        widget_2->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(280, 0));
        widget_3->setMaximumSize(QSize(280, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSlider = new QSlider(widget_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(180, 0));
        horizontalSlider->setMaximumSize(QSize(180, 16777215));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);


        verticalLayout->addWidget(widget_3);

        test_list = new my_list_view(widget_2);
        test_list->setObjectName(QString::fromUtf8("test_list"));
        test_list->setMinimumSize(QSize(280, 400));
        test_list->setMaximumSize(QSize(280, 16777215));

        verticalLayout->addWidget(test_list);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        output_pushButton = new toggle_button(widget_4);
        output_pushButton->setObjectName(QString::fromUtf8("output_pushButton"));

        horizontalLayout_3->addWidget(output_pushButton);

        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(20, 0));
        pushButton_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addWidget(widget_4);

        tableView = new laser_device_table(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);


        horizontalLayout->addWidget(widget);

        test_patterns->setCentralWidget(centralwidget);
        menubar = new QMenuBar(test_patterns);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 628, 23));
        test_patterns->setMenuBar(menubar);
        statusbar = new QStatusBar(test_patterns);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        test_patterns->setStatusBar(statusbar);

        retranslateUi(test_patterns);

        QMetaObject::connectSlotsByName(test_patterns);
    } // setupUi

    void retranslateUi(QMainWindow *test_patterns)
    {
        test_patterns->setWindowTitle(QApplication::translate("test_patterns", "MainWindow", nullptr));
        label->setText(QApplication::translate("test_patterns", "\344\272\256\345\272\246\357\274\232100%", nullptr));
        output_pushButton->setText(QApplication::translate("test_patterns", "\350\276\223\345\207\272\345\210\260\346\277\200\345\205\211", nullptr));
        pushButton_2->setText(QApplication::translate("test_patterns", "\344\270\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test_patterns: public Ui_test_patterns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_PATTERNS_H
