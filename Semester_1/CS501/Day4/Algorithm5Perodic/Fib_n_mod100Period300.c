#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int tempp[300];
int l = 10;
int N[1000000];
// returns a pointer to integer array of size 2
int (*MM(int A[][2], int B[][2]))[2]{  
	
	int r,s,t,u;
	static int C[2][2]; 
	// need to be static since it is to be available after the function terminates
	
	r = (A[0][0] * B[0][0] + A[0][1] * B[1][0])%100;
	s = (A[0][0] * B[0][1] + A[0][1] * B[1][1])%100;
	t = (A[1][0] * B[0][0] + A[1][1] * B[1][0])%100;
	u = (A[1][0] * B[0][1] + A[1][1] * B[1][1])%100;
	
	C[0][0] = r;
	C[0][1] = s;
	C[1][0] = t;
	C[1][1] = u;		
	
	return C;
}

// returns a pointer to integer array of size 2
int (*MM2(int A[][2], int B[][2]))[2]{  
	
	int r,s,t,u;
	static int C[2][2]; 
	// need to be static since it is to be available after the function terminates
	
	r = (A[0][0] * B[0][0] + A[0][1] * B[1][0])%100;
	s = (A[0][0] * B[0][1] + A[0][1] * B[1][1])%100;
	t = (A[1][0] * B[0][0] + A[1][1] * B[1][0])%100;
	u = (A[1][0] * B[0][1] + A[1][1] * B[1][1])%100;
	
	C[0][0] = r;
	C[0][1] = s;
	C[1][0] = t;
	C[1][1] = u;		
	
	return C;
}

int power(int A[][2], int N){
	int  Y[2][2] = {{1,0},{0,1}};
	int  (*y)[2],(*x)[2];
	x = A;
	y = Y;
	while(N > 0)
	{
		if((N%2) != 0)
			y= MM2(y,x);
		x = MM(x,x);
		N = N / 2; 
	}
	return y[1][0];
}

int main(int argc, char *argv[]){
	int A[2][2] = {{1,1},{1,0}};
	int (*a)[2];
	a = A;
	// Stores the period of numbers m=100 p=300. 
	// Hence we stores first 300 fib numbers that repeats with period 300
	// Later change the logic for all m. not specific for 100. 
	// Break the loop when tempp[i-1] == 0 && tempp[i] == 1
	// return period p as i - 2
	for(int i =0 ;i < 300; i++){
		tempp[i] = power(a,i);
		printf(" %d",tempp[i]);
	}
	
	FILE *fp;
	fp = fopen(argv[1],"r");
	int p;
	p = atoi(argv[2]);
	l = pow(l,p); // 10^p number of digits in the number

	for(int i = 0; i < l; i++)
	{
		fscanf(fp,"%1d",&N[i]);
	}	
	
	// Adding logic for F(n%p) here tempp(N%p)

	printf("\n");
	return 0;
}
