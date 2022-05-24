#pragma once

#include "point.h"
#include "direction.h"
#include "figure.h"
#include "ancontainer.h"
#include "display.h"
#include "traceline.h"
#include "color.h"
#include "active_figure.h"
#include "eat.h"

class Snake: public ActiveFigure{

private:

    Direction dir;
    Point start, head;
    Color head_color, body_color;
    char head_style, body_style;
    unsigned int speed,length;

public:

    Snake(const Point& start, unsigned int length, const Direction& dir, char head_style = '@', char body_style= '*', Color body_color = Color::CYAN,
    Color head_color = Color::RED);

    Point& GetHead() { return head; };
    Point& GetStart() { return start; };
    void Move(const Direction& dir, unsigned int offset);
    void DontMove();
    void Feed(const Direction& dir);
    void ClearAfterMove();
    void ClearAfterMoveTraceLine(Display& d);
    void Move_Back__By_Hit(Direction &dir, Display& d, unsigned int offcet = 2);




    ~Snake(){};
};

