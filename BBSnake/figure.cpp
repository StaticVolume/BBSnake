#include "figure.h"

 unsigned int Figure::id_all_figures = 0;

 bool Figure::operator==( Figure& in_figure) {
     bool is_true = true;
     if(pList.size() == in_figure.GetFigureList().size()) {

        for (auto& in_point : in_figure.GetFigureList()) {
            for ( auto& point : pList ) {
                if( point != in_point ) {
                    is_true = false;
                        goto END;
                }
            }
        }
    }else{
         is_true = false;
     }
 END:
 return is_true;
 }

 bool Figure::operator!=(Figure& in_figure) {
     return !(in_figure == *this);
 }

void Figure::FMove(const Direction& dir, unsigned int offset) {
     for(auto point : pList) {
        point.Move(dir,offset);
     }
}

bool Figure::IsHit(Figure& in_figure) {
     for (auto point : pList) {
        for (auto in_point : in_figure.GetFigureList()) {
            if( point.isHit(in_point) ) {
                return true;
            }
        }
    }
     return false;
}

void Figure::SetId() {
    ++id_all_figures;
}



