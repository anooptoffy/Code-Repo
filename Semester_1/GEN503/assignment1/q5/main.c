#include <stdio.h>

/*
  Three dice rolled
	A : divisible by 3
	B : divisible by 5
*/

int main(int argc, char *argv[]){
	int c3, c5,c35;
	c3 = 0;
	c5 = 0;
	c35 = 0;
	for(int i = 1; i <= 6; i++)
		for(int j = 1; j <= 6; j++)
			for(int k = 1; k <= 6; k++)
			{
				if((i+j+k) % 3 == 0)
					c3++;
				if((i+j+k) % 5 == 0)
					c5++;
				if(((i+j+k) % 3 == 0) && ((i+j+k) % 5 == 0))
					c35++;
			}	
	
	printf("\nThe count of pairs divisible by 3 are : %d", c3);
	printf("\nThe count of pairs divisible by 5 are : %d", c5);
	printf("\nBoth %d",c35);
	printf("\n");
	return 0;
}

