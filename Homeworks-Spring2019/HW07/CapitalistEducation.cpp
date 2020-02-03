#include"CapitalistEducation.h"

University* CapitalistEducation::foundUni(UniType x){
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

Employee* CapitalistEducation::giveJob(std::string name,std::string surname,empType x){
	Employee* temp;
	if(x==brokerlect){
		temp=new BrokerLecturer;
	}
	else if(x==brokeroff){
		temp=new BrokerOfficer;
	}
	else if(x==brokersec){
		temp=new BrokerSecretary;
	}
	else if(x==brokerassist){
		temp=new BrokerResAssist;
	}
	else if(x==workerlect){
		temp=new WorkerLecturer;
	}
	else if(x==workeroff){
		temp=new WorkerOfficer;
	}
	else if(x==workerassist){
		temp=new WorkerResAssist;
	}
	else if(x==workersec){
		temp=new WorkerSecretary;
	}
	
	temp->set_name(name);
	temp->set_surname(surname);
	temp->set_happiness(0);
	
	return temp;
}
