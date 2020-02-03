#include "ResearchAssistant.h"

namespace Fidan_class{
	

ResearchAssistant::ResearchAssistant():AcademicPersonnel(){
	
}

void ResearchAssistant::research(int& contribution){
	this->set_happiness(this->get_happiness()+3);
	contribution+=4;
}
	
	
void ResearchAssistant::readHW(int& contribution){
	this->set_happiness(this->get_happiness()-3);
	contribution+=2;
}

}
