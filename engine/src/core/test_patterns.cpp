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
    ui->test_list->setup(m_path);
    connect(ui->test_list,SIGNAL(clicked(QModelIndex)),this,SLOT(show_test_view(QModelIndex)));
}

test_patterns::~test_patterns()
{
    delete ui;
}

void test_patterns::show_test_view(QModelIndex current)
{
    if(m_path.isNull())
        return;
    QString str=current.data().toString().split(" ").at(0);
    QStringList pathsplit=m_path.split("/");
    if(pathsplit.isEmpty()) return;
    pathsplit.pop_back();
    pathsplit.push_back(str.append(".ild"));
    str=pathsplit.join('/');
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

//void my_list_view::currentChanged(const QModelIndex &current, const QModelIndex &previous)
//{

//}

//void my_list_view::set_output(bool flag)
//{
//    out_to_laser=flag;
//}





//void test_patterns::on_pushButton_clicked()
//{
//    ui->test_list->set_out_laser(ui->output_pushButton->getValue());
//}

