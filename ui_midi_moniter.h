/********************************************************************************
** Form generated from reading UI file 'midi_moniter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDI_MONITER_H
#define UI_MIDI_MONITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_midi_moniter
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_2;

    void setupUi(QDialog *midi_moniter)
    {
        if (midi_moniter->objectName().isEmpty())
            midi_moniter->setObjectName(QString::fromUtf8("midi_moniter"));
        midi_moniter->resize(347, 322);
        horizontalLayout = new QHBoxLayout(midi_moniter);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(midi_moniter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(midi_moniter);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(midi_moniter);
    } // setupUi

    void retranslateUi(QDialog *midi_moniter)
    {
        midi_moniter->setWindowTitle(QApplication::translate("midi_moniter", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("midi_moniter", "MIDI IN", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("midi_moniter", "MIDI OUT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("midi_moniter", "MIDI IN-OUT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("midi_moniter", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class midi_moniter: public Ui_midi_moniter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDI_MONITER_H
