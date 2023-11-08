#include "configuration.h"
#include<QCoreApplication>
#include<QFile>
//#include<iostream>
//#include<fstream>
#include<QDataStream>
#include<QFileDialog>
#include<QObject>
constexpr auto CONFIG_HEADER = "hwstaticconfig";

//Configuration::Configuration()
//{
//    Loop = true;
//    x_invert = false;
//    y_invert = false;
//    xy_swap = false;
//    x_size = 1.0f;
//    y_size = 1.0f;
//    xy_locked = true;
//    x_offset = 0;
//    y_offset = 0;
//    adjust_r = true;
//    red = 1.0f;
//    adjust_g = true;
//    green = 1.0f;
//    adjust_b = true;
//    blue = 1.0f;
//    moORsu = true;
//    Ybi = 1.0f;
//    Speed = 20;
//    PointGap = 10;
//    Delay = 1;
//    lang = "zh-CN";
//    m_path=QCoreApplication::applicationDirPath();
//    m_path.append("/system/de.config");
//}

Configuration::Configuration(QWidget* parent)
{
    Loop = true;
    x_invert = false;
    y_invert = false;
    xy_swap = false;
    x_size = 1.0f;
    y_size = 1.0f;
    xy_locked = true;
    x_offset = 0;
    y_offset = 0;
    adjust_r = true;
    red = 1.0f;
    adjust_g = true;
    green = 1.0f;
    adjust_b = true;
    blue = 1.0f;
    moORsu = true;
    Ybi = 1.0f;
    Speed = 20;
    PointGap = 10;
    Delay = 1;
    lang = "zh-CN";
    m_path=QCoreApplication::applicationDirPath();
    m_path.append("/system/de.config");
}

void Configuration::Reset()
{
    this->x_invert = false;
    this->y_invert = false;
    this->xy_swap = false;
    this->x_size = 1.0f;
    this->y_size = 1.0f;
    this->xy_locked = true;
    this->x_offset = 0;
    this->y_offset = 0;
}

void Configuration::Save()
{
//    QString m_path;

//    m_path="C:\\Users\\hm521\\Documents\\build-TCPServer-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\debug";
//    m_path.append("/system/de.config");
    QFile file(this);
    file.setFileName(m_path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        QDataStream binaryWriter(&file);
        int len = strlen(CONFIG_HEADER);
        binaryWriter.writeRawData((char*)&len, 1);
        binaryWriter.writeRawData(CONFIG_HEADER, len);
        binaryWriter.writeRawData((char*)&Loop, 1);
        binaryWriter.writeRawData((char*)&x_invert, 1);
        binaryWriter.writeRawData((char*)&y_invert, 1);
        binaryWriter.writeRawData((char*)&xy_swap, 1);
        binaryWriter.writeRawData((char*)&x_size, 4);
        binaryWriter.writeRawData((char*)&y_size, 4);
        binaryWriter.writeRawData((char*)&xy_locked, 1);
        binaryWriter.writeRawData((char*)&x_offset, 4);
        binaryWriter.writeRawData((char*)&y_offset, 4);
        binaryWriter.writeRawData((char*)&adjust_r, 1);
        binaryWriter.writeRawData((char*)&red, 4);
        binaryWriter.writeRawData((char*)&adjust_g, 1);
        binaryWriter.writeRawData((char*)&green, 4);
        binaryWriter.writeRawData((char*)&adjust_b, 1);
        binaryWriter.writeRawData((char*)&blue, 4);
        binaryWriter.writeRawData((char*)&moORsu, 1);
        binaryWriter.writeRawData((char*)&Ybi, 4);
        binaryWriter.writeRawData((char*)&Speed, 4);
        binaryWriter.writeRawData((char*)&PointGap, 4);
        binaryWriter.writeRawData((char*)&Delay, 1);
        int lang_len=lang.length();
        binaryWriter.writeRawData((char*)&lang_len, 1);
        binaryWriter.writeRawData(lang.c_str(), lang_len);
        file.close();
}
}

