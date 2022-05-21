#include "point.h"

Point::Point():x{0},y{0},style{'*'}{}

Point::Point(int in_x, int in_y, char in_style,  Color in_color): x{in_x},y{in_y}, style{in_style}, p_color{in_color} {}

bool Point::operator==(const Point& in_point) {

    return (  (x == in_point.x) && (y == in_point.y)   );
}

bool Point::operator!=(const Point& in_point) {

    return !(*this == in_point);
}

Point& Point::operator=(const Point& in_point) {

    if (*this != in_point) {
        x = in_point.GetPointX();
        y = in_point.GetPointY();
        style = in_point.GetPointStyle();
        p_color = in_point.GetPointColor();
    }
    return *this;
}

Point& Point::operator-(const Point& in_point) {

    this->SetPointX(this->GetPointX() - in_point.GetPointX());
    this->SetPointY(this->GetPointY() - in_point.GetPointY());

    return *this;
}

void Point::SetPointStyle(char in_style) {

    style = in_style;
}

void Point::SetPointX(int in_x){

    x = in_x;
}

void Point::SetPointY(int in_y){

    y = in_y;
}
void Point::SetPointColor(Color& in_color) {
    p_color = in_color;
}

void Point::Delete(){

    style  = ' ';
}

void Point::Move(const Direction& dir, unsigned int in_offset){

    switch (dir) {
    case Direction::RIGTH : x+= in_offset;
        break;
    case Direction::LEFT :  x-= in_offset;
        break;
    case Direction::UP:     y-= in_offset;
        break;
    case Direction::DOWN:   y+= in_offset;
        break;
    default:
        break;
    }
}

bool Point::isHit(const Point& in_point){
    bool ishit = ((x == in_point.GetPointX()) && (y == in_point.GetPointY())) ? true : false;
    return ishit;
}

