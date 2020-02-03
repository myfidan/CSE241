#ifndef OFFICER_H
#define OFFICER_H
#include"AdministrativePersonnel.h"

namespace Fidan_class{
	

class Officer:public AdministrativePersonnel{
	public:
		Officer();
		void makeDoc(int& contribution);
};

}
#endif
