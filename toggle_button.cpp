#include "toggle_button.h"
#include<QMouseEvent>

toggle_button::toggle_button(QWidget *parent):QPushButton(parent)
  ,m_value(false)
{

}

toggle_button::~toggle_button()
{

}

bool toggle_button::getValue()
{
    return m_value;
}

void toggle_button::setValue(bool press)
{
    m_value=press;
}

void toggle_button::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_value=!m_value;
    }
    QPushButton::mousePressEvent(event);
}

