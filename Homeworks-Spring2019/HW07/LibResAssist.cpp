#include"LibResAssist.h"

void LibResAssist::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=seminar && action!=academicPaper && action!=project && action!=homeworkTimeout){
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
		else if(action==seminar){
			this->seeSuccessfulStudent();
			std::cout<<"I"<<" have seminar.Therefore, "<<"I"<<" see succesfull student. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==academicPaper){
			this->makePublish();
			std::cout<<"I"<<" have academic paper.Therefore, "<<"I"<<" make publish. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==project){
			this->research();
			std::cout<<"I"<<" have project.Therefore, "<<"I"<<" research. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
		else if(action==homeworkTimeout){
			this->readHW();
			std::cout<<"I"<<" have homework timeout.Therefore, "<<"I"<<" read HW. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		}
	}
	catch(int take){
		std::cout<<"I cant have this action";
	}
}
