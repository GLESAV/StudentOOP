#ifndef COMPLEX_H
#define COMPLEX_H


class Complex {
    friend std::ostream& operator<< (std::ostream& os, const Complex& c);
    friend std::istream& operator>> (std::istream& is, Complex& c);

 public:
    Complex(double real=0.0, double imag=0.0);


    explicit operator bool() const;
    
    double get_real() const;
    double get_imag() const;

    Complex& operator++();
	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
    Complex operator++(int dummy);
    Complex& operator--();

    Complex operator--(int dummy);

    Complex operator*(const int i);

 private:
    double real;
    double imag;
};

bool operator== (const Complex& c1, const Complex& c2);
bool operator!= (const Complex& c1, const Complex& c2);
Complex operator+(const Complex& c1,const Complex& c2);

#endif
