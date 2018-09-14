#ifndef _INDIVIDUO_H_
#define _INDIVIDUO_H_

int indBinary(char *ind,int tam);
void getBinary(int num, int p, char *c);
void getGrayCode(char *indB,char *indG, int tam);
char xor(char a, char b);
void codEntero(char *indB, int num, int bits);
int countBits(int num);
void codReal(char *indB, char *indG, double ind);

#endif //_INDIVIDUO_H_