#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 * Maximum subarray problem. Such that sub array of length l
 * 
 * Time complexity : O(nl)
 *
 * try, Using reduction in linear time.
 *
 *  https://en.wikipedia.org/wiki/Maximum_subarray_problem
 *	Exactly l http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
 *  Atleast l http://stackoverflow.com/questions/7861387/maximum-contiguous-subsequence-sum-of-at-least-length-l
 *  Atmost  l
 *
 * Exactly l , O(nl) time
 * 
 * Can it be solved in linear time ? O(n)
 */

int main(int argc, char const *argv[])
{
	int a[] = {-5, -1, 2, -3, 0, -3, 3};
	int size = sizeof(a)/sizeof(a[0]);


	int maxSum = 0, l = 3;


	return 0;

}
