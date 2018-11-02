#include <stdio.h>		// printf 
#include "individuo.h"
#include "cruza.h"
	
int main() {
	u_char **poblacion = NULL;
	int tam = 8, bits = 10, r;
	
	setmry(&poblacion,tam,bits);

	// Generando individuos
	for(int i=0;i<tam;i++)
		indbinary(poblacion[i],bits);

	// Cruza de un punto
	printf("-- Cruza de un punto --\n\n");
	printf("%d\t", bintodec(poblacion[0],bits));
	printind(poblacion[0],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[1],bits));
	printind(poblacion[1],bits);
	printf("\n\n");

	r = cruzaup(poblacion[0],poblacion[1],bits);
	
	printf("\tCruza en: %d\n\n", r);
	printf("%d\t", bintodec(poblacion[0],bits));
	printind(poblacion[0],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[1],bits));
	printind(poblacion[1],bits);
	printf("\n\n");

	// Cruza de dos puntos
	printf("-- Cruza de dos puntos --\n\n");
	printf("%d\t", bintodec(poblacion[2],bits));
	printind(poblacion[2],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[3],bits));
	printind(poblacion[3],bits);
	printf("\n\n");

	cruzadp(poblacion[2],poblacion[3],bits);

	printf("%d\t", bintodec(poblacion[2],bits));
	printind(poblacion[2],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[3],bits));
	printind(poblacion[3],bits);
	printf("\n\n");	

	// Cruza uniforme
	printf("-- Cruza Uniforme --\n\n");
	printf("%d\t", bintodec(poblacion[4],bits));
	printind(poblacion[4],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[5],bits));
	printind(poblacion[5],bits);
	printf("\n\n");	
	
	cruzauf(poblacion[4],poblacion[5],bits);

	printf("%d\t", bintodec(poblacion[4],bits));
	printind(poblacion[4],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[5],bits));
	printind(poblacion[5],bits);
	printf("\n\n");

	// Cruza acentuada
	printf("-- Cruza Acentuada --\n\n");
	printf("%d\t", bintodec(poblacion[6],bits));
	printind(poblacion[6],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[7],bits));
	printind(poblacion[7],bits);
	printf("\n\n");	

	cruzaac(poblacion[6],poblacion[7],bits);

	printf("%d\t", bintodec(poblacion[6],bits));
	printind(poblacion[6],bits);
	printf("\n");
	printf("%d\t", bintodec(poblacion[7],bits));
	printind(poblacion[7],bits);
	printf("\n\n");	
	
	freemry(&poblacion,tam);
	return 0;
}

