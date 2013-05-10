/*
 * exec.cpp
 *
 *  Created on: 2013-5-9
 *      Author: slieer
 */
/* system example : DIR */
#include <cstdio>      /* printf */
#include <cstdlib>     /* system, NULL, EXIT_FAILURE */

int exec_main() {
	int i;
	printf("Checking if processor is available...");
	if (system(NULL))
		puts("Ok");
	else
		exit(EXIT_FAILURE);
	printf("Executing command DIR...\n");
	i = system("dir");
	printf("The value returned was: %d.\n", i);
	return 0;
}

