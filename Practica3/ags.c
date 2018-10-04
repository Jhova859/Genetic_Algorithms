#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Individuo.h"
#include "graphic.h"

#define GEN 10

int main(){
	char *ind;
	int bits=8, index;
	float rand, sum;

	char *poblacion[TAM],*aux[TAM];
	int valX[TAM], valXX[TAM];
	float proba[TAM], probaAc[TAM];

	ind = (char *)malloc(bits*sizeof(char));
	float minR[GEN], maxR[GEN];

	/* Crear los individuos */
	for(int i=0;i<TAM;i++){
		poblacion[i] = (char *)malloc(1*sizeof(char *));
		memset(ind,0x00,bits);
		memset(poblacion[i],0x00,bits);
		indBinary(ind,bits);
		getGrayCode(ind,poblacion[i],bits);
		valX[i] = binToDec(poblacion[i],bits);
	}

	for(int g=0;g<GEN;g++){
		printf("\nGENERACION : %d\n\n", g);

		for(int i=0;i<TAM;i++) valX[i] = binToDec(poblacion[i],bits);

		memset(valXX,0,sizeof(valX));	
		memset(valXX,0,sizeof(valXX));
		memset(proba,0.0,sizeof(proba));
		memset(probaAc,0.0,sizeof(probaAc));

		valAptitud(valX, valXX);

		sum = getSum(valXX);

		getProbability(valXX,proba,sum);
		getProbabilityAc(proba,probaAc);

		maxR[g] = getMaxValue(proba);
		minR[g] = getMinValue(proba);

		/**************** Impresion de resultados ********************/
		printf("Individuos\t\tx\tx*x\tProbabilidad\tP. Acumulada\n");
		for(int j=0;j<TAM;j++){
			printIndividuo(poblacion[j],bits);
			printf("\t%d\t", valX[j]);
			printf("%d\t%.4f\t\t%.4f\n", valXX[j],proba[j],probaAc[j]);
		}

		printf("\nSuma : %.0f\n", sum);
		printf("Promedio : %.4f\n", sum/TAM);
		printf("Probabilidad Maxima : %.4f\n", maxR[g]);
		printf("Probabilidad Minima : %.4f\n\n", minR[g]);

		/*************************************************************/

		/* Seleccion de posibles candidatos */
		for(int i=0;i<TAM;i++){
			aux[i] = (char *)malloc(1*sizeof(char *));
			rand = randomValue();
			index = getIndex(probaAc,rand);
			memset(aux[i],0x00,bits);
			memcpy(aux[i],poblacion[index],bits);
			printf("Numero Aleatorio : %.4f\n", rand);	
			printf("Index : %d\n", index);
		}

		printf("\nSeleccionados\t\tx\n");
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

		printf("\nCruza\t\t\tx\n");
		for(int i=0;i<TAM;i++){
			valX[i] = binToDec(poblacion[i],bits);
			printIndividuo(poblacion[i],bits);
			printf("\t%d\n",valX[i]);
			free(aux[i]);
		}

		printf("\nMutacion\t\tx\n");
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

	graphicResults(minR,maxR,GEN);
	free(ind);

	return 0;
}