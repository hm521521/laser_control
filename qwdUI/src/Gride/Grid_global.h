#ifndef GRID_GLOBAL_H
#define GRID_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GRID_LIBRARY)
#  define GRID_EXPORT Q_DECL_EXPORT
#else
#  define GRID_EXPORT Q_DECL_IMPORT
#endif

class GRID_EXPORT Untitled2
{
public:
    Untitled2();
};

#endif // GRID_GLOBAL_H
