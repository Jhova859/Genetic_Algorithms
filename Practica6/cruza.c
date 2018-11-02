#include <stdlib.h>		// malloc srand rand
#include <time.h>		// time
#include <string.h>		// memcpy
#include <stdio.h>
#include "cruza.h"

// Cruza con de un punto
int cruzaup(u_char *indA, u_char *indB, int bits){
	int index = randomint(bits);
	u_char *aux = NULL;
	aux = (u_char*)malloc(bits*sizeof(u_char));
	memcpy(aux,indA,bits);

	for(int i=index;i<bits;i++){
		indA[i] = indB[i];
		indB[i] = aux[i];
	}

	free(aux);	
	return index;
}

// Cruza de dos puntos
void cruzadp(u_char *indA, u_char *indB, int bits){
	int auxin;
	int index[2] = { randomint(bits), randomint(bits) };

	while(index[0]==index[1])
		index[1] = randomint(bits);

	if(index[0]>index[1]){
		auxin = index[0];
		index[0] = index[1];
		index[1] = auxin;
	}

	u_char **aux = NULL;	
	setma(&aux,bits);
	memcpy(aux[0],indA,bits);
	memcpy(aux[1],indB,bits);

	printf("\tCruza en: %d %d\n\n", index[0],index[1]);

	for(int i=index[0];i<index[1];i++){
		indA[i] = aux[1][i];
		indB[i] = aux[0][i];
	}

	freema(&aux);
}

// Cruza Uniforme
void cruzauf(u_char *indA, u_char *indB, int bits){
	int tam = bits/2, i, flag=0, value=0;
	int index[2][tam];

	u_char **aux = NULL;	
	setma(&aux,bits);
	memcpy(aux[0],indA,bits);
	memcpy(aux[1],indB,bits);

	for(int d=0;d<2;d++){
		i=0;
		do{
			flag = 1;
			value = randomint(bits);
			for(int j=0;j<=i;j++)
				if(index[d][j] == value){
					flag = 0;
					break;
				}
			if(flag == 1)
				index[d][i++] = value;
		}while(i<tam);
	}

	printf("\tCruza en: ");
	for(int k=0;k<tam;k++){
		printf("%d ", index[1][k]);
		indA[index[1][k]] = aux[1][index[1][k]];
	}
	printf("\n\tCruza en: ");
	for(int k=0;k<tam;k++){
		printf("%d ", index[0][k]);
		indB[index[0][k]] = aux[0][index[0][k]];
	}
	printf("\n\n");

	freema(&aux);
}

// Cruza Acentuada
void cruzaac(u_char *indA, u_char *indB, int bits){
	int sum=0, value=0, k=0, p=0;
	u_char *patron = NULL;
	u_char **aux = NULL;	

	setma(&aux,bits);
	patron = (u_char *)calloc(bits*2,sizeof(u_char));

	memcpy(aux[0],indA,bits);
	memcpy(aux[1],indB,bits);

	value = randomint(bits);
	sum += value;
	while(sum<(bits*2)){
		patron[sum] = 1;
		value = randomint(bits);
		sum+=value;
		p++;
	}

	printf("\tPatron A: ");
	for(int i=0;i<bits*2;i++){
		if(i==bits) printf("\n\tPatron B: ");
		printf("%d ", patron[i]);
	}
	printf("\n\n");

	for(int i=0;i<bits;i++){
		if(patron[i]==1 && k==0)	k=1;
		else if(patron[i]==1 && k==1) k=0;
		else k=k;
		indA[i] = aux[k][i];
	}
	k=1;
	for(int i=bits;i<bits*2;i++){
		if(patron[i]==1 && k==0)	k=1;
		else if(patron[i]==1 && k==1) k=0;
		else k=k;
		indB[i-bits] = aux[k][i-bits];
	}

	freema(&aux);
	free(patron);
}

int randomint(int tam){
	int r=0;
	srand(time(NULL)+rand());
	r = (rand() % (int)tam);
	return r;
}

void freema(u_char ***ptr){
	free((*ptr)[0]);
	free((*ptr)[1]);
	free(*ptr);
}

void setma(u_char ***ptr, int bits){
	*ptr = (u_char**)malloc(2*sizeof(u_char*));
	(*ptr)[0] = (u_char*)malloc(bits*sizeof(u_char));
	(*ptr)[1] = (u_char*)malloc(bits*sizeof(u_char));
}