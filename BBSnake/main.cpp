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
#include "eat.h"
#include "enemy.h"
#include <chrono>
#include <time.h>

#define MS_TO_FRAME 16

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

    Snake snake(Point(1,10),4,Direction::RIGTH,'*','*');


    Eat** p_eat = nullptr;
    Eat* eat = new Eat(50, 20);
    p_eat = &eat;

    //Enemy en('@',Color::RED);


    display.DrawFigure(wall1);
    display.DrawFigure(wall2);
    display.DrawFigure(wall3);
    display.DrawFigure(wall4);
    display.DrawFigure(wall5);


  //  display.DrawFigure(en);
    display.DrawFigure( **p_eat );



    /*for (auto& F : en.GetCarcas()) {
          display.DrawFigure(F);
     }*/



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
     bool hit_my_self = snake.IsHitMySelfe(snake.GetTraceLine().GetDestination());



        if(ishit) {

            bool is_eat = false;

                for(auto& p : (*p_eat)->GetFigureList()) {
                   if (p == snake.GetTraceLine().GetDestination()) {
                       is_eat = true;
                       p.Delete();
                       (*p_eat)->GetFigureList().clear();
                        break;
                    }
                }
                if (is_eat) {

                    snake.Feed(dir);
                    (*p_eat)->Eat::~Eat();
                     p_eat= nullptr;
                     Eat* new_eat = new Eat(50, 20);
                     p_eat = &new_eat;
                    display.DrawFigure(**p_eat);

                } else if (hit_my_self) {

                     snake.DontMove();

                } else {

                    snake.Move_Back__By_Hit(dir, display, 1);
                }

        } else {

            snake.Move(dir, 1);
            snake.GetTraceLine().BuildTrace();
            display.DrawFigure(snake);
            display.DrawFigure(snake.GetTrace());
            snake.ClearAfterMove();

        }

      std::this_thread::sleep_for(std::chrono::milliseconds(MS_TO_FRAME));
  }

    display.Stop(getch());
    return 0;
}
