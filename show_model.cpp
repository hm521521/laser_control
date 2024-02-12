#include "show_model.h"

show_model::show_model()
    :m_interval(40),
      m_x_end(0)
{

}

int show_model::get_interval()
{
    return m_interval;
}

int show_model::get_x_end()
{
    return m_x_end;
}
