#ifndef COMMUNISTEDUCATION_H
#define COMMUNISTEDUCATION_H

#include"EducationSystem.h"
#include"ComOff.h"
#include"ComLec.h"
#include"ComSec.h"
#include"ComResAssist.h"


class CommunistEducation:public EducationSystem{
	public:
	University* foundUni(UniType);
	Employee* giveJob(std::string,std::string,empType);
};


#endif
