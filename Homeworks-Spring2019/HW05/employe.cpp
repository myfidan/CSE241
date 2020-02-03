#include"employe.h"
#include<iostream>

namespace Fidan_class{
	

employe::employe()
{	
	University temp;
	temp.contribution_2=0;
	happiness=0;
	emp=&temp;
}

void employe::drinkTea(int& contribution){
	happiness+=5;
	contribution+=-2;
}

void employe::submitPetition(int& contribution){
	happiness+=1;
	contribution+=-2;
}

//setter functions
void employe::set_id(int x){
	pid=x;
}

void employe::set_name(std::string x){
	name=x;
}

void employe::set_surname(std::string x){
	surname=x;
}

void employe::set_happiness(int x){
	happiness=x;
}

//getter functions
int employe::get_id(){
	return pid;
}

int employe::get_happiness(){
	return happiness;
}

std::string employe::get_name(){
	return name;
}

std::string employe::get_surname(){
	return surname;
}

}
