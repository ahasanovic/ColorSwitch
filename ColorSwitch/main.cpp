#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#define DRAW 103

#define PRESSED(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#include <tchar.h>
#include <vector>
#include<stdio.h>
#include <windows.h>
#include <math.h>
#include "GameBall.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Square.hpp"
#include "ColorSwitch.hpp"
#include "Switcher.hpp"
#include "Star.hpp"
#include "resource.h"
#include <string>
#include "sqlite3.h"

static boolean start=true;
static boolean _isRunning=true;
static DWORD _frameDelay=90;

static int b=1;
static HWND hdil2;

static HWND hwnd;
static bool poslato=false;
static HWND hwndSecondWindow;
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowProcedureSecondWindow (HWND, UINT, WPARAM, LPARAM);

HINSTANCE HIDD2;
static int i=3;
static TCHAR* name="";

static COLORREF color1=RGB(167,0,201);
static COLORREF color2=RGB(255,3,96);
static COLORREF color3=RGB(3,248,255);
static COLORREF color4=RGB(255,255,25);

static bool isLevel1=true;
static bool isLevel2=false;
static bool isLevel3=false;

static bool finish = false;
static bool game_over = false;
static bool circleisDrawn = false;
static bool triangleisDrawn = false;
static bool squareisDrawn = false;

static int numOfPoints=0;
static int level=1;

static bool done = false;

const int ID_TIMER = 10;
typedef struct ObjectInfo
{
    int width;
    int height;
    int x;
    int y;
    int dx;
    int dy;
} Object;

Object hand;
Object bck;
Object colorswitch;
Object finished;
Object gameOver;
HBITMAP background;
HBITMAP hbmHandWhite;
HBITMAP hbmHandBlack;
HBITMAP hbmColorSwitch;
HBITMAP hbmColorSwitchBlack;
HBITMAP hbmFinishedWhite;
HBITMAP hbmFinishedBlack;
HBITMAP hbmGameOverWhite;
HBITMAP hbmGameOverBlack;

static GameBall ball;

