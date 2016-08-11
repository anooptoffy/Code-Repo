#include <stdio.h>
/*
	Linear time
	Constant Space
*/
int linear(int n){

	int a = 0, b = 1, c = n;
	for(int i = 2; i <= n; i++){
		c = (a+b) % 100;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d",linear(n));
	return 0;
}
