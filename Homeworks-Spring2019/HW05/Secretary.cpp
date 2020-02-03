#include"Secretary.h"

namespace Fidan_class{
	

Secretary::Secretary():AdministrativePersonnel(){
	
}

void Secretary::receivePetition(int& contribution){
	this->set_happiness(this->get_happiness()-1);
	contribution+=-1;
}

}
