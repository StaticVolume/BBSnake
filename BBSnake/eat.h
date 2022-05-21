#pragma once

#include "figure.h"
#include "point.h"
#include "ancontainer.h"
#include "active_figure.h"

class Eat : public ActiveFigure {

private:

    Point food;

public:

    Eat(int in_x, int in_y, char in_style = '$');
    Eat(Point& in_food);
};
