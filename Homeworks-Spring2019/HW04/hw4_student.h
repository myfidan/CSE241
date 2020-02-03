#ifndef HW4_STUDENT_H
#define HW4_STUDENT_H

#include<vector>
#include<string>
#include"hw4_classroom.h"


namespace Fidan_class{
	
	

	class Student{
		public:
			inline Student(){//constructer
				used=0;
				capacity=10;
				list_=new liste[capacity];
				
				name="x";
				surname="y";
				student_no=1;
				level=1;
				remained_credi=1;
				which_class=0;
				
			}
			//BIG THREE
			inline ~Student(){//destrcuter
				delete [] list_;
			}
			inline Student(const Student& other_student){//copy construter
				
				capacity=other_student.capacity;
				used=other_student.used;
				list_=new liste[capacity];
				for(int i=0; i<capacity; i++){
					list_[i]=other_student.list_[i];
				}
				
				name=other_student.name;
				surname=other_student.surname;
				student_no=other_student.student_no;
				level=other_student.level;
				remained_credi=other_student.remained_credi;
				list=other_student.list;
			
			}
			inline Student& operator=(const Student& other_student){//asssigment operator overloading
				if(this==&other_student){
					return *this;
				}
				else{
					capacity=other_student.capacity;
					used=other_student.used;
					list_=new liste[capacity];
					for(int i=0; i<capacity; i++){
						list_[i]=other_student.list_[i];
					}
				
					name=other_student.name;
					surname=other_student.surname;
					student_no=other_student.student_no;
					level=other_student.level;
					remained_credi=other_student.remained_credi;
					list=other_student.list;
					
					return *this;
				}
			}
			int enrollCourse(std::vector<Course>,int ders_id);
			int disenroll(std::vector<Course>,int ders_id);
			std::string extractSchedule();
		
			
			int& get_no(){
				return student_no;
			}
			int& get_credi(){
				return remained_credi;
			}
			std::string& get_name(){
				return name;
			}
			std::string& get_surname(){
				return surname;
			}
			int& get_level(){
				return level;
			}
			int& get_which_class(){
				return which_class;
			}
			std::vector<liste> list;
			
		private:
			std::string name,surname;
			int which_class;
			int student_no,level,remained_credi;
			int used,capacity;
			liste* list_;
	};

}

#endif
