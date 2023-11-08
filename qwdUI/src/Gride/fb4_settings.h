#ifndef FB4_SETTINGS_H
#define FB4_SETTINGS_H

#include <QMainWindow>

namespace Ui {
class FB4_Settings;
}

class FB4_Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit FB4_Settings(QWidget *parent = nullptr);
    ~FB4_Settings();

private:
    Ui::FB4_Settings *ui;
};

#endif // FB4_SETTINGS_H
