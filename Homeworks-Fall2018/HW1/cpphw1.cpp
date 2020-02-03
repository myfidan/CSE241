#include<iostream>
#include <fstream>
#include<cmath>

using namespace std;

enum Shape{Rectangle,Circle,Triangle};

void Draw_main_shape(Shape main_shape_type,double main_width,double main_height,double main_radius,double main_edge,ofstream& yaz);

void Draw_small_shape(Shape main_shape_type,Shape small_shape_type,double main_width,double main_height,double main_radius,double main_edge,double small_width,double small_height,double small_radius,double small_edge,ofstream& yaz);

int main(){
	Shape main_shape_type,small_shape_type;
	char main_shape,small_shape;
	double main_width,main_height,main_radius,main_edge;
	double small_width,small_height,small_radius,small_edge;

	ofstream yaz;
 	yaz.open ("result.svg");

 	cout<<"Please enter the main container shape (R, C, T)"<<endl;
 	cin>>main_shape;

 	switch(main_shape){
 		
 		case 'R':
 			main_shape_type=Rectangle;
 			cout<<"Please enter the width"<<endl;
 			cin>>main_width;
 			cout<<"Please enter the height"<<endl;
 			cin>>main_height;
 		break;
 		case 'C':
 			main_shape_type=Circle;
 			cout<<"Please enter the radius"<<endl;
 			cin>>main_radius;
 		break;
 		case 'T':
 			main_shape_type=Triangle;
 			cout<<"Please enter the edge length"<<endl;
 			cin>>main_edge;
 		break;
 		default:
 			cout<<"Error invalid shape code"<<endl;
 	}

 	cout<<"Please enter the small shape (R, C, T)"<<endl;
 	cin>>small_shape;

 	switch(small_shape){
 		
 		case 'R':
 			small_shape_type=Rectangle;
 			cout<<"Please enter the width"<<endl;
 			cin>>small_width;
 			cout<<"Please enter the height"<<endl;
 			cin>>small_height;
 		break;
 		case 'C':
 			small_shape_type=Circle;
 			cout<<"Please enter the radius"<<endl;
 			cin>>small_radius;
 		break;
 		case 'T':
 			small_shape_type=Triangle;
 			cout<<"Please enter the edge length"<<endl;
 			cin>>small_edge;
 		break;
 		default:
 			cout<<"Error invalid shape code"<<endl;

 	}

 	Draw_main_shape(main_shape_type,main_width,main_height,main_radius,main_edge,yaz);
 	Draw_small_shape(main_shape_type,small_shape_type,main_width,main_height,main_radius,main_edge,small_width,small_height,small_radius,small_edge,yaz);

  	yaz.close();

	return 0;
}


void Draw_main_shape(Shape main_shape_type,double main_width,double main_height,double main_radius,double main_edge,ofstream& yaz){

	
	if(main_shape_type==Rectangle){
		yaz<<"<svg> <rect x=\""<<0<<"\" y=\""<<0<<"\" width=\""<< main_width <<"\" height=\""<< main_height<<"\" fill=\"red\"/> "<<endl;
	}
	else if(main_shape_type==Circle){
		yaz<<"<svg> <circle cx=\""<<main_radius<<"\" cy=\""<<main_radius<<"\" r=\""<<main_radius<<"\" fill=\"green\" /> "<<endl;
	}
	else if(main_shape_type==Triangle){
		yaz<<"<svg> <polygon points=\""<<main_edge/2<<","<<0<<" "<<main_edge<<","<<(main_edge/2)*sqrt(3) <<" "<<0<<" "<<(main_edge/2)*sqrt(3)<<"\" fill=\"red\" /> "<<endl;
	}
	
}

