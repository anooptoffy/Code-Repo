#include <stdio.h>
#include <stdlib.h>

/*
 * Inversion Pair   Can we do better ? O(nlogn)  Try using Merge Sort logic
 * 
 *  Let a0, a1, a2, ... , an-1  be a arbitrary sequence of numbers
 *  if i < j and ai > aj then [ai,aj] forms the inversion pair
 *
 *  Unsorted
 *  Links : http://www.geeksforgeeks.org/counting-inversions/
 */

int c;

int comparator(const void *a, const void *b){
	int f = *(int *)a;
	int s = *(int *)b;
	return s-f; //desc
}

int MIP(int a[], int f, int mid, int l){
	if(a[f] > a[l])
		c = c + mid - f + l;
}

int IP(int a[], int i, int j){
	if(i < j){
		int mid = (i+j)/2;
		//IP(a,i,mid);
		//IP(a,mid+1,j);
		MIP(a,i,mid,j);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {4, 5, 2, 6, 1};
	int size = sizeof(a)/sizeof(a[0]);
	qsort((void *)a,size, sizeof(a[0]),comparator);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	IP(a,0,size - 1);
	printf("\nThe number of inversion pairs are, %d\n", c);

	return 0;
}