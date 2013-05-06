/*
 * polymorphism.cpp
 *
 *  Created on: 2013-5-5
 *      Author: Administrator
 */

// virtual members
#include <iostream>
using namespace std;

/*
 * 一个类中有纯虚函数就是抽象类
 * */
class CPolygon {
protected:
	int width, height;
public:
	void set_values(int a, int b) {
		width = a;
		height = b;
	}
//	virtual int area() {
//		return (0);
//	}
	virtual int area()= 0;
};

class CRectangle: public CPolygon {
public:
	int area() {
		return (width * height);
	}
};

class CTriangle: public CPolygon {
public:
	int area() {
		return (width * height / 2);
	}
};

int polymorphism_main() {
	CRectangle rect;
	CTriangle trgl;

	CPolygon* ppoly1 = &rect;
	CPolygon* ppoly2 = &trgl;

	ppoly1->set_values(4, 3);
	ppoly2->set_values(4, 2);

	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;

	//CPolygon poly;
	//CPolygon* ppoly3 = &poly;
	//ppoly3->set_values(4, 1);
	//cout << ppoly3->area() << endl;
	return 0;
}

