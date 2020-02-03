#include"AcademicPersonnel.h"

namespace Fidan_class{
	

AcademicPersonnel::AcademicPersonnel():employe(){
	
}

void AcademicPersonnel::seeSuccessfulStudent(int& contribution){
	this->set_happiness(this->get_happiness()+10);
	contribution+=0;
}

void AcademicPersonnel::makePublish(int& contribution){
	this->set_happiness(this->get_happiness()+2);
	contribution+=5;
}

}
