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
#include"output_dialog.h"
//#include"artnetserver.h"

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
        m_send_data=pConfig->value("output",0).toBool();
    }
//    m_main_panel=new main_panel(this);
    m_scene_pool=new scene_pool();
    m_output_panel=ui->display_view;
//    connect(&m_main_thread,SIGNAL(completed()),this,SLOT(on_thread_completion()));
//    connect(&m_main_thread,SIGNAL(update()),this,SLOT(on_thread_update()));
//    m_main_thread.start();
    m_main_worker=new main_thread_worker(this);

//    connect(m_main_worker,SIGNAL(update()),this,SLOT(on_thread_update()),Qt::QueuedConnection);
    m_config=new Configuration();//配置对象
    m_config->Load();
    //m_project_panel=ui->project_panel_view;
//    ui->gridLayout_3->setHorizontalSpacing(0);
//    ui->gridLayout_3->setVerticalSpacing(0);
    installEventFilter(this);
    do_select_page(ui->pushButton_timeline);
    //设备发现
    m_laser_device_manager=new laser_device_manager(this);
    m_pic_trace=new Picture_trace(this);
    m_publicize=new publicize(this);
    stage*s=new stage(this);
    s->set_config(m_config);
    s->set_device(m_laser_device_manager->get_default_device());
    if(s->get_device()!=nullptr)
    {
        m_stages.push_back(s);
    }
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),this,SLOT(refresh_stages(std::vector<laser_device*>)));
    connect(m_publicize,&publicize::operate,this,&MainWindow1::set_publicize_play);
    connect(m_publicize,&publicize::playpause,this,&MainWindow1::set_publicize_play);
    QThreadPool::globalInstance()->setMaxThreadCount(10);
    ui->trans_listView->setup("/system/trans_list.txt");
    m_main_timer=new QTimer(this);
    connect(m_main_timer,SIGNAL(timeout()),this,SLOT(main_timer_update()));
    m_line_timer = new QTimer(this);
    connect(m_line_timer, SIGNAL(timeout()), this, SLOT(line_timer_update()));
    set_artnet_slider_group();
    m_artnet=new ArtNetPlugin();
    m_artnet->init();
    set_track_panel();
    read_first_page();
}

MainWindow1::~MainWindow1()
{
    m_main_worker->setStop();
    QSettings *app_config=new QSettings("./system/settings.ini",QSettings::IniFormat);
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
    delete m_config;
    delete m_scene_pool;
    m_stages.clear();
    m_scene_pool=nullptr;
    delete m_output_panel;
    m_output_panel=nullptr;
    delete m_laser_device_manager;
    QThreadPool::globalInstance()->clear();
}

void MainWindow1::set_data_model(scene_pool *sp, Scene_Stack *stack, Scene_Tool_Box *book, bool flag)
{
    for (int i = stack->count(); i >-1; i--)
        stack->removeWidget(stack->widget(i));
    for (int i = book->count(); i >-1; i--)
        book->removeItem(i);
    m_scene_pool=sp;
    if(flag)
        m_scene_panels.clear();
   if (m_scene_pool == nullptr)
       return;
   book->setMaximumWidth(100);
   book->setMaximumHeight(300);
   int scenes_count=m_scene_pool->size();
//   int page_count=(scenes_count + 39) / 40;//每页有40个Scene,获取应该有多少页
   int page_count=m_scene_pool->total_page;
   for(int i=0;i<page_count;i++)
   {
       QWidget *wid=new QWidget();
       QGridLayout *grid_sizer = new QGridLayout(wid);
       grid_sizer->setHorizontalSpacing(0);
       grid_sizer->setVerticalSpacing(0);
//       grid_sizer->insertSpacing(0, -12);
       if (i == 0)
       {
           stack->addWidget(wid);
           for (int row = 0; row < 5; row++)
           {
               for (int col = 0; col < 8; col++)
               {
                   m_panel = new scene_panel(wid);
                   grid_sizer->addWidget(m_panel, row, col, 1, 1);
                   QRect scenerect = grid_sizer->cellRect(row, col);
                   m_panel->resize(scenerect.width(), scenerect.height());
                   m_panel->m_graphicsScene = new QGraphicsScene(scenerect);
                   m_panel->setScene(m_panel->m_graphicsScene);
                   //               connect(m_panel,SIGNAL(get_send_info()),this,SLOT(get_send_info()));
                   m_scene_panels.push_back(m_panel);
                   int idx = row * 8 + col; //获得当前scene的index
                  
                   if (idx < scenes_count)
                   {
                       m_panel->setIndex(!flag * 40 + idx);
                       connect(m_panel, SIGNAL(panel_index(int)), this, SLOT(update_output_scene(int)));
                       connect(m_panel, SIGNAL(show_panel_index(int)), this, SLOT(update_show_scene(int)));

                       //connect(m_panel, SIGNAL(mouse_move(int)), this, SLOT(stopSendData(int)));
                       m_panel->set_data_model(m_scene_pool->at(idx));
                       m_panel->do_draw(true);
                   }
                   else
                       continue;
               }
           }
           wid->setLayout(grid_sizer);
       }
    QWidget * page_1 = new QWidget(this);
    page_1->setObjectName(QString::fromUtf8("page_")+QString::number(i));
    book->addItem(page_1, QString::fromUtf8("page_")+QString::number(i));
    }
}

