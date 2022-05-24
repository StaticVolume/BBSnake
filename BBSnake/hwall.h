#pragma once

#include "figure.h"
#include "point.h"
#include "ancontainer.h"
#include "non_active_figure.h"

class Hwall : public NonActiveFigure{

private:
    unsigned int start_x;
    unsigned int last_x;
    unsigned int w_y;
    char w_style;
    Color color;
public:

    Hwall(unsigned int in_start_x, unsigned int in_last_x, unsigned int in_w_y, char in_w_style = '#', Color color = Color::WHITE);
    ~Hwall();
};


