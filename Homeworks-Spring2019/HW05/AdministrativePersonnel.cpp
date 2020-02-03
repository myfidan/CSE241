#include"AdministrativePersonnel.h"

namespace Fidan_class{
	

AdministrativePersonnel::AdministrativePersonnel():employe(){
	
}

void AdministrativePersonnel::manageProcess(int& contribution){
	this->set_happiness(this->get_happiness()-1);
	contribution+=2;
}

}