static Circle circle;
static Circle circle1;
static Square square;
static Triangle triangle;
static ColorSwitch colors;
static Switcher switcher;
static Switcher switcher1;
static Switcher switcher2;
static Star star;
static Star star1;
static Star star2;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgMain1(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* *********************************************************************************************** */
void checkCircle()
{
     if(circle.getCircles().at(11).getY()>0 ||circle.getCircles().at(12).getY()>0)
        {
            if(((ball.getPosition()-circle.getCircles().at(11).getY())<4  &&
                (ball.getPosition()-circle.getCircles().at(11).getY())>-4) ||
               ((ball.getPosition()-circle.getCircles().at(12).getY())<4  &&
               (ball.getPosition()-circle.getCircles().at(12).getY())>-4))
                {

                    if(ball.getColor() == circle.getCircles().at(11).getColor() || ball.getColor() == circle.getCircles().at(12).getColor())
                        return;
                    else
                    {
                        game_over = true;
                        return;
                    }
                }

        }

        if(circle.getCircles().at(0).getY()>0 ||circle.getCircles().at(1).getY()>0)
        {
            if(((ball.getPosition()-circle.getCircles().at(0).getY())<4  &&
                (ball.getPosition()-circle.getCircles().at(0).getY())>-4) ||
               ((ball.getPosition()-circle.getCircles().at(1).getY())<4  &&
               (ball.getPosition()-circle.getCircles().at(1).getY())>-4))
                {
                    printf("razlika 1 : %d razlika2:%d\n",(ball.getPosition()-circle.getCircles().at(0).getY()),(ball.getPosition()-circle.getCircles().at(1).getY()));

                    if(ball.getColor() == circle.getCircles().at(0).getColor() || ball.getColor() == circle.getCircles().at(1).getColor())
                        return;
                     else
                    {
                        game_over = true;
                        return;
                    }
                }
        }
}
/* *********************************************************************************************************************** */
/* *********************************************************************************************************************** */
void checkCircle1()
{
    if(circle1.getCircles().at(11).getY()>0 ||circle1.getCircles().at(12).getY()>0)
        {
            if(((ball.getPosition()-circle1.getCircles().at(11).getY())<4  &&
                (ball.getPosition()-circle1.getCircles().at(11).getY())>-4) ||
               ((ball.getPosition()-circle1.getCircles().at(12).getY())<4  &&
               (ball.getPosition()-circle1.getCircles().at(12).getY())>-4))
                {

                    if(ball.getColor() == circle1.getCircles().at(11).getColor() || ball.getColor() == circle1.getCircles().at(12).getColor())
                        return;
                    else
                    {
                        game_over = true;
                        return;
                    }
                }

        }

        if(circle1.getCircles().at(0).getY()>0 ||circle1.getCircles().at(1).getY()>0)
        {
            if(((ball.getPosition()-circle1.getCircles().at(0).getY())<4  &&
                (ball.getPosition()-circle1.getCircles().at(0).getY())>-4) ||
               ((ball.getPosition()-circle1.getCircles().at(1).getY())<4  &&
               (ball.getPosition()-circle1.getCircles().at(1).getY())>-4))
                {
                    printf("razlika 1 : %d razlika2:%d\n",(ball.getPosition()-circle1.getCircles().at(0).getY()),(ball.getPosition()-circle1.getCircles().at(1).getY()));

                    if(ball.getColor() == circle1.getCircles().at(0).getColor() || ball.getColor() == circle1.getCircles().at(1).getColor())
                        return;
                    else
                    {
                        game_over = true;
                        return;
                    }
                }
        }
}
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */
void  checkIfDoneTriangle()
{

         if(triangle.getTriangles().at(10).getY()>0 || triangle.getTriangles().at(11).getY()>0 || triangle.getTriangles().at(12).getY()>0 )
        {
            if(((ball.getPosition()-triangle.getTriangles().at(10).getY())<4  &&
                (ball.getPosition()-triangle.getTriangles().at(10).getY())>-4) ||
               ((ball.getPosition()-triangle.getTriangles().at(11).getY())<4  &&
               (ball.getPosition()-triangle.getTriangles().at(11).getY())>-4) ||
               ((ball.getPosition()-triangle.getTriangles().at(12).getY())<4  &&
               (ball.getPosition()-triangle.getTriangles().at(12).getY())>-4))
                {

                    if(ball.getColor() == triangle.getTriangles().at(10).getColor() || ball.getColor() == triangle.getTriangles().at(11).getColor() || ball.getColor() == triangle.getTriangles().at(12).getColor())
                        return;
                    else
                    {
                        game_over = true;
                        return;
                    }
                }
        }
         if(triangle.getTriangles().at(23).getY()>0 || triangle.getTriangles().at(0).getY()>0 || triangle.getTriangles().at(1).getY()>0 )
        {
            if(((ball.getPosition()-triangle.getTriangles().at(0).getY())<6  &&
                (ball.getPosition()-triangle.getTriangles().at(0).getY())>-6) ||
               ((ball.getPosition()-triangle.getTriangles().at(23).getY())<6  &&
               (ball.getPosition()-triangle.getTriangles().at(23).getY())>-6) ||
               ((ball.getPosition()-triangle.getTriangles().at(1).getY())<6  &&
               (ball.getPosition()-triangle.getTriangles().at(1).getY())>-6))
                {

                    if(ball.getColor() == triangle.getTriangles().at(23).getColor() || ball.getColor() == triangle.getTriangles().at(0).getColor() || ball.getColor() == triangle.getTriangles().at(1).getColor())
                        return;
                    else
                    {
                        game_over = true;
                        return;
                    }
                }
        }
 }
/* ************************************************************************************************************************* */
/* ************************************************************************************************************************* */
void checkIfDoneSquare()
{

         if(square.getSquares().at(15).getY()>0 || square.getSquares().at(16).getY()>0 || square.getSquares().at(14).getY()>0 )
        {
            if(((ball.getPosition()-square.getSquares().at(15).getY())<4  &&
                (ball.getPosition()-square.getSquares().at(15).getY())>-4) ||
               ((ball.getPosition()-square.getSquares().at(16).getY())<4  &&
               (ball.getPosition()-square.getSquares().at(16).getY())>-4) ||
               ((ball.getPosition()-square.getSquares().at(14).getY())<4  &&
               (ball.getPosition()-square.getSquares().at(14).getY())>-4))
                {

                    if(ball.getColor() == square.getSquares().at(15).getColor() || ball.getColor() == square.getSquares().at(16).getColor() ||ball.getColor() == square.getSquares().at(14).getColor())
                        return;
                    else
                    {
                        game_over = true;
                        return;
                    }
                }
        }


        if(square.getSquares().at(2).getY()>0 || square.getSquares().at(3).getY()>0 || square.getSquares().at(4).getY()>0 )
        {
            if(((ball.getPosition()-square.getSquares().at(2).getY())<4  &&
                (ball.getPosition()-square.getSquares().at(2).getY())>-4) ||
               ((ball.getPosition()-square.getSquares().at(3).getY())<4  &&
               (ball.getPosition()-square.getSquares().at(3).getY())>-4) ||
               ((ball.getPosition()-square.getSquares().at(4).getY())<4  &&
               (ball.getPosition()-square.getSquares().at(4).getY())>-4))
                {

                    if(ball.getColor() == square.getSquares().at(2).getColor() || ball.getColor() == square.getSquares().at(3).getColor() || ball.getColor() == square.getSquares().at(4).getColor())
                        return;
                  else
                    {
                        game_over = true;
                        return;
                    }
                }
        }
}
/* ************************************************************************************************************************* */
DWORD WINAPI checkIfDoneCircle()
{
    checkCircle();
    checkCircle1();
    return 0;
}

/* ************************************************************************************************************************* */

void checkInputLevel1()
{
    if(game_over || finish)
        return;
    if(hand.y <= 450)
    {
        hand.y += hand.dy;
        circle.addToObjects();
        star.update();
        switcher.update();
    }

    if(circle.getCircles().at(10).getY()>=200 || circle1.getCircles().at(10).getY()>=200)
    {
        circle1.addToObjects();
        circle.addToObjects();
        star.update();
        star1.update();
        switcher1.update();
        switcher.update();
    }
    if(circle.getCircles().at(10).getY() >= 500)
    {
        if(numOfPoints <= 4)
       {
           circle.reset();
       }
       if(numOfPoints < 3)
            switcher.restart();
        star.reset();
        circle.setColors();


    }
    if(circle1.getCircles().at(10).getY() >= 500)
    {
        if(numOfPoints <= 3)
         {
            circle1.reset();
            switcher1.restart();
         }
        star1.reset();
        circle1.setColors();
    }

   checkIfDoneCircle();
}
/* ************************************************************************************************************************* */
void checkInputLevel2()
{
    if(game_over || finish)
        return;
    if(hand.y < 450)
    {
        hand.y += hand.dy;
        circle.addToObjects();
        star.update();
        switcher.update();
    }
    if(circle.getCircles().at(10).getY()>200 || triangle.getTriangles().at(9).getY()>200)
    {
        circle.addToObjects();
        triangle.addToObjects();
        switcher.update();
        switcher1.update();
        star.update();
        star1.update();
    }
    if(circle.getCircles().at(10).getY() > 500)
    {
        if(numOfPoints < 14)
        {
            circle.reset();
            switcher.restart();
        }
        star.reset();
        circle.setColors();

    }
    if(triangle.getTriangles().at(9).getY() > 500)
    {
        if(numOfPoints <= 14)
            triangle.reset();
        if(numOfPoints < 13)
            switcher1.restart();
        star1.reset3();
        triangle.setColors();
    }
    checkIfDoneCircle();
    checkIfDoneTriangle();
}
/* ************************************************************************************************************************* */
void checkInputLevel3()
{
    if(game_over || finish)
        return;
    if(hand.y <= 450)
    {
        hand.y += hand.dy;
        circle.addToObjects();
        star.update();
        switcher.update();
    }
    if(circle.getCircles().at(10).getY()>200 || triangle.getTriangles().at(9).getY()>200 || square.getSquares().at(13).getY()>200)
    {
        if(i==3)
        {
            circle.addToObjects();
            triangle.addToObjects();
            star.update();
            star1.update();
            switcher.update();
            switcher1.update();
        }
        else if(i==2)
        {
            triangle.addToObjects();
            square.addToObjects();
            star2.update();
            star1.update();
            switcher2.update();
            switcher1.update();
        }
        else if(i==1)
        {
            square.addToObjects();
            circle.addToObjects();
            star.update();
            star2.update();
            switcher.update();
            switcher2.update();
        }
    }
    if(circle.getCircles().at(10).getY() > 500)
    {
        if(numOfPoints <= 24)
        {
            circle.reset();
            switcher.restart();
            star.reset();

        }
        else
        {
            circle.reset3();
        }

        circle.setColors();
        --i;


    }
    if(triangle.getTriangles().at(9).getY() > 500)
    {
        if(numOfPoints <= 24)
       {
            triangle.reset();
            switcher1.restart();
            star1.reset3();

       }
       else
       {
           triangle.reset2();
       }

       triangle.setColors();
        --i;
    }
    if(square.getSquares().at(13).getY() > 500)
    {
        if(numOfPoints <=26)
            square.reset();
        square.setColors();
        star2.reset();
        if(numOfPoints < 25)
            switcher2.restart();

        --i;
    }
    if(i<1)
        i=3;
    checkIfDoneCircle();
    checkIfDoneSquare();
    checkIfDoneTriangle();
}
/* ************************************************************************************************************************* */
void Update()
{
    if(game_over || finish)
    {
        if(!poslato){
        char *err=0;
        int status;
        sqlite3 *db;
        sqlite3_open("baza",&db);
        char sql[200];
        sprintf(sql,"INSERT INTO SCORE (name,score)" "VALUES ('%s','%d')",name,numOfPoints);

        status = sqlite3_exec(db,sql,0,0, &err);
        sqlite3_free(err);
        sqlite3_close(db);
        poslato=!poslato;
        }
    }
    else{

    if(PRESSED(VK_UP))
    {
            if(ball.getPosition()>100)
            ball.addToPosition(-10);
            hand.dy=5;
            if(isLevel1)
            {
                circle.setDy(5);
                circle1.setDy(5);
                star.setDy(5);
                switcher.setDy(5);
                star1.setDy(5);
                switcher1.setDy(5);
            }
            else if(isLevel2)
            {
                circle.setDy(5);
                triangle.setDy(5);
                star.setDy(5);
                switcher.setDy(5);
                star1.setDy(5);
                switcher1.setDy(5);
            }
            else if(isLevel3)
            {
                circle.setDy(5);
                triangle.setDy(5);
                square.setDy(5);
                star.setDy(5);
                switcher.setDy(5);
                star1.setDy(5);
                switcher1.setDy(5);
                star2.setDy(5);
                switcher2.setDy(5);
            }
    }
    else
    {
        if(ball.getPosition()>hand.y-20)
            return;
        ball.addToPosition(5);
        if(isLevel1)
        {
            circle.setDy(0);
            circle1.setDy(0);
            star.setDy(0);
            switcher.setDy(0);
            star1.setDy(0);
            switcher1.setDy(0);
        }

        else if(isLevel2)
        {
            circle.setDy(0);
            triangle.setDy(0);
            star.setDy(0);
            switcher.setDy(0);
            star1.setDy(0);
            switcher1.setDy(0);
        }
        else if(isLevel3)
        {
            circle.setDy(0);
            triangle.setDy(0);
            square.setDy(0);
            star.setDy(0);
            switcher.setDy(0);
            star1.setDy(0);
            switcher1.setDy(0);
            star2.setDy(0);
            switcher2.setDy(0);
        }
        hand.dy=0;
    }
    }
}

void checkInput(HDC hdcBuffer, HWND hwnd)
{
    RECT rect;
    GetClientRect(hwnd, &rect);
        if(ball.getPosition() - switcher.getY1()<5)
            {
                switcher.restart1();
                COLORREF ballColor = ball.getColor();
                if(ballColor == colors.getColor1())
                    ball.setColor(colors.getColor2());
                if(ballColor == colors.getColor2())
                    ball.setColor(colors.getColor3());
                if(ballColor == colors.getColor3())
                    ball.setColor(colors.getColor4());
                if(ballColor == colors.getColor4())
                    ball.setColor(colors.getColor1());

            }
        if(ball.getPosition()>350)
        {
            game_over=true;
        }

            if(ball.getPosition() - switcher1.getY1()<5)
            {
                switcher1.restart1();
                COLORREF ballColor = ball.getColor();
                if(ballColor == colors.getColor1())
                    ball.setColor(colors.getColor2());
                if(ballColor == colors.getColor2())
                    ball.setColor(colors.getColor3());
                if(ballColor == colors.getColor3())
                    ball.setColor(colors.getColor4());
                if(ballColor == colors.getColor4())
                    ball.setColor(colors.getColor1());
            }

            if(ball.getPosition() - switcher2.getY1()<5)
            {
                switcher2.restart1();
                COLORREF ballColor = ball.getColor();
                if(ballColor == colors.getColor1())
                    ball.setColor(colors.getColor2());
                if(ballColor == colors.getColor2())
                    ball.setColor(colors.getColor3());
                if(ballColor == colors.getColor3())
                    ball.setColor(colors.getColor4());
                if(ballColor == colors.getColor4())
                    ball.setColor(colors.getColor1());
            }

            if(ball.getPosition() - star.getY1()<5)
            {
                star.reset1();
                numOfPoints++;
                SendMessage(hwndSecondWindow, DRAW, 0,0);
            }

            if(ball.getPosition() - star1.getY1()<5)
            {
                star1.reset1();
                numOfPoints++;
                SendMessage(hwndSecondWindow, DRAW, 0,0);
            }

            if(ball.getPosition() - star2.getY1()<5)
            {
                star2.reset1();
                numOfPoints++;
                SendMessage(hwndSecondWindow, DRAW, 0,0);
            }

            if(isLevel1)
            {
                checkInputLevel1();
                if(numOfPoints == 5 && circle.getCircles().at(0).getY()-20 > ball.getPosition())
                {
                MessageBox(hwnd,"You have finished first level! Second one is coming :)","Successful",MB_OK);
                isLevel1 = false;
                //delete *circle1;

                _frameDelay = 75;
                hand.x = 268;
                hand.y = 274;

                circle.reset2();
                circle.setColors();
                star.reset2();
                switcher.restart2();

                triangle = (*new Triangle());
                triangle.setTriangleColors(colors);
                triangle.reset();
                switcher1.restart();
                star1.reset3();

                ball.setPosition(265);

                level++;
                SendMessage(hwndSecondWindow, DRAW, 0, 0);

                isLevel2 = true;
                return;
                }
            }
            if(isLevel2)
            {
                checkInputLevel2();
                if(numOfPoints == 15 && triangle.getTriangles().at(0).getY()-20 > ball.getPosition())
                {
                MessageBox(hwnd,"You have finished second level! Third one is coming :)","Successful",MB_OK);
                isLevel2 = false;
                //delete *circle1;

                _frameDelay=60;
                hand.x = 268;
                hand.y = 274;

                circle.reset2();
                circle.setCircleColors(colors);
                circle.setColors();
                star.reset2();
                switcher.restart2();

                triangle.reset();
                triangle.setTriangleColors(colors);
                triangle.setColors();
                switcher1.restart();
                star1.reset();

                square = (*new Square());
                square.setSquareColors(colors);
                square.reset();
                star2 = (*new Star(color4));
                star2.reset();
                switcher2 = (*new Switcher(colors));
                switcher2.restart();

                ball.setPosition(265);
                level++;
                SendMessage(hwndSecondWindow, DRAW, 0, 0);

                isLevel3 = true;
                return;
                }

            }
            if(isLevel3)
            {
                checkInputLevel3();
                if(numOfPoints == 27 && square.getSquares().at(0).getY()-20 > ball.getPosition())
                {
                    finish = true;
                    return;
                }
        }
}

void draw(HWND hwnd)
{
    RECT rect;
    HDC hdc=GetDC(hwnd);
    GetClientRect(hwnd,&rect);

    HDC hdcBuffer = CreateCompatibleDC(hdc);
    HBITMAP hbmBuffer = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
    HBITMAP hbmOldBuffer = (HBITMAP)SelectObject(hdcBuffer, hbmBuffer);

    HDC hdcMem = CreateCompatibleDC(hdc);

    HBITMAP hbmOld1 = (HBITMAP)SelectObject(hdcMem, background);
    BitBlt(hdcBuffer, bck.x, bck.y, bck.width, bck.height, hdcMem, 0, 0, SRCPAINT);
    HBITMAP hbmOld2,hbmOld3,hbmOld4,hbmOld5, hbmOld6, hbmOld7, hbmOld8, hbmOld9;

    if(finish)
    {
    hbmOld6 = (HBITMAP) SelectObject(hdcMem, hbmFinishedWhite);
    BitBlt(hdcBuffer, finished.x, finished.y, finished.width, finished.height, hdcMem, 0, 0, SRCAND);
    hbmOld7 = (HBITMAP) SelectObject(hdcMem, hbmFinishedBlack);
    BitBlt(hdcBuffer, finished.x, finished.y, finished.width, finished.height, hdcMem, 0, 0, SRCPAINT);
    if(finished.y < 10)
        finished.y+=10;

    }

    else if(game_over)
    {
    hbmOld8 = (HBITMAP) SelectObject(hdcMem, hbmGameOverBlack);
    BitBlt(hdcBuffer, gameOver.x, gameOver.y, gameOver.width, gameOver.height, hdcMem, 0, 0, SRCPAINT);

    hbmOld9 = (HBITMAP) SelectObject(hdcMem, hbmGameOverWhite);
    BitBlt(hdcBuffer, gameOver.x, gameOver.y, gameOver.width, gameOver.height, hdcMem, 0, 0, SRCAND);
        if(gameOver.y < 50)
            gameOver.y+=10;
    }

    else if(start)
    {
    hbmOld2 = (HBITMAP)SelectObject(hdcMem, hbmColorSwitch);
    BitBlt(hdcBuffer, colorswitch.x, colorswitch.y, colorswitch.width, colorswitch.height, hdcMem, 0, 0, SRCAND);

    hbmOld3 = (HBITMAP) SelectObject(hdcMem,hbmColorSwitchBlack);
    BitBlt(hdcBuffer, colorswitch.x, colorswitch.y, colorswitch.width, colorswitch.height, hdcMem, 0, 0, SRCPAINT);
    }
    else
    {


    hbmOld4 = (HBITMAP)SelectObject(hdcMem, hbmHandWhite);
    BitBlt(hdcBuffer, hand.x, hand.y, hand.width, hand.height, hdcMem, 0, 0, SRCAND);

    hbmOld5 = (HBITMAP) SelectObject(hdcMem,hbmHandBlack);
    BitBlt(hdcBuffer, hand.x, hand.y, hand.width, hand.height, hdcMem, 0, 0, SRCPAINT);

    switcher.drawSwitcher(hdcBuffer);
    switcher1.drawSwitcher(hdcBuffer);
    switcher2.drawSwitcher(hdcBuffer);
    star.draw(hdcBuffer);
    star1.draw(hdcBuffer);
    star2.draw(hdcBuffer);
    ball.drawBall(hdcBuffer);

    if(isLevel1) {

        if(circle.getDrawn())
            circle.changeColor();
        circle.drawCircles(hdcBuffer);

        if(circle1.getDrawn())
            circle1.changeColor();
        circle1.drawCircles(hdcBuffer);

    }
    else if(isLevel2)
    {
        if(circle.getDrawn())
                circle.changeColor();
        circle.drawCircles(hdcBuffer);
        if(triangle.getDrawn())
            triangle.changeColor();
        triangle.drawTriangles(hdcBuffer);
    }
    else if(isLevel3)
    {
        if(circle.getDrawn())
            circle.changeColor();
        circle.drawCircles(hdcBuffer);
        if(triangle.getDrawn())
            triangle.changeColor();
        triangle.drawTriangles(hdcBuffer);
        if(square.getDrawn())
            square.changeColor();
        square.drawSquares(hdcBuffer);
    }
    }
    BitBlt(hdc,0, 0, rect.right, rect.bottom, hdcBuffer, 0, 0, SRCCOPY);

    SelectObject(hdcMem, hbmOld1);
    SelectObject(hdcMem, hbmOld2);
    SelectObject(hdcMem, hbmOld3);
    SelectObject(hdcMem, hbmOld4);
    SelectObject(hdcMem, hbmOld5);
    SelectObject(hdcMem, hbmOld6);
    SelectObject(hdcMem, hbmOld7);
    SelectObject(hdcMem, hbmOld8);
    SelectObject(hdcMem, hbmOld9);

    DeleteObject(hdcMem);
    DeleteObject(hdcBuffer);

}

void drawSecondWindow(HWND hwnd)
{
            HDC hdc = GetDC(hwnd);
            HDC hdcBuffer = CreateCompatibleDC(hdc);
            RECT rect;
            GetClientRect(hwnd, &rect);
            HBITMAP hbmBuffer = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
            HBITMAP hbmOldBuffer = (HBITMAP)SelectObject(hdcBuffer, hbmBuffer);
            HDC hdcMem = CreateCompatibleDC(hdc);

            HFONT font1;
            HBITMAP hbmOld1 = (HBITMAP)SelectObject(hdcMem, background);
            BitBlt(hdcBuffer, bck.x, bck.y, bck.width, bck.height, hdcMem, 0, 0, SRCPAINT);

            SetTextColor(hdcBuffer, RGB(255,255,255));
            SetBkMode(hdcBuffer, TRANSPARENT);

            font1=CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_ROMAN,"Times New Roman");
            SelectObject(hdcBuffer,font1);

            SetTextColor(hdcBuffer, RGB(255,255,255));
            TextOut(hdcBuffer, 5, 5, "PLAYER NAME:", 12);

            SetTextColor(hdcBuffer, RGB(255,255,0));
            TextOut(hdcBuffer, 5, 25, name, strlen(name));

            SetTextColor(hdcBuffer, RGB(255,255,255));
            TextOut(hdcBuffer, 5, 80, "LEVEL:", 6);

            SetTextColor(hdcBuffer, RGB(255,255,0));
            font1=CreateFont(30,20,0,0,FW_NORMAL,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_ROMAN,"Times New Roman");
            SelectObject(hdcBuffer,font1);
            char a[1];
            int b = wsprintf(a, "%d", level);
            TextOut(hdcBuffer, 30, 100, a, b);

            font1=CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_ROMAN,"Times New Roman");
            SelectObject(hdcBuffer,font1);
            SetTextColor(hdcBuffer, RGB(255,255,255));
            TextOut(hdcBuffer, 5, 170, "SCORE:", 6);

            SetTextColor(hdcBuffer, RGB(255,255,0));
            font1=CreateFont(30,20,0,0,FW_NORMAL,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_ROMAN,"Times New Roman");
            SelectObject(hdcBuffer,font1);
            char c[1];
            int d = wsprintf(c, "%d", numOfPoints);
            TextOut(hdcBuffer, 30, 190, c, d);

            BitBlt(hdc,0, 0, rect.right, rect.bottom, hdcBuffer, 0, 0, SRCCOPY);
            SelectObject(hdcMem, hbmOld1);
            DeleteObject(hdcMem);
            DeleteObject(hdcBuffer);

            ReleaseDC(hwnd, hdc);
}


