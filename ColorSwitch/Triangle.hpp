#ifndef _TRIANGLE_
#define _TRIANGLE_
#include "GameObject.hpp"
#include "ColorSwitch.hpp"

class Triangle : public GameObject
{
    private:
            std::vector<GameObject> triangles;
            ColorSwitch triangleColors;
            bool drawn = false;
            int dy=0;
    public:
            Triangle();
            void reset();
            void reset2();
            void setDy(int num);
            int getDy();
            Triangle& operator=(Triangle other);
            std::vector<GameObject> getTriangles();
            ColorSwitch getColors();
            void addToObjects();
            void changeColor();
            void setColors();
            void setTriangleColors(ColorSwitch);
            void drawTriangles(HDC);
            bool getDrawn();

};


void Triangle::setDy(int num)
{
    dy=num;
}

int Triangle::getDy()
{
    return dy;
}
std::vector<GameObject> Triangle::getTriangles()
{
    return triangles;
}

ColorSwitch Triangle::getColors()
{
    return triangleColors;
}

void Triangle::reset2()
{
    for(int i = 0; i<triangles.size(); ++i)
    {
            triangles.at(i).setY(-1000);
    }
}
Triangle& Triangle::operator=(Triangle other)
{
    for(int i=0;i<triangles.size();++i)
    {
        triangles.at(i).setColor(other.getTriangles().at(i).getColor());
        triangles.at(i).setX(other.getTriangles().at(i).getX());
        triangles.at(i).setY(other.getTriangles().at(i).getY());
    }
    drawn=other.getDrawn();
    triangleColors=other.getColors();
    return *this;
}

void Triangle::addToObjects()
{
    for(int i=0; i<triangles.size(); ++i)
            triangles.at(i).addToY(dy);
}

void Triangle::setTriangleColors(ColorSwitch colors)
{
    triangleColors = colors;
}

bool Triangle::getDrawn()
{
    return drawn;
}


void Triangle::reset()
{
    std::vector<GameObject> triangles1;
    triangles=triangles1;

    GameObject a1 = (*new GameObject());
    a1.setXY(300, -140);

    GameObject b1 = (*new GameObject());
    b1.setXY(310, -125);
    GameObject b2 = (*new GameObject());
    b2.setXY(320, -110);
    GameObject b3 = (*new GameObject());
    b3.setXY(330, -95);
    GameObject b4 = (*new GameObject());
    b4.setXY(340, -80);
    GameObject b5 = (*new GameObject());
    b5.setXY(350, -65);
    GameObject b6 = (*new GameObject());
    b6.setXY(360, -50);
    GameObject b7 = (*new GameObject());
    b7.setXY(370, -35);

    GameObject c1 = (*new GameObject());
    c1.setXY(380, -20);
    GameObject c2 = (*new GameObject());
    c2.setXY(360, -20);
    GameObject c3 = (*new GameObject());
    c3.setXY(340, -20);
    GameObject c4 = (*new GameObject());
    c4.setXY(320, -20);
    GameObject c5 = (*new GameObject());
    c5.setXY(300, -20);
    GameObject c6 = (*new GameObject());
    c6.setXY(280, -20);
    GameObject c7 = (*new GameObject());
    c7.setXY(260, -20);
    GameObject c8 = (*new GameObject());
    c8.setXY(240, -20);
    GameObject c9 = (*new GameObject());
    c9.setXY(220, -20);

    GameObject d1 = (*new GameObject());
    d1.setXY(230, -35);
    GameObject d2 = (*new GameObject());
    d2.setXY(240, -50);
    GameObject d3 = (*new GameObject());
    d3.setXY(250, -65);
    GameObject d4 = (*new GameObject());
    d4.setXY(260, -80);
    GameObject d5 = (*new GameObject());
    d5.setXY(270, -95);
    GameObject d6 = (*new GameObject());
    d6.setXY(280, -110);
    GameObject d7 = (*new GameObject());
    d7.setXY(290, -125);

    triangles.push_back(a1);

    triangles.push_back(b1);
    triangles.push_back(b2);
    triangles.push_back(b3);
    triangles.push_back(b4);
    triangles.push_back(b5);
    triangles.push_back(b6);
    triangles.push_back(b7);

    triangles.push_back(c1);
    triangles.push_back(c2);
    triangles.push_back(c3);
    triangles.push_back(c4);
    triangles.push_back(c5);
    triangles.push_back(c6);
    triangles.push_back(c7);
    triangles.push_back(c8);
    triangles.push_back(c9);


    triangles.push_back(d1);
    triangles.push_back(d2);
    triangles.push_back(d3);
    triangles.push_back(d4);
    triangles.push_back(d5);
    triangles.push_back(d6);
    triangles.push_back(d7);

}

