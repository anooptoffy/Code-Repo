#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


/*
 * Counting Sort
 *
 * Using only Binary Numbers
 *
 * Complexity : O(2n)
 * For getting O(n) do swapping by traversing from either end, This method will caust you stability of the array
 */

int main(int argc, char const *argv[])
{
	int b[] = {0,1,1,1,1,0,0,1,0,1,0,1,1,0,0,1};
	int size = sizeof(b)/sizeof(b[0]);
	int CZero = 0, COne = 0;
	for (int j = 0; j < size; ++j)
	{
		if(b[j] == 0)
			CZero++;
		if(b[j] == 1)
			COne++;
	}

	for (int i = 0; i < CZero; ++i)
	{
		printf("%d ", 0);
	}


	for (int i = 0; i < COne; ++i)
	{
		printf("%d ", 1);
	}	
	printf("\n");
	return 0;
}