#include <stdio.h>
#include <stdlib.h>


/*
 *  Merge Sort
 *
 *
 *
 *
 */

void mergeSort(int *A,int sz){
	for(int j = 0; j < sz; j++)
		for(int i = 0; i < sz - 1 - j ; i++)	
			if(A[i] > A[i+1])
				swap(&A[i],&A[i+1]);					
}

int main(){
	printf("\n");
	int a[] = {5, 7, 4, 2, 40, 53, 99, 44, 1};
	int size;
	size = sizeof(a)/sizeof(a[0]);
	mergeSort(a,size);
	printf("Sorted Array\n");
	for(int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
