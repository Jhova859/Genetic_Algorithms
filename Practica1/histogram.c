#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

void hist(int *values, int tam){
	int i=0, j,k;
	FILE *fp;
	fp = fopen("/tmp/values.txt", "w");

	do{
		j = values[i];
		for(k=0;k<j;k++)
			fprintf(fp, "%d\n", i);
		
	}while(i++<tam);

	fclose(fp);
}


