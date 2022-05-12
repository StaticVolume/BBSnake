#pragma once

#include "vector"
#include "figure.h"
#include <iostream>


class ANContainer {

private:

    ANContainer() {};

   static ANContainer* containerInstance;
   std::vector<Figure> not_interactive;
   std::vector<Figure> interactive;


public:

    static ANContainer* GetInstance();

    ANContainer( const ANContainer& ancontainer ) = delete;
    ANContainer& operator=( const ANContainer& ancotainer ) = delete;


    inline std::vector<Figure>& GetNotInteractive(){ return not_interactive; };
    inline std::vector<Figure>& GetInteractive(){ return interactive; };

    void AddToContainer( Figure& in_figure, bool is_interactive = false);
    void RemoveFromContainer(Figure& in_figure, bool is_interactive = false);
};
