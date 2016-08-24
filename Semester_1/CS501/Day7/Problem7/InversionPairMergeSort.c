#include <stdio.h>


/*
 * Inversion Pair   Can we do better ? O(nlogn)  Try using Merge Sort
 * 
 *  a0, a1, a2, ... , an-1 is in the increasing order
 *  if i < j and ai > aj forms the inversion pair
 *
 *  Unsorted
 */

int c;

int MIP(int a[], int f, int mid, int l){
	if(a[f] > a[l])
		c = c + mid - f + l;
}

int IP(int a[], int i, int j){
	if(i < j){
		int mid = (i+j)/2;
		IP(a,i,mid);
		IP(a,mid+1,j);
		MIP(a,i,mid,j);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {4, 5, 2, 6, 1};
	int size = sizeof(a)/sizeof(a[0]);
	IP(a,0,size - 1);
	printf("\nThe number of inversion pairs are, %d\n", c);

	return 0;
}