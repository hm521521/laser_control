#ifndef TOGGLE_BUTTON_H
#define TOGGLE_BUTTON_H
#include<QPushButton>


class toggle_button:public QPushButton
{
    Q_OBJECT
public:
    toggle_button(QWidget*parent=nullptr);
    ~toggle_button();
    bool getValue();
    void setValue(bool press);
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    bool m_value;
};


#endif // TOGGLE_BUTTON_H
