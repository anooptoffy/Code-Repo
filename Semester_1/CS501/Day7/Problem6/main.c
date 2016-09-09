#include <stdio.h>

/*
 *
 *
 * max(aj - ai)
 * i <= j <= i+l
 * using naive approach that has complexity O(n*l)
 *
 */

int main(int argc, char *argv[]){
	int a[] = {10, 11, 7, 10, 6};
 	int size = sizeof(a)/sizeof(a[0]);
	int l = 3;
	int max = -1;
	for(int i = 0; i < size - l; i++){
		for(int j = i; j < (i+l); j++){
			if(a[j] - a[i] > max)
 				max = a[j] -  a[i];
 			if(a[j] < a[i])
 				i = j-1;
 			printf("The value of i is %d, max is %d \n",i, max );
		}
		printf("When to buy, Day %d at price %d\n", i, a[i]);
	}

	return 0;
}
