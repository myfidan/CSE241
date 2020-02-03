#include"Officer.h"

namespace Fidan_class{
	

Officer::Officer():AdministrativePersonnel(){
	
}
void Officer::makeDoc(int& contribution){
	this->set_happiness(this->get_happiness()-2);
	contribution+=3;
}

}
