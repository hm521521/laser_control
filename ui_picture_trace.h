/********************************************************************************
** Form generated from reading UI file 'picture_trace.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_TRACE_H
#define UI_PICTURE_TRACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Picture_trace
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_img;
    QPushButton *btn_src;
    QPushButton *btn_reduced;
    QPushButton *btn_traced;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *btn_smaller;
    QLabel *label;
    QToolButton *btn_bigger;
    QSlider *slider_size;
    QPushButton *btn_out;
    QToolButton *toolButton_5;
    QHBoxLayout *horizontalLayout_8;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QPushButton *btn_blur;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QPushButton *btn_color_separa;
    QPushButton *btn_highlight_separa;
    QPushButton *btn_centerline;
    QPushButton *btn_raster;
    QPushButton *btn_none;
    QVBoxLayout *verticalLayout;
    QLabel *label_rank;
    QSlider *slider_rank;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBox;
    QCheckBox *checkBox_3;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *check_space;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *distance_slider;
    QDoubleSpinBox *distance_SpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *offset_slider;
    QDoubleSpinBox *offset_SpinBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *check_smooth_;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *horizontalSlider_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *horizontalSlider_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Picture_trace)
    {
        if (Picture_trace->objectName().isEmpty())
            Picture_trace->setObjectName(QString::fromUtf8("Picture_trace"));
        Picture_trace->resize(1518, 1002);
        centralwidget = new QWidget(Picture_trace);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_img = new QPushButton(widget);
        btn_img->setObjectName(QString::fromUtf8("btn_img"));

        horizontalLayout->addWidget(btn_img);

        btn_src = new QPushButton(widget);
        btn_src->setObjectName(QString::fromUtf8("btn_src"));

        horizontalLayout->addWidget(btn_src);

        btn_reduced = new QPushButton(widget);
        btn_reduced->setObjectName(QString::fromUtf8("btn_reduced"));

        horizontalLayout->addWidget(btn_reduced);

        btn_traced = new QPushButton(widget);
        btn_traced->setObjectName(QString::fromUtf8("btn_traced"));

        horizontalLayout->addWidget(btn_traced);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);

        btn_smaller = new QToolButton(widget);
        btn_smaller->setObjectName(QString::fromUtf8("btn_smaller"));

        horizontalLayout->addWidget(btn_smaller);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btn_bigger = new QToolButton(widget);
        btn_bigger->setObjectName(QString::fromUtf8("btn_bigger"));

        horizontalLayout->addWidget(btn_bigger);

        slider_size = new QSlider(widget);
        slider_size->setObjectName(QString::fromUtf8("slider_size"));
        slider_size->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider_size);

        btn_out = new QPushButton(widget);
        btn_out->setObjectName(QString::fromUtf8("btn_out"));

        horizontalLayout->addWidget(btn_out);

        toolButton_5 = new QToolButton(widget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        horizontalLayout->addWidget(toolButton_5);


        verticalLayout_5->addWidget(widget);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        horizontalLayout_8->addWidget(graphicsView_2);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_8->addWidget(graphicsView);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        toolBox = new QToolBox(tab);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 401, 696));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_blur = new QPushButton(page);
        btn_blur->setObjectName(QString::fromUtf8("btn_blur"));

        gridLayout->addWidget(btn_blur, 0, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("Pre-tacing"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 401, 696));
        verticalLayout_9 = new QVBoxLayout(page_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        btn_color_separa = new QPushButton(page_2);
        btn_color_separa->setObjectName(QString::fromUtf8("btn_color_separa"));

        verticalLayout_7->addWidget(btn_color_separa);

        btn_highlight_separa = new QPushButton(page_2);
        btn_highlight_separa->setObjectName(QString::fromUtf8("btn_highlight_separa"));

        verticalLayout_7->addWidget(btn_highlight_separa);

        btn_centerline = new QPushButton(page_2);
        btn_centerline->setObjectName(QString::fromUtf8("btn_centerline"));

        verticalLayout_7->addWidget(btn_centerline);

        btn_raster = new QPushButton(page_2);
        btn_raster->setObjectName(QString::fromUtf8("btn_raster"));

        verticalLayout_7->addWidget(btn_raster);

        btn_none = new QPushButton(page_2);
        btn_none->setObjectName(QString::fromUtf8("btn_none"));

        verticalLayout_7->addWidget(btn_none);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_rank = new QLabel(page_2);
        label_rank->setObjectName(QString::fromUtf8("label_rank"));

        verticalLayout->addWidget(label_rank);

        slider_rank = new QSlider(page_2);
        slider_rank->setObjectName(QString::fromUtf8("slider_rank"));
        slider_rank->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_rank);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);

        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_8->setStretch(0, 4);
        verticalLayout_8->setStretch(1, 1);

        verticalLayout_9->addLayout(verticalLayout_8);

        toolBox->addItem(page_2, QString::fromUtf8("Tracing mode"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 401, 696));
        horizontalLayout_6 = new QHBoxLayout(page_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox = new QSpinBox(page_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_6->addWidget(spinBox);

        checkBox_3 = new QCheckBox(page_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_6->addWidget(checkBox_3);

        toolBox->addItem(page_3, QString::fromUtf8("Settings"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 401, 696));
        verticalLayout_4 = new QVBoxLayout(page_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        check_space = new QCheckBox(page_4);
        check_space->setObjectName(QString::fromUtf8("check_space"));

        verticalLayout_2->addWidget(check_space);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        distance_slider = new QSlider(page_4);
        distance_slider->setObjectName(QString::fromUtf8("distance_slider"));
        distance_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(distance_slider);

        distance_SpinBox = new QDoubleSpinBox(page_4);
        distance_SpinBox->setObjectName(QString::fromUtf8("distance_SpinBox"));
        distance_SpinBox->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(distance_SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        offset_slider = new QSlider(page_4);
        offset_slider->setObjectName(QString::fromUtf8("offset_slider"));
        offset_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(offset_slider);

        offset_SpinBox = new QDoubleSpinBox(page_4);
        offset_SpinBox->setObjectName(QString::fromUtf8("offset_SpinBox"));
        offset_SpinBox->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(offset_SpinBox);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        check_smooth_ = new QCheckBox(page_4);
        check_smooth_->setObjectName(QString::fromUtf8("check_smooth_"));

        verticalLayout_3->addWidget(check_smooth_);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSlider_4 = new QSlider(page_4);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_4);

        doubleSpinBox_3 = new QDoubleSpinBox(page_4);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setValue(1.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSlider_5 = new QSlider(page_4);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_5);

        doubleSpinBox_4 = new QDoubleSpinBox(page_4);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setValue(1.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_3);

        label_6 = new QLabel(page_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        toolBox->addItem(page_4, QString::fromUtf8("Traced points processing settings"));

        verticalLayout_6->addWidget(toolBox);

        tabWidget->addTab(tab, QString());

        horizontalLayout_8->addWidget(tabWidget);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 4);
        horizontalLayout_8->setStretch(2, 2);

        verticalLayout_5->addLayout(horizontalLayout_8);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_7 = new QHBoxLayout(widget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(720, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButton_13 = new QPushButton(widget_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        horizontalLayout_7->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(widget_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        horizontalLayout_7->addWidget(pushButton_14);


        verticalLayout_5->addWidget(widget_2);

        Picture_trace->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Picture_trace);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1518, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        Picture_trace->setMenuBar(menubar);
        statusbar = new QStatusBar(Picture_trace);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Picture_trace->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());

        retranslateUi(Picture_trace);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Picture_trace);
    } // setupUi

    void retranslateUi(QMainWindow *Picture_trace)
    {
        Picture_trace->setWindowTitle(QApplication::translate("Picture_trace", "MainWindow", nullptr));
        btn_img->setText(QApplication::translate("Picture_trace", "Picture...", nullptr));
        btn_src->setText(QApplication::translate("Picture_trace", "Original", nullptr));
        btn_reduced->setText(QApplication::translate("Picture_trace", "Reducced", nullptr));
        btn_traced->setText(QApplication::translate("Picture_trace", "Traced", nullptr));
        toolButton->setText(QApplication::translate("Picture_trace", "...", nullptr));
        toolButton_2->setText(QApplication::translate("Picture_trace", "...", nullptr));
        btn_smaller->setText(QApplication::translate("Picture_trace", "...", nullptr));
        label->setText(QApplication::translate("Picture_trace", "TextLabel", nullptr));
        btn_bigger->setText(QApplication::translate("Picture_trace", "...", nullptr));
        btn_out->setText(QApplication::translate("Picture_trace", "show it now", nullptr));
        toolButton_5->setText(QApplication::translate("Picture_trace", "...", nullptr));
        btn_blur->setText(QApplication::translate("Picture_trace", "\345\233\276\347\211\207\351\231\215\345\231\252", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Picture_trace", "Pre-tacing", nullptr));
        btn_color_separa->setText(QApplication::translate("Picture_trace", "\351\242\234\350\211\262\345\210\206\347\246\273", nullptr));
        btn_highlight_separa->setText(QApplication::translate("Picture_trace", "\351\253\230\345\205\211\345\210\206\347\246\273", nullptr));
        btn_centerline->setText(QApplication::translate("Picture_trace", "\344\270\255\345\277\203\347\272\277", nullptr));
        btn_raster->setText(QApplication::translate("Picture_trace", "Raster", nullptr));
        btn_none->setText(QApplication::translate("Picture_trace", "\345\217\226\346\266\210\350\256\276\347\275\256", nullptr));
        label_rank->setText(QApplication::translate("Picture_trace", "\345\210\206\347\246\273\347\255\211\347\272\247\357\274\232128", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Picture_trace", "Tracing mode", nullptr));
        label_7->setText(QApplication::translate("Picture_trace", "TextLabel", nullptr));
        checkBox_3->setText(QApplication::translate("Picture_trace", "CheckBox", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Picture_trace", "Settings", nullptr));
        check_space->setText(QApplication::translate("Picture_trace", "Enable Spacing filter", nullptr));
        label_2->setText(QApplication::translate("Picture_trace", "\350\267\235\347\246\273", nullptr));
        label_3->setText(QApplication::translate("Picture_trace", "\345\201\217\347\247\273", nullptr));
        check_smooth_->setText(QApplication::translate("Picture_trace", "\345\271\263\346\273\221\350\277\207\346\273\244\345\231\250", nullptr));
        label_4->setText(QApplication::translate("Picture_trace", "\350\267\235\347\246\273", nullptr));
        label_5->setText(QApplication::translate("Picture_trace", "\345\201\217\347\247\273", nullptr));
        label_6->setText(QApplication::translate("Picture_trace", "TextLabel", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("Picture_trace", "Traced points processing settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Picture_trace", "Options", nullptr));
        pushButton_13->setText(QApplication::translate("Picture_trace", "\347\241\256\350\256\244", nullptr));
        pushButton_14->setText(QApplication::translate("Picture_trace", "\345\217\226\346\266\210", nullptr));
        menuFile->setTitle(QApplication::translate("Picture_trace", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Picture_trace", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("Picture_trace", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Picture_trace: public Ui_Picture_trace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_TRACE_H
