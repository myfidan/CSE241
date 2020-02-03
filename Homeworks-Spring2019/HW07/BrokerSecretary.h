#ifndef BROKERSECRETARY_H
#define BROKERSECRETARY_H
#include"Employee.h"
#include"WorkerSecretary.h"
class BrokerSecretary:public Employee{
	public:
		void work(Action);
		WorkerSecretary* emp1;
		WorkerSecretary* emp2;
};

#endif
