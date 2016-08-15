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
int N[1000000],l = 3; // l specify the number of digit in n of Fib(n), here lets take 3

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
	int i =  first;
	int j = last, temp = 0, t;
	while(i <= j)
	{
		t = N[i];
		if(((temp*10 + t) / 2) == 0){
			if( i ==  first)
				first++;	
			temp = t % 2;	
			N[i] = 0;
		} 
		else{
			N[i] = (temp*10 + t) / 2;
			temp = (temp*10 + t) % 2; 
						
		}
		i++;				
	}	
}

int power(int A[][2], int *N){ // the no of digits in N is 10^6 // replace int N by int N[]
	int  Y[2][2] = {{1,0},{0,1}};
	int  (*y)[2],(*x)[2];
	x = A;
	y = Y;
	while(N[first] > 0) // need to alter this N[first] > 0
	{
		if((N[last]%2) != 0) // N[last] % 2 != 0
			y= MM2(y,x);
		x = MM(x,x);
		//N = N / 2; // need to find this divideby2() ; complexity is 0(d) where d is no of digits here d = log N ie. 0(lg(N))
		divideby2(N);
	}
	return y[1][0];
}

int main(){
	
	FILE *fp;
	fp = fopen("data_decimal.in","r");
	for(int i = 0; i < l; i++)
	{
		fscanf(fp,"%1d",&N[i]);
	}
	first = 0;
	last = l - 1;

	int A[2][2] = {{1,1},{1,0}};
	int (*a)[2];
	a = A;

	// here we are finding the first 300 of fib(n)mod100 numbers
	//for(int i =0 ;i < 300; i++)
	//	printf(" %d",power(a,i));


	// make the call here
	N[0] = 2;
	N[1] = 9;
	N[2] = 8;
	printf(" %d",power(a,N));
	
/*	divideby2(N);
	printf("\n");
	for(int i = first; i <= last; i++)
	{
		printf("%d",N[i]);
	}

	divideby2(N);
	printf("\n");
	for(int i = first; i <= last; i++)
	{
		printf("%d",N[i]);
	}

	divideby2(N);
	printf("\n");
	for(int i = first; i <= last; i++)
	{
		printf("%d",N[i]);
	}
*/	
	printf("\n");
	fclose(fp);
	return 0;
}
