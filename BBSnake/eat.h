#pragma once

#include "figure.h"
#include "point.h"

class Eat : public Figure{

private:

    Point food;

public:

    Eat(int in_x, int in_y, char in_style = '$');
    Eat(Point& in_food);
};
