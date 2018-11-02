#include <stdio.h>		// printf 
#include <stdlib.h>		// malloc calloc srand rand
#include <math.h>		// pow
#include <time.h>		// time
#include <string.h>		// memcpy
#include "individuo.h"

// Funciones Individuo/Poblacion

// Proporciona memoria necesaria a la matriz y la inicializa en 0 
void setmry(u_char ***poblacion, int tam, int bits){
	*poblacion = (u_char **)malloc(tam*sizeof(u_char*));
	for(int i=0;i<tam;i++)
		(*poblacion)[i] = (u_char *)calloc(bits,sizeof(u_char));
}

// Libera la memoria 
void freemry(u_char ***poblacion, int tam){
	for(int i=0;i<tam;i++)
		free((*poblacion)[i]);
	free(*poblacion);
}

// Imprime el individuo en bits
void printind(u_char *ind, int bits){
	printf("|");
	for(int i=0;i<bits;i++)
		printf("%d|", ind[i]);
}

/*  Obtiene un número aleatorio dependiendo los
	bits de rango que se quiera y lo convierte a binario */
int indbinary(u_char *ind, int bits){
	int num=0, j=0;
	double rango = pow(2,bits);
	srand(time(NULL)+rand());
	num = (rand() % (int)rango);

	u_char *aux = NULL;
	aux = (u_char*)calloc(bits,sizeof(u_char));

	dectobin(num,0,aux);
	for(int i=bits-1;i>=0;i--)
		ind[j++] = aux[i];

	free(aux);
	return num;
}

/* Funcion recursiva para convertir un número decimal 
	a binario */
void dectobin(int num, int p, u_char *ind){
	if(num==0) return;
	ind[p]=num%2;
    num=num/2;
    dectobin(num,p+1,ind);
}

int bintodec(u_char *ind, int bits){
	double dec=0;
	for(int i=0;i<bits;i++)
		if(ind[i]==1)
			dec+=pow(2,bits-i-1);
	return (int)dec;
}