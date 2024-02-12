#include "laser_setting.h"
#include "ui_laser_setting.h"
#include "laser_device_manager.h"
#include "hardware.h"
#include<QPainter>
#include<QGraphicsRectItem>
#include<QDebug>
#include <QMouseEvent>


laser_setting::laser_setting(QWidget *parent) :
    SubWindow(),
    ui(new Ui::laser_setting),
    m_posFlag(POS_DEFAULT),
    m_lastpos(0,0),
    m_type("laser_setting")
{
    ui->setupUi(this);
//    m_parent=parent;

//    refresh_laser_device();
//    connect(m_parent,SIGNAL(manager_changed()),this,SLOT(refresh()));
    connect(ui->view_size,SIGNAL(flagchanged()),this,SLOT(onflagchanged()));
    ui->colorGradeStackedWidget->setCurrentIndex(2);
    m_config=new Configuration(this);
    m_device_table=ui->tableView;
}


void laser_device_table::refresh_laser_device(std::vector<laser_device*> laser_device)
{
//    laser_device_manager *m=m_parent->get_laser_manager();
//    laser_device *dev;
    theModel->setRowCount(laser_device.size());

    for(int i=0;i<laser_device.size();++i)
    {
        auto dev=laser_device.at(i);
        QModelIndex index=theModel->index(i,0);//获取模型索引
        theSelection->clearSelection(); //清除现有选择
        theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
        theModel->setData(index,dev->get_name(),Qt::DisplayRole);//设置单元格字符串

    }

}


void MyGraphicsView::iniGraphicsSystem()
{
    QRectF rect(-(this->width()-10)/2,-(this->height()-10)/2,this->width()-10,this->height()-10);
    scene_size=new QGraphicsScene(rect);
    this->setScene(scene_size);
    QRectF recti(-this->width()*3/8,-this->height()*3/8,(this->width())*3/4,this->height()*3/4);
//    graphicsrectitem *item=new graphicsrectitem(rect);
    m_item=new graphicsrectitem(this);
    m_item->setRectSize(recti);
//    item->setRealPos(recti.topLeft());
    m_item->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);

    scene_size->addItem(m_item);
    m_item->setData(ItemId,0);

}


void laser_setting::refresh()
{
//    refresh_laser_device();
}


laser_setting::~laser_setting()
{
    delete ui;
}

QString laser_setting::getMyType()
{
    return m_type;
}



void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{ //鼠标左键按下事件


        emit MyGraphicsView::flagchanged();

    QGraphicsView::mouseReleaseEvent(event);
}


MyGraphicsView::MyGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    this->setGeometry(this->pos().x(),this->pos().y(),500,500);
    iniGraphicsSystem();
}


void laser_setting::on_xsize_Slider_sliderMoved(int position)
{
xsizechange(position);

//    it->setX(-250*position/100);

}

void laser_setting::xsizechange(int position)
{
    graphicsrectitem *item=ui->view_size->getItem();
    QPointF m_dpoint=item->getdPoint();
    qreal width=position*0.01*490;
    qreal dx=(width-item->boundingRect().width())/2;
    if (m_dpoint.x()-dx<-245+187)
        {
        dx=m_dpoint.x()+245-187;
        width=item->boundingRect().width()+2*dx;
        position=qRound(width*100/490);
        }
    else if(m_dpoint.x()+dx>490-item->boundingRect().width()-58)
    {
        dx=-m_dpoint.x()+(490-item->boundingRect().width()-58);
        width=item->boundingRect().width()+2*dx;
        position=qRound(width*100/490);
    }
    m_dpoint.setX(m_dpoint.x()-dx);
    item->setdPoint(m_dpoint);
    QRectF rect(item->boundingRect().x()-dx,item->boundingRect().y(),width,item->boundingRect().height());
    item->setRectSize(rect);
    ui->xspinBox->setValue(position);
    ui->xsize_Slider->setValue(position);
    item->scene()->update();
}

