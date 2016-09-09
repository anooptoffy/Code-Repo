#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>


/*
	
	Compile as 
	$gcc main.c -lm
	$./a.out <input_file> num
	
*/

int main(int argc, char const *argv[])
{	
	int p = atoi(argv[2]);
	FILE *fp;
	fp = fopen(argv[1],"r");
	int l = pow(10,p);
	int N[l];

	printf("%d\n", l);
	for (int i = 0; i < l; ++i)
	{
		fscanf(fp,"%d",&N[i]);		
	}

	
	return 0;
}