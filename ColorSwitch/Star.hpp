#ifndef _STAR_
#define _STAR_

class Star
{
    private:

            COLORREF color;
            int y1, y2, y3, y4;
            int dy=0;
    public :
        Star();
        int getDy();
        void setDy(int num);
        Star(COLORREF);
        void reset3();
        void reset2();
        void draw(HDC);
        int getY1();
        void update();
        void reset();
        void reset1();

};

Star::Star()
{

}


void Star::setDy(int num)
{
    dy=num;
}

int Star::getDy()
{
    return dy;
}

Star::Star(COLORREF color1)
{
    color = color1;
    y1 = 5;
    y2 = -10;
    y3 = -10;
    y4 = -25;
}

void Star::reset2()
{
    y1 = 5;
    y2 = -10;
    y3 = -10;
    y4 = -25;

}

void Star::draw(HDC hdc)
{
    HBRUSH hb = CreateSolidBrush(color);
    HPEN hp = CreatePen(PS_SOLID, 1, color);
    PAINTSTRUCT Ps;
    RECT rect;

    POINT Pt[] =
                { {290, y2},
                  {300, y1},
                  {310, y2},

                  {290, y3},
                  {300, y4},
                  {310, y3}
                };

    int lpPts[] = { 3, 3};
    SelectObject(hdc, hb);
    SelectObject(hdc, hp);
    PolyPolygon(hdc, Pt, lpPts, 2);
    DeleteObject(hb);
    DeleteObject(hp);
}

void Star::update()
{
    y1 += dy;
    y2 += dy;
    y3 += dy;
    y4 += dy;
}

void Star::reset()
{
    y1 = -65;
    y2 = -80;
    y3 = -80;
    y4 = -95;
}

void Star::reset3()
{
    y1 = -55;
    y2 = -70;
    y3 = -70;
    y4 = -85;
}

void Star::reset1()
{
    y1 = y2 = y3 = y4 = -500;
}

int Star::getY1()
{
    return y1;
}

#endif // _POINTS_
