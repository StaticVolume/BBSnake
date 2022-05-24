#pragma once
//#include "figure.h"
#include "active_figure.h"

class Hline : public ActiveFigure {
private:
    unsigned int start_x;
    unsigned int last_x;
    unsigned int w_y;
    char w_style;
    Color color;
public:
     Hline(unsigned int in_start_x, unsigned int in_last_x, unsigned int in_w_y, char in_w_style = '#', Color color = Color::WHITE);

    ~Hline(){};
};


