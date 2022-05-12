#include "eat.h"


Eat::Eat(int in_x, int in_y, char in_style){
    food.SetPointX(in_x);
    food.SetPointY(in_y);
    food.SetPointStyle(in_style);

    ANContainer::GetInstance()->AddToContainer(*this, true);
}

Eat::Eat(Point& in_food):food{in_food}{}
