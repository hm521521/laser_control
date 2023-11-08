#ifndef ILDAFILE_H
#define ILDAFILE_H
#include <stdint.h>
#include<stdio.h>
#include<Windows.h>
typedef struct tagILDAFILEHEADER {
    char filetype[4] = { 'I','L','D','A'};//������"ILDA"  ADLI  4
    WORD Reserved1 = 0; // 2
    uint8_t Reserved = 0;// 1
    uint8_t FormatCode=1;// 1
    DWORD64 FoCPalette_Name = 0;//8
    DWORD64 Company_Name = 0;// 8
    unsigned char a = 0x04;
    unsigned char b = 0x46;
    //unsigned short Record_Number;// 2 Total number of data records (points or colors)
    WORD FoCPalette_Number=0;//. 2  If the frame is part of a group such as an animation sequence, this represents the frame number.Counting begins with frame 0. Range is 0 �C 65534.
    WORD Total_F=0x0100;// 2 Total frames in this group or sequence. Range is 1 �C 65535. For color palettes this SHALL be 0.
    uint8_t Projector_name = 0;// 1 The projector number that this frame is to be displayed on. Range is 0 �C 255. For single projector files this SHOULD be set 0.

    uint8_t Reserved3 = 0; // 1



}ILDAFILEHEADER;

typedef struct tagILDAINFOHEADER {
    short X;
    short Y;
    unsigned char Status=0;//����һ����������Ҫ����ʱ�޸�
    //unsigned char blue=0;
    unsigned char green=255;
    //unsigned char red=0;

}ILDAINFODATA;
typedef struct tagILDAFILE {
    ILDAFILEHEADER ildafh;
    ILDAINFODATA* ildadata;

}ILDA;
#endif // ILDAFILE_H
