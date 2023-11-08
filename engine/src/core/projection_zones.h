#ifndef PROJECTION_ZONES_H
#define PROJECTION_ZONES_H

#include <QMainWindow>
#include "mainwindow1.h"
#include <QStandardItemModel>

enum cor_for_switch
{
    corSizecorsize=0,
    corPositioncorpos,
    corRotationcorrot,
    corLinearitycorline,
    corSymmetrycorsym,
    corKeystonecorkeystone,
    corPincushioncorpin,
    corBowcorbow,
    corShearcorshear
};

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
    QStringList zone_id_names;
};


class zone_names_table:public QListView
{
    Q_OBJECT
public:
    zone_names_table(QWidget *parent=0);
    ~zone_names_table();
private:
    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;
public slots:
    void display(QStringList m_namelist);
};

class zone_id_listView:public QListView
{
    Q_OBJECT
public:
    zone_id_listView(QWidget *parent=0);
    ~zone_id_listView();
private:
    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;
public slots:
    void display(QStringList m_idlist);
};


class projection_zones : public SubWindow
{
    Q_OBJECT
public:
    explicit projection_zones(MainWindow1 *parent = nullptr);
    ~projection_zones();
    QString getMyType();
    laser_device_table *m_device_table;
    zone_names_table *m_zones_table;
private slots:
    void newZoneName(QString str);
    void newIdName(QString str);
    void on_addZones_pushButton_clicked();
    void on_delete_zone_pushButton_clicked();
    void buttonClicked(int index);
    void zone_name_changed(QModelIndex);
    void on_size_radioButton_clicked();
    void radio_groupbox_clicked(int index);
    void math_groupbox_clicked(int index);
public slots:
    void loadZoneName();
    void delete_projection_zone();
    void delete_zone_id();
private:
    Ui::projection_zones *ui;
    QString m_type;
//    QStringList m_namelist;
//    QStandardItemModel *theModel;
//    QItemSelectionModel *theSelection;
    void refresh_laser_device();
    MainWindow1 *m_parent;
//    QStandardItemModel *theProjectorModel;
    QItemSelectionModel *theProjectorSelection;
    QSettings *m_qsettings;
    void load_settings();
    void save_settings();
    QList<pro_zone_settings> m_settings;
    QButtonGroup *m_button_group;
    QButtonGroup *m_radio_group;
    QButtonGroup *m_leftmath_group;
    QButtonGroup *m_rightmath_group;
    QButtonGroup *m_bottommath_group;
    QButtonGroup *m_topmath_group;
    void new_pro_settings();//clear current Projection Zone settings and load default settings
    void open_settings();
    void add_projection_zone();
    void init_settings(pro_zone_settings &s);
    void init_zone_id();
    void add_zone_id_name();
    void connectSliderAndSpin(QSlider *slider, QDoubleSpinBox *spin);
    void change_setting_values(int i,QString slidername,double spinvalue);
    QList<QStringList> m_zone_ids;
signals:
    void display_zone_names(QStringList m_namelist);
    void display_id_names(QStringList id_list);
};

#endif // PROJECTION_ZONES_H
