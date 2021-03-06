#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>


/*

	Find Rank using Median of Medians

*/

#define TOTAL_NUMBERS 1000000
#define TOTAL_RANKS 100

int medianOf(int arr[], int start, int end);	
int goodPivot(int arr[], int i, int j);
void swap(int *a, int *b);

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int arr[], int l, int h, int p)
{
    int x = arr[p];
    swap(&arr[p],&arr[h]); // swapping the pivot with the last index
    int i = l - 1;
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

int goodPivot(int arr[], int i, int j){

	if( (j - i) <= 5)
		return medianOf(arr, i, j);

	int start, end, pos, first;
	first = i;
	for (int k = i; k <= j; k = k + 5)
	{
		if( k >= j)
			end = j;
		else
			end = k + 4;
		start = k;
		
		pos = medianOf(arr, start, end);
		printf("Median of %d is %d\n", k, arr[pos] );
		swap(&arr[first], &arr[pos]);
		first++;
	}
	return goodPivot(arr, i, first - 1);
}


// Using bubble sort
int medianOf(int arr[], int start, int end){
	printf("Start %d, End %d\n",start, end );
	for(int i = start ; i <=  end; i++){
		
		for (int j = start ; j < end - (i - start); ++j)
		{
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}

	printf("\n");
	for (int i = start; i <= end; ++i)
	{
		printf("%d ", arr[i] );
	}
	printf("\n");

	return start + ((end - start +  1) / 2);
}

int findRank(int arr[], int i, int j, int r){
	int p, k;
	p = goodPivot(arr,i,j);
	k = partition(arr,i,j,p); // we are passing the index of the pivot.
	if(r == (j-k+1))
		return k;
	else if( r < (j-k+1))
		return findRank(arr ,k + 1 ,j, r);
	else
		return findRank(arr ,i ,k - 1, r - j + k - 1); // bug use r - j + k - 1 instead of r - j + k Since rank = j-k+1 we are neglecting last j-k+1 ranks when element is in that left half

}


int main(int argc, char const *argv[])
{
	//int A[TOTAL_NUMBERS], B[TOTAL_RANKS]; // A stores numbers and B stores ranks. 

	// Testing with a fixed Array and Rank.
	int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99}; 
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
    int size = sizeof(a)/sizeof(a[0]);
	int rank = 10;
    printf("\n The element with rank %d is %d", rank, a[findRank(a ,0 ,size -  1, rank)]);
    
    printf("\n");
    for (int i = 0; i < size; ++i)
    {
    	printf("%d ",a[i] );
    }
    printf("\n");
	return 0;
}