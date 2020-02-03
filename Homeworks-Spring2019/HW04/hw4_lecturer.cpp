#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include"hw4_classroom.h"
#include"hw4_lecturer.h"

namespace Fidan_class{
	
	using namespace std;
	

		
				
void Lecturer::set_id(int x){
	personal_id=x;
}

void Lecturer::set_name(string y){
	name=y;
}

void Lecturer::set_surname(string z){
	surname=z;
}

void Lecturer::set_title(string w){
	title=w;
}

int Lecturer::get_id(){
	return personal_id;
}

string Lecturer::get_name(){
	return name;
}

string Lecturer::get_surname(){
	return surname;
}

string Lecturer::get_title(){
	return title;
}

void Lecturer::proposeCourse(string input){
	
	int x[4];
	string y[2];
	string a;
	int b;
	stringstream stream(input);
	for(int i=0; i<7; i++){
		if(i==0)stream>>a;
		else if(i==1){
			stream>>b;
			x[0]=b;
		}
		else if(i==2){
			stream>>a;
			y[0]=a;
		}
		else if(i==3){
			stream>>b;
			x[1]=b;
		}
		else if(i==4){
			stream>>b;
			x[2]=b;
		}
		else if(i==5){
			stream>>b;
			x[3]=b;
		}
		else if(i==6){
			stream>>a;
			y[1]=a;
		}
		
		if(!stream)break;			
	}

	
		
		for(int j=0; j<this->proffesions[j].size()+1; j++){
		
			if(this->proffesions[j]==y[1]){
				
				Course temp;
				temp.id=-1;
				temp.name=y[0];
				temp.code=x[1];
				temp.credit=x[2];
				temp.total_hours=x[3];
				temp.field=y[1];
				temp.isMandatory=0;
				
				this->elect_courses.push_back(temp);
				break;
			}
		}
			
}

void Lecturer::assignCourse(Course selected_course){
	this->courses.push_back(selected_course);
}

}
