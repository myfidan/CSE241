#include"LibLec.h"

void LibLec::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=seminar && action!=academicPaper && action!=lesson && action!=HomeworkTime){
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
		else if(action==lesson){
			this->giveLesson();
			std::cout<<"I"<<" have lesson.Therefore, "<<"I"<<" give lesson. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		
		}
		else if(action==HomeworkTime){
			this->giveHW();
			std::cout<<"I"<<" have HomeworkTime.Therefore, "<<" I"<<" give HW. "<<"My happiness"<<" is "<<this->get_happiness()<<" and my money is";
		
		}	
	}
	catch(int take){
			std::cout<<"I cant have this action";
	}
}
