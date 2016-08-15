#include <stdio.h>
#include <stdlib.h>
/*
 * Verification can be done here : http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibmaths.html#fibmod
 * Tutorial : https://www.youtube.com/watch?annotation_id=annotation_146092965&feature=iv&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&src_vid=_j5lhHWkbnQ&v=sHcnvZA2u88 
 * Stackoverflow links:
 *  1. http://stackoverflow.com/questions/21181800/how-to-divide-a-very-large-number10100-when-number-is-stored-as-single-digit
 *  2.
 */

int first, last;
int N[1000000],l = 1000000; // l specify the number of digit in n of Fib(n), here lets take 10^6

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

void divideby2(int *N){ // integer array passed
	if(last > first)
		last--;	
}

int power(int A[][2], int *N){ // the no of digits in N is 10^6 // replace int N by int N[]
	int  Y[2][2] = {{1,0},{0,1}};
	int  (*y)[2],(*x)[2];
	x = A;
	y = Y;
	while(N[first] > 0) // need to alter this N[first] > 0
	{
		if(N[last] != 0) // N[last] % 2 != 0
			y= MM2(y,x);
		x = MM(x,x);
		//N = N / 2; // need to find this divideby2() ; complexity is 0(d) where d is no of digits here d = log N ie. 0(lg(N))
		divideby2(N);
	}
	return y[1][0];
}

int main(){
	
	FILE *fp;
	fp = fopen("data_binary.in","r");
	for(int i = 0; i < l; i++)
	{
		fscanf(fp,"%1d",&N[i]);
	}
	first = 0;
	last = l - 1;
	N[first] = 1; // because it should be 1
	//exit(0);

	int A[2][2] = {{1,1},{1,0}};
	int (*a)[2];
	a = A;

	printf(" %d",power(a,N));
	
	
	printf("\n");
	fclose(fp);
	return 0;
}