/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
static int num;
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{

    MSG msg;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;
    num=nCmdShow;
    BITMAP bitmap;
    unsigned int timer = SetTimer(hwnd, ID_TIMER, 20, NULL);
    hbmHandWhite= (HBITMAP) LoadImage(NULL, "hand_white.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    hbmHandBlack = (HBITMAP) LoadImage(NULL, "hand_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    hbmColorSwitch= (HBITMAP) LoadImage(NULL, "ColorSwitch.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    hbmColorSwitchBlack = (HBITMAP) LoadImage(NULL, "ColorSwitch-black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    hbmFinishedWhite = (HBITMAP) LoadImage(NULL, "done.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbmFinishedBlack = (HBITMAP) LoadImage(NULL, "done_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbmGameOverWhite = (HBITMAP) LoadImage(NULL, "game_over.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbmGameOverBlack = (HBITMAP) LoadImage(NULL, "game_over_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    background = (HBITMAP) LoadImage(NULL, "pozadina1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );

    GetObject(hbmGameOverBlack, sizeof(BITMAP), &bitmap);
    gameOver.width = bitmap.bmWidth;
    gameOver.height = bitmap.bmHeight;
    gameOver.x = 121.5;
    gameOver.y = -210;

    GetObject(hbmFinishedBlack, sizeof(BITMAP), &bitmap);
    finished.width = bitmap.bmWidth;
    finished.height = bitmap.bmHeight;
    finished.x = 80;
    finished.y = -400;

    GetObject(hbmHandWhite, sizeof(BITMAP), &bitmap);
    hand.width = bitmap.bmWidth;
    hand.height = bitmap.bmHeight;
    hand.x = 268;
    hand.y = 274;

    GetObject(hbmColorSwitch, sizeof(BITMAP), &bitmap);
    colorswitch.width = bitmap.bmWidth;
    colorswitch.height = bitmap.bmHeight;
    colorswitch.x = 170;
    colorswitch.y = 50;


    GetObject(background, sizeof(BITMAP), &bitmap);
    bck.width = bitmap.bmWidth;
    bck.height = bitmap.bmHeight;
    bck.x = 0;
    bck.y = 0;

    COLORREF color1=RGB(167,0,201);
    COLORREF color2=RGB(255,3,96);
    COLORREF color3=RGB(3,248,255);
    COLORREF color4=RGB(255,255,25);
    colors.setColor1(color1);
    colors.setColor2(color2);
    colors.setColor3(color3);
    colors.setColor4(color4);


    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "Parent";
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) GetStockObject(DKGRAY_BRUSH);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    wincl.lpfnWndProc = WindowProcedureSecondWindow;
    wincl.lpszClassName = "Child";
    wincl.lpszMenuName = NULL;
    wincl.hbrBackground= (HBRUSH) GetStockObject(WHITE_BRUSH);
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           "Parent",         /* Classname */
           _T("Krug"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           350,       /* Windows decides the position */
           200,       /* where the window ends up on the screen */
           600,                 /* The programs width */
           400,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    hwndSecondWindow = CreateWindowEx (
                           0,                   /* Extended possibilites for variation */
                           "Child",         /* Classname */
                           _T("Status"),       /* Title Text */
                           WS_CAPTION| WS_POPUP,
                           945,       /* Windows decides the position */
                           200,       /* where the window ends up on the screen */
                           200,                 /* The programs width */
                           395,                 /* and height in pixels */
                           hwnd,        /* The window is a child-window to desktop */
                           NULL,                /* No menu */
                           (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE),       /* Program Instance handler */
                           NULL                 /* No Window Creation data */
                       );

/*-----------------------------------------------------------*/

DWORD next_game_tick = GetTickCount();
int loops;
//MSG msg = {0};
bool m_bIsGameRunning = true;
const int TICKS_PER_SECOND = 500000 ; // Update() rate per second
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 100;
/*------------------------------------------------------------*/

    /* Run the message loop. It will run until GetMessage() returns 0 */
   while (_isRunning)
{
        HDC hdc = GetDC(hwnd);
         DWORD start_time;
         if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
         {
             if(msg.message == WM_QUIT)
             {
                exit(0);
             	break;
             }
             TranslateMessage(&msg);
             DispatchMessage(&msg);
         }
         start_time = GetTickCount();
         Update();
         checkInput(hdc, hwnd);
         draw(hwnd);

         DWORD frame_time = GetTickCount() - start_time;
        if(frame_time < _frameDelay)
       {
         Sleep(_frameDelay - frame_time);
       }
        ReleaseDC(hwnd,hdc);
 }

 m_bIsGameRunning = false;
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return msg.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedureSecondWindow (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)                  /* handle the messages */
    {

        case DRAW:
        {
            drawSecondWindow(hwnd);
            break;
        }
        case WM_CREATE:
        {break;
        }
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;

        case WM_COMMAND:
            {
            switch(LOWORD(wParam))
            {
                case IDM_EXIT1:
                    {
                        exit(0);
                    break;
                    }
                case IDM_NEW_GAME1:
                    {
                        name="";
                        DialogBox(HIDD2, MAKEINTRESOURCE(DLG_MAIN), hwnd, (DLGPROC)DlgMain);
                        break;
                    }
                case IDM_SCORE1:
                    {
                        DialogBox(HIDD2, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, (DLGPROC)DlgMain1);
                        b=1;
                        break;
                    }
            }
            break;
            }
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

void setColor(int num,COLORREF color)
{
    if(num==1)
        colors.setColor1(color);
    if(num==2)
        colors.setColor2(color);
    if(num==3)
        colors.setColor3(color);
    if(num==4)
        colors.setColor4(color);
}

int provjeri(HWND hwnd){
    HWND button=GetDlgItem(hwnd,IDC_EDIT1);
    int b=SendMessage(button,EM_GETLINECOUNT,0,0);
    int b1=SendMessage(button,EM_LINELENGTH,0,0);
    if(b1<1)
        return 2;
    else{
        name = new TCHAR[b1];
        SendMessage(button,WM_GETTEXT,b1+1,(LPARAM)name);
        }
    int num_of_colors=0;
    HWND checkbox=GetDlgItem(hwnd,green);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,purple);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,yellow);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,orange);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,white);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,pink);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,magenta);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,cyan);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,brown);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,red);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,blue);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    checkbox=GetDlgItem(hwnd,grey);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
        ++num_of_colors;

    if(num_of_colors!=4)
        return 1;
    int num=1;

    checkbox=GetDlgItem(hwnd,green);
    COLORREF color;
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
    {
        color=RGB(0,255,0);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,purple);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
    {
        color=RGB(128,0,128);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,yellow);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
    {
        color=RGB(255,255,0);
        setColor(num,color);
        ++num;
    }

    checkbox=GetDlgItem(hwnd,orange);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
    {
        color=RGB(255,145,0);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,white);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(255,255,255);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,pink);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(246,74,143);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,magenta);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(255,0,255);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,cyan);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(0,255,255);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,brown);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(165,42,42);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,red);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(255,0,0);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,blue);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(0,0,255);
        setColor(num,color);
        ++num;
    }
    checkbox=GetDlgItem(hwnd,grey);
    if(SendMessage(checkbox,BM_GETCHECK,0,0))
     {
        color=RGB(128,128,128);
        setColor(num,color);
        ++num;
    }
