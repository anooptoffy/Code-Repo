#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;
long sizeConverted;

void decbin(int num[], int res[], int size){
	long left, right,temp = 0 ,i ,j ,rem ,k = 0;
	left = 0;
	right = size - 1;

	stack<int> mystack;

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
		//res[k] = rem;
		mystack.push(rem);
		k++;

		if(num[left] == 0)
			left++;
	}
	sizeConverted = k;
	for (j = 0; !mystack.empty(); ++j)
	{
		res[j] = mystack.top();
		mystack.pop();
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {2, 2};
	int size = sizeof(a)/sizeof(a[0]);
	int res[100] = {0};

	decbin(a,res,size);

	for (int j = 0; j < sizeConverted; ++j)
	{
		printf("%d",res[j] );
	}
	printf("\n");
	return 0;
}