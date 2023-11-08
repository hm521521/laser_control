#include "projection_zones.h"
#include "ui_projection_zones.h"
#include "add_zones_dialog.h"
#include"add_id_dialog.h"
#include"delete_projection_zone_dialog.h"
#include"delete_zone_id_dialog.h"
#include <QString>
#include <QMessageBox>


projection_zones::projection_zones(MainWindow1 *parent) :
    SubWindow(),
    ui(new Ui::projection_zones),
    m_type("projection_zones")
{
    ui->setupUi(this);
    m_parent=parent;
    m_device_table=ui->projector_tableView;
    connect(m_device_table,SIGNAL(manager_setted()),this,SLOT(loadZoneName()));
    connect(this,SIGNAL(display_zone_names(QStringList)),ui->zone_names_tableView,SLOT(display(QStringList)));
    connect(this,SIGNAL(display_id_names(QStringList)),ui->zone_id_list,SLOT(display(QStringList)));
    connect(ui->zone_names_tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(zone_name_changed(QModelIndex)));

    m_button_group=new QButtonGroup(this);
    m_button_group->addButton(ui->New_pushButton,0);
    m_button_group->addButton(ui->Open_pushButton,1);
    m_button_group->addButton(ui->Save_pushButton,2);
    m_button_group->addButton(ui->Add_pushButton,3);
    m_button_group->addButton(ui->Del_pushButton,4);
    m_button_group->addButton(ui->Copy_pushButton,5);
    m_button_group->addButton(ui->addZoneId_pushButton,6);
    m_button_group->addButton(ui->deleteZoneId_pushButton,7);
    m_button_group->addButton(ui->confirm_pushButton,8);
    m_button_group->addButton(ui->cancel_pushButton,9);
    connect(m_button_group,SIGNAL(buttonClicked(int)),this,SLOT(buttonClicked(int)));
    connectSliderAndSpin(ui->left_verticalSlider,ui->left_doubleSpinBox);
    connectSliderAndSpin(ui->bottom_horizontalSlider,ui->bottom_doubleSpinBox);
    connectSliderAndSpin(ui->right_verticalSlider,ui->right_doubleSpinBox);
    connectSliderAndSpin(ui->top_horizontalSlider,ui->top_doubleSpinBox);
//    ui->left_doubleSpinBox->setDecimals(3);
//    ui->right_doubleSpinBox->setDecimals(3);
//    ui->bottom_doubleSpinBox->setDecimals(3);
//    ui->top_doubleSpinBox->setDecimals(3);
    m_radio_group=new QButtonGroup(this);
    m_radio_group->addButton(ui->size_radioButton,0);
    m_radio_group->addButton(ui->position_radioButton,1);
    m_radio_group->addButton(ui->rotation_radioButton,2);
    m_radio_group->addButton(ui->linearity_radioButton,3);
    m_radio_group->addButton(ui->symmetry_radioButton,4);
    m_radio_group->addButton(ui->keystone_radioButton,5);
    m_radio_group->addButton(ui->pincushion_radioButton,6);
    m_radio_group->addButton(ui->bow_radioButton,7);
    m_radio_group->addButton(ui->shear_radioButton,8);
    connect(m_radio_group,SIGNAL(buttonClicked(int)),this,SLOT(radio_groupbox_clicked(int)));
    m_leftmath_group=new QButtonGroup(this);
    m_leftmath_group->addButton(ui->left_po_pushButton,0);
    m_leftmath_group->addButton(ui->left_pzo_pushButton,1);
    m_leftmath_group->addButton(ui->left_pzzo_pushButton,2);
    m_leftmath_group->addButton(ui->left_nzzo_pushButton,3);
    m_leftmath_group->addButton(ui->left_nzo_pushButton,4);
    m_leftmath_group->addButton(ui->left_no_pushButton,5);
    connect(m_leftmath_group,SIGNAL(buttonClicked(int)),this,SLOT(math_groupbox_clicked(int)));
    m_rightmath_group=new QButtonGroup(this);
    m_rightmath_group->addButton(ui->right_po_pushButton,6);
    m_rightmath_group->addButton(ui->right_pzo_pushButton,7);
    m_rightmath_group->addButton(ui->right_pzzo_pushButton,8);
    m_rightmath_group->addButton(ui->right_nzzo_pushButton,9);
    m_rightmath_group->addButton(ui->right_nzo_pushButton,10);
    m_rightmath_group->addButton(ui->right_no_pushButton,11);
    connect(m_rightmath_group,SIGNAL(buttonClicked(int)),this,SLOT(math_groupbox_clicked(int)));
    m_topmath_group=new QButtonGroup(this);
    m_topmath_group->addButton(ui->top_po_pushButton,12);
    m_topmath_group->addButton(ui->top_pzo_pushButton,13);
    m_topmath_group->addButton(ui->top_pzzo_pushButton,14);
    m_topmath_group->addButton(ui->top_nzzo_pushButton,15);
    m_topmath_group->addButton(ui->top_nzo_pushButton,16);
    m_topmath_group->addButton(ui->top_no_pushButton,17);
    connect(m_topmath_group,SIGNAL(buttonClicked(int)),this,SLOT(math_groupbox_clicked(int)));
    m_bottommath_group=new QButtonGroup(this);
    m_bottommath_group->addButton(ui->bo_po_pushButton,18);
    m_bottommath_group->addButton(ui->bo_pzo_pushButton,19);
    m_bottommath_group->addButton(ui->bo_pzzo_pushButton,20);
    m_bottommath_group->addButton(ui->bo_nzzo_pushButton,21);
    m_bottommath_group->addButton(ui->bo_nzo_pushButton,22);
    m_bottommath_group->addButton(ui->bo_no_pushButton,23);
    connect(m_bottommath_group,SIGNAL(buttonClicked(int)),this,SLOT(math_groupbox_clicked(int)));

    new_pro_settings();
}


