#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 * Maximum subarray problem.
 * 
 * Time complexity : O(n^2)
 *
 *
 */

int main(int argc, char const *argv[])
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int size = sizeof(a)/sizeof(a[0]);

	int maxSum = INT_MIN, length;

	for (int i = 0; i < size; ++i)
	{
		int sum = 0;
		for (int j = i; j < size; ++j)
		{
			/* code */
			sum += a[j];
			if(sum > maxSum)
				maxSum = sum;
		}
	}

	printf("The maxSum is %d\n", maxSum );

	return 0;
}