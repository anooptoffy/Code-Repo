#include <stdio.h>
#include <stdlib.h>

/*
 * Wrong logic, incomplete [INGORE]
 *
 * Sell Stock Problem
 * Max(aj - ai) where i < j
 *
 * Page 68 CLRS
 */

int comparator(const void *l, const void *r){

	int f = *(const int *)l;
	int s = *(const int *)r;
	return f-s; // f-s asc s-f desc
}


int main(int argc, char *argv[]){
	int a[] = {10, 11, 7, 10, 6};
	int size = sizeof(a)/sizeof(a[0]);
	//int count = 0;
	//qsort((void *)a, size, sizeof(a[0]), comparator); // using a increasing sequence

	// for(int i = 0; i < size; i++)
	// 	printf("%d ", a[i]);
	// printf("\n");

	int i = 0, max = a[1] - a[0];
	for(int j = 1; j < size ; j++)
	{
		if(a[i] - a[j] > max)
			max= a[i] - a[j];
			{
				if(a[j] < a[i])
				i = j;
			}
	}

	printf("\n[When to buy] Day i is %d, price is %d\n", i, a[i]);
	return 0;
}
