#ifndef HW3_CLASS_H
#define HW3_CLASS_H
#include<vector>
#include<string>

using namespace std;

class Lecturer;
class Administrator;
struct Course;
struct Classroom;
struct Date;





class Lecturer{
	public:
		Lecturer();
		void proposeCourse(string input);
		void assignCourse(Course);
		
		void set_id(int x);
		void set_name(string y);
		void set_surname(string z);
		void set_title(string w);
		int get_id();
		string get_name();
		string get_surname();
		string get_title();
		
		vector<string> proffesions;
		vector<Course> courses;
		vector<Course> elect_courses;
	private:
		string name,surname,title;
		int personal_id;
		
	

};


struct Classroom{
	int id,c_no,capacity,student_inroom;
	
};

struct Course{
	int id,code,credit,total_hours;
	string name,field;
	bool isMandatory;
	Classroom course_class;
	vector<Date> lecture_dates;
};

class Administrator{
	public:
		Administrator();
		void arrangeClassroom(vector<Lecturer>&,Course&,int);
		void arrangeTimeTable(Course&);	
	private:
		int pid,password;
};


struct Date{
	string day;
	int start_hour;
	int end_hour;
};






#endif //HW3_H
