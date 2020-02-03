#include"University.h"
#include<iostream>
namespace My_Fidan{

template<class T>
T University<T>::contribute(T data){
	this->set_cont(this->get_cont()+data);
	return cont;
}	
	
	template class University<int>;
	template class University<double>;
	template class University<Complex>;

}
