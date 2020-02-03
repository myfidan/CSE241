#ifndef TEMP_UNIVERSITY_H
#define TEMP_UNIVERSITY_H

#include"University.h"

template<class T>
class Temp_University:public University{
	public:
		int contribute();
		void start();
		void employ();
		T cont;
};

#endif
