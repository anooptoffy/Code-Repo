#include <stdio.h>

/*
 * Given a0, a1, a2, a3, ... ,an-1
 * 
 * Given x, There exits i,j such that ai + aj = x
 *
 */
int main(int argc, char *argv[]){
	int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int size = sizeof(a)/sizeof(a[0]);
	int x = 45, count = 0;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(a[i] + a[j] == x){
				printf("%d + %d = %d\n",a[i], a[j], x);
				count++;
				break;
			}
	printf("\n Count is %d\n",count);
	return 0;
}

/*
 * The complexity of the algorithm is O(n^2)
 *
 */ 