void MainWindow1::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void MainWindow1::resizeEvent(QResizeEvent *event)
{
    QGraphicsScene *scene=new QGraphicsScene();
    /*m_project_panel->set_scene(scene);*/
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
    hardware *h=new hardware(this);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),h->m_hardware_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    connect(h,SIGNAL(refresh_controller()),m_laser_device_manager,SLOT(refresh_laser_device()));
    h->m_hardware_table->set_device_manager(m_laser_device_manager);
    h->setWindowModality(Qt::ApplicationModal);//阻塞其他窗体
    h->show();

//    h->set_output(m_stages.size()>0?m_stages.last():nullptr);
//    m_children.push_back(h);
}

void MainWindow1::on_laser_setting_triggered()
{
    laser_setting *m_laser_setting=new laser_setting(this);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),m_laser_setting->m_device_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    m_laser_setting->m_device_table->set_device_manager(m_laser_device_manager);
    m_laser_setting->setWindowModality(Qt::ApplicationModal);//阻塞其他窗体
    m_laser_setting->show();
//    m_children.push_back(l);
}

void MainWindow1::on_projection_zones_triggered()
{
    projection_zones *p=new projection_zones(this);
    p->m_device_table->set_device_manager(m_laser_device_manager);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),p->m_device_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    // m_children.push_back(p);

    p->setWindowModality(Qt::ApplicationModal);//阻塞其他窗体
    p->show();
}

void MainWindow1::on_open_workspace_triggered()//打开工作区
{
    m_workspace_worker=new workspace_worker(this);
    //QThreadPool::globalInstance()->start(m_workspace_worker);
    //connect(m_workspace_worker,SIGNAL(workspace()),this,SLOT(open_workspace()));
    open_workspace();
}

void MainWindow1::set_page_data(scene_pool* sp, int page, Scene_Stack* stack, Scene_Tool_Box* book, bool flag)
{
    std::vector<scene_panel*> temp_scene_panels;
    m_scene_pool = sp;
    if (flag)
    {
        int len = MIN(80, m_scene_panels.size());
        for (int i = 40; i < len; i++)
            temp_scene_panels.push_back(m_scene_panels.at(i));
        m_scene_panels.clear();
    }
    else
    {
        int len = MIN(80, m_scene_panels.size());
        for (int i = len - 1; i > 39; i--)
        {
            m_scene_panels.pop_back();
        }
    }
    if (m_scene_pool == nullptr)
        return;
    book->setMaximumWidth(100);
    book->setMaximumHeight(300);
    int scenes_count = m_scene_pool->size();
    for (int i = stack->count(); i > -1; i--)
    {
        stack->removeWidget(stack->widget(i));
    }
    QWidget* wid = new QWidget(stack);        
    QGridLayout* grid_sizer = new QGridLayout(wid);
    grid_sizer->setHorizontalSpacing(0);
    grid_sizer->setVerticalSpacing(0);
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            m_panel = new scene_panel(wid);
            grid_sizer->addWidget(m_panel, row, col, 1, 1);
            qDebug() << "grid_sizer" << grid_sizer->count();
            QRect scenerect = grid_sizer->cellRect(row, col);
            m_panel->resize(scenerect.width(), scenerect.height());
            m_panel->m_graphicsScene = new QGraphicsScene(scenerect);
            m_panel->setScene(m_panel->m_graphicsScene);
            //               connect(m_panel,SIGNAL(get_send_info()),this,SLOT(get_send_info()));
            m_scene_panels.push_back(m_panel);
            int idx = row * 8 + col; //获得当前scene的index

            if (idx < scenes_count)
            {
                m_panel->setIndex(!flag * 40 + idx);
                connect(m_panel, SIGNAL(panel_index(int)), this, SLOT(update_output_scene(int)));
                connect(m_panel, SIGNAL(show_panel_index(int)), this, SLOT(update_show_scene(int)));
                m_panel->set_data_model(m_scene_pool->at(idx));
                m_panel->do_draw(true);
            }
            else
                continue;
        }
    }
    if (flag)
    {
            for (int i = 0; i < temp_scene_panels.size(); i++)
                m_scene_panels.push_back(temp_scene_panels.at(i));
    }
    wid->setLayout(grid_sizer);
    stack->addWidget(wid);
}

