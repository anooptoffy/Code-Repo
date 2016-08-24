#include <stdio.h>
#include <stdlib.h>

/*
 *
 *  Maximum Gap Problem.
 *  http://cgm.cs.mcgill.ca/~godfried/teaching/dm-reading-assignments
 *  a0, a1, a2, a3, ... an-1
 *  Max i != j |ai - aj| 
 *  Time complexity : O(n^2)
 */


int main(int argc, char *argv[]){
	int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int size = sizeof(a)/sizeof(a[0]);
	int max = 0;
	for(int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
			if(abs(a[i] - a[j] > max))
				max = abs(a[i] - a[j]);
	printf("Max Gap is %d\n",max);
	return 0;
}
