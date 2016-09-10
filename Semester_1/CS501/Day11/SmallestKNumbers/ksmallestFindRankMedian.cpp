
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

/*
	Program to find k smallest elements in an array.

	Running and compiling

	$g++ ksmallestFindRankMedian.cpp data_decimal.in
	$./a.out

*/

#define MAX_ARRAY_SIZE 1000 // 10^6
#define MAX_BUFFER_SIZE 100  // 10^4


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
		//printf("Median of %d is %d\n", k, arr[pos] );
		swap(&arr[first], &arr[pos]);
		first++;
	}
	return goodPivot(arr, i, first - 1);
}


// Using bubble sort
int medianOf(int arr[], int start, int end){
	//printf("Start %d, End %d\n",start, end );
	for(int i = start ; i <=  end; i++){
		
		for (int j = start ; j < end - (i - start); ++j)
		{
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}

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
	int a[2*MAX_BUFFER_SIZE], i;
	int num;
	FILE *fp;

	fp = fopen(argv[1],"r");
	for(i = 0; i < 2*MAX_BUFFER_SIZE; i++){
		fscanf(fp, "%d",&num);
		//printf("%d - %d\n", i, num );
		a[i] = num;
	}

	for (int j = i; j < MAX_ARRAY_SIZE; j = j + MAX_BUFFER_SIZE)
	{
		// int p = goodPivot(a,0,2*MAX_BUFFER_SIZE -  1);
		// int k = partition(a,0,2*MAX_BUFFER_SIZE -  1, p);
		findRank(a, 0, 2*MAX_BUFFER_SIZE - 1, MAX_BUFFER_SIZE - 1);
		for (int t = MAX_BUFFER_SIZE; t < 2*MAX_BUFFER_SIZE; ++t)
		{
			
			fscanf(fp,"%d", &num);
			//printf("%d - %d\n",t, num );
			a[t] = num;
		}
	}

	printf("\n");
	for (int f = 0; f < MAX_BUFFER_SIZE; ++f)
	{
		printf("%d \n", a[f]);
	}

	printf("\n");
	fclose(fp);
	
	return 0;
}