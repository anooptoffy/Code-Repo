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
 * Random number generation : http://stackoverflow.com/questions/1608181/unique-random-numbers-in-an-integer-array-in-the-c-programming-language
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
	return j + 1;
}

int pivot(int *arr, int i, int j){
	return arr[j];
}

int findRank(int *arr, int i, int j, int r){
	int p, k;
	if(i < j){
		p = pivot(arr,i,j);
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

void randomNumbers(int *A, int n){	
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0; i < n; i++){
		A[i] = rand() % n;
	}
}

void randomRanks(int *B){
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0; i < m; i++){
		B[i] = rand() % n;
	}
}

int main(int argc, char *argv[]){
	
	int A[1000000], B[10000],m ,n; // A stores numbers and B stores ranks. 

	int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99}; 
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
        int size = sizeof(a)/sizeof(a[0]);
	int rank = 7;
	//printf("\n Array size : %d", size);
	//printf("\n Last element : %d", a[size - 1]);
        printf("\n The element with rank %d is %d", rank, findRank(a ,0 ,size -  1, rank));
        printf("\n");
	
	n = 1000;
	m = 100;
	printf("\n\n\n\n\n");
	randomNumbers(A);
	for(int i = 0; i < n ;i++)
		printf("%d ",A[i]);

	printf("\n\n\n\n\n");
	randomRanks(B);
	for(int i = 0; i < m ;i++)
		printf("%d ",B[i]);

	printf("\n\n\n\n\n");
	printf("\n The element with rank %d is %d", rank, findRank(A ,0 ,size -  1, rank));
	return 0;
}
