#ifndef _COLORSWITCH_
#define _COLORSWITCH_

class ColorSwitch
{
    private:
            COLORREF color1, color2, color3, color4;
    public:
            void setColor1(COLORREF);
            void setColor2(COLORREF);
            void setColor3(COLORREF);
            void setColor4(COLORREF);
            COLORREF getColor1();
            COLORREF getColor2();
            COLORREF getColor3();
            COLORREF getColor4();

};

void ColorSwitch::setColor1(COLORREF color)
{
    color1 = color;
}

void ColorSwitch::setColor2(COLORREF color)
{
    color2 = color;
}

void ColorSwitch::setColor3(COLORREF color)
{
    color3 = color;
}

void ColorSwitch::setColor4(COLORREF color)
{
    color4 = color;
}

COLORREF ColorSwitch::getColor1()
{
    return color1;
}

COLORREF ColorSwitch::getColor2()
{
    return color2;
}

COLORREF ColorSwitch::getColor3()
{
    return color3;
}

COLORREF ColorSwitch::getColor4()
{
    return color4;
}

#endif

