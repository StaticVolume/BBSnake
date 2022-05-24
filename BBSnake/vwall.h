#pragma once

#include "figure.h"
#include "point.h"
#include "ancontainer.h"
#include "non_active_figure.h"

class Vwall : public NonActiveFigure{

    private:
    unsigned int start_y;
    unsigned int last_y;
    unsigned int w_x;
    char w_style;
    Color color;

public:

    Vwall(unsigned int in_start_y, unsigned int in_last_y, unsigned int in_w_x, char in_w_style = '#', Color color = Color::WHITE);
    ~Vwall(){};
};

