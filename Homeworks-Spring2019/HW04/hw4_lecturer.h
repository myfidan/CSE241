#ifndef HW4_LECTURER_H
#define HW4_LECTURER_H

#include<vector>
#include<string>
#include "hw4_classroom.h"

namespace Fidan_class{
	
	
	
	class Lecturer{
		public:
			
			inline Lecturer(){//constructer
				name="x";
				surname="y";
				title="z";
				personal_id=1;
			}
			//BÝG THREE FOR LECTURER CLASS
			inline ~Lecturer(){//Destructer
					elect_courses.clear();
			}
			inline Lecturer(const Lecturer& other_lect){//copy constructer
				name=other_lect.name;
				surname=other_lect.surname;
				title=other_lect.title;
				personal_id=other_lect.personal_id;
				proffesions=other_lect.proffesions;
				courses=other_lect.courses;
				elect_courses=other_lect.elect_courses;
			}
			inline Lecturer& operator=(const Lecturer& other_lect){//assignment operator overloading
				if(this==&other_lect){
					return *this;
				}
				else{
				
				name=other_lect.name;
				surname=other_lect.surname;
				title=other_lect.title;
				personal_id=other_lect.personal_id;
				proffesions=other_lect.proffesions;
				courses=other_lect.courses;
				elect_courses=other_lect.elect_courses;
				}
				return *this;
			}
			
			void proposeCourse(std::string input);
			void assignCourse(Course);
			
			void set_id(int x);
			void set_name(std::string y);
			void set_surname(std::string z);
			void set_title(std::string w);
			int get_id();
	
			std::string get_name();
			std::string get_surname();
			std::string get_title();
			
			std::vector<std::string> proffesions;
			std::vector<Course> courses;	
			std::vector<Course> elect_courses;
		private:
			std::string name,surname,title;
			int personal_id;
			
			
			
		
	
	};

}
#endif