return 0;
}


BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
    {
        break;
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDOK:

            if(provjeri(hwndDlg)==0){
                start=false;
                poslato=false;
                circle.setCircleColors(colors);
                circle1.setCircleColors(colors);
                square.setSquareColors(colors);
                triangle.setTriangleColors(colors);
                switcher1.setColor(colors);
                switcher2.setColor(colors);
                switcher.setColor(colors);
                ball.setColor(colors.getColor1());
                i=3;

                isLevel1=true;
                isLevel2=false;
                isLevel3=false;

                finish = false;
                game_over = false;
                circleisDrawn = false;
                triangleisDrawn = false;
                squareisDrawn = false;

                numOfPoints=0;
                level=1;
                done = false;
                ball = (*new GameBall());
                ball.setColor(colors.getColor1());
                circle = (*new Circle());
                circle1 = (*new Circle());
                circle1.reset();
                circle.setCircleColors(colors);
                circle1.setCircleColors(colors);
                circle.setColors();
                circle1.setColors();
                switcher = (*new Switcher(colors));
                switcher1 = (*new Switcher(colors));
                switcher1.restart();

                star = (*new Star(color4));
                star1 = (*new Star(color4));
                star1.reset();

                gameOver.x = 121.5;
                gameOver.y = -210;

                finished.x = 80;
                finished.y = -400;

                hand.x = 268;
                hand.y = 274;
                ShowWindow(hwndSecondWindow,num);
                SendMessage(hwndSecondWindow,DRAW,0,0);

                EndDialog(hwndDlg, 0);
            }
            else if(provjeri(hwndDlg)==1)
                MessageBox(hwndDlg,"You can only select four colors!","Error",MB_OK);
            else if(provjeri(hwndDlg)==2)
                 {
                MessageBox(hwndDlg,"Please insert your name!","Error",MB_OK);
                 }
            break;
        }
        break;
    }
    return TRUE;
    }
    return FALSE;
}

