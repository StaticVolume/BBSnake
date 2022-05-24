#include "hline.h"

Hline::Hline(unsigned int in_start_x, unsigned int in_last_x, unsigned int in_w_y, char in_w_style, Color color): start_x{in_start_x}, last_x{in_last_x},w_y{in_w_y}, w_style{in_w_style},color{color} {

    for( unsigned int x = start_x; x <= last_x; ++x ) {
        GetFigureList().push_back( Point( x, w_y, w_style, color ) );
    }
}
