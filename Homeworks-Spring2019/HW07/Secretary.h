#ifndef SECRETARY_H
#define SECRETARY_H
#include"Employee.h"

class Secretary:public Employee{
	public:
		void receivePetition();
		void work(Action);
};

#endif
