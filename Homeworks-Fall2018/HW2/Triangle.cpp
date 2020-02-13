#include<iostream>
#include<fstream>
#include<cmath>
#include "Triangle.h"

using namespace std;

Triangle::Triangle():edge(0),x1_cord(0),y1_cord(0),x2_cord(0),y2_cord(0),x3_cord(0),y3_cord(0){

}

Triangle::Triangle(double init_edge):edge(init_edge),x1_cord(0),y1_cord(0),x2_cord(0),y2_cord(0),x3_cord(0),y3_cord(0){

}

Triangle::Triangle(double init_edge,double init_x1_cord,double init_y1_cord,double init_x2_cord,double init_y2_cord,double init_x3_cord,double init_y3_cord){
	edge=init_edge;
	x1_cord=init_x1_cord;
	y1_cord=init_y1_cord;
	x2_cord=init_x2_cord;
	y2_cord=init_y2_cord;
	x3_cord=init_x3_cord;
	y3_cord=init_y3_cord;
}


double Triangle::get_edge()const{
	return edge;
}

double Triangle::get_x1_cord()const{
	return x1_cord;
}

double Triangle::get_y1_cord()const{
	return y1_cord;
}

double Triangle::get_x2_cord()const{
	return x2_cord;
}

double Triangle::get_y2_cord()const{
	return y2_cord;
}

double Triangle::get_x3_cord()const{
	return x3_cord;
}

double Triangle::get_y3_cord()const{
	return y3_cord;
}

string Triangle::get_tri_color()const{
	return tri_color;
}

void Triangle::set_tri_color(string color){
	tri_color=color;
}

void Triangle::set_edge(double init_edge){
	edge=init_edge;
}

void Triangle::set_x1_cord(double init_x1_cord){
	x1_cord=init_x1_cord; 
}

void Triangle::set_y1_cord(double init_y1_cord){
	y1_cord=init_y1_cord;
}

void Triangle::set_x2_cord(double init_x2_cord){
	x2_cord=init_x2_cord; 
}

void Triangle::set_y2_cord(double init_y2_cord){
	y2_cord=init_y2_cord;
}

void Triangle::set_x3_cord(double init_x3_cord){
	x3_cord=init_x3_cord; 
}

void Triangle::set_y3_cord(double init_y3_cord){
	y3_cord=init_y3_cord;
}


void Triangle::Draw(ofstream& yaz)const{
	yaz<<"<polygon points=\""<<x1_cord<<","<<y1_cord<<" "<<x2_cord<<","<<y2_cord<<" "<<x3_cord<<","<<y3_cord<<"\" fill=\""<<tri_color<<"\" />"<<endl;

}