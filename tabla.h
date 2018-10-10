#ifndef tabla_h
#define tabla_h

#include <stdio.h>

typedef struct Tabla{
	char id[50];
	char componenteLexico[50];
	char valorAtributo[50]; //Por valor es el que se escribio
	char linea[3];
}Tabla;

#endif /* tabla_h */