/*
 * test.cpp
 *
 *  Created on: 2013-5-4
 *      Author: Administrator
 */

#include "print_entry.cpp"
#include "count_mary.cpp"
#include "count_various.cpp"
/**
 * http://www.stroustrup.com/3rd_code.html
 */
int sort_file_main();
int dc_main();
int assoc_main();
int string_example_main();
int mismatch_main();
int club_main();
int array_main();

class Test{
public:
	static void test_chapter2(){
		// std::list 使用
		PrintEntry p;
		p.print_entry_main();

		// 用std, 在字符串中查找字符
		CountMary c;
		c.f();

		// 自定义类型，模板，
		CountVarious count;
		count.count_various_main();

		sort_file_main();
	}

	static void test_chapter5(){}

	static void test_chapter6(){
		//dc_command_line(int argc, char* argv[]);
		dc_main();
	}

	static void test_chapter8(){
			//dc_namespace_main(int argc, char* argv[]);
	}

	static void test_Chapter11(){
		//http://www.stroustrup.com/assoc.c
		//[]重载
		assoc_main();
		//http://www.stroustrup.com/string_example.c
		//友元(友元函数是指某些虽然不是类成员却能够访问类的所有成员的函数。)，内部类
		string_example_main();
	}

	static void test_Chapter18(){
		mismatch_main();
		club_main();
	}

	static void test_AppendixC(){
		//多维数组
		array_main();
	}
};


