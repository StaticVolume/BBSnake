#pragma once

#include "figure.h"
#include "ancontainer.h"
#include "display.h"


class Traceline : public Figure {

private:

    Point origin;
    Point destination;
    unsigned int length;
    char style;
    bool ishit;

public:
    Traceline(){};
    Traceline(const Point& origin,const Point& destination);

    inline Point& GetOrigin(){ return origin; }
    inline Point& GetDestination(){ return destination; }
    inline char GetStyle(){ return style; }
    inline unsigned int GetPairLength(){ return length; }
    inline bool GetIsHit() const {return ishit;}

    void SetOrigin(Point& in_point);
    void SetDestination(Point& in_destination);
    void SetStyle(char in_style);
    void SetLength(unsigned int in_length);
    void SetIsHit(bool ishit);

    void CalculateTraceLineWhithDirection(const Point& origin,const Direction& dir);
    void BuildTrace(void);
    void CalculateBrezenhemTraceLine(void);

    void ClearAfterMove();
};


