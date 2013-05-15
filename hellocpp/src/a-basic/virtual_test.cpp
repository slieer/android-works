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

/*
1、空类、单一继承的空类、多重继承的空类所占空间大小为：1（字节，下同）；
2、一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间的；
3、因此一个对象的大小≥所有非静态成员大小的总和；
4、当类中声明了虚函数（不管是1个还是多个），那么在实例化对象时，编译器会自动在对象里安插一个指针vPtr指向虚函数表VTable；
5、虚承继的情况：由于涉及到虚函数表和虚基表，会同时增加一个（多重虚继承下对应多个）vfPtr指针指向虚函数表vfTable和一个vbPtr指针指向虚基表vbTable，这两者所占的空间大小为：8（或8乘以多继承时父类的个数）；
6、在考虑以上内容所占空间的大小时，还要注意编译器下的“补齐”padding的影响，即编译器会插入多余的字节补齐；
7、类对象的大小=各非静态数据成员（包括父类的非静态数据成员但都不包括所有的成员函数）的总和+ vfptr指针(多继承下可能不止一个)+vbptr指针(多继承下可能不止一个)+编译器额外增加的字节。
 * */
void virtual_test() {
	cout<< sizeof (int) <<endl;

	cout << "sizeof(A) :" <<sizeof(A) << endl; //1
	cout << "sizeof(B) :" <<sizeof(B) << endl; //4
	cout << "sizeof(C) :" <<sizeof(C) << endl; //4
	cout << "sizeof(D) :" <<sizeof(D) << endl; //8
}
