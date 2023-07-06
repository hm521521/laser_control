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
    ui->zone_names_tableView->setModel(theModel);
    ui->zone_names_tableView->setSelectionModel(theSelection);
    ui->zone_names_tableView->verticalHeader()->setHidden(true);
    ui->zone_names_tableView->horizontalHeader()->setHidden(true);
    ui->zone_names_tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->zone_names_tableView->setTextElideMode(Qt::ElideNone);
//    ui->zone_names_tableView->setWordWrap(true);
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
    new_pro_settings();
    m_button_group=new QButtonGroup(this);
    m_button_group->addButton(ui->New_pushButton,0);
    m_button_group->addButton(ui->Open_pushButton,1);
    m_button_group->addButton(ui->Save_pushButton,2);
    m_button_group->addButton(ui->Add_pushButton,3);
    m_button_group->addButton(ui->Del_pushButton,4);
    m_button_group->addButton(ui->Copy_pushButton,5);
    connect(m_button_group,SIGNAL(buttonClicked(int)),this,SLOT(buttonClicked(int)));
//    m_namelist.clear();
}

projection_zones::~projection_zones()
{
    if(m_qsettings)
        save_settings();
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
//    str.append("\n");
    m_namelist.push_back(str);
    if (m_namelist.length()>1)
        ui->delete_zone_pushButton->setEnabled(true);
    QString istr;
    int i=0;
    theModel->setRowCount(m_namelist.length());
    foreach (istr,m_namelist)
    {
        istr.append(QString::fromUtf8("\nProjector:"));
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

void projection_zones::buttonClicked(int index)
{
    switch (index)
    {
        case 0:
        {
            new_pro_settings();
            break;
        }
        case 1:
        {
            open_settings();
            break;
        }
        case 2:
        {
            save_settings();
            break;
        }
        case 3:
        {
            add_projection_zone();
        }
        case 4:
        {

        }
        default:
        {
            break;
        }
    }
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

void projection_zones::load_settings()
{
    if(!m_qsettings)
        return;
    int size=m_qsettings->beginReadArray("projector_zone_settings");

    for(int i=0;i<size;++i)
    {
        m_qsettings->setArrayIndex(i);
        pro_zone_settings setting;
        setting.apply_attenuation=m_qsettings->value("apply_attenuation").toBool();
        setting.attenuation_picture=m_qsettings->value("attenuation_picture").toByteArray();
        setting.beam_diameter=m_qsettings->value("beam_diameter").toInt();
        setting.ct=m_qsettings->value("ct").value<correction_type>();
        setting.dis_pat=m_qsettings->value("dis_pat").value<display_pattern>();
        setting.height=m_qsettings->value("height").toInt();
        setting.width=m_qsettings->value("width").toInt();
        setting.position_x=m_qsettings->value("position_x").toInt();
        setting.position_y=m_qsettings->value("position_y").toInt();
        setting.prepat=m_qsettings->value("prepat").value<preview_pattern>();
        setting.pro_zone_name=m_qsettings->value("pro_zone_name").toString();
        setting.rotation=m_qsettings->value("rotation").toInt();
        setting.x=m_qsettings->value("x").toInt();
        setting.y=m_qsettings->value("y").toInt();
        setting.YAG_projector=m_qsettings->value("YAG_projector").toBool();
        m_settings.append(setting);
    }
    m_qsettings->endArray();
}

void projection_zones::save_settings()
{
    if(!m_qsettings)
        return;
    m_qsettings->beginWriteArray("projector_zone_settings");
    for(int i=0;i<m_settings.size();++i)
    {
        m_qsettings->setArrayIndex(i);
        pro_zone_settings setting=m_settings.at(i);
        m_qsettings->setValue("apply_attenuation",setting.apply_attenuation);
        m_qsettings->setValue("attenuation_picture",setting.attenuation_picture);
        m_qsettings->setValue("beam_diameter",setting.beam_diameter);
        m_qsettings->setValue("ct",QVariant::fromValue(setting.ct));
        m_qsettings->value("dis_pat",QVariant::fromValue(setting.dis_pat));
        m_qsettings->setValue("height",setting.height);
        m_qsettings->setValue("width",setting.width);
        m_qsettings->setValue("position_x",setting.position_x);
        m_qsettings->setValue("position_y",setting.position_y);
        m_qsettings->value("prepat",QVariant::fromValue(setting.prepat));
        m_qsettings->setValue("pro_zone_name",setting.pro_zone_name);
        m_qsettings->setValue("rotation",setting.rotation);
        m_qsettings->setValue("x",setting.x);
        m_qsettings->setValue("y",setting.y);
        m_qsettings->setValue("YAG_projector",QVariant::fromValue(setting.YAG_projector));
    }
    m_qsettings->endArray();
}

void projection_zones::new_pro_settings()
{
    m_qsettings=new QSettings("/system/pro_zone_settings.ini",QSettings::IniFormat);
    load_settings();
}

void projection_zones::open_settings()
{
    QUrl fileUrl=QFileDialog::getOpenFileUrl(this,"打开投影区域",QUrl("./System/Settings"),tr("settings(*.ini)"));
    QString filepath=fileUrl.path();
    m_qsettings=new QSettings(filepath,QSettings::IniFormat);
    load_settings();
}

void projection_zones::add_projection_zone()
{
    add_zones_dialog *a=new add_zones_dialog(this);
    connect(a, SIGNAL(zone_name(QString)),this,SLOT(newZoneName(QString)));
    a->show();
}
