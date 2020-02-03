#ifndef LECTURER_H
#define LECTURER_H
#include"AcademicPersonnel.h"

namespace Fidan_class{
	

class Lecturer:public AcademicPersonnel{
	public:
		Lecturer();
		void giveLesson(int& contribution);
		void giveHW(int& contribution);
			
};

}
#endif
