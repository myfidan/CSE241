#ifndef HW4_CLASSROOM_H
#define HW4_CLASSROOM_H

#include<vector>
#include<string>

namespace Fidan_class{

struct Course;
struct Date;

	struct Attendance{
		int class_id_number;
		int course_id_number;
		int student_id_number;
		int attendance_score;
		int in_a_class;
		std::vector<int> hours;
	};
	
	struct Attendance_hour{
		std::vector<int> hour;
		int stu_no;
	};	
	
	class Classroom{
		public:/*
			inline Classroom(){
				used_class=0;
				capacity_class=20;
				attendance=new Attendance[capacity_class];
				for(int i=0; i<capacity_class; i++){
					attendance[i].attendance_score=-1;
					attendance[i].class_id_number=-1;
					attendance[i].course_id_number=-1;
					attendance[i].student_id_number=-1;
				}
				id=0;
				c_no=0;
				capacity=0;
				student_inroom=0;
			}
			inline ~Classroom(){
				delete [] attendance;
			}
			inline Classroom(const Classroom& other_class){
				capacity_class=other_class.capacity_class;
				used_class=other_class.used_class;
				attendance=new Attendance[capacity_class];
				for(int i=0; i<capacity_class; i++){
					attendance[i].attendance_score=other_class.attendance[i].attendance_score;
					attendance[i].class_id_number=other_class.attendance[i].class_id_number;
					attendance[i].course_id_number=other_class.attendance[i].course_id_number;
					attendance[i].student_id_number=other_class.attendance[i].student_id_number;
				}
				
				id=other_class.id;
				c_no=other_class.c_no;
				capacity=other_class.capacity;
				student_inroom=other_class.student_inroom;
			}
			inline Classroom& operator=(const Classroom& other_class){
				if(this==&other_class){
					return *this;
				}
				else{
					capacity_class=other_class.capacity_class;
					used_class=other_class.used_class;
					attendance=new Attendance[capacity_class];
					for(int i=0; i<capacity_class; i++){
						attendance[i].attendance_score=other_class.attendance[i].attendance_score;
						attendance[i].class_id_number=other_class.attendance[i].class_id_number;
						attendance[i].course_id_number=other_class.attendance[i].course_id_number;
						attendance[i].student_id_number=other_class.attendance[i].student_id_number;
					}
					
					id=other_class.id;
					c_no=other_class.c_no;
					capacity=other_class.capacity;
					student_inroom=other_class.student_inroom;
					return *this;
				}
			}*/
			Attendance enterClassroom(int,int,int,std::vector<Course>);
			void quitClassroom();
			
			void set_class_id(int);
			void set_class_no(int);
			void set_class_capacity(int);
			void set_class_inroom(int);
			void add_attendance(int);
			
			int get_class_id();
			int get_class_no();
			int get_class_capacity();
			int get_class_inroom();
		
			
			
		private:
			int id,c_no,capacity,student_inroom;
			//Attendance* attendance;
			//int used_class,capacity_class;
	};
	
	
	
	struct Date{
		std::string day;
		int start_hour;
		int end_hour;
	};

	
	
	struct Course{
		int id,code,credit,total_hours;
		std::string name,field;
		bool isMandatory;
		Classroom course_class;
		std::vector<Date> lecture_dates;
		
	};
	
	
	struct liste{
		std::string lesson_name;
		int lesson_id,lesson_credi,total_hours;
		std::vector<Date> list_date;
	};
	

}
#endif
