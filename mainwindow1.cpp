#include "mainwindow1.h"
#include "ui_mainwindow1.h"
//#include "ui_hardware.h"
#include "laser_setting.h"
#include "projection_zones.h"
#include<QFileDialog>
#include<QUrl>
#include"gdiplus_helper.h"
#include"stop_watch.hpp"
//#include<QtConfig>
//#define SET_NAME(x) graphicsView_##(x)//动态命名变量名
#include<QSettings>
#include"test_patterns.h"

MainWindow1::MainWindow1(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow1),
    m_device_num(0),
    m_play_show(false),
    m_send_data(false)
{
    ui->setupUi(this);
    QSettings *pConfig=new QSettings("/system/settings.ini",QSettings::IniFormat);
    if(pConfig)
    {
        int x=pConfig->value("x",0).toInt();
        int y=pConfig->value("y",0).toInt();
        int w=pConfig->value("w",1010).toInt();
        int h=pConfig->value("h",687).toInt();
        this->move(x,y);
        this->resize(w,h);
        m_multi_play=pConfig->value("multi",1).toBool();
        m_send_data=pConfig->value("output",1).toBool();
    }
    m_main_panel=new main_panel(this);
    m_scene_pool=new scene_pool();
    m_output_panel=ui->display_view;
//    connect(&m_main_thread,SIGNAL(completed()),this,SLOT(on_thread_completion()));
//    connect(&m_main_thread,SIGNAL(update()),this,SLOT(on_thread_update()));
//    m_main_thread.start();
    m_main_worker=new main_thread_worker(this);
    m_workspace_worker=new workspace_worker(this);
    connect(m_main_worker,SIGNAL(update()),this,SLOT(on_thread_update()),Qt::QueuedConnection);
    m_config=new Configuration();//配置对象
    m_config->Load();
    m_project_panel=ui->project_panel_view;
//    ui->gridLayout_3->setHorizontalSpacing(0);
//    ui->gridLayout_3->setVerticalSpacing(0);
    installEventFilter(this);
    do_select_page(ui->pushButton_timeline);
    //设备发现
    m_laser_device_manager=new laser_device_manager(this);
    m_pic_trace=new Picture_trace(this);
    m_publicize=new publicize(this);
    m_setup_admin_mode=new setup_Administrator_mode(this);
    m_setup_user_mode=new setup_user_mode(this);
    stage*s=new stage(this);
    s->set_config(m_config);
    s->set_device(m_laser_device_manager->get_default_device());
    if(s->get_device()!=nullptr)
    {
        m_stages.push_back(s);
    }
//    output_panel *op=new output_panel(this);
    m_hardware=new hardware(this);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),m_hardware,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    m_laser_setting=new laser_setting(this);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),m_laser_setting->m_device_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    connect(m_laser_device_manager,SIGNAL(new_device(laser_device*)),this,SLOT(refresh_stages(laser_device*)));
    connect(m_hardware,SIGNAL(refresh_controller()),m_laser_device_manager,SLOT(refresh_laser_device()));
    connect(m_publicize,&publicize::operate,this,&MainWindow1::set_publicize_play);
    connect(m_publicize,&publicize::playpause,this,&MainWindow1::set_publicize_play);
    m_test_pattern=new test_patterns(this);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),m_test_pattern->m_device_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    QThreadPool::globalInstance()->setMaxThreadCount(10);
    QThreadPool::globalInstance()->start(m_main_worker);
    m_dmx_setup=new DMX_setup(this);
    m_device_settings=new midi_device_settings(this);
    m_midi_monitor=new midi_moniter(this);
    m_osc_setting=new osc_settings(this);
    //调用moveToThread 将该任务交给workThread
    //调用moveToThread 将该任务交给workThread
//    stage_thread_pool.setMaxThreadCount(5);
//    stage_thread_pool.setExpiryTimeout(-1);
    ui->trans_listView->setup("/system/trans_list.txt");
}

