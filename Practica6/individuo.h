#ifndef _INDIVIDUO_H_
#define _INDIVIDUO_H_

// Definiciones
typedef unsigned char u_char;

// Funciones Prototipo
void setmry(u_char***,int,int);
void freemry(u_char***,int);
void printind(u_char*,int);
int indbinary(u_char*,int);
void dectobin(int,int,u_char*);
int bintodec(u_char*,int);

#endif //_INDIVIDUO_H_