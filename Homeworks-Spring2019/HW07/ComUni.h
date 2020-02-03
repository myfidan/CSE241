#ifndef COMUNI_H
#define COMUNI_H

#include"University.h"

class ComUni:public University{
	public:
		int contribute(int);
		void start(empType);
		void employ();
		int ComUniConst;
};
#endif
