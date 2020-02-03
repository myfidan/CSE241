#ifndef LIBSEC_H
#define LIBSEC_H
#include"Secretary.h"

class LibSec:public Secretary{
	public:
	void work(Action);
};
#endif
