#include "traceline.h"
#include "math.h"



Traceline::Traceline(const Point& in_origin,const  Point& in_destination):origin{in_origin},destination{in_destination}{

    unsigned int deltax = abs(destination.GetPointX() - origin.GetPointX());
    unsigned int deltay = abs(destination.GetPointY() - origin.GetPointY());
    length = sqrt(abs(pow(deltax,2) + pow(deltay,2)));
}


void Traceline::SetOrigin(Point& in_point) {
    origin = in_point;
}

void  Traceline::SetIsHit(bool ishit) {
    ishit = ishit;
}

void Traceline::CalculateTraceLineWhithDirection(const Point& origin,const Direction& dir) {
    int numbers_of_point = 0;
    int length_to_point = 0;

    switch(dir){
    case Direction::RIGTH : {
            for(auto figure : ANContainer::GetInstance()->GetNotInteractive()) {

                for(auto& point : figure->GetFigureList()){

                    if(  (origin.GetPointY() == point.GetPointY()) && (point.GetPointX() > origin.GetPointX())  ) {

                        ++numbers_of_point;

                        if(  (numbers_of_point > 1) && (length_to_point > (point.GetPointX() - origin.GetPointX()))  ) {

                                length_to_point = point.GetPointX() - origin.GetPointX();
                                 destination = point;
                        } else {

                            length_to_point = point.GetPointX() - origin.GetPointX();
                            destination = point;
                        }
                    }
                }
            }
        }break;

    case Direction::LEFT : {
        for(auto figure : ANContainer::GetInstance()->GetNotInteractive()) {

            for(auto point : figure->GetFigureList()) {

                if(  (origin.GetPointY() == point.GetPointY()) && (origin.GetPointX() > point.GetPointX())  ) {

                    ++numbers_of_point;

                    if(  (numbers_of_point > 1) && (length_to_point > (origin.GetPointX() - point.GetPointX()))  ) {

                            length_to_point = origin.GetPointX() - point.GetPointX();
                             destination = point;

                    } else {

                        length_to_point = origin.GetPointX() - point.GetPointX();
                         destination = point;
                    }

                }
            }
        }
        }break;

    case Direction::UP : {
        for(auto figure : ANContainer::GetInstance()->GetNotInteractive()) {

            for(auto point : figure->GetFigureList()) {

                if(  (origin.GetPointX() == point.GetPointX()) && (origin.GetPointY() > point.GetPointY())  ) {

                    ++numbers_of_point;

                    if(  (numbers_of_point > 1) && (length_to_point > (origin.GetPointY() - point.GetPointY()))  ) {

                            length_to_point = origin.GetPointY() - point.GetPointY();
                             destination = point;

                    } else {

                        length_to_point = origin.GetPointY() - point.GetPointY();
                         destination = point;
                    }

                }
            }
        }
        }break;

    case Direction::DOWN : {
        for(auto figure : ANContainer::GetInstance()->GetNotInteractive()) {

            for(auto point : figure->GetFigureList()) {

                if(  (origin.GetPointX() == point.GetPointX()) && (point.GetPointY() > origin.GetPointY())  ) {

                    ++numbers_of_point;
                    if(  (numbers_of_point > 1) && (length_to_point > (point.GetPointY() - origin.GetPointY()))  )
                    {
                            length_to_point = point.GetPointY() - origin.GetPointY();
                             destination = point;

                    } else {

                        length_to_point = point.GetPointY() - origin.GetPointY();
                         destination = point;
                    }

                }
            }
        }
        }break;
    }
}

void Traceline::BuildTrace(void){
    GetFigureList().clear();

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

void Traceline::ClearAfterMove() {
    for (auto& point : GetFigureList()){
        point.Delete();
    }
}

void Traceline::CalculateBrezenhemTraceLine(void) {
//need to create
}
