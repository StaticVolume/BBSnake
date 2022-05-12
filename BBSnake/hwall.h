#pragma once

#include "figure.h"
#include "point.h"
#include "ancontainer.h"

class Hwall : public Figure{

private:
    unsigned int start_x;
    unsigned int last_x;
    unsigned int w_y;
    char w_style;

public:

    Hwall(unsigned int in_start_x, unsigned int in_last_x, unsigned int in_w_y, char in_w_style = '#');
    ~Hwall();
};


