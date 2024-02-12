#include "dmx_setup.h"
#include "ui_dmx_setup.h"
#include "dmax_output_dialog.h"
#define UNIVERSES_PER_ADDRESS   4

#define KOutputColumnNetwork   0
#define KOutputColumnUniverse  1

#define KNodesColumnIP          0
#define KNodesColumnShortName   1
#define KNodesColumnLongName    2

DMX_setup::DMX_setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMX_setup)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DMX_setup::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DMX_setup::reject);
    //    connect(this,SIGNAL(close()),this,SLOT(close_dialog()));
    settings = new QSettings("./artnet_config.ini", QSettings::IniFormat);
    settings->beginGroup("dmax_output_way");
    dmax_output_ways.push_back((dmax_output_way)settings->value("output1_way").toInt());
    dmax_output_ways.push_back((dmax_output_way)settings->value("output2_way").toInt());
    dmax_output_ways.push_back((dmax_output_way)settings->value("output3_way").toInt());
    dmax_output_ways.push_back((dmax_output_way)settings->value("output4_way").toInt());
    settings->endGroup();
    m_outputTree=ui->m_outputTree;
//    fillOutputTree();
}

DMX_setup::~DMX_setup()
{
    delete ui;
}

void DMX_setup::set_artnetPlugin(ArtNetPlugin *plugin)
{
    m_plugin=plugin;
}

void DMX_setup::fillOutputTree()
{
    this->m_outputTree->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QList<QNetworkAddressEntry> ifaces = m_plugin->interfaces();
    QList<ArtNetIO> IOmap = m_plugin->getIOMapping();

    foreach (QNetworkAddressEntry entry, ifaces)
    {
        QString ifaceStr = entry.ip().toString();
        for (int u = 0; u < UNIVERSES_PER_ADDRESS; u++)
        {
            QTreeWidgetItem* pitem = new QTreeWidgetItem(this->m_outputTree);
            pitem->setFlags(pitem->flags() | Qt::ItemIsUserCheckable);
            pitem->setCheckState(KOutputColumnNetwork, Qt::Unchecked);
            for (int idx = 0; idx < IOmap.length(); idx++)
            {
                if (IOmap.at(idx).IPAddress == ifaceStr && IOmap.at(idx).port == u)
                {
                    pitem->setCheckState(KOutputColumnNetwork, Qt::Checked);
                    break;
                }
            }
            pitem->setText(KOutputColumnNetwork, ifaceStr);
            pitem->setText(KOutputColumnUniverse, tr("Universe %1").arg(u + 1));
            pitem->setData(KOutputColumnUniverse, Qt::UserRole, u);
        }
    }
}

void DMX_setup::accept()
{
    qDebug() << Q_FUNC_INFO;
    QList<QString> newMappedIPs;
    QList<int> newMappedPorts;
    for (int i = 0; i < m_outputTree->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = m_outputTree->topLevelItem(i);
        if (item->checkState(KOutputColumnNetwork) == Qt::Checked)
        {
            newMappedIPs.append(item->text(KOutputColumnNetwork));
            newMappedPorts.append(item->data(KOutputColumnUniverse, Qt::UserRole).toInt());
        }
    }
    m_plugin->remapOutputs(newMappedIPs, newMappedPorts);
    QDialog::accept();
}

void DMX_setup::reject()
{
    //int current_output = settings->value("current_output").toInt();
    emit set_artnet();
    QDialog::reject();
}

void DMX_setup::dealwithoutputsetting(int id)
{

}


