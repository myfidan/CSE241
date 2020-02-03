#ifndef LECTURER_H
#define LECTURER_H

#include"Employee.h"
namespace My_Fidan{
	
	class Lecturer:public Employee{
		public:
			void work(Action);
			void giveHW();
			void giveLesson();
		private:	
	};
	
}

#endif
