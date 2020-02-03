#ifndef LECTURER_H
#define LECTURER_H
#include"Employee.h"

class Lecturer:public Employee{
	public:
	void work(Action);
	void giveHW();

	void giveLesson();
};

#endif
