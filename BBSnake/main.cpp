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
#include <string.h>
using namespace std;

int main(void)
{
    Direction dir;
    bool ishit = false;

    Display display;

    Hwall wall1(0,display.GetDisplayWidth()-1, 0 ,'#');
    Hwall wall2(0,display.GetDisplayWidth()-1, display.GetDisplayHeigth()-1,'#');
    Vwall wall3(0,display.GetDisplayHeigth()-1,0,'#');
    Vwall wall4(0,display.GetDisplayHeigth()-1,display.GetDisplayWidth()-1,'#');
    Vwall wall5(0,20,200,'#');

    display.DrawFigure(wall1);
    display.DrawFigure(wall2);
    display.DrawFigure(wall3);
    display.DrawFigure(wall4);
    display.DrawFigure(wall5);

    Snake snake(Point(1,10),10,Direction::RIGTH,'*','*');
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



     snake.ClearAfterMoveTraceLine(display);
     snake.GetTraceLine().CalculateTraceLineWhithDirection(snake.GetTraceLine().GetOrigin(), dir);
     bool ishit = snake.IsHitByPoints( snake.GetTraceLine().GetOrigin(), snake.GetTraceLine().GetDestination(), dir ) ;

        if(ishit) {
            for(int x = 0 ; x < snake.GetFigureList().size(); ++x){
                snake.Move_Back__By_Hit(dir);
                snake.GetTraceLine().BuildTrace();
                display.DrawFigure(snake.GetTrace());
                display.DrawFigure(snake);
                snake.ClearAfterMove();
            }

        } else {
            snake.Move(dir, 1);
            snake.GetTraceLine().BuildTrace();
            display.DrawFigure(snake.GetTrace());
            display.DrawFigure(snake);
            snake.ClearAfterMove();

        }





  }

    display.Stop(getch());
    return 0;
}
