#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include<string>
#include"Employee.h"
enum UniType{
	Comuni=1,Libuni,Capuni
};

class University{
	public:
		void set_cont(int x){
			cont=x;
		}
		int get_cont(){
			return cont;
		}
		virtual int contribute(int)=0;
		virtual void start(empType)=0;
		virtual void employ()=0;
		private:
		int cont;
};

#endif