void MainWindow1::read_first_page()
{
    m_scene_pool->read(m_workspace_url);//只读上来第一页的所有数据
    set_data_model(m_scene_pool, ui->m_scenes_stack, ui->m_scenes_book);
    connect(ui->m_scenes_book, SIGNAL(currentChanged(int)), ui->m_scenes_stack, SLOT(setCurrentIndex(int)));
    connect(ui->m_scenes_book, SIGNAL(currentChanged(int)), this, SLOT(readSinglePage(int)));
    set_data_model(m_scene_pool, ui->quick_scenes_stack, ui->quick_scenes_book, false);
    connect(ui->quick_scenes_book, SIGNAL(currentChanged(int)), this, SLOT(readQuickSinglePage(int)));
    connect(ui->quick_scenes_book, SIGNAL(currentChanged(int)), ui->quick_scenes_stack, SLOT(setCurrentIndex(int)));
}



void MainWindow1::on_enable_output(yls_play_event &e)
{
    m_send_data=e.get_state();
    if(m_send_data)
    {
        int num=0;
        for(int i=0;i<m_stages.size();i++)
        {
            if(m_stages.at(i)->get_device()->m_socket->state()==QAbstractSocket::ConnectedState)
                break;
            num++;
        }
        if(num==m_stages.size()|m_stages.size()==0)
        {
            QMessageBox::information(this, tr("message"),
                                           tr("No device!"),
                                           QMessageBox::Ok | QMessageBox::Cancel);
            m_send_data=false;
            ui->output_button->setText("闭光");
            return;
        }
        ui->output_button->setText("闭光");
    }
    else
    {
        ui->output_button->setText("输出到激光");
    }
    
}


void MainWindow1::set_artnet_server()
{
    QSettings *settings = new QSettings("./artnet_config.ini", QSettings::IniFormat);
    int current_output = settings->value("current_output").toInt();
    settings->beginGroup("dmax_output");
    char string[1] = { 0 };
    QString str = "output" + QString(itoa(current_output + 1, string, 10)) + "_universe";
    int univers = 0;
    if (settings->contains(str))
    {
        univers = settings->value(str).toInt();
    }
    settings->endGroup();

}

void MainWindow1::setupDMXData(int id, int value)
{
    dmxData[id]=value;
    QByteArray dmx_data;
    for(int i=0;i<512;i++)
        dmx_data.append(dmxData[i]);
    m_artnet->setupDMXData(dmx_data);

}
void MainWindow1::recieveSection(CJSection section)
{
    if (section.empty())
        return;
    m_output_panel->m_picture.clear();
    for (int i = 0; i < section.size(); i++)
    {
        m_output_panel->m_picture.push_back(section.at(i));
    }
    m_output_panel->do_draw();
}
void MainWindow1::on_play_show(yls_play_event &e)
{
    m_play_show=e.get_state();
    if(m_play_show)
    {
        if (!m_line_timer->isActive()&&ui->track_list->hasinfo())
        {
            ui->play_button->setText("暂停");
            m_line_timer->start(timer_interval);

        }
    }
    else
    {
        if (m_line_timer->isActive())
        {
            ui->play_button->setText("播放");
            m_line_timer->stop();
            ui->track_list->play(m_play_show);
        }
            

    }
}



