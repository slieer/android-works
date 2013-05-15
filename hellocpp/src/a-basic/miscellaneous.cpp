#include <cstdio>
#include <iostream>

using namespace std;
static void _MyNew(int* p) {
	p = new int;
}

/**
 static int f(int a) {
 if (a > 0) {
 return 0;
 }
 return a;
 }
 */
static int like_f(int a) {
	return (a - -a) / 2;
}

static void callByVal() {
	int*p = NULL;
	bool isFailed = false;
	_MyNew(p);

	if (p == NULL)
		isFailed = true;

	cout << "isFailed:" << isFailed << endl;
}

class Poin {
public:
	static void func() {
		/*
		 * ISO C++ forbids incrementing a pointer of type 'void*' [-fpermissive]
		 * */
//		void* p = NULL;
//		p++;
		char* q = NULL;
		q++;
		int* r = NULL;
		r++;
	}

	static void f(int* p) {
	}
	static void f1(int p[]) {
	}
};

void miscellaneous() {
	cout << "like_f(1):" << like_f(1) << endl;
	cout << "like_f(-20):" << like_f(-20) << endl;

	callByVal();

	Poin p;
	p.func();
	p.f(NULL);
	p.f1(NULL);

}

