#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>

using namespace std;

struct Course;
struct Classroom;
struct liste;
struct date;

class Student{
	public:
		int enrollCourse(vector<Course>,int ders_id);
		int disenroll(vector<Course>,int ders_id);
		string extractSchedule();
		void enterClassroom(Classroom&);
		void quitClassroom(Classroom&);
		
		int& get_no(){
			return student_no;
		}
		int& get_credi(){
			return remained_credi;
		}
		string& get_name(){
			return name;
		}
		string& get_surname(){
			return surname;
		}
		int& get_level(){
			return level;
		}
		vector<liste> list;
	private:
		string name,surname;
		int student_no,level,remained_credi;
	
		
};

struct Course{
	int id,code,credit,total_hours;
	string name,field;
	vector<date> lecture_dates;
};

struct Classroom{
	int id,capacity,student_inroom;
	string c_no;
};

struct liste{
	string lesson_name;
	int lesson_id,lesson_credi,total_hours;
	vector<date> list_date;
};

struct date{
	string day;
	int start_hour;
	int end_hour;
};

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
	
		date tut;
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

void Student::enterClassroom(Classroom& class_x){
	
	
	
	if(class_x.student_inroom+1<=class_x.capacity){
		++class_x.student_inroom;
	}
	else{
		cout<<"Error: There is no capacity in this class";
	}
	
}

