#pragma once

#include "figure.h"
#include "ancontainer.h"
#include "display.h"

class Traceline: public Figure{

private:
    Point origin;
    Point destination;
    unsigned int length;
    char style;

public:
    Traceline(){};
    Traceline(const Point& origin,const Point& destination);


    inline Point& GetOrigin(){ return origin; }
    inline Point& GetDestination(){ return destination; }
    inline char GetStyle(){ return style; }
    inline unsigned int GetPairLength(){ return length; }

    void SetOrigin(Point& in_point);
    void SetDestination(Point& in_destination);
    void SetStyle(char in_style);
    void SetLength(unsigned int in_length);

    void CalculateTraceLineWhithDirection(const Point& origin,const Direction& dir);
    void CalculateTraceLine(void);
    void CalculateBrezenhemTraceLine(void);

    void ClearAfterMove();
};


