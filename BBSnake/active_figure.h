#pragma once

#include "traceline.h"
#include "figure.h"
#include "direction.h"


class ActiveFigure: public Figure {
private:

    static unsigned int id_active_figures;
    Traceline trace;

public:

    ActiveFigure() { ANContainer::GetInstance()->AddToContainer(this, true); ++id_active_figures; }
   ~ActiveFigure() { ANContainer::GetInstance()->RemoveFromContainer(this, true); --id_active_figures; }

    Traceline& GetTraceLine() { return trace; }
    Figure& GetTrace() { return trace; }
    bool IsHitByPoints(const Point& origin, const  Point& destination, Direction& dir)const;
};

