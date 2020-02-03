#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include "hw3_class.h"

using namespace std;

Administrator::Administrator(){
	pid=0;
	password=0;
}
Lecturer::Lecturer(){
	
}

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

void Administrator::arrangeTimeTable(Course& time_course){
	
	int max_start=17-time_course.total_hours;
	int rand_day=rand()%5+1;
	Date temp;
	if(rand_day==1){
		temp.day="Mon";
	}
	else if(rand_day==2){
		temp.day="Tues";
	}
	else if(rand_day==3){
		temp.day="Wed";
	}
	else if(rand_day==4){
		temp.day="Thurs";
	}
	else if(rand_day==5){
		temp.day="Fri";
	}
	bool flag=false;
	while(!flag){
		temp.start_hour=9+rand()%max_start;
		if(temp.start_hour<=max_start)flag=true;
	}

	temp.end_hour=temp.start_hour+time_course.total_hours;
	time_course.lecture_dates.push_back(temp);
}

void Administrator::arrangeClassroom(vector<Lecturer>& lecturers,Course& x,int tut_class){
	bool flag=false;
	string day;
	int start,end;
	for(int i=0; i<lecturers.size(); i++){
		for(int j=0; j<lecturers[i].courses.size(); j++){
			for(int z=0; z<lecturers[i].courses[j].lecture_dates.size(); z++){
				if(lecturers[i].courses[j].id==x.id){
					day=lecturers[i].courses[j].lecture_dates[z].day;
					start=lecturers[i].courses[j].lecture_dates[z].start_hour;
					end=lecturers[i].courses[j].lecture_dates[z].end_hour;
				}
			}
		}		
	}
	for(int i=0; i<lecturers.size(); i++){
		for(int j=0; j<lecturers[i].courses.size(); j++){
			if(tut_class==lecturers[i].courses[j].course_class.id && x.id!=lecturers[i].courses[j].id){
			for(int z=0; z<lecturers[i].courses[j].lecture_dates.size(); z++){
			
				if(lecturers[i].courses[j].lecture_dates[z].day==x.lecture_dates[z].day){
					if((lecturers[i].courses[j].lecture_dates[z].start_hour<x.lecture_dates[z].start_hour && lecturers[i].courses[j].lecture_dates[z].end_hour>x.lecture_dates[z].start_hour) || (lecturers[i].courses[j].lecture_dates[z].start_hour>x.lecture_dates[z].start_hour && lecturers[i].courses[j].lecture_dates[z].end_hour>x.lecture_dates[z].start_hour )){
						flag=true;
						
					}
				}
			}
			}
		}
	}
	
	if(flag==true){
		cout<<"Block:class is not available,there is another class assigned for this date";
	}
	else{
		x.course_class.id=tut_class;
		
		cout<<"DONE:("<<x.id<<")"<<x.name<<" in "<<tut_class<<" at "<<day<<"_"<<start<<"-"<<end;
	
	}
}


	

