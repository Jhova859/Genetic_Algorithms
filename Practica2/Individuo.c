#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Individuo.h"

/* Función que obtiene un número aleatorio dependiendo los
	bits de rango que se quiera y lo almacena en un array */
int indBinary(char *ind,int bits){
	int num=0, p=0;
	double rango = pow(2,bits);
	srand(time(NULL)+rand());
	num = (rand() % (int)rango);
	getBinary(num,p,ind);
	return (int)num;
}

/* Funcion recursiva para convertir un número decimal 
	a binario */
void getBinary(int num, int p, char *c){
	if(num==0) return;
	c[p]=num%2;
    num=num/2;
    getBinary(num,p+1,c);
}

void getGrayCode(char *indB,char *indG, int bits){
	indG[0] = xor(0,indB[0]);
	for(int i=bits-1;i>0;i--)
		indG[i] = xor(indB[i-1],indB[i]);
}

// Función lógica
char xor(char a, char b){
	if(a==b) return 0;
	return 1;
}

void codEntero(char *indB, int num, int bits){
	int x = num; 
	for(int i=bits-1;i>=0;i--){
		indB[i] = x % 10;
		x /= 10;
	}
}

int countBits(int num){
	int x = num;
	int bits=0;
	while(x){
		x /= 10;
		bits+=1;
	}
	return bits;
}
