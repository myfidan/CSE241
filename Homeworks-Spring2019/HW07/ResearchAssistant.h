#ifndef RESEARCHASSISTANT_H
#define RESEARCHASSISTANT_H
#include"Employee.h"

class ResearchAssistant:public Employee{
	public:	
	void work(Action);
	void research();
	void readHW();
};
#endif
