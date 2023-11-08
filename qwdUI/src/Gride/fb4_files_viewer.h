#ifndef FB4_FILES_VIEWER_H
#define FB4_FILES_VIEWER_H

#include <QMainWindow>

namespace Ui {
class FB4_Files_viewer;
}

class FB4_Files_viewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit FB4_Files_viewer(QWidget *parent = nullptr);
    ~FB4_Files_viewer();

private:
    Ui::FB4_Files_viewer *ui;
};

#endif // FB4_FILES_VIEWER_H
