#include <cstdio>      /* printf */
#include <cstdlib>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void * a, const void * b) {
	return (*(int*) a - *(int*) b);
}

int sort_bsearch() {
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
