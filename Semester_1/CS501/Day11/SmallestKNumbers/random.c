#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	long int i,n;	
	FILE *fp;
	fp = fopen("data_decimal.in","w");
	time_t t;
	n = 1000000; // 10^6
	srand((unsigned) time(&t));
	for(i = 0; i < n; i++){
		fprintf(fp,"%d\n",rand() % 10000);
	}
	printf("\nCount %ld\n",i);	
	return 0;
}
