/*
    Title:      Lab 1 – Polynomial
    Purpose:    Implement polynomial class
    Author:     Dr. Carlos Arias and Andrew McLain
    Date:       April 15, 2020
*/


#include "polynomial.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cfloat>
#include <math.h>

using std::istream;
using std::ostream;
using std::string;
using std::stringstream;
using std::fixed;
using std::setprecision;
using std::showpos;

//Constructor with degree parameter
//Constructs polynomial object with given degree
//Parameters:
//size_t degree: degree of the polynomial
//returns nothing
Polynomial::Polynomial(size_t degree) : _degree(degree){
	_coefficients = new float[_degree + 1];
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = 0.0;
	}
}
//Constructor with size and coefficients array pointer parameter
//Constructs polynomial object with given degree and coefficients passed as float*
//Parameters:
//size_t degree: degree of polynomial
//const float* coefficients: coefficients of polynomial
//returns nothing
Polynomial::Polynomial(size_t degree, const float* coefficients): _degree(degree){
	_coefficients = new float[_degree + 1];
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = coefficients[i];
	}
}
//copy constructor, makes a deep copy
//Constructs polynomial object deep copy of polynomial object passed as parameter
//Parameters:
//const Polynomial& polynomial: polynomial being copied
//returns nothing
Polynomial::Polynomial(const Polynomial& polynomial): _degree(polynomial._degree){
	_coefficients = new float[_degree + 1];
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = polynomial._coefficients[i];
	}
}