void laser_setting::ysizechange(int position)
{
    graphicsrectitem *item=ui->view_size->getItem();
    QPointF m_dpoint=item->getdPoint();
    qreal height=position*0.01*490;
    qreal dy=(height-item->boundingRect().height())/2;
    if (m_dpoint.y()-dy<-245+187)
        {
        dy=m_dpoint.y()+245-187;
        height=item->boundingRect().height()+2*dy;
        position=qRound(height*100/490);
        }
    else if(m_dpoint.y()+dy>490-item->boundingRect().height()-58)
    {
        dy=-m_dpoint.y()+(490-item->boundingRect().height()-58);
        height=item->boundingRect().height()+2*dy;
        position=qRound(height*100/490);
    }
    m_dpoint.setY(m_dpoint.y()-dy);
    item->setdPoint(m_dpoint);
    QRectF rect(item->boundingRect().x(),item->boundingRect().y()-dy,item->boundingRect().width(),height);
    item->setRectSize(rect);
    ui->yspinBox->setValue(position);
    ui->ysize_Slider->setValue(position);
    item->scene()->update();
}

void laser_setting::postionchange(int position,POS_FLAG pf)
{
    if (m_posFlag==POS_MOV_RECT)
    {
        m_posFlag=POS_DEFAULT;
        return;
    }
    graphicsrectitem *item=ui->view_size->getItem();

    if (pf==POS_MOV_XP)
      {
            QPointF m_dPoint=item->getdPoint();
            QRectF m_oldRect=item->boundingRect();
            QPointF pos((position-50)*245/50,(ui->yposition_Slider->value()-50)*245/50);
            QPointF point = (pos - m_lastpos);

            if (m_dPoint.x()+point.x()<-245+187)
            {
                point.setX(-245+187-m_dPoint.x());
//                position=(-245+187-m_dPoint.x()+m_lastpos.x())*50/245+50;
            }
            if(m_dPoint.x()+point.x()>490-m_oldRect.width()-58)
            {
                point.setX(490-m_oldRect.width()-58-m_dPoint.x());
//                position=(490-m_oldRect.width()-58-m_dPoint.x()+m_lastpos.x())*50/245+50;
            }

            item->moveBy(point.x(),0);
            m_dPoint.setX(m_dPoint.x()+point.x());
            item->setdPoint(m_dPoint);
            item->setRectSize(m_oldRect);
            pos=QPointF(m_dPoint.x()+m_oldRect.width()/2-187,(ui->yposition_Slider->value()-50)*245/50);
            m_lastpos=pos;
            m_posFlag=POS_MOV_RECT;
            ui->xp_spinBox->setValue(qRound(pos.x()*50/245+50));
            m_posFlag=POS_MOV_RECT;
            ui->xposition_Slider->setValue(qRound(pos.x()*50/245+50));

            item->scene()->update();
    }
        else if(pf==POS_MOV_YP)
        {
        QPointF m_dPoint=item->getdPoint();
        QRectF m_oldRect=item->boundingRect();
        QPointF pos((ui->xposition_Slider->value()-50)*245/50,(position-50)*245/50);
        QPointF point = (pos - m_lastpos);
        if(m_dPoint.y()+point.y()<-245+187)
            point.setY(-245+187-m_dPoint.y());
        if(m_dPoint.y()+point.y()>490-m_oldRect.height()-58)
            point.setY(490-m_oldRect.height()-58-m_dPoint.y());
        item->moveBy(0,point.y());
        m_dPoint.setY(m_dPoint.y()+point.y());
        item->setdPoint(m_dPoint);
        item->setRectSize(m_oldRect);
        pos=QPointF((ui->xposition_Slider->value()-50)*245/50,m_dPoint.y()+m_oldRect.height()/2-187);
        m_lastpos=pos;
        m_posFlag=POS_MOV_RECT;
        ui->yp_spinBox->setValue(qRound(pos.y()*50/245+50));
        m_posFlag=POS_MOV_RECT;
        ui->yposition_Slider->setValue(qRound(pos.y()*50/245+50));
        item->scene()->update();
    }
}

