#pragma once

#include <list>
#include "point.h"
#include "direction.h"



class Figure{

private:

    static unsigned int id_all_figures;
    std::list<Point> pList;
    Color color;

protected:

    static void SetId();

public:

    Figure(Color color = Color::WHITE){ ++id_all_figures; }
    virtual ~Figure() = default;

    bool operator==(Figure& in_figure);
    bool operator!=(Figure& in_figure);
    static const unsigned int GetId() { return id_all_figures; }
    inline std::list<Point>& GetFigureList(){ return pList; }
    void FMove(const Direction& dir, unsigned int offset = 1);
    bool IsHit( Figure& in_figure);

};

