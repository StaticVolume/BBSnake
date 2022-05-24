#pragma once

#include "figure.h"
#include "point.h"
#include "ancontainer.h"
#include "active_figure.h"
#include "display.h"

class Eat : public ActiveFigure {

private:

    Point* food = nullptr;

public:

    Eat(unsigned int w_width, unsigned int w_heigth, char in_style = '$', Color in_color = Color::YELLOW);
    Point* GetFood() {return food;};
    void SetFood(Point& point);
    ~Eat() { delete food; }
};
