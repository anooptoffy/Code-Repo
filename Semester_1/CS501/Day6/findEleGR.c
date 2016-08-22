#include <stdio.h>
#include <limits.h>

/*
 * Chapter 9, Order Statistic and finding median, 
 * Discussion about "Selection Problem"
 *
 * Given an rank r, find element x ie. of rank r 
 * Rank(x) = r;
 * Complext O(nlg(n))
 * Can we make it linear ? ie. without explicit sorting.
 *
 */


void merge(int *A, int f, int l, int mid){
	int a1,a2,i,j,k;
	int L[100],R[100];
	
	a1 = mid - f + 1;
	a2 = l - mid;

	for(i = 1 ; i <= a1; i++)
		L[i] = A[f + i - 1];
	
	L[i+1] = INT_MAX;

	for(j = 1 ; j <= a2; j++)
		R[j] = A[ mid + j];

	R[j + 1] = INT_MAX;
	
	i = 1;
	j = 1;
	k = f;

	while(i <= a1 && j <= a2)
	{
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		} 
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while(i <= a1){
		A[k] = L[i];
		i++;
		k++;
	}

	while(j <= a2){
		A[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *A,int f, int l){
	int mid;
	
	mid = (	f + l ) / 2;
	if(f < l){
	mergeSort(A,f,mid);
	mergeSort(A,mid+1,l);
	merge(A,f,l,mid);
	}
}

int main(int argc, char *argv[]){
	int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99}; //Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
        int size = sizeof(a)/sizeof(a[0]);
	mergeSort(a,0,size-1);
	printf("Sorted Array\n");
	for(int i = 0; i < size; i++)
		printf("%d ", a[i]);
	
	int r = 7; // find the element that has rank 7.
	printf("\n The element with rank %d is %d", r, a[size-r]);
	printf("\n");
	return 0;
}