MainWindow1::~MainWindow1()
{
    m_main_worker->setStop();
    QSettings *app_config=new QSettings("/system/settings.ini",QSettings::IniFormat);
    qDebug() << QCoreApplication::applicationDirPath();
    if(app_config)
    {
        int x,y,w,h;
        w=this->size().width();
        h=this->size().height();
        x=this->pos().x();
        y=this->pos().y();
        app_config->setValue("x",x);
        app_config->setValue("y",y);
        app_config->setValue("w",w);
        app_config->setValue("h",h);
        app_config->setValue("multi",m_multi_play);
        app_config->setValue("output",m_send_data);
    }
    delete ui;
    delete m_hardware;
    delete m_config;
    delete m_scene_pool;
    delete m_laser_setting;
    delete m_main_panel;
    m_stages.clear();
    m_scene_pool=nullptr;
    delete m_output_panel;
    m_output_panel=nullptr;
    delete m_project_panel;
    m_project_panel=nullptr;
    delete m_test_pattern;
    QThreadPool::globalInstance()->clear();
}

void MainWindow1::closeEvent(QCloseEvent *event)
{
//    if(m_main_thread.isRunning())
//    {
//        m_main_thread.stopThread();
//        m_main_thread.wait();
//    }
    event->accept();
}

void MainWindow1::resizeEvent(QResizeEvent *event)
{
//    QGraphicsScene *scene=new QGraphicsScene(ui->verticalLayout_4->itemAt(0)->geometry());
    QGraphicsScene *scene=new QGraphicsScene();
    m_project_panel->set_scene(scene);
}
inline void set_button_bg(toggle_button* btn, bool pressed)
{
     btn->setValue(pressed);
}

void MainWindow1::do_select_page(toggle_button *button)
{
    if (button == ui->pushButton_grid)
        {
            set_button_bg(ui->pushButton_grid, true);
            set_button_bg(ui->pushButton_timeline, false);
            set_button_bg(ui->pushButton_playlist, false);
        }
        else if (button == ui->pushButton_timeline)
        {
            set_button_bg(ui->pushButton_grid, false);
            set_button_bg(ui->pushButton_timeline, true);
            set_button_bg(ui->pushButton_playlist, false);
        }
        else if (button == ui->pushButton_playlist)
        {
            set_button_bg(ui->pushButton_grid, false);
            set_button_bg(ui->pushButton_timeline, false);
            set_button_bg(ui->pushButton_playlist, true);
        }
}

void MainWindow1::on_hardware_triggered()//每次打开都添加一个子窗口，需要修改、关闭程序tcp不断开，需要修改
{

    m_hardware->show();

//    h->set_output(m_stages.size()>0?m_stages.last():nullptr);
//    m_children.push_back(h);
}

void MainWindow1::on_laser_setting_triggered()
{
    m_laser_setting->show();
//    m_children.push_back(l);
}

void MainWindow1::on_projection_zones_triggered()
{
     projection_zones *p=new projection_zones(this);
     connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),p->m_device_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
     p->show();
// m_children.push_back(p);
}

void MainWindow1::on_open_workspace_triggered()//打开工作区
{
    connect(m_workspace_worker,SIGNAL(workspace()),this,SLOT(open_workspace()));
    QThreadPool::globalInstance()->start(m_workspace_worker);
}

void MainWindow1::on_thread_completion()
{

}

void MainWindow1::on_thread_update()
{
    m_output_panel->m_picture.clear();
    for(int i=0;i<m_publicize->m_output_panels.size();++i)
    {
        m_publicize->m_output_panels.at(i)->m_picture.clear();
    }
    m_main_panel->update_scene(m_send_data ? &m_output_panel->m_picture:nullptr);
    if(m_play_show)
    {
        m_project_panel->update_show(m_send_data ? &m_output_panel->m_picture:nullptr);
    }
    if(m_publicize_play)
    {
        for(int i=0;i<m_publicize->m_output_panels.size();++i)
        {
            m_publicize->update_show(m_send_data ? &m_publicize->m_output_panels.at(i)->m_picture:nullptr,i);
        }
    }
    if(m_send_data&&m_output_panel->m_picture.size()>0)
    {
        for(int i=0;i<m_stages.size();++i)
        {
            auto s=m_stages.at(i);
            std::vector<ishow_data> out=m_output_panel->m_picture.globalprocessing(m_config);
            s->add_send_data(out);
        }
    }
    else if(m_send_data&&m_publicize_play)
    {
        for(int i=0;i<m_publicize->m_output_panels.size();++i)
        {
            if(m_publicize->m_output_panels.at(i)->m_picture.size()>0&&m_stages.size()>1)
            {
                auto s=m_stages.at(i);
                std::vector<ishow_data> out=m_publicize->m_output_panels.at(i)->m_picture.globalprocessing(m_config);
                s->add_send_data(out);
            }
        }

    }
    m_output_panel->do_draw();
    for(int i=0;i<m_publicize->m_output_panels.size();++i)
    {
        m_publicize->m_output_panels.at(i)->do_draw();
    }
}

