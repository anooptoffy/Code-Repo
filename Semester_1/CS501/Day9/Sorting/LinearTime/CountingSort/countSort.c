#include <stdio.h>
#include <stdlib.h>

/*
 * Counting Sort
 * 
 * Stable version. 
 *
 */

int main(int argc, char const *argv[])
{
	int b[] = {10, 9, 1, 44, 67, 100, 56, 7, 2, 44, 99, 54, 99, 34, 400, 93, 123, 400};
	int size = sizeof(b)/sizeof(b[0]);
	

	int count[500] = {0};

	for (int i = 0; i < size; ++i)
	{
		count[b[i]]++;
	}

	// for (int i = 0; i < 500; ++i)
	// {
	// 	printf("%d ", count[i]);
	// }
		

	for (int i = 1; i < 500; ++i)
	{
		count[i] += count[i-1];
	}

	// for (int i = 0; i < 500; ++i)
	// {
	// 	printf("%d ", count[i]);
	// }

	int res[size];

	for (int i = size - 1; i >= 0; --i)
	{
			res[count[b[i]]] = b[i];
			count[b[i]]--; 
	}

	for (int i = 1; i <= size; ++i)
	{
		printf("%d ", res[i]);
	}

	printf("\n");
	return 0;
}