void laser_setting::checkComboBox(QString arg)
{

    if (arg=="Single laser") {
        if (ui->TTL_pushButton->isChecked())
        {
            ui->colorGradeStackedWidget->setCurrentIndex(2);
        }
        else
        {
            ui->colorGradeStackedWidget->setCurrentIndex(1);
        }
    }
    else if (arg=="3lasers(RGB)")
    {
        if (ui->TTL_pushButton->isChecked())
        {
            ui->colorGradeStackedWidget->setCurrentIndex(2);
        }
        else{
        ui->colorGradeStackedWidget->setCurrentIndex(0);
        ui->blueMaxU_spinBox->setVisible(true);
        ui->blueMinU_spinBox->setVisible(true);
        ui->blueMaxU_horizontalSlider->setVisible(true);
        ui->blueMinU_horizontalSlider->setVisible(true);
        ui->greenMaxU_spinBox->setVisible(true);
        ui->greenMinU_spinBox->setVisible(true);
        ui->greenMinU_horizontalSlider->setVisible(true);
        ui->greenMaxU_horizontalSlider->setVisible(true);
        ui->redMaxU_spinBox->setVisible(true);
        ui->redMinU_spinBox->setVisible(true);
        ui->redMinU_horizontalSlider->setVisible(true);
        ui->redMaxU_horizontalSlider->setVisible(true);
        }
    }
    else if(arg=="3lasers(RGV)")
    {
        if (ui->TTL_pushButton->isChecked())
        {
            ui->colorGradeStackedWidget->setCurrentIndex(2);
        }
        else
        {
        ui->colorGradeStackedWidget->setCurrentIndex(0);
        ui->blueMaxU_spinBox->setVisible(true);
        ui->blueMinU_spinBox->setVisible(true);
        ui->blueMaxU_horizontalSlider->setVisible(true);
        ui->blueMinU_horizontalSlider->setVisible(true);
        ui->greenMaxU_spinBox->setVisible(true);
        ui->greenMinU_spinBox->setVisible(true);
        ui->greenMinU_horizontalSlider->setVisible(true);
        ui->greenMaxU_horizontalSlider->setVisible(true);
        ui->redMaxU_spinBox->setVisible(true);
        ui->redMinU_spinBox->setVisible(true);
        ui->redMinU_horizontalSlider->setVisible(true);
        ui->redMaxU_horizontalSlider->setVisible(true);
        }
    }
    else if(arg=="2lasers(RG)")
    {
        if (ui->TTL_pushButton->isChecked())
        {
            ui->colorGradeStackedWidget->setCurrentIndex(2);
        }
        else
        {
        ui->colorGradeStackedWidget->setCurrentIndex(0);
        ui->blueMaxU_spinBox->setVisible(false);
        ui->blueMinU_spinBox->setVisible(false);
        ui->blueMaxU_horizontalSlider->setVisible(false);
        ui->blueMinU_horizontalSlider->setVisible(false);
        ui->blueMaxU_label->setVisible(false);
        ui->blueMinU_label->setVisible(false);
        ui->greenMaxU_spinBox->setVisible(true);
        ui->greenMinU_spinBox->setVisible(true);
        ui->greenMinU_horizontalSlider->setVisible(true);
        ui->greenMaxU_horizontalSlider->setVisible(true);
        ui->greenMaxU_label->setVisible(true);
        ui->greenMinU_label->setVisible(true);
        ui->redMaxU_spinBox->setVisible(true);
        ui->redMinU_spinBox->setVisible(true);
        ui->redMinU_horizontalSlider->setVisible(true);
        ui->redMaxU_horizontalSlider->setVisible(true);
        ui->redMaxU_label->setVisible(true);
        ui->redMinU_label->setVisible(true);
}
    }
    else if(arg=="2lasers(RB)")
    {
        if (ui->TTL_pushButton->isChecked())
        {
            ui->colorGradeStackedWidget->setCurrentIndex(2);
        }
        else{
        ui->colorGradeStackedWidget->setCurrentIndex(0);
        ui->greenMaxU_spinBox->setVisible(false);
        ui->greenMinU_spinBox->setVisible(false);
        ui->greenMinU_horizontalSlider->setVisible(false);
        ui->greenMaxU_horizontalSlider->setVisible(false);
        ui->greenMaxU_label->setVisible(false);
        ui->greenMinU_label->setVisible(false);
        ui->blueMaxU_spinBox->setVisible(true);
        ui->blueMinU_spinBox->setVisible(true);
        ui->blueMaxU_horizontalSlider->setVisible(true);
        ui->blueMinU_horizontalSlider->setVisible(true);
        ui->blueMaxU_label->setVisible(true);
        ui->blueMinU_label->setVisible(true);
        ui->redMaxU_spinBox->setVisible(true);
        ui->redMinU_spinBox->setVisible(true);
        ui->redMinU_horizontalSlider->setVisible(true);
        ui->redMaxU_horizontalSlider->setVisible(true);
        ui->redMaxU_label->setVisible(true);
        ui->redMinU_label->setVisible(true);

        }}
    else if(arg=="2lasers(GB)")
    {
        if (ui->TTL_pushButton->isChecked())
        {
            ui->colorGradeStackedWidget->setCurrentIndex(2);
        }
        else{
        ui->colorGradeStackedWidget->setCurrentIndex(0);
        ui->redMaxU_spinBox->setVisible(false);
        ui->redMinU_spinBox->setVisible(false);
        ui->redMinU_horizontalSlider->setVisible(false);
        ui->redMaxU_horizontalSlider->setVisible(false);
        ui->redMaxU_label->setVisible(false);
        ui->redMinU_label->setVisible(false);
        ui->blueMaxU_spinBox->setVisible(true);
        ui->blueMinU_spinBox->setVisible(true);
        ui->blueMaxU_horizontalSlider->setVisible(true);
        ui->blueMinU_horizontalSlider->setVisible(true);
        ui->blueMaxU_label->setVisible(true);
        ui->blueMinU_label->setVisible(true);
        ui->greenMaxU_spinBox->setVisible(true);
        ui->greenMinU_spinBox->setVisible(true);
        ui->greenMinU_horizontalSlider->setVisible(true);
        ui->greenMaxU_horizontalSlider->setVisible(true);
        ui->greenMaxU_label->setVisible(true);
        ui->greenMinU_label->setVisible(true);
}
    }

}



