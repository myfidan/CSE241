#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include"hw4_classroom.h"
#include"hw4_student.h"

namespace Fidan_class{
	
	using namespace std;

int Student::enrollCourse(vector<Course> lesson,int ders_id){//enrolll
	int x=-1;
	int counter=0;
	int not_overlap=0;
	for(int i=0; i<lesson.size(); i++){
		if(lesson[i].id==ders_id) x=i;
	}
	
	if((remained_credi-lesson[x].credit)<0){//credi check
		cout<<"ERROR:Because of Credits";
		return remained_credi;
	}
	
	for(int i=0; i<list.size(); i++){//student check
		if(list[i].lesson_id==lesson[x].id){
			cout<<"ERROR: STUDENT ALREAY ENROLL THIS COURSE";
			return remained_credi;
		}
	}
	
	liste temp;
	for(int i=0; i<lesson[x].lecture_dates.size(); i++){
	
		Date tut;
		tut.day=lesson[x].lecture_dates[i].day;
		tut.start_hour=lesson[x].lecture_dates[i].start_hour;
		tut.end_hour=lesson[x].lecture_dates[i].end_hour;
		temp.list_date.push_back(tut);
	}
	temp.total_hours=lesson[x].total_hours;
	temp.lesson_name=lesson[x].name;
	temp.lesson_id=lesson[x].id;
	temp.lesson_credi=lesson[x].credit;
	list.push_back(temp);
	
	//overlap check
	int overlap_flag=0;
	for(int i=0; i<list.size(); i++){
		for(int j=0; j<list[i].list_date.size(); j++){
			for(int k=0; k<list.size(); k++){
				for(int t=0; t<list[k].list_date.size(); t++){
					overlap_flag=0;
					if(list[i].lesson_id==list[k].lesson_id);
					else{
						if(list[i].list_date[j].day==list[k].list_date[t].day){
						
							if(list[i].list_date[j].start_hour==list[k].list_date[t].end_hour);
							if(list[i].list_date[j].start_hour<=list[k].list_date[t].start_hour && list[i].list_date[j].end_hour<=list[k].list_date[t].end_hour){
								if(list[i].list_date[j].end_hour-list[i].list_date[j].start_hour==2){
								
									if(abs(list[i].list_date[j].end_hour-list[k].list_date[t].start_hour==1)){
										if(overlap_flag==0){
											not_overlap++;
										}		
									}
									else if(abs(list[i].list_date[j].end_hour-list[k].list_date[t].start_hour==2)){
										if(overlap_flag==0){
											not_overlap=not_overlap+2;
										}
										overlap_flag=1;
									}
									if(not_overlap>(list[i].total_hours)/2){
										cout<<"Error: Because of overlap";
										list.erase(list.end() - 1);
										return remained_credi;
									}
								}	
							}
							
						}
					}
				}
			}
		}
	}
	
	remained_credi=remained_credi-lesson[x].credit;
	return (remained_credi);
}

int Student::disenroll(vector<Course> lesson,int ders_id){//dissenroll
	int x,y;
	for(int i=0; i<lesson.size(); i++){
		if(lesson[i].id==ders_id) x=i;
	}
	for(int i=0; i<list.size(); i++){
		if(list[i].lesson_id==ders_id) y=i;
	}
	int deneme_count=0;
	for(int i=0; i<list.size(); i++){
		if(list[i].lesson_id==lesson[x].id){
			++deneme_count;
			
		}
	}
	if(deneme_count==0){
		cout<<"Error:Student is not already taken this course";
		return remained_credi;
	}
	
	remained_credi=remained_credi+lesson[x].credit;
	list.erase(list.begin()+y);
	return remained_credi;
}



string Student::extractSchedule(){
	string extract_schedule;
	extract_schedule+=name+ " "+ surname+": ";
	for(int j=0; j<list.size(); j++){
		extract_schedule+=list[j].lesson_name + to_string(list[j].lesson_credi) + " ";
		
	}
	if(level==4){
		extract_schedule+="Total credits:"+ to_string(23-remained_credi)+'\n';
		extract_schedule+="Credit right for "+to_string(level) + ".Level student 23"+ '\n';
	}
	if(level==3){
		extract_schedule+="Total credits:"+ to_string(22-remained_credi)+'\n';
		extract_schedule+="Credit right for "+to_string(level) + ".Level student 22"+ '\n';
}
	if(level==2){
		extract_schedule+="Total credits:"+ to_string(21-remained_credi)+'\n';
		extract_schedule+="Credit right for "+to_string(level) + ".Level student 21"+ '\n';
}
	if(level==1){
		extract_schedule+="Total credits:"+ to_string(20-remained_credi)+'\n';
		extract_schedule+="Credit right for "+to_string(level) + ".Level student 20"+ '\n';
}
	return extract_schedule;		
}

}
