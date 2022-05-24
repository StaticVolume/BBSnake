#pragma once

#include "non_active_figure.h"
#include "hline.h"
#include "vline.h"
#include "string"
#include "vector"
#include "traceline.h"


class Enemy : public ActiveFigure {

private:
    std::vector<Figure> carcas;
    std::vector<std::string> phrases{"Oh Epta", "Ya tebya seychas uyabuu", "Idi suda nahuy"};
    unsigned int life_count = 3;
    Color color;
    char style;
    Traceline trace;

public:

    Enemy(char style = '#', Color color = Color::RED );

    std::vector<Figure>& GetCarcas() { return carcas; };

    ~Enemy(){};

};
