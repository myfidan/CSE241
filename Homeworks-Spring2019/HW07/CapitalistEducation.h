#ifndef CAPITALISTEDUCATION_H
#define CAPITALISTEDUCATION_H

#include"EducationSystem.h"
#include"BrokerLecturer.h"
#include"BrokerOfficer.h"
#include"BrokerSecretary.h"
#include"BrokerResAssist.h"
#include"WorkerLecturer.h"
#include"WorkerOfficer.h"
#include"WorkerResAssist.h"
#include"WorkerSecretary.h"


class CapitalistEducation:public EducationSystem{
	public:
		
	University* foundUni(UniType);
	Employee* giveJob(std::string,std::string,empType);
};

#endif
