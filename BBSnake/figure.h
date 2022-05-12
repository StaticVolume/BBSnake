#pragma once

#include <list>
#include "point.h"
#include "direction.h"


class Figure{

private:

    static unsigned int id;
    std::list<Point> pList;

protected:

     Figure() = default;
     static void SetId();

public:

    virtual ~Figure() = default;

    bool operator==(Figure& in_figure);
    bool operator!=(Figure& in_figure);
    static const unsigned int GetId() { return id; }
    inline std::list<Point>& GetFigureList(){ return pList; }
    void FMove(const Direction& dir, unsigned int offset = 1);
    bool FisHit( Figure& in_figure);
};

