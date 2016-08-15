#include <stdio.h>

int power(int x, int n){
	if(n == 0)
		return 1;
	else if(n % 2 == 0)
		return power(x*x,n/2);
	else
		return x*power(x*x,n/2);
}

int main(){
	int n=2;
	printf("%d",power(2,10));
	return 0;
}