#include<iostream>
#include<fstream>
#include "Circle.h"

using namespace std;

Circle::Circle():radius(0),x_cord(0),y_cord(0){

}

Circle::Circle(double init_radius):radius(init_radius),x_cord(0),y_cord(0){

}

Circle::Circle(double init_radius,double init_x_cord,double init_y_cord):radius(init_radius),x_cord(init_x_cord),y_cord(init_y_cord){

}

double Circle::get_radius()const{
	return radius;
}

double Circle::get_x_cord()const{
	return x_cord;
}

double Circle::get_y_cord()const{
	return y_cord;
}

string Circle::get_circ_color()const{
	return circ_color;
}

void Circle::set_circ_color(string color){
	circ_color=color;
}	

void Circle::set_radius(double init_radius){
	radius=init_radius;
}

void Circle::set_x_cord(double init_x_cord){
	x_cord=init_x_cord;
}

void Circle::set_y_cord(double init_y_cord){
	y_cord=init_y_cord;
}

void Circle::Draw(ofstream& yaz)const{
	yaz<<"<circle cx=\""<<x_cord<<"\" cy=\""<<y_cord<<"\" r=\""<<radius<<"\" fill=\""<<circ_color<<"\" />"<<endl;

}