void MainWindow1::on_enable_output(yls_play_event &e)
{
    m_send_data=e.get_state();
}

void MainWindow1::on_play_show(yls_play_event &e)
{
    m_play_show=e.get_state();
    if(m_play_show)
    {
        m_project_panel->play();
//        if(m_send_data)
//        {
//            for(int i=0;i<m_stages.size();++i)
//            {
//                auto s=m_stages.at(i);
//                stage_thread_pool.start(s);
//            }
//        }
    }
    else
    {
        m_project_panel->stop();
    }
}

//void MainWindow1::moveto_stage_thread(stage *s)
//{
//    s->moveToThread(&stage_thread);
//    //operate信号发射后启动线程工作
//    connect(this,SIGNAL(stage_operate(bool)),s,SLOT(do_send_data(bool)));
//    connect(s,SIGNAL(stage_finish()),&stage_thread,SLOT(quit()));
//    //该线程结束时销毁
//    connect(&stage_thread,&QThread::isFinished,s,&QObject::deleteLater);
//    connect(s,SIGNAL(resultReady(int)),this,SLOT(handle_stage_results(int)));
//    qDebug()<<"emit the signal to execute";
//    qDebug()<<"\tCurrent thread ID:"<<QThread::currentThreadId()<<'\n';
//}

void MainWindow1::refresh_stages(laser_device * device)
{
    if(device==nullptr)
        return;
    for(int i=0;i<m_stages.size();++i)
    {
        if(m_stages.at(i)->get_device()->get_name()==device->get_name())
            return;
    }
    stage*s=new stage(this);
    s->set_config(m_config);
    s->set_device(device);

    if(s->get_device()!=nullptr)
    {
        m_stages.push_back(s);
    }
}

void MainWindow1::handle_stage_results(int result)
{
    qDebug()<<"receive the resultReady signal";
}



//main_frame_thread::main_frame_thread(QObject *parent)
//    :QThread(parent),m_main_frame(parent)
//{

//}

//void main_frame_thread::stopThread()
//{
//    m_stop=true;
//}

//void main_frame_thread::run()
//{
//    m_stop=false;//启动线程另m_stop=false
//    double next_frame=0;
//    stop_watch sw;
//    sw.start();
//    while(!m_stop)//循环主体
//    {
//        double current_time=sw.elapsed();
//        if (current_time>=next_frame)
//        {
//            if(current_time>=10000000.0)
//            {
//                sw.restart();
//                next_frame=0;
//            }
//            //通知主线程render以及更新scene control
//            emit update();
//            next_frame+=100.f/25.0;//TODO设置可调节的播放速度
//        }
//        msleep(60);
//    }
//    emit completed();
//    quit();
//}

void MainWindow1::on_pushButton_grid_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    do_select_page(ui->pushButton_grid);
}


void MainWindow1::on_pushButton_timeline_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    do_select_page(ui->pushButton_timeline);
}


void MainWindow1::on_play_button_clicked()
{
    if(ui->play_button->getValue())
        ui->play_button->setText("暂停");
    else
        ui->play_button->setText("播放");
    yls_play_event *event=new yls_play_event(ylsEVT_TOOLBAR_PLAY_EVENT, objectName());
    event->set_state(ui->play_button->getValue());
    QCoreApplication::postEvent(this,event);
}

void MainWindow1::on_output_button_clicked()
{
    yls_play_event *event=new yls_play_event(ylsEVT_TOOLBAR_ENABLE_OUTPUT_EVENT, objectName());
    event->set_state(ui->output_button->getValue());
    QCoreApplication::postEvent(this,event);
}

bool MainWindow1::eventFilter(QObject *obj, QEvent *event)
{
    yls_play_event *e=dynamic_cast<yls_play_event*>(event);
    if(e)
    {
        if(e->type()==ylsEVT_TOOLBAR_PLAY_EVENT)
        {
            on_play_show(*e);
        }
        else if(e->type()==ylsEVT_TOOLBAR_ENABLE_OUTPUT_EVENT)
        {
            on_enable_output(*e);
        }
    }
    return QMainWindow::eventFilter(obj,event);
}

