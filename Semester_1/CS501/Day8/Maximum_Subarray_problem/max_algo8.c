
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

// TODO

/*
 * Maximum subarray problem. Such that sub array of length l
 * 
 * Time complexity : O(n)
 *
 * try, Using reduction in linear time.
 *
 *  https://en.wikipedia.org/wiki/Maximum_subarray_problem
 *	Exactly l http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
 *  Atleast l http://stackoverflow.com/questions/7861387/maximum-contiguous-subsequence-sum-of-at-least-length-l
 *  Atmost  l
 *
 * Atmost l
 * 
 * Can it be solved in linear time ? O(n)
 */

int main(int argc, char const *argv[])
{
	//int a[] = {-5, -1, 2, -3, 0, -3, 3};
	int a[] = {0,   5,    -3,    -1,    2,   -4,   1,    7 ,  8};
	int size = sizeof(a)/sizeof(a[0]);


	//int maxSum = 0, l = 3, sumL  = 0 ;
	int maxSum = 0, l = 2, sumL  = 0 ;
	
	for (int i = 0; i < l; ++i)
	{
		sumL += a[i];
	}
	maxSum = sumL;
	for (int i = l ; i < size; ++i)
	{
		/* code */
		sumL =  sumL - a[i-l] + a[i];

		if(sumL > maxSum){
			maxSum = sumL;
		}

	}


	printf("Maximum sum of length %d is %d\n", l, maxSum );
	return 0;

}
