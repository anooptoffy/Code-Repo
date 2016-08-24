#include <stdio.h>
#include <stdlib.h>
/*
 * Given a0, a1, a2, ... an-1
 *
 * find if ai + aj = ak
 *
 * Time complexity : O(n^2) + O(nlg(n))
 */

int comparator(const void *l, const void *r){

	int f = *(const int *)l;
	int s = *(const int *)r;
	return f-s;
}

int main(int argc, char *argv[]){
	int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int size = sizeof(a)/sizeof(a[0]);
	int count = 0;
	qsort((void *)a, size, sizeof(a[0]), comparator);
	
		for(int j = 0; j < size; j++){
			int l = 0, r =  size - 1;	
			while(l <= r){
				if(a[l] + a[r] == a[j])
				{
					printf("%d + %d = %d\n",a[l], a[r], a[j]);
					count++;
					//break;
					l++;
					r--;
				}
				else if(a[l] + a[r] < a[j])
					l++;
				else
					r--;
			}
		}
	printf("\n Count is %d\n",count);
	return 0;
}
