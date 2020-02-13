#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include<fstream>
#include<string>
using namespace std;

class Rectangle{
	public:
		//Constructors 
		Rectangle();
		Rectangle(double init_width);
		Rectangle(double init_width,double init_height);
		Rectangle(double init_width,double init_height,double init_x_cord,double init_y_cord);
		//Getter methods
		double get_width()const;
		double get_height()const;
		double get_x_cord()const;
		double get_y_cord()const;
		string get_rect_color()const;
		//Setter Methods
		void set_width(double init_width);
		void set_height(double init_height);
		void set_x_cord(double init_x_cord);
		void set_y_cord(double init_y_cord);
		void set_rect_color(string color);
		//Draw
		void Draw(ofstream& yaz)const;
	private:
		double width;
		double height;
		double x_cord;
		double y_cord;

		string rect_color;	
};

#endif