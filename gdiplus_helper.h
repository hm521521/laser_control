#ifndef GDIPLUS_HELPER_H
#define GDIPLUS_HELPER_H
#include <string>
#include "cjsection.h"


class gdiplus_helper
{
public:
//    gdiplus_helper();
    static void get_point_from_text(QString txt, CJSection& section
                , unsigned char r, unsigned char g, unsigned char b);
};

#endif // GDIPLUS_HELPER_H
