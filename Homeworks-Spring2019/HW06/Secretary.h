#ifndef SECRETARY_H
#define SECRETARY_H

#include"Employee.h"

namespace My_Fidan{
	
	class Secretary:public Employee{
		public:
			void work(Action);
			void receivePetition();
		private:	
	};
	
}
#endif
