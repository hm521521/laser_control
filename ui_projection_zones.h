/********************************************************************************
** Form generated from reading UI file 'projection_zones.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTION_ZONES_H
#define UI_PROJECTION_ZONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projection_zones
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListView *zone_names_listView;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addZones_pushButton;
    QPushButton *pushButton_12;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *delete_zone_pushButton;
    QPushButton *pushButton_14;
    QLabel *label_3;
    QTableView *projector_tableView;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QWidget *tab_1;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *projection_zones)
    {
        if (projection_zones->objectName().isEmpty())
            projection_zones->setObjectName(QStringLiteral("projection_zones"));
        projection_zones->resize(879, 691);
        centralwidget = new QWidget(projection_zones);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(100, 0));
        horizontalSlider->setMaximumSize(QSize(100, 16777215));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(10, 0));
        pushButton_7->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(pushButton_10);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(widget_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(tableView);

        tabWidget = new QTabWidget(widget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget_8 = new QWidget(tab);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMaximumSize(QSize(375, 16777215));
        verticalLayout_6 = new QVBoxLayout(widget_8);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(200, 0));
        widget_6->setMaximumSize(QSize(16777215, 150));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        zone_names_listView = new QListView(widget_3);
        zone_names_listView->setObjectName(QStringLiteral("zone_names_listView"));

        verticalLayout_3->addWidget(zone_names_listView);


        horizontalLayout_4->addWidget(widget_3);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMaximumSize(QSize(50, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addZones_pushButton = new QPushButton(widget_4);
        addZones_pushButton->setObjectName(QStringLiteral("addZones_pushButton"));
        addZones_pushButton->setMaximumSize(QSize(20, 16777215));

        verticalLayout_2->addWidget(addZones_pushButton);

        pushButton_12 = new QPushButton(widget_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMaximumSize(QSize(20, 16777215));

        verticalLayout_2->addWidget(pushButton_12);


        horizontalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMaximumSize(QSize(50, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        delete_zone_pushButton = new QPushButton(widget_5);
        delete_zone_pushButton->setObjectName(QStringLiteral("delete_zone_pushButton"));
        delete_zone_pushButton->setMaximumSize(QSize(20, 16777215));

        verticalLayout_4->addWidget(delete_zone_pushButton);

        pushButton_14 = new QPushButton(widget_5);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMaximumSize(QSize(20, 16777215));

        verticalLayout_4->addWidget(pushButton_14);


        horizontalLayout_4->addWidget(widget_5);


        verticalLayout_6->addWidget(widget_6);

        label_3 = new QLabel(widget_8);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);

        projector_tableView = new QTableView(widget_8);
        projector_tableView->setObjectName(QStringLiteral("projector_tableView"));
        projector_tableView->setMinimumSize(QSize(350, 0));
        projector_tableView->setMaximumSize(QSize(350, 16777215));

        verticalLayout_6->addWidget(projector_tableView);


        horizontalLayout_3->addWidget(widget_8);

        widget_7 = new QWidget(tab);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(widget_7);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_7);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget_7);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));

        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget_7);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));

        verticalLayout_5->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget_7);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));

        verticalLayout_5->addWidget(groupBox_5);


        horizontalLayout_3->addWidget(widget_7);

        tabWidget->addTab(tab, QString());
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget->addTab(tab_6, QString());

        horizontalLayout_2->addWidget(tabWidget);


        verticalLayout->addWidget(widget_2);

        projection_zones->setCentralWidget(centralwidget);
        menubar = new QMenuBar(projection_zones);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 879, 25));
        projection_zones->setMenuBar(menubar);
        statusbar = new QStatusBar(projection_zones);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        projection_zones->setStatusBar(statusbar);

        retranslateUi(projection_zones);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(projection_zones);
    } // setupUi

    void retranslateUi(QMainWindow *projection_zones)
    {
        projection_zones->setWindowTitle(QApplication::translate("projection_zones", "MainWindow", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("projection_zones", "\347\262\230\350\264\264", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("projection_zones", "\346\211\223\345\274\200", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("projection_zones", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("projection_zones", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("projection_zones", "+", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("projection_zones", "\303\227", Q_NULLPTR));
        label->setText(QApplication::translate("projection_zones", "Brightness:", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("projection_zones", "\347\262\230\350\264\264", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("projection_zones", "show it now", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("projection_zones", "?", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("projection_zones", "-", Q_NULLPTR));
        label_2->setText(QApplication::translate("projection_zones", "Projection zone names(identifies)", Q_NULLPTR));
        addZones_pushButton->setText(QApplication::translate("projection_zones", "+", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("projection_zones", "\342\206\221", Q_NULLPTR));
        delete_zone_pushButton->setText(QApplication::translate("projection_zones", "\303\227", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("projection_zones", "\342\206\223", Q_NULLPTR));
        label_3->setText(QApplication::translate("projection_zones", " \350\276\223\345\207\272\346\234\254\345\214\272\345\237\237\345\210\260\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("projection_zones", "Geometric correction", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("projection_zones", "Beam Attenuation Map", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("projection_zones", "Preview window appearance", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("projection_zones", "Advanced settings", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("projection_zones", "Also to", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("projection_zones", "General", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("projection_zones", "Geometirc correction", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("projection_zones", "Preview", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("projection_zones", "Beam Attenuation Map", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("projection_zones", "Advanced", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("projection_zones", "Unresolved zone names:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("projection_zones", "Distribution", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class projection_zones: public Ui_projection_zones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTION_ZONES_H
