#ifndef EFFECT_H
#define EFFECT_H
#include"cjimage.h"
#include"color.h"

enum class EffectType
{
    ET_PICTURE,		//点阵图片
    ET_TEXT,		//文字
    ET_TIME,		//时钟
    ET_BLACK,		//黑屏
    ET_COLOR,		//颜色
    ET_X_MOVE,		//水平移动
    ET_Y_MOVE,		//垂直移动
    ET_Z_MOVE,		//纵深移动
    ET_X_ROTATE,	//水平旋转
    ET_Y_ROTATE,	//垂直旋转
    ET_Z_ROTATE,	//中心旋转
    ET_X_SIZE,		//水平大小
    ET_Y_SIZE,		//垂直大小
    ET_X_INVERT,	//水平镜像
    ET_Y_INVERT,	//垂直镜像
    ET_XY_SIZE,		//大小
    ET_GRADUALLY_RENDER		//渐绘
};

class PictureInfo//图片信息类
{
private:
    EffectType m_type;
    int m_index;

public:
    PictureInfo(EffectType t, int i);

    EffectType get_type() const;
    //void setType(EffectType value);
    int get_index() const;
    //void setIndex(int value);
};

class effect
{
public:
    effect();
    ~effect();
    static effect* CreateEffect(PictureInfo *pi);
    int max_frame_length() const{return this->m_start_frame_index+this->m_frame_length;}
public:
    union//联合中只能有一个数据成员可以有值
    {
        struct
        {
            int m_start_index;
            int m_end_index;
            int m_loop;
            int m_loop_time;
        }point_param;

        struct
        {
            int m_mode;
            int m_r;
            int m_g;
            int m_b;
        }color_param;

        struct
        {
            int m_r;
            int m_g;
            int m_b;
            int m_font_size;
        }text_param;

        struct
        {
            int m_mode;
            int m_data[3];
        }rotate_param;

        int param_data[4];
    } Param;
    CJImage get_pictures();
    effect *Load();
    void set_pictures(CJImage pic);
    void set_type(EffectType type);
    void set_index(int ind);
    void set_start_index(int start);
    void set_frame_length(int len);
    EffectType get_type();
    int get_index();
    virtual void render(CJSection& section, int time) = 0;//虚函数，需要子类重写，把m_pictures中保留的动画存入section
    int get_start_index();
    int get_frame_length();
protected:
    EffectType m_type;
    CJImage m_pictures;//动画数据类即一张动画上的所有图
    int m_index;
    int m_start_frame_index;
    int m_frame_length;
};


class point_effect:public effect
{
public:
    point_effect();
    void render(CJSection& section, int time) override;

};

class text_effect:public effect
{
public:
    text_effect();
    void render(CJSection& section, int time) override;
private:
    bool m_invert;//反向
};

class time_effect:public effect
{
public:
    time_effect();
    void render(CJSection& section, int time) override;
private:
    Color color;

};
class BlackEffect:public effect
{
public:
    BlackEffect();
    void render(CJSection& section, int time) override;
};

class color_effect : public effect//当动画效果为ET_COLOR时，创建的对应的类
{
public:
    color_effect();
    void render(CJSection& section, int time) override;
private:
    void GenerateColor();//生成随机颜色
    const int rametime=100;
    static int rametimetiem;
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};
class XMoveEffect : public effect//沿X轴移动效果
{
public:
    XMoveEffect();
    void render(CJSection& section, int time) override;
};

class YMoveEffect : public effect//y坐标横移
{
public:
    YMoveEffect();
    void render(CJSection& section, int time) override;
};

class ZMoveEffect : public effect//z坐标平移
{
public:
    ZMoveEffect();
    void render(CJSection& section, int time) override;
};
class XRotateEffect : public effect//x旋转效果
{
public:
    XRotateEffect();
    void render(CJSection& section, int time) override;
};
class YRotateEffect : public effect
{
public:
    YRotateEffect();
    void render(CJSection& section, int time) override;
};

class ZRotateEffect : public effect//绕z轴旋转
    {
    public:
        ZRotateEffect();
        void render(CJSection& section, int time) override;
};
class XSizeEffect : public effect//
{
public:
    XSizeEffect();
    void render(CJSection& section, int time) override;
};

class YSizeEffect : public effect
{
public:
    YSizeEffect();
    void render(CJSection& section, int time) override;
};

class XInvertEffect : public effect
{
public:
    XInvertEffect();
    void render(CJSection& section, int time) override;
};
class YInvertEffect : public effect//y翻转效果
{
public:
    YInvertEffect();
    void render(CJSection& section, int time) override;
};
class xy_size_effect : public effect
{
public:
    xy_size_effect();
    void render(CJSection& section, int time) override;
};
class gradually_render_effect : public effect
{
public:
    gradually_render_effect();
    void render(CJSection& section, int time) override;
private:
    int starpoint;
    int indexstar;
};

#endif // EFFECT_H
