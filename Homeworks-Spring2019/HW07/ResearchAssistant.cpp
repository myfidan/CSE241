#include"ResearchAssistant.h"

void ResearchAssistant::work(Action x){
	
}

void ResearchAssistant::readHW(){
	this->set_happiness(this->get_happiness()-3);
}
	
void ResearchAssistant::research(){
	this->set_happiness(this->get_happiness()+3);
}
