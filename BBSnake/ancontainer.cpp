#include "ancontainer.h"
#include <algorithm>

using std::vector;

void ANContainer::AddToContainer(Figure& in_figure, bool is_interactive){
    std::vector<Figure>* vec = nullptr;
    if (is_interactive) { vec = &interactive; } else { vec = &not_interactive; }
    for (auto figure : *vec){
        if (figure != in_figure){
            vec->push_back(figure);
        }
    }
}

/*void ANContainer::RemoveFromContainer(Figure& in_figure, bool is_interactive){
    std::vector<Figure>* vec = nullptr;
    if (is_interactive) { vec = &interactive; } else { vec = &not_interactive; }
    int vec_size = vec->size();
    std::vector<Figure>::iterator vec_iterator = vec->begin();
    if(!(vec->empty())){
       for (Figure& f : *vec){
           if (f == in_figure){
             //std::remove(vec->begin(),vec->end(), f);
           }
       }
    }
    vec =nullptr;
}*/

