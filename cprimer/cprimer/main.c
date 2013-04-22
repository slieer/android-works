#include <stdio.h>

/**
 * http://blog.csdn.net/ds1121/article/details/5680708
 * 
 * 有关C语言中比较晦涩的阴暗角落，比如类型提升、 类型转换、型别退化以及其它一些无用的东西
 * */
void f();
void ff();
int main(int argc, char **argv)
{
	//printf("hello world\n");
	f();
	ff();
	return 0;
}

void f(){
	unsigned int ui_one = 1;
	signed int i_one = 1;
	signed short s_minus_one = -1;
	if (s_minus_one > ui_one){
		printf ("-1 > 1 \n");		
	}

	if (s_minus_one < i_one){
		printf ("-1 < 1 \n");
	}
}

void ff(){
	int array[] = {0, 1, 2, 3, 4};
	int *pointer = array;
	//printf("%s",sizeof array);
	//printf("%s", sizeof pointer);
	if (sizeof array == sizeof pointer){
		printf ("This will never be printed!!");	
	}
	
	if (sizeof(int *) == sizeof &array[0]){
		printf ("This will be printed!!\n");
	}
	
	if (&array[2] - &array[0] == 8 ){
		printf ("This will never be printed either, result is 2 not 8!!");
	}
}