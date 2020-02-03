#ifndef OFFICER_H
#define OFFICER_H
#include"Employee.h"

class Officer:public Employee{
	public:
	void makeDoc();
	void work(Action);
};

#endif
