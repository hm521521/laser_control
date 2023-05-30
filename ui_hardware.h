/********************************************************************************
** Form generated from reading UI file 'hardware.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARDWARE_H
#define UI_HARDWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <hardware.h>

QT_BEGIN_NAMESPACE

class Ui_hardware
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Plus_Button;
    QPushButton *Up_Button;
    QPushButton *Down_Button;
    QPushButton *Delete_button;
    QPushButton *Big_Icon;
    QPushButton *Small_Icon;
    QPushButton *Refresh_Button;
    QSpacerItem *horizontalSpacer_2;
    hardware_table *tableView;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *hardware)
    {
        if (hardware->objectName().isEmpty())
            hardware->setObjectName(QStringLiteral("hardware"));
        hardware->resize(758, 508);
        centralwidget = new QWidget(hardware);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Plus_Button = new QPushButton(widget);
        Plus_Button->setObjectName(QStringLiteral("Plus_Button"));

        horizontalLayout_2->addWidget(Plus_Button);

        Up_Button = new QPushButton(widget);
        Up_Button->setObjectName(QStringLiteral("Up_Button"));

        horizontalLayout_2->addWidget(Up_Button);

        Down_Button = new QPushButton(widget);
        Down_Button->setObjectName(QStringLiteral("Down_Button"));

        horizontalLayout_2->addWidget(Down_Button);

        Delete_button = new QPushButton(widget);
        Delete_button->setObjectName(QStringLiteral("Delete_button"));

        horizontalLayout_2->addWidget(Delete_button);

        Big_Icon = new QPushButton(widget);
        Big_Icon->setObjectName(QStringLiteral("Big_Icon"));

        horizontalLayout_2->addWidget(Big_Icon);

        Small_Icon = new QPushButton(widget);
        Small_Icon->setObjectName(QStringLiteral("Small_Icon"));

        horizontalLayout_2->addWidget(Small_Icon);


        horizontalLayout_3->addWidget(widget);

        Refresh_Button = new QPushButton(widget_3);
        Refresh_Button->setObjectName(QStringLiteral("Refresh_Button"));

        horizontalLayout_3->addWidget(Refresh_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);

        tableView = new hardware_table(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(widget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);


        verticalLayout->addWidget(widget_2);

        hardware->setCentralWidget(centralwidget);
        menubar = new QMenuBar(hardware);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 758, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        hardware->setMenuBar(menubar);
        statusbar = new QStatusBar(hardware);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        hardware->setStatusBar(statusbar);
        toolBar = new QToolBar(hardware);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        hardware->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());

        retranslateUi(hardware);

        QMetaObject::connectSlotsByName(hardware);
    } // setupUi

    void retranslateUi(QMainWindow *hardware)
    {
        hardware->setWindowTitle(QApplication::translate("hardware", "MainWindow", Q_NULLPTR));
        Plus_Button->setText(QApplication::translate("hardware", "+", Q_NULLPTR));
        Up_Button->setText(QApplication::translate("hardware", "\342\206\221", Q_NULLPTR));
        Down_Button->setText(QApplication::translate("hardware", "\342\206\223", Q_NULLPTR));
        Delete_button->setText(QApplication::translate("hardware", "\303\227", Q_NULLPTR));
        Big_Icon->setText(QApplication::translate("hardware", "\343\200\223", Q_NULLPTR));
        Small_Icon->setText(QApplication::translate("hardware", "\342\230\260", Q_NULLPTR));
        Refresh_Button->setText(QApplication::translate("hardware", "Refresh list and reset controllers", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("hardware", "PushButton", Q_NULLPTR));
        menu->setTitle(QApplication::translate("hardware", "\347\241\254\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("hardware", "\345\210\206\347\261\273", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("hardware", "\350\247\206\345\233\276", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("hardware", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hardware: public Ui_hardware {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARDWARE_H
