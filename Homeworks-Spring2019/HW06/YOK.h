#ifndef YOK_H
#define YOK_H

#include"University.h"
#include"Employee.h"
#include"Lecturer.h"
#include"ResearchAssistant.h"
#include"Secretary.h"
#include"Officer.h"
#include"Complex.h"
namespace My_Fidan{
	
	enum UniType{//enumureter for University types
		research_uni=1,linguistic_uni,technical_uni
	};
	
	template<class T>
	class YOK{
		public:
			University<T> foundUni(UniType x);
			Employee* giveJob(std::string,std::string,empType);		
	};

}
#endif