void Student::quitClassroom(Classroom& class_x){
	if(class_x.student_inroom-1>=0){
		--class_x.student_inroom;
	}
	else{
		cout<<"Error : There is no student in this class";
	}
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
	


int main(){
	vector<Student> students;///students
	vector<Course> courses;
	vector<Classroom> classrooms;
	vector<int> student_num;
	Classroom class_;
	class_.student_inroom=0;
	class_.capacity=60;
	
	
	Student temp;
	Course temp_course;
	Classroom temp_classroom;
	string kelimeler;//read file
	string read_word;
	int total_student_in_class=1;
	int read_int;
	string kelime1,kelime2;
	char harf1,harf2;
	string file;
	int sayi1,sayi2,sayi3,sayi4;
	int counter_1=0;
	ifstream read;
	read.open("courses_classrooms.txt");
	ofstream write("file.txt");
	
	int counter_2=0;
	
	int id_1=1;
	int id_2=1;
	while(read>>read_word || read>>read_int){
		
	
		if(read_word=="CLASSROOMS"){
			
			
			counter_2++;	
		} 
		else if(read_word=="COURSES");
		else if(counter_2==0){
			
			
			
			
			temp_course.id=id_1;
			id_1++;
			read>>read_word;
			temp_course.name=read_word;
			
			read>>read_int;
			temp_course.code=read_int;
			read>>read_int;
			temp_course.credit=read_int;
			read>>read_int;
			temp_course.total_hours=read_int;
			read>>read_word;
		//	temp_course.lecture_dates=read_word;//
			
	date temp_date;
	string x=read_word;		
	string y;
	string z;
	string a;
	int start_hour;
	int end_hour;
	int k=0;
	int counter=0;
	int counter_2=0;
	for(int i=0; i<x.size(); i++){
		if(x[i]==','){
			for(int j=0; j<y.size(); j++){//print mon
				a+=y[j];
			}
			temp_date.day=a;
			temp_date.start_hour=start_hour;
			temp_date.end_hour=end_hour;
			temp_course.lecture_dates.push_back(temp_date);
			temp_date.day.clear();
			a.clear();
			y.clear();
			counter=0;
			counter_2=0;
			k=0;
		}
		else if(x[i]=='_'){
			
			counter=1;
		}
		else if(counter==1){
			if(x[i]!='-'){
				if(x[i]!='9'){
				z[k]=x[i];
				k++;
				}
				else{
					
					z[k]=x[i];
					k=2;
					i++;
				}
				
				
			}
			if(k==2){
				if(counter_2==0){
					if(stoi(z)>=90){
						start_hour=9;
						counter_2=1;
					} 
					else{
						start_hour=stoi(z);
						counter_2=1;
					}
					
				}
				else{
					end_hour=stoi(z);
				}
				z.clear();
				k=0;
			}
		}
		else if(counter==0){
			y.push_back(x[i]);
			
		}
		
		}
			
		for(int i=0; i<y.size(); i++){
			a+=y[i];
		}
		
		temp_date.day=a;
		temp_date.start_hour=start_hour;
		temp_date.end_hour=end_hour;
		temp_course.lecture_dates.push_back(temp_date);
		temp_date.day.clear();
		a.clear();
		y.clear();	
			
		
			
			
			
		courses.push_back(temp_course);
		temp_course.lecture_dates.clear();
		}
		if(counter_2==1){
			
			if(read_word=="CLASSROOMS");
			else{
				
				temp_classroom.id=id_2;
				id_2++;
				read>>read_word;
				temp_classroom.c_no=read_word;
				read>>read_int;
				temp_classroom.capacity=read_int;
				
				classrooms.push_back(temp_classroom);
			}
		}
		
	}
	
	int arr[5];
	string tut[3];
	string x;
	int num;
	int counter_white_space=0;
	while(kelimeler !="exit"){
		
		counter_white_space=0;
		
		cout<<"(input)>";
		getline(cin,kelimeler);
				
		
		for(int i=0; i<kelimeler.length(); i++){
			if(kelimeler[i]==' '){
				counter_white_space++;
			}
		}
		
		if(kelimeler=="exit") break;
		else if(kelimeler[0] =='-' && kelimeler[1]=='n' && kelimeler[2]=='s'){
			
	
		if(counter_white_space!=4){
			cout<<"ERROR";
		}
		stringstream stream(kelimeler);
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
		temp.get_name()=tut[1];
		temp.get_surname()=tut[2];
		temp.get_no()=arr[3];
		temp.get_level()=arr[4];
		if(arr[4]==4)temp.get_credi()=23;
		if(arr[4]==3)temp.get_credi()=22;
		if(arr[4]==2)temp.get_credi()=21;
		if(arr[4]==1)temp.get_credi()=20;
		students.push_back(temp);
			
		}
		else if(kelimeler[0]=='-' && kelimeler[1]=='l' && kelimeler[2]=='i' && kelimeler[3]=='s' && kelimeler[4]=='t'){//-list
			cout<<"(output)>";
			for(int i=0; i<courses.size(); i++){
				cout<<"("<<i+1<<")"<<courses[i].name;
			}
			cout<<endl;
		}
		else if(kelimeler[0]=='-' && kelimeler.length()==2 && kelimeler[1]=='o'){//print all student informations in terminal
			//o
			cout<<"(output)>";
			for(int i=0; i<students.size(); i++){
						
				cout<<students[i].extractSchedule();//********using extractschedule for returnin student informations as string after that cout this string in terminal
				
			}
			
		}
		else if(kelimeler[0]=='-' && kelimeler[1]=='d' && kelimeler[2]=='e'){//this code disenroll a course
		//dissenroll
			int num;
			string y;
			int arr[3];
			stringstream stream(kelimeler);
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
				students[x].quitClassroom(class_);
			}
		}
		else if(kelimeler[0]=='-' && kelimeler[1]=='o' && kelimeler[4]!='f' && kelimeler.length()>2){//this code print a student informations in terminal
		//-o 111
			cout<<"(output)>";
			int num;
			int arr[3];
			string y;
			stringstream stream(kelimeler);
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
		
		}
		else if(kelimeler[0]=='-' && kelimeler[1]=='e'){//this code for enroll course
		//111 1//-e 111 1
			int num;
			int arr[3];
			string y;
			stringstream stream(kelimeler);
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
					students[x].enterClassroom(class_);
				}
			}
		
		}
		else if(kelimeler[0]=='-' && kelimeler[1]=='o' && kelimeler[3]=='-' && kelimeler[4]=='f' && counter_white_space==2){//this code print all student informations in a txt file
			//0 file.txt
			
			
			string y;
			stringstream stream(kelimeler);
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
		}
		else if(kelimeler[0]=='-' && kelimeler[1]=='o' && kelimeler[3]=='-' && kelimeler[4]=='f' && counter_white_space==3 ){//This code print a student informations in a txt file
			//-o -f 111 file.txt
			
			
			int num;
			int arr[4];
			string y;
			stringstream stream(kelimeler);
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
	}
	
	
	write.close();
	read.close();
	return 0;
}
