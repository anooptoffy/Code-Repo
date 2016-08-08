#include <stdio.h>

int rec (int n){
		if (n<2) 
			return (n);
		else
			return((rec(n-1)+rec(n-2))%100);
}

void main(){
	int n;
	scanf("%d",&n);

	printf("%d",rec(n));
}
