#ifndef DMX_SETUP_H
#define DMX_SETUP_H

#include <QDialog>
#include<unordered_map>
#include<QSettings>
#include"artnetplugin.h"
#include<QTreeWidget>


namespace Ui {
class DMX_setup;
}
enum dmax_output_way {
    Disabled = 0,
    Artnet,
    sACN
};

class DMX_setup : public QDialog
{
    Q_OBJECT

public:
    explicit DMX_setup(QWidget *parent = nullptr);
    ~DMX_setup();
    void set_artnetPlugin(ArtNetPlugin* plugin);
private:
    Ui::DMX_setup *ui;
    QSettings* settings;
    std::vector<dmax_output_way> dmax_output_ways;
    std::unordered_map<dmax_output_way, std::string> dmaxToString = { {Disabled,"Disabled"},{Artnet,"Artnet"},{sACN,"sACN"} };

private:
    ArtNetPlugin* m_plugin;
    QTreeWidget *m_outputTree;
    QTreeWidget *m_nodesTree;
public:
    void fillOutputTree();
//    void fillNodesTree();

private:
    void load_dmax_output_way();
public slots:
    void dealwithoutputsetting(int id);
//    void set_dmax_output_way(int output_id, int way_id);
    void accept() override;
    void reject() override;

signals:
    void set_artnet();
};

#endif // DMX_SETUP_H
