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
     //�½������ռ�
    connect(ui->actionNew_Workspace,&QAction::triggered,this,[=](){

      //  QMessageBox::information(this,"information","���Ƿ�Ҫ����һ�������ռ�",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        QMessageBox box(QMessageBox::Information, "��ʾ", "���Ƿ�Ҫ����һ�������ռ�");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, QString("ȷ��"));
        box.setButtonText(QMessageBox::Cancel, QString("ȡ��"));
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
    //�򿪹����ռ�
    connect(ui->actionOpen_Workspace,&QAction::triggered,this,[=](){
       QString fn = QFileDialog::getOpenFileName(this,"�򿪹����ռ�","/","BEYOND Workspace;;BEYOND Workspace only;;QuickShow Workspace(*.isw *.iSw)");
        emit this->openWorkspace(fn);
    });

    //���湤���ռ�
    connect(ui->actionSave_Workspace,&QAction::triggered,this,[=](){
         if(true)//û��ע����������
             DisSave();
    });
    //���湤���ռ䵽
    connect(ui->actionSave_WS_As,&QAction::triggered,this,[=](){
        if(true)///û��ע����������
            DisSave();
    });

    //���湤�����ĵ�ǰҳ
    connect(ui->actionS_Cur_P,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });

    //����������Ϊ����ҳ�汣�浽�ļ�����
    connect(ui->actionS_To_File,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });

    //�򿪲�����µ�ҳ�浽������
    connect(ui->actionww_2,&QAction::triggered,this,[=](){
        QFileDialog::getOpenFileName(this,"�򿪲�����µ�ҳ�浽������","/","BEYOND Page");
    });
    //�򿪲��滻��ǰѡ������ʾ��
    connect(ui->actionvv,&QAction::triggered,this,[=](){
        QFileDialog::getOpenFileName(this,"�򿪲��滻��ǰѡ������ʾ��","/","ALL supported formats;;BEYOND Cue(bcue);;QuickShow Cue(qcue)");
    });
    //����������ʾ�ڵ�ǰҳ���ļ���
    connect(ui->actionS_cue_to_F,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });
    //���浱ǰ��ѡ����ʾ
    connect(ui->actionS_Cur_cue,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });
    //��������������ʾ���浽�ļ���
    connect(ui->actionS_Acue_To_F,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });
    //���뼤��֡/��������Ŀ��
    connect(ui->actionEX_laser,&QAction::triggered,this,[=](){
        QFileDialog::getOpenFileName(this,"���뼤��֡/��������Ŀ��","/","ALL supported formats;;Parametric Image;;QS/BEYOND Frames(qsbframes);;QuickShow frames(qfrm);;LD/QM32 frames(ldb);;QuickShow Text(qtxt);;ILDA frames(ild);;QuickShow Shape(qabs);;LiveQUICK Animation(lqa);;QuickShow Synthesizer(qsyn);;LAStudio Picture(lpc);;QuickShow Clock(qclk);;QuickShow Cue(qcue);;LD2000 frames(lds);;LAStudio Abstract(lab);;QuickShow Show(qshw);;Lasershow Designer frames(lda);;LAStudio Write out(lwo);;BEYOND Multi Image(bmul);;BEYOND Show(bys);;QuickShow DMX(qdmx);;BEYOND Parametric image(bpim);;Polar Image;;BEYOND Animation(bani);;FB4 SD Project;;BEYOND Cue(bcue);;LAStudio Animated words(law);;BEYOND Text image(btxt);;BEYOND Beams(bbem);;BEYOND DMX Image;;BEYOND DMX(bdmx);;BEYOND Frames(bfrm);;BEYOND Text(btxt);;BEYOND Shape(babs);;BEYOND Image Synth(bsyn);;BEYOND Clock(bclk);;Pangolin Content");
    });
    //������Ŀ��
    //������ʾ������ͼ
    connect(ui->actionEx_Cue_thu,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });
    //FB4����
    connect(ui->action_FB4_Export,&QAction::triggered,this,[=](){
        FB4_E.show();
    });
    //FB4���
    connect(ui->actionFB4_B,&QAction::triggered,this,[=](){
        QMessageBox::information(this,"Information","û������Pangolin FB4Ӳ����BEYOND\n����FB4����ʱ���ļ�����ſ���");
    });
    //FB4����
    connect(ui->actionFB4_S,&QAction::triggered,this,[=](){
        F_S.show();
    });
    //FB4�ļ����
    connect(ui->actionFB4_B_v,&QAction::triggered,this,[=](){
       F_B_V.show();
    });
    //�򿪲��滻QuickFx
    connect(ui->actionQuickFX,&QAction::triggered,this,[=](){
        QMessageBox box(QMessageBox::Question, "�򿪲��滻QuickFx", "�Ƿ�ȷʵҪ�ô��ļ����ص�Ч���滻Quickfxѡ��ϵ�����Ч����");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, QString("��"));
        box.setButtonText(QMessageBox::Cancel, QString("��"));
        box.exec();
    });
    //�ӹ��������� quickFx
    connect(ui->actionSave_QkFx,&QAction::triggered,this,[=](){
        if(true)//û��ע����������
            DisSave();
    });
    //��Ŀ��Ϣ��
    connect(ui->actionP_G_I,&QAction::triggered,this,[=](){
        P_G_I.show();
    });
    //���ô�BEYOND����
    connect(ui->actionSetpassword,&QAction::triggered,this,[=](){
        s.exec();
    });
    //�˳�
    connect(ui->actionQuit,&QAction::triggered,this,[=](){
        QMessageBox box(QMessageBox::Information, "Confirm", "���Ƿ�ȷ��Ҫ�ر�BEYOND");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, QString("ȷ��"));
        box.setButtonText(QMessageBox::Cancel, QString("ȡ��"));
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
    strList.append("����");strList.append("������״");strList.append("����2");
    strList.append("�˶�");strList.append("����");strList.append("���");
    strList.append("����");strList.append("����");strList.append("����1");
    strList.append("����2");strList.append("����");strList.append("����");
    strList.append("������");strList.append("����1");strList.append("����2");
    strList.append("����3");strList.append("�û�ͼ��");strList.append("�û���ʶa");
    strList.append("���1");strList.append("���2");strList.append("����1");
    strList.append("����2");strList.append("Բ׶��1");strList.append("Բ׶��2");
    strList.append("��1");strList.append("��2");strList.append("Fans of Beams 1");
    strList.append("Fans of Beams 2");strList.append("Hot Beams 1");strList.append("Hot Beams 2");
    strList.append("��1");strList.append("��2");strList.append("��3");
    strList.append("���1");strList.append("���2");strList.append("Ŀ��");
    strList.append("��������");strList.append("�û���Χ");strList.append("��");
    strList.append("���ı�");strList.append("����");strList.append("�򵥵�");
    strList.append("���� BCP 1");strList.append("���� BCP 2");strList.append("���� BCP 3");
    strList.append("Ƭ״ BCP 1");strList.append("Ƭ״ BCP 2");strList.append("Ƭ״ BCP 3");
    strList.append("׶�� BCP 1");strList.append("׶�� BCP 2");strList.append("׶�� BCP 3");
    strList.append("���� BCP 1");strList.append("���� BCP 2");strList.append("���� BCP 3");
    strList.append("�� BCP 1");strList.append("�� BCP 2");strList.append("�� BCP 3");
    strList.append("��� 3(BCP)");strList.append("����ˢ1");strList.append("����ˢ2");
    strList.append("�����û�ˢ");strList.append("����ˢ1");strList.append("����ˢ2");
    strList.append("����ˢ3");strList.append("���ʳ���");strList.append("�û�����ժҪ");
    strList.append("ˢ��");strList.append("ˢ��2");strList.append("ˢ��ͼ��");strList.append("��ˢ����");
    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);//����ÿ�е�ֵ
    }
    //ui->listView_37->setModel(ItemModel);
    //ui->listView->setFixedSize(200,300);//����listView�Ĵ�С
}
void MainWindow::initAll2()
{
    ItemModel = new QStandardItemModel(this);
    QStringList strList;
    strList.append("�Ŵ�");strList.append("����");strList.append("���潥��");
    strList.append("����");strList.append("����");strList.append("�������");
    strList.append("�����ұ�");strList.append("���򶥲�");strList.append("����ײ�");
    strList.append("�޼�����"); strList.append("�޼��ײ�");strList.append("�����޼�");strList.append("�����޼�");
    strList.append("���޼�");strList.append("�����");strList.append("���ſ�");
    strList.append("��������");strList.append("������ת");strList.append("��LB");
    strList.append("��RB");strList.append("��RT");
    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);//����ÿ�е�ֵ
    }
    ui->listView_2->setModel(ItemModel);
    //ui->listView->setFixedSize(200,300);//����listView�Ĵ�С
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
    QMessageBox msg;//���messageBox���������
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
    QMessageBox box(QMessageBox::Information, "����ʧ��", "��ǰ�ѽ��ñ��档\n�Ҳ������֤����ע�����������");
    box.setStandardButtons(QMessageBox::Ok );
    box.setButtonText(QMessageBox::Ok, QString("����ע������֤������"));

    box.exec();
}
