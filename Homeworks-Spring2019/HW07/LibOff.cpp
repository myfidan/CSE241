#include"LibOff.h"

void LibOff::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=administration && action!=document){
			throw 1;
		}
		if(action==slackness){
			this->drinkTea();
			std::cout<<"I"<<" have slackness.Therefore, "<<"I"<<" drinks tea. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==solution){
			this->submitPetition();
			std::cout<<"I"<<" have solution.Therefore, "<<"I"<<" submit petition. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==administration){
			this->manageProcess();
			std::cout<<"I"<<" have administration.Therefore, "<<"I"<<" manage process. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
	
		}
		else if(action==document){
			this->makeDoc();
			std::cout<<"I"<<" have document.Therefore, "<<"I"<<" make Doc. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
	}
	catch(int take){
		std::cout<<"I cant have this actions";
	}
}
