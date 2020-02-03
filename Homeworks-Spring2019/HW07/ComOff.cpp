#include"ComOff.h"

void ComOff::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=administration && action!=document){
			throw 1;
		}
		if(action==slackness){
			this->drinkTea();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have slackness.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" drinks tea. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==solution){
			this->submitPetition();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have solution.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" submit petition. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==administration){
			this->manageProcess();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have administration.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" manage process. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
	
		}
		else if(action==document){
			this->makeDoc();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have document.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" make Doc. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
	}
	catch(int take){
		std::cout<<this->get_name()<<" "<<this->get_surname()<<" cant have this actions";
	}
}
