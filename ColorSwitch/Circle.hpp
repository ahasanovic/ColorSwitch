#ifndef _CIRCLE_
#define _CIRCLE_
#include "GameObject.hpp"
#include "ColorSwitch.hpp"

class Circle : public GameObject
{
    private:
            std::vector<GameObject> circles;
            ColorSwitch circleColors;
            bool drawn = false;
            int dy=0;
    public:
            Circle();
            void reset();
            void reset2();
            void reset3();
            void setDy(int num);
            int getDy();
            Circle& operator=(Circle other);
            std::vector<GameObject> getCircles();
            ColorSwitch getColors();
            void addToObjects();
            void changeColor();
            void setColors();
            void drawCircles(HDC);
            void setCircleColors(ColorSwitch);
            bool getDrawn();
};


std::vector<GameObject> Circle::getCircles()
{
    return circles;
}

void Circle::setDy(int num){
    dy=num;
}

int Circle::getDy()
{
    return dy;
}

ColorSwitch Circle::getColors()
{
    return circleColors;
}

void Circle::reset3()
{
    for(int i=0; i<circles.size(); i++)
        circles.at(i).setY(-1000);
}
Circle& Circle::operator=(Circle other)
{
    for(int i=0;i<circles.size();++i)
    {
        circles.at(i).setColor(other.getCircles().at(i).getColor());
        circles.at(i).setX(other.getCircles().at(i).getX());
        circles.at(i).setY(other.getCircles().at(i).getY());
    }
    drawn=other.getDrawn();
    circleColors=other.getColors();
    return *this;
}

void Circle::addToObjects()
{
    for(int i=0; i<circles.size(); ++i)
            circles.at(i).addToY(dy);
}

bool Circle::getDrawn()
{
    return drawn;
}


void Circle::setColors()
{
    for(int i = 0; i<circles.size(); ++i)
    {
        if(i < 5)
            circles.at(i).setColor(circleColors.getColor1());
        if(i >= 5 && i<10)
            circles.at(i).setColor(circleColors.getColor2());
        if(i >= 10 && i<15)
            circles.at(i).setColor(circleColors.getColor3());
        if(i >= 15)
            circles.at(i).setColor(circleColors.getColor4());
    }
}

void Circle::setCircleColors(ColorSwitch colors)
{
    circleColors = colors;
}


void Circle::reset()
{
        std::vector<GameObject> circles1;
        circles = circles1;
        GameObject a1 = (*new GameObject());
        a1.setXY(290, -140);
        GameObject a2 = (*new GameObject());
        a2.setXY(310, -140);
        GameObject a3 = (*new GameObject());
        a3.setXY(330, -133);
        GameObject a4 = (*new GameObject());
        a4.setXY(344, -120);
        GameObject a5 = (*new GameObject());
        a5.setXY(354, -105);

        GameObject b1 = (*new GameObject());
        b1.setXY(360, -90);
        GameObject b2 = (*new GameObject());
        b2.setXY(360, -70);
        GameObject b3 = (*new GameObject());
        b3.setXY(354, -55);
        GameObject b4 = (*new GameObject());
        b4.setXY(344, -40);
        GameObject b5 = (*new GameObject());
        b5.setXY(330, -27);


        GameObject c1 = (*new GameObject());
        c1.setXY(310, -20);
        GameObject c2 = (*new GameObject());
        c2.setXY(290, -20);
        GameObject c3 = (*new GameObject());
        c3.setXY(270, -27);
        GameObject c4 = (*new GameObject());
        c4.setXY(256, -40);
        GameObject c5 = (*new GameObject());
        c5.setXY(246, -55);


        GameObject d1 = (*new GameObject());
        d1.setXY(240, -70);
        GameObject d2 = (*new GameObject());
        d2.setXY(240, -90);
        GameObject d3 = (*new GameObject());
        d3.setXY(246, -105);
        GameObject d4 = (*new GameObject());
        d4.setXY(256, -120);
        GameObject d5 = (*new GameObject());
        d5.setXY(270, -133);

        circles.push_back(a1);
        circles.push_back(a2);
        circles.push_back(a3);
        circles.push_back(a4);
        circles.push_back(a5);
        circles.push_back(b1);
        circles.push_back(b2);
        circles.push_back(b3);
        circles.push_back(b4);
        circles.push_back(b5);
        circles.push_back(c1);
        circles.push_back(c2);
        circles.push_back(c3);
        circles.push_back(c4);
        circles.push_back(c5);
        circles.push_back(d1);
        circles.push_back(d2);
        circles.push_back(d3);
        circles.push_back(d4);
        circles.push_back(d5);
}

