#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Individuo.h"
#include "graphic.h"

#define GEN 30

void barajear(int bar[]); 

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

		for(int i=0;i<TAM;i++) valX[i] = binToDec(poblacion[i],bits);

		memset(valXX,0,sizeof(valX));	
		memset(valXX,0,sizeof(valXX));
		memset(proba,0.0,sizeof(proba));
		memset(probaAc,0.0,sizeof(probaAc));
		memset(bar,0,sizeof(bar));

		valAptitud(valX, valXX);

		sum = getSum(valXX);

		getProbability(valXX,proba,sum);
		getProbabilityAc(proba,probaAc);

		maxR[g] = getMaxValue(proba);
		minR[g] = sum/TAM;

		/**************** Impresion de resultados ********************/
		printf("Individuos\tx\tfitness\tProbabilidad\tP. Acumulada\n");
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
		int t=0, w=0, l=0;
		for(int i=0;i<2;i++){
			barajear(bar);
			for(int j=0;j<TAM/2;j++){
				rand = randomValue();
				if(rand<0.7) w=0;
				else w=1;
				int index = bar[l+w];
				memcpy(aux[t++],poblacion[index],bits);
				l+=2;
			}
			l=0;
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

	graphicResults(minR,maxR,GEN);
	free(ind);
	return 0;
}

void barajear(int bar[]){
	/* Barajeo */
	int rI=0,tB=0, fg=0;
	for(int b=0;b<TAM;b++){
		rI = randomValueIndex(TAM);
		if(rI==0) rI=1;
		for(int c=0;c<tB+1;c++){
			if(rI==bar[c]){ fg=0; break; }
			else fg=1;
		}
		if(fg==1) { bar[tB]=rI; fg=0; tB++; }
		else if(b<TAM-1) b--;
	}
}
