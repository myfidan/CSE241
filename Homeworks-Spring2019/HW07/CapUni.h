#ifndef CAPUNI_H
#define CAPUNI_H

#include"University.h"

class CapUni:public University{
	public:
		int contribute(int);
		void start();
		void employ();
		int CapUniConst;
};
#endif
