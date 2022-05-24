#include "vwall.h"


Vwall::Vwall(unsigned int in_start_y, unsigned int in_last_y, unsigned int in_w_x, char in_w_style, Color color): start_y{in_start_y}, last_y{in_last_y},w_x{in_w_x}, color{color}, w_style{in_w_style}{
        for(unsigned int y = start_y; y<last_y; ++y){
            GetFigureList().push_back(Point(w_x, y, w_style, color));
        }
}
