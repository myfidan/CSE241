#include"Lecturer.h"

namespace Fidan_class{
	


Lecturer::Lecturer():AcademicPersonnel(){
	
}

void Lecturer::giveLesson(int& contribution){
	this->set_happiness(this->get_happiness()+1);
	contribution+=5;
}

void Lecturer::giveHW(int& contribution){
	this->set_happiness(this->get_happiness()-2);
	contribution+=1;
}

}