void projection_zones::init_zone_id()
{
    if(m_settings.size()==0)
        return;
//    QString zone_name=ui->zone_names_tableView->model()->data(ui->zone_names_tableView->currentIndex()).toString();
//    zone_name=zone_name.split(QString::fromUtf8("\n")).at(0);
//    for(int i=0;i<m_settings.size();++i)
//    {
//        if(m_settings.at(i).pro_zone_name==zone_name)
//        {
//            display_id_names(m_zone_ids.at(i));
//        }
//    }

}

void zone_id_listView::display(QStringList strlist)//在id_name栏里显示projection_zones的别名
{
    QString idname;
    QStandardItemModel *Model=new QStandardItemModel(this);
    for(int i=0;i<strlist.size();++i)
    {
        idname=strlist.at(i);
        QStandardItem* item=new QStandardItem(idname);
        item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        Model->appendRow(item);

    }
    setModel(Model);
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
    QStringList m_namelist;

    for(int i=0;i<m_settings.size();++i)
    {
        QString istr=m_settings.at(i).pro_zone_name;
        istr.append(QString::fromUtf8("\nProjector 1:"));
        auto ld=m_device_table->get_manager()->get_device_list();
        istr.append(ld[0]->get_name());
        m_namelist.push_back(istr);
    }
    QString istr=str;
    istr.append(QString::fromUtf8("\nProjector 1:"));
    auto ld=m_device_table->get_manager()->get_device_list();
    istr.append(ld[0]->get_name());
    if (!(m_namelist.filter(istr)).isEmpty()||str=="")
        return;
//    str.append("\n");
    m_namelist.push_back(istr);
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
        ui->deleteZoneId_pushButton->setEnabled(true);
    emit display_zone_names(m_namelist);
    newIdName(str);


}
void projection_zones::newIdName(QString str)
{
    if(str=="")
        return;
    QString zone_name=ui->zone_names_tableView->model()->data(ui->zone_names_tableView->currentIndex()).toString();
    zone_name=zone_name.split(QString::fromUtf8("\n")).at(0);
    if(zone_name.isEmpty())
        zone_name=str;

    QStringList id_list;
    for(int i=0;i<m_settings.size();++i)
    {
        if(m_settings.at(i).pro_zone_name==zone_name)
        {
            if(i==m_zone_ids.size())
            {
                QStringList newzoneid;
                newzoneid.append(str);
                m_zone_ids.append(newzoneid);
                emit display_id_names(m_zone_ids.at(i));

//                id_list=m_zone_ids.at(i);
            }
            else
            {
                id_list=m_zone_ids.at(i);
                if (!(id_list.filter(str)).isEmpty())
                    return;
                id_list.push_back(str);
                emit display_id_names(id_list);
                m_zone_ids.replace(i,id_list);

            }
            break;

        }

    }
}

void projection_zones::loadZoneName()
{
    if (m_settings.size()<1)
        return;
    QStringList m_namelist;
    for(int i=0;i<m_settings.size();++i)
    {
        QString istr=m_settings.at(i).pro_zone_name;
        istr.append(QString::fromUtf8("\nProjector 1:"));
        auto ld=m_device_table->get_manager()->get_device_list();
        istr.append(ld[0]->get_name());
        m_namelist.push_back(istr);
    }
    emit display_zone_names(m_namelist);
    if(m_zone_ids.size()>0)
        display_id_names(m_zone_ids.at(0));
}




