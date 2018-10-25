#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Individuo.h"

#define GEN 100

void Merge(int *A,int *L,int leftCount,int *R,int rightCount); 
void MergeSort(int *A,int n);
float valEsp(int jera, int n);

int main(){
	char *ind;
	int bits=4, index;
	float rand, sum;
	
	int bar[TAM];
	char *poblacion[TAM],*aux[TAM];
	int valX[TAM], valXX[TAM];
	float proba[TAM], probaAc[TAM];

	ind = (char *)malloc(bits*sizeof(char));

	float minR[GEN], maxR[GEN];

	/* Crear los individuos */
	for(int i=0;i<TAM;i++){
		poblacion[i] = (char *)malloc(1*sizeof(char *));
		aux[i] = (char *)malloc(1*sizeof(char *));
		memset(aux[i],0x00,bits);
		memset(ind,0x00,bits);
		memset(poblacion[i],0x00,bits);
		indBinary(ind,bits);
		getGrayCode(ind,poblacion[i],bits);
		valX[i] = binToDec(poblacion[i],bits);
	}

	for(int g=0;g<GEN;g++){
		printf("\nGENERACION : %d\n\n", g);

		memset(probaAc,0.0,sizeof(probaAc));

		valAptitud(valX, valXX);

		sum = getSum(valXX);

		//getProbability(valXX,proba,sum);
		//getProbabilityAc(proba,probaAc);

		maxR[g] = getMaxValue(proba);
		minR[g] = sum/TAM;

		/**************** Impresion de resultados ********************/
		printf("Individuos\tx\tF. finesses\n");
		memset(ind,0x00,bits);

		for(int j=0;j<TAM;j++){
			printIndividuo(poblacion[j],bits);
			printf("\t%d", valX[j]);
			printf("\t%d\n", valXX[j]);
			memset(poblacion[j],0x00,bits);
		}

		MergeSort(valX,TAM);

		printf("\nJerarquia\tIndividuo\tx\tValEsp\tP. Acumulada\n");
		for(int j=0;j<TAM;j++){
			printf("%d\t\t", j+1);

			memset(ind,0x00,bits);
			decToBin(valX[j],ind,bits);
			memcpy(poblacion[j],ind,bits);
			printIndividuo(poblacion[j],bits);
			printf("\t%d", valX[j]);

			proba[j] = valEsp(j+1,TAM);
			printf("\t%.4f", proba[j]);
			
			if(j!=0) probaAc[j] += proba[j]+probaAc[j-1];
			else probaAc[j] = proba[j];

			printf("\t%.4f\n", probaAc[j]);
		}
		/*
		printf("\nSuma : %.0f\n", sum);
		printf("Promedio : %.4f\n", sum/TAM);
		printf("Probabilidad Maxima : %.4f\n", maxR[g]);
		printf("Probabilidad Minima : %.4f\n\n", minR[g]);


		/*************************************************************/
		/* Seleccion de posibles candidatos */
		printf("\n");
		for(int i=0;i<TAM;i++){
			rand = randomValueFloat(probaAc[TAM-1]);
			index = getIndex(probaAc,rand);
			memcpy(aux[i],poblacion[index],bits);
			printf("Numero Aleatorio : %.4f\n", rand);	
			printf("Index : %d\n", index);
		}

		printf("\nSeleccionados\tx\n");
		for(int i=0;i<TAM;i++){
			memcpy(poblacion[i],aux[i],bits);
			valX[i] = binToDec(poblacion[i],bits);
			printIndividuo(poblacion[i],bits);
			printf("\t%d\n",valX[i]);
		}

		/* Realizando una cruza en pares bit aleatorio */
		
		printf("\nCruzas Realizadas\n");
		int k=0;
		for(int i=0;i<(TAM/2);i++){
			cruza(aux[k],aux[k+1],poblacion[k],poblacion[k+1],bits);
			k+=2;
		}

		printf("\nCruza\t\tx\n");
		for(int i=0;i<TAM;i++){
			valX[i] = binToDec(poblacion[i],bits);
			printIndividuo(poblacion[i],bits);
			printf("\t%d\n",valX[i]);
		}

		printf("\nMutacion\tx\n");
		int r=0;
		int rep = (TAM*10)/100;
		if(rep == 0) rep=1;
		for(int i=0;i<rep;i++){
			r = randomValueIndex();
			mutar(poblacion[r],bits);
		}
		for(int i=0;i<TAM;i++){
			valX[i] = binToDec(poblacion[i],bits);
			printIndividuo(poblacion[i],bits);
			printf("\t%d\n",valX[i]);
		}
	}

	//graphicResults(minR,maxR,GEN);
	free(ind);
	return 0;
}

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	i = 0; j = 0; k =0;
	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}
 
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;  

	mid = n/2;   

	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid);
	MergeSort(R,n-mid); 
	Merge(A,L,mid,R,n-mid); 
    free(L);
    free(R);
}

float valEsp(int jera, int n){
	float r=0;
	r = 0.9 + 0.2*((double)(jera-1)/(n-1));
	return r;
}
