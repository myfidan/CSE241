#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>

#include "hw4_student.h"
#include "hw4_lecturer.h"
#include "hw4_classroom.h"
#include "hw4_admin.h"

using namespace std;
 

int main(){
	using namespace Fidan_class;
	
	Administrator Admin;
	vector<Lecturer> lecturers;
	vector<Course> courses;
	vector<Classroom> classrooms;
	vector<Student> students;
	vector<Attendance> attendance;//attendance 
	vector<Attendance_hour> tut_hours;
	
	string read_word;
	int read_int;
	int assign=0,timetable=0;
	srand(time(NULL));
	ifstream read;
	read.open("lecturers.txt");//open lecturers file for read
	
	while(read>>read_int){//read lecturers
		Lecturer lect_temp;
		lect_temp.set_id(read_int);
		read>>read_word;
		lect_temp.set_name(read_word);
		read>>read_word;
		lect_temp.set_surname(read_word);
		read>>read_word;
		lect_temp.set_title(read_word);
		read>>read_word;
		//parse proffesions
		char copy[read_word.size()+1];
		strcpy(copy,read_word.c_str());
		char *take=strtok(copy,",");
		while(take!=NULL){
			lect_temp.proffesions.push_back(take);
			take=strtok(NULL,",");
		}
		
		lecturers.push_back(lect_temp);
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
			
			temp.set_class_id(class_id++);
			read_course>>read_word;
			read_word.erase(read_word.begin());
			temp.set_class_no(stoi(read_word));
			read_course>>read_int;
		
			temp.set_class_capacity(read_int);
			temp.set_class_inroom(0);
			
			classrooms.push_back(temp);
		}
	}
	string input;
	//
	
	
		
	
	input="-propose 2 deneme_1 111 1 1 CYBER";		
	lecturers[0].proposeCourse(input);
	
	input="-propose 1 secmeli_1 111 1 1 MATH";		
	lecturers[0].proposeCourse(input);
	input="-propose 1 secmeli_2 111 1 1 OS";		
	lecturers[1].proposeCourse(input);
	input="-propose 3 secmeli_3 111 1 1 AI";	
	lecturers[1].proposeCourse(input);
	input="-propose 3 secmeli_4 111 1 1 PROG";		
	lecturers[2].proposeCourse(input);
	input="-propose 4 secmeli_5 111 1 1 ALG";		
	lecturers[2].proposeCourse(input);
	input="-propose 4 secmeli_6 111 1 1 ARCH";		
	lecturers[3].proposeCourse(input);
	input="-propose 5 secmeli_7 111 1 1 MATH";		
	lecturers[3].proposeCourse(input);
	input="-propose 5 secmeli_8 111 1 1 MACH";		
	lecturers[4].proposeCourse(input);
	input="-propose 6 secmeli_9 111 1 1 MATERIAL";		
	lecturers[4].proposeCourse(input);	
	input="-propose 6 secmeli_10 111 1 1 MATH";		
	lecturers[5].proposeCourse(input);	
	input="-propose 7 secmeli_11 111 1 1 PHY";		
	lecturers[5].proposeCourse(input);	
	input="-propose 7 secmeli_12 111 1 1 MACH";		
	lecturers[6].proposeCourse(input);	
	input="-propose 7 secmeli_13 111 1 1 PROG";		
	lecturers[6].proposeCourse(input);	
	
	//
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
							lecturers[x].assignCourse(courses[i]);/******ASSÝGN FUNCTÝON CALLED******/
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
		//
		int check=0;
		if(assign==1){
			
			/*for(int i=0; i<lecturers.size(); i++){
				for(int j=0; j<lecturers[i].courses.size(); j++){
					
					lecturers[i].courses[j].lecture_dates.clear();
				}
			}*/
			
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
			
			
			for(int x=0; x<lecturers.size(); x++){
						
						for(int y=0; y<lecturers[x].courses.size(); y++){
							
							for(int w=0; w<courses.size(); w++){
								
								if(lecturers[x].courses[y].id==courses[w].id){
									if(courses[w].lecture_dates.size()==0){
									
										courses[w].lecture_dates.push_back(lecturers[x].courses[y].lecture_dates[0]);
										
							
									}
									else{
										break;
									}
									
								}	
							}
							
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
		//
		
		for(int i=0; i<lecturers.size(); i++){
			for(int j=0; j<lecturers[i].courses.size(); j++){
				//buraya dön
				bool flag=true;
				while(flag){
				
				flag=false;
				int random_class=rand()%6+1;
				lecturers[i].courses[j].course_class.set_class_id(rand()%6+1);
				for(int k=0; k<lecturers.size(); k++){
					for(int t=0; t<lecturers[k].courses.size(); t++){
						if(lecturers[k].courses[t].course_class.get_class_id()==lecturers[i].courses[j].course_class.get_class_id() && lecturers[k].courses[t].id!=lecturers[i].courses[j].id){
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
					cout<<lecturers[i].courses[j].course_class.get_class_id()<<". class ";
					for(int z=0; z<courses.size(); z++){
						if(courses[z].name==lecturers[i].courses[j].name){
							courses[z].course_class.set_class_id(lecturers[i].courses[j].course_class.get_class_id());
						}
					}
					cout<<"at "<<lecturers[i].courses[j].lecture_dates[0].day<<"_"<<lecturers[i].courses[j].lecture_dates[0].start_hour<<"-"<<lecturers[i].courses[j].lecture_dates[0].end_hour;
					if(j!=lecturers[i].courses.size()-1) cout<<" / ";
			}
			cout<<endl;
		}
		
	
	
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
	//create students
	if(input[0] =='-' && input[1]=='n' && input[2]=='s'){
		int arr[5];
		string tut[3];
		string x;
		int num;
		stringstream stream(input);
			for(int i=0; i<5; i++){
				if(i<3)stream>>x;
				else{
				stream>>num;
			
				}
				if(!stream)break;
				if(i<3){
					tut[i]=x;
				}
				else{
					arr[i]=num;
				}
			
				
			}
		Student temp;
		temp.get_name()=tut[1];
		temp.get_surname()=tut[2];
		temp.get_no()=arr[3];
		temp.get_level()=arr[4];
		if(arr[4]==4)temp.get_credi()=23;
		if(arr[4]==3)temp.get_credi()=22;
		if(arr[4]==2)temp.get_credi()=21;
		if(arr[4]==1)temp.get_credi()=20;
		students.push_back(temp);
	}//show all courses
	else if(input[0]=='-' && input[1]=='l' && input[2]=='i' && input[3]=='s' && input[4]=='t'){
		for(int i=0; i<courses.size(); i++){
				cout<<"("<<i+1<<")"<<courses[i].name;
			}
			cout<<endl;
	}//show students informations
	else if(input[0]=='-' && input.length()==2 && input[1]=='o'){
		for(int i=0; i<students.size(); i++){
						
				cout<<students[i].extractSchedule();//********using extractschedule for returnin student informations as string after that cout this string in terminal
				
			}
	}//disenroll student from a course
	else if(input[0]=='-' && input[1]=='d' && input[2]=='e'){
		int num;
			string y;
			int arr[3];
			stringstream stream(input);
			for(int i=0; i<3; i++){
				if(i==0){
					stream>>y;
					arr[0]=0;
				}
				else{
					stream>>num;
					if(!stream)break;
					arr[i]=num;
				}
			}
			int x;
			for(int i=0; i<students.size(); i++){
				if(students[i].get_no()==arr[1]){
					x=i;	
					break;
				}
			}
			int ders_id=arr[2];
			int tut=students[x].get_credi();
			students[x].get_credi()=students[x].disenroll(courses,ders_id);
			if(tut!=students[x].get_credi()){
				cout<<"(output)> DONE!";
				
			}
	}//prints one students information screen
	else if(input[0]=='-' && input[1]=='o' && input[4]!='f' && input.length()>2){
		cout<<"(output)>";
			int num;
			int arr[3];
			string y;
			stringstream stream(input);
			for(int i=0; i<2; i++){
				if(i==0){
					stream>>y;
					arr[0]=0;
				}
				else{
				stream>>num;
				if(!stream)break;
				arr[i]=num;	
				}		
			}
			int x;
			
			for(int i=0; i<students.size(); i++){
				if(students[i].get_no()==arr[1]){
					x=i;	
					break;
				}
			}
			
			cout<<students[x].extractSchedule();
	}//enroll a course for a student
/*	else if(input[0]=='-' && input[1]=='e'){
		int num;
			int arr[3];
			string y;
			stringstream stream(input);
			for(int i=0; i<3; i++){
				if(i==0){
					stream>>y;
					arr[0]=0;
				}
				else{
					stream>>num;
				if(!stream)break;
				arr[i]=num;
				}
				
			
			}
			int x=-1;
			for(int i=0; i<students.size(); i++){
				if(students[i].get_no()==arr[1]){
					x=i;	
					break;
				}
			}
			if(x==-1){
				cout<<"ERROR: NO STUDENT";
			}
			else{
				int ders_id=arr[2];
				int tut=students[x].get_credi();
				students[x].get_credi()=students[x].enrollCourse(courses,ders_id);
				if(tut!=students[x].get_credi()){
					cout<<"(output)> DONE!"<<endl;
				
				}
			}	
	}*/
	//prints all student informations in a txt file
	else if(input[0]=='-' && input[1]=='o' && input[3]=='-' && input[4]=='f' && bosluk==2){
		string y;
			stringstream stream(input);
			for(int i=0; i<3; i++){
					stream>>y;
				if(!stream)break;		
			}
			
			
			ofstream yaz;
			yaz.open(y.c_str());
				
			for(int i=0; i<students.size(); i++){
						yaz<<students[i].extractSchedule();
				
			}
			cout<<"(output)> DONE! "<<y.c_str()<<endl;
			yaz.close();
	}//prints a student informations in a file
	else if(input[0]=='-' && input[1]=='o' && input[3]=='-' && input[4]=='f' && bosluk==3){
		int num;
			int arr[4];
			string y;
			stringstream stream(input);
			for(int i=0; i<4; i++){
				if(i==0 || i==1 || i==3 ){
					stream>>y;
					arr[i]=0;
				}
				else{
				stream>>num;
				if(!stream)break;
				arr[i]=num;	
				}		
			}
			int x;
			
			ofstream yaz;
			yaz.open(y.c_str());
			
			for(int i=0; i<students.size(); i++){
				if(students[i].get_no()==arr[2]){
					x=i;	
					break;
				}
			}
			yaz<<students[x].extractSchedule();
			cout<<"DONE! "<<y.c_str()<<endl;
			yaz.close();
		}
		else if(input[0]=='-' && input[1]=='p' && input[2]=='r' && input[3]=='o' && input[4]=='p' && input[5]=='o' && input[6]=='s' && input[7]=='e'){/**********PROPOSE LECTURE********/
			
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
				lecturers[i].proposeCourse(input);/*PROPOSE FUNCTÝON CALLED*/
			}
		}
	}
	//assign one course to one lecturer
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
				lecturers[hold_lecture].assignCourse(courses[hold_course]);/**********ASSÝGN FUNCTÝON CALL**********/
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
							lecturers[x].assignCourse(courses[i]);/******ASSÝGN FUNCTÝON CALLED******/
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
		
	}//TÝMETABLE FOR ONE COURSE
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
			
			Admin.arrangeTimeTable(courses[b-1]);/********arrangeTimeTable FUNCTÝON CALLED*********/
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
	}//AUTO TÝMETABLE FOR ALL COURSES
	else if(input[0]=='-' && input[1]=='t' && input[2]=='i' && input[3]=='m' && input[4]=='e' && input.size()==10){
		
		int check=0;
		if(assign==1){
			
			/*for(int i=0; i<lecturers.size(); i++){
				for(int j=0; j<lecturers[i].courses.size(); j++){
					
					lecturers[i].courses[j].lecture_dates.clear();
				}
			}*/
			
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
			
			
			for(int x=0; x<lecturers.size(); x++){
						
						for(int y=0; y<lecturers[x].courses.size(); y++){
							
							for(int w=0; w<courses.size(); w++){
								
								if(lecturers[x].courses[y].id==courses[w].id){
									if(courses[w].lecture_dates.size()==0){
									
										courses[w].lecture_dates.push_back(lecturers[x].courses[y].lecture_dates[0]);
										
							
									}
									else{
										break;
									}
									
								}	
							}
							
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
			if(x[1]==classrooms[k].get_class_id()){
				check_class=true;
				tut_class=classrooms[k].get_class_id();
			} 
		}
		
		if(timetable==0 || check_course==false || check_class==false){
			cout<<"Error:no class or no course or timetable not arranged yet"<<endl;
		}else if(tut_class==1){
			courses[tut_course-1].course_class.set_class_id(1);
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
			if(x[1]==classrooms[k].get_class_id()){
				check_class=true;
				tut_class=classrooms[k].get_class_id();
			} 
		}
		
		if(timetable==0 || check_course==false || check_class==false){
			cout<<"Error:no class or no course or timetable not arranged yet"<<endl;
		}else if(tut_class==1){
			courses[tut_course-1].course_class.set_class_id(1);
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
				lecturers[i].courses[j].course_class.set_class_id(rand()%6+1);
				for(int k=0; k<lecturers.size(); k++){
					for(int t=0; t<lecturers[k].courses.size(); t++){
						if(lecturers[k].courses[t].course_class.get_class_id()==lecturers[i].courses[j].course_class.get_class_id() && lecturers[k].courses[t].id!=lecturers[i].courses[j].id){
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
					cout<<lecturers[i].courses[j].course_class.get_class_id()<<". class ";
					for(int z=0; z<courses.size(); z++){
						if(courses[z].name==lecturers[i].courses[j].name){
							courses[z].course_class.set_class_id(lecturers[i].courses[j].course_class.get_class_id());
						}
					}
					cout<<"at "<<lecturers[i].courses[j].lecture_dates[0].day<<"_"<<lecturers[i].courses[j].lecture_dates[0].start_hour<<"-"<<lecturers[i].courses[j].lecture_dates[0].end_hour;
					if(j!=lecturers[i].courses.size()-1) cout<<" / ";
			}
			cout<<endl;
		}
		
	
	}
	else if(input[0]=='-' && input[1]=='e' && input[2]=='n' && input[3]=='t' && input[4]=='e' && input[5]=='r'){
	
		int take[3];
		string a;
		stringstream stream(input);
		for(int i=0; i<4; i++){
			if(i==1){
				stream>>take[0];//student_id
			}
			else if(i==0){
				stream>>a;
			}
			else if(i==2){
				stream>>take[1];//classroom_id
			} 
			else if(i==3){
				stream>>take[2];//hour of week
			}
			if(!stream)break;			
		}
		int check_student=0;
		int check_class=0;
		for(int i=0; i<students.size(); i++){
			if(students[i].get_no()==take[0])check_student=1;
		}
		
		if(take[2]>=0 && take[2]<8){
			for(int i=0; i<courses.size(); i++){
				if(courses[i].lecture_dates[0].day=="Mon"){
					if(courses[i].course_class.get_class_id()==take[1]){
						if(courses[i].lecture_dates[0].start_hour-9<=take[2] && courses[i].lecture_dates[0].end_hour-9>take[2]){
							check_class=1;
						}
					}
				}
			}
		}
		else if(take[2]>=8 && take[2]<16){
			for(int i=0; i<courses.size(); i++){
				if(courses[i].lecture_dates[0].day=="Tues"){
					if(courses[i].course_class.get_class_id()==take[1]){
						if(courses[i].lecture_dates[0].start_hour-9<=take[2]-8 && courses[i].lecture_dates[0].end_hour-9>take[2]-8){
							check_class=1;
						}
					}
				}
			}
		}
		else if(take[2]>=16 && take[2]<24){
			for(int i=0; i<courses.size(); i++){
				if(courses[i].lecture_dates[0].day=="Wed"){
					if(courses[i].course_class.get_class_id()==take[1]){
						if(courses[i].lecture_dates[0].start_hour-9<=take[2]-16 && courses[i].lecture_dates[0].end_hour-9>take[2]-16){
							check_class=1;
						}
					}
				}
			}
		}
		else if(take[2]>=24 && take[2]<32){
			for(int i=0; i<courses.size(); i++){
				if(courses[i].lecture_dates[0].day=="Thurs"){
					if(courses[i].course_class.get_class_id()==take[1]){
						if(courses[i].lecture_dates[0].start_hour-9<=take[2]-24 && courses[i].lecture_dates[0].end_hour-9>take[2]-24){
							check_class=1;
						}
					}
				}
			}
		}
		else if(take[2]>=32 && take[2]<40){
			for(int i=0; i<courses.size(); i++){
				if(courses[i].lecture_dates[0].day=="Fri"){
					if(courses[i].course_class.get_class_id()==take[1]){
						if(courses[i].lecture_dates[0].start_hour-9<=take[2]-32 && courses[i].lecture_dates[0].end_hour-9>take[2]-32){
							check_class=1;
						}
					}
				}
			}
		}
		int check_class_chance=0;
		for(int i=0; i<attendance.size(); i++){
			if(attendance[i].student_id_number==take[0]){
				if(attendance[i].in_a_class==1){
					if(attendance[i].class_id_number!=take[1]){
						check_class_chance=1;
					}
				}
			}
		}
		if(check_class_chance==1)cout<<"s/he is another classroom";
		else if(check_student==1 && check_class==1){
			for(int i=0; i<classrooms.size(); i++){
				if(classrooms[i].get_class_id()==take[1]){
					if(classrooms[i].get_class_inroom()==classrooms[i].get_class_capacity()){
						cout<<"No capacity in this class";
					}
					else{
						
						classrooms[i].set_class_inroom(classrooms[i].get_class_inroom()+1);		
						cout<<classrooms[i].get_class_inroom()<<"(Student inroom)";
					}
				}
			}
		
			int check=0;
			int check_2=0;
		
			Attendance x=classrooms[0].enterClassroom(take[1],take[0],take[2],courses);
			x.in_a_class=1;
			Attendance_hour temp;
			temp.hour.push_back(x.hours[0]);
			temp.stu_no=x.student_id_number;
			
			tut_hours.push_back(temp);
			
			for(int i=0; i<attendance.size(); i++){
				if(attendance[i].student_id_number==x.student_id_number){
					attendance[i].hours.push_back(take[2]);
					check=1;
					for(int k=0; k<attendance[i].hours.size(); k++){
						
						if(attendance[i].hours[k]==take[2]){
						
							check_2++;
						}
					}
					if(check_2==1){
						attendance[i].attendance_score++;	
					}
				}
			}
			if(check==0){
				x.in_a_class=take[1];
				attendance.push_back(x);	
			}
		}
		else{
			cout<<"Error no student or class";
		}
	//	cout<<attendance.size();
	/*	for(int i=0; i<attendance.size(); i++){
			cout<<attendance[i].student_id_number<<"-"<<attendance[i].attendance_score<<endl;
		}
		*/
	}
	else if(input[0]=='-' && input[1]=='q' && input[2]=='u' && input[3]=='i' && input[4]=='t'){
		int y;
		string a;
		stringstream stream(input);
		for(int i=0; i<2; i++){
			if(i==1){
				stream>>y;//student_id
			}
			else if(i==0){
				stream>>a;
			}
		
			if(!stream)break;			
		}
	
		for(int i=0; i<attendance.size(); i++){
			if(attendance[i].student_id_number==y){
				attendance[i].in_a_class=-1;
				classrooms[attendance[i].class_id_number-1].set_class_inroom(classrooms[attendance[i].class_id_number-1].get_class_inroom()-attendance[i].hours.size());
				cout<<classrooms[attendance[i].class_id_number-1].get_class_inroom()<<"(Student inroom)"<<endl;
			}
		}
	}
	else if(input[0]=='-' && input[1]=='a' && input[2]=='t' && input[3]=='t' && input[4]=='e' && input[5]=='n' && input[6]=='d' && input[7]=='a' && input[8]=='n' && input[9]=='c' && input[10]=='e'){
		
		int y;
		string a;
		stringstream stream(input);
		for(int i=0; i<2; i++){
			if(i==1){
				stream>>y;//course_id
			}
			else if(i==0){
				stream>>a;
			}
		
			if(!stream)break;			
		}
	
		for(int i=0; i<attendance.size(); i++){
			if(attendance[i].course_id_number==y){
				for(int j=0; j<students.size(); j++){
					if(attendance[i].student_id_number==students[j].get_no()){
						cout<<students[j].get_name();
					}
				}
				cout<<"-"<<attendance[i].attendance_score<<endl;
			}
		}
	}
	else{
		cout<<"Wrong input";
	}
	
}
	


	return 0;
}

