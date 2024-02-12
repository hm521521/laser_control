/********************************************************************************
** Form generated from reading UI file 'delete_zone_id_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_ZONE_ID_DIALOG_H
#define UI_DELETE_ZONE_ID_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_delete_zone_id_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *delete_zone_id_Dialog)
    {
        if (delete_zone_id_Dialog->objectName().isEmpty())
            delete_zone_id_Dialog->setObjectName(QString::fromUtf8("delete_zone_id_Dialog"));
        delete_zone_id_Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(delete_zone_id_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(delete_zone_id_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 90, 261, 16));

        retranslateUi(delete_zone_id_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), delete_zone_id_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), delete_zone_id_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(delete_zone_id_Dialog);
    } // setupUi

    void retranslateUi(QDialog *delete_zone_id_Dialog)
    {
        delete_zone_id_Dialog->setWindowTitle(QApplication::translate("delete_zone_id_Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("delete_zone_id_Dialog", "\345\210\240\351\231\244\345\275\223\345\211\215\346\212\225\345\275\261\345\214\272\345\237\237\345\220\215\347\247\260\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_zone_id_Dialog: public Ui_delete_zone_id_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_ZONE_ID_DIALOG_H
