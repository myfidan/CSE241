#include "YOK.h"
#include<iostream>
namespace My_Fidan{

template<class T>
University<T> YOK<T>::foundUni(UniType x){
	University<T> temp;
	
	if(x==research_uni){
		temp.set_name("GTU");
		
	}
	else if(x==linguistic_uni){
		temp.set_name("Dou");
		
	}
	else if(x==technical_uni){
		temp.set_name("EGE");
	}
	return temp;
}

template<class T>
Employee* YOK<T>::giveJob(std::string name,std::string surname,empType x){
	Employee* temp;
	if(x==lecturer){
		temp=new Lecturer;
	}
	else if(x==researchassistant){
		temp=new ResearchAssistant;
	}
	else if(x==secretary){
		temp=new Secretary;
	}
	else if(x==officer){
		temp=new Officer;
	}
	temp->set_name(name);
	temp->set_surname(surname);
	temp->set_happiness(0);
	
	return temp;
	

	
}

	template class YOK<int>;
	template class YOK<double>;
	template class YOK<Complex>;
}
