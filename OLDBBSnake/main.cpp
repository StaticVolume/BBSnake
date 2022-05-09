#include <iostream>
#include <list>
#include <ncurses.h>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cstring>
using namespace std;

enum Direction{UP,DOWN,LEFT,RIGTH};

class Display{
	private:
		int d_rows,d_cols;
		char stop_button;
		bool check_cursor;
	public:
		Display(char stop = 'p', bool input_check_cursor = false) : stop_button(stop),check_cursor(input_check_cursor){}

		int GetRows(){return d_rows;}
		int GetCols(){return d_cols;}
		
		void DWinInit(void){
		initscr();
		noecho();
		curs_set(check_cursor);
		getmaxyx(stdscr,d_rows,d_cols);
		}

		void DWinClose(void){
		refresh();
		while (getch()!= stop_button){
		refresh();
		getch();
		}
		endwin();
		}		
};


class Point{
	private:
		int p_x, p_y;
		char style;
	public:
		Point(){}
		Point (int x_input,int y_input , char style_input): p_x(x_input),p_y(y_input),style(style_input) {}
		Point (const Point& point_input): p_x(point_input.p_x),p_y(point_input.p_y),style(point_input.style){}
		Point& operator= (const Point& point_input){
			p_x = point_input.p_x;
			p_y = point_input.p_y;
			style = point_input.style;
			return *this;
		}
		int GetPointX(){return p_x;}
		int GetPointY(){return p_y;}
		void SetPointX(int input_x){p_x = input_x;}
		void SetPointY(int input_y){p_y = input_y;}

		char GetPointStyle(){return style;}
		void SetPointStyle(char input_style){style = input_style;}

		void PDraw(void){
		move(p_y, p_x);
		addch(style);
		refresh();
		}


		void PMove(const Direction& dir, int  offset){
			if (dir == Direction::UP){
				p_y -= offset;
			}else if(dir == Direction::DOWN ){
				p_y+= offset;
			}else if (dir == Direction::LEFT){
				p_x -= offset;
			}else if (dir == Direction::RIGTH){
				p_x += offset;
			}
		}

		void PDelete(void){
			style =' ';
			PDraw();
		}

		bool PHit(Point& input_point){
			if ((p_x == input_point.GetPointX()) && (p_y == input_point.GetPointY())){
				return true;
			}else {
				return false;
			}
		}

};

class Figure{
	protected:
		list<Point> pList;
	public:		
		void FDraw(void){
			for(auto p : pList){
				p.PDraw();		
			}	
	 	}

		list<Point>GetFList(void){
			return pList;
		}
	
		bool FigureHit(list<Point>& input_figure_list){
			bool is_hit = false;
			for (auto& p : pList){
				for (auto& input_p : input_figure_list){
					if (p.PHit(input_p)){
						is_hit = true;
						break;
					}
				}			
			}
		 return is_hit;
		}
		
};


class VecContainer{
	private : 
		vector<Figure>not_active;
		vector<Figure>active;
		 int length;

	public:
		VecContainer(){}		
		vector<Figure> GetNotActive(){
		return not_active;
		}
		vector<Figure> GetActive(){
		return active;
		}

	  //	void  ExPushInNotActive(int count, Figure* figure, ...){
	//		length= count;
	//		for (int x = 0; x<length ; ++x){
	//			not_active.push_back(*figure);
	//			figure++;
	//		}

	//	}
		
		void PushInNotActive(const Figure& figure){
			//	auto element = find(Container.cbegin(), Container.cend(),figure);
			  //   if(element == Container.cend()){
				not_active.push_back(figure);
				}
		 	//	}

		void PushInActive(const Figure& figure){
                        //      auto element = find(Container.cbegin(), Container.cend(),figure);
                          //   if(element == Container.cend()){
                                active.push_back(figure);
                                }
                        //      }

};


class HarWall: public Figure{
	private:	
	int	x_left, x_rigth, y;
	char	style;

	public:
		HarWall(int x_input_start, int x_input_end, int y_input, char input_style = '*'): x_left(x_input_start), x_rigth(x_input_end), y(y_input) , style(input_style){
			for (int x = x_left; x <= x_rigth; ++x){
                        pList.push_back(Point(x,y,style));
											//	cout << " X HARWALL = " << x << "  Y HARWALL = " << y << "  STYLE HARWALL  " << style << endl;
			}
		}

		

};

class VertWall: public Figure{
        private:
        int     y_down, y_up, x;
        char    style;

        public:
	VertWall(int y_input_start, int y_input_end, int x_input, char input_style = '*'): y_down(y_input_start), y_up(y_input_end), x(x_input) , style(input_style){
			for (int y = y_down; y <= y_up; ++y){
                        pList.push_back(Point(x,y,style));
									                  //      cout << " X HARWALL = " << x << "  Y HARWALL = " << y << "  STYLE HARWALL  " << style << endl;
                        }
                }
};


