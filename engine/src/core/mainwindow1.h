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
#include"toggle_button.h"
#include"output_panel.h"
#include"picture_trace.h"
#include"publicize.h"
#include"test_patterns.h"
#include"dmx_setup.h"
#include"setup_administrator_mode.h"
#include"setup_user_mode.h"
#include"midi_device_settings.h"
#include"midi_moniter.h"
#include"osc_settings.h"
//class scene_pool;
namespace Ui {
class MainWindow1;
}
class workspace_worker:public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit workspace_worker(QObject *parent=nullptr);
private:
    void run() override;
signals:
    void workspace();
};
class main_thread_worker:public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit main_thread_worker(QObject *parent=nullptr);
    void setStop();
private:
    void run() override;
    bool m_stop;

signals:
    void update();
};

//class main_frame_thread:public QThread
//{
//    Q_OBJECT
//public:
//    main_frame_thread(QObject *parent = nullptr);
//    void stopThread();
//private:
//    QObject *m_main_frame;
//    bool m_stop;
//signals:
//    void update();
//    void completed();
//protected:
//    void run() Q_DECL_OVERRIDE;
//};

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
    void set_publicize_play();
private:
    Ui::MainWindow1 *ui;
    int m_device_num;
//    QList<SubWindow*> m_children;
    scene_pool *m_scene_pool;
    bool m_play_show;
//    main_frame_thread m_main_thread;
    Configuration* m_config;
    output_panel* m_output_panel;
    bool m_send_data;
    project_panel * m_project_panel;
    std::vector<stage*> m_stages;
    bool m_multi_play;
//    hardware *m_hardware;
//    laser_setting *m_laser_setting;
    laser_device_manager *m_laser_device_manager;
    Picture_trace *m_pic_trace;
    publicize *m_publicize;
    bool m_publicize_play=false;
    main_thread_worker* m_main_worker;
    workspace_worker* m_workspace_worker;
//    QToolBox* m_toolbox;
    std::vector<scene_panel*> m_scene_panels;
    scene_panel *m_panel;
    void set_data_model(scene_pool* sp, Scene_Stack *stack=0, Scene_Tool_Box *book=0,bool flag=true);
    std::vector<unsigned char> update_show_index;
    QTimer *m_main_timer;
    QUrl m_workspace_url;
//    test_patterns* m_test_pattern;
//    DMX_setup* m_dmx_setup;
//    setup_Administrator_mode *m_setup_admin_mode;
//    setup_user_mode *m_setup_user_mode;
//    midi_device_settings *m_device_settings;
//    midi_moniter *m_midi_monitor;
//    osc_settings *m_osc_setting;
//    QVector<output_panel*> m_output_panels;//publicize多屏显示
private:
    void on_enable_output(yls_play_event& e);
    void on_play_show(yls_play_event &e);
//    void moveto_stage_thread(stage *s);
private slots:
    void refresh_stages(laser_device* device);
    static void handle_stage_results(int result);//处理子线程的结果
    void on_picture_tracer_triggered();
    void on_publicize_triggered();
    void open_workspace();
    void on_test_patterns_triggered();
    void on_DMX_ArtNet_Settings_triggered();
    void on_Setup_Administritor_Mode_triggered();
    void on_Setup_User_Mode_triggered();
    void on_Midi_Monitor_triggered();
    void on_Midi_Device_Settings_triggered();
    void on_OSC_Settings_triggered();
//    void get_send_info(bool send,output_panel *panel);
    void update_output_scene(int idx);//发送的idx>0代表播放，idx<0代表停止播放，idx<0值为对应的序号减去40
    void main_timer_update();
    void update_show_scene(int idx);
    void readSinglePage(int);
signals:
    void stage_operate(const bool);//发送信号，触发线程
};

#endif // MAINWINDOW1_H
