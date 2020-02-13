#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using namespace std;



class ComposedShape{
	public:
		//constructors
		ComposedShape(Rectangle mr,Rectangle sr);
		ComposedShape(Rectangle mr,Circle sr);
		ComposedShape(Rectangle mr,Triangle sr);
		ComposedShape(Circle mr,Rectangle sr);
		ComposedShape(Circle mr,Circle sr);
		ComposedShape(Circle mr,Triangle sr);
		ComposedShape(Triangle mr,Rectangle sr);
		ComposedShape(Triangle mr,Circle sr);
		ComposedShape(Triangle mr,Triangle sr);
		//optimalFit
		void OptimalFit(Rectangle mr,Rectangle sr);
		void OptimalFit(Rectangle mr,Circle sr);
		void OptimalFit(Rectangle mr,Triangle sr);
		void OptimalFit(Circle mr,Rectangle sr);
		void OptimalFit(Circle mr,Circle sr);
		void OptimalFit(Circle mr,Triangle sr);
		void OptimalFit(Triangle mr,Rectangle sr);
		void OptimalFit(Triangle mr,Circle sr);
		void OptimalFit(Triangle mr,Triangle sr);
		//getter vectors
		vector<Rectangle> get_vect_rect()const;
		vector<Circle> get_vect_circ()const;
		vector<Triangle> get_vect_tri()const;
		//getter shapes
		Rectangle get_main_rect()const;
		Rectangle get_small_rect()const;
		Circle get_main_circ()const;
		Circle get_small_circ()const;
		Triangle get_main_tri()const;
		Triangle get_small_tri()const;

		//Draw Container shapes
		void DrawContainerRectangle(ofstream& yaz)const;
		void DrawContainerCircle(ofstream& yaz)const;
		void DrawContainerTriangle(ofstream& yaz)const;
		//Draw inner shapes
		void DrawInnerRectangle(ofstream& yaz)const;
		void DrawInnerCircle(ofstream& yaz)const;
		void DrawInnerTriangle(ofstream& yaz)const;
	private:
		Rectangle main_r,small_r;
		Circle main_c,small_c;
		Triangle main_t,small_t;

		vector<Rectangle> r_vector;
		vector<Circle> c_vector;
		vector<Triangle> t_vector;
};

#endif