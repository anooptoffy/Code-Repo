#include <stdio.h>
#include <stdlib.h>

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

int main(){
	int A[2][2] = {{1,1},{1,0}};
	int (*a)[2];
	a = A;
	for(int i =0 ;i < 300; i++)
		printf(" %d",power(a,i));
	printf("\n");
	return 0;
}
