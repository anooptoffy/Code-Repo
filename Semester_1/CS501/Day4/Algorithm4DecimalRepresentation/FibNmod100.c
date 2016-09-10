#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int first, last;
int N[1000000],l = 10; // l specify the number of digit in n of Fib(n), here lets take 10^6

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


int (*MM3(int A[][2], int B[][2]))[2]{  
	
	int r,s,t,u;
	static int D[2][2]; 
	// need to be static since it is to be available after the function terminates
	
	r = (A[0][0] * B[0][0] + A[0][1] * B[1][0])%100;
	s = (A[0][0] * B[0][1] + A[0][1] * B[1][1])%100;
	t = (A[1][0] * B[0][0] + A[1][1] * B[1][0])%100;
	u = (A[1][0] * B[0][1] + A[1][1] * B[1][1])%100;
	
	D[0][0] = r;
	D[0][1] = s;
	D[1][0] = t;
	D[1][1] = u;		
	
	return D;
}


int (*powerni(int A[][2], int N))[2]{ 
	int  Y[2][2] = {{1,0},{0,1}};
	int  (*y)[2],(*x)[2];
	x = A;
	y = Y;
	while(N > 0) 
	{
		if((N%2) != 0) 
			y= MM2(y,x);
		x = MM(x,x);
		N /= 2;
	}
	return y;
}

int power(int A[][2], int *N){ 
	int  Y[2][2] = {{1,0},{0,1}};
	int  (*y)[2],(*x)[2];
	x = A;
	y = Y;
	//printf("First %d\n", first );
	//printf("Last  %d\n", last);
	while(first <= last) 
	{
		//printf("Hai\n");
		if(N[last] != 0){ 
			x = powerni(x,N[last]);
			y= MM3(y,x);
		}
		x = powerni(x,10);
		last--;
	}
	return y[1][0];
}


/*
	Compile as 
	$gcc FibNmod100.c -lm
	$./a.out <input_file> num
*/

int main(int argc,char *argv[]){
	int p= atoi(argv[2]);
	FILE *fp;
	fp = fopen(argv[1],"r");
	l = pow(l,p);
	//l = 1;
	//printf("%d \n",l);
	for(int i = 0; i < l; i++)
	{
		fscanf(fp,"%1d",&N[i]);
	}

	first = 0;
	last = l - 1;

	int A[2][2] = {{1,1},{1,0}};
	int (*a)[2];
	a = A;

	printf(" %d",power(a,N));
	
	printf("\n");
	fclose(fp);
	return 0;
}
