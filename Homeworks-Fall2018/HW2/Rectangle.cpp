#include<iostream>
#include<fstream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle():width(0),height(0),x_cord(0),y_cord(0){

}

Rectangle::Rectangle(double init_width):width(init_width),height(0),x_cord(0),y_cord(0){

}

Rectangle::Rectangle(double init_width,double init_height):width(init_width),height(init_height),x_cord(0),y_cord(0){

}

Rectangle::Rectangle(double init_width,double init_height,double init_x_cord,double init_y_cord):width(init_width),height(init_height),x_cord(init_x_cord),y_cord(init_y_cord){

}

double Rectangle::get_width()const{
	return width;
}

double Rectangle::get_height()const{
	return height;
}

double Rectangle::get_x_cord()const{
	return x_cord;
}

double Rectangle::get_y_cord()const{
	return y_cord;
}

string Rectangle::get_rect_color()const{
	return rect_color;
}

void Rectangle::set_rect_color(string color){
	rect_color=color;
}

void Rectangle::set_width(double init_width){
	width=init_width;
}

void Rectangle::set_height(double init_height){
	height=init_height;
}

void Rectangle::set_x_cord(double init_x_cord){
	x_cord=init_x_cord;
}

void Rectangle::set_y_cord(double init_y_cord){
	y_cord=init_y_cord;
}

void Rectangle::Draw(ofstream& yaz)const{
	yaz<<"<rect x=\""<<x_cord<<"\" y=\""<<y_cord<<"\" width=\""<< width <<"\" height=\""<<height<<"\" fill=\""<<rect_color<<"\"/> "<<endl;
}







