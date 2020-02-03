#ifndef UNIVERSITY
#define UNIVERSITY
#include<string>
#include"Complex.h"

namespace My_Fidan{
	
	
	enum empType{//enumureter for employee types
		lecturer=1,researchassistant,secretary,officer
	};
	
	template <class T>
	class University{
		public:
			void set_cont(T x){
				cont=x;
			}
			T get_cont(){
				return cont;
			}
			T contribute(T data);
			
			std::string get_name(){
				return uni_name;
			}
			void set_name(std::string other){
				uni_name=other;	
			}
			
		private:
			T cont;	
			std::string uni_name;
	};
	
}
#endif
