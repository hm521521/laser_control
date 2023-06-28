#include "test_patterns.h"
#include "ui_test_patterns.h"
#include<QStandardItemModel>
#include<QFile>
#include<QDebug>

test_patterns::test_patterns(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test_patterns)
{
    ui->setupUi(this);
    m_device_table=ui->tableView;
    ui->test_list->setup("/system/test_list.txt");
}

test_patterns::~test_patterns()
{
    delete ui;
}


my_list_view::my_list_view(QWidget *parent)
{

}

my_list_view::~my_list_view()
{

}

void my_list_view::setup(QString list_path)
{
    m_list_path=list_path;
    QStandardItemModel* model=new QStandardItemModel;
    QString filename=QCoreApplication::applicationDirPath();
    filename.append(m_list_path);
    QFile file(filename);
//    qDebug() << file.exists();
    if(!file.open(QIODevice::ReadOnly))
        return;
    QByteArray bytearray = file.readLine(32);
    while (bytearray.size()>0) {
        QStandardItem *item = new QStandardItem(bytearray.data());
        model->appendRow(item);
        bytearray = file.readLine(32);
    }
    this->setModel(model);
    this->show();
}
