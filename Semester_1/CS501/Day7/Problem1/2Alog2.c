#include <stdio.h>
#include <stdlib.h>

/*
 * Given a0, a1, a2, a3, ... ,an-1
 * 
 * Given x, There exits i,j such that ai + aj = x
 *
 */

int comparator(const void *l, const void *r){

	int f = *(const int *)l;
	int s = *(const int *)r;
	return f-s;
}

int main(int argc, char *argv[]){
	int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int size = sizeof(a)/sizeof(a[0]);
	int x = 45	;
	qsort((void *)a, size, sizeof(a[0]), comparator);
	//for(int i = 0; i < size; i++)
	//	printf("%d ", a[i]);
	int l = 0, r = size - 1, count = 0;
	//exit(0);
	while(l <= r)
	{
		if(a[l] + a[r] == x){
			printf("%d + %d = %d\n",a[l], a[r], x);
			count++;
			l++;
			r--;
			//break;
		}
		else if(a[l] + a[r] > x)
			r--;
		else
			l++;
	}
	printf("\n Count is %d\n",count);
	return 0;
}

/*
 * The complexity of the algorithm is O(nlg(n))
 * If Merge Sort is being used. For convinence I used Quick Sort.
 *
 */ 
