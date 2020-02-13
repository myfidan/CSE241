#include<iostream>
#include<fstream>
#include<cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"

using namespace std;

int main(){
	ofstream yaz;
 	yaz.open ("hw2.svg");
 	yaz<<"<svg>"<<endl;
 	int choose;
 	Rectangle rect[4]={{100,200,0,0},{10,20},{20,20},{}};
 	Circle circ[4]={{200,200,200},{15},{50},{}};
 	Triangle tri[4]={{300,150,0,300,150*sqrt(3),0,150*sqrt(3)},{10},{20},{}};

 	
 	cout<<endl<<"********************************************************"<<endl;
 	cout<<"1-)Rectangle-Rectangle"<<endl;
 	cout<<"2-)Rectangle-Circle"<<endl;
 	cout<<"3-)Rectangle-Triangle"<<endl;
 	cout<<"4-)Circle-Rectangle"<<endl;
 	cout<<"5-)Circle-Circle"<<endl;
 	cout<<"6-)Circle-Triangle"<<endl;
 	cout<<"7-)Triangle-Rectangle"<<endl;
 	cout<<"8-)Triangle-Circle"<<endl;
 	cout<<"9-)Triangle-Triangle"<<endl;
 	cout<<"Choose Your Combination:";
 	cin>>choose;

 	if(choose==1){

	 	cout<<endl<<"*****Container Rectangle - Inner Rectangle*****"<<endl;//RECTANGLE-RECTANGLE

	 	cout<<"Main Rectangle width="<<rect[0].get_width()<<" height="<<rect[0].get_height()
	 	<<" x_coordinant="<<rect[0].get_x_cord()<<" y_coordinant="<<rect[0].get_y_cord()<<endl;

	 	cout<<"Inner Rectangle width="<<rect[1].get_width()<<" height="<<rect[1].get_height()
	 	<<" x_coordinant="<<rect[1].get_x_cord()<<" y_coordinant="<<rect[1].get_y_cord()<<endl;
	 	
	 	rect[0].set_rect_color("red");
	 	rect[1].set_rect_color("green");
	 	ComposedShape RR(rect[0],rect[1]);
	 	RR.OptimalFit(rect[0],rect[1]);
	 	RR.DrawContainerRectangle(yaz);
	 	RR.DrawInnerRectangle(yaz);
	
 	}
 	else if(choose==2){
 		cout<<endl<<"*****Container Rectangle - Inner Circle*****"<<endl;//RECTANGLE-CIRCLE

	 	cout<<"Main Rectangle width="<<rect[0].get_width()<<" height="<<rect[0].get_height()
	 	<<" x_coordinant="<<rect[0].get_x_cord()<<" y_coordinant="<<rect[0].get_y_cord()<<endl;

	 	cout<<"InnerCircle radius="<<circ[1].get_radius()<<" x_coordinant="<<circ[1].get_x_cord()
	 	<<" y_coordinant="<<circ[1].get_y_cord()<<endl;

	 	rect[0].set_rect_color("red");
	 	circ[1].set_circ_color("green");
	 	ComposedShape RC(rect[0],circ[1]);
	 	RC.OptimalFit(rect[0],circ[1]);
	 	RC.DrawContainerRectangle(yaz);
	 	RC.DrawInnerCircle(yaz);
 	}
 	else if(choose==3){
 		cout<<endl<<"*****Container Rectangle - Inner Triangle*****"<<endl;//RECTANGLE-TRIANGLE

	 	cout<<"Main Rectangle width="<<rect[0].get_width()<<" height="<<rect[0].get_height()
	 	<<" x_coordinant="<<rect[0].get_x_cord()<<" y_coordinant="<<rect[0].get_y_cord()<<endl;


	 	cout<<"Inner Triangle edge="<<tri[1].get_edge()<<" x1_cord="<<tri[1].get_x1_cord()
	 	<<" y1_cord="<<tri[1].get_y1_cord()<<" x2_cord="<<tri[1].get_x2_cord()<<" y2_cord="
	 	<<tri[1].get_y2_cord()<<" x3_cord="<<tri[1].get_x3_cord()<<" y3_cord="<<tri[1].get_y3_cord()<<endl;

	 	rect[0].set_rect_color("red");
	 	tri[1].set_tri_color("green");
	 	ComposedShape RT(rect[0],tri[1]);
	 	RT.OptimalFit(rect[0],tri[1]);
	 	RT.DrawContainerRectangle(yaz);
	 	RT.DrawInnerTriangle(yaz);
 	}
 	else if(choose==4){
 		cout<<endl<<"*****Container Circle - Inner Rectangle*****"<<endl;//CIRCLE-RECTANGLE

	 	cout<<"Main Circle radius="<<circ[0].get_radius()<<" x_coordinant="<<circ[0].get_x_cord()
	 	<<" y_coordinant="<<circ[0].get_y_cord()<<endl;

	 	cout<<"Inner Rectangle width="<<rect[1].get_width()<<" height="<<rect[1].get_height()
	 	<<" x_coordinant="<<rect[1].get_x_cord()<<" y_coordinant="<<rect[1].get_y_cord()<<endl;

	 	circ[0].set_circ_color("red");
	 	rect[1].set_rect_color("green");
	 	ComposedShape CR(circ[0],rect[1]);
	 	CR.OptimalFit(circ[0],rect[1]);
	 	CR.DrawContainerCircle(yaz);
	 	CR.DrawInnerRectangle(yaz);
 	}
 	else if(choose==5){
 		cout<<endl<<"*****Container Circle - Inner Circle*****"<<endl;//CIRCLE-CIRCLE

	 	cout<<"Main Circle radius="<<circ[0].get_radius()<<" x_coordinant="<<circ[0].get_x_cord()
	 	<<" y_coordinant="<<circ[0].get_y_cord()<<endl;

	 	cout<<"InnerCircle radius="<<circ[1].get_radius()<<" x_coordinant="<<circ[1].get_x_cord()
	 	<<" y_coordinant="<<circ[1].get_y_cord()<<endl;

	 	circ[0].set_circ_color("red");
	 	circ[1].set_circ_color("green");
	 	ComposedShape CC(circ[0],circ[1]);
	 	CC.OptimalFit(circ[0],circ[1]);
	 	CC.DrawContainerCircle(yaz);
	 	CC.DrawInnerCircle(yaz);
 	}
 	else if(choose==6){
 		cout<<endl<<"*****Container Circle - Inner Triangle*****"<<endl;//CIRCLE-TRIANGLE

	 	cout<<"Main Circle radius="<<circ[0].get_radius()<<" x_coordinant="<<circ[0].get_x_cord()
	 	<<" y_coordinant="<<circ[0].get_y_cord()<<endl;

	 	cout<<"Inner Triangle edge="<<tri[1].get_edge()<<" x1_cord="<<tri[1].get_x1_cord()
	 	<<" y1_cord="<<tri[1].get_y1_cord()<<" x2_cord="<<tri[1].get_x2_cord()<<" y2_cord="
	 	<<tri[1].get_y2_cord()<<" x3_cord="<<tri[1].get_x3_cord()<<" y3_cord="<<tri[1].get_y3_cord()<<endl;

	 	circ[0].set_circ_color("red");
	 	tri[1].set_tri_color("green");
	 	ComposedShape CT(circ[0],tri[1]);
	 	CT.OptimalFit(circ[0],tri[1]);
	 	CT.DrawContainerCircle(yaz);
	 	CT.DrawInnerTriangle(yaz);
	 }
	 else if(choose==7){
	 	cout<<endl<<"*****Container Triangle - Inner Rectangle*****"<<endl;//TRIANGLE-RENTANGLE

	 	cout<<"Main Triangle edge="<<tri[0].get_edge()<<" x1_cord="<<tri[0].get_x1_cord()
	 	<<" y1_cord="<<tri[0].get_y1_cord()<<" x2_cord="<<tri[0].get_x2_cord()<<" y2_cord="
	 	<<tri[0].get_y2_cord()<<" x3_cord="<<tri[0].get_x3_cord()<<" y3_cord="<<tri[0].get_y3_cord()<<endl;

	 	cout<<"Inner Rectangle width="<<rect[1].get_width()<<" height="<<rect[1].get_height()
	 	<<" x_coordinant="<<rect[1].get_x_cord()<<" y_coordinant="<<rect[1].get_y_cord()<<endl;

	 	tri[0].set_tri_color("red");
	 	rect[1].set_rect_color("green");
	 	ComposedShape TR(tri[0],rect[1]);
	 	TR.OptimalFit(tri[0],rect[1]);
	 	TR.DrawContainerTriangle(yaz);
	 	TR.DrawInnerRectangle(yaz);
	 }
 	else if(choose==8){
 		cout<<endl<<"*****Container Triangle - Inner Circle*****"<<endl;//TRIANGLE-CIRCLE

	 	cout<<"Main Triangle edge="<<tri[0].get_edge()<<" x1_cord="<<tri[0].get_x1_cord()
	 	<<" y1_cord="<<tri[0].get_y1_cord()<<" x2_cord="<<tri[0].get_x2_cord()<<" y2_cord="
	 	<<tri[0].get_y2_cord()<<" x3_cord="<<tri[0].get_x3_cord()<<" y3_cord="<<tri[0].get_y3_cord()<<endl;


	 	cout<<"InnerCircle radius="<<circ[1].get_radius()<<" x_coordinant="<<circ[1].get_x_cord()
	 	<<" y_coordinant="<<circ[1].get_y_cord()<<endl;

	 	tri[0].set_tri_color("red");
	 	circ[1].set_circ_color("green");
	 	ComposedShape TC(tri[0],circ[1]);
	 	TC.OptimalFit(tri[0],circ[1]);
	 	TC.DrawContainerTriangle(yaz);
	 	TC.DrawInnerCircle(yaz);
	 }
	 else if(choose==9){
	 	cout<<endl<<"*****Container Triangle - Inner Triangle*****"<<endl;//TRIANGLE-TRIANGLE

	 	cout<<"Main Triangle edge="<<tri[0].get_edge()<<" x1_cord="<<tri[0].get_x1_cord()
	 	<<" y1_cord="<<tri[0].get_y1_cord()<<" x2_cord="<<tri[0].get_x2_cord()<<" y2_cord="
	 	<<tri[0].get_y2_cord()<<" x3_cord="<<tri[0].get_x3_cord()<<" y3_cord="<<tri[0].get_y3_cord()<<endl;

	 	cout<<"Inner Triangle edge="<<tri[1].get_edge()<<" x1_cord="<<tri[1].get_x1_cord()
	 	<<" y1_cord="<<tri[1].get_y1_cord()<<" x2_cord="<<tri[1].get_x2_cord()<<" y2_cord="
	 	<<tri[1].get_y2_cord()<<" x3_cord="<<tri[1].get_x3_cord()<<" y3_cord="<<tri[1].get_y3_cord()<<endl;

	 	tri[0].set_tri_color("red");
	 	tri[1].set_tri_color("green");
	 	ComposedShape TT(tri[0],tri[1]);
	 	TT.OptimalFit(tri[0],tri[1]);
	 	TT.DrawContainerTriangle(yaz);
	 	TT.DrawInnerTriangle(yaz);
	 }
	 else{
	 	cout<<"ERROR-Please enter a number between 1-9"<<endl;
	 }
 	
 	yaz<<"</svg>";
	yaz.close();
	return 0;
}