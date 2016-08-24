
#include <stdio.h>
#include <stdlib.h>

/*
 * Inversion Pair  O(n^2)
 * 
 *  a0, a1, a2, ... , an-1 is in the increasing order
 *  if i < j and ai > aj forms the inversion pair
 *
 *  The number of inversion pairs for a desc sorted sequence is 0 (n*(n-1))/2
 */

int comparator(const void *a, const void *b){
	int f = *(int *)a;
	int s = *(int *)b;
	return s-f; //desc
}

int main(int argc, char *argv[]){
	int a[] = {4, 5, 2, 6, 1};
	int size = sizeof(a)/sizeof(a[0]);

	qsort((void *)a,size, sizeof(a[0]),comparator);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if(a[i] > a[j])
				count++;
		}
	}

	printf("\nThe number of inversion parirs are %d\n", count);
	printf("\n");

	return 0;
}
