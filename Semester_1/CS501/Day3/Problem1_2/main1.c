#include <stdio.h>


/*
	Dynamic Programming
	complexity:
		Space : Linear
		Time  : Linear
*/
int f[100000];
int dp(int n){
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		f[i] = (f[i-1] + f[i-2]) % 100;
	}
	return f[n];
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",dp(n));
	return 0;
}
