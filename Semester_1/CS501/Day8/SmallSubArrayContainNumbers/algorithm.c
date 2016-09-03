#include <stdio.h>
#include <limits.h>

// TODO - DONE

/*
 * Smallest subarray contains all the numbers 1,2....k atleast once
 *
 */

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 10, 6, 3, 1, 2, 7, 6, 4, 2, 8, 6, 1, 7, 3};
	int size = sizeof(a)/sizeof(a[0]);

	int k = 4;
	int StartIndex = 0, EndIndex = size;
	int c = 0;
	int aC[100] = {0};
	int length = 0; // This should be minimum.

	for (int i = 0; i < size; ++i)
	{
		if (a[i] <= k)
		{
			aC[a[i]]++;
			if(aC[a[i]] == 1)
				c++;
			
			//EndIndex = i;
		}
		//printf("[DEBUG] The value of i is %d\n", i);
		//printf("[DEBUG] The c value is %d\n", c);
		if(c == k){
			int l = StartIndex;

			while(1){
				if(a[l] > k)
				{
					l++;
					continue;
				}
				//printf("The count of k (%d) in aC[%d] is %d\n",k,k, aC[a[k]]);
				if(aC[a[l]] > 1){
					aC[a[l]]--;
					l++;
				}
				else
					break;
			}
			if((i - l + 1) < (EndIndex - StartIndex + 1)){
				StartIndex = l;
				EndIndex = i;
			}
			//printf("The value of StartIndex is %d\n", StartIndex);
			//break;
		}
	}

	printf("Smallest sub array that contains all %d numbers is %d\n",k,(EndIndex - StartIndex + 1) );
	printf("StartIndex %d, EndIndex %d\n",StartIndex,EndIndex );

	return 0;
}			