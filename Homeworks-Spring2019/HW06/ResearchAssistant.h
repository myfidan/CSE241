#ifndef RESEARCHASSISTANT_H
#define RESEARCHASSISTANT_H

#include"Employee.h"

namespace My_Fidan{
	
	class ResearchAssistant:public Employee{
		public:
			void work(Action);
			void research();
			void readHW();
		private:
	};
		
}

#endif
