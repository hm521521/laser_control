#include "scene_tool_box.h"
#include<QEvent>

Scene_Tool_Box::Scene_Tool_Box(QWidget *parent, Qt::WindowFlags f):QToolBox(parent, f)
{

}

//bool Scene_Tool_Box::event(QEvent *e)
//{
//    int page;
//    if(e->type()==QEvent::LayoutRequest)
//    {
//        page=this->currentIndex();
//        emit currentChanged(page);
//        return true;
//    }
//    else
//    {return false;}
//}



Scene_Stack::Scene_Stack(QWidget *parent):QStackedWidget(parent)
{

}

//void Scene_Stack::setCurIndex(int index)
//{
//    emit currentChanged(index);
//    QStackedWidget::setCurrentIndex(index);
//}



