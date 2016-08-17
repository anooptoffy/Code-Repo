#include <stdio.h>
#include <stdlib.h>


/*
 *  Insertion Sort
 *
 *  Number of comparisons is 0(n^2)
 *  If sorted (Best case) 0(n)
 *
 *
 */

void insertionSort(int *A,int sz){
	for(int j = 1; j < sz; j++){
		int t = A[j];
		int i = j - 1;
		while( i >= 0 && A[i] > t){	
			A[i+1] = A[i];
			i--;
		}	
		A[i + 1] = t;					
	}
}

int main(){
	printf("\n");
	int a[] = {5, 7, 4, 2, 40, 53, 99, 44, 1};
	int size;
	size = sizeof(a)/sizeof(a[0]);
	insertionSort(a,size);
	printf("Sorted Array\n");
	for(int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
