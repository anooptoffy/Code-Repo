#include <stdio.h>
#include <stdlib.h>

/*
 * Selection Sort
 *  
 *   Number of Comparisons : 0(n^2)
 *   Number of Swaps : 0(n)
 *  
 *  Finds the maximum element and push it to the last index.
 *  Hence right side of the array remains sorted after each
 *  Iteration. 
 *  We are only doing swapping 0(n) times. (ie. the advantage)
 *  Considerable reduction in number of swaps.
 *
 */

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int *A,int sz){
	int idx;
	for(int j = 0; j < sz; j++){
		idx = 0;
		for(int i = 0; i < sz - j ; i++){
			if(A[i] > A[idx])
				idx = i;
		}
		swap(&A[sz-1-j],&A[idx]);					
	}
}

int main(){
	printf("\n");
	int a[] = {5, 7, 4, 2, 40, 53, 99, 44, 1};
	int size;
	size = sizeof(a)/sizeof(a[0]);
	selectionSort(a,size);
	printf("Sorted Array\n");
	for(int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
