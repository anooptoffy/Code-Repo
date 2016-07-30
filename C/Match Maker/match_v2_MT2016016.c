#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char ch;
	int count = 0;
	FILE *fp,*fpTarget, *fpOut;
	char vocab[100][100];

	//Opening the file for reading, corpus.txt
	fp = fopen("corpus.txt","r");
	fpTarget = fopen("targets.txt", "r");
	fpOut = fopen("matches.txt", "w");
	//fclose(fp);
	

	//Reading the vocabulary words fromt the file
	int i = 0, j = 0;
	while((ch = fgetc(fp)) != '\n'){
		//printf("%c",ch);
		if(ch == ',')
		{	
			vocab[i][j] = '\0';
			i++;
			j = 0;
		}
		else
		{
			vocab[i][j] = ch;
			j++;
		}
	}
	count = ++i;

	//printf("The Vocab Words are : \n");
	for(int i = 0;i < count; i++)
	{
		//printf("%s \n", vocab[i]);
	}
	//printf("\n");
	// Reading targets.txt
	ch = fgetc(fpTarget);
	char line[100][100];
	int t = 0, r = 0;
	while(ch != EOF)	
	{	
		t = 0;
		while(ch != '\n')
		{
			line[r][t] = ch;
			t++;
			ch = fgetc(fpTarget);
		}
		line[r][t] = '\0';
		//printf("%s \n",line[r]);
		r++;
		ch = fgetc(fpTarget);

		// Finding out the Match Scores
	}
	
	//printf("The Target Words are : \n");
	for(int i = 0; i < r ; i++){
		//printf("%s\n",line[i]);	
	}
	// r contains the number of TARGET LINES are available.
	//printf("\n");
	// Reading the rest of the lines from the corpus file
	char cor[100][100];
	int f = 0, g = 0;
	ch = fgetc(fp);
	while(ch != EOF)
	{
		f = 0;
		while(ch != '\n')
		{
			cor[g][f] = ch;
			f++;
			ch = fgetc(fp);
		}
		cor[g][f] = '\0';
		//printf("%s \n", cor[g]);
		g++;
		ch = fgetc(fp);
		
	}

	//printf("The Corpus Words are : \n");
	for(int i = 0; i < g ; i++){
		//printf("%s\n",cor[i]);	
	}
	//printf("\n");


	//printf("Processing : \n");
	char t_tokens[100][100], c_tokens[100][100], *ptr, dummy[100];
	double res[100][100];
	int un[100][100],in[100][100];
	int k,h,q;
	int n,m,l,rr,x,z;
	char *pt;
	double re;

	for(int j = 0; j < g; j++){
			strcpy(dummy,cor[j]);
			ptr = strtok(dummy, ",");
			h = 0;
			while(ptr != NULL)
			{
				for(int y = 0 ; y < count; y++)
				{
					if(strcmp(ptr,vocab[y]) == 0)
					{
						strcpy(c_tokens[h],ptr);
						h++;							
					}
				}				
				ptr = strtok(NULL,",");
			}
		
			for(int e = 0; e < h; e++){
				//printf("%s ", c_tokens[e]);
			}
			//printf("\n");

			

			l = h; // count of corpus words that are in vocab for index j
			for(int w = 0; w < r; w++){
				
				strcpy(dummy,line[w]);
				pt = strtok(dummy, ",");
				q = 0;
				while(pt != NULL){
					//printf("%s ", pt);
					strcpy(t_tokens[q],pt);
					q++;
					pt = strtok(NULL, ",");				
				}
				
				for(int e = 0; e < q; e++){
				//printf("%s ", t_tokens[e]);
				}

				// perform intersection then union and then calculate match score and then store it in res[w][j]
				rr = 0;
				//printf("q = %d, h = %d\n", q,h);
				for(z = 0; z < q; z++){
					for(x = 0 ; x < h; x++){
						//printf("%s %s",t_tokens[z],c_tokens[x]);
						if(strcmp(t_tokens[z],c_tokens[x]) == 0){
							//printf("Hello ");
							rr++;				
						}	
					}
				}
				// union
				n = h + q - rr;				
				re = (double) rr / (double) n;
				//printf("%d %d %f",rr,n, re);
				res[w][j] = re;
				un[w][j] = n;
				in[w][j] = rr;
				//printf("\n");
	
			}

			//printf("\n");
	}

	double value;
	int index;
	for(int w = 0 ; w < r; w++){ // target
		value = 0;
		for(int j = 0; j < g; j ++){ // print corpus values for so lines
			//printf("%.2f ", res[w][j]);
			if(res[w][j] > value){
				value = 	res[w][j];
				index = j;
			}
		}
		printf("%s;%d/%d=%.2f;%s",line[w],in[w][index],un[w][index],res[w][index],cor[index]);
		printf("\n");
	}


	// r contains count of target words, it has only vocab words.
	// g contains count of the corpus words, it has both vocab words and non.

	

	fclose(fpTarget);
	fclose(fpOut);
	fclose(fp);
	return 0;
}
