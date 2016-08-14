#include <stdio.h>
/*
	0(lg(n)) time
*/
int power(int x,int n){
	int y =1;
	while(n > 0){
		if(n%2 != 0)
			y = y * x;
		x = x*x;
		n = n / 2;
	}
	return y;
}

int main(){
	int n;
	printf("%d",power(2,10));
	return 0;
}
