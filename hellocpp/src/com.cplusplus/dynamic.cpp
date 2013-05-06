/*
 * dynamic.cpp
 *
 * Dynamic memory in ANSI-C
 * Operators new and delete are exclusive of C++.
 * They are not available in the C language.
 * But using pure C language and its library,
 * dynamic memory can also be used through the functions malloc, calloc, realloc and free,
 * which are also available in C++ including the <cstdlib> header file (see cstdlib for more info).
 *
 */

// rememb-o-matic
#include <iostream>
#include <new>
using namespace std;

/*
 * new有三种使用方式：plain new，nothrow new和placement new。
（1）plain new顾名思义就是普通的new，就是我们惯常使用的new。在C++中是这样定义的：

    void* operator new(std::size_t) throw(std::bad_alloc);
    void operator delete(void *) throw();
	提示：plain new在分配失败的情况下，抛出异常std::bad_alloc而不是返回NULL，因此通过判断返回值是否为NULL是徒劳的。

（2）nothrow new是不抛出异常的运算符new的形式。nothrow new在失败时，返回NULL。定义如下：

    void * operator new(std::size_t,const std::nothrow_t&) throw();
    void operator delete(void*) throw();

（3）placement new意即“放置”，这种new允许在一块已经分配成功的内存上重新构造对象或对象数组。
    placement new不用担心内存分配失败，因为它根本不分配内存，它做的唯一一件事情就是调用对象的构造函数。定义如下：

    void* operator new(size_t,void*);
    void operator delete(void*,void*);
 *
 * */
int dynamic_main() {
	int i, n;
	int * p;
	cout << "How many numbers would you like to type? ";
	cin >> i;
	p = new (nothrow) int[i];

	cout << "new return value is " << p << endl;
	if (p == 0)
		cout << "Error: memory could not be allocated";
	else {
		for (n = 0; n < i; n++) {
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++)
			cout << p[n] << ", ";
		delete[] p;
	}
	return 0;
}

