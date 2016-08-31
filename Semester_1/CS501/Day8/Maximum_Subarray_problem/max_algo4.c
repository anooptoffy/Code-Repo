#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 * Maximum subarray problem.
 * 
 * Time complexity : O(n)
 *
 * Using reduction in linear time.
 *
 *  https://en.wikipedia.org/wiki/Maximum_subarray_problem
 *
 */

int main(int argc, char const *argv[])
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int size = sizeof(a)/sizeof(a[0]);

	int maxSum = INT_MIN, length;

	int sum = 0, i = 0;

	for (int j = 0; j < size; ++j)
	{
		/* code */
		sum = sum + a[j];
		if(sum > maxSum)
			maxSum = sum;
		if(sum < 0)
		{
			i = j + 1;
			sum = 0;
		}
	}

	printf("The maxSum is %d\n",maxSum );

	return 0;
}