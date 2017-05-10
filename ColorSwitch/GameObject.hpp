#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

class GameObject
{
    private:
            int x, y;
            COLORREF color;
    public:
            void setX(int);
            void setY(int);
            void addToY(int);
            void setColor(COLORREF);
            void setXY(int, int);
            int getY();
            int getX();
            COLORREF getColor();
};

void GameObject::setX(int X)
{
    x = X;
}


void GameObject::setColor(COLORREF col)
{
    color = col;
}

void GameObject::setY(int Y)
{
    y = Y;
}

void GameObject::addToY(int number)
{
    y+=number;
}

void GameObject::setXY(int X, int Y)
{
    x = X;
    y = Y;
}

int GameObject::getX()
{
    return x;
}


COLORREF GameObject::getColor()
{
    return color;
}

int GameObject::getY()
{
    return y;
}
#endif

