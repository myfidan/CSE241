#include"Employee.h"

namespace My_Fidan{

Employee::Employee(){
	
}

//getters
int Employee::get_pid(){
	return pid;
}

std::string Employee::get_name(){
	return name;
}

std::string Employee::get_surname(){
	return surname;
}

int Employee::get_happiness(){
	return happiness;
}

//setters
void Employee::set_pid(int x){
	pid=x;
}

void Employee::set_name(std::string x){
	name=x;
}

void Employee::set_surname(std::string x){
	surname=x;
}

void Employee::set_happiness(int x){
	happiness=x;
}

void Employee::drinkTea(){
	this->set_happiness(this->get_happiness()+5);
}
void Employee::submitPetition(){
	this->set_happiness(this->get_happiness()+1);
}
void Employee::seeSuccessfulStudent(){
	this->set_happiness(this->get_happiness()+10);
}
void Employee::makePublish(){
	this->set_happiness(this->get_happiness()+2);
}
void Employee::manageProcess(){
	this->set_happiness(this->get_happiness()-1);
}
}
