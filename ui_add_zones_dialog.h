/********************************************************************************
** Form generated from reading UI file 'add_zones_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ZONES_DIALOG_H
#define UI_ADD_ZONES_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            add_zones_dialog->setObjectName(QStringLiteral("add_zones_dialog"));
        add_zones_dialog->resize(456, 156);
        verticalLayout = new QVBoxLayout(add_zones_dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(add_zones_dialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(add_zones_dialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        OK_pushButton = new QPushButton(widget_2);
        OK_pushButton->setObjectName(QStringLiteral("OK_pushButton"));

        horizontalLayout_2->addWidget(OK_pushButton);

        cancel_pushButton = new QPushButton(widget_2);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));

        horizontalLayout_2->addWidget(cancel_pushButton);


        verticalLayout->addWidget(widget_2);


        retranslateUi(add_zones_dialog);

        QMetaObject::connectSlotsByName(add_zones_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_zones_dialog)
    {
        add_zones_dialog->setWindowTitle(QApplication::translate("add_zones_dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("add_zones_dialog", "New Projection Zone name", Q_NULLPTR));
        OK_pushButton->setText(QApplication::translate("add_zones_dialog", "OK", Q_NULLPTR));
        cancel_pushButton->setText(QApplication::translate("add_zones_dialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class add_zones_dialog: public Ui_add_zones_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ZONES_DIALOG_H
