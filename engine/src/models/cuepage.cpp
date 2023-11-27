#include "cuepage.h"
#include "core/constants.h"

CuePage::CuePage(QObject *parent)
    : QObject{parent}
{
    m_cues = QVector<CueBase*>(CUE_GRID_COUNT, nullptr);
}
