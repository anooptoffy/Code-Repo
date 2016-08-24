#include  <stdio.h>

/*
  * Stock selection problem
  * 
  * Max(aj - ai) where j > i+l
  *
  * ie. sell after an intervel l after buying or buy if we are fixing j(selling date)
  *  not before l days before j ie buy from interval i to j-l time
 */


 int main(int argc, char *argv[]){
 	int a[] = {10, 11, 7, 10, 6};
 	int size = sizeof(a)/sizeof(a[0]);

 	int i = 0, max = a[1] - a[0], l =2;
 	for(int j = i+l; j < size; j++){

 		if(a[j] - a[i] > max)
 			max = a[j] -  a[i];
 		if(a[j] < a[i])
 			i = j-1;
 	}
 	printf("When to buy, %d Day at price %d\n", i, a[i]);
 	return 0;
 }
