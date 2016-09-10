
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

// Taking a random pivot instead of a fixed pivot.

int pivot(int arr[], int i, int j){
	int pivot =  i + rand() % (j - i +1);
	return pivot;
}


int main(int argc, char const *argv[])
{
	int a[2*MAX_BUFFER_SIZE], i;
	int num;
	FILE *fp;
	int p, k;

	fp = fopen(argv[1],"r");
	for(i = 0; i < 2*MAX_BUFFER_SIZE; i++){
		fscanf(fp, "%d",&num);
		//printf("%d - %d\n", i, num );
		a[i] = num;
	}

	for (int j = i; j < MAX_ARRAY_SIZE; )
	{
		// int p = goodPivot(a,0,2*MAX_BUFFER_SIZE -  1);
		// int k = partition(a,0,2*MAX_BUFFER_SIZE -  1, p);
		p = pivot(a,0,2*MAX_BUFFER_SIZE -  1);
		k = partition(a,0,2*MAX_BUFFER_SIZE -  1,p); 
		if( k > MAX_BUFFER_SIZE){
			for (int t = k; t < 2*MAX_BUFFER_SIZE; ++t)
			{
				
				fscanf(fp,"%d", &num);
				//printf("%d - %d\n",t, num );
				a[t] = num;
			}
			j = j + 2*MAX_BUFFER_SIZE - k;
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