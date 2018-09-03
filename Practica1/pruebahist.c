#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main(int argc, char const *argv[]) {
	
	int array[] = {5,8,4,7,19,8,6,15,1,5,4};
	int tam = sizeof(array)/sizeof(int);
	
	hist(array,tam);

	GRAPHIC_HIST;

	return 0;
}