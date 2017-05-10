#ifndef _SQUARE_
#define _SQUARE_
#include "GameObject.hpp"

class Square : public GameObject
{
    private:
       std::vector<GameObject> squares;
       ColorSwitch squareColors;
       bool drawn=false;
       int dy=0;
    public:
            Square();
            void reset();
            void setDy(int num);
            int getDy();
            void reset2();
            Square& operator=(Square other);
            std::vector<GameObject> getSquares();
            ColorSwitch getColors();
            void addToObjects();
            void setColors();
            void setSquareColors(ColorSwitch);
            void drawSquares(HDC);
            void changeColor();
            bool getDrawn();

};

void Square::setDy(int num)
{
    dy=num;
}

int Square::getDy()
{
    return dy;
}

std::vector<GameObject> Square::getSquares()
{
    return squares;
}

ColorSwitch Square::getColors()
{
    return squareColors;
}

Square& Square::operator=(Square other)
{
    for(int i=0;i<squares.size();++i)
    {
        squares.at(i).setColor(other.getSquares().at(i).getColor());
        squares.at(i).setX(other.getSquares().at(i).getX());
        squares.at(i).setY(other.getSquares().at(i).getY());
    }
    drawn=other.getDrawn();
    squareColors=other.getColors();
    return *this;
}

bool Square::getDrawn()
{
    return drawn;
}

void Square::addToObjects()
{
    for(int i=0; i<squares.size(); ++i)
            squares.at(i).addToY(dy);
}


void Square::setSquareColors(ColorSwitch colors)
{
    squareColors=colors;
}

void Square::reset2()
{
    std::vector<GameObject> a;
    squares=a;
    GameObject a1 = (*new GameObject());
    a1.setXY(240,-120);
    GameObject a2 = (*new GameObject());
    a2.setXY(260,-120);
    GameObject a3 = (*new GameObject());
    a3.setXY(280,-120);
    GameObject a4 = (*new GameObject());
    a4.setXY(300,-120);
    GameObject a5 = (*new GameObject());
    a5.setXY(320,-120);
    GameObject a6 = (*new GameObject());
    a6.setXY(340,-120);
    GameObject a7 = (*new GameObject());
    a7.setXY(360,-120);

    GameObject b1 = (*new GameObject());
    b1.setXY(360,-100);
    GameObject b2 = (*new GameObject());
    b2.setXY(360,-80);
    GameObject b3 = (*new GameObject());
    b3.setXY(360,-60);
    GameObject b4 = (*new GameObject());
    b4.setXY(360,-40);
    GameObject b5 = (*new GameObject());
    b5.setXY(360,-20);
    GameObject b6 = (*new GameObject());
    b6.setXY(360, 0);

    GameObject c1 = (*new GameObject());
    c1.setXY(340, 0);
    GameObject c2 = (*new GameObject());
    c2.setXY(320, 0);
    GameObject c3 = (*new GameObject());
    c3.setXY(300, 0);
    GameObject c4 = (*new GameObject());
    c4.setXY(280, 0);
    GameObject c5 = (*new GameObject());
    c5.setXY(260, 0);
    GameObject c6 = (*new GameObject());
    c6.setXY(240, 0);


    GameObject d1 = (*new GameObject());
    d1.setXY(240,-20);
    GameObject d2 = (*new GameObject());
    d2.setXY(240,-40);
    GameObject d3 = (*new GameObject());
    d3.setXY(240,-60);
    GameObject d4 = (*new GameObject());
    d4.setXY(240,-80);
    GameObject d5 = (*new GameObject());
    d5.setXY(240,-100);
    GameObject d6 = (*new GameObject());
    d6.setXY(240,-120);

    squares.push_back(a1);
    squares.push_back(a2);
    squares.push_back(a3);
    squares.push_back(a4);
    squares.push_back(a5);
    squares.push_back(a6);
    squares.push_back(a7);

    squares.push_back(b1);
    squares.push_back(b2);
    squares.push_back(b3);
    squares.push_back(b4);
    squares.push_back(b5);
    squares.push_back(b6);

    squares.push_back(c1);
    squares.push_back(c2);
    squares.push_back(c3);
    squares.push_back(c4);
    squares.push_back(c5);
    squares.push_back(c6);

    squares.push_back(d1);
    squares.push_back(d2);
    squares.push_back(d3);
    squares.push_back(d4);
    squares.push_back(d5);
    squares.push_back(d6);
}