void MainWindow1::refresh_stages(std::vector<laser_device*> device_list)
{
    m_stages.clear();
    for(int i=0;i<device_list.size();i++)
    {
        stage *s=new stage(this);
        s->set_config(m_config);
        s->set_device(device_list.at(i));
        m_stages.push_back(s);
    }
}

void MainWindow1::handle_stage_results(int result)
{
    qDebug()<<"receive the resultReady signal";
}



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
    yls_play_event *event=new yls_play_event(ylsEVT_TOOLBAR_PLAY_EVENT, objectName());
    
    event->set_state(!m_play_show);
    QCoreApplication::postEvent(this,event);
}

void MainWindow1::on_output_button_clicked()
{
    yls_play_event *event=new yls_play_event(ylsEVT_TOOLBAR_ENABLE_OUTPUT_EVENT, objectName());
    event->set_state(ui->output_button->getValue());
    QCoreApplication::postEvent(this,event);
}

//void MainWindow1::stopSendData(int idx)
//{
//    m_send_data = false;
//}

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

void MainWindow1::output_universe()
{
    output_universe_Dialog *m_output_universe=new output_universe_Dialog(this);
    m_output_universe->setWindowModality(Qt::ApplicationModal);
    m_output_universe->show();
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
    m_workspace_url=QFileDialog::getOpenFileUrl(this,"打开工作区",QUrl("./Workspace"),tr("workspaces(*.isw *.iSw)"));
    read_first_page();
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
//        emit update();
        next_frame+=100.f/25.0;
        QThread::msleep(75);
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
    test_patterns *m_test_pattern=new test_patterns(this);
    connect(m_laser_device_manager,SIGNAL(manager_changed(std::vector<laser_device*>)),m_test_pattern->m_device_table,SLOT(refresh_laser_device(std::vector<laser_device*>)));
    connect(m_test_pattern, SIGNAL(sendSection(CJSection)), this, SLOT(recieveSection(CJSection)));
    connect(m_test_pattern,SIGNAL(on_enable_output()),this,SLOT(on_output_button_clicked()));
    m_test_pattern->m_device_table->set_device_manager(m_laser_device_manager);
    m_test_pattern->setWindowModality(Qt::ApplicationModal);//阻塞其他窗体
    m_test_pattern->show();
}


void MainWindow1::on_DMX_ArtNet_Settings_triggered()
{
    DMX_setup *m_dmx_setup=new DMX_setup(this);
    m_dmx_setup->show();
//    m_artnet->init();
    m_dmx_setup->set_artnetPlugin(m_artnet);
    m_dmx_setup->fillOutputTree();
//    connect(m_dmx_setup,SIGNAL(set_artnet()),this,SLOT(set_artnet_server()));
}

