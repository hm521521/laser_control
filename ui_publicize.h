/********************************************************************************
** Form generated from reading UI file 'publicize.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLICIZE_H
#define UI_PUBLICIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "output_panel.h"

QT_BEGIN_NAMESPACE

class Ui_publicize
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_open;
    QPushButton *btn_process;
    QPushButton *btn_play;
    QPushButton *btn_output;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSlider *distance_horizontalSlider;
    QDoubleSpinBox *distance_SpinBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    output_panel *public_panel_1;
    output_panel *public_panel_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *publicize)
    {
        if (publicize->objectName().isEmpty())
            publicize->setObjectName(QString::fromUtf8("publicize"));
        publicize->resize(800, 600);
        centralwidget = new QWidget(publicize);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_open = new QPushButton(widget_2);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));

        horizontalLayout_2->addWidget(btn_open);

        btn_process = new QPushButton(widget_2);
        btn_process->setObjectName(QString::fromUtf8("btn_process"));

        horizontalLayout_2->addWidget(btn_process);

        btn_play = new QPushButton(widget_2);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));

        horizontalLayout_2->addWidget(btn_play);

        btn_output = new QPushButton(widget_2);
        btn_output->setObjectName(QString::fromUtf8("btn_output"));

        horizontalLayout_2->addWidget(btn_output);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        distance_horizontalSlider = new QSlider(widget_3);
        distance_horizontalSlider->setObjectName(QString::fromUtf8("distance_horizontalSlider"));
        distance_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(distance_horizontalSlider);

        distance_SpinBox = new QDoubleSpinBox(widget_3);
        distance_SpinBox->setObjectName(QString::fromUtf8("distance_SpinBox"));

        horizontalLayout_3->addWidget(distance_SpinBox);


        verticalLayout->addWidget(widget_3);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        public_panel_1 = new output_panel(widget);
        public_panel_1->setObjectName(QString::fromUtf8("public_panel_1"));
        public_panel_1->setMinimumSize(QSize(379, 379));

        horizontalLayout->addWidget(public_panel_1);

        public_panel_2 = new output_panel(widget);
        public_panel_2->setObjectName(QString::fromUtf8("public_panel_2"));
        public_panel_2->setMinimumSize(QSize(379, 379));

        horizontalLayout->addWidget(public_panel_2);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        publicize->setCentralWidget(centralwidget);
        menubar = new QMenuBar(publicize);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        publicize->setMenuBar(menubar);
        statusbar = new QStatusBar(publicize);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        publicize->setStatusBar(statusbar);

        retranslateUi(publicize);

        QMetaObject::connectSlotsByName(publicize);
    } // setupUi

    void retranslateUi(QMainWindow *publicize)
    {
        publicize->setWindowTitle(QApplication::translate("publicize", "MainWindow", nullptr));
        btn_open->setText(QApplication::translate("publicize", "open_file", nullptr));
        btn_process->setText(QApplication::translate("publicize", "process", nullptr));
        btn_play->setText(QApplication::translate("publicize", "play", nullptr));
        btn_output->setText(QApplication::translate("publicize", "output", nullptr));
        label->setText(QApplication::translate("publicize", "\350\267\235\347\246\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class publicize: public Ui_publicize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLICIZE_H
