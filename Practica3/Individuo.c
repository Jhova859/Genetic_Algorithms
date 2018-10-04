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

void printIndividuo(char *ind,int bits){
	printf("|");
	for(int j=0;j<bits;j++)
		printf("%d|", ind[j]);
}

int binToDec(char *ind,int bits){
	int dec = 0;
	int j = 0;
	for(int i=bits-1;i>=0;i--){
		if(ind[i]==1) dec += bin[j];
		j+=1;
	}
	return dec;
}

void valAptitud(int *valX, int *valXX){
	for(int i=0;i<TAM;i++) valXX[i] = valX[i]*valX[i];
}

float getSum(int *valXX){
	float sum = 0;
	for(int i=0;i<TAM;i++) sum+=valXX[i];	
	return sum;
}

float getMaxValue(float *proba){
	float maxV=proba[0];
	for(int i=1;i<TAM;i++)
		if(proba[i]>maxV) maxV = proba[i];

	return maxV; 
}

float getMinValue(float *proba){
	float minV=proba[0];
	for(int i=1;i<TAM;i++)
		if(proba[i]<minV) minV = proba[i];

	return minV; 
}

void getProbability(int *valXX,float *proba, int sum){
	for(int i=0;i<TAM;i++) proba[i] = ((float)valXX[i])/sum;
}

void getProbabilityAc(float *proba,float *probaAc){
	probaAc[0] = proba[0];
	for(int i=1;i<TAM;i++) probaAc[i] += probaAc[i-1]+proba[i];
}

float randomValue(){
	srand(time(NULL)+rand());
	float p = (float)(rand()%101)/100;
	return p;
}

int randomValueIndex(int tam){
	int r=0;
	srand(time(NULL)+rand());
	r = (rand() % (int)TAM);
	return r;
}

int getIndex(float *probaAc,float rand){
	for(int i=0;i<TAM;i++)
		if(probaAc[i]>=rand)
			return i;
}

void cruza(char *indA, char *indB, char *indC, char *indD, int bits){
	int r=0;
	srand(time(NULL)+rand());
	r = (rand() % (int)bits);
	printf("Bit de cruza : %d\n", r);
	for(int i=r;i<bits;i++){
		indD[i] = indA[i];
		indC[i] = indB[i];
	}
}

void mutar(char *indA, int bits){
	int c = randomValueIndex(bits);
	if(indA[c] == 1) indA[c]=0;
	else indA[c]=1;
}