#ifndef PROJECTION_ZONES_H
#define PROJECTION_ZONES_H

#include <QMainWindow>
#include "mainwindow1.h"
#include <QStandardItemModel>


struct cor_Size{
    float x=100;
    float y=100;
};
struct cor_Position{
    float x=0;
    float y=0;
};
struct cor_Rotation{
    float angle=0;
};
struct cor_Linearity{
    float x=0;
    float y=0;
};
struct cor_Symmetry{
    float left=0;
    float right=0;
    float top=0;
    float bottom=0;
};
struct cor_Keystone{
    float x=0;
    float y=0;
};
struct cor_Pincushion{
    float left=0;
    float right=0;
    float top=0;
    float bottom=0;
};
struct cor_Bow{
    float left=0;
    float right=0;
    float top=0;
    float bottom=0;
};
struct cor_Shear{
    float x=0;
    float y=0;
};


struct Audience_Scanning_Beam{
    float emuLaserPosX=0;
    float emuLaserPosY=0;
};

struct Preview_ERP{
    int fogFrontBrightness=13;
    int fogRearBrightness=71;
    int fogDesigty=100;
    int fogSpeed=0;
    int gauzeScreenDistance=0;
};
namespace Ui {
class projection_zones;
}

struct pro_zone_settings{
    QString pro_zone_name;//general
    cor_Size corsize;
    cor_Position corpos;
    cor_Rotation corrot;
    cor_Linearity corline;
    cor_Symmetry corsym;
    cor_Keystone corkeystone;
    cor_Pincushion corpin;
    cor_Bow corbow;
    cor_Shear corshear;
    int preview_width=100;
    int preview_height=100;
    int preview_position_x=0;
    int preview_position_y=0;
    int preview_rotation=0;
    int preview_beam_diameter=1.0;
    QByteArray attenuation_picture;//beam attenuation 60*60
//    bool apply_attenuation;
    QString projector_name;
    Audience_Scanning_Beam scanbeam;
    Preview_ERP preerp;
};


class projection_zones : public SubWindow
{
    Q_OBJECT
public:
    explicit projection_zones(MainWindow1 *parent = nullptr);
    ~projection_zones();
    QString getMyType();
    laser_device_table *m_device_table;
private slots:
    void newZoneName(QString str);
    void on_addZones_pushButton_clicked();
    void on_delete_zone_pushButton_clicked();
    void buttonClicked(int index);
private:
    Ui::projection_zones *ui;
    QString m_type;
    QStringList m_namelist;
    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;
    void refresh_laser_device();
    MainWindow1 *m_parent;
    QStandardItemModel *theProjectorModel;
    QItemSelectionModel *theProjectorSelection;
    QSettings *m_qsettings;
    void load_settings();
    void save_settings();
    QList<pro_zone_settings> m_settings;
    QButtonGroup *m_button_group;
    void new_pro_settings();//clear current Projection Zone settings and load default settings
    void open_settings();
    void add_projection_zone();
    void init_settings(pro_zone_settings &s);
};

#endif // PROJECTION_ZONES_H
