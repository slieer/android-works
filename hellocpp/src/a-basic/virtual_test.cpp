namespace {

class A {
};

class B {
	void f() {
	}
	int i;
};

class C {
	virtual void f() {
	}
};

class D: public B, public C {
};
}

#include <iostream>
using namespace std;
void virtual_test() {
	cout << "sizeof(A) :" <<sizeof(A) << endl;
	cout << "sizeof(B) :" <<sizeof(B) << endl;
	cout << "sizeof(C) :" <<sizeof(C) << endl;
	cout << "sizeof(D) :" <<sizeof(D) << endl;
}
