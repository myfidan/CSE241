#include"ResearchAssistant.h"
#include<iostream>
namespace My_Fidan{

void ResearchAssistant::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=seminar && action!=academicPaper && action!=project && action!=HomeworkTimeout){
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
		else if(action==seminar){
			this->seeSuccessfulStudent();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have seminar.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" see succesfull student.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
		else if(action==academicPaper){
			this->makePublish();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have academic paper.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" make publish.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
		else if(action==project){
			this->research();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have project.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" research.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
		else if(action==HomeworkTimeout){
			this->readHW();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have homework timeout.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" read HW.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		}
	}
	catch(int take){
		std::cout<<"Research assistants cant have this action";
	}
}	


void ResearchAssistant::readHW(){
	this->set_happiness(this->get_happiness()-3);
}
	
void ResearchAssistant::research(){
	this->set_happiness(this->get_happiness()+3);
}

}
