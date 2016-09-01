
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 * Maximum Density Subsequence
 * O(n)
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
	int currentSum = sumL, currentDensity = currentSum / l, maxDensity = currentDensity;
	int start = 0;
	for (int i = l ; i < size; ++i)
	{
		if (currentSum < 0)
		{
			/* code */
			currentSum =  currentSum - a[i-l] + a[i];
			start = i - l;
		}
		else
			currentSum += a[i];
		/* code */
		
		currentDensity = currentSum / (i - start + 1);

		if(currentDensity > maxDensity){
			maxDensity = currentDensity;
		}



	}


	printf("Maximum Density of Subsequence of length > %d is %d\n", l, maxSum );
	return 0;

}