void MainWindow1::add_stages(stage *s)
{
    if(s)
    {
        for(int i=0;i<m_stages.size();++i)
        {
            if(m_stages.at(i)->get_device()->get_name()==s->get_device()->get_name())
                return;
        }
        m_stages.push_back(s);

    }
}

void MainWindow1::set_publicize_play()
{
    m_publicize_play=!m_publicize_play;
}

void MainWindow1::on_picture_tracer_triggered()
{
    m_pic_trace->show();
}


void MainWindow1::on_publicize_triggered()
{
    m_publicize->show();
}

void MainWindow1::open_workspace()
{
    QUrl fileUrl=QFileDialog::getOpenFileUrl(this,"打开工作区",QUrl("./Workspace"),tr("workspaces(*.isw *.iSw)"));
    if(!m_scene_pool->isEmpty())
    {
        m_main_panel->set_data_model(nullptr);
        m_scene_pool->clearup();
    }
    m_scene_pool=new scene_pool(this);
    m_scene_pool->read(fileUrl);
    delete ui->m_scenes_book;
    ui->m_scenes_book=new Scene_Tool_Box(ui->widget);
    delete ui->m_scenes_stack;
    ui->m_scenes_stack=new Scene_Stack(ui->widget);
    m_main_panel->set_data_model(m_scene_pool,ui->m_scenes_stack,ui->m_scenes_book);
    ui->horizontalLayout_7->addWidget(ui->m_scenes_book);
    ui->horizontalLayout_7->addWidget(ui->m_scenes_stack);
    if(ui->m_scenes_book->count()!=0)
        ui->m_scenes_stack->setCurrentIndex(ui->m_scenes_book->currentIndex());
    ui->m_scenes_book->show();
    ui->m_scenes_stack->show();
    connect(ui->m_scenes_book,SIGNAL(currentChanged(int)),ui->m_scenes_stack,SLOT(setCurrentIndex(int)));
    delete ui->quick_scenes_book;
    ui->quick_scenes_book=new Scene_Tool_Box(ui->widget);
    delete ui->quick_scenes_stack;
    ui->quick_scenes_stack=new Scene_Stack(ui->widget);
    m_main_panel->set_data_model(m_scene_pool,ui->quick_scenes_stack,ui->quick_scenes_book,false);
//输出ild文件
//    m_main_panel->out_to_ild();
    ui->horizontalLayout_3->addWidget(ui->quick_scenes_book);
    ui->horizontalLayout_3->addWidget(ui->quick_scenes_stack);
//    ui->horizontalLayout_3->setSpacing(0);
    if(ui->quick_scenes_book->count()!=0)
        ui->quick_scenes_stack->setCurrentIndex(ui->quick_scenes_book->currentIndex());
    ui->quick_scenes_book->show();
    ui->quick_scenes_stack->show();
    connect(ui->quick_scenes_book,SIGNAL(currentChanged(int)),ui->quick_scenes_stack,SLOT(setCurrentIndex(int)));
}

main_thread_worker::main_thread_worker(QObject *parent)
{
    setAutoDelete(true);
}

void main_thread_worker::setStop()
{
    m_stop=true;
}

void main_thread_worker::run()
{
    m_stop=false;
    double next_frame=0;
    while(!m_stop)//循环主体
    {
        emit update();
        next_frame+=100.f/25.0;
        QThread::msleep(50);
    }
}


workspace_worker::workspace_worker(QObject *parent)
{
     setAutoDelete(true);
}

void workspace_worker::run()
{
    emit workspace();
}

void MainWindow1::on_test_patterns_triggered()
{
    m_test_pattern->show();
}


void MainWindow1::on_DMX_ArtNet_Settings_triggered()
{
    m_dmx_setup->show();
}


void MainWindow1::on_Setup_Administritor_Mode_triggered()
{
    m_setup_admin_mode->show();
}


void MainWindow1::on_Setup_User_Mode_triggered()
{
    m_setup_user_mode->show();
}


void MainWindow1::on_Midi_Monitor_triggered()
{
    m_midi_monitor->show();
}


void MainWindow1::on_Midi_Device_Settings_triggered()
{
    m_device_settings->show();
}


void MainWindow1::on_OSC_Settings_triggered()
{
    m_osc_setting->show();
}

