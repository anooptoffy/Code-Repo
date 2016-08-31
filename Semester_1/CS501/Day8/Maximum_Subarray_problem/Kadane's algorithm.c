#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 *  http://www.algorithmist.com/index.php/Kadane's_Algorithm
 */

int main(int argc, char const *argv[])
{
	//int a[] = {-5, -1, 2, -3, 0, -3, 3};
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int size = sizeof(a)/sizeof(a[0]);


	int maxSum = INT_MIN, maxStartIndex = 0, maxEndIndex = 0, currentMaxSum = 0;
	for (int i = 0; i < size; ++i)
	{
		/* code */
		currentMaxSum += a[i];

		if(currentMaxSum > maxSum)
		{
			maxSum = currentMaxSum;
			maxEndIndex = i;
		}	

		if(currentMaxSum < 0)
		{
			maxStartIndex = i +1;
			currentMaxSum = 0;
		}
	}

	printf("The maxSum is %d, maxStartIndex is %d, maxEndIndex is %d \n",maxSum, maxStartIndex, maxEndIndex );
	return 0;

}