//Destructor.
//Deallocates memory for _coefficients array
//Parameters:
//none
//returns nothing
Polynomial::~Polynomial(){
	// DO THIS FIRST TO PREVENT MEMORY LEAKS!
	delete[] _coefficients;
}
//operator+
//returns the sum of this polynomial and rhs
//Parameters:
//const Polynomial& rhs: polynomial being added to this polynomial
//returns a polynomial equal to the sum of this polynomial and rhs
const Polynomial Polynomial::operator+(const Polynomial& rhs)const{
    size_t degree;
    //set the degree of the sum equal to the degree of the higher-degree polynomial
    if(this->_degree >= rhs._degree){
        degree = this->_degree;
    }
    else{
        degree = rhs._degree;
    }
    //construct polynomial to return
    Polynomial p2(degree);
    //traverse p2's coefficient array and update the coefficients at each index
    //to be the sum of the coefficients of this and rhs at the same index
    for(size_t i = 0; i < degree + 1; i++){
        //if this and rhs go up to that degree, sum them
        if(i < rhs._degree + 1 && i < this->_degree + 1)
            p2._coefficients[i] = rhs._coefficients[i] + this->_coefficients[i];
        //if only this goes up to that degree
        else if(i < this->_degree + 1)
            p2._coefficients[i] = this->_coefficients[i];
        //if only rhs goes up to that degree
        else
            p2._coefficients[i] = rhs._coefficients[i];
    }

	return p2;
}
//binary operator-
//returns the difference of this polynomial and rhs
//Parameters:
//const Polynomial& rhs: polynomial being subtracted from this polynomial
//returns a polynomial equal to the difference of this polynomial and rhs
const Polynomial Polynomial::operator-(const Polynomial& rhs)const{
    size_t degree;
    //set degree of difference equal to higher-degree polynomial
    if(this->_degree >= rhs._degree){
        degree = this->_degree;
    }
    else{
        degree = rhs._degree;
    }
    //construct difference polynomial
    Polynomial p2(degree);
    //traverse difference polynomial, updating coefficient values
    for(size_t i = 0; i < degree + 1; i++){
        //if both this and rhs go up to that degree
        if(i < rhs._degree + 1 && i < this->_degree + 1)
            p2._coefficients[i] = this->_coefficients[i] - rhs._coefficients[i];
        //if only this goes up to that degree
        else if(i < this->_degree + 1)
            p2._coefficients[i] = this->_coefficients[i];
        //if only rhs goes up to that degree
        else
            p2._coefficients[i] = -rhs._coefficients[i];
    }

    return p2;
}
//unary operator -
//returns the additive inverse of this polynomial
//Parameters:
//None
//returns a polynomial equal to the additive inverse of this polynomial
const Polynomial Polynomial::operator-()const{
    //copy constructor
	Polynomial retVal(*this);
	//traverse retVal, multiplying each coefficient by -1
	for (size_t i = 0; i < _degree + 1; i++) {
		retVal._coefficients[i] *= -1;
	}
	return retVal;
}
//operator*
//return result of multiplying this polynomial by polynomial rhs
//Parameters:
//const Polynomial& rhs: polynomial being multiplied with this polynomial
//returns a polynomial equal to the product of this polynomial and rhs
const Polynomial Polynomial::operator*(const Polynomial& rhs)const{
    //construct empty p2 with degree equal to rhs + this
    Polynomial p2((this->_degree + rhs._degree));
    //traverse p2, updating the coefficient values
    for(size_t i = 0; i < this->_degree + 1; i++){
        for(size_t j = 0; j < rhs._degree + 1; j++){
            p2._coefficients[i + j] += this->_coefficients[i] * rhs._coefficients[j];
        }
    }

	return p2;
}
//operator/
//returns result of dividing this polynomial by rhs
//Parameters:
//const Polynomial& rhs: polynomial dividing this polynomial
//returns a polynomial equal to the quotient of this polynomial and rhs
const Polynomial Polynomial::operator/(const Polynomial& rhs)const{
    //dividing by larger polynomial gives nothing
    if(this->_degree < rhs._degree){
        return Polynomial(rhs);
    }
    //construct result polynomial with degree equal to this - rhs
    Polynomial remainder(*this);
    size_t degree = remainder._degree;
    Polynomial result(this->_degree - rhs._degree);
    //traverse through the result and update the remainder until the remainder can no longer be divided
    while(degree >= rhs._degree){
        result._coefficients[degree - rhs._degree] = remainder._coefficients[degree] /
                                                                rhs._coefficients[rhs._degree];
        remainder = remainder - (result * rhs);
        degree--;
    }
    return result;
}
//operator()
//return result of deriving this polynomial
//Parameters:
//none
//returns a polynomial equal to the derivative of this polynomial
const Polynomial Polynomial::operator()()const{
    //degree of polynomial goes down by one when deriving
    Polynomial p2(this->_degree - 1);
    //traverse p2, updating the coefficients
    for(size_t i = 1; i < this->_degree; i++){
        p2._coefficients[i - 1] = i * this->_coefficients[i];
    }
	return p2;
}
//operator(float x)
//return result of plugging in value x into the polynomial
//Parameters:
//float x: value being plugged in to polynomial
//returns the float total of the evaluted expression
float Polynomial::operator()(float x)const{
    float sum = 0.0;
    //traverse this coefficient array and add result of function to sum
    for(size_t i = 0; i < this->_degree + 1; i++){
        sum += this->_coefficients[i] * pow(x, i);
    }
    return sum;
}
//operator(float start, float end)
//return result of integrating this polynomial from bounds start to end
//Parameters:
//float start: lower bound of integral
//float end: upper bound of integral
//returns a float of the value of the evaluated definite integral
float Polynomial::operator()(float start, float end)const{
    //integration causes degree to increase by one
    Polynomial p3(this->_degree + 2);
    float val;
    //traverse through p3 and update the coefficients
    for(size_t i = 1; i < this->_degree + 2; i++){
        p3._coefficients[i] = this->_coefficients[i - 1] / i;
    }
    val = p3(end) - p3(start);
    return val;
}
//operator=
//assignment operator that changes this to equal rhs
//Parameters:
//const Polynomial& rhs: polynomial which this polynomial will be set equal to
//return this polynomial after it is assigned
const Polynomial& Polynomial::operator=(const Polynomial& rhs){
    //if they are already equal, just return this
	if (&rhs == this){
		return *this;
	}
	//if the degree is different, deallocate the coefficients array and resize it
	if (_degree != rhs._degree){
		if (_coefficients){
			delete[] _coefficients;
		}
		_degree = rhs._degree;
		_coefficients = new float[_degree + 1];
	}
	//update this coefficient array to equal rhs
	for (size_t i = 0; i < _degree + 1; i++) {
		_coefficients[i] = rhs._coefficients[i];
	}
	return *this;
}
//operator==
//returns whether this is equal to rhs
//Parameters:
//const Polynomial& rhs: polynomial being tested for equality with this polynomial
//returns true if this and rhs are equal, false if they are not
bool Polynomial::operator==(const Polynomial& rhs)const{
    //if the degree is different, we know they are not equal
	if (_degree != rhs._degree){
		return false;
	}
	//traverse the coefficients until they are not equal or the end is reached
	for (size_t i=0; i < _degree; i++){
		if (abs(_coefficients[i] - rhs._coefficients[i]) > 0.0001){
			return false;
		}
	}
	//if the end is reached, they are equal
	return true;
}
//ToString
//return this polynomial in its string representation with the degree and coefficients in increasing order
//Parameters:
// none
//returns string representation of this polynomial
string Polynomial::ToString()const{
	stringstream ss;
	for (size_t i = _degree; i > 0; i--) {
		ss << showpos << fixed << setprecision(2) << _coefficients[i] << "x^" << i << " ";
	}
	ss << showpos << fixed << setprecision(2) << _coefficients[0];
	return ss.str();
}
//Write
//Write this polynomial to an output stream
//Parameters:
//ostream& output: ostream which the polynomial will be read to
//returns output of this polynomial as an ostream
ostream& Polynomial::Write(ostream& output)const{
	output << _degree << " ";
	for (size_t i = 0; i < _degree + 1; i++) {
		output << _coefficients[i] << " ";
	}
	return output;
}
//Read
//Read this polynomial from an input stream
//Parameters:
//istream& input: istream which the polynomial will be read from
//returns istream& of this polynomial's input
istream& Polynomial::Read(istream& input){
	size_t degree;
	input >> degree;
	if (input.fail()){
		return input;
	}
	float* coefficients = new float[degree + 1];
	for (size_t i = 0; i < degree + 1; i++) {
		input >> coefficients[i];
		if (input.fail()){
			delete[] coefficients;
			return input;
		}
	}

	if (degree != _degree){
		if (_coefficients){
			delete[] _coefficients;
		}
		_degree = degree;
		_coefficients = coefficients;
	}else{
		for (size_t i = 0; i < _degree + 1; i++) {
			_coefficients[i] = coefficients[i];
		}
		delete[] coefficients;
	}
	return input;
}