void Draw_small_shape(Shape main_shape_type,Shape small_shape_type,double main_width,double main_height,double main_radius,double main_edge,double small_width,double small_height,double small_radius,double small_edge,ofstream& yaz){

	double height_boundary;
	double width_boundary;

	if(main_shape_type==Rectangle && small_shape_type==Rectangle){
		
		height_boundary=0.0;
		width_boundary=0.0;

		while(height_boundary+small_height<=main_height){
			yaz<<"<rect x=\""<<width_boundary<<"\" y= \""<<height_boundary<<"\" width=\""<<small_width<<"\" height=\""<<small_height<<"\" style=\"fill:green; stroke:blue; stroke-width:0.5;\" />"<<endl;
			width_boundary+=small_width;
			if(width_boundary+small_width>main_width){
				width_boundary=0;
				height_boundary+=small_height;
			}
		}
		//özel durumlar eklenmedi(rotate)
	}
	else if(main_shape_type==Rectangle && small_shape_type==Circle){
		height_boundary=small_radius;
		width_boundary=small_radius;

		while(height_boundary+small_radius<=main_height){
			yaz<<"<circle cx=\""<<width_boundary<<"\" cy=\""<<height_boundary<<"\" r=\""<<small_radius<<"\" fill=\"green\" /> "<<endl;
			width_boundary+=2*small_radius;
			if(width_boundary+small_radius>main_width){
				width_boundary=small_radius;
				height_boundary+=2*small_radius;
			}
		}
		//özel durumlar eklenmedi(rotate)
	}
	else if(main_shape_type==Rectangle && small_shape_type==Triangle){
		width_boundary=small_edge/2;
		height_boundary=(small_edge/2)*(3^1/2);

		while(height_boundary<=main_height){
			yaz<<"<polygon points=\""<<width_boundary<<","<<height_boundary-(small_edge/2)*(3^1/2)<<" "<<width_boundary+small_edge/2<<","<<height_boundary <<" "<<width_boundary-small_edge/2<<" "<<height_boundary<<"\" style=\"fill:green; stroke:blue; stroke-width:0.2;\" /> "<<endl;
			width_boundary+=small_edge;
			if(width_boundary>main_width){
				width_boundary=small_edge/2;
				height_boundary+=(small_edge/2)*(3^1/2);
			}
		}
		width_boundary=small_edge/2;
		height_boundary=(small_edge/2)*(3^1/2);

		while(height_boundary<=main_height){
			yaz<<"<polygon points=\""<<width_boundary+small_edge/2<<","<<height_boundary<<" "<<width_boundary+small_edge<<","<<height_boundary-(small_edge/2)*(3^1/2) <<" "<<width_boundary<<" "<<height_boundary-(small_edge/2)*(3^1/2)<<"\" style=\"fill:green; stroke:blue; stroke-width:0.2;\" /> "<<endl;
			width_boundary+=small_edge;
			if(width_boundary+small_edge>main_width){
				width_boundary=small_edge/2;
				height_boundary+=(small_edge/2)*(3^1/2);
			}
		}
		//özel durumlar eklenmedi

	}
	else if(main_shape_type==Circle && small_shape_type==Rectangle){
		int up=1;
		double coordinat_width=main_radius;
		double coordinat_height=main_radius-small_height;
		double max_width;
		double ekle_width=0;
		double ekle_height=small_height;
		double cikar_width=main_radius-small_width;
		while(coordinat_height>0){
			max_width=sqrt(pow(main_radius,2)-pow(small_height*up,2));
			while(ekle_width+small_width<=max_width){
				yaz<<"<rect x=\""<<coordinat_width+ekle_width<<"\" y= \""<<coordinat_height<<"\" width=\""<<small_width<<"\" height=\""<<small_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.5;\" />"<<endl;
				yaz<<"<rect x=\""<<cikar_width<<"\" y= \""<<coordinat_height<<"\" width=\""<<small_width<<"\" height=\""<<small_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.5;\" />"<<endl;
				yaz<<"<rect x=\""<<coordinat_width+ekle_width<<"\" y= \""<<coordinat_height+ekle_height<<"\" width=\""<<small_width<<"\" height=\""<<small_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.5;\" />"<<endl;
				yaz<<"<rect x=\""<<cikar_width<<"\" y= \""<<coordinat_height+ekle_height<<"\" width=\""<<small_width<<"\" height=\""<<small_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.5;\" />"<<endl;


				ekle_width+=small_width;
				cikar_width-=small_width;
			}
			up++;
			ekle_width=0;
			cikar_width=main_radius-small_width;
			coordinat_height-=small_height;
			ekle_height+=small_height*2;
		}

	}
	else if(main_shape_type==Circle && small_shape_type==Circle){
		double coordinat_radius_height=main_radius;
		double coordinat_radius_width=main_radius;
		double max_radius;
		double sol_width=0;
		double alt_height=0;
		int up=0;
		while(coordinat_radius_height-small_radius>=0){
			max_radius=sqrt(pow(main_radius,2)-pow(small_radius*up,2));
			coordinat_radius_width=main_radius;
			while(max_radius-small_radius>=0){
				yaz<<"<circle cx=\""<<coordinat_radius_width<<"\" cy=\""<<coordinat_radius_height<<"\" r=\""<<small_radius<<"\" fill=\"red\" /> "<<endl;
				if(sol_width!=0){
					yaz<<"<circle cx=\""<<coordinat_radius_width-sol_width<<"\" cy=\""<<coordinat_radius_height<<"\" r=\""<<small_radius<<"\" fill=\"red\" /> "<<endl;
				}
				if(alt_height!=0){
					yaz<<"<circle cx=\""<<coordinat_radius_width<<"\" cy=\""<<coordinat_radius_height+alt_height<<"\" r=\""<<small_radius<<"\" fill=\"red\" /> "<<endl;
				}
				if(alt_height!=0 && sol_width!=0){
					yaz<<"<circle cx=\""<<coordinat_radius_width-sol_width<<"\" cy=\""<<coordinat_radius_height+alt_height<<"\" r=\""<<small_radius<<"\" fill=\"red\" /> "<<endl;

				}
				
				coordinat_radius_width+=2*small_radius;
				max_radius-=2*small_radius;
				sol_width+=4*small_radius;
				
			}
			up+=2;
			
			coordinat_radius_height-=2*small_radius;
			sol_width=0;
			alt_height+=4*small_radius;
		}
	}
	else if(main_shape_type==Circle && small_shape_type==Triangle){
		
		double triangle_height=(small_edge/2)*sqrt(3);
		double height=main_radius;
		double max_radius;
		int up=0;
		max_radius=sqrt(pow(main_radius,2)-pow(triangle_height*up,2));
		double sol_width=0;
		double alt_height=0;
		while(height-triangle_height>=0){
			
			double width=main_radius;
			while(width+small_edge<=main_radius+max_radius){
				yaz<<"<polygon points=\""<<width<<","<<height<<" "<<width+small_edge/2<<","<<height-triangle_height <<" "<<width-small_edge/2<<" "<<height-triangle_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
				if(width+small_edge*2<=main_radius+max_radius){
					yaz<<"<polygon points=\""<<width+small_edge/2<<","<<height-triangle_height<<" "<<width+small_edge<<","<<height <<" "<<width<<" "<<height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
				}
				if(sol_width!=0){
					yaz<<"<polygon points=\""<<width-sol_width<<","<<height<<" "<<width+small_edge/2-sol_width<<","<<height-triangle_height <<" "<<width-small_edge/2-sol_width<<" "<<height-triangle_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
					yaz<<"<polygon points=\""<<width+small_edge/2-sol_width<<","<<height-triangle_height<<" "<<width+small_edge-sol_width<<","<<height <<" "<<width-sol_width<<" "<<height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
				}
				if(alt_height!=0){
					yaz<<"<polygon points=\""<<width<<","<<height+alt_height<<" "<<width+small_edge/2<<","<<height-triangle_height+alt_height <<" "<<width-small_edge/2<<" "<<height-triangle_height+alt_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
					yaz<<"<polygon points=\""<<width+small_edge/2<<","<<height-triangle_height+alt_height<<" "<<width+small_edge<<","<<height +alt_height<<" "<<width<<" "<<height+alt_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
				}
				if(alt_height!=0 && sol_width!=0){
					yaz<<"<polygon points=\""<<width-sol_width<<","<<height+alt_height<<" "<<width+small_edge/2-sol_width<<","<<height-triangle_height+alt_height <<" "<<width-small_edge/2-sol_width<<" "<<height-triangle_height+alt_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;
					yaz<<"<polygon points=\""<<width+small_edge/2-sol_width<<","<<height-triangle_height+alt_height<<" "<<width+small_edge-sol_width<<","<<height+alt_height <<" "<<width-sol_width<<" "<<height+alt_height<<"\" style=\"fill:red; stroke:blue; stroke-width:0.4;\" /> "<<endl;

				}
				width+=small_edge;
				sol_width+=2*small_edge;
			}
			up+=1;
			height-=triangle_height;
			sol_width=0;
			alt_height+=triangle_height*2;
			max_radius=sqrt(pow(main_radius,2)-pow(triangle_height*up+triangle_height,2));
		}

	}
	else if(main_shape_type==Triangle && small_shape_type==Rectangle){
		double height=(main_edge/2*sqrt(3))-small_height;
		double width=0;
		int up=0;
		double max_width=main_edge;
		while(height>=0){
			while(width<=max_width-2*small_height/sqrt(3)-small_width){
				yaz<<"<rect x=\""<<width+small_height/sqrt(3)<<"\" y= \""<<height<<"\" width=\""<<small_width<<"\" height=\""<<small_height<<"\" style=\"fill:green; stroke:blue; stroke-width:0.5;\" />"<<endl;
				width+=small_width;
			}
			up++;
			width=up*small_height/sqrt(3);
			height-=small_height;
			max_width-=small_height/sqrt(3);
		}
	}
	else if(main_shape_type==Triangle && small_shape_type==Circle){
		double height=main_edge/2*sqrt(3)-small_radius;
		double width=small_radius*sqrt(3);
		int up=0;
		while(height-small_radius>=0){
			while(width+small_radius*sqrt(3)<=main_edge){
				yaz<<"<circle cx=\""<<width<<"\" cy=\""<<height<<"\" r=\""<<small_radius<<"\" fill=\"green\" /> "<<endl;
				width+=2*small_radius;
			}
			up=up+1;
			height-=sqrt(3)*small_radius;
			width=small_radius*sqrt(3)+small_radius*up;
			main_edge-=small_radius;
			
			
			
		}

	}
	else if(main_shape_type==Triangle && small_shape_type==Triangle){
		double main_tri_height=main_edge/2*sqrt(3);
		double small_tri_height=small_edge/2*sqrt(3);
		double width=0;
		int up=1;
		while(main_tri_height-small_tri_height>=0){
			while(width+small_edge<=main_edge){
				yaz<<"<polygon points=\""<<width+small_edge/2<<","<<main_tri_height-small_tri_height<<" "<<width+small_edge<<","<<main_tri_height <<" "<<width<<" "<<main_tri_height<<"\" style=\"fill:green; stroke:blue; stroke-width:0.4;\" /> "<<endl;
				if(width+small_edge+small_edge/2<=main_edge){
					yaz<<"<polygon points=\""<<width+small_edge<<","<<main_tri_height<<" "<<width+small_edge/2<<","<<main_tri_height-small_tri_height<<" "<<width+small_edge*3/2<<" "<<main_tri_height-small_tri_height<<"\" style=\"fill:green; stroke:blue; stroke-width:0.4;\" /> "<<endl;
				}
				
				width+=small_edge;
			}

			width=small_edge/2*up;
			main_tri_height-=small_tri_height;
			main_edge-=small_edge/2;
			up++;
		}
	}

	yaz<<"</svg>";
}