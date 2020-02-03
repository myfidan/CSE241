#include"ComResAssist.h"

void ComResAssist::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=seminar && action!=academicPaper && action!=project && action!=homeworkTimeout){
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
		else if(action==seminar){
			this->seeSuccessfulStudent();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have seminar.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" see succesfull student. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==academicPaper){
			this->makePublish();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have academic paper.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" make publish. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==project){
			this->research();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have project.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" research. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
		else if(action==homeworkTimeout){
			this->readHW();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have homework timeout.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" read HW. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
		}
	}
	catch(int take){
		std::cout<<this->get_name()<<" "<<this->get_surname()<<" cant have this action";
	}
}
