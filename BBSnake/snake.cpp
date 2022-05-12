#include "snake.h"

Snake::Snake(const Point start, unsigned int length, const Direction dir, char head_style, char body_style, Color body_color, Color head_color):
start{start}, length{length}, dir{dir}, head_style{head_style}, body_style{body_style}, body_color{body_color}, head_color{head_color} {

    Color* col = &body_color;
    for (unsigned int x = 0; x < length; ++x) {
          Point p( start.GetPointX() + x, start.GetPointY(), body_style, *col);
          if(x == (length-2)){
              col  = &head_color;
          }else if (x == (length-1)){
              p.SetPointStyle(head_style);
          }
          p.Move(dir);
          this->GetFigureList().push_back(p);

    }

   ANContainer::GetInstance()->AddToContainer(*this);
   Figure::SetId();
}

void Snake::Move(const Direction& dir, unsigned int offset) {
    this->GetFigureList().front().Delete();
     //d.DrawPoint(this->GetFigureList().front());
    //this->GetFigureList().pop_front();

    Point head(this->GetFigureList().back());
    Point new_head(this->GetFigureList().back());

    head.SetPointStyle(body_style);
    head.SetPointColor(body_color);

    this->GetFigureList().pop_back();
    this->GetFigureList().push_back(head);
    new_head.Move(dir,1);


    this->GetFigureList().push_back(new_head);
}

//костыль удаления(очистки List с точками snake). Причина создания - некорректная отрисовка обьекта после вызова функции DrawFigure класса Display
void Snake::ClearAfterMove(){
    GetFigureList().pop_front();
}
