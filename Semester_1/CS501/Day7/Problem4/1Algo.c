#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 *
 *
 * Sell Stock Problem
 * http://www.geeksforgeeks.org/stock-buy-sell/
 * Max(aj - ai) where i < j
 *
 * Page 68 CLRS
 * You may maximize the profit by either buying at lowest price or selling at the highest price.
 * 
 */

// int comparator(const void *l, const void *r){

// 	int f = *(const int *)l;
// 	int s = *(const int *)r;
// 	return s-f; // f-s asc s-f desc
// }


int main(int argc, char *argv[]){
	//int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int a[] = {10, 11, 7, 10, 6};
	int size = sizeof(a)/sizeof(a[0]);
	//int count = 0;
	//qsort((void *)a, size, sizeof(a[0]), comparator); // using a decreasing sequence
	//for(int i = 0; i < size; i++)
	//	printf("%d ", a[i]);
	printf("\n");

	int i = 0, max = a[1] - a[0]; // INT_MIN
	for(int j = 1; j < size ; j++)
	{
		if((a[j] - a[i]) > max)
			max= a[j] - a[i];
		if(a[j] < a[i])
			i = j;
	}

	printf("\n[When to buy] Day i is %d, price is %d\n", i, a[i]);
	return 0;
}
