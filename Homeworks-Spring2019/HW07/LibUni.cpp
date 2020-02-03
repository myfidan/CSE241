#include"LibUni.h"
#include<iostream>
int LibUni::contribute(int data){
	
	this->set_cont(this->get_cont()+data);
	return get_cont();	
	
}

void LibUni::employ(){
	
}

void LibUni::start(empType x){
	if(x==Liblec){
		std::cout<<"I see that there is an oppurtunity for being Lecturer in the University.So I am Lecturer"<<std::endl;	
	}
	else if(x==Liboff){
		std::cout<<"I see that there is an oppurtunity for being Officer in the University.So I am Officer"<<std::endl;	
	}
	else if(x==Libassist){
		std::cout<<"I see that there is an oppurtunity for being ResAssistant in the University.So I am ResAssistant"<<std::endl;	
	}
	else if(x==Libsec){
		std::cout<<"I see that there is an oppurtunity for being Secretary in the University.So I am Secretary"<<std::endl;	
	}
}
