#include <stdio.h>



/*
	Find median in linear time using median of medians
	
	1. Using sort logic in medianOf
	2. Using partition Logic 

	https://www.youtube.com/watch?v=mR_RUjsJnV8
*/

int medianOf(int arr[], int start, int end);	
int goodPivot(int arr[], int i, int j);
void swap(int *a, int *b);

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int goodPivot(int arr[], int i, int j){

	if( (j - i) < 5)
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

int main(int argc, char *argv[]){
	int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99, 120, 108, 6}; 
	//Sorting looks : 1, 2, 7, 9, 10, 22, 30, |40|, 55, 60, 80, 99, 100, 108, 120	
	int size = sizeof(a)/sizeof(a[0]);

	//printf("Median is %d \n",a[medianOf(a, 0, size - 1)]);
	int k = goodPivot(a,0,size - 1);
	
	printf("The median is index %d,  %d\n",k, a[k]);
	printf("\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i] );
	}
	printf("\n");
	return 0;
}