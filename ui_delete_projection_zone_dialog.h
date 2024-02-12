/********************************************************************************
** Form generated from reading UI file 'delete_projection_zone_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_PROJECTION_ZONE_DIALOG_H
#define UI_DELETE_PROJECTION_ZONE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_delete_projection_zone_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *delete_projection_zone_Dialog)
    {
        if (delete_projection_zone_Dialog->objectName().isEmpty())
            delete_projection_zone_Dialog->setObjectName(QString::fromUtf8("delete_projection_zone_Dialog"));
        delete_projection_zone_Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(delete_projection_zone_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 220, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(delete_projection_zone_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 90, 211, 31));

        retranslateUi(delete_projection_zone_Dialog);

        QMetaObject::connectSlotsByName(delete_projection_zone_Dialog);
    } // setupUi

    void retranslateUi(QDialog *delete_projection_zone_Dialog)
    {
        delete_projection_zone_Dialog->setWindowTitle(QApplication::translate("delete_projection_zone_Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("delete_projection_zone_Dialog", "\345\210\240\351\231\244\345\275\223\345\211\215\346\212\225\345\275\261\345\214\272\345\237\237\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_projection_zone_Dialog: public Ui_delete_projection_zone_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_PROJECTION_ZONE_DIALOG_H
