#include"Secretary.h"
#include<iostream>
namespace My_Fidan{

void Secretary::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=administration && action!=incident){
			throw 1;
		}
		if(action==slackness){
			this->drinkTea();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have slackness.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" drinks tea.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
		else if(action==solution){
			this->submitPetition();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have solution.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" submit petition.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
		else if(action==administration){
			this->manageProcess();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have administration.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" manage process.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
	
		}
		else if(action==incident){
			this->receivePetition();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have incident.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" receive petition.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
	}
	catch(int take){
		std::cout<<"Secretaries cant have this actions";
	}
}

void Secretary::receivePetition(){
	this->set_happiness(this->get_happiness()-1);
}


}
