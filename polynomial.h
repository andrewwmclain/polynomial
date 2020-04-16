/*
    Title:      Lab 1 – Polynomial
    Purpose:    Implement polynomial class
    Author:     Dr. Carlos Arias and Andrew McLain
    Date:       April 15, 2020
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

class Polynomial{
	size_t _degree;
	float* _coefficients;
public:
	Polynomial(size_t);
	Polynomial(size_t, const float*);
	Polynomial(const Polynomial&);
	~Polynomial();
    const Polynomial operator+(const Polynomial&)const;
    const Polynomial operator-(const Polynomial&)const;
    const Polynomial operator-()const;
    const Polynomial operator*(const Polynomial&)const;
    const Polynomial operator/(const Polynomial&)const;
    const Polynomial operator()()const;
    float operator()(float)const;
    float operator()(float, float)const;
	const Polynomial& operator=(const Polynomial&);
	string ToString()const;
    bool operator==(const Polynomial&)const;
    ostream& Write(ostream&)const;
	istream& Read(istream&);

};



#endif
