#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<string>

namespace Fidan_class{


class University{
	public:
		int contribution_2;
};


class employe{
	public:
		employe();
		void drinkTea(int& contribution);
		void submitPetition(int& contribution);
		
		//set functions
		void set_id(int);
		void set_name(std::string);
		void set_surname(std::string);
		void set_happiness(int);
		//get functions
		int get_id();
		std::string get_name();
		std::string get_surname();
		int get_happiness();
	private:
		University* emp;	
		int pid;
		std::string name;
		std::string surname;
		int happiness;
};

//This is an extra class that I use to read personnellist.txt file
class read_file{
	public:
		int id;
		std::string name;
		std::string surname;
		std::string alan;
};

}
#endif
