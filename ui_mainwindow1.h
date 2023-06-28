/********************************************************************************
** Form generated from reading UI file 'mainwindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW1_H
#define UI_MAINWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <project_panel.h>
#include <test_patterns.h>
#include "output_panel.h"
#include "scene_tool_box.h"
#include "toggle_button.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow1
{
public:
    QAction *hardware;
    QAction *laser_setting;
    QAction *projection_zones;
    QAction *new_workspace;
    QAction *open_workspace;
    QAction *picture_tracer;
    QAction *publicize;
    QAction *test_patterns;
    QAction *DMX_ArtNet_Settings;
    QAction *actionDMX_Monitor;
    QAction *actionDMX_IN_State_Monitor;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    toggle_button *pushButton_grid;
    toggle_button *pushButton_timeline;
    toggle_button *pushButton_playlist;
    toggle_button *play_button;
    toggle_button *output_button;
    QStackedWidget *stackedWidget_2;
    QWidget *page_13;
    QHBoxLayout *horizontalLayout_7;
    Scene_Tool_Box *m_scenes_book;
    QWidget *page_14;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_15;
    Scene_Stack *m_scenes_stack;
    QWidget *page_16;
    QWidget *page_17;
    QWidget *page_18;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    project_panel *project_panel_view;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QTabWidget *quick_tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    Scene_Tool_Box *quick_scenes_book;
    QWidget *page_3;
    QWidget *page_4;
    Scene_Stack *quick_scenes_stack;
    QWidget *page;
    QWidget *page_2;
    QWidget *tab_2;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    output_panel *display_view;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_5;
    QToolBox *toolBox;
    QWidget *page_5;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *doubleSpinBox;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QCheckBox *checkBox;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QPushButton *pushButton_4;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButton_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QSpacerItem *verticalSpacer;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_7;
    my_list_view *trans_listView;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QWidget *tab_4;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuDMX;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow1)
    {
        if (MainWindow1->objectName().isEmpty())
            MainWindow1->setObjectName(QString::fromUtf8("MainWindow1"));
        MainWindow1->resize(1010, 687);
        MainWindow1->setMinimumSize(QSize(0, 0));
        hardware = new QAction(MainWindow1);
        hardware->setObjectName(QString::fromUtf8("hardware"));
        hardware->setCheckable(false);
        laser_setting = new QAction(MainWindow1);
        laser_setting->setObjectName(QString::fromUtf8("laser_setting"));
        laser_setting->setCheckable(false);
        projection_zones = new QAction(MainWindow1);
        projection_zones->setObjectName(QString::fromUtf8("projection_zones"));
        projection_zones->setCheckable(false);
        new_workspace = new QAction(MainWindow1);
        new_workspace->setObjectName(QString::fromUtf8("new_workspace"));
        new_workspace->setCheckable(false);
        open_workspace = new QAction(MainWindow1);
        open_workspace->setObjectName(QString::fromUtf8("open_workspace"));
        open_workspace->setCheckable(false);
        picture_tracer = new QAction(MainWindow1);
        picture_tracer->setObjectName(QString::fromUtf8("picture_tracer"));
        publicize = new QAction(MainWindow1);
        publicize->setObjectName(QString::fromUtf8("publicize"));
        test_patterns = new QAction(MainWindow1);
        test_patterns->setObjectName(QString::fromUtf8("test_patterns"));
        DMX_ArtNet_Settings = new QAction(MainWindow1);
        DMX_ArtNet_Settings->setObjectName(QString::fromUtf8("DMX_ArtNet_Settings"));
        actionDMX_Monitor = new QAction(MainWindow1);
        actionDMX_Monitor->setObjectName(QString::fromUtf8("actionDMX_Monitor"));
        actionDMX_IN_State_Monitor = new QAction(MainWindow1);
        actionDMX_IN_State_Monitor->setObjectName(QString::fromUtf8("actionDMX_IN_State_Monitor"));
        centralwidget = new QWidget(MainWindow1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_grid = new toggle_button(widget_3);
        pushButton_grid->setObjectName(QString::fromUtf8("pushButton_grid"));

        horizontalLayout_4->addWidget(pushButton_grid);

        pushButton_timeline = new toggle_button(widget_3);
        pushButton_timeline->setObjectName(QString::fromUtf8("pushButton_timeline"));

        horizontalLayout_4->addWidget(pushButton_timeline);

        pushButton_playlist = new toggle_button(widget_3);
        pushButton_playlist->setObjectName(QString::fromUtf8("pushButton_playlist"));

        horizontalLayout_4->addWidget(pushButton_playlist);

        play_button = new toggle_button(widget_3);
        play_button->setObjectName(QString::fromUtf8("play_button"));

        horizontalLayout_4->addWidget(play_button);

        output_button = new toggle_button(widget_3);
        output_button->setObjectName(QString::fromUtf8("output_button"));

        horizontalLayout_4->addWidget(output_button);


        verticalLayout_3->addWidget(widget_3);

        stackedWidget_2 = new QStackedWidget(widget);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setMinimumSize(QSize(700, 350));
        stackedWidget_2->setMaximumSize(QSize(16777215, 16777215));
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        horizontalLayout_7 = new QHBoxLayout(page_13);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        m_scenes_book = new Scene_Tool_Box(page_13);
        m_scenes_book->setObjectName(QString::fromUtf8("m_scenes_book"));
        m_scenes_book->setMaximumSize(QSize(100, 16777215));
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        page_14->setGeometry(QRect(0, 0, 100, 280));
        verticalLayout_8 = new QVBoxLayout(page_14);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer_2 = new QSpacerItem(20, 259, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        m_scenes_book->addItem(page_14, QString::fromUtf8("Page 1"));
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        page_15->setGeometry(QRect(0, 0, 100, 280));
        m_scenes_book->addItem(page_15, QString::fromUtf8("Page 2"));

        horizontalLayout_7->addWidget(m_scenes_book);

        m_scenes_stack = new Scene_Stack(page_13);
        m_scenes_stack->setObjectName(QString::fromUtf8("m_scenes_stack"));
        m_scenes_stack->setMinimumSize(QSize(0, 0));
        page_16 = new QWidget();
        page_16->setObjectName(QString::fromUtf8("page_16"));
        m_scenes_stack->addWidget(page_16);
        page_17 = new QWidget();
        page_17->setObjectName(QString::fromUtf8("page_17"));
        m_scenes_stack->addWidget(page_17);

        horizontalLayout_7->addWidget(m_scenes_stack);

        stackedWidget_2->addWidget(page_13);
        page_18 = new QWidget();
        page_18->setObjectName(QString::fromUtf8("page_18"));
        verticalLayout = new QVBoxLayout(page_18);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(page_18);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        project_panel_view = new project_panel(widget_2);
        project_panel_view->setObjectName(QString::fromUtf8("project_panel_view"));

        verticalLayout_4->addWidget(project_panel_view);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(widget_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(713, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(widget_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(widget_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_4->addWidget(widget_7);


        verticalLayout->addWidget(widget_2);

        stackedWidget_2->addWidget(page_18);

        verticalLayout_3->addWidget(stackedWidget_2);

        quick_tabWidget = new QTabWidget(widget);
        quick_tabWidget->setObjectName(QString::fromUtf8("quick_tabWidget"));
        quick_tabWidget->setMinimumSize(QSize(0, 150));
        quick_tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        quick_scenes_book = new Scene_Tool_Box(tab);
        quick_scenes_book->setObjectName(QString::fromUtf8("quick_scenes_book"));
        quick_scenes_book->setMaximumSize(QSize(68, 16777215));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 68, 108));
        quick_scenes_book->addItem(page_3, QString::fromUtf8("Page 1"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 68, 108));
        quick_scenes_book->addItem(page_4, QString::fromUtf8("Page 2"));

        horizontalLayout_3->addWidget(quick_scenes_book);

        quick_scenes_stack = new Scene_Stack(tab);
        quick_scenes_stack->setObjectName(QString::fromUtf8("quick_scenes_stack"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        quick_scenes_stack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        quick_scenes_stack->addWidget(page_2);

        horizontalLayout_3->addWidget(quick_scenes_stack);

        quick_tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        quick_tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(quick_tabWidget);


        horizontalLayout->addWidget(widget);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        display_view = new output_panel(widget_6);
        display_view->setObjectName(QString::fromUtf8("display_view"));
        display_view->setMinimumSize(QSize(250, 250));
        display_view->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(display_view);

        tabWidget = new QTabWidget(widget_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 350));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_5 = new QHBoxLayout(tab_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        toolBox = new QToolBox(tab_3);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 176, 279));
        toolBox->addItem(page_5, QString::fromUtf8("\350\256\276\347\275\256\351\231\220\345\210\266"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 257, 352));
        verticalLayout_5 = new QVBoxLayout(page_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(page_6);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        widget_4 = new QWidget(page_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(widget_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        doubleSpinBox = new QDoubleSpinBox(widget_8);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        horizontalLayout_9->addWidget(doubleSpinBox);


        verticalLayout_6->addWidget(widget_8);

        widget_9 = new QWidget(widget_4);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_6 = new QHBoxLayout(widget_9);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(widget_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        doubleSpinBox_2 = new QDoubleSpinBox(widget_9);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        horizontalLayout_6->addWidget(doubleSpinBox_2);


        verticalLayout_6->addWidget(widget_9);

        checkBox = new QCheckBox(widget_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_6->addWidget(checkBox);

        widget_10 = new QWidget(widget_4);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 0));
        horizontalLayout_10 = new QHBoxLayout(widget_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_4 = new QLabel(widget_10);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        doubleSpinBox_3 = new QDoubleSpinBox(widget_10);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        horizontalLayout_10->addWidget(doubleSpinBox_3);

        pushButton_4 = new QPushButton(widget_10);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_10->addWidget(pushButton_4);


        verticalLayout_6->addWidget(widget_10);

        widget_11 = new QWidget(widget_4);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_11 = new QHBoxLayout(widget_11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_5 = new QLabel(widget_11);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(42, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        doubleSpinBox_4 = new QDoubleSpinBox(widget_11);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        horizontalLayout_11->addWidget(doubleSpinBox_4);

        pushButton_5 = new QPushButton(widget_11);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_11->addWidget(pushButton_5);


        verticalLayout_6->addWidget(widget_11);


        verticalLayout_5->addWidget(widget_4);

        checkBox_3 = new QCheckBox(page_6);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout_5->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(page_6);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout_5->addWidget(checkBox_4);

        checkBox_2 = new QCheckBox(page_6);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_5->addWidget(checkBox_2);

        checkBox_5 = new QCheckBox(page_6);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        verticalLayout_5->addWidget(checkBox_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        toolBox->addItem(page_6, QString::fromUtf8("Cue appearance"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        verticalLayout_7 = new QVBoxLayout(page_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        trans_listView = new my_list_view(page_7);
        trans_listView->setObjectName(QString::fromUtf8("trans_listView"));

        verticalLayout_7->addWidget(trans_listView);

        widget_12 = new QWidget(page_7);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_12 = new QHBoxLayout(widget_12);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_6 = new QLabel(widget_12);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_12->addWidget(label_6);

        doubleSpinBox_5 = new QDoubleSpinBox(widget_12);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        horizontalLayout_12->addWidget(doubleSpinBox_5);

        pushButton_7 = new QPushButton(widget_12);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_12->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(widget_12);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_12->addWidget(pushButton_6);


        verticalLayout_7->addWidget(widget_12);

        toolBox->addItem(page_7, QString::fromUtf8("\350\277\207\346\270\241"));

        horizontalLayout_5->addWidget(toolBox);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_2->addWidget(tabWidget);


        horizontalLayout->addWidget(widget_6);

        MainWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1010, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuDMX = new QMenu(menu);
        menuDMX->setObjectName(QString::fromUtf8("menuDMX"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow1->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(hardware);
        menu->addAction(laser_setting);
        menu->addAction(projection_zones);
        menu->addAction(test_patterns);
        menu->addAction(menuDMX->menuAction());
        menuDMX->addAction(DMX_ArtNet_Settings);
        menuDMX->addAction(actionDMX_Monitor);
        menuDMX->addAction(actionDMX_IN_State_Monitor);
        menu_2->addAction(new_workspace);
        menu_2->addAction(open_workspace);
        menu_3->addAction(picture_tracer);
        menu_3->addAction(publicize);

        retranslateUi(MainWindow1);

        play_button->setDefault(false);
        stackedWidget_2->setCurrentIndex(0);
        m_scenes_book->setCurrentIndex(0);
        m_scenes_stack->setCurrentIndex(1);
        quick_tabWidget->setCurrentIndex(0);
        quick_scenes_book->setCurrentIndex(0);
        quick_scenes_stack->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow1)
    {
        MainWindow1->setWindowTitle(QApplication::translate("MainWindow1", "MainWindow", nullptr));
        hardware->setText(QApplication::translate("MainWindow1", "\346\277\200\345\205\211\347\201\257\344\270\216\346\216\247\345\210\266\345\231\250\347\241\254\344\273\266", nullptr));
        laser_setting->setText(QApplication::translate("MainWindow1", "\346\277\200\345\205\211\347\201\257\350\256\276\347\275\256", nullptr));
        projection_zones->setText(QApplication::translate("MainWindow1", "\346\212\225\345\275\261\345\214\272\345\237\237", nullptr));
        new_workspace->setText(QApplication::translate("MainWindow1", "\346\226\260\345\273\272\345\267\245\344\275\234\345\214\272", nullptr));
        open_workspace->setText(QApplication::translate("MainWindow1", "\346\211\223\345\274\200\345\267\245\344\275\234\345\214\272", nullptr));
        picture_tracer->setText(QApplication::translate("MainWindow1", "\345\233\276\347\211\207\347\244\272\350\270\252\345\211\202", nullptr));
        publicize->setText(QApplication::translate("MainWindow1", "\345\256\243\344\274\240\350\257\255", nullptr));
        test_patterns->setText(QApplication::translate("MainWindow1", "\346\265\213\350\257\225\346\250\241\345\274\217", nullptr));
        DMX_ArtNet_Settings->setText(QApplication::translate("MainWindow1", "DMX/ArtNet Settings", nullptr));
        actionDMX_Monitor->setText(QApplication::translate("MainWindow1", "DMX Monitor", nullptr));
        actionDMX_IN_State_Monitor->setText(QApplication::translate("MainWindow1", "DMX IN State Monitor", nullptr));
        pushButton_grid->setText(QApplication::translate("MainWindow1", "\347\275\221\346\240\274", nullptr));
        pushButton_timeline->setText(QApplication::translate("MainWindow1", "\346\227\266\351\227\264\347\272\277", nullptr));
        pushButton_playlist->setText(QApplication::translate("MainWindow1", " \346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        play_button->setText(QApplication::translate("MainWindow1", " \346\222\255\346\224\276", nullptr));
        output_button->setText(QApplication::translate("MainWindow1", "  \350\276\223\345\207\272\345\210\260\346\277\200\345\205\211", nullptr));
        m_scenes_book->setItemText(m_scenes_book->indexOf(page_14), QApplication::translate("MainWindow1", "Page 1", nullptr));
        m_scenes_book->setItemText(m_scenes_book->indexOf(page_15), QApplication::translate("MainWindow1", "Page 2", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow1", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow1", "PushButton", nullptr));
        pushButton->setText(QApplication::translate("MainWindow1", "PushButton", nullptr));
        quick_scenes_book->setItemText(quick_scenes_book->indexOf(page_3), QApplication::translate("MainWindow1", "Page 1", nullptr));
        quick_scenes_book->setItemText(quick_scenes_book->indexOf(page_4), QApplication::translate("MainWindow1", "Page 2", nullptr));
        quick_tabWidget->setTabText(quick_tabWidget->indexOf(tab), QApplication::translate("MainWindow1", "Tab 1", nullptr));
        quick_tabWidget->setTabText(quick_tabWidget->indexOf(tab_2), QApplication::translate("MainWindow1", "Tab 2", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("MainWindow1", "\350\256\276\347\275\256\351\231\220\345\210\266", nullptr));
        label->setText(QApplication::translate("MainWindow1", "\350\275\257\346\232\202\345\201\234\346\214\201\347\273\255\346\227\266\351\227\264", nullptr));
        label_2->setText(QApplication::translate("MainWindow1", "\350\212\202\347\233\256\346\240\274\345\274\200\345\247\213", nullptr));
        label_3->setText(QApplication::translate("MainWindow1", "\350\212\202\347\233\256\346\240\274\347\273\223\346\235\237", nullptr));
        checkBox->setText(QApplication::translate("MainWindow1", "CheckBox", nullptr));
        label_4->setText(QApplication::translate("MainWindow1", "\350\212\202\347\233\256\346\240\274\345\274\200\345\247\213", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow1", "\316\243", nullptr));
        label_5->setText(QApplication::translate("MainWindow1", " \350\212\202\347\233\256\346\240\274\347\273\223\346\235\237", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow1", "\316\243", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow1", "\345\234\250\351\227\252\347\203\201\346\250\241\345\274\217\344\270\255\345\220\257\347\224\250\345\274\200\345\247\213\346\225\210\346\236\234", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow1", "\345\234\250\351\227\252\347\203\201\346\250\241\345\274\217\344\270\255\344\275\277\347\224\250\345\256\214\346\210\220\346\225\210\346\236\234", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow1", "Use Start effect in Flash Solo mode", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow1", "Use Finish effect in Flash Solo mode", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("MainWindow1", "Cue appearance", nullptr));
        label_6->setText(QApplication::translate("MainWindow1", "\346\214\201\347\273\255", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow1", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow1", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("MainWindow1", "\350\277\207\346\270\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow1", "Dynamics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow1", "Tab 2", nullptr));
        menu->setTitle(QApplication::translate("MainWindow1", "\350\256\276\347\275\256", nullptr));
        menuDMX->setTitle(QApplication::translate("MainWindow1", "DMX", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow1", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow1", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1: public Ui_MainWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW1_H
