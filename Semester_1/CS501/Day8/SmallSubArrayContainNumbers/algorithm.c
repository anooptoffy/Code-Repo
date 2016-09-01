#include <stdio.h>
#include <limits.h>

// TODO

/*
 * Smallest subarray contains all the numbers 1,2....k atleast once
 *
 */

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 10, 6, 3, 1, 2, 7, 6, 4, 2, 8, 6, 1, 7, 3};
	int size = sizeof(a)/sizeof(a[0]);

	int k = 4;
	int StartIndex = 0, EndIndex = 0;
	int c = 0;
	int aC[100] = {0};

	for (int i = 0; i < size; ++i)
	{
		if (a[i] <= k && aC[a[i]] >= 0)
		{
			if(aC[a[i]] == 1)
				c++;
			aC[a[i]]++;
			EndIndex = i;
		}

		if(c == k){
			int k = StartIndex;

			while(1){
				if(aC[a[k]] >= 2){
					aC[a[k]]--;
					k++;
				}
				else
					break;
			}
			StartIndex = k;
			//break;
		}
	}

	printf("Smallest sub array that contains all %d numbers is %d\n",k,(EndIndex - StartIndex + 1) );

	return 0;
}			