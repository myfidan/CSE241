#include "ComposedShape.h"

ComposedShape::ComposedShape(Rectangle mr,Rectangle sr){
	main_r.set_width(mr.get_width());
	main_r.set_height(mr.get_height());
	main_r.set_x_cord(mr.get_x_cord());
	main_r.set_y_cord(mr.get_y_cord());
	main_r.set_rect_color(mr.get_rect_color());

	small_r.set_width(sr.get_width());
	small_r.set_height(sr.get_height());
	small_r.set_x_cord(sr.get_x_cord());
	small_r.set_y_cord(sr.get_y_cord());
	small_r.set_rect_color(sr.get_rect_color());
}

ComposedShape::ComposedShape(Rectangle mr,Circle sr){
	main_r.set_width(mr.get_width());
	main_r.set_height(mr.get_height());
	main_r.set_x_cord(mr.get_x_cord());
	main_r.set_y_cord(mr.get_y_cord());
	main_r.set_rect_color(mr.get_rect_color());

	small_c.set_radius(sr.get_radius());
	small_c.set_x_cord(sr.get_x_cord());
	small_c.set_y_cord(sr.get_y_cord());
	small_c.set_circ_color(sr.get_circ_color());
}

ComposedShape::ComposedShape(Rectangle mr,Triangle sr){
	main_r.set_width(mr.get_width());
	main_r.set_height(mr.get_height());
	main_r.set_x_cord(mr.get_x_cord());
	main_r.set_y_cord(mr.get_y_cord());
	main_r.set_rect_color(mr.get_rect_color());

	small_t.set_edge(sr.get_edge());
	small_t.set_x1_cord(sr.get_x1_cord());
	small_t.set_y1_cord(sr.get_y1_cord());
	small_t.set_x2_cord(sr.get_x2_cord());
	small_t.set_y2_cord(sr.get_y2_cord());
	small_t.set_x3_cord(sr.get_x3_cord());
	small_t.set_y3_cord(sr.get_y3_cord());
	small_t.set_tri_color(sr.get_tri_color());
}

ComposedShape::ComposedShape(Circle mr,Rectangle sr){
	main_c.set_radius(mr.get_radius());
	main_c.set_x_cord(mr.get_x_cord());
	main_c.set_y_cord(mr.get_y_cord());
	main_c.set_circ_color(mr.get_circ_color());

	small_r.set_width(sr.get_width());
	small_r.set_height(sr.get_height());
	small_r.set_x_cord(sr.get_x_cord());
	small_r.set_y_cord(sr.get_y_cord());
	small_r.set_rect_color(sr.get_rect_color());
}

ComposedShape::ComposedShape(Circle mr,Circle sr){
	main_c.set_radius(mr.get_radius());
	main_c.set_x_cord(mr.get_x_cord());
	main_c.set_y_cord(mr.get_y_cord());
	main_c.set_circ_color(mr.get_circ_color());

	small_c.set_radius(sr.get_radius());
	small_c.set_x_cord(sr.get_x_cord());
	small_c.set_y_cord(sr.get_y_cord());
	small_c.set_circ_color(sr.get_circ_color());
}

ComposedShape::ComposedShape(Circle mr,Triangle sr){
	main_c.set_radius(mr.get_radius());
	main_c.set_x_cord(mr.get_x_cord());
	main_c.set_y_cord(mr.get_y_cord());
	main_c.set_circ_color(mr.get_circ_color());

	small_t.set_edge(sr.get_edge());
	small_t.set_x1_cord(sr.get_x1_cord());
	small_t.set_y1_cord(sr.get_y1_cord());
	small_t.set_x2_cord(sr.get_x2_cord());
	small_t.set_y2_cord(sr.get_y2_cord());
	small_t.set_x3_cord(sr.get_x3_cord());
	small_t.set_y3_cord(sr.get_y3_cord());
	small_t.set_tri_color(sr.get_tri_color());
}

ComposedShape::ComposedShape(Triangle mr,Rectangle sr){
	main_t.set_edge(mr.get_edge());
	main_t.set_x1_cord(mr.get_x1_cord());
	main_t.set_y1_cord(mr.get_y1_cord());
	main_t.set_x2_cord(mr.get_x2_cord());
	main_t.set_y2_cord(mr.get_y2_cord());
	main_t.set_x3_cord(mr.get_x3_cord());
	main_t.set_y3_cord(mr.get_y3_cord());
	main_t.set_tri_color(mr.get_tri_color());

	small_r.set_width(sr.get_width());
	small_r.set_height(sr.get_height());
	small_r.set_x_cord(sr.get_x_cord());
	small_r.set_y_cord(sr.get_y_cord());
	small_r.set_rect_color(sr.get_rect_color());
}

