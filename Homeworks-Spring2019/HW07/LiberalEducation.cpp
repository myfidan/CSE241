#include"LiberalEducation.h"
#include<iostream>

University* LiberalEducation::foundUni(UniType x){
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


Employee* LiberalEducation::giveJob(std::string name,std::string surname,empType x){
	Employee* temp;
	if(x==Liblec){
		temp=new LibLec;
	}
	else if(x==Liboff){
		temp=new LibOff;
	}
	else if(x==Libsec){
		temp=new LibSec;
	}
	else if(x==Libassist){
		temp=new LibResAssist;
	}
	temp->set_name(name);
	temp->set_surname(surname);
	temp->set_happiness(0);
	
	return temp;
	

	
}
