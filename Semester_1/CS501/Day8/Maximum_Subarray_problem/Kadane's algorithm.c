#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 *  http://www.algorithmist.com/index.php/Kadane's_Algorithm
 *  O(n) algorithm

The algorithm keeps track of the tentative maximum subsequence in (maxSum, maxStartIndex, maxEndIndex). It accumulates a partial sum in currentMaxSum and updates the optimal range when this partial sum becomes larger than maxSum.

Kadane's Algorithm(array[1..n])
begin
    (maxSum, maxStartIndex, maxEndIndex) := (-INFINITY, 0, 0)
    currentMaxSum := 0
    currentStartIndex := 1
    for currentEndIndex := 1 to n do
        currentMaxSum := currentMaxSum + array[currentEndIndex]
        if currentMaxSum > maxSum then
            (maxSum, maxStartIndex, maxEndIndex) := (currentMaxSum, currentStartIndex, currentEndIndex)
        endif

        if currentMaxSum < 0 then
            currentMaxSum := 0
            currentStartIndex := currentEndIndex + 1
        endif
    endfor

    return (maxSum, maxStartIndex, maxEndIndex)
end
 
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
