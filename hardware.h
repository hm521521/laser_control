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
private slots:
    void on_Plus_Button_clicked();
//    void onNewConnection();//处理新连接
//    void onSocketReadyRead();//读取设备发送的数据，判断是否是laser_device
    void on_Refresh_Button_clicked();
    void on_table_selected(QVariant s);
private:
    Ui::hardware *ui;
    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//Item选择模型
    void init_menu_bar();
//    laser_device_manager *m_manager;
    QUdpSocket *m_udpsocket;
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
public slots:
    void refresh_laser_device(QVector<laser_device*> m_device_list);

};

class hardware_table:public QTableView
{
    Q_OBJECT
public:
    hardware_table(QWidget *parent=nullptr);
protected:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) override;
signals:
    void table_selected(QVariant s);
//    QModelIndexList selectedIndexes() const override;

//    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;

};





#endif // HARDWARE_H
