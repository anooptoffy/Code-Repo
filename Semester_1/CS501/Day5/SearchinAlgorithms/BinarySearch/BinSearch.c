#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
 * Binary Search - 0(lg(n))
 * 
 * Page number, 799 CLRS
 */

int binSearch(int *A,int sz,int item){

	int f = 0, l = sz - 1, mid;
	while(l > f)
	{
		mid = (f+l)/2;
		if(A[mid] == item)
			return mid;
		else if(item <=  A[mid])
			l = mid;
		else
			f = mid + 1; 
	}
	return -1;
}

int main(int argc, char *argv[]){
	int a[] = {1, 4, 5, 66, 88, 100, 130, 500};
	int size = sizeof(a) / sizeof(a[0]);
	int item = atoi(argv[1]);
	int flag = binSearch(a, size, item);
	if( flag == -1)
		printf("\n%d , not found\n", item);
	else
		printf("\n%d , found\n" , item);
	return 0;
}
