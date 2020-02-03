#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>
#include<cstdlib>

#include"hw4_classroom.h"
namespace Fidan_class{
	
	using namespace std;
int Classroom::get_class_id(){
	return id;
}

int Classroom::get_class_no(){
	return c_no;
}

int Classroom::get_class_capacity(){
	return capacity;
}

int Classroom::get_class_inroom(){
	return student_inroom;
}

void Classroom::set_class_id(int x){
	id=x;
}


void Classroom::set_class_no(int x){
	c_no=x;
}


void Classroom::set_class_capacity(int x){
	capacity=x;
}


void Classroom::set_class_inroom(int x){
	student_inroom=x;
}
/*
void Classroom::add_attendance(int x){
	attendance[used_class]=x;
	used_class++;
}
*/
Attendance Classroom::enterClassroom(int class_no,int student_no,int hour,vector<Course> courses){

	Attendance temp;
	temp.class_id_number=class_no;
	temp.student_id_number=student_no;
	temp.hours.push_back(hour);
	if(hour>0 && hour<=8){
		for(int i=0; i<courses.size(); i++){
			
			if(courses[i].course_class.id==class_no){
			
				for(int j=0; j<courses[i].lecture_dates.size(); j++){
				
					if(courses[i].lecture_dates[j].day=="Mon"){
						
						if(courses[i].lecture_dates[j].start_hour-9<=hour && courses[i].lecture_dates[j].end_hour-9>hour){
						
							//temp.attendance_score=courses[i].lecture_dates[j].end_hour-9-hour;
							temp.attendance_score=1;
							temp.course_id_number=courses[i].id;
						//	x.push_back(temp);
						}
					}
				}
			}
			
		}
	}
	else if(hour>8 && hour<=16){
		for(int i=0; i<courses.size(); i++){
			if(courses[i].course_class.id==class_no){
				for(int j=0; j<courses[i].lecture_dates.size(); j++){
					
					if(courses[i].lecture_dates[j].day=="Tues"){
						if(courses[i].lecture_dates[j].start_hour-9<=hour-8 && courses[i].lecture_dates[j].end_hour-9>hour-8){
							//temp.attendance_score=courses[i].lecture_dates[j].end_hour-9-hour-8;
							temp.attendance_score=1;
							temp.course_id_number=courses[i].id;
							//x.push_back(temp);
						}
					}
				}
			}
			
		}
	}
	else if(hour>16 && hour<=24){
		for(int i=0; i<courses.size(); i++){
			if(courses[i].course_class.id==class_no){
				for(int j=0; j<courses[i].lecture_dates.size(); j++){
					
					if(courses[i].lecture_dates[j].day=="Wed"){
						if(courses[i].lecture_dates[j].start_hour-9<=hour-16 && courses[i].lecture_dates[j].end_hour-9>hour-16){
							//temp.attendance_score=courses[i].lecture_dates[j].end_hour-9-hour-16;
							temp.attendance_score=1;
							temp.course_id_number=courses[i].id;
							//x.push_back(temp);
						}
					}
				}
			}
			
		}
	}
	else if(hour>24 && hour<=32){
		for(int i=0; i<courses.size(); i++){
			if(courses[i].course_class.id==class_no){
				for(int j=0; j<courses[i].lecture_dates.size(); j++){
					
					if(courses[i].lecture_dates[j].day=="Thurs"){
						if(courses[i].lecture_dates[j].start_hour-9<=hour-24 && courses[i].lecture_dates[j].end_hour-9>hour-24){
							//temp.attendance_score=courses[i].lecture_dates[j].end_hour-9-hour-24;
							temp.attendance_score=1;
							temp.course_id_number=courses[i].id;
						//	x.push_back(temp);
						}
					}
				}
			}
			
		}
	}
	else if(hour>32 && hour<=40){
		for(int i=0; i<courses.size(); i++){
			if(courses[i].course_class.id==class_no){
				for(int j=0; j<courses[i].lecture_dates.size(); j++){
					
					if(courses[i].lecture_dates[j].day=="Fri"){
						if(courses[i].lecture_dates[j].start_hour-9<=hour-32 && courses[i].lecture_dates[j].end_hour-9>hour-32){
							//temp.attendance_score=courses[i].lecture_dates[j].end_hour-9-hour-32;
							temp.attendance_score=1;
							temp.course_id_number=courses[i].id;
							//x.push_back(temp);
						}
					}
				}
			}
			
		}
	}
	else{
		cout<<"Error hour must range of 0-40"<<endl;
	}
	
	return temp;
}

void Classroom::quitClassroom(){
	
}

}
