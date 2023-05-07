#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include<QString>
#include<QUrl>

class Configuration
{
public:
    Configuration();
    void Reset();
    void Save();
    void Load();
    bool getLoop() const;
    void setLoop(bool value);
    bool x_invert; //x反向
    bool y_invert; //y 反向
    bool xy_swap; //xy交换
    float x_size; //x方向大小
    float y_size; //y 方向大小
    bool xy_locked; //锁定xy比例
    int x_offset; //x方向偏移
    int y_offset; //y方向偏移
    bool adjust_r; //是否使用R
    float red; //R
    bool adjust_g; //是否使用R
    float green; //G
    bool adjust_b; //是否使用R
    float blue; //B
    bool moORsu;//模拟调节
    float Ybi; //亮度
    int Speed; //振镜速度（*1000）
    int PointGap; //点间隙最大
    unsigned char Delay; //光源断笔延时
    std::string lang;

private:
    bool Loop = true;
    QString m_path;
};

#endif // CONFIGURATION_H
