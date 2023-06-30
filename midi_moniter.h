#ifndef MIDI_MONITER_H
#define MIDI_MONITER_H

#include <QDialog>

namespace Ui {
class midi_moniter;
}

class midi_moniter : public QDialog
{
    Q_OBJECT

public:
    explicit midi_moniter(QWidget *parent = nullptr);
    ~midi_moniter();

private:
    Ui::midi_moniter *ui;
};

#endif // MIDI_MONITER_H
