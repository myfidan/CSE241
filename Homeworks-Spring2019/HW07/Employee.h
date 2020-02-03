#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>
#include<iostream>
enum empType{//emptype enum
	Liblec,Liboff,Libsec,Libassist,Comlec,Comoff,Comsec,Comassist,Caplec,Capoff,Capsec,Capassit,brokerlect,brokerassist,brokersec,brokeroff,workerlect,workerassist,workersec,workeroff
};

enum Action{//actions enum
	document=1,slackness,project,lesson,seminar,academicPaper,administration,HomeworkTime,homeworkTimeout,incident,solution
};

class Employee{
	public:
		virtual void work(Action)=0;//Pure virtual func so Employee class abstract
		
		void set_pid(int x){
			pid=x;
		}
		void set_name(std::string x){
			name=x;
		}
		void set_surname(std::string x){
			surname=x;
		}
		void set_happiness(int x){
			happiness=x;
		}
		
		int get_pid(){
			return pid;
		}
		std::string get_name(){
			return name;
		}
		std::string get_surname(){
			return surname;
		}
		int get_happiness(){
			return happiness;
		}
		
		void drinkTea(){
			this->set_happiness(this->get_happiness()+5);
		}
		void submitPetition(){
			this->set_happiness(this->get_happiness()+1);
		}
		void seeSuccessfulStudent(){
			this->set_happiness(this->get_happiness()+10);
		}
		void makePublish(){
			this->set_happiness(this->get_happiness()+2);
		}
		void manageProcess(){
			this->set_happiness(this->get_happiness()-1);
		}
	private:
		int pid;
		std::string name;
		std::string surname;
		int happiness;	
};


struct Personnel{
	std::string name;
	std::string surname;
	std::string wb;
};

#endif
