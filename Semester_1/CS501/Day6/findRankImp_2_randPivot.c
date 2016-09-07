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

#define TOTAL_NUMBERS 1000000
#define TOTAL_RANKS 100

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *A, int f, int l, int pivot){

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

// Taking a random pivot instead of a fixed pivot.

int pivot(int a[], int i, int j){
	int pivot =  i + rand() % (j - i +1);
	return pivot;
}

int findRank(int *arr, int i, int j, int r){
	int p, k;
	
	p = pivot(arr,i,j);
	//printf("\n Pivot is : %d",p);	
	k = partition(arr,i,j,p);
	//printf("\n Position of pivot %d, is %d",p,k);
	if(r == (j-k+1))
		return p;
	else if( r < (j-k+1))
		return findRank(arr ,k+1 ,j, r);
	else
		return findRank(arr ,i ,k - 1, r - j + k -  1);
	
}

void randomNumbers(int *A){	
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0; i < TOTAL_NUMBERS; i++){
		A[i] = rand() % TOTAL_NUMBERS;
	}
}

void randomRanks(int *B){
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0; i < TOTAL_RANKS; i++){
		B[i] = rand() % TOTAL_NUMBERS;
	}
}

int main(int argc, char *argv[]){
	
	int A[TOTAL_NUMBERS], B[TOTAL_RANKS]; // A stores numbers and B stores ranks. 
	FILE *fp_num, *fp_rank, *fp_out;

	// Testing with a fixed Rank.
	int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99}; 
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
    int size = sizeof(a)/sizeof(a[0]);
	int rank = 10;
    printf("\n The element with rank %d is %d", rank, a[findRank(a ,0 ,size -  1, rank)]);
    printf("\n");
	

	printf("\n\n\n\n\n");
	fp_num = fopen("data.in","r");
	//randomNumbers(A); // Generates a set of random numbers of size TOTAL_NUMBERS
	for(int i = 0; i < TOTAL_NUMBERS;i++)
		//printf("%d ",A[i]);
		fscanf(fp_num, "%d", &A[i]);

	printf("\n\n\n\n\n");
	fp_rank = fopen("data_rank.in","r");
	//randomRanks(B); // Generated a set of random ranks to compute
	for(int i = 0; i < TOTAL_RANKS ;i++)
		//printf("%d ",B[i]);
		fscanf(fp_rank, "%d", &B[i]);

	fclose(fp_rank);
	fclose(fp_num);


	fp_out = fopen("data_out.in","w");
	for(int i = 0; i < TOTAL_RANKS ;i++)
	{
		fprintf(fp_out, "%d\n", A[findRank(A ,0 ,TOTAL_NUMBERS - 1, B[i])]);
		//printf("\n The element with rank %d is %d", B[i], A[findRank(A ,0 ,TOTAL_NUMBERS - 1, B[i])]);
	}
	
 	fclose(fp_out);

 	printf("\n\n\n\n\n");
	return 0;
}
