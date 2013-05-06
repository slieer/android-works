/*
 * classes.cpp
 *
 *  Created on: 2013-5-5
 *      Author: Administrator
 */

// classes example
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace My {

class CRectangle {
	int x, y;
public:
	CRectangle(){}
	CRectangle(int, int);
	void set_values(int, int);
	int area() {
		return (x * y);
	}
};

CRectangle::CRectangle(int a, int b) {
	x = a;
	y = b;
}

void CRectangle::set_values(int a, int b) {
	x = a;
	y = b;
}

}

int classes_main_() {
	 using namespace My;

	CRectangle rect;
	rect.set_values(3, 4);
	cout << "area: " << rect.area() << endl;
	return 0;
}

