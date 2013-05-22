#include <cstdio>      /* printf */
#include <cstdlib>     /* qsort */
#include <vector>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;
class OrderTest{
private:
	static int compare(const void * a, const void * b) {
		return (*(int*) a - *(int*) b);
	}
public:

	/**
	 * c语方快排序
	 */
	static int sort_bsearch() {
		int values[] = { 40, 10, 100, 90, 20, 25 };
		qsort(values, 6, sizeof(int), compare);

		int key = 40;
		int * pItem = (int*) bsearch(&key, values, 6, sizeof(int), compare);
		if (pItem != NULL)
			printf("%d is in the array.\n", *pItem);
		else
			printf("%d is not in the array.\n", key);

		for (int n = 0; n < 6; n++)
			printf("%d ", values[n]);
		return 0;
	}

	//list_test
	static void sort_list(){}

	static void sort_vector(){
		vector<int> ve;

		ve.push_back(100);
		ve.push_back(-10);
		ve.push_back(2);
		ve.push_back(50);
		ve.push_back(-1);

		//functional: less<Type>（升序）、greater<Type>（降序）
		sort(ve.begin(),ve.end(), less<int>());//
	}

};



