/********************************************************************************
** Form generated from reading UI file 'clockedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKEDIT_H
#define UI_CLOCKEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_ClockEdit
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_9;
    mygraphicsview *graphicsView;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *Slider_sizeX;
    QSpinBox *spinBox_sizeX;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *Slider_sizeY;
    QSpinBox *spinBox_sizeY;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *Slider_locX;
    QSpinBox *spinBox_locX;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSlider *Slider_locY;
    QSpinBox *spinBox_locY;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *Slider_fontsize;
    QSpinBox *spinBox_fontsize;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSlider *Slider_fgap;
    QSpinBox *spinBox_fgap;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QLineEdit *hour_min_gapchar;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QLineEdit *min_sec_gapchar;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *view_day;
    QCheckBox *view_hour;
    QCheckBox *view_min;
    QCheckBox *view_sec;
    QFrame *line;
    QCheckBox *check_vic_loc_dig;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QGraphicsView *graphicsView_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QPushButton *btn_open;
    QPushButton *btn_edit;
    QPushButton *btn_del;
    QCheckBox *check_sizectl;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_8;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClockEdit)
    {
        if (ClockEdit->objectName().isEmpty())
            ClockEdit->setObjectName(QStringLiteral("ClockEdit"));
        ClockEdit->resize(800, 600);
        centralwidget = new QWidget(ClockEdit);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_11 = new QVBoxLayout(centralwidget);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_9 = new QHBoxLayout(widget_3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        graphicsView = new mygraphicsview(widget_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout_9->addWidget(graphicsView);


        horizontalLayout_10->addWidget(widget_3);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolBox = new QToolBox(widget_2);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 369, 371));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(page);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(page);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(page);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(page);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(page);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout->addWidget(radioButton_6);

        toolBox->addItem(page, QString::fromUtf8("\346\227\266\351\222\237\347\261\273\345\236\213"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 369, 371));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Slider_sizeX = new QSlider(page_2);
        Slider_sizeX->setObjectName(QStringLiteral("Slider_sizeX"));
        Slider_sizeX->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Slider_sizeX);

        spinBox_sizeX = new QSpinBox(page_2);
        spinBox_sizeX->setObjectName(QStringLiteral("spinBox_sizeX"));

        horizontalLayout_2->addWidget(spinBox_sizeX);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        Slider_sizeY = new QSlider(page_2);
        Slider_sizeY->setObjectName(QStringLiteral("Slider_sizeY"));
        Slider_sizeY->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(Slider_sizeY);

        spinBox_sizeY = new QSpinBox(page_2);
        spinBox_sizeY->setObjectName(QStringLiteral("spinBox_sizeY"));

        horizontalLayout_3->addWidget(spinBox_sizeY);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        Slider_locX = new QSlider(page_2);
        Slider_locX->setObjectName(QStringLiteral("Slider_locX"));
        Slider_locX->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(Slider_locX);

        spinBox_locX = new QSpinBox(page_2);
        spinBox_locX->setObjectName(QStringLiteral("spinBox_locX"));

        horizontalLayout_4->addWidget(spinBox_locX);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        Slider_locY = new QSlider(page_2);
        Slider_locY->setObjectName(QStringLiteral("Slider_locY"));
        Slider_locY->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Slider_locY);

        spinBox_locY = new QSpinBox(page_2);
        spinBox_locY->setObjectName(QStringLiteral("spinBox_locY"));

        horizontalLayout_5->addWidget(spinBox_locY);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        Slider_fontsize = new QSlider(page_2);
        Slider_fontsize->setObjectName(QStringLiteral("Slider_fontsize"));
        Slider_fontsize->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(Slider_fontsize);

        spinBox_fontsize = new QSpinBox(page_2);
        spinBox_fontsize->setObjectName(QStringLiteral("spinBox_fontsize"));

        horizontalLayout_6->addWidget(spinBox_fontsize);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        Slider_fgap = new QSlider(page_2);
        Slider_fgap->setObjectName(QStringLiteral("Slider_fgap"));
        Slider_fgap->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(Slider_fgap);

        spinBox_fgap = new QSpinBox(page_2);
        spinBox_fgap->setObjectName(QStringLiteral("spinBox_fgap"));

        horizontalLayout_7->addWidget(spinBox_fgap);


        verticalLayout_3->addLayout(horizontalLayout_7);

        toolBox->addItem(page_2, QString::fromUtf8("\345\270\203\345\261\200"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 369, 371));
        verticalLayout_9 = new QVBoxLayout(page_3);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        hour_min_gapchar = new QLineEdit(page_3);
        hour_min_gapchar->setObjectName(QStringLiteral("hour_min_gapchar"));

        verticalLayout_4->addWidget(hour_min_gapchar);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        min_sec_gapchar = new QLineEdit(page_3);
        min_sec_gapchar->setObjectName(QStringLiteral("min_sec_gapchar"));

        verticalLayout_5->addWidget(min_sec_gapchar);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_9->addLayout(verticalLayout_6);

        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        view_day = new QCheckBox(groupBox);
        view_day->setObjectName(QStringLiteral("view_day"));

        verticalLayout_7->addWidget(view_day);

        view_hour = new QCheckBox(groupBox);
        view_hour->setObjectName(QStringLiteral("view_hour"));

        verticalLayout_7->addWidget(view_hour);

        view_min = new QCheckBox(groupBox);
        view_min->setObjectName(QStringLiteral("view_min"));

        verticalLayout_7->addWidget(view_min);

        view_sec = new QCheckBox(groupBox);
        view_sec->setObjectName(QStringLiteral("view_sec"));

        verticalLayout_7->addWidget(view_sec);


        verticalLayout_8->addLayout(verticalLayout_7);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line);

        check_vic_loc_dig = new QCheckBox(groupBox);
        check_vic_loc_dig->setObjectName(QStringLiteral("check_vic_loc_dig"));

        verticalLayout_8->addWidget(check_vic_loc_dig);


        verticalLayout_9->addWidget(groupBox);

        toolBox->addItem(page_3, QString::fromUtf8("\346\225\260\345\255\227\346\227\266\351\222\237\345\210\206\351\232\224\347\254\246"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 432, 371));
        verticalLayout_10 = new QVBoxLayout(page_4);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        graphicsView_2 = new QGraphicsView(page_4);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        horizontalLayout_8->addWidget(graphicsView_2);

        widget_4 = new QWidget(page_4);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_open = new QPushButton(widget_4);
        btn_open->setObjectName(QStringLiteral("btn_open"));

        gridLayout_2->addWidget(btn_open, 0, 0, 1, 1);

        btn_edit = new QPushButton(widget_4);
        btn_edit->setObjectName(QStringLiteral("btn_edit"));

        gridLayout_2->addWidget(btn_edit, 0, 1, 1, 1);

        btn_del = new QPushButton(widget_4);
        btn_del->setObjectName(QStringLiteral("btn_del"));

        gridLayout_2->addWidget(btn_del, 1, 0, 1, 1);


        horizontalLayout_8->addWidget(widget_4);


        verticalLayout_10->addLayout(horizontalLayout_8);

        check_sizectl = new QCheckBox(page_4);
        check_sizectl->setObjectName(QStringLiteral("check_sizectl"));

        verticalLayout_10->addWidget(check_sizectl);

        toolBox->addItem(page_4, QString::fromUtf8("\350\203\214\346\231\257\345\270\247"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);


        horizontalLayout_10->addWidget(widget_2);


        verticalLayout_11->addLayout(horizontalLayout_10);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(589, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_11->addWidget(widget);

        ClockEdit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClockEdit);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_7 = new QMenu(menubar);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        menu_8 = new QMenu(menubar);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        ClockEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(ClockEdit);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ClockEdit->setStatusBar(statusbar);

        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menu_7->menuAction());
        menubar->addAction(menu_8->menuAction());

        retranslateUi(ClockEdit);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ClockEdit);
    } // setupUi

    void retranslateUi(QMainWindow *ClockEdit)
    {
        ClockEdit->setWindowTitle(QApplication::translate("ClockEdit", "MainWindow", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ClockEdit", "\346\250\241\346\213\237", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("ClockEdit", "\346\225\260\345\255\227", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("ClockEdit", "\346\225\260\345\255\227-\345\200\222\346\225\260", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("ClockEdit", "\346\225\260\345\255\227-\345\236\202\347\233\264\345\200\222\346\225\260", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("ClockEdit", "\346\225\260\345\255\227-\344\273\216\345\244\264\345\274\200\345\247\213\345\200\222\346\225\260", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("ClockEdit", "\346\225\260\345\255\227-count up", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ClockEdit", "\346\227\266\351\222\237\347\261\273\345\236\213", Q_NULLPTR));
        label->setText(QApplication::translate("ClockEdit", "X\345\260\272\345\257\270", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClockEdit", "Y\345\260\272\345\257\270", Q_NULLPTR));
        label_3->setText(QApplication::translate("ClockEdit", "X\344\275\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("ClockEdit", "Y\344\275\215\347\275\256", Q_NULLPTR));
        label_5->setText(QApplication::translate("ClockEdit", "\346\226\207\345\255\227\345\244\247\345\260\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("ClockEdit", "\346\226\207\345\255\227\351\227\264\351\232\224", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ClockEdit", "\345\270\203\345\261\200", Q_NULLPTR));
        label_7->setText(QApplication::translate("ClockEdit", "\345\260\217\346\227\266\345\210\206\351\222\237\345\210\206\351\232\224\347\254\246", Q_NULLPTR));
        label_8->setText(QApplication::translate("ClockEdit", "\345\210\206-\347\247\222\345\210\206\351\232\224\347\254\246", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ClockEdit", "\346\237\245\347\234\213", Q_NULLPTR));
        view_day->setText(QApplication::translate("ClockEdit", "\345\244\251", Q_NULLPTR));
        view_hour->setText(QApplication::translate("ClockEdit", "\345\260\217\346\227\266", Q_NULLPTR));
        view_min->setText(QApplication::translate("ClockEdit", "\345\210\206\351\222\237", Q_NULLPTR));
        view_sec->setText(QApplication::translate("ClockEdit", "\347\247\222", Q_NULLPTR));
        check_vic_loc_dig->setText(QApplication::translate("ClockEdit", "\345\236\202\347\233\264\346\225\260\345\255\227\344\275\215\347\275\256", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("ClockEdit", "\346\225\260\345\255\227\346\227\266\351\222\237\345\210\206\351\232\224\347\254\246", Q_NULLPTR));
        btn_open->setText(QApplication::translate("ClockEdit", "\346\211\223\345\274\200", Q_NULLPTR));
        btn_edit->setText(QApplication::translate("ClockEdit", "\347\274\226\350\276\221", Q_NULLPTR));
        btn_del->setText(QApplication::translate("ClockEdit", "\345\210\240\351\231\244", Q_NULLPTR));
        check_sizectl->setText(QApplication::translate("ClockEdit", "\344\270\272\346\227\266\351\222\237\350\203\214\346\231\257\345\220\257\347\224\250\345\260\272\345\257\270\346\216\247\345\210\266", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("ClockEdit", "\350\203\214\346\231\257\345\270\247", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ClockEdit", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ClockEdit", "PushButton", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("ClockEdit", "\344\277\235\345\255\230", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("ClockEdit", "\346\211\223\345\274\200\345\261\236\346\200\247\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("ClockEdit", "\346\230\276\347\244\272\345\235\220\346\240\207\347\275\221\346\240\274", Q_NULLPTR));
        menu_6->setTitle(QApplication::translate("ClockEdit", "\345\201\234\346\255\242", Q_NULLPTR));
        menu_7->setTitle(QApplication::translate("ClockEdit", "\345\220\257\345\212\250", Q_NULLPTR));
        menu_8->setTitle(QApplication::translate("ClockEdit", "\350\256\276\347\275\256\345\255\227\344\275\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClockEdit: public Ui_ClockEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKEDIT_H
