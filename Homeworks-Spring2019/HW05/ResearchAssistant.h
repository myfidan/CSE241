#ifndef RESEARCHASSISTANT_H
#define RESEARCHASSISTANT_H
#include"AcademicPersonnel.h"

namespace Fidan_class{
	

class ResearchAssistant:public AcademicPersonnel{
	public:
		ResearchAssistant();
		void research(int& contribution);
		void readHW(int& contribution);
};

}
#endif
