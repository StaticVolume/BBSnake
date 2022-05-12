#pragma once

#include "figure.h"
#include "point.h"
#include "ancontainer.h"

class Vwall : public Figure{

    private:
    unsigned int start_y;
    unsigned int last_y;
    unsigned int w_x;
    char w_style;

public:

    Vwall(unsigned int in_start_y, unsigned int in_last_y, unsigned int in_w_x, char in_w_style = '#');
    ~Vwall(){};
};