void zone_names_table::display(QStringList m_namelist)
{
    QString istr;
    QStandardItemModel *Model=new QStandardItemModel(this);
    for(int i=0;i<m_namelist.size();++i)
    {
        istr=m_namelist.at(i);
        QStandardItem* item=new QStandardItem(istr);
        item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        Model->appendRow(item);
    }
    setModel(Model);
    setCurrentIndex(Model->index(0, 0));
}

void projection_zones::on_addZones_pushButton_clicked()
{

}


void projection_zones::on_delete_zone_pushButton_clicked()
{
//    QMessageBox delete_zone;
//    delete_zone.setWindowTitle("Delete Projection Zone name");
//    QPushButton *yesButton=delete_zone.addButton(tr("是(Y)"),QMessageBox::ActionRole);
//    QPushButton *noButton=delete_zone.addButton(tr("否(N)"),QMessageBox::ActionRole);
//    delete_zone.setText(tr("Would like you to delete Projection zone name"));
//    delete_zone.exec();
//    if(delete_zone.clickedButton()==yesButton)
//    {
//        int k=ui->zone_names_listView->selectionModel()->currentIndex().row();
//        m_namelist.removeAt(k);
//        QString istr;
//        int i=0;
//        theModel->setRowCount(m_namelist.length());
//        foreach (istr,m_namelist)
//        {
//            QModelIndex index=theModel->index(i,0);//获取模型索引
//            theSelection->clearSelection(); //清除现有选择
//            theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
//            theModel->setData(index,istr,Qt::DisplayRole);//设置单元格字符串
//            i++;
//        }
//    }
//    else if (delete_zone.clickedButton()==noButton)
//    {
//        delete_zone.close();

//    }
//    if (m_namelist.length()<=1)
//        ui->delete_zone_pushButton->setEnabled(false);
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
            break;
        }
        case 4:
        {
            QModelIndex idx=ui->zone_names_tableView->currentIndex();
            if(idx.row()>=0)
            {
                delete_projection_zone_Dialog *a=new delete_projection_zone_Dialog(this);
                connect(a,SIGNAL(delete_zone()),this,SLOT(delete_projection_zone()));
                a->show();
            }
            break;
        }
        case 6:
        {
            add_zone_id_name();
            break;
        }
        case 7:
        {
            QModelIndex idx=ui->zone_names_tableView->currentIndex();

            if(m_zone_ids.size()>idx.row())
            {
                int i=0;
                if(idx.row()>=0)
                    i=idx.row();

                if(ui->zone_id_list->currentIndex().row()<0||m_zone_ids.at(i).size()<2)
                    return;
                delete_zone_id_Dialog *b=new delete_zone_id_Dialog(this);
                connect(b,SIGNAL(delete_id()),this,SLOT(delete_zone_id()));
                b->show();
            }
            break;
        }
        case 8:
        {
            save_settings();
            close();
            break;
        }
        case 9:
        {
            close();
            break;
        }
        default:
        {
            break;
        }
    }
}

void projection_zones::zone_name_changed(QModelIndex index)
{
    int idx=index.row();
    if(idx<m_zone_ids.size())
        emit display_id_names(m_zone_ids.at(idx));
}

void projection_zones::add_zone_id_name()
{
    add_id_dialog *a=new add_id_dialog(this);
    connect(a, SIGNAL(id_name(QString)),this,SLOT(newIdName(QString)));
    a->show();
}

void projection_zones::delete_projection_zone()
{
    QModelIndex idx=ui->zone_names_tableView->currentIndex();
    ui->zone_names_tableView->model()->removeRow(idx.row());
    m_settings.removeAt(idx.row());
    m_zone_ids.removeAt(idx.row());
    idx=ui->zone_names_tableView->currentIndex();
    if(m_zone_ids.size()>idx.row()&&idx.row()>=0)
        emit display_id_names(m_zone_ids.at(idx.row()));
    else

        emit display_id_names(QStringList());

}

