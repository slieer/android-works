/*
 * exec.cpp
 *
 *  Created on: 2013-5-9
 *      Author: slieer
 */
/* system example : DIR */
#include <cstdio>      /* printf */
#include <cstdlib>     /* system, NULL, EXIT_FAILURE */
#include <unistd.h>

namespace exec {

int execute_main() {
	int i;
	printf("Checking if processor is available...");
	if (system(NULL))
		puts("Ok");
	else
		exit(EXIT_FAILURE);
	printf("Executing command DIR...\n");
	i = system("dir");
	printf("The value returned was: %d.\n", i);

	//system("exit");
	return 0;
}

int execl_main_1() {
	char args[] = " -l";
	execl("/bin/ls", "ls", "-al", "/etc/", NULL);
	return 0;
}
/**
 * exec()函数之间的主要区别就在于命令行参数如何传给新程序.
 * execl系列将argv中的没一个元素作为单独的参数传给程序,而用NULL结束整个列表.
 * execv将命令行参数作为C字符串数组来传递(是一个指向以\0结尾的字符串数组的以"NULL"结尾的指针数组中的一个指针)
 * execle 和execve则是多了环境变量.   execve是内核中的实际调用
 */
}

