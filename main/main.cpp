#include "Gride/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QQuickView>
#include <uicontroller_cueworkspace.h>
#include <core/colorlinestrip.h>
#include <core/system_fileio.h>
#include "core/enums.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 创建系统单例
    System_CueManager sys_cueManager;
    System_CueWsManager sys_cueWsManager(&sys_cueManager);
    System_FileIO sys_fileIO(&sys_cueWsManager, &sys_cueManager);
    System_MainTimeLoop sys_mainLoop;
    System_CueAnimator sys_cueAnim(&sys_mainLoop);

    // 声明qml中可以使用ColorLineStrip
    qmlRegisterType<ColorLineStrip>("yel", 1, 0, "ColorLineStrip");

    // 创建qml端控制器并插入widget主窗口 //考虑widget改为全qml?
    UIController_CueWorkspace uc_cueWorkspace(&sys_cueAnim);
    uc_cueWorkspace.setworkspace(sys_cueWsManager.workspace());
    MainWindow w; //widget主窗口
    w.setQmlUIGrid(QUrl("qrc:/Block_Workspace.qml"), &uc_cueWorkspace); //插入qml
    QObject::connect(&w, &MainWindow::openWorkspace, &sys_fileIO, static_cast<void (System_FileIO::*)(QString)>(&System_FileIO::loadWorkspace));
    w.show();

    // 加载一个工作区文件看效果
    sys_fileIO.loadWorkspace("..\\..\\laser_control\\resources\\workspace\\1111.isw");


    return a.exec();
}
