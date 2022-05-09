#pragma once

#include "vector"
#include "figure.h"



class ANContainer{

private:

    std::vector<Figure>not_interactive;
    std::vector<Figure>interactive;

public:

    ANContainer() = default;

    inline std::vector<Figure>& GetNotInteractive(){ return not_interactive; };
    inline std::vector<Figure>& GetInteractive(){ return interactive; };

    void AddToContainer( Figure& in_figure, bool is_interactive = false);
    void RemoveFromContainer(Figure& in_figure, bool is_interactive = false);
};
