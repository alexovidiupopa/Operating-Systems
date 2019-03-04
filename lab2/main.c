#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
	FILE *F = fopen(argv[1],"r");
	FILE *G = fopen(argv[2],"w");
	int n=10,m=10;
	fscanf(F,"%d",&n);
	fscanf(F,"%d",&m);
	int **matrix = (int **)malloc(sizeof(int*)*n);
	int i;
	for (i = 0;i<n;i++){
		int j;
		*(matrix+i) =(int*) malloc(sizeof(int*)*m);
		for (j=0;j<m;j++){
			fscanf(F,"%d",&matrix[i][j]);
		}
	}
	fclose(F);
        for (i = 0;i<n;i++){
                int j;
		for (j=0;j<m;j++){
			fprintf(G,"%d  ",matrix[i][j]);
		}
		fprintf(G,"%s","\n");
	}
	for (i=0;i<n;i++){
		free(*(matrix+i));
	}
	fclose(G);
	free(matrix);
	return 0;

}
