#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include "hw3_class.h"

using namespace std;

int main(){
	Administrator Admin;
	vector<Lecturer> lecturers;
	vector<Course> courses;
	vector<Classroom> classrooms;
	string read_word;
	int read_int;
	int assign=0,timetable=0;
	srand(time(NULL));
	ifstream read;
	read.open("lecturers.txt");//open lecturers file for read
	
	while(read>>read_int){//read lecturers
		Lecturer temp;
		temp.set_id(read_int);
		read>>read_word;
		temp.set_name(read_word);
		read>>read_word;
		temp.set_surname(read_word);
		read>>read_word;
		temp.set_title(read_word);
		read>>read_word;
		//parse proffesions
		char copy[read_word.size()+1];
		strcpy(copy,read_word.c_str());
		char *take=strtok(copy,",");
		while(take!=NULL){
			temp.proffesions.push_back(take);
			take=strtok(NULL,",");
		}
		
		lecturers.push_back(temp);
	}
	//read classroom and class
	ifstream read_course;
	read_course.open("courses_classrooms.txt");
	int course_id=1;
	int class_id=1;
	int read_classrooms=0;
	while(read_course>>read_word || read_course>>read_int){
		if(read_word=="COURSES");
		else if(read_word=="CLASSROOMS"){
			read_classrooms++;
		}
		else if(read_classrooms==0){//read courses
			Course temp;
			temp.id=course_id++;
			read_course>>read_word;
			temp.name=read_word;
			read_course>>read_int;
			temp.code=read_int;
			read_course>>read_int;
			temp.credit=read_int;
			read_course>>read_int;
			temp.total_hours=read_int;
			read_course>>read_word;
			temp.field=read_word;
			
			courses.push_back(temp);
		}
		else{//read classrooms
			Classroom temp;
			temp.id=class_id++;
			read_course>>read_word;
			read_word.erase(read_word.begin());
			temp.c_no=stoi(read_word);
			read_course>>read_int;
			temp.capacity=read_int;
			
			classrooms.push_back(temp);
		}
	}
	string input;
	
	
	
	while(input!="exit"){
		getline(cin,input);
		int bosluk=0;
		int virgul=0;
		for(int t=0; t<input.size(); t++){
			if(input[t]==' ')bosluk++;
			if(input[t]==',')virgul++;
		}
		int x[4];
		string y[2];
		/**********PROPOSE LECTURE********/
		if(input[0]=='-' && input[1]=='p' && input[2]=='r' && input[3]=='o' && input[4]=='p' && input[5]=='o' && input[6]=='s' && input[7]=='e'){
			
			string a;
			int b;
			stringstream stream(input);
			for(int i=0; i<7; i++){
				if(i==0)stream>>a;
				else if(i==1){
					stream>>b;
					x[0]=b;
				}
				if(!stream)break;			
		}
		for(int i=0; i<lecturers.size(); i++){
			if(lecturers[i].get_id()==x[0]){
				lecturers[i].proposeCourse(input);/*PROPOSE FUNCTİON CALLED*/
			}
		}
		
	
		
		
	}//assign one course to one lecturer
	else if(input[0]=='-' &&input[1]=='a' && input[2]=='s' && input[3]=='s' && input[4]=='i' && input[5]=='g' && input[6]=='n' && input[7]==' '){
		int x[2];
		int tut=0;
		int b;
		string a;
		stringstream stream(input);
		for(int i=0; i<3; i++){
			if(i==1){
				stream>>b;
				x[0]=b;
			}
			else if(i==2){
				stream>>b;
				x[1]=b;
			}
			else if(i==0){
				stream>>a;
			}
			if(!stream)break;			
		}
		int flag1=0;
		int flag2=0;
		int hold_lecture,hold_course;
		for(int i=0; i<lecturers.size(); i++){
			if(lecturers[i].get_id()==x[0]){
				flag1=1;
				hold_lecture=i;
			}
		}
		for(int i=0; i<courses.size(); i++){
			if(courses[i].id==x[1]){
				flag2=1;
				hold_course=i;
			}
		}
		int check_prof=0;
		if(flag1==1 && flag2==1){
			string course_prof=courses[hold_course].field;
			for(int i=0; i<lecturers[hold_lecture].proffesions.size(); i++){
				if(lecturers[hold_lecture].proffesions[i]==course_prof){
					check_prof=1;
				}
			}
		}
		else{
			cout<<"Error:no lecture or course"<<endl;
			tut++;
		}
		
		if(check_prof==1){
			if(lecturers[hold_lecture].courses.size()<3){
				lecturers[hold_lecture].assignCourse(courses[hold_course]);/**********ASSİGN FUNCTİON CALL**********/
				cout<<"DONE"<<endl;
			}
			else{
				cout<<"Error This lecture already has 3 courses"<<endl;
			}
			
		}
		else{
			if(tut==0){		
				cout<<"Block:Field and profession mismatch"<<endl;
			}
		}
		
	}//auto assign all courses to the lecturers
	else if(input[0]=='-' && input[1]=='a' && input[2]=='s' && input[3]=='s' && input[4]=='i' && input[5]=='g' && input[6]=='n' && input.size()==7){
		bool flag=false;
		int verilen_ders=0;
		while(verilen_ders!=18){
			verilen_ders=0;
			for(int i=0; i<lecturers.size(); i++){
				lecturers[i].courses.clear();
			}
			lecturers[0].courses.push_back(courses[17]);
			lecturers[0].courses.push_back(courses[8]);
			verilen_ders=2;
			for(int i=0; i<courses.size()-1; i++){
				int say=0;
				if(i==8);
				else{
					flag=false;
				while(!flag){
					say++;
					if(say==30)break;
					int x=rand()%6+1;
				if(lecturers[x].courses.size()<3){
					for(int k=0; k<lecturers[x].proffesions.size(); k++){
						if(courses[i].field==lecturers[x].proffesions[k]){
							lecturers[x].assignCourse(courses[i]);/******ASSİGN FUNCTİON CALLED******/
							verilen_ders++;
							flag=true;
							break;
						}	
					}	
				}		
				}
				}
					
			}
		}
		for(int i=0; i<lecturers.size(); i++){
			if(lecturers[i].courses.size()==2 && lecturers[i].elect_courses.size()>0){
				lecturers[i].courses.push_back(lecturers[i].elect_courses[0]);
			}
			else if(lecturers[i].courses.size()==1 && lecturers[i].elect_courses.size()>0){
				lecturers[i].courses.push_back(lecturers[i].elect_courses[0]);
				lecturers[i].courses.push_back(lecturers[i].elect_courses[1]);
			}
		}
		int tut=0;
		for(int i=0; i<lecturers.size(); i++){
			if(lecturers[i].courses.size()!=3){
				tut=-1;
			}
		}
		if(tut==-1){
			cout<<"Error:Some lecturers dont have 3 lesson please propose some lecture and try again assign"<<endl;
		}
		else{
			assign=1;
		}
		
		for(int i=0; i<lecturers.size(); i++){
		cout<<lecturers[i].get_name()<<": ";
		for(int j=0; j<lecturers[i].courses.size(); j++){
			cout<<lecturers[i].courses[j].name<<" ";
			if(j!=lecturers[i].courses.size()-1)cout<<"/ ";
		}
		cout<<endl;
		}
		cout<<endl;
		
	}//TİMETABLE FOR ONE COURSE
	else if(input[0]=='-' && input[1]=='t' && input[2]=='i' && input[3]=='m' && input[4]=='e' && input.size()>9 && input[10]==' '){
	
		int b;
		string a;
		stringstream stream(input);
		for(int i=0; i<2; i++){
			if(i==1){
				stream>>b;
			}
			else if(i==0){
				stream>>a;
			}
			if(!stream)break;			
		}
		int flag=0;
		for(int i=0; i<courses.size(); i++){
			if(courses[i].id==b) flag=1;
		}
		if(flag==0){
			cout<<"Error: no class";
		}
		else if(courses[b-1].lecture_dates.size()==0){
			
			Admin.arrangeTimeTable(courses[b-1]);/********arrangeTimeTable FUNCTİON CALLED*********/
			cout<<"DONE:("<<courses[b-1].name<<") "<<courses[b-1].lecture_dates[0].day<<"_"<<courses[b-1].lecture_dates[0].start_hour<<"-"<<courses[b-1].lecture_dates[0].end_hour<<endl;
		}
		else{
			cout<<"Assigned Before: "<<courses[b-1].name<<" ";
			for(int i=0; i<courses[b-1].lecture_dates.size(); i++){
				cout<<courses[b-1].lecture_dates[i].day<<"_"<<courses[b-1].lecture_dates[i].start_hour<<"-"<<courses[b-1].lecture_dates[i].end_hour;
				if(i+1!=courses[b-1].lecture_dates.size()){
					cout<<",";
				}
			}
		}
	}//AUTO TİMETABLE FOR ALL COURSES
	else if(input[0]=='-' && input[1]=='t' && input[2]=='i' && input[3]=='m' && input[4]=='e' && input.size()==10){
		int check=0;
		if(assign==1){
			for(int i=0; i<lecturers.size(); i++){
				for(int j=0; j<lecturers[i].courses.size(); j++){
					lecturers[i].courses[j].lecture_dates.clear();
				}
			}
			
			for(int i=0; i<lecturers.size(); i++){
				for(int j=0; j<lecturers[i].courses.size(); j++){
					
					int max_start=17-lecturers[i].courses[j].total_hours;
					bool flag2=true;
					Date temp;
					while(flag2){
					flag2=false;
					int rand_day=rand()%5+1;
					
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
					for(int k=0; k<lecturers[i].courses.size(); k++){
						for(int z=0; z<lecturers[i].courses[k].lecture_dates.size(); z++){
						
							if(temp.day==lecturers[i].courses[k].lecture_dates[z].day){
								flag2=true;
							}	
						}
					}
					
					}
					bool flag=false;
					while(!flag){
						temp.start_hour=9+rand()%max_start;
						if(temp.start_hour<=max_start)flag=true;
					}
				
					temp.end_hour=temp.start_hour+lecturers[i].courses[j].total_hours;
					lecturers[i].courses[j].lecture_dates.push_back(temp);
				}
			}
			timetable=1;
		}
		
		else{
			cout<<"Error:Cant make a timetable because all lecturers dont have 3 lesson please propose some lesson and assign-timetable"<<endl;
			check=1;
		}
		if(check==0){
			for(int i=0; i<lecturers.size(); i++){
				cout<<lecturers[i].get_name()<<": ";
				for(int j=0; j<lecturers[i].courses.size(); j++){
					cout<<lecturers[i].courses[j].name<<"="<<lecturers[i].courses[j].lecture_dates[0].day<<" "<<lecturers[i].courses[j].lecture_dates[0].start_hour<<"-"<<lecturers[i].courses[j].lecture_dates[0].end_hour<<" "; 
				}
				cout<<endl;
			}
		}	
			
	}//ONLY 1 COURSE ARRANGE
	else if(input[0]=='-' && input[1]=='a' && input[2]=='r' && input[3]=='r' && input[4]=='a' && bosluk==2 && virgul==0){
		int x[2];
		string a;
		stringstream stream(input);
		for(int i=0; i<3; i++){
			if(i==1){
				stream>>x[0];
			}
			else if(i==0){
				stream>>a;
			}
			else if(i==2){
				stream>>x[1];
			} 
			if(!stream)break;			
		}
		bool check_course=false;
		bool check_class=false;
		int tut_class,tut_course;
		for(int j=0; j<courses.size(); j++){
			if(x[0]==courses[j].id){
				check_course=true;
				tut_course=courses[j].id;
			} 
		}
		for(int k=0; k<classrooms.size(); k++){
			if(x[1]==classrooms[k].id){
				check_class=true;
				tut_class=classrooms[k].id;
			} 
		}
		
		if(timetable==0 || check_course==false || check_class==false){
			cout<<"Error:no class or no course or timetable not arranged yet"<<endl;
		}else if(tut_class==1){
			courses[tut_course-1].course_class.id=1;
			string day;
			int start,end;
			for(int i=0; i<lecturers.size(); i++){
				for(int j=0; j<lecturers[i].courses.size(); j++){
					for(int z=0; z<lecturers[i].courses[j].lecture_dates.size(); z++){
						if(lecturers[i].courses[j].id==courses[tut_course-1].id){
							day=lecturers[i].courses[j].lecture_dates[z].day;
							start=lecturers[i].courses[j].lecture_dates[z].start_hour;
							end=lecturers[i].courses[j].lecture_dates[z].end_hour;
						}
					}
				}		
			}
			cout<<"DONE:("<<courses[tut_course-1].id<<")"<<courses[tut_course-1].name<<" in "<<tut_class<<" at "<<day<<"_"<<start<<"-"<<end;

		}
		else{
			Admin.arrangeClassroom(lecturers,courses[tut_course-1],tut_class);/************Arrange course function called********/
		}
		
	}//ONLY 2 COURSES ARRANGE
	else if(input[0]=='-' && input[1]=='a' && input[2]=='r' && input[3]=='r' && input[4]=='a' && bosluk==2 && virgul==1){
		int x[3];
		string a;
		stringstream stream(input);
		for(int i=0; i<4; i++){
			if(i==1){
				stream>>x[0];
			}
			else if(i==0){
				stream>>a;
			}
			else if(i==2){
				stream>>x[1];
			} 
			else if(i==3){
				stream>>x[2];
			}
			if(!stream)break;			
		}
		bool check_course=false;
		bool check_class=false;
		int tut_class,tut_course;
		for(int j=0; j<courses.size(); j++){
			if(x[0]==courses[j].id){
				check_course=true;
				tut_course=courses[j].id;
			} 
		}
		for(int k=0; k<classrooms.size(); k++){
			if(x[1]==classrooms[k].id){
				check_class=true;
				tut_class=classrooms[k].id;
			} 
		}
		
		if(timetable==0 || check_course==false || check_class==false){
			cout<<"Error:no class or no course or timetable not arranged yet"<<endl;
		}else if(tut_class==1){
			courses[tut_course-1].course_class.id=1;
			cout<<"DONE:("<<courses[tut_course-1].id<<")"<<courses[tut_course-1].name<<" in "<<tut_class<<" at "<<courses[tut_course-1].lecture_dates[0].day<<"_"<<courses[tut_course-1].lecture_dates[0].start_hour<<"-"<<courses[tut_course-1].lecture_dates[0].end_hour;

		}
		else{
			Admin.arrangeClassroom(lecturers,courses[tut_course-1],tut_class);/************Arrange course function called********/
		}
		
	}//AUTO ARRANGE ALL COURSES
	else if(input[0]=='-' && input[1]=='a' && input[2]=='r' && input[3]=='r' && input[4]=='a' && bosluk==0){
		
		for(int i=0; i<lecturers.size(); i++){
			for(int j=0; j<lecturers[i].courses.size(); j++){
				//buraya dön
				bool flag=true;
				while(flag){
				
				flag=false;
				int random_class=rand()%6+1;
				lecturers[i].courses[j].course_class.id=rand()%6+1;
				for(int k=0; k<lecturers.size(); k++){
					for(int t=0; t<lecturers[k].courses.size(); t++){
						if(lecturers[k].courses[t].course_class.id==lecturers[i].courses[j].course_class.id && lecturers[k].courses[t].id!=lecturers[i].courses[j].id){
							if(lecturers[k].courses[t].lecture_dates[0].day==lecturers[i].courses[j].lecture_dates[0].day){
								if((lecturers[i].courses[j].lecture_dates[0].start_hour<lecturers[k].courses[t].lecture_dates[0].start_hour && lecturers[i].courses[j].lecture_dates[0].end_hour>lecturers[k].courses[t].lecture_dates[0].start_hour) || (lecturers[i].courses[j].lecture_dates[0].start_hour>lecturers[k].courses[t].lecture_dates[0].start_hour && lecturers[i].courses[j].lecture_dates[0].end_hour>lecturers[k].courses[t].lecture_dates[0].start_hour )){
									flag=true;	
								}
							}
						}
					}
				}
			}
		}
	}
		for(int i=0; i<lecturers.size(); i++){
			cout<<lecturers[i].get_name()<<" "<<lecturers[i].get_surname()<<": ";
			for(int j=0; j<lecturers[i].courses.size(); j++){
					cout<<lecturers[i].courses[j].name<<" "<<"in ";
					cout<<lecturers[i].courses[j].course_class.id<<". class ";
					cout<<"at "<<lecturers[i].courses[j].lecture_dates[0].day<<"_"<<lecturers[i].courses[j].lecture_dates[0].start_hour<<"-"<<lecturers[i].courses[j].lecture_dates[0].end_hour;
					if(j!=lecturers[i].courses.size()-1) cout<<" / ";
			}
			cout<<endl;
		}
		
	}
	else{
		cout<<"Wrong input";
	}
	
}
	
	

	return 0;
}

