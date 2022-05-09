#pragma once

#include <list>
#include "point.h"
#include "direction.h"


class Figure{

private:

    std::list<Point> pList;

protected:

    Figure() = default;

public:

    virtual ~Figure() = default;

    bool operator==(Figure& in_figure);
    bool operator!=(Figure& in_figure);

    inline std::list<Point>& GetFigureList(){ return pList; }
    void FMove(const Direction& dir, unsigned int offset = 1);
    bool FisHit( Figure& in_figure);
};


