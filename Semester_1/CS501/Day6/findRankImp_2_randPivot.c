#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

/*
 * Check Order Statistics, Chapter 9 of CLRS
 * @Author : Anoop Toffy
 * Making Improvement in running time.
 * For, Given rank R can we find element x of rank R in linear time ?
 *
 * Now choosing a random pivot.
 * Let A[n] holds array of size n that contains n numbers, 10 < n <= 10^6
 * Let B[m] holds array of ranks.  1 <= m <= 10^4
 * 
 * we need to pick a random pivot using the ranks in the B array.
 * ie. find a random rank and try finding the element with rank R.
 * 
 * Randomized Version of the pivot.
 *
 */ 

int A[1000000], B[10000]; // A stores numbers and B stores ranks. 

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
	return j + 1;
}

int randomPivot(int *arr, int i, int j){
	time_t t;
	srand((unsigned) time(&t));
	return arr[rand() % 10000];
}

int findRank(int *arr, int i, int j, int r){
	int p, k;
	if(i < j){
		p = randomPivot(arr,i,j);
		//printf("\n Pivot is : %d",p);	
		k = partition(arr,i,j,p);
		//printf("\n Position of pivot %d, is %d",p,k);
		if(r == (j-k+1))
			return p;
		else if( r < (j-k+1))
			return findRank(arr ,k+1 ,j, r);
		else
			return findRank(arr ,i ,k , r - j + k);
	}
}

void randomNumbers(int size){
	long int i,n;	
	time_t t;
	n = pow(10,size); // 10^6
	srand((unsigned) time(&t));
	for(i = 0; i < n; i++){
		A[i] = rand() % 1000000;
	}
	//printf("\nCount %ld",i);
}

void randomRanks(int size){
	long int i,n;	
	time_t t;
	n = pow(10,size); // 10^4
	srand((unsigned) time(&t));
	for(i = 0; i < n; i++){
		B[i] = rand() % 10000;
	}
}

int main(int argc, char *argv[]){
	//int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99}; 
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
        long size = sizeof(A)/sizeof(A[0]);
	int rank = 7;
	//printf("\n Array size : %d", size);
	//printf("\n Last element : %d", a[size - 1]);
	
	randomNumbers(6);
	randomRanks(4);
        printf("\n The element with rank %d is %d", rank, findRank(A ,0 ,size -  1, rank));
        printf("\n");

	return 0;
}
