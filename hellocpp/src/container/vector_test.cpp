/*
 * Array
 *
 *  Created on: 2013-5-7
 *      Author: slieer
 */

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//using std::vector;

static vector<int> vector_init();
static void append(vector<int> v, int val);
int vector_main_1() {
	//clock_t t = clock();
	vector<int> ve = vector_init();

	ve.push_back(100);  //append

	cout << "first element:" << ve.at(0) << endl;
	ve.push_back(-10);  //append
	ve.push_back(2);  //
	ve.push_back(50);  //
	ve.push_back(-1);  //

	cout << "vector size:" << ve.size() << endl;

	for (std::vector<int>::iterator it = ve.begin(); it != ve.end(); ++it){
	    cout << ' ' << *it;
	}
	cout << endl;
	return 0;
}

static vector<int> vector_init(){
	//动态数组
	vector<int> ivec(10);
	//它包含十个int型的元素 每个元素都被初始化为-1
	vector<int> ivec1(10, -1);

	int ia[6] = { -2, -1, 0, 1, 2, 1024 };
	//把 ia 的 6 个元素拷贝到 ivec 中
	vector<int> ivec2(ia,  ia + sizeof(ia) / sizeof(int));

	vector<int> ivec3(ivec2);

	return ivec3;
}

