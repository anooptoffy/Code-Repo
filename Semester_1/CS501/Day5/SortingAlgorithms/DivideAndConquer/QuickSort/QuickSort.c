#include <stdio.h>
#include <stdlib.h>

/*
 * Quick Sort
 *
 *
 */

int pivot(int *A,int f, int l){ 
// always returns the last element as the pivot
	return A[l];
}

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *A, int f, int l, int pivot){

	int i,j;
	i = f;
	j = l;
	while( i <= j)
	{

		while(A[i] <= pivot) i++;
		while(A[j] > pivot) j--;
		if(i <= j)
			swap(&A[i],&A[j]);
		i++;
		j--;
	}	
	return j;
}

int quicksort(int *A,int f, int l){
	if(l <= f)
		return 0;
	int p = pivot(A,f,l);
	int k = partition(A,f,l,p);
	//exit(0);
	quicksort(A,f,k);
	quicksort(A,k+1,l);
	return 0;
}

int main(){
	printf("\n");
	int a[] = { 2, 4, 1, 55, 66, 7, 90 ,101};
	int size = sizeof(a)/sizeof(a[0]);
	//exit(0);
	quicksort(a,0,size-1);
	//exit(0);
	for(int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
