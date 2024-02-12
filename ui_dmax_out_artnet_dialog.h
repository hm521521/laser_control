/********************************************************************************
** Form generated from reading UI file 'dmax_out_artnet_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMAX_OUT_ARTNET_DIALOG_H
#define UI_DMAX_OUT_ARTNET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dmax_out_artnet_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpinBox *subnet_spinBox;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *universe_spinBox_2;
    QLabel *label_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *sim_universe_spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dmax_out_artnet_Dialog)
    {
        if (dmax_out_artnet_Dialog->objectName().isEmpty())
            dmax_out_artnet_Dialog->setObjectName(QString::fromUtf8("dmax_out_artnet_Dialog"));
        dmax_out_artnet_Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(dmax_out_artnet_Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(dmax_out_artnet_Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        widget = new QWidget(dmax_out_artnet_Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        subnet_spinBox = new QSpinBox(widget);
        subnet_spinBox->setObjectName(QString::fromUtf8("subnet_spinBox"));

        horizontalLayout_2->addWidget(subnet_spinBox);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(dmax_out_artnet_Dialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        universe_spinBox_2 = new QSpinBox(widget_2);
        universe_spinBox_2->setObjectName(QString::fromUtf8("universe_spinBox_2"));

        horizontalLayout->addWidget(universe_spinBox_2);


        verticalLayout->addWidget(widget_2);

        label_2 = new QLabel(dmax_out_artnet_Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        widget_3 = new QWidget(dmax_out_artnet_Dialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        sim_universe_spinBox = new QSpinBox(widget_3);
        sim_universe_spinBox->setObjectName(QString::fromUtf8("sim_universe_spinBox"));
        sim_universe_spinBox->setMaximum(255);

        horizontalLayout_3->addWidget(sim_universe_spinBox);


        verticalLayout->addWidget(widget_3);

        buttonBox = new QDialogButtonBox(dmax_out_artnet_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dmax_out_artnet_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), dmax_out_artnet_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dmax_out_artnet_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(dmax_out_artnet_Dialog);
    } // setupUi

    void retranslateUi(QDialog *dmax_out_artnet_Dialog)
    {
        dmax_out_artnet_Dialog->setWindowTitle(QApplication::translate("dmax_out_artnet_Dialog", "dmax_out_artnet_Dialog", nullptr));
        label->setText(QApplication::translate("dmax_out_artnet_Dialog", "Standard addressing[subnet,universe]", nullptr));
        label_3->setText(QApplication::translate("dmax_out_artnet_Dialog", "Subnet", nullptr));
        label_4->setText(QApplication::translate("dmax_out_artnet_Dialog", "Universe", nullptr));
        label_2->setText(QApplication::translate("dmax_out_artnet_Dialog", "Simplified addressing[0..255]", nullptr));
        label_5->setText(QApplication::translate("dmax_out_artnet_Dialog", "Universe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dmax_out_artnet_Dialog: public Ui_dmax_out_artnet_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAX_OUT_ARTNET_DIALOG_H
