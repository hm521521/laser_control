/********************************************************************************
** Form generated from reading UI file 'add_id_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ID_DIALOG_H
#define UI_ADD_ID_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add_id_dialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *add_id_dialog)
    {
        if (add_id_dialog->objectName().isEmpty())
            add_id_dialog->setObjectName(QString::fromUtf8("add_id_dialog"));
        add_id_dialog->resize(400, 300);
        label = new QLabel(add_id_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 70, 54, 12));
        lineEdit = new QLineEdit(add_id_dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 70, 231, 20));
        okButton = new QPushButton(add_id_dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(90, 160, 75, 23));
        cancelButton = new QPushButton(add_id_dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 160, 75, 23));

        retranslateUi(add_id_dialog);

        QMetaObject::connectSlotsByName(add_id_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_id_dialog)
    {
        add_id_dialog->setWindowTitle(QApplication::translate("add_id_dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("add_id_dialog", "New name", nullptr));
        okButton->setText(QApplication::translate("add_id_dialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("add_id_dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_id_dialog: public Ui_add_id_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ID_DIALOG_H
