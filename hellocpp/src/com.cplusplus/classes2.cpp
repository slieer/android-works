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
	CDummy();
	CDummy(int);
	int isitme(CDummy& param);
};

CDummy:: CDummy(){
	cout << "default constructor" << endl;
}

CDummy::CDummy(int x){
	cout << "next constructor, x is " << x << endl;
}

int CDummy::isitme(CDummy& param) {
	if (&param == this)
		return true;
	else
		return false;
}

int classes2_main() {
	CVector a(3, 1);
	CVector b(1, 2);
	CVector c;
	c = a + b;
	cout << c.x << "," << c.y << endl;

	CDummy a1;
	CDummy* b1 = &a1;
	if (b1->isitme(a1))
		cout << "yes, &a is b" << endl;

	CDummy b3(100);
	CDummy *b2 = new CDummy(100);

	if(! b3.isitme(*b2)){
		cout << "not equals!" << endl;
	}
	return 0;
}

