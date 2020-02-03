#ifndef BROKERLECTURER_H
#define BROKERLECTURER_H
#include"Employee.h"
#include"WorkerLecturer.h"
class BrokerLecturer:public Employee{
	public:
		void work(Action);
		private:
		WorkerLecturer* emp1;
		WorkerLecturer* emp2;
};

#endif
