#ifndef EDUCATIONSYSTEM_H
#define EDUCATIONSYSTEM_H

#include<string>
#include"University.h"
#include"Employee.h"

class EducationSystem{
	public:
		virtual University* foundUni(UniType)=0;
		virtual Employee* giveJob(std::string,std::string,empType)=0;
};


#endif
