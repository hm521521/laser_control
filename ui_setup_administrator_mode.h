/********************************************************************************
** Form generated from reading UI file 'setup_administrator_mode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_ADMINISTRATOR_MODE_H
#define UI_SETUP_ADMINISTRATOR_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setup_Administrator_mode
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *setup_Administrator_mode)
    {
        if (setup_Administrator_mode->objectName().isEmpty())
            setup_Administrator_mode->setObjectName(QString::fromUtf8("setup_Administrator_mode"));
        setup_Administrator_mode->resize(457, 437);
        verticalLayout = new QVBoxLayout(setup_Administrator_mode);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(setup_Administrator_mode);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);

        widget = new QWidget(setup_Administrator_mode);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(256, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(widget);


        retranslateUi(setup_Administrator_mode);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(setup_Administrator_mode);
    } // setupUi

    void retranslateUi(QDialog *setup_Administrator_mode)
    {
        setup_Administrator_mode->setWindowTitle(QApplication::translate("setup_Administrator_mode", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("setup_Administrator_mode", "\345\205\266\344\273\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("setup_Administrator_mode", "Main menu", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("setup_Administrator_mode", "Tabs on the right", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("setup_Administrator_mode", "QuickTools", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("setup_Administrator_mode", "Password and startup", nullptr));
        pushButton->setText(QApplication::translate("setup_Administrator_mode", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("setup_Administrator_mode", " \345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setup_Administrator_mode: public Ui_setup_Administrator_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_ADMINISTRATOR_MODE_H