graphicsrectitem *MyGraphicsView::getItem()
{
    return m_item;
}



void laser_setting::on_xspinBox_valueChanged(int arg1)
{
    xsizechange(arg1);
}

void laser_setting::onflagchanged()
{
    graphicsrectitem *item=ui->view_size->getItem();
    STATE_FLAG flag=ui->view_size->getItem()->getStageFlag();
//    QPointF dpoint=item->getdPoint();
    if (flag==MOV_LEFT_LINE||flag==MOV_RIGHT_LINE)
    {
        qreal width=item->boundingRect().width();
        int position=qRound(width*100/490);
        ui->xspinBox->setValue(position);
        ui->xsize_Slider->setValue(position);
        if(flag==MOV_LEFT_LINE)
        {
            m_posFlag=POS_MOV_RECT;
            QPointF dpoint=item->getdPoint();
            qreal xpos=qRound((dpoint.x()+item->boundingRect().width()/2-187)*50/245)+50;
            ui->xp_spinBox->setValue(xpos);
            m_posFlag=POS_MOV_RECT;
            ui->xposition_Slider->setValue(xpos);

        }
        else
        {
            m_posFlag=POS_MOV_RECT;
            QPointF dpoint=item->getdPoint();
            qreal xpos=qRound((dpoint.x()+item->boundingRect().width()/2-187)*50/245)+50;
            ui->xp_spinBox->setValue(xpos);
            m_posFlag=POS_MOV_RECT;
            ui->xposition_Slider->setValue(xpos);
        }

    }
    else if (flag==MOV_TOP_LINE||flag==MOV_BOTTOM_LINE)
    {
        qreal height=item->boundingRect().height();
        int position=qRound(height*100/490);
        ui->yspinBox->setValue(position);
        ui->ysize_Slider->setValue(position);
        if(flag==MOV_TOP_LINE)
        {
            m_posFlag=POS_MOV_RECT;
            QPointF dpoint=item->getdPoint();
            qreal ypos=qRound((dpoint.y()+item->boundingRect().height()/2-187)*50/245+50);
            ui->yp_spinBox->setValue(ypos);
            m_posFlag=POS_MOV_RECT;
            ui->yposition_Slider->setValue(ypos);

        }
        else
        {
            m_posFlag=POS_MOV_RECT;
            QPointF dpoint=item->getdPoint();
            qreal ypos=qRound((dpoint.y()+item->boundingRect().height()/2-187)*50/245+50);
            ui->yp_spinBox->setValue(ypos);
            m_posFlag=POS_MOV_RECT;
            ui->yposition_Slider->setValue(ypos);
        }
    }
    else if(flag==MOV_RECT)
    {
        m_posFlag=POS_MOV_RECT;
        QPointF dpoint=item->getdPoint();
        qreal xpos=qRound((dpoint.x()+item->boundingRect().width()/2-187)*50/245+50);
        ui->xp_spinBox->setValue(xpos);
        m_posFlag=POS_MOV_RECT;
        ui->xposition_Slider->setValue(xpos);
        m_posFlag=POS_MOV_RECT;
        qreal ypos=qRound((dpoint.y()+item->boundingRect().height()/2-187)*50/245+50);
        ui->yp_spinBox->setValue(ypos);
        m_posFlag=POS_MOV_RECT;
        ui->yposition_Slider->setValue(ypos);

    }
}

