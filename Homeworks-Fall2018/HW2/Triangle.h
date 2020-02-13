#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<fstream>
#include<string>

using namespace std;

class Triangle{
	public:	
		//constructors
		Triangle();
		Triangle(double init_edge);
		Triangle(double init_edge,double init_x1_cord,double init_y1_cord,double init_x2_cord,double init_y2_cord,double init_x3_cord,double init_y3_cord);
		//getter
		double get_edge()const;
		double get_x1_cord()const;
		double get_y1_cord()const;
		double get_x2_cord()const;
		double get_y2_cord()const;
		double get_x3_cord()const;
		double get_y3_cord()const;
		string get_tri_color()const;
		//setter
		void set_edge(double init_edge);
		void set_x1_cord(double init_x1_cord);
		void set_y1_cord(double init_y1_cord);
		void set_x2_cord(double init_x2_cord);
		void set_y2_cord(double init_y2_cord);
		void set_x3_cord(double init_x3_cord);
		void set_y3_cord(double init_y3_cord);
		void set_tri_color(string color);
		//Draw
		void Draw(ofstream& yaz)const;
	private:
		double edge;
		double x1_cord;
		double y1_cord;
		double x2_cord;
		double y2_cord;
		double x3_cord;
		double y3_cord;

		string tri_color;
};


#endif