#include "enemy.h"


Enemy::Enemy(char style, Color color) : style{style}, color{color} {
    unsigned int x = 50;
    unsigned int y = 15;

    Point p(x,y,style,color);
    GetFigureList().push_back(p);

   /* Hline top(50,55,10,style,color);
    Hline bottom(50,55, 12, style, color);
    Hline canon(48,50,11,style, color);

    Vline left(10,12,50,style, color);
    Vline rigth(10,12,55,style, color);

    carcas.push_back(top);
    carcas.push_back(bottom);
    carcas.push_back(canon);
    carcas.push_back(left);
    carcas.push_back(rigth);*/

}
