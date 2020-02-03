#include"Lecturer.h"
#include<iostream>

namespace My_Fidan{
	
void Lecturer::work(Action action){
	try{//exeption handling for actions
		if(action!=slackness && action!=solution && action!=seminar && action!=academicPaper && action!=lesson && action!=HomeworkTime){
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
		else if(action==lesson){
			this->giveLesson();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have lesson.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" give lesson.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		
		}
		else if(action==HomeworkTime){
			this->giveHW();
			std::cout<<this->get_name()<<" "<<this->get_surname()<<" have HomeworkTime.Therefore, "<<this->get_name()<<" "<<this->get_surname()<<" give HW.Happines of "<<this->get_name()<<" "<<this->get_surname()<<" is "<<this->get_happiness()<<",";
		
		}	
	}
	catch(int take){
			std::cout<<"Lecturers cant have this action";
	}
}

void Lecturer::giveHW(){
	this->set_happiness(this->get_happiness()-2);
		
}

void Lecturer::giveLesson(){
	this->set_happiness(this->get_happiness()+1);
}

}
