#include "active_figure.h"

unsigned int ActiveFigure::id_active_figures = 0;


bool ActiveFigure::IsHitByPoints(const Point& origin, const Point& destination, Direction& dir) const {

    bool is_hit = false;

    switch (dir) {
    case Direction::RIGTH : is_hit = (origin.GetPointX() > destination.GetPointX()-2) ;
        break;
    case Direction::LEFT : is_hit = (origin.GetPointX() < destination.GetPointX()+2);
        break;
    case Direction::UP:     is_hit = (origin.GetPointY() < destination.GetPointY()+2);
        break;
    case Direction::DOWN:   is_hit = (origin.GetPointY() > destination.GetPointY()-2);
        break;
    default:
        break;
    }

    return is_hit;
}

