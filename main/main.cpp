#include "Gride/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    //QQuickView *view = new QQuickView(QUrl("qrc:/Block_Workspace.qml"));
    //QWidget *qmlWidget = QWidget::createWindowContainer(view);
    w.setQmlUIGrid(QUrl("qrc:/Block_Workspace.qml"));

    w.show();


    return a.exec();
}