void projection_zones::delete_zone_id()
{
    QModelIndex idIdx=ui->zone_id_list->currentIndex();
    QModelIndex idx=ui->zone_names_tableView->currentIndex();
    int i=0;
    if(idx.row()>=0)
        i=idx.row();
    if(idIdx.row()>=0&&m_zone_ids.at(i).size()>1)
    {
//        ui->zone_id_list->model()->removeRow(idIdx.row());
        QStringList id_list=m_zone_ids.at(i);
        id_list.removeAt(idIdx.row());
        emit display_id_names(id_list);
        m_zone_ids.replace(i,id_list);
//        m_zone_ids.at(idx.row()).removeAt(idIdx.row());
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
//        setting.zone_id_names=m_qsettings->value("zone_id_names").toStringList();
        m_zone_ids.append(m_qsettings->value("zone_id_names").toStringList());
        m_settings.append(setting);
    }
    m_qsettings->endArray();
    ui->size_radioButton->setChecked(true);
    if(m_settings.size()<1) return;
    ui->left_doubleSpinBox->setValue(m_settings.at(0).corsize.y);
    ui->bottom_doubleSpinBox->setValue(m_settings.at(0).corsize.x);
    ui->right_math_widget->setVisible(false);
    ui->top_math_widget->setVisible(false);
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
        m_qsettings->setValue("zone_id_names",QVariant(m_zone_ids.at(i)));
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



zone_names_table::zone_names_table(QWidget *parent)
{

}

zone_names_table::~zone_names_table()
{

}

zone_id_listView::zone_id_listView(QWidget *parent)
{

}

zone_id_listView::~zone_id_listView()
{

}


void projection_zones::on_size_radioButton_clicked()
{

}

void projection_zones::radio_groupbox_clicked(int index)
{
    int si=0;
    si=ui->zone_names_tableView->currentIndex().row();
    if(si<0)
        return;
    auto setting=m_settings.at(si);
    switch(index)
    {
    case 0:{
        ui->bottom_doubleSpinBox->setValue(setting.corsize.x);
        ui->left_doubleSpinBox->setValue(setting.corsize.y);
        ui->top_math_widget->setVisible(false);
        ui->right_math_widget->setVisible(false);
        ui->bottom_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        break;
    }
    case 1:{
        ui->bottom_doubleSpinBox->setValue(setting.corpos.x);
        ui->left_doubleSpinBox->setValue(setting.corpos.y);
        ui->top_math_widget->setVisible(false);
        ui->right_math_widget->setVisible(false);
        ui->bottom_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        break;
    }
    case 3:{
        ui->bottom_doubleSpinBox->setValue(setting.corline.x);
        ui->left_doubleSpinBox->setValue(setting.corline.y);
        ui->top_math_widget->setVisible(false);
        ui->right_math_widget->setVisible(false);
        ui->bottom_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        break;
    }
    case 5:{
        ui->bottom_doubleSpinBox->setValue(setting.corkeystone.x);
        ui->left_doubleSpinBox->setValue(setting.corkeystone.y);
        ui->top_math_widget->setVisible(false);
        ui->right_math_widget->setVisible(false);
        ui->bottom_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        break;
    }
    case 8:
    {
        ui->bottom_doubleSpinBox->setValue(setting.corshear.x);
        ui->left_doubleSpinBox->setValue(setting.corshear.y);
        ui->top_math_widget->setVisible(false);
        ui->right_math_widget->setVisible(false);
        ui->bottom_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        break;
    }
    case 2:
    {
        ui->bottom_doubleSpinBox->setValue(setting.corrot.angle);
        ui->top_math_widget->setVisible(false);
        ui->left_math_widget->setVisible(false);
        ui->right_math_widget->setVisible(false);
        ui->bottom_math_widget->setVisible(true);
        break;
    }
    case 4:{
        ui->bottom_doubleSpinBox->setValue(setting.corsym.bottom);
        ui->left_doubleSpinBox->setValue(setting.corsym.left);
        ui->right_doubleSpinBox->setValue(setting.corsym.right);
        ui->top_doubleSpinBox->setValue(setting.corsym.top);
        ui->bottom_math_widget->setVisible(true);
        ui->top_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        ui->right_math_widget->setVisible(true);
        break;
    }
    case 6:{
        ui->bottom_doubleSpinBox->setValue(setting.corpin.bottom);
        ui->left_doubleSpinBox->setValue(setting.corpin.left);
        ui->right_doubleSpinBox->setValue(setting.corpin.right);
        ui->top_doubleSpinBox->setValue(setting.corpin.top);
        ui->bottom_math_widget->setVisible(true);
        ui->top_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        ui->right_math_widget->setVisible(true);
        break;
    }
    case 7:
    {
        ui->bottom_doubleSpinBox->setValue(setting.corbow.bottom);
        ui->top_doubleSpinBox->setValue(setting.corbow.top);
        ui->left_doubleSpinBox->setValue(setting.corbow.left);
        ui->right_doubleSpinBox->setValue(setting.corbow.right);
        ui->bottom_math_widget->setVisible(true);
        ui->top_math_widget->setVisible(true);
        ui->left_math_widget->setVisible(true);
        ui->right_math_widget->setVisible(true);
        break;
    }
    default:
    {
        break;
    }
    }
}

void projection_zones::math_groupbox_clicked(int index)
{
    QDoubleSpinBox *spinbox;
    switch(index/6)
    {
    case 0:
    {
        spinbox=ui->left_doubleSpinBox;
        break;
    }
    case 1:
    {
        spinbox=ui->right_doubleSpinBox;
        break;
    }
    case 2:
    {
        spinbox=ui->top_doubleSpinBox;
        break;
    }
    case 3:
    {
        spinbox=ui->bottom_doubleSpinBox;
        break;
    }
    default:
        break;
    }
    double value=spinbox->value();
    double dv;
    switch(index%6){
    case 0:
    {
        dv=value+1.0000;
        spinbox->setValue(dv);
        break;
    }
    case 1:
    {
        spinbox->setValue(value+0.10);
        break;
    }
    case 2:
    {
        spinbox->setValue(value+0.01);
        break;
    }
    case 3:
    {
        dv=value-0.01000;
        spinbox->setValue(dv);
        break;
    }
    case 4:
    {
        dv=value-0.10000;
        spinbox->setValue(dv);
        break;
    }
    case 5:
    {
        spinbox->setValue(value-1.00);
        break;
    }
    default:
    {
        break;
    }
    }
}


void projection_zones::connectSliderAndSpin(QSlider *slider, QDoubleSpinBox *spin)
{
    connect(spin, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), slider, &QSlider::setValue);
    connect(spin, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, [=]{
//        QRadioButton *rad;
        QModelIndex zoneidx=ui->zone_names_tableView->currentIndex();
        int zi=0;
        if(zoneidx.row()>0)
            zi=zoneidx.row();
        int i=m_radio_group->checkedId();
        change_setting_values(i,spin->objectName(),spin->value());
   });
//   connect(slider, &QSlider::valueChanged, spin, &QDoubleSpinBox::setValue);
   connect(slider, &QSlider::valueChanged, [=]{
        double sval=spin->value();
        if(abs(sval-slider->value())>1)
            spin->setValue(slider->value());});

}


