#ifndef PROGRAMGROUPINFO_H
#define PROGRAMGROUPINFO_H

#include <QWidget>

namespace Ui {
class ProgramGroupInfo;
}

class ProgramGroupInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ProgramGroupInfo(QWidget *parent = nullptr);
    ~ProgramGroupInfo();

private:
    Ui::ProgramGroupInfo *ui;
};

#endif // PROGRAMGROUPINFO_H
