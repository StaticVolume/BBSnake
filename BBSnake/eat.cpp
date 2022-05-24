#include "eat.h"


Eat::Eat(unsigned int w_width, unsigned int w_heigth,char in_style, Color in_color){
    food  = new Point ( (2 + rand() % (50)), (2 + rand() % (10)), in_style, in_color);;
    GetFigureList().push_back(*food);
}

void Eat::SetFood(Point& point) {

    food = new Point(point);
}
