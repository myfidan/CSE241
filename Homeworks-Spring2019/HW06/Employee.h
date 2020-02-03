#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

namespace My_Fidan{
	
	enum Action{//2emp 2academic  2lect 1admin 2assistant 1officer 1secretary
		slackness=1,solution,seminar,academicPaper,HomeworkTime,lesson,administration,project,HomeworkTimeout,document,incident
	};
	
	class Employee{
		public:
			Employee();
			virtual void work(Action)=0;//an abstract virtual function
			
			//getters
			int get_pid();
			std::string get_name();
			std::string get_surname();
			int get_happiness();
			//setter
			void set_pid(int);
			void set_name(std::string);
			void set_surname(std::string);
			void set_happiness(int);
			
			//emp actions
			void drinkTea();
			void submitPetition();
			void seeSuccessfulStudent();
			void makePublish();
			void manageProcess();
		private:
			int pid;
			std::string name;
			std::string surname;
			int happiness;
	};
	
	struct read_file{//my structer for read file
		int id;
		std::string name;
		std::string surname;
	};
	
	
}

#endif
