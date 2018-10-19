#ifndef _INDIVIDUO_H_
#define _INDIVIDUO_H_

int indBinary(char *ind,int tam);
void getBinary(int num, int p, char *c);
void getGrayCode(char *indB,char *indG, int tam);
char xor(char a, char b);
void codEntero(char *indB, int num, int bits);
int countBits(int num);
void codReal(char *indB, char *indG, double ind);
void printIndividuo(char *ind, int bits);
int binToDec(char *ind,int bits);
void valAptitud(int *valX, int *valXX);
float getSum(int *valXX);
float getMaxValue(float *proba);
float getMinValue(float *proba);
void getProbability(int *valXX,float *proba, int sum);
void getProbabilityAc(float *proba,float *probaAc);
float randomValue();
int randomValueIndex();
int getIndex(float *probaAc,float rand);
void cruza(char *indA, char *indB, char *indC, char *indD, int bits);
void mutar(char *indA, int bits);

#define TAM 16

static int bin[] = {1,2,4,8,16,32,64,128,256,512};

#endif //_INDIVIDUO_H_