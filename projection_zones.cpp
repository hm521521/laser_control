#include "projection_zones.h"
#include "ui_projection_zones.h"
#include "add_zones_dialog.h"
#include <QString>
#include <QMessageBox>


projection_zones::projection_zones(MainWindow1 *parent) :
    SubWindow(),
    ui(new Ui::projection_zones),
    m_type("projection_zones")
{
    ui->setupUi(this);
//    QStringListModel *model=new QStringListModel(m_namelist);
    m_parent=parent;
    theModel = new QStandardItemModel(0,1,this); //创建数据模型
    theSelection = new QItemSelectionModel(theModel);//Item选择模型
//    ui->tableView->setSelectionModel(theSelection);//设置选择模型
    ui->zone_names_listView->setModel(theModel);
    ui->zone_names_listView->setSelectionModel(theSelection);
    if (m_namelist.length()<=1)
        ui->delete_zone_pushButton->setEnabled(false);
    theProjectorModel = new QStandardItemModel(0,1,this); //创建数据模型
    theProjectorSelection = new QItemSelectionModel(theModel);//Item选择模型
    ui->projector_tableView->setModel(theProjectorModel); //设置数据模型
    ui->projector_tableView->setSelectionModel(theProjectorSelection);//设置选择模型
    ui->projector_tableView->verticalHeader()->setHidden(true);
    ui->projector_tableView->horizontalHeader()->setHidden(true);
    ui->projector_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->projector_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    refresh_laser_device();
//    m_namelist.clear();
}

projection_zones::~projection_zones()
{
    delete ui;
}

QString projection_zones::getMyType()
{
    return m_type;
}

void projection_zones::newZoneName(QString str)
{
    if (!(m_namelist.filter(str)).isEmpty()||str=="")
        return;
    m_namelist.push_back(str);
    if (m_namelist.length()>1)
        ui->delete_zone_pushButton->setEnabled(true);
    QString istr;
    int i=0;

    theModel->setRowCount(m_namelist.length());
    foreach (istr,m_namelist)
    {
        QModelIndex index=theModel->index(i,0);//获取模型索引
        theSelection->clearSelection(); //清除现有选择
        theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
        theModel->setData(index,istr,Qt::DisplayRole);//设置单元格字符串
        i++;
    }
    if (m_namelist.length()<=1)
        ui->delete_zone_pushButton->setEnabled(false);


}


void projection_zones::on_addZones_pushButton_clicked()
{
    add_zones_dialog *a=new add_zones_dialog(this);
    connect(a, SIGNAL(zone_name(QString)),this,SLOT(newZoneName(QString)));
    a->show();
}


void projection_zones::on_delete_zone_pushButton_clicked()
{

    QMessageBox delete_zone;
    delete_zone.setWindowTitle("Delete Projection Zone name");
//    QMessageBox::question(this, "","Would like you to delete Projection zone name");
    QPushButton *yesButton=delete_zone.addButton(tr("是(Y)"),QMessageBox::ActionRole);
    QPushButton *noButton=delete_zone.addButton(tr("否(N)"),QMessageBox::ActionRole);
    delete_zone.setText(tr("Would like you to delete Projection zone name"));
    delete_zone.exec();
    if(delete_zone.clickedButton()==yesButton)
    {
        int k=ui->zone_names_listView->selectionModel()->currentIndex().row();
        m_namelist.removeAt(k);
        QString istr;
        int i=0;
        theModel->setRowCount(m_namelist.length());
        foreach (istr,m_namelist)
        {
            QModelIndex index=theModel->index(i,0);//获取模型索引
            theSelection->clearSelection(); //清除现有选择
            theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
            theModel->setData(index,istr,Qt::DisplayRole);//设置单元格字符串
            i++;
        }
    }
    else if (delete_zone.clickedButton()==noButton)
    {
        delete_zone.close();

    }
    if (m_namelist.length()<=1)
        ui->delete_zone_pushButton->setEnabled(false);
}


void projection_zones::refresh_laser_device()
{
//    laser_device_manager *m=m_parent->get_laser_manager();
//    laser_device *dev;
//    theModel->setRowCount(m_parent->get_device_num());
//    int i=0;
//    foreach(dev,*m)
//    {
//        QModelIndex index=theModel->index(i,0);//获取模型索引
//        theSelection->clearSelection(); //清除现有选择
//        theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
//        theModel->setData(index,dev->get_name(),Qt::DisplayRole);//设置单元格字符串
//        i++;
//    }
}
