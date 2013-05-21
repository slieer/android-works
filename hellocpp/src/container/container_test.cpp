/*
   动态数组 <vector>
 双向链表<list>

 deque
 array
 forward_list

 set
 multiset
 map
 multimap

 bitset

 unordered_set
 unordered_multiset
 unordered_map
 unordered_multimap

 queue
 priority_queue
 stack
 */

int list_main_0();
int list_main_1();
int map_main_();
void set_main_();
int vector_main_1();

class ContainerTest{
public :
	static void test(){

	}

	static void list_test(){
		list_main_0();
		list_main_1();
	}

	static void map_test(){
		map_main_();
	}

	static void vector_test(){
		vector_main_1();
	}

	static void set_test(){
		set_main_();
	}
};
