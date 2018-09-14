#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Individuo.h"

void printMenu();
void printArray(char *ind, int bits);

int main(){
	
	char opc;
	int bits=0;
	int numInd=0;
	double real;
	char *ind,*indG;
	
	do{
		printMenu();
		scanf("%c",&opc);
		getchar();
		switch(opc){
			case '1':
				printf("\nRepresentacion Binaria\n");
				printf("Numero de bits, Numero de individuos \"8 5\" : \t");
				scanf("%d %d",&bits,&numInd);
				getchar();
				ind = (char *)malloc(bits*sizeof(char));
				printf("\nIndividuo\tBinario\n\n");
				for(int i=0;i<numInd;i++){
					memset(ind,0x00,bits);
					indBinary(ind,bits);
					printf("%d -> \t", i);
					printArray(ind,bits);
					printf("\n\n");
				}
				getchar();
				free(ind);
				break;
			case '2':
				printf("\nCodigo Gray\n");
				printf("Numero de bits, Numero de individuos \"8 5\" : \t");
				scanf("%d %d",&bits,&numInd);
				getchar();
				ind = (char *)malloc(bits*sizeof(char));
				indG = (char *)malloc(bits*sizeof(char));
				printf("\nIndividuo\tBinario\t\tCodigo Gray\n\n");
				for(int i=0;i<numInd;i++){
					memset(ind,0x00,bits);
					indBinary(ind,bits);
					getGrayCode(ind,indG,bits);
					printf("%d -> \t", i);
					printArray(ind,bits);
					printf("->\t");
					printArray(indG,bits);
					printf("\n\n");
				}
				getchar();
				free(ind);
				free(indG);
				break;
			case '3':
				printf("Codificacion de Numeros Reales\n");
				printf("Numero Real : \t");
				scanf("%lf",&real);
				getchar();
				int entero = real/1;
				int flotante = (real-entero)*10000;
				ind = (char *)malloc(8*sizeof(char));
				getBinary(entero,0,ind);
				indG = (char *)malloc(8*sizeof(char));
				getBinary(entero,0,indG);
				printArray(ind,bits);
				printf("->\t");
				printArray(indG,bits);
				printf("\n\n");
				getchar();
				free(ind);
				free(indG);
				break;
			case '4':
				printf("\nCodificacion en Numeros Enteros\n");
				printf("Numero a codificar : \t");
				scanf("%d",&numInd);
				getchar();
				bits = countBits(numInd);
				ind = (char *)malloc(bits*sizeof(char));
				codEntero(ind,numInd,bits);
				printf("\nEntero\tCodificado\n\n");
				printf("%d -> \t", numInd);
				printArray(ind,bits);
				printf("\n");
				getchar();
				break;
			case '5':
				printf("\t\tFinalizado\n");
				break;
			default:
				printf("\n\t\tOpcion incorrecta...\n");
				getchar();
				break;
		}
	}while(opc!='5');

	return 0;
}

void printMenu(){
	system("clear");
	printf("Representacion de individuos\n\n");
	printf("\t1 ) Representacion Binaria\n");
	printf("\t2 ) Codigo de Gray\n");
	printf("\t3 ) Codificación de Números Reales\n");
	printf("\t4 ) Codificación de Números Enteros\n");
	printf("\t5 ) Salir\n\n");
	printf("\tSeleccione una opcion:\t");
}

void printArray(char *ind,int bits){
	printf("|");
	for(int j=0;j<bits;j++)
		printf("%d|", ind[j]);
}