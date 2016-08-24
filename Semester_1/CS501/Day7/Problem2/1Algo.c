#include <stdio.h>

/*
 * Given a0, a1, a2, ... an-1
 *
 * find if ai + aj = ak
 *
 * Time complexity : O(n^3)
 */

int main(int argc, char *argv[]){
	int a[] = {3, 2, 5, 6, 11, 13, 40, 66, 34, 12, 90, 100, 78, 44, 34, 22, 25};
	int size = sizeof(a)/sizeof(a[0]);
	int count = 0;
	for(int i = 0;  i <  size; i++)
		for(int j = 0; j < size; j++)
			for(int k = 0; k < size; k++)
				if(a[i] + a[j] == a[k])
				{
					printf("%d + %d = %d\n",a[i], a[j], a[k]);
					count++;		
					break;
				}
	printf("\nCount is %d\n",count);
	return 0;
}
