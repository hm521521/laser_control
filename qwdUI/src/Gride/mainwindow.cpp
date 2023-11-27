#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QFileDialog>
#include<QColorDialog>
#include<QStackedWidget>
#include<QListWidget>
#include<QDebug>
#include <QQuickWidget>
#include <QQmlContext>>
#include <QQuickView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initAll37();
    initAll2();
    //initGraphics();


    //connect(ui->listView_37,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));
    connect(ui->listView_2,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));
     //新建工作空间
    connect(ui->actionNew_Workspace,&QAction::triggered,this,[=](){

      //  QMessageBox::information(this,"information","你是否要创建一个工作空间",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        QMessageBox box(QMessageBox::Information, "提示", "你是否要创建一个工作空间");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, QString("确定"));
        box.setButtonText(QMessageBox::Cancel, QString("取消"));
        int ret = box.exec();
//        switch (ret) {
//        case QMessageBox::Ok:
//            qDebug() << "QMessageBox::Ok!";
//            break;
//        case QMessageBox::Cancel:
//            qDebug() << "QMessageBox::Cancel!";
//            break;
//        }
    });
    //打开工作空间
    connect(ui->actionOpen_Workspace,&QAction::triggered,this,[=](){
       QString fn = QFileDialog::getOpenFileName(this,"打开工作空间","/","BEYOND Workspace;;BEYOND Workspace only;;QuickShow Workspace(*.isw *.iSw)");
        emit this->openWorkspace(fn);
    });

    //保存工作空间
    connect(ui->actionSave_Workspace,&QAction::triggered,this,[=](){
         if(true)//没有注册软件的情况
             DisSave();
    });
    //保存工作空间到
    connect(ui->actionSave_WS_As,&QAction::triggered,this,[=](){
        if(true)///没有注册软件的情况
            DisSave();
    });

    //保存工作区的当前页
    connect(ui->actionS_Cur_P,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });

    //将工作区作为独立页面保存到文件夹中
    connect(ui->actionS_To_File,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });

    //打开并添加新的页面到工作区
    connect(ui->actionww_2,&QAction::triggered,this,[=](){
        QFileDialog::getOpenFileName(this,"打开并添加新的页面到工作区","/","BEYOND Page");
    });
    //打开并替换当前选定的提示音
    connect(ui->actionvv,&QAction::triggered,this,[=](){
        QFileDialog::getOpenFileName(this,"打开并替换当前选定的提示音","/","ALL supported formats;;BEYOND Cue(bcue);;QuickShow Cue(qcue)");
    });
    //保存所有提示在当前页面文件夹
    connect(ui->actionS_cue_to_F,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });
    //保存当前的选择提示
    connect(ui->actionS_Cur_cue,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });
    //将工作区所有提示保存到文件夹
    connect(ui->actionS_Acue_To_F,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });
    //导入激光帧/动画到节目格
    connect(ui->actionEX_laser,&QAction::triggered,this,[=](){
        QFileDialog::getOpenFileName(this,"导入激光帧/动画到节目格","/","ALL supported formats;;Parametric Image;;QS/BEYOND Frames(qsbframes);;QuickShow frames(qfrm);;LD/QM32 frames(ldb);;QuickShow Text(qtxt);;ILDA frames(ild);;QuickShow Shape(qabs);;LiveQUICK Animation(lqa);;QuickShow Synthesizer(qsyn);;LAStudio Picture(lpc);;QuickShow Clock(qclk);;QuickShow Cue(qcue);;LD2000 frames(lds);;LAStudio Abstract(lab);;QuickShow Show(qshw);;Lasershow Designer frames(lda);;LAStudio Write out(lwo);;BEYOND Multi Image(bmul);;BEYOND Show(bys);;QuickShow DMX(qdmx);;BEYOND Parametric image(bpim);;Polar Image;;BEYOND Animation(bani);;FB4 SD Project;;BEYOND Cue(bcue);;LAStudio Animated words(law);;BEYOND Text image(btxt);;BEYOND Beams(bbem);;BEYOND DMX Image;;BEYOND DMX(bdmx);;BEYOND Frames(bfrm);;BEYOND Text(btxt);;BEYOND Shape(babs);;BEYOND Image Synth(bsyn);;BEYOND Clock(bclk);;Pangolin Content");
    });
    //导出节目格
    //导出提示音缩略图
    connect(ui->actionEx_Cue_thu,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });
    //FB4导出
    connect(ui->action_FB4_Export,&QAction::triggered,this,[=](){
        FB4_E.show();
    });
    //FB4浏览
    connect(ui->actionFB4_B,&QAction::triggered,this,[=](){
        QMessageBox::information(this,"Information","没有连接Pangolin FB4硬件到BEYOND\n仅当FB4连接时，文件管理才可用");
    });
    //FB4设置
    connect(ui->actionFB4_S,&QAction::triggered,this,[=](){
        F_S.show();
    });
    //FB4文件浏览
    connect(ui->actionFB4_B_v,&QAction::triggered,this,[=](){
       F_B_V.show();
    });
    //打开并替换QuickFx
    connect(ui->actionQuickFX,&QAction::triggered,this,[=](){
        QMessageBox box(QMessageBox::Question, "打开并替换QuickFx", "是否确实要用从文件加载的效果替换Quickfx选项卡上的所有效果？");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, QString("是"));
        box.setButtonText(QMessageBox::Cancel, QString("否"));
        box.exec();
    });
    //从工作区保存 quickFx
    connect(ui->actionSave_QkFx,&QAction::triggered,this,[=](){
        if(true)//没有注册软件的情况
            DisSave();
    });
    //节目信息池
    connect(ui->actionP_G_I,&QAction::triggered,this,[=](){
        P_G_I.show();
    });
    //设置打开BEYOND密码
    connect(ui->actionSetpassword,&QAction::triggered,this,[=](){
        s.exec();
    });
    //退出
    connect(ui->actionQuit,&QAction::triggered,this,[=](){
        QMessageBox box(QMessageBox::Information, "Confirm", "你是否确定要关闭BEYOND");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, QString("确定"));
        box.setButtonText(QMessageBox::Cancel, QString("取消"));
        box.exec();
//        int ret = box.exec();
    });

    //page_104
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAll37()
{
    ItemModel = new QStandardItemModel(this);
    QStringList strList;
    strList.append("动物");strList.append("人物形状");strList.append("人物2");
    strList.append("运动");strList.append("汽车");strList.append("庆典");
    strList.append("汽车");strList.append("场景");strList.append("主题1");
    strList.append("主题2");strList.append("假期");strList.append("混杂");
    strList.append("颗粒物");strList.append("背景1");strList.append("背景2");
    strList.append("背景3");strList.append("用户图形");strList.append("用户标识a");
    strList.append("板块1");strList.append("板块2");strList.append("波浪1");
    strList.append("波浪2");strList.append("圆锥体1");strList.append("圆锥体2");
    strList.append("框1");strList.append("框2");strList.append("Fans of Beams 1");
    strList.append("Fans of Beams 2");strList.append("Hot Beams 1");strList.append("Hot Beams 2");
    strList.append("键1");strList.append("键2");strList.append("键3");
    strList.append("混合1");strList.append("混合2");strList.append("目标");
    strList.append("经典数据");strList.append("用户氛围");strList.append("简单");
    strList.append("简单文本");strList.append("简单线");strList.append("简单点");
    strList.append("波浪 BCP 1");strList.append("波浪 BCP 2");strList.append("波浪 BCP 3");
    strList.append("片状 BCP 1");strList.append("片状 BCP 2");strList.append("片状 BCP 3");
    strList.append("锥体 BCP 1");strList.append("锥体 BCP 2");strList.append("锥体 BCP 3");
    strList.append("辐条 BCP 1");strList.append("辐条 BCP 2");strList.append("辐条 BCP 3");
    strList.append("点 BCP 1");strList.append("点 BCP 2");strList.append("点 BCP 3");
    strList.append("混合 3(BCP)");strList.append("抽象刷1");strList.append("抽象刷2");
    strList.append("抽象用户刷");strList.append("抽象刷1");strList.append("抽象刷2");
    strList.append("抽象刷3");strList.append("画笔抽象");strList.append("用户画笔摘要");
    strList.append("刷梁");strList.append("刷梁2");strList.append("刷子图案");strList.append("梁刷测试");
    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);//加入每行的值
    }
    //ui->listView_37->setModel(ItemModel);
    //ui->listView->setFixedSize(200,300);//设置listView的大小
}
void MainWindow::initAll2()
{
    ItemModel = new QStandardItemModel(this);
    QStringList strList;
    strList.append("放大");strList.append("淡入");strList.append("交叉渐变");
    strList.append("变形");strList.append("横切");strList.append("滚向左边");
    strList.append("滚向右边");strList.append("滚向顶部");strList.append("滚向底部");
    strList.append("修剪顶部"); strList.append("修剪底部");strList.append("向内修剪");strList.append("向外修剪");
    strList.append("门修剪");strList.append("拉伸口");strList.append("缩放口");
    strList.append("交叉缩放");strList.append("交叉旋转");strList.append("角LB");
    strList.append("角RB");strList.append("角RT");
    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);//加入每行的值
    }
    ui->listView_2->setModel(ItemModel);
    //ui->listView->setFixedSize(200,300);//设置listView的大小
}

