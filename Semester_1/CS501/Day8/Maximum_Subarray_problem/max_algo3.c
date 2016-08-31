#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 * Maximum subarray problem.
 * 
 * Time complexity : O(n lg(n))
 *
 * Using Divide and Conquer Algorithms
 * http://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
 */

int maxSum = INT_MIN;
int size;

void Conquer(int a[], int i, int m, int j){
	int l, mid, f;
	f  = i;
	mid = m;
	l = j;
	int sumL = 0, sumR = 0, sum = 0;
	for(int h = mid; h >= f; h--){
		sum += a[h];
		if(sum > sumL)
			sumL = sum;
	}
	sum  = 0;
	for (int k = mid + 1; k <= l; k++)
	{
		sum += a[k];
		if (sum > sumR)
		{
			/* code */
			sumR =  sum;
		}
	}
	
	if (maxSum < (sumR + sumL))
		maxSum = sumL + sumR;
}

void Divide(int a[], int i, int j){
	if(i < j){
		int mid = (i + j) / 2;
		Divide(a, i, mid);
		Divide(a, mid+1, j);
		Conquer(a, i, mid, j);
	}
}


int main(int argc, char const *argv[])
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	size = sizeof(a)/sizeof(a[0]);

	Divide(a, 0, size - 1);

	printf("The maxSum is %d\n", maxSum );

	return 0;
}