#include"Complex.h"

Complex::Complex(){
	real_int=0;
	imag_int=0;
	real_double=0.0;
	imag_double=0.0;	
}

Complex Complex::operator+(const Complex& other){
	Complex temp;
	temp.real_int=real_int+other.real_int;
	temp.imag_int=imag_int+other.imag_int;
	temp.real_double=real_double+other.real_double;
	temp.imag_double=imag_double+other.imag_double;
	
	return temp;
}

Complex Complex::operator-(const Complex& other){
	Complex temp;
	temp.real_int=real_int-other.real_int;
	temp.imag_int=imag_int-other.imag_int;
	temp.real_double=real_double-other.real_double;
	temp.imag_double=imag_double-other.imag_double;
	
	return temp;
}

Complex& Complex::operator=(const Complex& other){
	if(this!=&other){
		real_int=other.real_int;
		imag_int=other.imag_int;
		real_double=other.real_double;
		imag_double=other.imag_double;
	}
	return *this;
}

Complex& Complex::operator++(){//pre increment
	++real_int;
	++imag_int;
	++real_double;
	++imag_double;
	
	return *this;
}

Complex Complex::operator++(int){//post increment
	Complex temp;
	temp.real_int=real_int;
	temp.imag_int=imag_int;
	temp.real_double=real_double;
	temp.imag_double=imag_double;
	
	real_int++;
	imag_int++;
	real_double++;
	imag_double++;
	
	return temp;
}

std::ostream& operator<<(std::ostream& yaz,Complex& other){
	double x=other.get_real_double();
	yaz<<other.get_real_int()<<"/"<<std::to_string(other.get_real_double());
	
	return yaz;
}

void Complex::set_real_int(int x){
	real_int=x;
}

void Complex::set_imag_int(int x){
	imag_int=x;
}

void Complex::set_real_double(double x){
	real_double=x;
}

void Complex::set_imag_double(double x){
	imag_double=x;
}

int Complex::get_real_int(){
	return real_int;
}

int Complex::get_imag_int(){
	return imag_int;
}

double Complex::get_real_double(){
	return real_double;
}

double Complex::get_imag_double(){
	return imag_double;
}