void MainWindow1::set_artnet_slider_group()
{
    int n = 512;
    QWidget* slider_widgets = new QWidget(this);
    //slider_widgets->(71 * n);
    slider_widgets->setFixedWidth(71 * n);
    QHBoxLayout* horizontalLayout_8 = new QHBoxLayout(slider_widgets);
    for (int i = 0; i < n; i++)
    {
        QWidget *slide_group_0 = new QWidget(slider_widgets);
        char string[1] = { 0 };
        QString str = "slide_group_"+QString(itoa(i,string,10));
        slide_group_0->setObjectName(str);
        slide_group_0->setFixedSize(61, 148);
        QVBoxLayout *verticalLayout_10 = new QVBoxLayout(slide_group_0);
        str = "verticalLayout_" + QString(itoa(i + 10, string, 10));
        verticalLayout_10->setObjectName(str);
        QSpinBox *spinBox_0 = new QSpinBox(slide_group_0);
        str = "spinBox_" + QString(itoa(i , string, 10));
        spinBox_0->setObjectName(str);
        spinBox_0->setMaximum(254);
        spinBox_0->setFixedSize(43,20);
        verticalLayout_10->addWidget(spinBox_0);
        artnetdmx_slider * verticalSlider_0 = new artnetdmx_slider(slide_group_0);
        str = "verticalSlider_" + QString(itoa(i, string, 10));
        verticalSlider_0->setObjectName(str);
        verticalSlider_0->setMinimumSize(QSize(0, 84));
        verticalSlider_0->setOrientation(Qt::Vertical);
        verticalSlider_0->setFixedSize(22,80);
        verticalSlider_0->setMaximum(254);
        verticalLayout_10->addWidget(verticalSlider_0);
        QLabel* Label_0 = new QLabel(slide_group_0);
        str = "Label" + QString(itoa(i, string, 10));
        Label_0->setObjectName(str);
        Label_0->setFixedSize(43, 20);
        Label_0->setText(QString(itoa(i, string, 10)));
        verticalLayout_10->addWidget(Label_0);
        //connect_Slider_Spinbox(verticalSlider_0,spinBox_0);
        connect(verticalSlider_0, &QSlider::valueChanged, spinBox_0, &QSpinBox::setValue);
        connect(spinBox_0, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),verticalSlider_0, &QSlider::setValue);
        connect(verticalSlider_0,&QSlider::valueChanged,verticalSlider_0,&artnetdmx_slider::deal_value_changed);
        connect(verticalSlider_0,SIGNAL(value_changed(int,int)),this,SLOT(setupDMXData(int,int)));
        horizontalLayout_8->addWidget(slide_group_0);
    }
    QScrollArea* scroLLArea = new QScrollArea(this);
    QHBoxLayout* verticalLayout_9 = new QHBoxLayout(ui->tab_2);
    verticalLayout_9->addWidget(scroLLArea);    
    QPushButton* output_universe=new QPushButton(this);
    output_universe->setText("universe");
    verticalLayout_9->addWidget(output_universe);
    connect(output_universe,&QPushButton::clicked,this,&MainWindow1::output_universe);
    scroLLArea->setMinimumWidth(155);
    scroLLArea->setWidget(slider_widgets);
    scroLLArea->setWidgetResizable(true);//非常重要！！！！！！！！！！

}

void MainWindow1::set_track_panel()
{
    ui->verticalLayout_9->setMargin(0);
    ui->track_project_widget->setContentsMargins(0, 0, 0, 0);
    
    ui->horizontalLayout_2->setMargin(0);
    ui->track_list->setContentsMargins(0, 0, 0, 0);
    ui->horizontalLayout_8->setMargin(0);
    ui->list_tick_widget->setContentsMargins(0, 0, 0, 0);
    ui->horizontalLayout_13->setMargin(0);
    ui->tick_panel_widget->setContentsMargins(0, 0, 0, 0);
     
    connect(ui->horizontalScrollBar, &QScrollBar::valueChanged, [=](int value) {
        double dOffSet = static_cast<double>(value) / static_cast<double>(ui->horizontalScrollBar->maximum());
        ui->track_project_widget->move(-(ui->track_project_widget->width() - 350) * dOffSet, 0);     
        ui->tick_panel_widget->move(-(ui->tick_panel_widget->width() - 350) * dOffSet, 0);
        });
    connect(ui->verticalScrollBar, &QScrollBar::valueChanged, [=](int value) {
        double dOffSet = static_cast<double>(value) / static_cast<double>(ui->verticalScrollBar->maximum());
        ui->track_project_widget->move(0,-(ui->track_project_widget->height() - 176) * dOffSet);     
        ui->track_list->move(0, -(ui->track_list->height() - 176) * dOffSet);
        });
    ui->track_project_widget->setTrackList(ui->track_list);

    connect(ui->track_list, SIGNAL(set_Width(int)), ui->tick_panel_widget, SLOT(resizeWidth(int)));
    connect(ui->track_list, SIGNAL(setCurrentTime(float)), ui->track_project_widget, SLOT(setCurrent(float)));
    connect(ui->track_list, SIGNAL(addTrack(bool)), ui->track_project_widget, SLOT(acceptAddTrack(bool)));
    connect(ui->track_list, SIGNAL(set_Height(int)), ui->track_project_widget, SLOT(set_Height(int)));
   
}


void MainWindow1::on_Setup_Administritor_Mode_triggered()
{
    setup_Administrator_mode *m_setup_admin_mode=new setup_Administrator_mode(this);
    m_setup_admin_mode->show();
}


void MainWindow1::on_Setup_User_Mode_triggered()
{
    setup_user_mode *m_setup_user_mode=new setup_user_mode(this);
    m_setup_user_mode->show();
}


