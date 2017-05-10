#ifndef _GAMEBALL_
#define _GAMEBALL_

class GameBall
{
    private:
            int x = 300;
            int y;
            COLORREF color;
    public:
            GameBall();
            void addToPosition(int num);
            void setPosition(int);
            void setColor(COLORREF);
            int getPosition();
            int getPositionx();
            COLORREF getColor();
            void checkInput();
            void drawBall(HDC);
            void update();
};

void GameBall::addToPosition(int num)
{
    y+=num;
}

GameBall::GameBall()
{
    y = 265;
    color = RGB(0,255,200);
}

void GameBall::setPosition(int Y)
{
    y = Y;
}

void GameBall::setColor(COLORREF Color)
{
    color = Color;
}

int GameBall::getPosition()
{
    return y;
}


int GameBall::getPositionx()
{
    return x;
}

COLORREF GameBall::getColor()
{
    return color;
}


void GameBall::drawBall(HDC hdc)
{
    HBRUSH hbrush = CreateSolidBrush(color);
    HPEN hpen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hdc, hpen);
    SelectObject(hdc, hbrush);
    Ellipse(hdc, x-7, y-7, x+7, y+7);
}

void GameBall::update()
{
}

#endif

