#ifndef HARDWARE_H
#define HARDWARE_H

#include <QMainWindow>
#include <QDialog>
#include <QStringListModel>
#include <QStandardItemModel>
#include<QItemSelectionModel>
#include<QThread>
#include<QtNetwork>
#include "laser_device_manager.h"
//#include "mainwindow1.h"
#include "ed_laser_output.h"
#include "laser_output.h"
#include "stage.h"
#include<QTableView>



namespace Ui {
class hardware;
class QWDialogHeaders;
}

class SubWindow:public QMainWindow
{
    Q_OBJECT
public:
    virtual QString getMyType()=0;
};
//class MainWindow1;
class hardware_table;
class hardware : public SubWindow
{
    Q_OBJECT

public:
    explicit hardware(QWidget *parent = nullptr);
    ~hardware();
//    bool broadcast();
//    QString getLocalIP();
    QString getMyType();
    void set_output(stage* output_stage);
    hardware_table *m_hardware_table;
private slots:
    void on_Plus_Button_clicked();
//    void onNewConnection();//处理新连接
//    void onSocketReadyRead();//读取设备发送的数据，判断是否是laser_device
    void on_Refresh_Button_clicked();
    void on_table_selected(QVariant s);
    void on_Delete_button_clicked();

private:
    Ui::hardware *ui;
    void init_menu_bar();
//    laser_device_manager *m_manager;
    //QUdpSocket *m_udpsocket;
    int m_device_num;
    QTimer *myTimer;
    QString m_type;
    bool m_enable_out;

protected:
    void closeEvent(QCloseEvent *event);
    stage* m_output_stage;
signals:
    void stage_changed(stage * s);
    void refresh_controller();


};

class hardware_table:public QTableView
{
    Q_OBJECT
public:
    hardware_table(QWidget *parent=nullptr);
    void set_device_manager(laser_device_manager *manager);
protected:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) override;
signals:
    void table_selected(QVariant s);
private:
    laser_device_manager *m_manager;
    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//Item选择模型
public slots:
    void refresh_laser_device(std::vector<laser_device*> m_device_list);
//    QModelIndexList selectedIndexes() const override;

//    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;

};





#endif // HARDWARE_H
