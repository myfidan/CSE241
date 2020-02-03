#ifndef ACADEMICPERSONNEL_H
#define ACADEMICPERSONNEL_H
#include"employe.h"

namespace Fidan_class{

class AcademicPersonnel:public employe{
	public:
		AcademicPersonnel();
		void seeSuccessfulStudent(int& contribution);
		void makePublish(int& contribution);
};

}
#endif
