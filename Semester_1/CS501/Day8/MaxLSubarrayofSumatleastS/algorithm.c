
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

/*
 * a0,a1, ---- an-1
 * 
 *
 * min length of sub array whose sum is atleast S
 *
 *
 */

int main(int argc, char const *argv[])
{
	int a[] = {10, 0, 5, 5, 3, 7, 12, 6};
	int size = sizeof(a)/sizeof(a[0]);

	int minLength = size, S = 12, sum = 0;
	int j = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += a[i];
		if(sum > S){
			if(minLength >  i - j + 1)
			{
				minLength = i - j + 1;
			}
			while(sum > S){
				sum = sum - a[j];
				j++;
			}
		}
	}

	printf("The minLength sub array whose sum is > %d is %d\n", S, minLength );

	return 0;
}