void projection_zones::change_setting_values(int i, QString slidername,double spinvalue)
{
    int si=0;
    si=ui->zone_names_tableView->currentIndex().row();
    if(si<0)
        return;
    auto setting=m_settings.at(si);
    switch (i) {
    case 0:
    {
        if(slidername=="left_doubleSpinBox")
        {
            setting.corsize.y=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="bottom_doubleSpinBox")
        {
            setting.corsize.x=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 1:
    {
        if(slidername=="left_doubleSpinBox")
        {

            setting.corpos.y=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="bottom_doubleSpinBox")
        {

            setting.corpos.x=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 2:
    {
        if(slidername=="bottom_doubleSpinBox")
        {

            setting.corrot.angle=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 3:
    {
        if(slidername=="left_doubleSpinBox")
        {

            setting.corline.y=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="bottom_doubleSpinBox")
        {

            setting.corline.x=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 4:
    {
        if(slidername=="left_doubleSpinBox")
        {
            setting.corsym.left=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="bottom_doubleSpinBox")
        {
            setting.corsym.bottom=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="right_doubleSpinBox")
        {
            setting.corsym.right=ui->right_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="top_doubleSpinBox")
        {
            setting.corsym.top=ui->top_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 5:
    {

        if(slidername=="bottom_doubleSpinBox")
        {
            setting.corkeystone.x=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="left_doubleSpinBox")
        {
            setting.corkeystone.y=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 6:
    {
        if(slidername=="left_doubleSpinBox")
        {
            setting.corpin.left=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="bottom_doubleSpinBox")
        {
            setting.corpin.bottom=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="right_doubleSpinBox")
        {
            setting.corpin.right=ui->right_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="top_doubleSpinBox")
        {
            setting.corpin.top=ui->top_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 7:
    {
        if(slidername=="left_doubleSpinBox")
        {
            setting.corbow.left=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="bottom_doubleSpinBox")
        {
            setting.corbow.bottom=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="right_doubleSpinBox")
        {
            setting.corbow.right=ui->right_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="top_doubleSpinBox")
        {
            setting.corbow.top=ui->top_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    case 8:
    {
        if(slidername=="bottom_doubleSpinBox")
        {
            setting.corshear.x=ui->bottom_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        else if(slidername=="left_doubleSpinBox")
        {
            setting.corshear.y=ui->left_doubleSpinBox->value();
            m_settings.replace(si,setting);
        }
        break;
    }
    default:
        break;
    }
}