ComposedShape::ComposedShape(Triangle mr,Circle sr){
	main_t.set_edge(mr.get_edge());
	main_t.set_x1_cord(mr.get_x1_cord());
	main_t.set_y1_cord(mr.get_y1_cord());
	main_t.set_x2_cord(mr.get_x2_cord());
	main_t.set_y2_cord(mr.get_y2_cord());
	main_t.set_x3_cord(mr.get_x3_cord());
	main_t.set_y3_cord(mr.get_y3_cord());
	main_t.set_tri_color(mr.get_tri_color());

	small_c.set_radius(sr.get_radius());
	small_c.set_x_cord(sr.get_x_cord());
	small_c.set_y_cord(sr.get_y_cord());
	small_c.set_circ_color(sr.get_circ_color());
}

ComposedShape::ComposedShape(Triangle mr,Triangle sr){
	main_t.set_edge(mr.get_edge());
	main_t.set_x1_cord(mr.get_x1_cord());
	main_t.set_y1_cord(mr.get_y1_cord());
	main_t.set_x2_cord(mr.get_x2_cord());
	main_t.set_y2_cord(mr.get_y2_cord());
	main_t.set_x3_cord(mr.get_x3_cord());
	main_t.set_y3_cord(mr.get_y3_cord());
	main_t.set_tri_color(mr.get_tri_color());

	small_t.set_edge(sr.get_edge());
	small_t.set_x1_cord(sr.get_x1_cord());
	small_t.set_y1_cord(sr.get_y1_cord());
	small_t.set_x2_cord(sr.get_x2_cord());
	small_t.set_y2_cord(sr.get_y2_cord());
	small_t.set_x3_cord(sr.get_x3_cord());
	small_t.set_y3_cord(sr.get_y3_cord());
	small_t.set_tri_color(sr.get_tri_color());
}

Rectangle ComposedShape::get_main_rect()const{
	return main_r;
}

Rectangle ComposedShape::get_small_rect()const{
	return small_r;
}

Circle ComposedShape::get_main_circ()const{
	return main_c;
}

Circle ComposedShape::get_small_circ()const{
	return small_c;
}

Triangle ComposedShape::get_main_tri()const{
	return main_t;
}

Triangle ComposedShape::get_small_tri()const{
	return small_t;
}

vector<Rectangle> ComposedShape::get_vect_rect()const{
	return r_vector;
}

vector<Circle> ComposedShape::get_vect_circ()const{
	return c_vector;
}

vector<Triangle> ComposedShape::get_vect_tri()const{
	return t_vector;
}