void MainWindow1::on_Midi_Monitor_triggered()
{
    midi_moniter *m_midi_monitor=new midi_moniter(this);
    m_midi_monitor->show();
}


void MainWindow1::on_Midi_Device_Settings_triggered()
{
    midi_device_settings *m_device_settings=new midi_device_settings(this);
    m_device_settings->show();
}


void MainWindow1::on_OSC_Settings_triggered()
{
    osc_settings *m_osc_setting=new osc_settings(this);
    m_osc_setting->show();
}

void MainWindow1::update_output_scene(int idx)
{
    if(idx<m_scene_panels.size()&&idx>-1)
    {
        m_scene_panels[idx]->update_scene(&m_output_panel->m_picture);
    }
}

void MainWindow1::main_timer_update()//检查update_show_index里有哪些scene
{
    m_output_panel->m_picture.clear();
    for(int i=update_show_index.size()-1;i>-1;i--)
    {
        if(m_scene_panels[update_show_index[i]]->is_selected())
            update_output_scene(update_show_index[i]);
        else if(m_scene_panels[update_show_index[i]]->is_mouse_enter())
        {
            update_output_scene(update_show_index[i]-40);
            m_scene_panels[update_show_index[i]]->do_draw(false);
        }
        else
        {
            update_output_scene(update_show_index[i]-40);
            m_scene_panels[update_show_index[i]]->m_frame_index=0;
            m_scene_panels[update_show_index[i]]->do_draw(true);
            update_show_index.erase(update_show_index.begin()+i);
        }
    }
    m_output_panel->do_draw();
    if(m_send_data && m_output_panel->m_picture.size()>0 )
    {
        for(int i=0;i<m_stages.size();++i)
        {
            auto s=m_stages.at(i);
            std::vector<ishow_data> out=m_output_panel->m_picture.globalprocessing(m_config);//全局处理
            s->add_send_data(out);
        }
    }
       
    if(update_show_index.size()==0)
        m_main_timer->stop();

}

void MainWindow1::line_timer_update()
{
    ui->track_list->setCurrentTime(timer_interval);
    ui->track_project_widget->m_current_time += (float)timer_interval / 1000;
    if (XConversion(ui->track_list->m_current_time, ui->track_list->m_interval_prop) > ui->track_project_widget->width())
    {
        ui->track_list->setCurrentTime(0);
        ui->track_project_widget->m_current_time = 0;
    }
    ui->track_project_widget->update();
    ui->track_list->play(m_play_show);
    qDebug() << "m_play_show:" << m_play_show;
    ui->track_list->updateOutputScene(&m_output_panel->m_picture);
    m_output_panel->do_draw();
    if (m_send_data && m_output_panel->m_picture.size() > 0)
    {
        for (int i = 0; i < m_stages.size(); ++i)
        {
            auto s = m_stages.at(i);
            std::vector<ishow_data> out = m_output_panel->m_picture.globalprocessing(m_config);//全局处理
            s->add_send_data(out);
        }
    }    
}

void MainWindow1::update_show_scene(int idx)//只处理添加
{
    if(!m_main_timer->isActive()) 
        m_main_timer->start(timer_interval);//开启主定时器线程
    if(idx>-1&&std::find(update_show_index.begin(),update_show_index.end(),idx)==update_show_index.end())
        update_show_index.push_back(idx);
}

void MainWindow1::readSinglePage(int page)
{
    qDebug() << "page:" << page;
    if (page < 0 | page == m_lastpage)
        return;

    m_scene_pool->readSinglePage(m_workspace_url,page); 

    set_page_data(m_scene_pool,page, ui->m_scenes_stack, ui->m_scenes_book);
    
    
    m_lastpage = page;
}

void MainWindow1::readQuickSinglePage(int page)
{
    qDebug() << "page:" << page;
    if (page < 0 | page == -m_lastpage)
        return;

    m_scene_pool->readSinglePage(m_workspace_url, page);

    set_page_data(m_scene_pool, page, ui->quick_scenes_stack, ui->quick_scenes_book,false);

    m_lastpage = -page;
}

artnetdmx_slider::artnetdmx_slider(QWidget *parent):
    QSlider(parent)
{

}

void artnetdmx_slider::deal_value_changed(int value)
{
    QString str=this->objectName().split("_").last();
    int index=str.toInt();
    emit value_changed(index,value);
}
