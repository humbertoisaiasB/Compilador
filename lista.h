#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdbool.h>
#include "tabla.h"

typedef struct Nodo{
	Tabla tabla;
	struct Nodo* siguiente;
}Nodo;

typedef struct Lista{
	Nodo* cabeza;
	int longitud;
}Lista;

Nodo* crearNodo(Tabla* tabla);

void destruirNodo(Nodo* nodo);

void insertarPrincipio(Lista* lista, Tabla* tabla);

void insertarPrincipio(Lista* lista, Tabla* tabla);

void insertarDespues(int n, Lista* lista, Tabla* tabla);

Tabla* obtener(int n, Lista* lista);

int contar(Lista* lista);

int estaVacia(Lista* lista);

void eliminarPrincipio(Lista* lista);

void eliminarUltimo(Lista* lista);

void eliminarElemento(int n, Lista* lista);
//Agregar nuevos metodos
//determina le entrara un arreglo de enteros por punteros
//
void determina(char *a, int numero);

void muestraLexema(char *a, int tamano);

int tamano(char a[]);

bool comparaStr (char entrada[],char modelo[]);

#endif 
