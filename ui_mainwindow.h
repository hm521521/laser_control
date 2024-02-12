/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "output_panel.h"
#include "scene_tool_box.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actStart;
    QAction *actStop;
    QAction *actQuit;
    QAction *actClear;
    QAction *actHostInfo;
    QAction *hardware;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget;
    QWidget *page_7;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    Scene_Tool_Box *m_scenes_book_2;
    QWidget *page_9;
    QWidget *page_10;
    Scene_Stack *m_scenes_stack_2;
    QWidget *page_11;
    QWidget *page_12;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_41;
    QGraphicsView *graphicsView_42;
    QGraphicsView *graphicsView_43;
    QGraphicsView *graphicsView_44;
    QGraphicsView *graphicsView_45;
    QGraphicsView *graphicsView_46;
    QGraphicsView *graphicsView_47;
    QGraphicsView *graphicsView_48;
    QGraphicsView *graphicsView_49;
    QGraphicsView *graphicsView_50;
    QGraphicsView *graphicsView_51;
    QGraphicsView *graphicsView_52;
    QGraphicsView *graphicsView_53;
    QGraphicsView *graphicsView_54;
    QGraphicsView *graphicsView_55;
    QGraphicsView *graphicsView_56;
    QGraphicsView *graphicsView_57;
    QGraphicsView *graphicsView_58;
    QGraphicsView *graphicsView_59;
    QGraphicsView *graphicsView_60;
    QGraphicsView *graphicsView_61;
    QGraphicsView *graphicsView_62;
    QGraphicsView *graphicsView_63;
    QGraphicsView *graphicsView_64;
    QGraphicsView *graphicsView_65;
    QGraphicsView *graphicsView_66;
    QGraphicsView *graphicsView_67;
    QGraphicsView *graphicsView_68;
    QGraphicsView *graphicsView_69;
    QGraphicsView *graphicsView_70;
    QGraphicsView *graphicsView_71;
    QGraphicsView *graphicsView_72;
    QGraphicsView *graphicsView_73;
    QGraphicsView *graphicsView_74;
    QGraphicsView *graphicsView_75;
    QGraphicsView *graphicsView_76;
    QGraphicsView *graphicsView_77;
    QGraphicsView *graphicsView_78;
    QGraphicsView *graphicsView_79;
    QGraphicsView *graphicsView_80;
    QWidget *page_8;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    output_panel *display_view;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1220, 706);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        actStart = new QAction(MainWindow);
        actStart->setObjectName(QString::fromUtf8("actStart"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        actStop = new QAction(MainWindow);
        actStop->setObjectName(QString::fromUtf8("actStop"));
        actStop->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actClear = new QAction(MainWindow);
        actClear->setObjectName(QString::fromUtf8("actClear"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon3);
        actHostInfo = new QAction(MainWindow);
        actHostInfo->setObjectName(QString::fromUtf8("actHostInfo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/110.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actHostInfo->setIcon(icon4);
        hardware = new QAction(MainWindow);
        hardware->setObjectName(QString::fromUtf8("hardware"));
        hardware->setCheckable(true);
        hardware->setVisible(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addWidget(widget_2);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        horizontalLayout_6 = new QHBoxLayout(page_7);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_4 = new QWidget(page_7);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(992, 583));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_scenes_book_2 = new Scene_Tool_Box(widget_4);
        m_scenes_book_2->setObjectName(QString::fromUtf8("m_scenes_book_2"));
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        page_9->setGeometry(QRect(0, 0, 68, 513));
        m_scenes_book_2->addItem(page_9, QString::fromUtf8("Page 1"));
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        page_10->setGeometry(QRect(0, 0, 68, 513));
        m_scenes_book_2->addItem(page_10, QString::fromUtf8("Page 2"));

        horizontalLayout_5->addWidget(m_scenes_book_2);

        m_scenes_stack_2 = new Scene_Stack(widget_4);
        m_scenes_stack_2->setObjectName(QString::fromUtf8("m_scenes_stack_2"));
        m_scenes_stack_2->setMinimumSize(QSize(700, 521));
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        m_scenes_stack_2->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        gridLayout_2 = new QGridLayout(page_12);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView_41 = new QGraphicsView(page_12);
        graphicsView_41->setObjectName(QString::fromUtf8("graphicsView_41"));
        graphicsView_41->setMinimumSize(QSize(105, 105));
        graphicsView_41->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_41, 0, 0, 1, 1);

        graphicsView_42 = new QGraphicsView(page_12);
        graphicsView_42->setObjectName(QString::fromUtf8("graphicsView_42"));
        graphicsView_42->setMinimumSize(QSize(105, 105));
        graphicsView_42->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_42, 0, 1, 1, 1);

        graphicsView_43 = new QGraphicsView(page_12);
        graphicsView_43->setObjectName(QString::fromUtf8("graphicsView_43"));
        graphicsView_43->setMinimumSize(QSize(105, 105));
        graphicsView_43->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_43, 0, 2, 1, 1);

        graphicsView_44 = new QGraphicsView(page_12);
        graphicsView_44->setObjectName(QString::fromUtf8("graphicsView_44"));
        graphicsView_44->setMinimumSize(QSize(105, 105));
        graphicsView_44->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_44, 0, 3, 1, 1);

        graphicsView_45 = new QGraphicsView(page_12);
        graphicsView_45->setObjectName(QString::fromUtf8("graphicsView_45"));
        graphicsView_45->setMinimumSize(QSize(105, 105));
        graphicsView_45->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_45, 0, 4, 1, 1);

        graphicsView_46 = new QGraphicsView(page_12);
        graphicsView_46->setObjectName(QString::fromUtf8("graphicsView_46"));
        graphicsView_46->setMinimumSize(QSize(105, 105));
        graphicsView_46->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_46, 0, 5, 1, 1);

        graphicsView_47 = new QGraphicsView(page_12);
        graphicsView_47->setObjectName(QString::fromUtf8("graphicsView_47"));
        graphicsView_47->setMinimumSize(QSize(105, 105));
        graphicsView_47->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_47, 0, 6, 1, 1);

        graphicsView_48 = new QGraphicsView(page_12);
        graphicsView_48->setObjectName(QString::fromUtf8("graphicsView_48"));
        graphicsView_48->setMinimumSize(QSize(105, 105));
        graphicsView_48->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_48, 0, 7, 1, 1);

        graphicsView_49 = new QGraphicsView(page_12);
        graphicsView_49->setObjectName(QString::fromUtf8("graphicsView_49"));
        graphicsView_49->setMinimumSize(QSize(105, 105));
        graphicsView_49->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_49, 1, 0, 1, 1);

        graphicsView_50 = new QGraphicsView(page_12);
        graphicsView_50->setObjectName(QString::fromUtf8("graphicsView_50"));
        graphicsView_50->setMinimumSize(QSize(105, 105));
        graphicsView_50->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_50, 1, 1, 1, 1);

        graphicsView_51 = new QGraphicsView(page_12);
        graphicsView_51->setObjectName(QString::fromUtf8("graphicsView_51"));
        graphicsView_51->setMinimumSize(QSize(105, 105));
        graphicsView_51->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_51, 1, 2, 1, 1);

        graphicsView_52 = new QGraphicsView(page_12);
        graphicsView_52->setObjectName(QString::fromUtf8("graphicsView_52"));
        graphicsView_52->setMinimumSize(QSize(105, 105));
        graphicsView_52->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_52, 1, 3, 1, 1);

        graphicsView_53 = new QGraphicsView(page_12);
        graphicsView_53->setObjectName(QString::fromUtf8("graphicsView_53"));
        graphicsView_53->setMinimumSize(QSize(105, 105));
        graphicsView_53->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_53, 1, 4, 1, 1);

        graphicsView_54 = new QGraphicsView(page_12);
        graphicsView_54->setObjectName(QString::fromUtf8("graphicsView_54"));
        graphicsView_54->setMinimumSize(QSize(105, 105));
        graphicsView_54->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_54, 1, 5, 1, 1);

        graphicsView_55 = new QGraphicsView(page_12);
        graphicsView_55->setObjectName(QString::fromUtf8("graphicsView_55"));
        graphicsView_55->setMinimumSize(QSize(105, 105));
        graphicsView_55->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_55, 1, 6, 1, 1);

        graphicsView_56 = new QGraphicsView(page_12);
        graphicsView_56->setObjectName(QString::fromUtf8("graphicsView_56"));
        graphicsView_56->setMinimumSize(QSize(105, 105));
        graphicsView_56->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_56, 1, 7, 1, 1);

        graphicsView_57 = new QGraphicsView(page_12);
        graphicsView_57->setObjectName(QString::fromUtf8("graphicsView_57"));
        graphicsView_57->setMinimumSize(QSize(105, 105));
        graphicsView_57->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_57, 2, 0, 1, 1);

        graphicsView_58 = new QGraphicsView(page_12);
        graphicsView_58->setObjectName(QString::fromUtf8("graphicsView_58"));
        graphicsView_58->setMinimumSize(QSize(105, 105));
        graphicsView_58->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_58, 2, 1, 1, 1);

        graphicsView_59 = new QGraphicsView(page_12);
        graphicsView_59->setObjectName(QString::fromUtf8("graphicsView_59"));
        graphicsView_59->setMinimumSize(QSize(105, 105));
        graphicsView_59->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_59, 2, 2, 1, 1);

        graphicsView_60 = new QGraphicsView(page_12);
        graphicsView_60->setObjectName(QString::fromUtf8("graphicsView_60"));
        graphicsView_60->setMinimumSize(QSize(105, 105));
        graphicsView_60->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_60, 2, 3, 1, 1);

        graphicsView_61 = new QGraphicsView(page_12);
        graphicsView_61->setObjectName(QString::fromUtf8("graphicsView_61"));
        graphicsView_61->setMinimumSize(QSize(105, 105));
        graphicsView_61->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_61, 2, 4, 1, 1);

        graphicsView_62 = new QGraphicsView(page_12);
        graphicsView_62->setObjectName(QString::fromUtf8("graphicsView_62"));
        graphicsView_62->setMinimumSize(QSize(105, 105));
        graphicsView_62->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_62, 2, 5, 1, 1);

        graphicsView_63 = new QGraphicsView(page_12);
        graphicsView_63->setObjectName(QString::fromUtf8("graphicsView_63"));
        graphicsView_63->setMinimumSize(QSize(105, 105));
        graphicsView_63->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_63, 2, 6, 1, 1);

        graphicsView_64 = new QGraphicsView(page_12);
        graphicsView_64->setObjectName(QString::fromUtf8("graphicsView_64"));
        graphicsView_64->setMinimumSize(QSize(105, 105));
        graphicsView_64->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_64, 2, 7, 1, 1);

        graphicsView_65 = new QGraphicsView(page_12);
        graphicsView_65->setObjectName(QString::fromUtf8("graphicsView_65"));
        graphicsView_65->setMinimumSize(QSize(105, 105));
        graphicsView_65->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_65, 3, 0, 1, 1);

        graphicsView_66 = new QGraphicsView(page_12);
        graphicsView_66->setObjectName(QString::fromUtf8("graphicsView_66"));
        graphicsView_66->setMinimumSize(QSize(105, 105));
        graphicsView_66->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_66, 3, 1, 1, 1);

        graphicsView_67 = new QGraphicsView(page_12);
        graphicsView_67->setObjectName(QString::fromUtf8("graphicsView_67"));
        graphicsView_67->setMinimumSize(QSize(105, 105));
        graphicsView_67->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_67, 3, 2, 1, 1);

        graphicsView_68 = new QGraphicsView(page_12);
        graphicsView_68->setObjectName(QString::fromUtf8("graphicsView_68"));
        graphicsView_68->setMinimumSize(QSize(105, 105));
        graphicsView_68->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_68, 3, 3, 1, 1);

        graphicsView_69 = new QGraphicsView(page_12);
        graphicsView_69->setObjectName(QString::fromUtf8("graphicsView_69"));
        graphicsView_69->setMinimumSize(QSize(105, 105));
        graphicsView_69->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_69, 3, 4, 1, 1);

        graphicsView_70 = new QGraphicsView(page_12);
        graphicsView_70->setObjectName(QString::fromUtf8("graphicsView_70"));
        graphicsView_70->setMinimumSize(QSize(105, 105));
        graphicsView_70->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_70, 3, 5, 1, 1);

        graphicsView_71 = new QGraphicsView(page_12);
        graphicsView_71->setObjectName(QString::fromUtf8("graphicsView_71"));
        graphicsView_71->setMinimumSize(QSize(105, 105));
        graphicsView_71->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_71, 3, 6, 1, 1);

        graphicsView_72 = new QGraphicsView(page_12);
        graphicsView_72->setObjectName(QString::fromUtf8("graphicsView_72"));
        graphicsView_72->setMinimumSize(QSize(105, 105));
        graphicsView_72->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_72, 3, 7, 1, 1);

        graphicsView_73 = new QGraphicsView(page_12);
        graphicsView_73->setObjectName(QString::fromUtf8("graphicsView_73"));
        graphicsView_73->setMinimumSize(QSize(105, 105));
        graphicsView_73->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_73, 4, 0, 1, 1);

        graphicsView_74 = new QGraphicsView(page_12);
        graphicsView_74->setObjectName(QString::fromUtf8("graphicsView_74"));
        graphicsView_74->setMinimumSize(QSize(105, 105));
        graphicsView_74->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_74, 4, 1, 1, 1);

        graphicsView_75 = new QGraphicsView(page_12);
        graphicsView_75->setObjectName(QString::fromUtf8("graphicsView_75"));
        graphicsView_75->setMinimumSize(QSize(105, 105));
        graphicsView_75->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_75, 4, 2, 1, 1);

        graphicsView_76 = new QGraphicsView(page_12);
        graphicsView_76->setObjectName(QString::fromUtf8("graphicsView_76"));
        graphicsView_76->setMinimumSize(QSize(105, 105));
        graphicsView_76->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_76, 4, 3, 1, 1);

        graphicsView_77 = new QGraphicsView(page_12);
        graphicsView_77->setObjectName(QString::fromUtf8("graphicsView_77"));
        graphicsView_77->setMinimumSize(QSize(105, 105));
        graphicsView_77->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_77, 4, 4, 1, 1);

        graphicsView_78 = new QGraphicsView(page_12);
        graphicsView_78->setObjectName(QString::fromUtf8("graphicsView_78"));
        graphicsView_78->setMinimumSize(QSize(105, 105));
        graphicsView_78->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_78, 4, 5, 1, 1);

        graphicsView_79 = new QGraphicsView(page_12);
        graphicsView_79->setObjectName(QString::fromUtf8("graphicsView_79"));
        graphicsView_79->setMinimumSize(QSize(105, 105));
        graphicsView_79->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_79, 4, 6, 1, 1);

        graphicsView_80 = new QGraphicsView(page_12);
        graphicsView_80->setObjectName(QString::fromUtf8("graphicsView_80"));
        graphicsView_80->setMinimumSize(QSize(105, 105));
        graphicsView_80->setMaximumSize(QSize(105, 105));

        gridLayout_2->addWidget(graphicsView_80, 4, 7, 1, 1);

        m_scenes_stack_2->addWidget(page_12);

        horizontalLayout_5->addWidget(m_scenes_stack_2);


        horizontalLayout_6->addWidget(widget_4);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        stackedWidget->addWidget(page_8);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout->addWidget(widget);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        display_view = new output_panel(widget_3);
        display_view->setObjectName(QString::fromUtf8("display_view"));
        display_view->setMinimumSize(QSize(150, 0));
        display_view->setMaximumSize(QSize(150, 150));

        horizontalLayout_4->addWidget(display_view);


        horizontalLayout->addWidget(widget_3);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        m_scenes_book_2->setCurrentIndex(0);
        m_scenes_stack_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TCP Server", nullptr));
        actStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
#ifndef QT_NO_TOOLTIP
        actStart->setToolTip(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\347\250\213\345\272\217", nullptr));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
#endif // QT_NO_TOOLTIP
        actHostInfo->setText(QApplication::translate("MainWindow", "\346\234\254\346\234\272\345\234\260\345\235\200", nullptr));
#ifndef QT_NO_TOOLTIP
        actHostInfo->setToolTip(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\234\254\346\234\272\345\234\260\345\235\200", nullptr));
#endif // QT_NO_TOOLTIP
        hardware->setText(QApplication::translate("MainWindow", "\346\277\200\345\205\211\347\201\257\345\222\214\346\216\247\345\210\266\345\231\250\347\241\254\344\273\266", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        m_scenes_book_2->setItemText(m_scenes_book_2->indexOf(page_9), QApplication::translate("MainWindow", "Page 1", nullptr));
        m_scenes_book_2->setItemText(m_scenes_book_2->indexOf(page_10), QApplication::translate("MainWindow", "Page 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
