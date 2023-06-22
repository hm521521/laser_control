//#include "mainwindow.h"
#include <QApplication>
#include "hardware.h"
#include "mainwindow1.h"
#include"picture_trace.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow1 w;
    w.show();
//    Picture_trace p;
//    p.show();
    return a.exec();
}
