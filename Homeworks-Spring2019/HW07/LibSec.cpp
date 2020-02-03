#include"LibSec.h"

void LibSec::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=administration && action!=incident){
			throw 1;
		}
		if(action==slackness){
			this->drinkTea();
			std::cout<<"I"<<" have slackness.Therefore, "<<"I"<<" drink tea. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==solution){
			this->submitPetition();
			std::cout<<"I"<<" have solution.Therefore, "<<"I"<<" submit petition. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==administration){
			this->manageProcess();
			std::cout<<"I"<<" have administration.Therefore, "<<"I"<<" manage process. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
	
		}
		else if(action==incident){
			this->receivePetition();
			std::cout<<"I"<<" have incident.Therefore, "<<"I"<<" receive petition. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
	}
	catch(int take){
		std::cout<<"I cant have this actions";
	}
}


