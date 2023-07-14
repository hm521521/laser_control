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
    m_device_table=ui->projector_tableView;
//    refresh_laser_device();
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
    m_qsettings=new QSettings("./system/pro_zone_settings.ini",QSettings::IniFormat);
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
    pro_zone_settings newsettings;
    newsettings.pro_zone_name=str;
    init_settings(newsettings);
    try
    {
        newsettings.projector_name=m_device_table->model()->data(m_device_table->model()->index(0,0)).toString();
    }
    catch(...)
    {
        newsettings.projector_name="";
    }
    m_settings.push_back(newsettings);
    if (m_namelist.length()>1)
        ui->delete_zone_pushButton->setEnabled(true);
    QString istr;
    int i=0;
    theModel->setRowCount(m_namelist.length());
    foreach (istr,m_namelist)
    {
        istr.append(QString::fromUtf8("\nProjector 1:"));
        istr.append(m_device_table->model()->data(m_device_table->model()->index(0,0)).toString());
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
        setting.pro_zone_name=m_qsettings->value("pro_zone_name").toString();
        setting.corsize.x=m_qsettings->value("corsize_x").toFloat();
        setting.corsize.y=m_qsettings->value("corsize_y").toFloat();
        setting.corpos.x=m_qsettings->value("corpos_x").toFloat();
        setting.corpos.y=m_qsettings->value("corpos_y").toFloat();
        setting.corrot.angle=m_qsettings->value("corrot_angle").toFloat();
        setting.corline.x=m_qsettings->value("corline_x").toFloat();
        setting.corline.y=m_qsettings->value("corline_y").toFloat();
        setting.corsym.left=m_qsettings->value("corsym_left").toFloat();
        setting.corsym.right=m_qsettings->value("corsym_right").toFloat();
        setting.corsym.top=m_qsettings->value("corsym_top").toFloat();
        setting.corsym.bottom=m_qsettings->value("corsym_bottom").toFloat();
        setting.corkeystone.x=m_qsettings->value("corkeystone_x").toFloat();
        setting.corkeystone.y=m_qsettings->value("corkeystone_y").toFloat();
        setting.corpin.left=m_qsettings->value("corpin_left").toFloat();
        setting.corpin.right=m_qsettings->value("corpin_right").toFloat();
        setting.corpin.top=m_qsettings->value("corpin_top").toFloat();
        setting.corpin.bottom=m_qsettings->value("corpin_bottom").toFloat();
        setting.corbow.left=m_qsettings->value("corbow_left").toFloat();
        setting.corbow.right=m_qsettings->value("corbow_right").toFloat();
        setting.corbow.top=m_qsettings->value("corbow_top").toFloat();
        setting.corbow.bottom=m_qsettings->value("corbow_bottom").toFloat();
        setting.corshear.x=m_qsettings->value("corshear_x").toFloat();
        setting.corshear.y=m_qsettings->value("corshear_y").toFloat();
        setting.preview_width=m_qsettings->value("preview_width").toInt();
        setting.preview_height=m_qsettings->value("preview_height").toInt();
        setting.preview_position_x=m_qsettings->value("preview_position_x").toInt();
        setting.preview_position_y=m_qsettings->value("preview_position_y").toInt();
        setting.preview_rotation=m_qsettings->value("preview_rotation").toInt();
        setting.preview_beam_diameter=m_qsettings->value("preview_beam_diameter").toInt();
        setting.attenuation_picture=m_qsettings->value("attenuation_picture").toByteArray();
        setting.projector_name=m_qsettings->value("projector_name").toString();
        setting.scanbeam.emuLaserPosX=m_qsettings->value("scanbeam_emuLaserPosX").toFloat();
        setting.scanbeam.emuLaserPosY=m_qsettings->value("scanbeam_emuLaserPosY").toFloat();
        setting.preerp.fogDesigty=m_qsettings->value("preerp_fogDesigty").toInt();
        setting.preerp.fogFrontBrightness=m_qsettings->value("preerp_fogFrontBrightness").toInt();
        setting.preerp.fogRearBrightness=m_qsettings->value("preerp_fogRearBrightness").toInt();
        setting.preerp.fogSpeed=m_qsettings->value("preerp_fogSpeed").toInt();
        setting.preerp.gauzeScreenDistance=m_qsettings->value("preerp_gauzeScreenDistance").toInt();
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
        m_qsettings->setValue("pro_zone_name",setting.pro_zone_name);
        m_qsettings->setValue("corsize_x",setting.corsize.x);
        m_qsettings->setValue("corsize_y",setting.corsize.y);
        m_qsettings->setValue("corpos_x",setting.corpos.x);
        m_qsettings->setValue("corpos_y",setting.corpos.y);
        m_qsettings->setValue("corrot_angle",setting.corrot.angle);
        m_qsettings->setValue("corline_x",setting.corline.x);
        m_qsettings->setValue("corline_y",setting.corline.y);
        m_qsettings->setValue("corsym_left",setting.corsym.left);
        m_qsettings->setValue("corsym_right",setting.corsym.right);
        m_qsettings->setValue("corsym_top",setting.corsym.top);
        m_qsettings->setValue("corsym_bottom",setting.corsym.bottom);
        m_qsettings->setValue("corkeystone_x",setting.corkeystone.x);
        m_qsettings->setValue("corkeystone_y",setting.corkeystone.y);
        m_qsettings->setValue("corpin_left",setting.corpin.left);
        m_qsettings->setValue("corpin_right",setting.corpin.right);
        m_qsettings->setValue("corpin_top",setting.corpin.top);
        m_qsettings->setValue("corpin_bottom",setting.corpin.bottom);
        m_qsettings->setValue("corbow_left",setting.corbow.left);
        m_qsettings->setValue("corbow_right",setting.corbow.right);
        m_qsettings->setValue("corbow_top",setting.corbow.top);
        m_qsettings->setValue("corbow_bottom",setting.corbow.bottom);
        m_qsettings->setValue("corshear_x",setting.corshear.x);
        m_qsettings->setValue("corshear_y",setting.corshear.y);
        m_qsettings->setValue("height",setting.preview_height);
        m_qsettings->setValue("width",setting.preview_width);
        m_qsettings->setValue("position_x",setting.preview_position_x);
        m_qsettings->setValue("position_y",setting.preview_position_y);
        m_qsettings->setValue("rotation",setting.preview_rotation);
        m_qsettings->setValue("beam_diameter",setting.preview_beam_diameter);
        m_qsettings->setValue("attenuation_picture",setting.attenuation_picture);
        m_qsettings->setValue("projector_name",setting.projector_name);
        m_qsettings->setValue("scanbeam_emuLaserPosX",setting.scanbeam.emuLaserPosX);
        m_qsettings->setValue("scanbeam_emuLaserPosY",setting.scanbeam.emuLaserPosY);
        m_qsettings->setValue("preerp_fogDesigty",setting.preerp.fogDesigty);
        m_qsettings->setValue("preerp_fogFrontBrightness",setting.preerp.fogFrontBrightness);
        m_qsettings->setValue("preerp_fogRearBrightness",setting.preerp.fogRearBrightness);
        m_qsettings->setValue("preerp_fogSpeed",setting.preerp.fogSpeed);
        m_qsettings->setValue("preerp_gauzeScreenDistance",setting.preerp.gauzeScreenDistance);
    }
    m_qsettings->endArray();
}

void projection_zones::new_pro_settings()
{
    m_qsettings=new QSettings("./system/pro_zone_settings.ini",QSettings::IniFormat);
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

void projection_zones::init_settings(pro_zone_settings &s)
{
    s.attenuation_picture.resize(3600);
    char a[3600]={0};
    s.attenuation_picture.fromRawData(a,3600);
}


