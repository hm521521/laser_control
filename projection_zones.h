#ifndef PROJECTION_ZONES_H
#define PROJECTION_ZONES_H

#include <QMainWindow>
#include "mainwindow1.h"
#include <QStandardItemModel>

enum correction_type{
    Size,
    Position,
    Rotation,
    Linearity,
    Symmetry,
    Keystone,
    Pincushion,
    Bow,
    Shear
};
enum preview_pattern{
    Laser_Graphics,
    Audience_Scanning_Beam
};

enum display_pattern{
    GDI,
    ERP
};
Q_DECLARE_METATYPE(correction_type)
Q_DECLARE_METATYPE(preview_pattern)
Q_DECLARE_METATYPE(display_pattern)
namespace Ui {
class projection_zones;
}

struct pro_zone_settings{
    QString pro_zone_name;//general
    correction_type ct;//correction
    float x;
    float y;
    preview_pattern prepat;//preview
    bool YAG_projector;
    int width;
    int height;
    int position_x;
    int position_y;
    int rotation;
    int beam_diameter;
    display_pattern dis_pat;
    QByteArray attenuation_picture;//beam attenuation 60*60
    bool apply_attenuation;
};


class projection_zones : public SubWindow
{
    Q_OBJECT
public:
    explicit projection_zones(MainWindow1 *parent = nullptr);
    ~projection_zones();
    QString getMyType();
private slots:
    void newZoneName(QString str);
    void on_addZones_pushButton_clicked();
    void on_delete_zone_pushButton_clicked();
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
     void default_pro_setting();
     QList<pro_zone_settings> m_settings;

};

#endif // PROJECTION_ZONES_H
