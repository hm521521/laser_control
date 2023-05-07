#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
    Color()
        : R(0), G(0), B(0)
    {}

    Color(unsigned char r, unsigned char g, unsigned char b)
        : R(r), G(g), B(b)
    {}

    unsigned char R;
    unsigned char G;
    unsigned char B;
};

#endif // COLOR_H
