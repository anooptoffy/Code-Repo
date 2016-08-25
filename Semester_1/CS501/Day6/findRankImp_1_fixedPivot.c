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
	return j+1;
}


int pivot(int *arr, int i, int j){
	return arr[j];
}

int findRank(int *arr, int i, int j, int r){
	int p, k;
	if(i < j){
		p = pivot(arr,i,j);
		printf("\n Pivot is : %d",p);	
		k = partition(arr,i,j,p);
		printf("\n Position of pivot %d, is %d",p,k);
		if(r == (j-k+1))
			return p;
		else if( r < (j-k+1))
			return findRank(arr ,k+1 ,j, r);
		else
			return findRank(arr ,i ,k , r - j + k - 1); // bug use r - j + k - 1 instead of r - j + k
	}
}

int main(int argc, char *argv[]){
	int a[] = {60, 30, 100, 10}; 
	// 10, 30, 60, 100
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
        int size = sizeof(a)/sizeof(a[0]);
	int rank = 7;
	scanf("%d",&rank);
	while(rank != 1000){
        	printf("\n The element with rank %d is %d\n", rank, findRank(a ,0 ,size -  1, rank));
		scanf("%d",&rank);
	}
        printf("\n");

	return 0;
}
