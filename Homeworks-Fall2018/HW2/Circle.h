#ifndef CIRCLE_H
#define CIRCLE_H

#include<fstream>
#include<string>
using namespace std;

class Circle{
	public:
		//constructors
		Circle();
		Circle(double init_radius);
		Circle(double init_radius,double init_x_cord,double init_y_cord);
		//Getter methods
		double get_radius()const;
		double get_x_cord()const;
		double get_y_cord()const;
		string get_circ_color()const;
		//setter methods
		void set_radius(double init_radius);
		void set_x_cord(double init_x_cord);
		void set_y_cord(double init_y_cord);
		void set_circ_color(string color);
		//Draw
		void Draw(ofstream& yaz)const;
	private:
		double radius;
		double x_cord;
		double y_cord;

		string circ_color;
};




#endif