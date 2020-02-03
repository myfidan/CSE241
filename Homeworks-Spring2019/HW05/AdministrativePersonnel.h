#ifndef ADMINISTRATIVEPERSONNEL_H
#define ADMINISTRATIVEPERSONNEL_H
#include"employe.h"

namespace Fidan_class{
	

class AdministrativePersonnel:public employe{
	public:
		AdministrativePersonnel();
		void manageProcess(int& contribution);
		
};

}

#endif
