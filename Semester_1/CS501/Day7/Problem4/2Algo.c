#include <stdio.h>
#include <stdlib.h>

/*
 *
 *
 * Sell Stock Problem
 * Max(aj - i) where i < j
 *
 */

int comparator(const void *l, const void *r){

	int f = *(const int *)l;
	int s = *(const int *)r;
	return f-s; // f-s asc s-f desc
}


int main(int argc, char *argv[]){
	int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int size = sizeof(a)/sizeof(a[0]);
	//int count = 0;
	qsort((void *)a, size, sizeof(a[0]), comparator); // using a increasing sequence

	for(int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");

	int i = 0, max = a[size-1] - a[0];
	for(int j = 1; j < size ; j++)
	{
		if(a[i] - a[j] > max)
			max= a[i] - a[j];
		if(a[j] < a[i])
			i = j;
	}

	printf("\ni is %d, max is %d\n", i, max);
	return 0;
}
