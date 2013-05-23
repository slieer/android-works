#include "datetime.cpp"
#include "sort_test.cpp"
#include "string_test.cpp"

class UtilsTest{
public:
	static void test(){
		int test = 1;
		if(test == 1){
			testDatetime();
		}else{
			testSort();
		}
	}

	static void testDatetime(){
		//DateTimeTest::ftimeTest();
		DateTimeTest::timeTest();
	}

	static void testSort(){
		OrderTest::sort_bsearch();
		OrderTest::sort_vector();
	}
};
