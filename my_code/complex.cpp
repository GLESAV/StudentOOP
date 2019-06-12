#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {


	return (
	(c1.get_real()==c2.get_real())

	&& (c1.get_imag()==c2.get_imag())
	
	);

	// if (c1.get_real()==c2.get_real() &&
	// c1.get_imag()==c2.get_imag())
		// {return true;}
	// else
		// {return false;}




}
bool operator!= (const Complex& c1, const Complex& c2)
{
	return (!(c1==c2));
}

ostream& operator<< (ostream& os, const Complex& c) {
	if (c.imag>=0)
	{
		os << c.real << " + " << c.imag <<"i"<< endl;
	}
	else //less than zero
	{
		os << c.real << " - " << c.imag*-1 <<"i"<<endl;
	}
	
	return os;
}

Complex::Complex(double real, double imag):real(real),imag(imag){}

/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	
	cout << "Input the real part: ";
	
	is >> c.real;
	cout << "Input the imag part: ";
	
	is	>> c.imag;
	
	return is;
	
}




 Complex::operator bool() const {
	 
	 
		return //(real!=0);
		
		((real!=0)||(imag!=0));
	 
 }

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex Complex::operator++(int dummy) {
	Complex hold(real,imag);
	++real;
	return hold;
}

Complex& Complex::operator--()
{
	real+=-1;
	imag+=-1;
	return *this;
}

Complex Complex::operator--(int dummy)
{
	Complex hold(real,imag);
	real+=-1;
	imag+=-1;
	return hold;
	
}


Complex& Complex::operator+=(const Complex& rhs)
{
	real+=rhs.get_real();
	imag+=rhs.get_imag();
	
	return *this;
}
Complex& Complex::operator-=(const Complex& rhs)
{
	real-=rhs.get_real();
	imag-=rhs.get_imag();
	
	return *this;
}

Complex operator+(const Complex& c1,const Complex& c2) 
{
	
	Complex sum(c1.get_real(),c1.get_imag());
	sum+=c2;
	return sum;
}


Complex operator-(const Complex& c1,const Complex& c2) 
{
	Complex sum(c2.get_real()*-1,c2.get_imag()*-1);
	sum+=c1;
	return sum;
	
}

double Complex::get_real() const 
{
	return real;
}
double Complex::get_imag() const 
{
	return imag;
}

Complex Complex::operator*(const int i) 
{
	Complex product(real*i,imag*i);
	return product;
}


