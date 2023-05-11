#include "hardware.h"
#include "ui_hardware.h"
//#include"ed_laser_output.h"

//constexpr unsigned short tcp_port = 4000;
#define TCP_SERVER_PORT		7765
#define UDP_SERVER_PORT		1200
#define UDP_TARGET_PORT     7654


hardware::hardware(QWidget *parent) :
    SubWindow(),
    ui(new Ui::hardware),
    m_udpsocket(nullptr),
    m_type("hardware")
//    m_laser_device_manager(parent->m_laser_device_manager)
{
    Configuration *m_config=new Configuration();//配置对象
    m_config->Load();
    m_output_stage=new stage(this);
    ui->setupUi(this);
//    parent->setEnabled(false);
    theModel = new QStandardItemModel(1,3,this); //创建数据模型
    theSelection = new QItemSelectionModel(theModel);//Item选择模型
    ui->tableView->setModel(theModel); //设置数据模型
    ui->tableView->setSelectionModel(theSelection);//设置选择模型
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList strList;//获取对话框上修改后的StringList
    strList.append("#");
    strList.append("Hardware-Projector");
    strList.append("Projection Zones");
    theModel->setHorizontalHeaderLabels(strList);// 设置模型的表头标题
    connect(ui->tableView,SIGNAL(table_selected(QVariant)),this,SLOT(on_table_selected(QVariant)));
}

hardware::~hardware()
{
    delete ui;
}

void hardware::closeEvent(QCloseEvent *event)
{
//    m_parent->setEnabled(true);
    QMainWindow::closeEvent(event);
}
void hardware::on_Plus_Button_clicked()
{

}


//void hardware::onSocketReadyRead()//UDP主机：10.200.26.233 :1200/本地主机：10.200.26.233 :7654
////UDP接收内容格式：fromUDP hahahahaF8-16-54-B3-9D-7710.200.26.233
//{
//    if(m_udpsocket->bytesAvailable())
//    {
//        QByteArray   datagram;
//        datagram.resize(m_udpsocket->pendingDatagramSize());

//        QHostAddress    peerAddr;
//        quint16 peerPort;
//        m_udpsocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
//        QString data(datagram.data());
//        QString name;
//        QString head;
//        QString mac;
//        QString addr;
//        for(int i=0;i<8;i++)
//        {
//           head.append(data.at(i));
//        }
//        if (!(head=="fromUDP ")){return;}

//        try
//        {
//            for(int i=8;i<16;i++)
//            {
//                name.append(data.at(i));
//            }
//            for(int i=16;i<33;i++)
//            {
//                mac.append(data.at(i));
//            }
//    //        memcpy(&mac,datagram.data(),datagram.size());

//            for(int i=34;i<data.length();i++)
//            {
//                addr.append(data.at(i));
//            }
//        }
//        catch(...)
//        {
//            return;
//        }

////        memcpy(&addr,datagram.data(),datagram.size());

//        laser_device *dev;
////        laser_device_manager *m=m_parent->get_laser_manager();
////        foreach(dev,*m)
////        {
////            if(dev->is_create_by(mac))
////            {
//////                m_udpsocket->deleteLater();
////                return;
////            }
////        }
////        laser_device *device=new laser_device(name,mac,addr);
////        m_manager->push_back(device);

////        m->push_back(device);
////        m_parent->set_laser_manager(m);
////        int num=m_parent->get_device_num();
////        num++;
////        m_parent->set_device_num(num);
//        return;
//    }
//}

QString hardware::getMyType()
{
    return m_type;
}

void hardware::set_output(stage *output_stage)
{
    m_output_stage=output_stage;
    if(m_output_stage)
    {
        m_enable_out=true;
    }
    else
        m_enable_out=false;
}

void hardware::on_Refresh_Button_clicked()
{
//    emit refresh_laser_device();
//    m_laser_device_manager->refresh_laser_device();
//    broadcast();
    myTimer->start(20);
}

void hardware::on_table_selected(QVariant s)
{
    m_output_stage->set_device(new ed_v2_device(s.toString()));
    emit stage_changed(m_output_stage);
}

void hardware::refresh_laser_device(QVector<laser_device*> device_list){
//    laser_device *dev;
    theModel->setRowCount(device_list.size());
//    int i=0;
//    laser_device_manager*m=m_parent->get_laser_manager();
//    foreach(dev,m_laser_device_manager->get_device_list())
    for (int i=0;i<device_list.size();++i)
    {
        auto dev=device_list.at(i);
        QModelIndex index=theModel->index(i,0);//获取模型索引
        theSelection->clearSelection(); //清除现有选择
        theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
        theModel->setData(index,i+1,Qt::DisplayRole);//设置单元格字符串
        index=theModel->index(i,1);//获取模型索引
        theSelection->clearSelection(); //清除现有选择
        theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
        theModel->setData(index,dev->get_name(),Qt::DisplayRole);//设置单元格字符串
    }
}


hardware_table::hardware_table(QWidget *parent):QTableView(parent)
{
//    connect(this,clicked())
//    connect(this,SIGNAL(QModelIndex),)
}


void hardware_table::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    if(selected.size()>1)
    {
        auto text=selected.indexes().at(0).model()->index(0,1).data();
        emit table_selected(text);
    }
//    if(deselected.size()>1)
//    {
//        auto text=deselected.indexes().at(0).model()->index(0,1).data();
//        emit table_deselected(text);
//    }

//    s->set_device();
//    m_stages.push_back(s);
}
