#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>
#include<cstdlib>

#include "hw4_admin.h"

namespace Fidan_class{
	
	using namespace std;
	
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
			if(tut_class==lecturers[i].courses[j].course_class.get_class_id() && x.id!=lecturers[i].courses[j].id){
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
		x.course_class.set_class_id(tut_class);
		
		cout<<"DONE:("<<x.id<<")"<<x.name<<" in "<<tut_class<<" at "<<day<<"_"<<start<<"-"<<end;
	
	}
}

}
