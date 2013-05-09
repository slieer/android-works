#include <map>
#include <string>
#include <iostream>
using namespace std;

void map_insert(map<string, string> *mapStudent, string index, string x) {
	map<string, string>::value_type val(index, x);
	mapStudent->insert(val);
}

int map_main_() {
	char tmp[32] = "";
	map<string, string> mapS;

//insert element
	map_insert(&mapS, "192.168.0.128", "xiong");
	map_insert(&mapS, "192.168.200.3", "feng");
	map_insert(&mapS, "192.168.200.33", "xiongfeng");

	map<string, string>::iterator iter;

	cout << "We Have Third Element:" << endl;
	cout << "-----------------------------" << endl;

//find element
	iter = mapS.find("192.168.0.33");
	if (iter != mapS.end()) {
		cout << "find the elememt" << endl;
		cout << "It is:" << iter->second << endl;
	} else {
		cout << "not find the element" << endl;
	}

//see element
	for (iter = mapS.begin(); iter != mapS.end(); iter) {

		cout << "| " << iter->first << " | " << iter->second << " |" << endl;

	}
	cout << "-----------------------------" << endl;

	map_insert(&mapS, "192.168.30.23", "xf");

	cout << "After We Insert One Element:" << endl;
	cout << "-----------------------------" << endl;
	for (iter = mapS.begin(); iter != mapS.end(); iter) {

		cout << "| " << iter->first << " | " << iter->second << " |" << endl;
	}

	cout << "-----------------------------" << endl;

//delete element
	iter = mapS.find("192.168.200.33");
	if (iter != mapS.end()) {
		cout << "find the element:" << iter->first << endl;
		cout << "delete element:" << iter->first << endl;
		cout << "=================================" << endl;
		mapS.erase(iter);
	} else {
		cout << "not find the element" << endl;
	}
	for (iter = mapS.begin(); iter != mapS.end(); iter++) {

		cout << "| " << iter->first << " | " << iter->second << " |" << endl;

	}
	cout << "=================================" << endl;
	return 0;
}

static void swap() {
	map<int, int> m1, m2, m3;
	map<int, int>::iterator m1_Iter;

	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 200));
	m3.insert(pair<int, int>(30, 300));

	cout << "The original map m1 is:";
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;

	// This is the member function version of swap
	//m2 is said to be the argument map; m1 the target map
	m1.swap(m2);

	cout << "After swapping with m2, map m1 is:";
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;
	cout << "After swapping with m2, map m2 is:";
	for (m1_Iter = m2.begin(); m1_Iter != m2.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;
	// This is the specialized template version of swap
	swap(m1, m3);

	cout << "After swapping with m3, map m1 is:";
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;

	map<int, int> m6;
	map<int, int>::iterator m6_Iter;

	m6.insert(pair<int, int>(1, 20));
	m6.insert(pair<int, int>(4, 40));
	m6.insert(pair<int, int>(3, 60));
	m6.insert(pair<int, int>(2, 50));
	m6.insert(pair<int, int>(6, 40));
	m6.insert(pair<int, int>(7, 30));

	cout << "The original map m6 is:" << endl;
	for (m6_Iter = m6.begin(); m6_Iter != m6.end(); m6_Iter++)
		cout << m6_Iter->first << " " << m6_Iter->second << endl;

}
