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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <main_panel.h>
#include "toggle_button.h"

QT_BEGIN_NAMESPACE

class Ui_publicize
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_open;
    toggle_button *btn_process;
    QPushButton *btn_play;
    QPushButton *btn_output;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSlider *thresh_horizontalSlider;
    QSpinBox *thresh_spinBox;
    QCheckBox *thresh_checkBox;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSlider *distance_horizontalSlider;
    QSpinBox *distance_spinBox;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSlider *image_num_horizontalSlider;
    QSpinBox *image_num_spinBox;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSlider *horizontalSlider_2;
    QSpinBox *spinBox_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    scene_panel *pub_scene_panel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *publicize_gridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *publicize)
    {
        if (publicize->objectName().isEmpty())
            publicize->setObjectName(QString::fromUtf8("publicize"));
        publicize->resize(354, 488);
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

        btn_process = new toggle_button(widget_2);
        btn_process->setObjectName(QString::fromUtf8("btn_process"));

        horizontalLayout_2->addWidget(btn_process);

        btn_play = new QPushButton(widget_2);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));

        horizontalLayout_2->addWidget(btn_play);

        btn_output = new QPushButton(widget_2);
        btn_output->setObjectName(QString::fromUtf8("btn_output"));

        horizontalLayout_2->addWidget(btn_output);


        verticalLayout->addWidget(widget_2);

        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        thresh_horizontalSlider = new QSlider(widget_7);
        thresh_horizontalSlider->setObjectName(QString::fromUtf8("thresh_horizontalSlider"));
        thresh_horizontalSlider->setEnabled(true);
        thresh_horizontalSlider->setMaximum(254);
        thresh_horizontalSlider->setValue(127);
        thresh_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(thresh_horizontalSlider);

        thresh_spinBox = new QSpinBox(widget_7);
        thresh_spinBox->setObjectName(QString::fromUtf8("thresh_spinBox"));
        thresh_spinBox->setMaximum(254);
        thresh_spinBox->setValue(127);

        horizontalLayout_7->addWidget(thresh_spinBox);

        thresh_checkBox = new QCheckBox(widget_7);
        thresh_checkBox->setObjectName(QString::fromUtf8("thresh_checkBox"));

        horizontalLayout_7->addWidget(thresh_checkBox);


        verticalLayout->addWidget(widget_7);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        distance_horizontalSlider = new QSlider(widget_3);
        distance_horizontalSlider->setObjectName(QString::fromUtf8("distance_horizontalSlider"));
        distance_horizontalSlider->setValue(3);
        distance_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(distance_horizontalSlider);

        distance_spinBox = new QSpinBox(widget_3);
        distance_spinBox->setObjectName(QString::fromUtf8("distance_spinBox"));
        distance_spinBox->setValue(3);

        horizontalLayout_3->addWidget(distance_spinBox);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        image_num_horizontalSlider = new QSlider(widget_4);
        image_num_horizontalSlider->setObjectName(QString::fromUtf8("image_num_horizontalSlider"));
        image_num_horizontalSlider->setMinimum(1);
        image_num_horizontalSlider->setMaximum(8);
        image_num_horizontalSlider->setSingleStep(1);
        image_num_horizontalSlider->setPageStep(10);
        image_num_horizontalSlider->setValue(1);
        image_num_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(image_num_horizontalSlider);

        image_num_spinBox = new QSpinBox(widget_4);
        image_num_spinBox->setObjectName(QString::fromUtf8("image_num_spinBox"));
        image_num_spinBox->setMinimum(1);
        image_num_spinBox->setMaximum(8);
        image_num_spinBox->setSingleStep(1);
        image_num_spinBox->setValue(1);

        horizontalLayout_4->addWidget(image_num_spinBox);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        horizontalSlider_2 = new QSlider(widget_5);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_2);

        spinBox_2 = new QSpinBox(widget_5);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_5->addWidget(spinBox_2);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pub_scene_panel = new scene_panel(widget_6);
        pub_scene_panel->setObjectName(QString::fromUtf8("pub_scene_panel"));
        pub_scene_panel->setMinimumSize(QSize(150, 150));
        pub_scene_panel->setMaximumSize(QSize(150, 150));
        pub_scene_panel->setBaseSize(QSize(0, 0));

        horizontalLayout_6->addWidget(pub_scene_panel);

        horizontalSpacer_2 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_6);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        publicize_gridLayout = new QGridLayout();
        publicize_gridLayout->setObjectName(QString::fromUtf8("publicize_gridLayout"));

        horizontalLayout->addLayout(publicize_gridLayout);


        verticalLayout->addWidget(widget);

        publicize->setCentralWidget(centralwidget);
        menubar = new QMenuBar(publicize);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 354, 23));
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
        label_4->setText(QApplication::translate("publicize", "\344\272\256\345\272\246\351\230\210\345\200\274", nullptr));
        thresh_checkBox->setText(QApplication::translate("publicize", "\350\207\252\345\212\250", nullptr));
        label->setText(QApplication::translate("publicize", "\347\202\271\351\227\264\350\267\235\347\246\273", nullptr));
        label_2->setText(QApplication::translate("publicize", "\345\270\247\346\225\260", nullptr));
        label_3->setText(QApplication::translate("publicize", "\346\222\255\346\224\276\351\200\237\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class publicize: public Ui_publicize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLICIZE_H
