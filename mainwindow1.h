#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include "laser_device_manager.h"
#include "scene_pool.h"
#include"main_panel.h"
#include"project_panel.h"
#include<QGridLayout>
#include"configuration.h"
#include"stage.h"
#include"yls_play_event.h"
#include "hardware.h"
#include"laser_setting.h"
//class scene_pool;
namespace Ui {
class MainWindow1;
}


class main_frame_thread:public QThread
{
    Q_OBJECT
public:
    main_frame_thread(QObject *parent = nullptr);
    void stopThread();
private:
    QObject *m_main_frame;
    bool m_stop;
signals:
    void update();
    void completed();
protected:
    void run() Q_DECL_OVERRIDE;
};




class MainWindow1 : public QMainWindow
{
    Q_OBJECT
//    QThread stage_thread;
//    QThreadPool stage_thread_pool;
public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();
    QList<SubWindow*> getMyChildren();

protected:
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void do_select_page(toggle_button *button);
private slots:
    void on_hardware_triggered();
    void on_laser_setting_triggered();
    void on_projection_zones_triggered();
    void on_open_workspace_triggered();
    void on_thread_completion();
    void on_thread_update();
    void on_pushButton_grid_clicked();
    void on_pushButton_timeline_clicked();
    void on_play_button_clicked();
    void on_output_button_clicked();
    bool eventFilter(QObject *obj,QEvent *event);
    void add_stages(stage *s);

private:
    Ui::MainWindow1 *ui;

    int m_device_num;
//    QList<SubWindow*> m_children;
    scene_pool *m_scene_pool;
    main_panel *m_main_panel;
    bool m_play_show;
    main_frame_thread m_main_thread;
    Configuration* m_config;
    output_panel* m_output_panel;
    bool m_send_data;
    project_panel * m_project_panel;
    QVector<stage*> m_stages;
    bool m_multi_play;
    hardware *m_hardware;
    laser_setting *m_laser_setting;
    laser_device_manager *m_laser_device_manager;
private:
    void on_enable_output(yls_play_event& e);
    void on_play_show(yls_play_event &e);
//    void moveto_stage_thread(stage *s);
private slots:
    void refresh_stages(laser_device* device);
    static void handle_stage_results(int result);//处理子线程的结果
signals:
    void stage_operate(const bool);//发送信号，触发线程
};




#endif // MAINWINDOW1_H
