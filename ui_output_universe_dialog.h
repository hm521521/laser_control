/********************************************************************************
** Form generated from reading UI file 'output_universe_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUT_UNIVERSE_DIALOG_H
#define UI_OUTPUT_UNIVERSE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_output_universe_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *output_universe_Dialog)
    {
        if (output_universe_Dialog->objectName().isEmpty())
            output_universe_Dialog->setObjectName(QString::fromUtf8("output_universe_Dialog"));
        output_universe_Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(output_universe_Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(output_universe_Dialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(output_universe_Dialog);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(output_universe_Dialog);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(output_universe_Dialog);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        buttonBox = new QDialogButtonBox(output_universe_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(output_universe_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), output_universe_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), output_universe_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(output_universe_Dialog);
    } // setupUi

    void retranslateUi(QDialog *output_universe_Dialog)
    {
        output_universe_Dialog->setWindowTitle(QApplication::translate("output_universe_Dialog", "output_universe_Dialog", nullptr));
        radioButton->setText(QApplication::translate("output_universe_Dialog", "universe_1", nullptr));
        radioButton_2->setText(QApplication::translate("output_universe_Dialog", "universe_2", nullptr));
        radioButton_3->setText(QApplication::translate("output_universe_Dialog", "universe_3", nullptr));
        radioButton_4->setText(QApplication::translate("output_universe_Dialog", "universe_4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class output_universe_Dialog: public Ui_output_universe_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_UNIVERSE_DIALOG_H
