//============================================================================
// Name        : hellocpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "testheader/test.h"
#include "Stud.cpp"
#include "com.stroustrup/print_entry.cpp"
#include "com.stroustrup/count_mary.cpp"

using namespace std;

static void basicIOTest();
static void basicOjbTest();
static void test_print_entry();
static void test_count_mary();

#define TEST_THIS  1
int main() {
	int flag = TEST_THIS;
	if(flag == 1){
		test_count_mary();
	}else{
		basicIOTest();
		basicOjbTest();
		test_print_entry();
	}
}

static void basicIOTest(){
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	test();

	int a, b, s;
	cin >> a >> b;
	s = sum(a, b);

	cout << "a+b=" << s << endl;
}

static void basicOjbTest(){
	Student s;
	Student s1;
	s.display();
	s1.display();
}

static void test_print_entry(){
	PrintEntry p;
	p.print_entry_main();
}

static void test_count_mary(){
	CountMary c;
	c.f();
}
