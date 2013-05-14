/*
 * constructor_test.cpp
 *  Created on: --
 *      Author: slieer
 */
#include <iostream>
using namespace std;
namespace constructor_test {
/*
 * 析构执行是先自己再父类
 */
class A {
public:
	A() {
		cout << "A()" << endl;
	}

	/*不是虚析构函数*/
	~A() {
		std::cout << "~A" << std::endl;
	}
};

class B: public A {
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B" << endl;
	}
};
}

void test_construct_init() {
	/*
	 * 调用构造函数，从父类到子类。由远到近。
	 */
	constructor_test::A* p = new constructor_test::B;
	delete p;
}

