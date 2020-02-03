#include"ComLec.h"

void ComLec::work(Action action){
		try{//exeption handling for actions
			if(action!=slackness && action!=solution && action!=seminar && action!=academicPaper && action!=lesson && action!=HomeworkTime){
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
			else if(action==lesson){
				this->giveLesson();
				std::cout<<this->get_name()<<" "<<this->get_surname()<<" have lesson.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" give lesson. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
			
			}
			else if(action==HomeworkTime){
				this->giveHW();
				std::cout<<this->get_name()<<" "<<this->get_surname()<<" have HomeworkTime.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" give HW. "<<"Happiness of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<" ";
			
			}	
		}
		catch(int take){
				std::cout<<this->get_name()<<" "<<this->get_surname()<<" cant have this action";
		}
}
