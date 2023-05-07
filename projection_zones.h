#ifndef PROJECTION_ZONES_H
#define PROJECTION_ZONES_H

#include <QMainWindow>
#include "mainwindow1.h"
#include <QStandardItemModel>

namespace Ui {
class projection_zones;
}

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
};

#endif // PROJECTION_ZONES_H
