#include "dialog_fb4_export.h"
#include "ui_dialog_fb4_export.h"

Dialog_FB4_Export::Dialog_FB4_Export(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FB4_Export)
{
    ui->setupUi(this);


}

Dialog_FB4_Export::~Dialog_FB4_Export()
{

    delete ui;
}

void Dialog_FB4_Export::on_listWidget_FB4_Ex_itemClicked(QListWidgetItem *item)
{
    int index = ui->listWidget_FB4_Ex->currentRow();
    switch (index) {
    case 0:ui->label_2->clear();ui->label_2->setText("如果要将内容包上载到连接的FB4，请选择此选项");break;
    case 1:ui->label_2->clear();ui->label_2->setText("如果要使用Pangolin标准测试帧，请选择此选项。");break;
    case 2:ui->label_2->clear();ui->label_2->setText("如果要从空白项目开始导出文件，请选择此选项");break;
    case 3:ui->label_2->clear();ui->label_2->setText("将前9个工作区页面分配给DMX映射");break;
    case 4:ui->label_2->clear();ui->label_2->setText("创建空模板，您可以在其中手动分配工作区提示或文件。");break;
    case 5:ui->label_2->clear();ui->label_2->setText("将所有工作区页面分配给DMX映射");break;
    case 6:ui->label_2->clear();ui->label_2->setText("创建空模板，您可以在其中手动为FB4/MAX分配工作区提示或文件");break;
    case 7:ui->label_2->clear();ui->label_2->setText("如果您想创建几个动画文件，请选择此选项，这些文件可以在FB4显示器中选择，并通过投影仪通电启动。如果您需要一些复杂的内容，如文件序列或基于时间的播放时间表，请选择上面的一个选项");break;
    case 8:ui->label_2->clear();ui->label_2->setText("简单播放列表是FB4将依次播放的文件列表。在这种模式下，无法设置文件的开始时间。它不是基于时间的调度程序。如果我只想在一个序列中播放几个文件，请使用这种模式");break;
    case 9:ui->label_2->clear();ui->label_2->setText("单日调度程序允许您组成基于时间的动画文件序列。此调度程序将每天重新开始，没有任何例外。如果需要更多，请使用多天调度程序");break;
    case 10:ui->label_2->clear();ui->label_2->setText("这是最复杂的计划程序版本，包括一周中每一天的个人计划，以及假期等特殊日子。在这种模式下，您需要为一周中的每一天定义计划。假期计划是可选的，并且比正常的周计划具有更高的优先级");break;
    case 11:ui->label_2->clear();ui->label_2->setText("如果不需要创建任何动画文件，而需要上载一些以前创建的文件，请选择此选项");break;


    }


}

