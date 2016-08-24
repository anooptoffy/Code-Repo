#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Majority Number n/3 + 1
 *
 * O(nlogn) algorithm, using sorting technique. 
 * Since I am lazy i used qsort instead of Mergre sort or heap sort, which is supposed to be used instead.
 * 
 * Useful links :
 *
 * 1. http://stackoverflow.com/questions/4325200/find-the-majority-element-in-array
 * 2. http://www.geeksforgeeks.org/majority-element/ 
 * 3. 
 *
 */

 int comparator(const void *a, const void *b){
 	int f = *(int*)a;
 	int s = *(int*)b;
 	return f-s; //asc
 }
 
int main(int argc, char *argv[]){
	int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int size = sizeof(a) / sizeof(a[0]);
	qsort((void*)a, size, sizeof(a[0]), comparator);
	int count = 0, k = -1;
	int prev = a[0];
	for(int i = 1; i < size ; i++){
		if(a[i] == prev){
			count++;
		}
		else{
			prev = a[i];
			count = 0;
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