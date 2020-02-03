#ifndef BROKERRESASSIST_H
#define BROKERRESASSIST_H
#include"Employee.h"
#include"WorkerResAssist.h"
class BrokerResAssist:public Employee{
	public:
		void work(Action);
		WorkerResAssist* emp1;
		WorkerResAssist* emp2;
};

#endif
