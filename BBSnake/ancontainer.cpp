#include "ancontainer.h"
#include <algorithm>

using std::vector;

ANContainer* ANContainer::containerInstance = nullptr;


ANContainer* ANContainer::GetInstance() {
    if(containerInstance == nullptr){
       containerInstance = new ANContainer();
    }
return  containerInstance;
}



void ANContainer::AddToContainer(Figure& in_figure, bool is_interactive) {
    std::vector<Figure>* vec = nullptr;
    if (is_interactive) { vec = &interactive; } else { vec = &not_interactive; }
    if(vec){
            vec->push_back(in_figure);
    }else{
        std::cout<< "Error Pointer in NULL" <<std::endl;
    }
}


void ANContainer::RemoveFromContainer(Figure& in_figure, bool is_interactive) {
    std::vector<Figure>* vec = nullptr;
    if (is_interactive) { vec = &interactive; } else { vec = &not_interactive; }

    if(!(vec->empty())) {
        for(int i = 0; i < vec->size() ; ++i) {
            if ( (*vec)[i].GetId() == in_figure.GetId() ) {
                    std::swap( (*vec)[i], vec->back() );
                    vec->pop_back();
            }
        }
    }
}



/*void ANContainer::AddToContainer(Figure& in_figure, bool is_interactive) {
    std::vector<Figure>* vec = nullptr;
    if (is_interactive) { vec = &interactive; } else { vec = &not_interactive; }
    if(vec){
        if(vec->size() > 0) {
            for (Figure& figure : (*vec)) {
                if (in_figure != figure) {
                    vec->push_back(in_figure);
                }
             }
        } else {
            vec->push_back(in_figure);
         }
    } else {
        std::cout<< "Error Pointer in NULL" <<std::endl;
    }
    std::cout<<vec->size()<<std::endl;
}*/





