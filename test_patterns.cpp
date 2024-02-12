#include "test_patterns.h"
#include "ui_test_patterns.h"
#include<QStandardItemModel>
#include<QFile>
#include<QDebug>

test_patterns::test_patterns(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::test_patterns)
{
	ui->setupUi(this);
	m_device_table = ui->tableView;
	ui->test_list->setup(m_path);
	connect(ui->test_list, SIGNAL(clicked(QModelIndex)), this, SLOT(show_test_view(QModelIndex)));
	connect(ui->test_list, SIGNAL(sendSection(CJSection)), this, SLOT(receiveSection(CJSection)));
	//connect(ui->output_pushButton, SIGNAL(), this, SLOT());
}



test_patterns::~test_patterns()
{
	delete ui;
}

void test_patterns::receiveSection(CJSection section)
{
	emit sendSection(section);
}

void test_patterns::show_test_view(QModelIndex current)
{
	if (m_path.isNull())
		return;
	QString str = current.data().toString().split(" ").at(0);
	QStringList pathsplit = m_path.split("/");
	if (pathsplit.isEmpty()) return;
	pathsplit.pop_back();
	pathsplit.push_back(str.append(".ild"));
	str = pathsplit.join('/');
}

my_list_view::my_list_view(QWidget* parent)
{

}

my_list_view::~my_list_view()
{

}

void my_list_view::setup(QString list_path)
{
	m_list_path = list_path;
	QStandardItemModel* model = new QStandardItemModel;
	QString filename = QCoreApplication::applicationDirPath();
	filename.append(m_list_path);
	QFile file(filename);
	//    qDebug() << file.exists();
	if (!file.open(QIODevice::ReadOnly))
		return;
	QByteArray bytearray = file.readLine(32);
	while (bytearray.size() > 0) {
		QStandardItem* item = new QStandardItem(bytearray.data());
		model->appendRow(item);
		bytearray = file.readLine(32);
	}
	this->setModel(model);
	this->show();
}

void my_list_view::currentChanged(const QModelIndex& current, const QModelIndex& previous)
{
	auto data = this->model()->data(current);
	QString dtr = data.toString();
	QFile file;
	QString filename = QCoreApplication::applicationDirPath();
	QString filepath = QString("/system/") + dtr.mid(0, 4) + ".txt";
	filename.append(filepath);
	qDebug() << filename;
	file.setFileName(filename);
	if (!file.open(QIODevice::ReadOnly))
		return;
	CJSection section;
	QByteArray array=file.readAll();
	if (!array.isEmpty())
	{
		for (int i = 0; i < array.size() / 8; i++)
		{
			char ch[1];
			ch[0] = array.at(i * 8);
			ch[1] = array.at(i * 8 + 1);
			int X = 0;
			memcpy(&X,ch,sizeof(ch));
			int Y = 0;
			ch[0] = array.at(i * 8 + 2);
			ch[1] = array.at(i * 8 + 3);
			memcpy(&Y, ch, sizeof(ch));
			
			uchar R = 0;
			char r = array.at(i * 8 + 5);
			memcpy(&R, &r, sizeof(R));
			
			uchar G = 0;
			char g=array.at(i * 8 + 6);
			memcpy(&G, &g, sizeof(G));
			
			uchar B = 0; 
			char b= array.at(i * 8 + 7);
			memcpy(&B, &b, sizeof(B));
			if (R != 0 || G != 0 || B != 0)
				qDebug() << R << G << B;
			PointAttribute pc(X, Y, 0, R, G, B);
			section.push_back(pc);
			
		}
	}
	emit sendSection(section);
		
}

//void my_list_view::set_output(bool flag)
//{
//    out_to_laser=flag;
//}





//void test_patterns::on_pushButton_clicked()
//{
//    ui->test_list->set_out_laser(ui->output_pushButton->getValue());
//}


void test_patterns::on_output_pushButton_clicked()
{
    emit on_enable_output();
}

