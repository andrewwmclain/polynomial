/*
    Title:      Lab 1 – Polynomial
    Purpose:    Implement polynomial class
    Author:     Dr. Carlos Arias and Andrew McLain
    Date:       April 15, 2020
*/

#include "polynomial.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::stringstream;


int main(int argc, char* argv[]){
	stringstream data[5];
	data[0].str("3 -1 2 0 -2.5");
	data[1].str("4 -1 -2 0 0 3");
	data[2].str("2 -1 0 4");
	data[3].str("3 -6 -5 2 1");
	data[4].str("1 -2 1");

	stringstream answers[6];
	answers[0].str("4 -2 0 0 -2.5 3"); // a + b
	answers[1].str("7 1 0 -4 2.5 2 6 0 -7.5"); // a * b
	answers[2].str("2 3 4 1"); // d / e
	answers[3].str("2 1 0 -4"); // -c
	answers[4].str("4 0 -4 0 2.5 3"); // b - a
	answers[5].str("2 2 0 -7.5"); // d/dx a

	Polynomial a(0), b(0), c(0), d(3), e(1), r(0);

	a.Read(data[0]);
	b.Read(data[1]);
	c.Read(data[2]);
	d.Read(data[3]);
	e.Read(data[4]);

	Polynomial s(0), t(0), u(0), v(0), w(0), x(0);
	s.Read(answers[0]);
	t.Read(answers[1]);
	u.Read(answers[2]);
	v.Read(answers[3]);
	w.Read(answers[4]);
	x.Read(answers[5]);


	float total = 0;
	if ((a + b) == s){
		cout << "\tSUM PASSED " << ++total << endl;
	}else{
		cout << "\tSUM FAILED" << endl;
	}

	if ((b - a) == w){
		cout << "\tSUBTRACT PASSED " << ++total << endl;
	}else{
		cout << "\tSUBTRACT FAILED" << endl;
	}

	if ((a * b) == t){
		cout << "\tMULTIPLY PASSED " << ++total << endl;
	}else{
		cout << "\tMULTIPLY FAILED" << endl;
	}

	if (a() == x){
		cout << "\tDERIVE PASSED " << ++total << endl;
	}else{
		cout << "\tDERIVE FAILED" << endl;
	}

	if (b(3) == 236.0){
		cout << "\tEVALUATE PASSED " << ++total << endl;
	}else{
		cout << "\tEVALUATE FAILED" << endl;
	}

	cout << "TOTAL TESTS TO PASS = 5" << endl;
	cout << "UNIT TEST GRADE = " << (total / 5 * 100) << endl;
	cout << " =======================" << endl;
	cout << "Extra Credit : : : : : : : : : " << endl;

	if (a(1, 2) == -7.375){
		total += 0.75;
		cout << "\tINTEGRATE PASSED " << total << endl;
	}else{
		cout << "\tINTEGRATE FAILED" << endl;
	}

	if ((d / e) == u){
		cout << "\tDIVIDE PASSED " << ++total << endl;
	}else{
		cout << "\tDIVIDE FAILED" << endl;
	}
	cout << "UNIT TEST FINAL GRADE = " << (total / 5 * 100) << endl;

	return 0;
}
