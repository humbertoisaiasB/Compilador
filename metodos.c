#include "lista.h"
#include <stdlib.h>
#include <string.h>

void muestraLexema(char *a, int tamano){
	int i;
	for(i=0; i<tamano; i++){
		printf("%c\n", a);
	}
}

int tamano(char a[]){
	int tamano = sizeof(a)/sizeof(int);
	return tamano;
}
