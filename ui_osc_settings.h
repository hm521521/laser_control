/********************************************************************************
** Form generated from reading UI file 'osc_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSC_SETTINGS_H
#define UI_OSC_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_osc_settings
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *osc_settings)
    {
        if (osc_settings->objectName().isEmpty())
            osc_settings->setObjectName(QString::fromUtf8("osc_settings"));
        osc_settings->resize(399, 378);
        verticalLayout = new QVBoxLayout(osc_settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(osc_settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        spinBox = new QSpinBox(widget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_2->addWidget(spinBox);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_4->addWidget(checkBox_2);

        widget_4 = new QWidget(groupBox_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(172, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        spinBox_2 = new QSpinBox(widget_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_3->addWidget(spinBox_2);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);


        verticalLayout_4->addWidget(widget_4);

        widget_3 = new QWidget(groupBox_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout_4->addWidget(widget_3);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);


        verticalLayout_2->addWidget(groupBox_3);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        widget = new QWidget(osc_settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addWidget(widget);


        retranslateUi(osc_settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(osc_settings);
    } // setupUi

    void retranslateUi(QDialog *osc_settings)
    {
        osc_settings->setWindowTitle(QApplication::translate("osc_settings", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("osc_settings", "Input (OSC Server)", nullptr));
        checkBox->setText(QApplication::translate("osc_settings", "Enable receiving OSC messages", nullptr));
        label->setText(QApplication::translate("osc_settings", "Incoming port", nullptr));
        label_2->setText(QApplication::translate("osc_settings", "UDP", nullptr));
        groupBox_2->setTitle(QApplication::translate("osc_settings", "\350\276\223\345\207\272", nullptr));
        checkBox_2->setText(QApplication::translate("osc_settings", "Enable outgoing communication", nullptr));
        label_3->setText(QApplication::translate("osc_settings", "Outging port", nullptr));
        label_4->setText(QApplication::translate("osc_settings", "UDP", nullptr));
        label_5->setText(QApplication::translate("osc_settings", "Destination IP", nullptr));
        groupBox_3->setTitle(QApplication::translate("osc_settings", "Local PC Information", nullptr));
        label_6->setText(QApplication::translate("osc_settings", "Adapter 1:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("osc_settings", "\350\277\236\346\216\245", nullptr));
        pushButton->setText(QApplication::translate("osc_settings", "Monitor", nullptr));
        pushButton_2->setText(QApplication::translate("osc_settings", "\347\241\256\350\256\244", nullptr));
        pushButton_3->setText(QApplication::translate("osc_settings", " \345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class osc_settings: public Ui_osc_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSC_SETTINGS_H
