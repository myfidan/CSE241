#include"Officer.h"
#include<iostream>
namespace My_Fidan{


void Officer::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=administration && action!=document){
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
		else if(action==document){
			this->makeDoc();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have document.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" make Doc.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
	}
	catch(int take){
		std::cout<<"Officers cant have this actions";
	}
}

void Officer::makeDoc(){
	this->set_happiness(this->get_happiness()-2);
}

	
}
