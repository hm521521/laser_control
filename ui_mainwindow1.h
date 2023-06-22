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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <project_panel.h>
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
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_8;
    Scene_Tool_Box *m_scenes_book;
    QWidget *page_14;
    QWidget *page_15;
    Scene_Stack *m_scenes_stack;
    QWidget *page_16;
    QWidget *page_17;
    QGridLayout *gridLayout_3;
    QGraphicsView *graphicsView_87;
    QGraphicsView *graphicsView_94;
    QGraphicsView *graphicsView_90;
    QGraphicsView *graphicsView_109;
    QGraphicsView *graphicsView_118;
    QGraphicsView *graphicsView_115;
    QGraphicsView *graphicsView_105;
    QGraphicsView *graphicsView_88;
    QGraphicsView *graphicsView_108;
    QGraphicsView *graphicsView_98;
    QGraphicsView *graphicsView_112;
    QGraphicsView *graphicsView_83;
    QGraphicsView *graphicsView_100;
    QGraphicsView *graphicsView_96;
    QGraphicsView *graphicsView_92;
    QGraphicsView *graphicsView_97;
    QGraphicsView *graphicsView_93;
    QGraphicsView *graphicsView_89;
    QGraphicsView *graphicsView_103;
    QGraphicsView *graphicsView_104;
    QGraphicsView *graphicsView_117;
    QGraphicsView *graphicsView_107;
    QGraphicsView *graphicsView_120;
    QGraphicsView *graphicsView_110;
    QGraphicsView *graphicsView_86;
    QGraphicsView *graphicsView_81;
    QGraphicsView *graphicsView_95;
    QGraphicsView *graphicsView_102;
    QGraphicsView *graphicsView_119;
    QGraphicsView *graphicsView_116;
    QGraphicsView *graphicsView_91;
    QGraphicsView *graphicsView_106;
    QGraphicsView *graphicsView_111;
    QGraphicsView *graphicsView_84;
    QGraphicsView *graphicsView_113;
    QGraphicsView *graphicsView_99;
    QGraphicsView *graphicsView_114;
    QGraphicsView *graphicsView_101;
    QGraphicsView *graphicsView_85;
    QGraphicsView *graphicsView_82;
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
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow1)
    {
        if (MainWindow1->objectName().isEmpty())
            MainWindow1->setObjectName(QString::fromUtf8("MainWindow1"));
        MainWindow1->resize(1370, 1035);
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
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        horizontalLayout_7 = new QHBoxLayout(page_13);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        widget_5 = new QWidget(page_13);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(992, 583));
        horizontalLayout_8 = new QHBoxLayout(widget_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        m_scenes_book = new Scene_Tool_Box(widget_5);
        m_scenes_book->setObjectName(QString::fromUtf8("m_scenes_book"));
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        page_14->setGeometry(QRect(0, 0, 98, 28));
        m_scenes_book->addItem(page_14, QString::fromUtf8("Page 1"));
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        page_15->setGeometry(QRect(0, 0, 98, 28));
        m_scenes_book->addItem(page_15, QString::fromUtf8("Page 2"));

        horizontalLayout_8->addWidget(m_scenes_book);

        m_scenes_stack = new Scene_Stack(widget_5);
        m_scenes_stack->setObjectName(QString::fromUtf8("m_scenes_stack"));
        m_scenes_stack->setMinimumSize(QSize(700, 521));
        page_16 = new QWidget();
        page_16->setObjectName(QString::fromUtf8("page_16"));
        m_scenes_stack->addWidget(page_16);
        page_17 = new QWidget();
        page_17->setObjectName(QString::fromUtf8("page_17"));
        gridLayout_3 = new QGridLayout(page_17);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        graphicsView_87 = new QGraphicsView(page_17);
        graphicsView_87->setObjectName(QString::fromUtf8("graphicsView_87"));
        graphicsView_87->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_87, 0, 6, 1, 1);

        graphicsView_94 = new QGraphicsView(page_17);
        graphicsView_94->setObjectName(QString::fromUtf8("graphicsView_94"));
        graphicsView_94->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_94, 1, 5, 1, 1);

        graphicsView_90 = new QGraphicsView(page_17);
        graphicsView_90->setObjectName(QString::fromUtf8("graphicsView_90"));
        graphicsView_90->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_90, 1, 1, 1, 1);

        graphicsView_109 = new QGraphicsView(page_17);
        graphicsView_109->setObjectName(QString::fromUtf8("graphicsView_109"));
        graphicsView_109->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_109, 3, 4, 1, 1);

        graphicsView_118 = new QGraphicsView(page_17);
        graphicsView_118->setObjectName(QString::fromUtf8("graphicsView_118"));
        graphicsView_118->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_118, 4, 5, 1, 1);

        graphicsView_115 = new QGraphicsView(page_17);
        graphicsView_115->setObjectName(QString::fromUtf8("graphicsView_115"));
        graphicsView_115->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_115, 4, 2, 1, 1);

        graphicsView_105 = new QGraphicsView(page_17);
        graphicsView_105->setObjectName(QString::fromUtf8("graphicsView_105"));
        graphicsView_105->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_105, 3, 0, 1, 1);

        graphicsView_88 = new QGraphicsView(page_17);
        graphicsView_88->setObjectName(QString::fromUtf8("graphicsView_88"));
        graphicsView_88->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_88, 0, 7, 1, 1);

        graphicsView_108 = new QGraphicsView(page_17);
        graphicsView_108->setObjectName(QString::fromUtf8("graphicsView_108"));
        graphicsView_108->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_108, 3, 3, 1, 1);

        graphicsView_98 = new QGraphicsView(page_17);
        graphicsView_98->setObjectName(QString::fromUtf8("graphicsView_98"));
        graphicsView_98->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_98, 2, 1, 1, 1);

        graphicsView_112 = new QGraphicsView(page_17);
        graphicsView_112->setObjectName(QString::fromUtf8("graphicsView_112"));
        graphicsView_112->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_112, 3, 7, 1, 1);

        graphicsView_83 = new QGraphicsView(page_17);
        graphicsView_83->setObjectName(QString::fromUtf8("graphicsView_83"));
        graphicsView_83->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_83, 0, 2, 1, 1);

        graphicsView_100 = new QGraphicsView(page_17);
        graphicsView_100->setObjectName(QString::fromUtf8("graphicsView_100"));
        graphicsView_100->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_100, 2, 3, 1, 1);

        graphicsView_96 = new QGraphicsView(page_17);
        graphicsView_96->setObjectName(QString::fromUtf8("graphicsView_96"));
        graphicsView_96->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_96, 1, 7, 1, 1);

        graphicsView_92 = new QGraphicsView(page_17);
        graphicsView_92->setObjectName(QString::fromUtf8("graphicsView_92"));
        graphicsView_92->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_92, 1, 3, 1, 1);

        graphicsView_97 = new QGraphicsView(page_17);
        graphicsView_97->setObjectName(QString::fromUtf8("graphicsView_97"));
        graphicsView_97->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_97, 2, 0, 1, 1);

        graphicsView_93 = new QGraphicsView(page_17);
        graphicsView_93->setObjectName(QString::fromUtf8("graphicsView_93"));
        graphicsView_93->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_93, 1, 4, 1, 1);

        graphicsView_89 = new QGraphicsView(page_17);
        graphicsView_89->setObjectName(QString::fromUtf8("graphicsView_89"));
        graphicsView_89->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_89, 1, 0, 1, 1);

        graphicsView_103 = new QGraphicsView(page_17);
        graphicsView_103->setObjectName(QString::fromUtf8("graphicsView_103"));
        graphicsView_103->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_103, 2, 6, 1, 1);

        graphicsView_104 = new QGraphicsView(page_17);
        graphicsView_104->setObjectName(QString::fromUtf8("graphicsView_104"));
        graphicsView_104->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_104, 2, 7, 1, 1);

        graphicsView_117 = new QGraphicsView(page_17);
        graphicsView_117->setObjectName(QString::fromUtf8("graphicsView_117"));
        graphicsView_117->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_117, 4, 4, 1, 1);

        graphicsView_107 = new QGraphicsView(page_17);
        graphicsView_107->setObjectName(QString::fromUtf8("graphicsView_107"));
        graphicsView_107->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_107, 3, 2, 1, 1);

        graphicsView_120 = new QGraphicsView(page_17);
        graphicsView_120->setObjectName(QString::fromUtf8("graphicsView_120"));
        graphicsView_120->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_120, 4, 7, 1, 1);

        graphicsView_110 = new QGraphicsView(page_17);
        graphicsView_110->setObjectName(QString::fromUtf8("graphicsView_110"));
        graphicsView_110->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_110, 3, 5, 1, 1);

        graphicsView_86 = new QGraphicsView(page_17);
        graphicsView_86->setObjectName(QString::fromUtf8("graphicsView_86"));
        graphicsView_86->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_86, 0, 5, 1, 1);

        graphicsView_81 = new QGraphicsView(page_17);
        graphicsView_81->setObjectName(QString::fromUtf8("graphicsView_81"));
        graphicsView_81->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_81, 0, 0, 1, 1);

        graphicsView_95 = new QGraphicsView(page_17);
        graphicsView_95->setObjectName(QString::fromUtf8("graphicsView_95"));
        graphicsView_95->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_95, 1, 6, 1, 1);

        graphicsView_102 = new QGraphicsView(page_17);
        graphicsView_102->setObjectName(QString::fromUtf8("graphicsView_102"));
        graphicsView_102->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_102, 2, 5, 1, 1);

        graphicsView_119 = new QGraphicsView(page_17);
        graphicsView_119->setObjectName(QString::fromUtf8("graphicsView_119"));
        graphicsView_119->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_119, 4, 6, 1, 1);

        graphicsView_116 = new QGraphicsView(page_17);
        graphicsView_116->setObjectName(QString::fromUtf8("graphicsView_116"));
        graphicsView_116->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_116, 4, 3, 1, 1);

        graphicsView_91 = new QGraphicsView(page_17);
        graphicsView_91->setObjectName(QString::fromUtf8("graphicsView_91"));
        graphicsView_91->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_91, 1, 2, 1, 1);

        graphicsView_106 = new QGraphicsView(page_17);
        graphicsView_106->setObjectName(QString::fromUtf8("graphicsView_106"));
        graphicsView_106->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_106, 3, 1, 1, 1);

        graphicsView_111 = new QGraphicsView(page_17);
        graphicsView_111->setObjectName(QString::fromUtf8("graphicsView_111"));
        graphicsView_111->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_111, 3, 6, 1, 1);

        graphicsView_84 = new QGraphicsView(page_17);
        graphicsView_84->setObjectName(QString::fromUtf8("graphicsView_84"));
        graphicsView_84->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_84, 0, 3, 1, 1);

        graphicsView_113 = new QGraphicsView(page_17);
        graphicsView_113->setObjectName(QString::fromUtf8("graphicsView_113"));
        graphicsView_113->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_113, 4, 0, 1, 1);

        graphicsView_99 = new QGraphicsView(page_17);
        graphicsView_99->setObjectName(QString::fromUtf8("graphicsView_99"));
        graphicsView_99->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_99, 2, 2, 1, 1);

        graphicsView_114 = new QGraphicsView(page_17);
        graphicsView_114->setObjectName(QString::fromUtf8("graphicsView_114"));
        graphicsView_114->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_114, 4, 1, 1, 1);

        graphicsView_101 = new QGraphicsView(page_17);
        graphicsView_101->setObjectName(QString::fromUtf8("graphicsView_101"));
        graphicsView_101->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_101, 2, 4, 1, 1);

        graphicsView_85 = new QGraphicsView(page_17);
        graphicsView_85->setObjectName(QString::fromUtf8("graphicsView_85"));
        graphicsView_85->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_85, 0, 4, 1, 1);

        graphicsView_82 = new QGraphicsView(page_17);
        graphicsView_82->setObjectName(QString::fromUtf8("graphicsView_82"));
        graphicsView_82->setMinimumSize(QSize(105, 105));

        gridLayout_3->addWidget(graphicsView_82, 0, 1, 1, 1);

        m_scenes_stack->addWidget(page_17);

        horizontalLayout_8->addWidget(m_scenes_stack);


        horizontalLayout_7->addWidget(widget_5);

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
        quick_tabWidget->setMinimumSize(QSize(0, 300));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        quick_scenes_book = new Scene_Tool_Box(tab);
        quick_scenes_book->setObjectName(QString::fromUtf8("quick_scenes_book"));
        quick_scenes_book->setMaximumSize(QSize(68, 16777215));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 68, 205));
        quick_scenes_book->addItem(page_3, QString::fromUtf8("Page 1"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 68, 205));
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
        display_view->setMinimumSize(QSize(300, 300));
        display_view->setMaximumSize(QSize(300, 300));

        verticalLayout_2->addWidget(display_view);


        horizontalLayout->addWidget(widget_6);

        MainWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1370, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
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
        menu_2->addAction(new_workspace);
        menu_2->addAction(open_workspace);
        menu_3->addAction(picture_tracer);
        menu_3->addAction(publicize);

        retranslateUi(MainWindow1);

        play_button->setDefault(false);
        stackedWidget_2->setCurrentIndex(1);
        m_scenes_book->setCurrentIndex(0);
        m_scenes_stack->setCurrentIndex(1);
        quick_tabWidget->setCurrentIndex(0);
        quick_scenes_book->setCurrentIndex(0);
        quick_scenes_stack->setCurrentIndex(0);


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
        menu->setTitle(QApplication::translate("MainWindow1", "\350\256\276\347\275\256", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow1", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow1", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1: public Ui_MainWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW1_H
