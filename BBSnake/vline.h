#pragma once
//#include "figure.h"
#include "active_figure.h"

class Vline : public ActiveFigure {

private:
    unsigned int start_y;
    unsigned int last_y;
    unsigned int w_x;
    char w_style;
    Color color;

public:

    Vline(unsigned int in_start_y, unsigned int in_last_y, unsigned int in_w_x, char in_w_style = '#', Color color = Color::WHITE);

    ~Vline(){};
};
