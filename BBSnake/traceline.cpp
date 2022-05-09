#include "traceline.h"
#include "math.h"

using std::pair;

Traceline::Traceline(Point& in_origin, Point& in_destination):origin{in_origin},destination{in_destination}{

    unsigned int deltax = abs(destination.GetPointX() - origin.GetPointX());
    unsigned int deltay = abs(destination.GetPointY() - origin.GetPointY());
    length = sqrt(abs(pow(deltax,2) + pow(deltay,2)));

}

void Traceline::CalculateTraceLine(void){

    this->GetFigureList().clear();

    if(origin.GetPointX() == destination.GetPointX()){
        style = '|';
         if(destination.GetPointY() > origin.GetPointY()){
            for(int trace_y = (origin.GetPointY()+1); trace_y < destination.GetPointY(); ++trace_y){
                GetFigureList().push_back(Point(destination.GetPointX(), trace_y, style));
            }
         }else{
            for( int trace_y = (destination.GetPointY()+1); trace_y < origin.GetPointY(); ++trace_y){
                GetFigureList().push_back(Point(destination.GetPointX(),trace_y, style));
            }
          }
    }else{
        style = '-';
        if(destination.GetPointX() > origin.GetPointX()){
            for( int trace_x = (origin.GetPointX()+1); trace_x < destination.GetPointX(); ++trace_x){
                GetFigureList().push_back(Point(trace_x, destination.GetPointY(), style));
            }
        }else{
            for( int  trace_x = (destination.GetPointX()+1); trace_x < origin.GetPointX(); ++trace_x){
                GetFigureList().push_back(Point(trace_x,destination.GetPointY(), style));
            }
        }
    }
}

void Traceline::CalculateBrezenhemTraceLine(void){
//need to create
}
