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
    case 0:ui->label_2->clear();ui->label_2->setText("���Ҫ�����ݰ����ص����ӵ�FB4����ѡ���ѡ��");break;
    case 1:ui->label_2->clear();ui->label_2->setText("���Ҫʹ��Pangolin��׼����֡����ѡ���ѡ�");break;
    case 2:ui->label_2->clear();ui->label_2->setText("���Ҫ�ӿհ���Ŀ��ʼ�����ļ�����ѡ���ѡ��");break;
    case 3:ui->label_2->clear();ui->label_2->setText("��ǰ9��������ҳ������DMXӳ��");break;
    case 4:ui->label_2->clear();ui->label_2->setText("������ģ�壬�������������ֶ����乤������ʾ���ļ���");break;
    case 5:ui->label_2->clear();ui->label_2->setText("�����й�����ҳ������DMXӳ��");break;
    case 6:ui->label_2->clear();ui->label_2->setText("������ģ�壬�������������ֶ�ΪFB4/MAX���乤������ʾ���ļ�");break;
    case 7:ui->label_2->clear();ui->label_2->setText("������봴�����������ļ�����ѡ���ѡ���Щ�ļ�������FB4��ʾ����ѡ�񣬲�ͨ��ͶӰ��ͨ���������������ҪһЩ���ӵ����ݣ����ļ����л����ʱ��Ĳ���ʱ�����ѡ�������һ��ѡ��");break;
    case 8:ui->label_2->clear();ui->label_2->setText("�򵥲����б���FB4�����β��ŵ��ļ��б�������ģʽ�£��޷������ļ��Ŀ�ʼʱ�䡣�����ǻ���ʱ��ĵ��ȳ��������ֻ����һ�������в��ż����ļ�����ʹ������ģʽ");break;
    case 9:ui->label_2->clear();ui->label_2->setText("���յ��ȳ�����������ɻ���ʱ��Ķ����ļ����С��˵��ȳ���ÿ�����¿�ʼ��û���κ����⡣�����Ҫ���࣬��ʹ�ö�����ȳ���");break;
    case 10:ui->label_2->clear();ui->label_2->setText("������ӵļƻ�����汾������һ����ÿһ��ĸ��˼ƻ����Լ����ڵ��������ӡ�������ģʽ�£�����ҪΪһ���е�ÿһ�춨��ƻ������ڼƻ��ǿ�ѡ�ģ����ұ��������ܼƻ����и��ߵ����ȼ�");break;
    case 11:ui->label_2->clear();ui->label_2->setText("�������Ҫ�����κζ����ļ�������Ҫ����һЩ��ǰ�������ļ�����ѡ���ѡ��");break;


    }


}

