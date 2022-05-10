#pragma once

#include "point.h"
#include "direction.h"
#include "figure.h"
#include "ancontainer.h"
#include "display.h"
#include "traceline.h"
#include "color.h"

class Snake: public Figure{

private:
    Traceline trace;
    Direction dir;
    Point start;
    Color head_color, body_color;
    char head_style, body_style;
    unsigned int speed,length;

public:

    Snake(const Point start, unsigned int length, const Direction dir, char head_style = '@', char body_style= '*', Color body_color = Color::YELLOW,
    Color head_color = Color::GREEN);

    void Move(const Direction& dir, unsigned int offset);
    void Eat(ANContainer& figurs, bool is_interactive = true);
    void ClearAfterMove();

};