void ComposedShape::OptimalFit(Rectangle mr,Rectangle sr){
	double height_boundary=0.0;
	double width_boundary=0.0;
	int	counter_shape=0;
	while(height_boundary+sr.get_height()<=mr.get_height()){
		counter_shape++;
		Rectangle temp_r(sr.get_width(),sr.get_height(),width_boundary,height_boundary);
		temp_r.set_rect_color("green");
		r_vector.push_back(temp_r);
		width_boundary+=sr.get_width();
		if(width_boundary+sr.get_width()>mr.get_width()){
			width_boundary=0.0;
			height_boundary+=sr.get_height();
		}
	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Rectangle in main Rectangle"<<endl;
}


void ComposedShape::OptimalFit(Rectangle mr,Circle sr){
	double height_boundary=sr.get_radius();
	double width_boundary=sr.get_radius();
	int counter_shape=0;
	while(height_boundary+sr.get_radius()<=mr.get_height()){
		counter_shape++;
		Circle temp_c(sr.get_radius(),width_boundary,height_boundary);
		temp_c.set_circ_color("green");
		c_vector.push_back(temp_c);
		width_boundary+=2*sr.get_radius();
		if(width_boundary+sr.get_radius()>mr.get_width()){
			width_boundary=sr.get_radius();
			height_boundary+=2*sr.get_radius();
		}
	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Circle in main Rectangle"<<endl;
}

void ComposedShape::OptimalFit(Rectangle mr,Triangle sr){
	double width_boundary=sr.get_edge()/2;
	double height_boundary=sr.get_edge()/2*sqrt(3);
	int counter_shape=0;
	while(height_boundary<=mr.get_height()){
		counter_shape++;
		Triangle temp_t(sr.get_edge(),width_boundary,height_boundary-(sr.get_edge()/2)*sqrt(3),width_boundary+sr.get_edge()/2,height_boundary,width_boundary-sr.get_edge()/2,height_boundary);
		temp_t.set_tri_color("green");
		t_vector.push_back(temp_t);
		width_boundary+=sr.get_edge();
		if(width_boundary>mr.get_width()){
			width_boundary=sr.get_edge()/2;
			height_boundary+=sr.get_edge()/2*sqrt(3);
		}
	}
	width_boundary=sr.get_edge()/2;
	height_boundary=sr.get_edge()/2*sqrt(3);

	while(height_boundary<=mr.get_height()){
		counter_shape++;
		Triangle temp_t(sr.get_edge(),width_boundary+sr.get_edge()/2,height_boundary,width_boundary+sr.get_edge(),height_boundary-sr.get_edge()/2*sqrt(3),width_boundary,height_boundary-sr.get_edge()/2*sqrt(3));
		temp_t.set_tri_color("green");
		t_vector.push_back(temp_t);
		width_boundary+=sr.get_edge();
		if(width_boundary+sr.get_edge()>mr.get_width()){
			width_boundary=sr.get_edge()/2;
			height_boundary+=sr.get_edge()/2*sqrt(3);
		}
	}


	cout<<"I can fit at most *"<<counter_shape<<"* inner Triangle in main Rectangle"<<endl;
}

void ComposedShape::OptimalFit(Circle mr,Rectangle sr){
	int up=1;
	double coordinat_width=mr.get_radius();
	double coordinat_height=mr.get_radius()-sr.get_height();
	double max_width;
	double ekle_width=0;
	double ekle_height=sr.get_height();
	double cikar_width=mr.get_radius()-sr.get_width();
	int counter_shape=0;
	while(coordinat_height>0){
		max_width=sqrt(pow(mr.get_radius(),2)-pow(sr.get_height()*up,2));
		while(ekle_width+sr.get_width()<=max_width){
			counter_shape++;
			counter_shape++;
			counter_shape++;
			counter_shape++;

			Rectangle temp_r1(sr.get_width(),sr.get_height(),coordinat_width+ekle_width,coordinat_height);
			temp_r1.set_rect_color("green");
			r_vector.push_back(temp_r1);

			Rectangle temp_r2(sr.get_width(),sr.get_height(),cikar_width,coordinat_height);
			temp_r2.set_rect_color("green");
			r_vector.push_back(temp_r2);

			Rectangle temp_r3(sr.get_width(),sr.get_height(),coordinat_width+ekle_width,coordinat_height+ekle_height);
			temp_r3.set_rect_color("green");
			r_vector.push_back(temp_r3);

			Rectangle temp_r4(sr.get_width(),sr.get_height(),cikar_width,coordinat_height+ekle_height);
			temp_r4.set_rect_color("green");
			r_vector.push_back(temp_r4);

			ekle_width+=sr.get_width();
			cikar_width-=sr.get_width();
		}
		up++;
		ekle_width=0;
		cikar_width=mr.get_radius()-sr.get_width();
		coordinat_height-=sr.get_height();
		ekle_height+=sr.get_height()*2;
	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Rectangle in main Circle"<<endl;
}	

void ComposedShape::OptimalFit(Circle mr,Circle sr){
	double coordinat_radius_height=mr.get_radius();
	double coordinat_radius_width=mr.get_radius();
	double max_radius;
	double sol_width=0;
	double alt_height=0;
	int up=0;
	int counter_shape=0;

	while(coordinat_radius_height-sr.get_radius()>=0){
		max_radius=sqrt(pow(mr.get_radius(),2)-pow(sr.get_radius()*up,2));
		coordinat_radius_width=mr.get_radius();
		while(max_radius-sr.get_radius()>=0){
			counter_shape++;
			
			Circle temp_c1(sr.get_radius(),coordinat_radius_width,coordinat_radius_height);
			temp_c1.set_circ_color("green");
			c_vector.push_back(temp_c1);

			if(sol_width!=0){
				counter_shape++;
				Circle temp_c2(sr.get_radius(),coordinat_radius_width-sol_width,coordinat_radius_height);
				temp_c2.set_circ_color("green");
				c_vector.push_back(temp_c2);
			}
			if(alt_height!=0){
				counter_shape++;
				Circle temp_c3(sr.get_radius(),coordinat_radius_width,coordinat_radius_height+alt_height);
				temp_c3.set_circ_color("green");
				c_vector.push_back(temp_c3);
			}
			if(alt_height!=0 && sol_width!=0){
				counter_shape++;
				Circle temp_c4(sr.get_radius(),coordinat_radius_width-sol_width,coordinat_radius_height+alt_height);
				temp_c4.set_circ_color("green");
				c_vector.push_back(temp_c4);
			}

			coordinat_radius_width+=2*sr.get_radius();
			max_radius-=2*sr.get_radius();
			sol_width+=4*sr.get_radius();

		}
		up+=2;

		coordinat_radius_height-=2*sr.get_radius();
		sol_width=0;
		alt_height+=4*sr.get_radius();
	}	
	cout<<"I can fit at most *"<<counter_shape<<"* inner Circle in main Circle"<<endl;
}

void ComposedShape::OptimalFit(Circle mr,Triangle sr){//C-T ilk ödevdeki problemden dolayı tam çalışmıyor
	double triangle_height=sr.get_edge()/2*sqrt(3);
	double height=mr.get_radius();
	double max_radius;
	int up=0;
	max_radius=sqrt(pow(mr.get_radius(),2)-pow(triangle_height*up,2));
	double sol_width=0;
	double alt_height=0;
	int counter_shape=0;

	while(height-triangle_height>=0){
		double width=mr.get_radius();
		while(width+sr.get_edge()<=mr.get_radius()+max_radius){
			counter_shape++;
			Triangle temp_t1(sr.get_edge(),width,height,width+sr.get_edge()/2,height-triangle_height,width-sr.get_edge()/2,height-triangle_height);
			temp_t1.set_tri_color("green");
			t_vector.push_back(temp_t1);

			if(width+sr.get_edge()*2<=mr.get_radius()+max_radius){
				counter_shape++;
				Triangle temp_t2(sr.get_edge(),width+sr.get_edge()/2,height-triangle_height,width+sr.get_edge(),height,width,height);
				temp_t2.set_tri_color("green");
				t_vector.push_back(temp_t2);
			}
			if(sol_width!=0){
				counter_shape++;
				counter_shape++;

				Triangle temp_t3(sr.get_edge(),width-sol_width,height,width+sr.get_edge()/2-sol_width,height-triangle_height,width-sr.get_edge()/2-sol_width,height-triangle_height);
				temp_t3.set_tri_color("green");
				t_vector.push_back(temp_t3);

				Triangle temp_t4(sr.get_edge(),width+sr.get_edge()/2-sol_width,height-triangle_height,width+sr.get_edge()-sol_width,height,width-sol_width,height);
				temp_t4.set_tri_color("green");
				t_vector.push_back(temp_t4);
			}
			if(alt_height!=0){
				counter_shape++;
				counter_shape++;

				Triangle temp_t5(sr.get_edge(),width,height+alt_height,width+sr.get_edge()/2,height-triangle_height+alt_height,width-sr.get_edge()/2,height-triangle_height+alt_height);
				temp_t5.set_tri_color("green");
				t_vector.push_back(temp_t5);

				Triangle temp_t6(sr.get_edge(),width+sr.get_edge()/2,height-triangle_height+alt_height,width+sr.get_edge(),height +alt_height,width,height+alt_height);
				temp_t6.set_tri_color("green");
				t_vector.push_back(temp_t6);

			}
			if(alt_height!=0 && sol_width!=0){
				counter_shape++;
				counter_shape++;

				Triangle temp_t7(sr.get_edge(),width-sol_width,height+alt_height,width+sr.get_edge()/2-sol_width,height-triangle_height+alt_height,width-sr.get_edge()/2-sol_width,height-triangle_height+alt_height);
				temp_t7.set_tri_color("green");
				t_vector.push_back(temp_t7);

				Triangle temp_t8(sr.get_edge(),width+sr.get_edge()/2-sol_width,height-triangle_height+alt_height,width+sr.get_edge()-sol_width,height+alt_height,width-sol_width,height+alt_height);
				temp_t8.set_tri_color("green");
				t_vector.push_back(temp_t8);
			}
			width+=sr.get_edge();
			sol_width+=2*sr.get_edge();

		}
		up+=1;
		height-=triangle_height;
		sol_width=0;
		alt_height+=triangle_height*2;
		max_radius=sqrt(pow(mr.get_radius(),2)-pow(triangle_height*up+triangle_height,2));
	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Triangle in main Circle"<<endl;
}

void ComposedShape::OptimalFit(Triangle mr,Rectangle sr){
	double height=(mr.get_edge()/2*sqrt(3))-sr.get_height();
	double width=0;
	int up=0;
	int counter_shape=0;
	double max_width=mr.get_edge();
	while(height>=0){
		while(width<=max_width-2*sr.get_height()/sqrt(3)-sr.get_width()){
			counter_shape++;
			
			Rectangle temp_r(sr.get_width(),sr.get_height(),width+sr.get_height()/sqrt(3),height);
			temp_r.set_rect_color("green");
			r_vector.push_back(temp_r);

			width+=sr.get_width();
		}
		up++;
		width=up*sr.get_height()/sqrt(3);
		height-=sr.get_height();
		max_width-=sr.get_height()/sqrt(3);
	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Rectangle in main Triangle"<<endl;
}

void ComposedShape::OptimalFit(Triangle mr,Circle sr){
	double height=mr.get_edge()/2*sqrt(3)-sr.get_radius();
	double width=sr.get_radius()*sqrt(3);
	int up=0;
	int counter_shape=0;
	while(height-sr.get_radius()>=0){
		while(width+sr.get_radius()*sqrt(3)<=mr.get_edge()){
			counter_shape++;
			
			Circle temp_c(sr.get_radius(),width,height);
			temp_c.set_circ_color("green");
			c_vector.push_back(temp_c);
			width+=2*sr.get_radius();
		}
		up=up+1;
		height-=sqrt(3)*sr.get_radius();
		width=sr.get_radius()*sqrt(3)+sr.get_radius()*up;
		mr.set_edge(mr.get_edge()-sr.get_radius());
	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Circle in main Triangle"<<endl;

}

void ComposedShape::OptimalFit(Triangle mr,Triangle sr){
	double main_tri_height=mr.get_edge()/2*sqrt(3);
	double small_tri_height=sr.get_edge()/2*sqrt(3);
	double width=0;
	int up=1;
	int counter_shape=0;
	while(main_tri_height-small_tri_height>=0){
		while(width+sr.get_edge()<=mr.get_edge()){
			counter_shape++;
			Triangle temp_t(sr.get_edge(),width+sr.get_edge()/2,main_tri_height-small_tri_height,width+sr.get_edge(),main_tri_height,width,main_tri_height);
			temp_t.set_tri_color("green");
			t_vector.push_back(temp_t);
			if(width+sr.get_edge()+sr.get_edge()/2<=mr.get_edge()){
				counter_shape++;
				Triangle temp_t2(sr.get_edge(),width+sr.get_edge(),main_tri_height,width+sr.get_edge()/2,main_tri_height-small_tri_height,width+sr.get_edge()*3/2,main_tri_height-small_tri_height);
				temp_t2.set_tri_color("green");
				t_vector.push_back(temp_t2);
			}
			width+=sr.get_edge();
		}
		width=sr.get_edge()/2*up;
		main_tri_height-=small_tri_height;
		mr.set_edge(mr.get_edge()-sr.get_edge()/2);
		up++;	

	}
	cout<<"I can fit at most *"<<counter_shape<<"* inner Triangle in main Triangle"<<endl;
}

//Draw Container shapes
void ComposedShape::DrawContainerRectangle(ofstream& yaz)const{
	main_r.Draw(yaz);
}

void ComposedShape::DrawContainerCircle(ofstream& yaz)const{
	main_c.Draw(yaz);
}

void ComposedShape::DrawContainerTriangle(ofstream& yaz)const{
	main_t.Draw(yaz);
}

//Draw inner shapes
void ComposedShape::DrawInnerRectangle(ofstream& yaz)const{
	for(int i=0; i<r_vector.size(); i++){
		r_vector[i].Draw(yaz);
	}
}

void ComposedShape::DrawInnerCircle(ofstream& yaz)const{
	for(int i=0; i<c_vector.size(); i++){
		c_vector[i].Draw(yaz);
	}
}

void ComposedShape::DrawInnerTriangle(ofstream& yaz)const{
	for(int i=0; i<t_vector.size(); i++){
		t_vector[i].Draw(yaz);
	}
}




