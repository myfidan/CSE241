#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include<string>


class Complex{
	public:
		//setters
		Complex();
		
		void set_real_int(int);
		void set_imag_int(int);
		void set_real_double(double);
		void set_imag_double(double);
		//getters
		int get_real_int();
		int get_imag_int();
		double get_real_double();
		double get_imag_double();
		//operator overloadings
		Complex operator+(const Complex& other);
		Complex operator-(const Complex& other);
		Complex& operator=(const Complex& other);
		Complex& operator++();
		Complex operator++(int);
		friend std::ostream& operator<<(std::ostream& yaz,Complex& other);
	private:
		int real_int;
		int	imag_int;
		double real_double;
		double imag_double;	
		
};

#endif
