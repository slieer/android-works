/*
 * classes2.cpp
 *
 *  Created on: 2013-5-5
 *      Author: Administrator
 */

// vectors: overloading operators example
#include <iostream>
using namespace std;

/**
 * 运算符重载
 */
class CVector {
public:
	int x, y;
	CVector() {
		x = 0;
		y = 0;
	}
	;

	CVector(int, int);
	CVector operator +(CVector);
};

CVector::CVector(int a, int b) {
	x = a;
	y = b;
}

CVector CVector::operator+(CVector param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return (temp);
}

class CDummy {
public:
	int isitme(CDummy& param);
};

int CDummy::isitme(CDummy& param) {
	if (&param == this)
		return true;
	else
		return false;
}

int classes_main() {
	CVector a(3, 1);
	CVector b(1, 2);
	CVector c;
	c = a + b;
	cout << c.x << "," << c.y;

	CDummy a1;
	CDummy* b1 = &a1;
	if (b1->isitme(a1))
		cout << "yes, &a is b";
	return 0;
}