Triangle::Triangle()
{
     GameObject a1 = (*new GameObject());
    a1.setXY(300, -140);

    GameObject b1 = (*new GameObject());
    b1.setXY(310, -125);
    GameObject b2 = (*new GameObject());
    b2.setXY(320, -110);
    GameObject b3 = (*new GameObject());
    b3.setXY(330, -95);
    GameObject b4 = (*new GameObject());
    b4.setXY(340, -80);
    GameObject b5 = (*new GameObject());
    b5.setXY(350, -65);
    GameObject b6 = (*new GameObject());
    b6.setXY(360, -50);
    GameObject b7 = (*new GameObject());
    b7.setXY(370, -35);

    GameObject c1 = (*new GameObject());
    c1.setXY(380, -20);
    GameObject c2 = (*new GameObject());
    c2.setXY(360, -20);
    GameObject c3 = (*new GameObject());
    c3.setXY(340, -20);
    GameObject c4 = (*new GameObject());
    c4.setXY(320, -20);
    GameObject c5 = (*new GameObject());
    c5.setXY(300, -20);
    GameObject c6 = (*new GameObject());
    c6.setXY(280, -20);
    GameObject c7 = (*new GameObject());
    c7.setXY(260, -20);
    GameObject c8 = (*new GameObject());
    c8.setXY(240, -20);
    GameObject c9 = (*new GameObject());
    c9.setXY(220, -20);

    GameObject d1 = (*new GameObject());
    d1.setXY(230, -35);
    GameObject d2 = (*new GameObject());
    d2.setXY(240, -50);
    GameObject d3 = (*new GameObject());
    d3.setXY(250, -65);
    GameObject d4 = (*new GameObject());
    d4.setXY(260, -80);
    GameObject d5 = (*new GameObject());
    d5.setXY(270, -95);
    GameObject d6 = (*new GameObject());
    d6.setXY(280, -110);
    GameObject d7 = (*new GameObject());
    d7.setXY(290, -125);

    triangles.push_back(a1);

    triangles.push_back(b1);
    triangles.push_back(b2);
    triangles.push_back(b3);
    triangles.push_back(b4);
    triangles.push_back(b5);
    triangles.push_back(b6);
    triangles.push_back(b7);

    triangles.push_back(c1);
    triangles.push_back(c2);
    triangles.push_back(c3);
    triangles.push_back(c4);
    triangles.push_back(c5);
    triangles.push_back(c6);
    triangles.push_back(c7);
    triangles.push_back(c8);
    triangles.push_back(c9);


    triangles.push_back(d1);
    triangles.push_back(d2);
    triangles.push_back(d3);
    triangles.push_back(d4);
    triangles.push_back(d5);
    triangles.push_back(d6);
    triangles.push_back(d7);
}

void Triangle::setColors()
{
    for(int i = 0; i<triangles.size(); ++i)
    {
        if(i < 6)
            triangles.at(i).setColor(triangleColors.getColor1());
        if(i >= 6 && i<12)
            triangles.at(i).setColor(triangleColors.getColor2());
        if(i >= 12 && i<18)
            triangles.at(i).setColor(triangleColors.getColor3());
        if(i >= 18)
            triangles.at(i).setColor(triangleColors.getColor4());
    }
}
void Triangle::drawTriangles(HDC hdc)
{
    static HBRUSH hbrush;
    static HPEN hpen;

       if(!getDrawn())
   {
        setColors();
        drawn = true;
   }

    for(int i = 0; i<triangles.size(); ++i)
    {

        hbrush = CreateSolidBrush(triangles.at(i).getColor());
        hpen = CreatePen(PS_SOLID, 1, triangles.at(i).getColor());
        SelectObject(hdc, hpen);
        SelectObject(hdc, hbrush);
        Ellipse(hdc, triangles.at(i).getX()-6, triangles.at(i).getY()-6, triangles.at(i).getX()+6, triangles.at(i).getY()+6);
        DeleteObject(hpen);
        DeleteObject(hbrush);
    }
}

void Triangle::changeColor()
{
    triangles.at(triangles.size()-1).setColor(triangles.at(0).getColor());
    for(int i = 0; i<triangles.size()-1; ++i)
            triangles.at(i).setColor(triangles.at(i+1).getColor());
}
#endif

