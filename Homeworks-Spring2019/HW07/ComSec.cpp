#include"ComSec.h"

void ComSec::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=administration && action!=incident){
			throw 1;
		}
		if(action==slackness){
			this->drinkTea();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have slackness.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" drink tea. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==solution){
			this->submitPetition();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have solution.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" submit petition. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==administration){
			this->manageProcess();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have administration.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" manage process. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
	
		}
		else if(action==incident){
			this->receivePetition();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have incident.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" receive petition. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
	}
	catch(int take){
		std::cout<<this->get_name()<<" "<<this->get_surname()<<" cant have this actions";
	}
}
