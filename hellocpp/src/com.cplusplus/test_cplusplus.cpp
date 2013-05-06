/*
 * test_cplusplus.cpp
 *
 *  Created on: 2013-5-5
 *      Author: Administrator
 */

void dynamic_main();
int classes_main_();
int classes2_main();
int polymorphism_main();
void structres();

using namespace std;
class TestCPlus{
public:
	static void test_dynamic(){
		dynamic_main();
	}

	static void test_classes(){
		//using namespace My;
		//My::classes_main_();
		classes_main_();
	}

	static void test_classes1(){
		classes2_main();

	}

	static void test_polymorphism(){
		polymorphism_main();
	}

	static void test_structres(){
		structres();
	}
};


