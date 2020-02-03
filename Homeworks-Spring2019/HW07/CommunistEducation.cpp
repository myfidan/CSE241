#include"CommunistEducation.h"
#include<iostream>
University* CommunistEducation::foundUni(UniType x){
	University* temp;
	if(x==Libuni){
	
		std::cout<<"*****Liberal University*****"<<std::endl;
	}
	else if(x==Capuni){
	
		std::cout<<"*****Capitalist University*****"<<std::endl;
	}
	else if(x==Comuni){
	
		std::cout<<"*****Communist University*****"<<std::endl;
	}
	return temp;
}


Employee* CommunistEducation::giveJob(std::string name,std::string surname,empType x){
	Employee* temp;
	if(x==Comlec){
		temp=new ComLec;
	}
	else if(x==Comoff){
		temp=new ComOff;
	}
	else if(x==Comsec){
		temp=new ComSec;
	}
	else if(x==Comassist){
		temp=new ComResAssist;
	}
	temp->set_name(name);
	temp->set_surname(surname);
	temp->set_happiness(0);
	
	return temp;
	

	
}
