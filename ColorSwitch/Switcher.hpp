#ifndef _SWITCHER_
#define _SWITCHER_
#include "ColorSwitch.hpp"
class Switcher
{
    private:
        ColorSwitch colors;
        int y1, y2, y3;
        int dy=0;
        bool drawn = true;
    public:
            Switcher();
            Switcher(ColorSwitch);
            void drawSwitcher(HDC);
            void update();
            void restart2();
            void restart1();
            void setColor(ColorSwitch);
            void restart();
            bool draw();
            int getY1();
            int getY2();
            int getY3();
            int getDy();
            void setDy(int num);
};

void Switcher::setDy(int num)
{
    dy=num;
}

int Switcher::getDy()
{
    return dy;
}

int Switcher::getY1()
{
    return y1;
}
void Switcher::setColor(ColorSwitch Colors)
{
    colors=Colors;
}
int Switcher::getY2()
{
    return y2;
}
int Switcher::getY3()
{
    return y3;
}

bool Switcher::draw()
{
    return drawn;
}

Switcher::Switcher()
{
}

Switcher::Switcher(ColorSwitch c)
{
    y1 = -150;
    y2 = -135;
    y3 = -120;
    colors = c;
}

void Switcher::restart2()
{
    y1 = -150;
    y2 = -135;
    y3 = -120;
}

void Switcher::restart()
{
    y1 = -190;
    y2 = -205;
    y3 = -220;

}

void Switcher::restart1()
{
    y1 = -400;
    y2 = -400;
    y3 = -400;

}
void Switcher::drawSwitcher(HDC hdc)
{
    HBRUSH color1 = CreateSolidBrush(colors.getColor1());
    HBRUSH color2 = CreateSolidBrush(colors.getColor2());
    HBRUSH color3 = CreateSolidBrush(colors.getColor3());
    HBRUSH color4 = CreateSolidBrush(colors.getColor4());

    HPEN pen1 = CreatePen(PS_SOLID, 1, colors.getColor1());
    HPEN pen2 = CreatePen(PS_SOLID, 1, colors.getColor2());
    HPEN pen3 = CreatePen(PS_SOLID, 1, colors.getColor3());
    HPEN pen4 = CreatePen(PS_SOLID, 1, colors.getColor4());

    SelectObject(hdc, color1);
    SelectObject(hdc, pen1);
    Rectangle(hdc, 285, y1, 300, y2);
    SelectObject(hdc, color2);
    SelectObject(hdc, pen2);
    Rectangle(hdc,300, y1, 315, y2);
    SelectObject(hdc, color3);
    SelectObject(hdc, pen3);
    Rectangle(hdc, 285, y2, 300, y3);
    SelectObject(hdc, color4);
    SelectObject(hdc, pen4);
    Rectangle(hdc, 300, y2, 315, y3);

    DeleteObject(color1);
    DeleteObject(color2);
    DeleteObject(color3);
    DeleteObject(color4);
    DeleteObject(pen1);
    DeleteObject(pen2);
    DeleteObject(pen3);
    DeleteObject(pen4);

}

void Switcher::update()
{
    y1 += dy;
    y2 += dy;
    y3 += dy;
}

#endif

