#pragma once

#include "direction.h"
#include "color.h"

class Point{

private:

    char style;
    Color p_color;
    int x,y;

public:

    Point();
    Point(int in_x, int in_y, char in_style = '*', Color in_color = Color::WHITE);
    Point& operator=(const Point& in_point);
    Point& operator=(const int number);
    bool operator!=(const Point& in_point);
    bool operator ==(const Point& in_point);
    Point& operator-(const Point& in_point);

    inline int GetPointX()const { return x; }
    inline int GetPointY()const { return y; }
    inline Color GetPointColor()const { return p_color; };
    void SetPointX(int in_x);
    void SetPointY(int in_y);
    void SetPointColor(Color& in_color);

    inline char GetPointStyle()const { return style; }
    void SetPointStyle(char in_style);

    bool isEmty(void);
    void Move(const Direction& dir, unsigned int offset = 1);
    void Delete(void);
    bool isHit(const Point& in_point);
};

