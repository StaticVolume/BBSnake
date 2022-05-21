#pragma once

#include "figure.h"
#include "ancontainer.h"

class NonActiveFigure : public Figure {
private:
   static unsigned int id_non_active_figures;
public:
    NonActiveFigure() { ANContainer::GetInstance()->AddToContainer(this);  ++id_non_active_figures; }
   ~NonActiveFigure() {ANContainer::GetInstance()->RemoveFromContainer(this); }
};
