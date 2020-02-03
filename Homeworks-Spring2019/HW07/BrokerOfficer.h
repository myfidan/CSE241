#ifndef BROKEROFFICER_H
#define BROKEROFFICER_H
#include"Employee.h"
#include"WorkerOfficer.h"
class BrokerOfficer:public Employee{
	public:
		void work(Action);
		WorkerOfficer* emp1;
		WorkerOfficer* emp2;
};

#endif
