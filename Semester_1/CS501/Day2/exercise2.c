#include <stdio.h>

void main(){
	int i,j,k,n,a[10000000];
	n=1000;
	for (i=0;i<n;++i)
		for (j=0;j<n;++j)
			for (k=0;k<n;++k)
				a[i*n*n+j*n+k]=2*i*j*k+1;
}
