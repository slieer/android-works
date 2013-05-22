#include "datetime.cpp"
#include "exec.cpp"
#include "sort_test.cpp"
#include "string_test.cpp"

class UtilsTest{
public:
	static void test(){
		testSort();
	}

	static void testDatetime(){

	}

	static void testSort(){
		OrderTest t;
		t.sort_bsearch();
		t.sort_vector();
	}
};
