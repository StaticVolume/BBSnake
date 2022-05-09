#include "figure.h"


 bool Figure::operator==(Figure& in_figure){
     bool is_true = true;
     for (auto point : pList){
        for (auto in_point : in_figure.GetFigureList()){
            if( (point.GetPointX() != in_point.GetPointX()) || (point.GetPointY() != in_point.GetPointY()) || (point.GetPointStyle() != in_point.GetPointStyle()) ){
                is_true = false;
                    break;
            }
        }
     }
     return is_true;
 }

 bool Figure::operator!=(Figure& in_figure){
     return !(in_figure == *this);
 }

void Figure::FMove(const Direction& dir, unsigned int offset){
     for(auto point : pList){
        point.Move(dir,offset);
     }
}

bool Figure::FisHit(Figure& in_figure){
     for (auto point : pList){
        for (auto in_point : in_figure.GetFigureList()){
            if( point.isHit(in_point) ){
                return true;
            }
        }
    }
     return false;
}
