#include "snake.h"

Snake::Snake(const Point& start, unsigned int length, const Direction& dir, char head_style, char body_style, Color body_color, Color head_color):
start{start}, length{length},dir{dir}, head_style{head_style}, body_style{body_style}, body_color{body_color}, head_color{head_color} {

    Color* col = &body_color;
    for (unsigned int x = 0; x < length; ++x) {
          Point p( start.GetPointX() + x, start.GetPointY(), body_style, *col);
          if(x == (length-2)){
              col  = &head_color;
          }else if (x == (length-1)){
              p.SetPointStyle(head_style);
          }
          p.Move(dir);
          head = p;
          GetFigureList().push_back(p);
    }

   GetTraceLine().SetOrigin(head);
   GetTraceLine().CalculateTraceLineWhithDirection(GetTraceLine().GetOrigin(),dir);



}



void Snake::Move(const Direction& dir, unsigned int offset) {

    this->GetFigureList().front().Delete();

    Point old_head(this->GetFigureList().back());
    Point new_head(this->GetFigureList().back());

    old_head.SetPointStyle(body_style);
    old_head.SetPointColor(body_color);

    this->GetFigureList().pop_back();
    this->GetFigureList().push_back(old_head);

    new_head.Move(dir, offset);

    head = new_head;
    this->GetFigureList().push_back(new_head);

    GetTraceLine().SetOrigin(head);
    GetTraceLine().CalculateTraceLineWhithDirection(GetTraceLine().GetOrigin(),dir);

}



void Snake::DontMove() {

}

void Snake::Feed(){
       GetFigureList().push_back(GetFigureList().back());

}

void Snake::Move_Back__By_Hit(Direction &dir, Display& d, unsigned int offcet) {

std::list<Point> List;

        switch (dir){

        case Direction::RIGTH : {

            for (auto& p : GetFigureList()){
                    Point new_p(p);
                    new_p.Move(Direction::LEFT,offcet);
                    List.push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);

            }
            GetFigureList().clear();
            for (auto& p : List) {
                    Point new_p(p);
                    GetFigureList().push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);
                    d.DrawPoint(new_p);
                    head = GetFigureList().back();
            }
            List.clear();
         }

                break;

        case Direction::LEFT : {

            for (auto& p : GetFigureList()){
                    Point new_p(p);
                    new_p.Move(Direction::RIGTH,offcet);
                    List.push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);

            }
            GetFigureList().clear();
            for (auto& p : List) {
                    Point new_p(p);
                    GetFigureList().push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);
                    d.DrawPoint(new_p);
                    head = GetFigureList().back();
            }
            List.clear();
         }


                break;

        case Direction::UP : {

            for (auto& p : GetFigureList()){
                    Point new_p(p);
                    new_p.Move(Direction::DOWN,offcet);
                    List.push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);

            }
            GetFigureList().clear();
            for (auto& p : List) {
                    Point new_p(p);
                    GetFigureList().push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);
                    d.DrawPoint(new_p);
                    head = GetFigureList().back();
            }
            List.clear();
         }


                break;

        case Direction::DOWN : {


            for (auto& p : GetFigureList()){
                    Point new_p(p);
                    new_p.Move(Direction::UP,offcet);
                    List.push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);

            }
            GetFigureList().clear();
            for (auto& p : List) {
                    Point new_p(p);
                    GetFigureList().push_back(new_p);
                    p.Delete();
                    d.DrawPoint(p);
                    d.DrawPoint(new_p);
                    head = GetFigureList().back();
            }
            List.clear();
         }


                break;
        }

        GetTraceLine().SetOrigin(head);
        GetTraceLine().CalculateTraceLineWhithDirection(GetTraceLine().GetOrigin(),dir);


}


//костыль удаления(очистки List с точками snake). Причина создания - некорректная отрисовка обьекта после вызова функции DrawFigure класса Display
void Snake::ClearAfterMoveTraceLine(Display& d){
    GetTraceLine().ClearAfterMove();
    d.DrawFigure(GetTrace());
    GetTraceLine().GetFigureList().clear();
}
void Snake::ClearAfterMove(){
     GetFigureList().pop_front();


}
