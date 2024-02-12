/********************************************************************************
** Form generated from reading UI file 'dmax_output_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMAX_OUTPUT_DIALOG_H
#define UI_DMAX_OUTPUT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dmax_output_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButton *disabled_radioButton;
    QRadioButton *ArtNet_radioButton;
    QRadioButton *sACN_radioButton;

    void setupUi(QDialog *dmax_output_Dialog)
    {
        if (dmax_output_Dialog->objectName().isEmpty())
            dmax_output_Dialog->setObjectName(QString::fromUtf8("dmax_output_Dialog"));
        dmax_output_Dialog->resize(109, 84);
        verticalLayout = new QVBoxLayout(dmax_output_Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        disabled_radioButton = new QRadioButton(dmax_output_Dialog);
        disabled_radioButton->setObjectName(QString::fromUtf8("disabled_radioButton"));
        disabled_radioButton->setToolTipDuration(-1);

        verticalLayout->addWidget(disabled_radioButton);

        ArtNet_radioButton = new QRadioButton(dmax_output_Dialog);
        ArtNet_radioButton->setObjectName(QString::fromUtf8("ArtNet_radioButton"));

        verticalLayout->addWidget(ArtNet_radioButton);

        sACN_radioButton = new QRadioButton(dmax_output_Dialog);
        sACN_radioButton->setObjectName(QString::fromUtf8("sACN_radioButton"));

        verticalLayout->addWidget(sACN_radioButton);


        retranslateUi(dmax_output_Dialog);

        QMetaObject::connectSlotsByName(dmax_output_Dialog);
    } // setupUi

    void retranslateUi(QDialog *dmax_output_Dialog)
    {
        dmax_output_Dialog->setWindowTitle(QApplication::translate("dmax_output_Dialog", "dmax_output_dialog", nullptr));
        disabled_radioButton->setText(QApplication::translate("dmax_output_Dialog", "Disabled", nullptr));
        ArtNet_radioButton->setText(QApplication::translate("dmax_output_Dialog", "Art-Net", nullptr));
        sACN_radioButton->setText(QApplication::translate("dmax_output_Dialog", "sACN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dmax_output_Dialog: public Ui_dmax_output_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAX_OUTPUT_DIALOG_H