void Circle::reset2()
{
        std::vector<GameObject> circles1;
        circles = circles1;
        GameObject a1 = (*new GameObject());
        a1.setXY(290, -70);
        GameObject a2 = (*new GameObject());
        a2.setXY(310, -70);
        GameObject a3 = (*new GameObject());
        a3.setXY(330, -63);
        GameObject a4 = (*new GameObject());
        a4.setXY(344, -50);
        GameObject a5 = (*new GameObject());
        a5.setXY(354, -35);

        GameObject b1 = (*new GameObject());
        b1.setXY(360, -20);
        GameObject b2 = (*new GameObject());
        b2.setXY(360, 0);
        GameObject b3 = (*new GameObject());
        b3.setXY(354, 15);
        GameObject b4 = (*new GameObject());
        b4.setXY(344, 30 );
        GameObject b5 = (*new GameObject());
        b5.setXY(330, 43);


        GameObject c1 = (*new GameObject());
        c1.setXY(310, 50);
        GameObject c2 = (*new GameObject());
        c2.setXY(290, 50);
        GameObject c3 = (*new GameObject());
        c3.setXY(270, 43);
        GameObject c4 = (*new GameObject());
        c4.setXY(256, 30);
        GameObject c5 = (*new GameObject());
        c5.setXY(246, 15);




        GameObject d1 = (*new GameObject());
        d1.setXY(240, 0);
        GameObject d2 = (*new GameObject());
        d2.setXY(240, -20);
        GameObject d3 = (*new GameObject());
        d3.setXY(246, -35);
        GameObject d4 = (*new GameObject());
        d4.setXY(256, -50);
        GameObject d5 = (*new GameObject());
        d5.setXY(270, -63);

        circles.push_back(a1);
        circles.push_back(a2);
        circles.push_back(a3);
        circles.push_back(a4);
        circles.push_back(a5);
        circles.push_back(b1);
        circles.push_back(b2);
        circles.push_back(b3);
        circles.push_back(b4);
        circles.push_back(b5);
        circles.push_back(c1);
        circles.push_back(c2);
        circles.push_back(c3);
        circles.push_back(c4);
        circles.push_back(c5);

        circles.push_back(d1);
        circles.push_back(d2);
        circles.push_back(d3);
        circles.push_back(d4);
        circles.push_back(d5);
}
Circle::Circle()
{
        GameObject a1 = (*new GameObject());
        a1.setXY(290, -70);
        GameObject a2 = (*new GameObject());
        a2.setXY(310, -70);
        GameObject a3 = (*new GameObject());
        a3.setXY(330, -63);
        GameObject a4 = (*new GameObject());
        a4.setXY(344, -50);
        GameObject a5 = (*new GameObject());
        a5.setXY(354, -35);

        GameObject b1 = (*new GameObject());
        b1.setXY(360, -20);
        GameObject b2 = (*new GameObject());
        b2.setXY(360, 0);
        GameObject b3 = (*new GameObject());
        b3.setXY(354, 15);
        GameObject b4 = (*new GameObject());
        b4.setXY(344, 30 );
        GameObject b5 = (*new GameObject());
        b5.setXY(330, 43);


        GameObject c1 = (*new GameObject());
        c1.setXY(310, 50);
        GameObject c2 = (*new GameObject());
        c2.setXY(290, 50);
        GameObject c3 = (*new GameObject());
        c3.setXY(270, 43);
        GameObject c4 = (*new GameObject());
        c4.setXY(256, 30);
        GameObject c5 = (*new GameObject());
        c5.setXY(246, 15);




        GameObject d1 = (*new GameObject());
        d1.setXY(240, 0);
        GameObject d2 = (*new GameObject());
        d2.setXY(240, -20);
        GameObject d3 = (*new GameObject());
        d3.setXY(246, -35);
        GameObject d4 = (*new GameObject());
        d4.setXY(256, -50);
        GameObject d5 = (*new GameObject());
        d5.setXY(270, -63);

        circles.push_back(a1);
        circles.push_back(a2);
        circles.push_back(a3);
        circles.push_back(a4);
        circles.push_back(a5);
        circles.push_back(b1);
        circles.push_back(b2);
        circles.push_back(b3);
        circles.push_back(b4);
        circles.push_back(b5);
        circles.push_back(c1);
        circles.push_back(c2);
        circles.push_back(c3);
        circles.push_back(c4);
        circles.push_back(c5);

        circles.push_back(d1);
        circles.push_back(d2);
        circles.push_back(d3);
        circles.push_back(d4);
        circles.push_back(d5);
}

void Circle::drawCircles(HDC hdc)
{

    static HBRUSH hbrush;
    static HPEN hpen;

       if(!getDrawn())
   {
        setColors();
        drawn = true;
   }

    for(int i = 0; i<circles.size(); ++i)
    {
        hbrush = CreateSolidBrush(circles.at(i).getColor());
        hpen = CreatePen(PS_SOLID, 1, circles.at(i).getColor());
        SelectObject(hdc, hpen);
        SelectObject(hdc, hbrush);

        Ellipse(hdc, circles.at(i).getX()-6, circles.at(i).getY()-6, circles.at(i).getX()+6, circles.at(i).getY()+6);
        DeleteObject(hpen);
        DeleteObject(hbrush);
    }
}

void Circle::changeColor()
{
    circles.at(circles.size()-1).setColor(circles.at(0).getColor());
    for(int i = 0; i<circles.size()-1; ++i)
            circles.at(i).setColor(circles.at(i+1).getColor());
}

#endif
