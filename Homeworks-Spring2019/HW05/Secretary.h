#ifndef SECRETARY_H
#define SECRETARY_H
#include"AdministrativePersonnel.h"

namespace Fidan_class{
	

class Secretary:public AdministrativePersonnel{
	public:
		Secretary();
		void receivePetition(int& contribution);
};

}
#endif