void Square::reset()
{
    std::vector<GameObject> a;
    squares=a;
    GameObject a1 = (*new GameObject());
    a1.setXY(240,-140);
    GameObject a2 = (*new GameObject());
    a2.setXY(260,-140);
    GameObject a3 = (*new GameObject());
    a3.setXY(280,-140);
    GameObject a4 = (*new GameObject());
    a4.setXY(300,-140);
    GameObject a5 = (*new GameObject());
    a5.setXY(320,-140);
    GameObject a6 = (*new GameObject());
    a6.setXY(340,-140);
    GameObject a7 = (*new GameObject());
    a7.setXY(360,-140);

    GameObject b1 = (*new GameObject());
    b1.setXY(360,-120);
    GameObject b2 = (*new GameObject());
    b2.setXY(360,-100);
    GameObject b3 = (*new GameObject());
    b3.setXY(360,-80);
    GameObject b4 = (*new GameObject());
    b4.setXY(360,-60);
    GameObject b5 = (*new GameObject());
    b5.setXY(360,-40);
    GameObject b6 = (*new GameObject());
    b6.setXY(360,-20);

    GameObject c1 = (*new GameObject());
    c1.setXY(340,-20);
    GameObject c2 = (*new GameObject());
    c2.setXY(320,-20);
    GameObject c3 = (*new GameObject());
    c3.setXY(300,-20);
    GameObject c4 = (*new GameObject());
    c4.setXY(280,-20);
    GameObject c5 = (*new GameObject());
    c5.setXY(260,-20);
    GameObject c6 = (*new GameObject());
    c6.setXY(240,-20);


    GameObject d1 = (*new GameObject());
    d1.setXY(240,-40);
    GameObject d2 = (*new GameObject());
    d2.setXY(240,-60);
    GameObject d3 = (*new GameObject());
    d3.setXY(240,-80);
    GameObject d4 = (*new GameObject());
    d4.setXY(240,-100);
    GameObject d5 = (*new GameObject());
    d5.setXY(240,-120);
    GameObject d6 = (*new GameObject());
    d6.setXY(240,-140);

    squares.push_back(a1);
    squares.push_back(a2);
    squares.push_back(a3);
    squares.push_back(a4);
    squares.push_back(a5);
    squares.push_back(a6);
    squares.push_back(a7);

    squares.push_back(b1);
    squares.push_back(b2);
    squares.push_back(b3);
    squares.push_back(b4);
    squares.push_back(b5);
    squares.push_back(b6);

    squares.push_back(c1);
    squares.push_back(c2);
    squares.push_back(c3);
    squares.push_back(c4);
    squares.push_back(c5);
    squares.push_back(c6);

    squares.push_back(d1);
    squares.push_back(d2);
    squares.push_back(d3);
    squares.push_back(d4);
    squares.push_back(d5);
    squares.push_back(d6);
}

Square::Square()
{
    GameObject a1 = (*new GameObject());
    a1.setXY(140,-60);
    GameObject a2 = (*new GameObject());
    a2.setXY(160,-60);
    GameObject a3 = (*new GameObject());
    a3.setXY(180,-60);
    GameObject a4 = (*new GameObject());
    a4.setXY(200,-60);
    GameObject a5 = (*new GameObject());
    a5.setXY(220,-60);
    GameObject a6 = (*new GameObject());
    a6.setXY(240,-60);
    GameObject a7 = (*new GameObject());
    a7.setXY(260,-60);

    GameObject b1 = (*new GameObject());
    b1.setXY(260,-40);
    GameObject b2 = (*new GameObject());
    b2.setXY(260,-20);
    GameObject b3 = (*new GameObject());
    b3.setXY(260,0);
    GameObject b4 = (*new GameObject());
    b4.setXY(260,20);
    GameObject b5 = (*new GameObject());
    b5.setXY(260,40);
    GameObject b6 = (*new GameObject());
    b6.setXY(260,60);

    GameObject c1 = (*new GameObject());
    c1.setXY(240,60);
    GameObject c2 = (*new GameObject());
    c2.setXY(220,60);
    GameObject c3 = (*new GameObject());
    c3.setXY(200,60);
    GameObject c4 = (*new GameObject());
    c4.setXY(180,60);
    GameObject c5 = (*new GameObject());
    c5.setXY(160,60);
    GameObject c6 = (*new GameObject());
    c6.setXY(140,60);


    GameObject d1 = (*new GameObject());
    d1.setXY(140,40);
    GameObject d2 = (*new GameObject());
    d2.setXY(140,20);
    GameObject d3 = (*new GameObject());
    d3.setXY(140,0);
    GameObject d4 = (*new GameObject());
    d4.setXY(140,-20);
    GameObject d5 = (*new GameObject());
    d5.setXY(140,-40);
    GameObject d6 = (*new GameObject());
    d6.setXY(140,-60);

    squares.push_back(a1);
    squares.push_back(a2);
    squares.push_back(a3);
    squares.push_back(a4);
    squares.push_back(a5);
    squares.push_back(a6);
    squares.push_back(a7);

    squares.push_back(b1);
    squares.push_back(b2);
    squares.push_back(b3);
    squares.push_back(b4);
    squares.push_back(b5);
    squares.push_back(b6);

    squares.push_back(c1);
    squares.push_back(c2);
    squares.push_back(c3);
    squares.push_back(c4);
    squares.push_back(c5);
    squares.push_back(c6);

    squares.push_back(d1);
    squares.push_back(d2);
    squares.push_back(d3);
    squares.push_back(d4);
    squares.push_back(d5);
    squares.push_back(d6);
}

void Square::setColors()
{
    for(int i = 0; i<squares.size(); ++i)
    {
         if(i < 6)
            squares.at(i).setColor(squareColors.getColor1());
        if(i >= 6 && i<12)
            squares.at(i).setColor(squareColors.getColor2());
        if(i >= 12 && i<18)
            squares.at(i).setColor(squareColors.getColor3());
        if(i >= 18)
            squares.at(i).setColor(squareColors.getColor4());
    }
}



void Square::drawSquares(HDC hdc)
{
       if(!getDrawn())
   {
        setColors();
        drawn = true;
   }
    static HBRUSH hbrush;
    static HPEN hpen;
    for(int i = 0; i<squares.size(); ++i)
    {
        hbrush = CreateSolidBrush(squares.at(i).getColor());
        hpen = CreatePen(PS_SOLID, 1, squares.at(i).getColor());
        SelectObject(hdc, hpen);
        SelectObject(hdc, hbrush);
        Ellipse(hdc, squares.at(i).getX()-6, squares.at(i).getY()-6, squares.at(i).getX()+6, squares.at(i).getY()+6);
        DeleteObject(hpen);
        DeleteObject(hbrush);
    }
}


void Square::changeColor()
{
    squares.at(squares.size()-1).setColor(squares.at(0).getColor());
    for(int i = 0; i<squares.size()-1; ++i)
            squares.at(i).setColor(squares.at(i+1).getColor());
}
#endif

