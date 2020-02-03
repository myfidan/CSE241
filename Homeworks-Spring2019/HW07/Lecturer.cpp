#include"Lecturer.h"

void Lecturer::work(Action x){
	
}

void Lecturer::giveHW(){
	this->set_happiness(this->get_happiness()-2);
		
}

void Lecturer::giveLesson(){
	this->set_happiness(this->get_happiness()+1);
}
