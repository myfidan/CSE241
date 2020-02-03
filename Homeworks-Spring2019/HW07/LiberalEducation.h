#ifndef LIBERALEDUCATION_H
#define LIBERALEDUCATION_H

#include"EducationSystem.h"
#include"LibLec.h"
#include"LibSec.h"
#include"LibOff.h"
#include"LibResAssist.h"

class LiberalEducation:public EducationSystem{
	public:
	University* foundUni(UniType);
	Employee* giveJob(std::string,std::string,empType);
};

#endif