void MainWindow::setQmlUIGrid(QUrl qml, QObject* ctx)
{
    QQuickView *v = new QQuickView(qml);
    v->rootContext()->setContextProperty("UC_Workspace", ctx);
    ui->page_104->layout()->removeWidget(ui->quickWidget);

    QWidget *container = QWidget::createWindowContainer(v, ui->page_104);
    container->setObjectName("wrappingContainer");
    ui->page_104->layout()->addWidget(container);

    //ui->quickWidget->setSource(qml);
    //ui->quickWidget->rootContext()->setContextProperty("UC_Workspace", ctx);
    // set uictrl_cueWs
    //ui->widget_98->setParent(nullptr);
    //qDebug()<<ui->widget_98->geometry();
    //widget->setGeometry(ui->widget_98->geometry());
    //widget->setSizePolicy(ui->widget_98->sizePolicy());
    //widget->setParent(ui->widget_98);

    //QGridLayout *l = new QGridLayout(ui->page_104);
    //l->addWidget(widget, 0, 0, 1, 1);
}


void MainWindow::showClick(QModelIndex index)
{
    QString strTemp;
    strTemp = index.data().toString();
    QMessageBox msg;//提出messageBox里面的内容
    msg.setText(strTemp);
    msg.exec();
}

void MainWindow::on_pushButton_172_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
    ui->stackedWidget_12->setCurrentIndex(0);
    //ui->tabWidget_5->setCurrentIndex(2);
    ui->Play_stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_pushButton_173_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
    ui->stackedWidget_12->setCurrentIndex(1);
    ui->Grid_Playpage_3->show();
}


void MainWindow::on_pushButton_174_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::DisSave(){
    QMessageBox box(QMessageBox::Information, "保存失败", "当前已禁用保存。\n找不到许可证，请注册您的软件。");
    box.setStandardButtons(QMessageBox::Ok );
    box.setButtonText(QMessageBox::Ok, QString("开放注册和许可证管理器"));

    box.exec();
}
