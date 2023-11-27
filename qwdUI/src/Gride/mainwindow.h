#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include<QPushButton>
#include"dialog_setpassword.h"
#include"dialog_fb4_export.h"
#include"fb4_files_viewer.h"
#include"fb4_settings.h"
#include"programgroupinfo.h"
#include<QGridLayout>
#include<QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
     QStringListModel *Model;
     QStandardItemModel *ItemModel;
     void initAll37();
     void initAll2();
     //void initGraphics();
     //void openeDfault();
     /*
      * @brief 在widget界面中插入qml-ui grid部分
      */
     void setQmlUIGrid(QUrl qml, QObject* ctx);



private slots:
    void on_pushButton_172_clicked();

    void on_pushButton_173_clicked();

    void on_pushButton_174_clicked();

    void showClick(QModelIndex index);

    void DisSave();//保存失败的槽函数



signals:
    void openWorkspace(QString url);


private:
    Ui::MainWindow *ui;
    MainWindow *model;
    //新建工作空间的按钮
   int ret;
   //设置密码对话框
   Dialog_Setpassword s;
   //FB4导出对话框
   Dialog_FB4_Export FB4_E;
   FB4_Files_viewer F_B_V;
   FB4_Settings F_S;
   ProgramGroupInfo P_G_I;
};
#endif // MAINWINDOW_H