void Configuration::Load()
{
    QFile file(m_path);
    if(!file.open(QIODevice::ReadOnly))
        return;
    QDataStream binaryReader(&file);
    unsigned char header_len=0;
    binaryReader.readRawData((char*)header_len,sizeof(header_len));
    if(header_len==strlen(CONFIG_HEADER))
    {
        char header[128]={0};
        binaryReader.readRawData(header,header_len);
        if(0 == strcmp(header, CONFIG_HEADER))
        {
            binaryReader.readRawData((char*)&this->Loop, 1);
            binaryReader.readRawData((char*)&this->x_invert, 1);
            binaryReader.readRawData((char*)&this->y_invert, 1);
            binaryReader.readRawData((char*)&this->xy_swap, 1);
            binaryReader.readRawData((char*)&this->x_size, 4);
            binaryReader.readRawData((char*)&this->y_size, 4);
            binaryReader.readRawData((char*)&this->xy_locked, 1);
            binaryReader.readRawData((char*)&this->x_offset, sizeof(int));
            binaryReader.readRawData((char*)&this->y_offset, sizeof(int));
            binaryReader.readRawData((char*)&this->adjust_r, sizeof(bool));
            binaryReader.readRawData((char*)&this->red, sizeof(float));
            binaryReader.readRawData((char*)&this->adjust_g, sizeof(bool));
            binaryReader.readRawData((char*)&this->green, sizeof(float));
            binaryReader.readRawData((char*)&this->adjust_b, sizeof(bool));
            binaryReader.readRawData((char*)&this->blue, sizeof(float));
            binaryReader.readRawData((char*)&this->moORsu, sizeof(bool));
            binaryReader.readRawData((char*)&this->Ybi, sizeof(float));
            binaryReader.readRawData((char*)&this->Speed, sizeof(int));
            binaryReader.readRawData((char*)&this->PointGap, sizeof(int));
            binaryReader.readRawData((char*)&this->Delay, sizeof(unsigned char));
            int size = 0;
            binaryReader.readRawData((char*)&size, sizeof(char));
            this->lang.resize(size);
            binaryReader.readRawData((char*)this->lang.data(), size);
        }

    }
}

void Configuration::SaveAs()
{
    QString filename=QFileDialog::getSaveFileName(this,tr("保存配置"),"/system/de.config",tr("配置文件(*.config)"));
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream binaryWriter(&file);
        int len = strlen(CONFIG_HEADER);
        binaryWriter.writeRawData((char*)&len, 1);
        binaryWriter.writeRawData(CONFIG_HEADER, len);
        binaryWriter.writeRawData((char*)&Loop, 1);
        binaryWriter.writeRawData((char*)&x_invert, 1);
        binaryWriter.writeRawData((char*)&y_invert, 1);
        binaryWriter.writeRawData((char*)&xy_swap, 1);
        binaryWriter.writeRawData((char*)&x_size, 4);
        binaryWriter.writeRawData((char*)&y_size, 4);
        binaryWriter.writeRawData((char*)&xy_locked, 1);
        binaryWriter.writeRawData((char*)&x_offset, 4);
        binaryWriter.writeRawData((char*)&y_offset, 4);
        binaryWriter.writeRawData((char*)&adjust_r, 1);
        binaryWriter.writeRawData((char*)&red, 4);
        binaryWriter.writeRawData((char*)&adjust_g, 1);
        binaryWriter.writeRawData((char*)&green, 4);
        binaryWriter.writeRawData((char*)&adjust_b, 1);
        binaryWriter.writeRawData((char*)&blue, 4);
        binaryWriter.writeRawData((char*)&moORsu, 1);
        binaryWriter.writeRawData((char*)&Ybi, 4);
        binaryWriter.writeRawData((char*)&Speed, 4);
        binaryWriter.writeRawData((char*)&PointGap, 4);
        binaryWriter.writeRawData((char*)&Delay, 1);
        int lang_len=lang.length();
        binaryWriter.writeRawData((char*)&lang_len, 1);
        binaryWriter.writeRawData(lang.c_str(), lang_len);
        file.close();
    }

}

bool Configuration::getLoop() const
{
    return Loop;
}

void Configuration::setLoop(bool value)
{
    Loop=value;
}
