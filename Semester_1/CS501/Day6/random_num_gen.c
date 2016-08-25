#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

int a[10000000];
int main(int argc, char *argv[]){
	long int i,n;	
	FILE *fp;
	fp = fopen("data.in","w");
	time_t t;
	n = pow(10,atoi(argv[1])); // 10^6
	srand((unsigned) time(&t));
	for(i = 0; i < n; i++){
		fprintf(fp,"%d ",rand() % 10000);
	}
	printf("\nCount %ld",i);	
	return 0;
}