void laser_setting::on_ysize_Slider_sliderMoved(int position)
{
    ysizechange(position);
}


void laser_setting::on_yspinBox_valueChanged(int arg1)
{
    ysizechange(arg1);
}


void laser_setting::on_xposition_Slider_sliderMoved(int position)
{
//    m_posFlag=POS_MOV_XP;
    postionchange(position,POS_MOV_XP);

}


void laser_setting::on_xp_spinBox_valueChanged(int arg1)
{
//    m_posFlag=POS_MOV_XP;

    postionchange(arg1,POS_MOV_XP);
}


void laser_setting::on_yposition_Slider_sliderMoved(int position)
{
//    m_posFlag=POS_MOV_YP;
    postionchange(position,POS_MOV_YP);
}


void laser_setting::on_yp_spinBox_valueChanged(int arg1)
{
//    m_posFlag=POS_MOV_YP;
   postionchange(arg1,POS_MOV_YP);
}


void laser_setting::on_comboBox_activated(const QString &arg1)
{
    QString arg=arg1;
    checkComboBox(arg);
   }


void laser_setting::on_TTL_pushButton_clicked()
{
    ui->TTL_pushButton->setAutoExclusive(true);
    ui->TTL_pushButton->setCheckable(true);
    ui->TTL_pushButton->setChecked(true);
    ui->linearRes_pushButton->setChecked(false);
    ui->logRes_pushButton->setChecked(false);
    ui->colorGradeStackedWidget->setCurrentIndex(2);

}


void laser_setting::on_linearRes_pushButton_clicked()
{

    ui->linearRes_pushButton->setCheckable(true);
    QString str=ui->comboBox->currentText();
    ui->TTL_pushButton->setChecked(false);
    ui->linearRes_pushButton->setChecked(true);
    ui->logRes_pushButton->setChecked(false);
    checkComboBox(str);
    ui->linearRes_pushButton->setAutoExclusive(true);
}


void laser_setting::on_logRes_pushButton_clicked()
{
    ui->logRes_pushButton->setAutoExclusive(true);
    ui->logRes_pushButton->setCheckable(true);
    ui->logRes_pushButton->setChecked(true);
    ui->TTL_pushButton->setChecked(false);
    ui->logRes_pushButton->setChecked(false);
    QString str=ui->comboBox->currentText();
    checkComboBox(str);
    ui->logRes_pushButton->setAutoExclusive(true);
}


laser_setting_data::laser_setting_data(QWidget *parent):
    m_colorMode("Single laser"),
    m_colorType(TTL),
    m_redMinU(0),
    m_redMaxU(100),
    m_greenMinU(0),
    m_greenMaxU(100),
    m_blueMinU(0),
    m_blueMaxU(100),
    m_singleMinU(0),
    m_singleMaxU(100)
{

}

laser_setting_data::~laser_setting_data()
{

}

void laser_setting::on_singleMinU_horizontalSlider_sliderMoved(int position)
{
    ui->singleMinU_spinBox->setValue(position);
}


