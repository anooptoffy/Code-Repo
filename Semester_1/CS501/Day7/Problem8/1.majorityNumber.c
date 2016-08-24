#include <stdio.h>


/*
 *
 * Majority Number n/3 + 1
 *
 * O(n^2) algorithm
 * 
 * Useful links :
 *
 * 1. http://stackoverflow.com/questions/4325200/find-the-majority-element-in-array
 * 2. http://www.geeksforgeeks.org/majority-element/ 
 * 3. 
 *
 */
 
int main(int argc, char *argv[]){
	int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int size = sizeof(a) / sizeof(a[0]);
	int count = 0, k = -1;
	for(int i = 0; i < size ; i++){
		count = -1;
		for(int j = 0; j < size; j++){
			if(a[i] == a[j]){
				count++;
			}
		}
		if(count >= (size/3) + 1)
			k = i;
	}
	if(k != -1)
			printf("Majority element exits, it is %d\n", a[k]);
	else
			printf("Does not exists!!\n");
	return 0;
}