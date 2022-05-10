#include <iostream>

#include "point.h"
#include "display.h"
#include "figure.h"
#include "ancontainer.h"
#include "hwall.h"
#include "vwall.h"
#include "snake.h"
#include "direction.h"
#include "display.h"
#include <chrono>
#include <thread>

using namespace std;

int main(void)
{
    Direction dir;
    Color point_color = Color::GREEN;
    Color trace_color = Color::YELLOW;
    Color wall_color = Color::WHITE;
    Display display;

    Hwall wall1(0,display.GetDisplayWidth()-1, 0 ,'#');
    Hwall wall2(0,display.GetDisplayWidth()-1, display.GetDisplayHeigth()-1,'#');
    Vwall wall3(0,display.GetDisplayHeigth()-1,0,'#');
    Vwall wall4(0,display.GetDisplayHeigth()-1,display.GetDisplayWidth()-1,'#');

    Point p(100,10);
    Point g(100,20);
    Point v(100,40);

    Snake snake(Point(5,15),10,Direction::RIGTH,'D','*');

    Traceline trace(p,g);
    Traceline tr(g,v);

    trace.CalculateTraceLine();
    tr.CalculateTraceLine();

    display.DrawFigure(wall1);
    display.DrawFigure(wall2);
    display.DrawFigure(wall3);
    display.DrawFigure(wall4);

    display.DrawPoint(p);
    display.DrawPoint(g);

    display.DrawFigure(trace);
    display.DrawFigure(tr);

    display.DrawFigure(snake);


    while(true){

        switch (getch()) {
            case 'd': dir = Direction::RIGTH;
                break;
            case 'a' : dir = Direction::LEFT;
                break;
            case 'w' : dir = Direction::UP;
                break;
            case 's' :  dir = Direction::DOWN;
        }
     snake.Move(dir, 1);
     display.DrawFigure(snake);
     snake.ClearAfterMove();
    }



    display.Stop(getch());
    return 0;
}
