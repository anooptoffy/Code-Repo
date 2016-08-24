#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
 *
 * Majority Number n/3 + 1
 *
 * Is there better algorithm than O(nlg(n)) ?
 * Is O(n) practical? 
 * Useful links :
 *
 * 1. http://stackoverflow.com/questions/4325200/find-the-majority-element-in-array
 * 2. http://www.geeksforgeeks.org/majority-element/ 
 * 3. https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 *
 */

/*
	Using Buckets

	Yo Yo
*/

int main(int argc, char const *argv[])
{
        int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
        int size = sizeof(a) / sizeof(a[0]);
	
	int c1, c2;
	int A,B;

	for(int i = 0; i < size ; i++)
	{
		if(c1 > 0 && A == a[i])
			c1++;
		else if(c2 > 0 && B == a[i])
			c2++;
		else if(c1 == 0)
		{
			c1 = 0;
			A = a[i];
		}
		else if(c2 == 0)
		{
			c2 = 0;
			B = a[i];
		}
		else
		{
			c1--;
			c2--;
		}
	}
	int count1 = 0, count2 = 0;
        for(int i = 0; i < size ; i++){
                if(a[i] == A){
                        count1++;
                }
        }

        if(count1 >= ((size/3) + 1))
                printf("Majority element can be  %d\n", A);

        for(int i = 0; i < size ; i++){
                if(a[i] == B){
                        count2++;
                }
        }

        if(count2 >= ((size/3) + 1))
                printf("Majority element can be  %d\n", B);
	
	 	
	return 0;
}
