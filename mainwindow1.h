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
#include"configureartnet.h"
#include"artnetplugin.h"
#include"output_universe_dialog.h"

//#include"artnetserver.h"
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

class artnetdmx_slider:public QSlider
{
    Q_OBJECT
public:
    explicit artnetdmx_slider(QWidget *parent=nullptr);
signals:
    void value_changed(int index,int value);
public slots:
    void deal_value_changed(int value);
};


class MainWindow1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();
    QList<SubWindow*> getMyChildren();
protected:
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void do_select_page(toggle_button *button);
private slots:
    void on_hardware_triggered();//打开硬件连接
    void on_laser_setting_triggered();//打开激光设置
    void on_projection_zones_triggered();//打开投影区域设置
    void on_open_workspace_triggered();//打开工作区
    void on_pushButton_grid_clicked();//打开网格页
    void on_pushButton_timeline_clicked();//打开时间线页
    void on_play_button_clicked();//按播放按钮
    bool eventFilter(QObject *obj,QEvent *event);
    void add_stages(stage *s);
    void set_publicize_play();
    void output_universe();
private:
    Ui::MainWindow1 *ui;
    int m_device_num;
    scene_pool *m_scene_pool;
    bool m_play_show;
    Configuration* m_config;
    output_panel* m_output_panel;
    bool m_send_data;
    //project_panel * m_project_panel;
    std::vector<stage*> m_stages;
    bool m_multi_play;
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
    QTimer* m_line_timer;
    QUrl m_workspace_url = QUrl::fromEncoded("/./Workspace/123.isw");
    ConfigureArtNet *m_config_artnet;
    ArtNetPlugin *m_artnet;
    void set_page_data(scene_pool* sp, int page, Scene_Stack* stack = 0, Scene_Tool_Box* book = 0, bool flag = true);
    void read_first_page();
    int timer_interval=100;
private:
    void on_enable_output(yls_play_event& e);
    void on_play_show(yls_play_event &e);//点击播放按钮触发的动作
    void set_artnet_slider_group();
    void set_track_panel();
private slots:
    void refresh_stages(std::vector<laser_device*> list);
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
    void update_output_scene(int idx);//发送的idx>0代表播放，idx<0代表停止播放，idx<0值为对应的序号减去40
    void main_timer_update();
    void line_timer_update();//时间线定时器的timeout函数
    void update_show_scene(int idx);
    void readSinglePage(int page);
    void readQuickSinglePage(int page);
    void on_output_button_clicked();
    //void stopSendData(int idx);
signals:
    void stage_operate(const bool);//发送信号，触发线程
    void dialog_close();
public slots:
    void set_artnet_server();
    void setupDMXData(int id,int value);
    void recieveSection(CJSection section);
private:
    uchar dmxData[512]={0};
    int m_lastpage=0;
};

#endif // MAINWINDOW1_H