int callback(void *pArg, int argc, char **argv, char **imekolone)
{
 int i;

 for (i = 0; i < argc; i++)
    {
        if(i==0){

                if(b==1)
                {
                    SetDlgItemText(hdil2,rank1,"1");
                    SetDlgItemText(hdil2,name1,argv[i]);
                }
                else if(b==2)
                {
                    SetDlgItemText(hdil2,rank2,"2");
                    SetDlgItemText(hdil2,name2,argv[i]);
                }

           if(b==3)
                {
                    SetDlgItemText(hdil2,rank3,"3");
                    SetDlgItemText(hdil2,name3,argv[i]);
                }
                else if(b==4)
                {
                    SetDlgItemText(hdil2,rank4,"4");
                    SetDlgItemText(hdil2,name4,argv[i]);
                }
                else if(b==5)
                {
                    SetDlgItemText(hdil2,rank5,"5");
                    SetDlgItemText(hdil2,name5,argv[i]);
                }
        }

        if(i==1)
               {

               if(b==1)
                {
                    SetDlgItemText(hdil2,score1,argv[i]);
                    ++b;
                }
                else if(b==2)
                {
                    SetDlgItemText(hdil2,score2,argv[i]);
                    ++b;
                }
                else if(b==3)
                {
                    SetDlgItemText(hdil2,score3,argv[i]);
                    ++b;
                }
                else if(b==4)
                {
                    SetDlgItemText(hdil2,score4,argv[i]);
                    ++b;
                }
                else if(b==5)
                {
                    SetDlgItemText(hdil2,score5,argv[i]);
                    ++b;
                }
    }}

 return(0);

}


BOOL CALLBACK DlgMain1(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    hdil2=hwndDlg;
    switch(uMsg)
    {
        case WM_INITDIALOG:
    {
        char *err=0;
        int status;
        sqlite3 *db;
        sqlite3_open("baza",&db);
        status = sqlite3_exec(db, "SELECT NAME,SCORE FROM Score ORDER BY SCORE DESC LIMIT 5", callback, NULL, &err);
        if (status != SQLITE_OK)
        {
            fprintf(stderr, "SQL greska: %s\n", err);
        }
        sqlite3_free(err);
        sqlite3_close(db);

        break;
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    }
    return FALSE;
}

