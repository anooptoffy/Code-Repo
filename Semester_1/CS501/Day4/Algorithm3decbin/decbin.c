#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

void decbin(int num[], int res[], int size){
	int left, right,temp = 0 ,i ,j ,rem ,k = 0;
	left = 0;
	right = size - 1;

	while(left <= right){
		
		temp = 0;
		for(i = left; i <= right; i++){
			
			if(temp > 0){
				temp = temp * 10 + num[i];
				rem = temp % 2;
				num[i] = temp / 2;	
				temp = 0;
			}
			else{
				rem = num[i] % 2;
				num[i] = num[i] / 2;
			}
			
			temp = temp * 10 + rem;
		}
		res[k] = rem;
		k++;

		if(num[left] == 0)
			left++;
	}

	for (j = 0; j < k; ++j)
	{
		printf("%d", res[j]);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {2, 2};
	int size = sizeof(a)/sizeof(a[0]);
	int res[100] = {0};

	decbin(a,res,size);
	printf("\n");
	return 0;
}