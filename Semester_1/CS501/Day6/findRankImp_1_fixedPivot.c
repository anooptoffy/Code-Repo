#include <stdio.h>

/*
 * Check Order Statistics, Chapter 9 of CLRS
 * @Author : Anoop Toffy
 * Making Improvement in running time.
 * For, Given rank R can we find element x of rank R in linear time ?
 *
 */


void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// // This partition function has a bug since at times depending on the input the last elements will not be partitioned correctly
// int partition(int *A, int f, int l, int pivot){

// 	int i,j;
// 	i = f;
// 	j = l;
// 	while( i <= j)
// 	{

// 		while(A[i] <= pivot) i++;
// 		while(A[j] > pivot) j--;
// 		if(i <= j)
// 			swap(&A[i],&A[j]);
// 		i++;
// 		j--;
// 	}	
// 	return j+1;
// }

// Initial Swapping is necessary here to keep the pivot in correct position after partitions

/*

Link : https://en.wikipedia.org/wiki/Quicksort

algorithm1 <<<<Lomuto partition scheme>>>>

	algorithm partition(A, lo, hi) is
	    pivot := A[hi]
	    i := lo        // place for swapping
	    for j := lo to hi – 1 do
	        if A[j] ≤ pivot then
	            swap A[i] with A[j]
	            i := i + 1
	    swap A[i] with A[hi]
	    return i

algorithm2 <<<<Hoare partition scheme>>>>

	algorithm partition(A, lo, hi) is
	    pivot := A[lo]
	    i := lo – 1
	    j := hi + 1
	    loop forever
	        do
	            i := i + 1
	        while A[i] < pivot
	        
	        do
	            j := j – 1
	        while A[j] > pivot
	        
	        if i >= j then
	            return j
	        
	        swap A[i] with A[j]

*/

int partition(int A[], int f, int l, int pivot){

	int i,j;
	i = f;
	swap(&A[pivot],&A[l]);
	j = l - 1;
	
	while( i < j)
	{

		while(A[i] <= A[pivot]) i++;
		while(A[j] > A[pivot]) j--;
		if(i <= j){
			swap(&A[i],&A[j]);
			i++;
		}		
	}
	j++;
	swap(&A[j],&A[l]);	
	return j;
}


// We are using a fixed Pivot.
int pivot(int arr[], int i, int j){
	return j; // returing the index of the fixed pivot. Note the pivot itself
}

int findRank(int arr[], int i, int j, int r){
	int p, k, pivoted;

	p = pivot(arr,i,j);
	//printf("\n Pivot is : %d",arr[p]);
	pivoted = arr[p];	
	k = partition(arr,i,j,p); // we are passing the index of the pivot.
	//printf("\n Position of pivot %d, is %d",pivoted,k);
	if(r == (j-k+1))
		return k;
	else if( r < (j-k+1))
		return findRank(arr ,k + 1 ,j, r);
	else
		return findRank(arr ,i ,k - 1, r - j + k - 1); // bug use r - j + k - 1 instead of r - j + k Since rank = j-k+1 we are neglecting last j-k+1 ranks when element is in that left half

}

int main(int argc, char *argv[]){
	int a[] = {60, 30, 100, 10}; 
	// 10, 30, 60, 100
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
    int size = sizeof(a)/sizeof(a[0]);
	int rank;
	printf("Try Ranks Below %d\n", size + 1);
	printf("Print 1000 to Quit!!\n");
	scanf("%d",&rank);
	while(rank != 1000){
        printf("\n The element with rank %d is %d\n", rank, a[findRank(a ,0 ,size -  1, rank)]);
		scanf("%d",&rank);
	}

	// printf("\n");
	// for (int i = 0; i < size; ++i)
	// {
	// 	printf("%d ", a[i] );
	// }
    printf("\n");

	return 0;
}
