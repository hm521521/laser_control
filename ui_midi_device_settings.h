/********************************************************************************
** Form generated from reading UI file 'midi_device_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDI_DEVICE_SETTINGS_H
#define UI_MIDI_DEVICE_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_midi_device_settings
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QComboBox *comboBox_7;
    QComboBox *comboBox_8;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_6;
    QLabel *label_5;
    QListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *midi_device_settings)
    {
        if (midi_device_settings->objectName().isEmpty())
            midi_device_settings->setObjectName(QString::fromUtf8("midi_device_settings"));
        midi_device_settings->resize(298, 787);
        verticalLayout = new QVBoxLayout(midi_device_settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(midi_device_settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        comboBox_2 = new QComboBox(tab_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);

        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_2->addWidget(widget_2);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        comboBox_3 = new QComboBox(tab_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        verticalLayout_2->addWidget(comboBox_3);

        comboBox_4 = new QComboBox(tab_2);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        verticalLayout_2->addWidget(comboBox_4);

        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_3->addWidget(pushButton_4);


        verticalLayout_2->addWidget(widget_3);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        comboBox_5 = new QComboBox(tab_2);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        verticalLayout_2->addWidget(comboBox_5);

        comboBox_6 = new QComboBox(tab_2);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        verticalLayout_2->addWidget(comboBox_6);

        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_5 = new QPushButton(widget_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_4->addWidget(pushButton_5);


        verticalLayout_2->addWidget(widget_4);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        comboBox_7 = new QComboBox(tab_2);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));

        verticalLayout_2->addWidget(comboBox_7);

        comboBox_8 = new QComboBox(tab_2);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        verticalLayout_2->addWidget(comboBox_8);

        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_5->addWidget(pushButton_6);


        verticalLayout_2->addWidget(widget_5);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        listView = new QListView(tab_2);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        widget = new QWidget(midi_device_settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(widget);


        retranslateUi(midi_device_settings);

        QMetaObject::connectSlotsByName(midi_device_settings);
    } // setupUi

    void retranslateUi(QDialog *midi_device_settings)
    {
        midi_device_settings->setWindowTitle(QApplication::translate("midi_device_settings", "Dialog", nullptr));
        label->setText(QApplication::translate("midi_device_settings", "Device 1[Input and Output]", nullptr));
        pushButton_3->setText(QApplication::translate("midi_device_settings", "Configure", nullptr));
        label_2->setText(QApplication::translate("midi_device_settings", "Device 2[Input and Output]", nullptr));
        pushButton_4->setText(QApplication::translate("midi_device_settings", "Configure", nullptr));
        label_3->setText(QApplication::translate("midi_device_settings", "Device 3[Input and Output]", nullptr));
        pushButton_5->setText(QApplication::translate("midi_device_settings", "Configure", nullptr));
        label_4->setText(QApplication::translate("midi_device_settings", "Device 4[Input and Output]", nullptr));
        pushButton_6->setText(QApplication::translate("midi_device_settings", "Configure", nullptr));
        label_5->setText(QApplication::translate("midi_device_settings", "Information about startup of MIDI devices", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("midi_device_settings", "MIDI\350\256\276\345\244\207", nullptr));
        pushButton->setText(QApplication::translate("midi_device_settings", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("midi_device_settings", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class midi_device_settings: public Ui_midi_device_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDI_DEVICE_SETTINGS_H
