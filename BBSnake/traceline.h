#pragma once

#include "figure.h"

class Traceline: public Figure{

private:

    Point origin;
    Point destination;
    unsigned int length;
    char style;

public:

    Traceline(Point& origin, Point& destination);

    inline Point& GetOrigin(){ return origin; }
    inline Point& GetDestination(){ return destination; }
    inline char GetStyle(){ return style; }
    inline unsigned int GetPairLength(){ return length; }

    void SetOrigin(Point& in_point);
    void SetDestination(Point& in_destination);
    void SetStyle(char in_style);
    void SetLength(unsigned int in_length);

    void CalculateTraceLine(void);
    void CalculateBrezenhemTraceLine(void);
};


