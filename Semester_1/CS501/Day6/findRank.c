#include <stdio.h>

/*
 * Find the rank of an element x in an array
 *
 * Complexity : O(n)
 */


int findRank(int *arr,int size, int num){
	int r,i = 0;	
	r = 1;
	while(i < size){
		if(arr[i] > num)
			r++;	
		i++;
	}
	return r;
}

int main(int argc, char *argv[]){
	int a[] = {10, 30, 60, 100, 1, 2, 7, 9, 80, 40, 55, 22, 99};// Sorting looks : 1, 2, 7, 9, 10, 22, 30, 40, 55, 60, 80, 99, 100
	int size = sizeof(a)/sizeof(a[0]);
	int num =  30;
	printf("The rank of %d is %d", num, findRank(a, size, num));
	printf("\n");
	
	return 0;
}