void laser_setting::on_singleMinU_spinBox_valueChanged(int arg1)
{
    ui->singleMinU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_singleMaxU_horizontalSlider_sliderMoved(int position)
{
    ui->singleMaxU_spinBox->setValue(position);
}



void laser_setting::on_singleMaxU_spinBox_valueChanged(int arg1)
{
    ui->singleMaxU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_redMinU_horizontalSlider_sliderMoved(int position)
{
    ui->redMinU_spinBox->setValue(position);
}


void laser_setting::on_redMinU_spinBox_valueChanged(int arg1)
{
    ui->redMinU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_redMaxU_horizontalSlider_sliderMoved(int position)
{
    ui->redMaxU_spinBox->setValue(position);
}


void laser_setting::on_redMaxU_spinBox_valueChanged(int arg1)
{
    ui->redMaxU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_greenMinU_horizontalSlider_sliderMoved(int position)
{
    ui->greenMinU_spinBox->setValue(position);
}


void laser_setting::on_greenMinU_spinBox_valueChanged(int arg1)
{
    ui->greenMinU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_greenMaxU_horizontalSlider_sliderMoved(int position)
{
    ui->greenMaxU_spinBox->setValue(position);
}


void laser_setting::on_greenMaxU_spinBox_valueChanged(int arg1)
{
    ui->greenMaxU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_blueMinU_horizontalSlider_sliderMoved(int position)
{
    ui->blueMinU_spinBox->setValue(position);
}


void laser_setting::on_blueMinU_spinBox_valueChanged(int arg1)
{
    ui->blueMinU_horizontalSlider->setValue(arg1);
}


void laser_setting::on_blueMaxU_horizontalSlider_sliderMoved(int position)
{
    ui->blueMaxU_spinBox->setValue(position);
}


void laser_setting::on_blueMaxU_spinBox_valueChanged(int arg1)
{
    ui->blueMaxU_horizontalSlider->setValue(arg1);
}

void laser_setting::on_sample_horizontalSlider_sliderMoved(int position)
{
    ui->sample_spinBox->setValue(position);
}

void laser_setting::on_sample_spinBox_valueChanged(int arg1)
{
    ui->sample_horizontalSlider->setValue(arg1);
}
void laser_setting::on_min_horizontalSlider_sliderMoved(int position)
{
    ui->min_spinBox->setValue(position);
    ui->sample_horizontalSlider->setMinimum(position);
}

void laser_setting::on_min_spinBox_valueChanged(int arg1)
{
    ui->min_horizontalSlider->setValue(arg1);
    ui->sample_horizontalSlider->setMinimum(arg1);
}
void laser_setting::on_max_horizontalSlider_sliderMoved(int position)
{
    ui->max_spinBox->setValue(position);
    ui->sample_horizontalSlider->setMaximum(position);
}

void laser_setting::on_max_spinBox_valueChanged(int arg1)
{
    ui->max_horizontalSlider->setValue(arg1);
    ui->sample_horizontalSlider->setMaximum(arg1);
}

void laser_setting::on_OpenConfigButton_clicked()
{
    m_config->Load();
}

void laser_setting::on_actionopensettins_triggered()
{
    m_config->Load();
}

void laser_setting::on_saveConfigButton_clicked()
{
    if(m_config)
        m_config->Save();
}

void laser_setting::on_actionsavesettings_triggered()
{
    if(m_config)
        m_config->Save();
}


void laser_setting::on_saveAsConfigButton_clicked()
{
    if(m_config)
        m_config->SaveAs();
}

laser_device_table::laser_device_table(QWidget *parent)
{
    theModel = new QStandardItemModel(1,1,this); //创建数据模型
    theSelection = new QItemSelectionModel(theModel);//Item选择模型
    this->setModel(theModel); //设置数据模型
    this->setSelectionModel(theSelection);//设置选择模型
    this->verticalHeader()->setHidden(true);
    this->horizontalHeader()->setHidden(true);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
}



laser_device_table::~laser_device_table()
{

}

void laser_device_table::set_device_manager(laser_device_manager *manager)
{
    m_manager=manager;
    refresh_laser_device(m_manager->get_device_list());
    emit manager_setted();
}

laser_device_manager *laser_device_table::get_manager()
{
    return m_manager;
}
