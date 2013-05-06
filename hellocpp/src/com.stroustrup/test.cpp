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
		PrintEntry p;
		p.print_entry_main();

		CountMary c;
		c.f();

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
		assoc_main();
		string_example_main();
	}

	static void test_Chapter18(){
		mismatch_main();
		club_main();
	}

	static void test_AppendixC(){
		array_main();
	}
};


