/********************************************************************************
** Form generated from reading UI file 'add_zones_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ZONES_DIALOG_H
#define UI_ADD_ZONES_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_zones_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QDialog *add_zones_dialog)
    {
        if (add_zones_dialog->objectName().isEmpty())
            add_zones_dialog->setObjectName(QString::fromUtf8("add_zones_dialog"));
        add_zones_dialog->resize(456, 156);
        verticalLayout = new QVBoxLayout(add_zones_dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(add_zones_dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(add_zones_dialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        OK_pushButton = new QPushButton(widget_2);
        OK_pushButton->setObjectName(QString::fromUtf8("OK_pushButton"));

        horizontalLayout_2->addWidget(OK_pushButton);

        cancel_pushButton = new QPushButton(widget_2);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout_2->addWidget(cancel_pushButton);


        verticalLayout->addWidget(widget_2);


        retranslateUi(add_zones_dialog);

        QMetaObject::connectSlotsByName(add_zones_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_zones_dialog)
    {
        add_zones_dialog->setWindowTitle(QApplication::translate("add_zones_dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("add_zones_dialog", "New Projection Zone name", nullptr));
        OK_pushButton->setText(QApplication::translate("add_zones_dialog", "OK", nullptr));
        cancel_pushButton->setText(QApplication::translate("add_zones_dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_zones_dialog: public Ui_add_zones_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ZONES_DIALOG_H