class Eat: public Figure{
	private:
	Point* eat_coord = nullptr;
	int w_width;
	int w_heigth;
	char eat_style;
	public:
	Eat (int input_width, int input_heigth, char input_style): w_width(input_width), w_heigth(input_heigth), eat_style(input_style){
		eat_coord = new Point ((2 + rand() % (w_width - 2)),(2 + rand() % (w_heigth -2)),eat_style);
		pList.push_back(*eat_coord);
	}
	Point GetEatCoord(){
		return *eat_coord;
	}
	~Eat(){
	delete eat_coord;
	}
};


class Snake: public Figure{
	private:
	Direction dir;
	int length, x_start, y_start, offset;
	char style_body, style_head, key;
	public:

	Snake(Direction input_dir,int x_input_start,int y_input_start, int input_length, char input_body_style,char input_head_style = '#'):dir(input_dir),x_start(x_input_start),
		y_start(y_input_start),length(input_length), style_body(input_body_style),style_head(input_head_style){

		for (int num = 0 ; num < length; ++num){
			Point sn(x_start,y_start,style_body);
		sn.PMove(dir,num);
		pList.push_back(sn);
	}
	if ((pList.size()-(length-1)) == 1){
		Point head(x_start,y_start,style_head);
		head.PMove(dir,length);
		pList.push_back(head);
	}
		
}

bool SnakeHit(const list<Point>& input_figure_list){
		bool is_hit = false;
			for (auto input_p : input_figure_list){
			 is_hit = pList.back().PHit(input_p);
			  if(is_hit == true) {break;} 
			}      
	 return is_hit;
      }

void SMove(const Direction& input_dir, int  input_offset){ 
	dir = input_dir;
	offset = input_offset;
	Point last(pList.front());
	pList.pop_front();
	Point head(GetNextPoint());
	pList.push_back(head);
	last.PDelete();
	head.PDraw();
	}

Point GetNextPoint(void){
	Point head(pList.back());
	Point result(head);
	head.SetPointStyle(style_body);
	head.PDraw();
	result.PMove(dir,offset);
	return result;
}

Direction DirByKey(const char& input_key ){

if (input_key == 'd'){
	dir = Direction::RIGTH;
}else if(input_key == 'a' ){
	dir = Direction::LEFT;
}else if(input_key == 'w'){
	dir = Direction::UP;
}if (input_key == 's'){
	dir = Direction::DOWN;
}
return dir;
}	


bool SnakeHitVecCont(vector<Figure> input_vec){
	bool is_hit = false;
	for (auto& figure : input_vec){
	 is_hit = SnakeHit(figure.GetFList());
	 if (is_hit == true) {break;}
	}
	 return is_hit;
      }

	void Eating(vector<Figure> input_eat){
		for (auto& f : input_eat){
		for	(auto& p : f.GetFList() ){
		pList.push_front(p);
		}
		}
}

};


int main(void){
Display D;
D.DWinInit();
Direction dir;

VecContainer* vec = new(VecContainer);
HarWall wall1(0,(D.GetCols()-1), 0 ,'#');
HarWall wall2(0,(D.GetCols()-1),(D.GetRows()-1),'#');
VertWall wall3(0,(D.GetRows()-1),0,'+');
VertWall wall4(0,(D.GetRows()-1),(D.GetCols()-1),'+');
Eat eat1(D.GetCols()-1,D.GetRows()-1,'$');	
Snake sn(RIGTH,15,15,1,'#','@');


vec->PushInNotActive(wall1);
	vec->PushInNotActive(wall2);
	vec->PushInNotActive(wall3);
	vec->PushInNotActive(wall4);
	vec->PushInActive(eat1);


	eat1.FDraw();	
        wall1.FDraw();
        wall2.FDraw();
        wall3.FDraw();
        wall4.FDraw();
        sn.FDraw();


	while (true){

	dir = sn.DirByKey(getch());
	if(!(sn.SnakeHitVecCont(vec->GetNotActive()))){
		sn.SMove(dir,1);
		if(sn.SnakeHitVecCont(vec->GetActive())){
			sn.Eating(vec->GetActive());
			vec->GetActive().clear();
			Eat eat1(D.GetCols()-1,D.GetRows()-1,'$');
			vec->PushInActive(eat1);
			eat1.FDraw();
		}
		}else{
		const char *mesg = "FINGER B ASS POPAL! ";
                mvwprintw(stdscr, D.GetRows() / 2, (D.GetCols() - strlen(mesg)) / 2, "%s", mesg);
		break;
		}	
	}

	delete vec;	
	D.DWinClose();
	return 0;
}
