#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Nodo* crearNodo(Tabla* tabla){
	Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
	strncpy(nodo->tabla.id,tabla->id,50);
	strncpy(nodo->tabla.componenteLexico,tabla->componenteLexico,50);
	strncpy(nodo->tabla.valorAtributo,tabla->valorAtributo,50);
	strncpy(nodo->tabla.linea,tabla->linea,3);
	nodo->siguiente = NULL;
	return nodo;
}

void destruirNodo(Nodo* nodo){
	free(nodo);
}

void insertarPrincipio(Lista* lista, Tabla* tabla){
	Nodo* nodo = crearNodo(tabla);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
}

void insertarUltimo(Lista* lista, Tabla* tabla){
	Nodo* nodo = crearNodo(tabla);
	if(lista->cabeza == NULL){
		lista->cabeza = nodo;
	}else{
		Nodo* puntero = lista->cabeza;
		while(puntero->siguiente){
			puntero = puntero->siguiente;
		}
		puntero->siguiente = nodo;
	}
	lista->longitud++;
}

void insertarDespues(int n, Lista* lista, Tabla* tabla){
	Nodo* nodo = crearNodo(tabla);
	if(lista->cabeza == NULL){
		lista->cabeza == nodo;
	}else{
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while(posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		}
		nodo->siguiente = puntero->siguiente;
		puntero->siguiente = nodo;
	}
	lista->longitud++;
}


Tabla* obtener(int n, Lista* lista){
	if(lista->cabeza == NULL){
		return NULL;
	}else{
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while(posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		}
		if (posicion != n){
			return NULL;
		}else{
			return &puntero->tabla;
		}
	}
}


int contar(Lista* lista){
	return lista->longitud;
}

int estaVacia(Lista* lista){
	return lista->cabeza == NULL;
}

void eliminarPrincipio(Lista* lista){
	if(lista->cabeza){
		Nodo* eliminado = lista->cabeza;
		lista->cabeza = lista->cabeza->siguiente;
		destruirNodo(eliminado);
		lista->longitud--;
	}
}

void eliminarUltimo(Lista* lista){
	if(lista->cabeza){
		if (lista->cabeza->siguiente){
			Nodo* puntero = lista->cabeza;
			while(puntero->siguiente->siguiente){
				puntero = puntero->siguiente;
			}
			Nodo* eliminado = puntero->siguiente;
			puntero->siguiente = NULL;
			destruirNodo(eliminado);
			lista->longitud--;	
		}else{
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = NULL;
			destruirNodo(eliminado);
			lista->longitud--;
		}
		
	}
}

void eliminarElemento(int n, Lista* lista){
	if(lista->cabeza){
		if(n == 0){
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			destruirNodo(eliminado);
			lista->longitud--;
		}else if(n < lista->longitud){
			Nodo* puntero = lista->cabeza;
			int posicion = 0;
			while(posicion < (n - 1)){
				puntero = puntero->siguiente;
				posicion++;
			}
			Nodo* eliminado = puntero->siguiente;
			puntero->siguiente = eliminado->siguiente;
			destruirNodo(eliminado);
			lista->longitud--;
		}
	}
}
 

int main(int argc, char const *argv[])
{
	
	//Tabla* tabla1[4]; //Cada tabla sera una palabra y/o valor en el compilador por lo tanto  
	//Una lista sera un conjunto de tablas, dentro de una linea oh un lexema
	//Tabla tablaAux;
	
	//Lista* lista1[1]; //Conjunto de tablas.
	char hello[] = "int";
	char *hola = &hello;
	
	int t = tamano(hello);
	muestraLexema(hola, t);
	char hello1[] = "int";
	if(comparaStr(hola, hello1)==true){
		printf("Ahuevo\n");
	}
	
	
	/*
	int queso=0;
	printf("Hola, escribe el id de la primer posicion.");
	strncpy(tablaAux.id,hola,49);
	tablaAux.id[50] = '\0';
	printf("Hola, escribe el id de la primer posicion.");
	printf( "id1 de la tabla es :  %s.\n", tablaAux.id);
	insertarPrincipio(lista1[0],tabla1[0]);
	printf( "id2 de la tabla es :  %s.\n", tablaAux.id);
	insertarUltimo(lista1[0],tabla1[1]);
	printf( "id3 de la tabla es :  %s.\n", tablaAux.id);
	tablaAux = obtener(queso,lista1[0]);
	printf( "id4 de la tabla es :  %s.\n", tablaAux.id);
	//printf( "Escribe el apellido del amigo: " );
	//scanf( "%s", &amigo.apellido );
	*/
	//printf( "Escribe el número de teléfono del amigo: " );
	//scanf( "%s", &amigo.telefono );
	//printf( "id de la tabla es :  %s.\n", tablaAux.id);
	printf("Hola\n");
	return 0;
}
void muestraLexema(char *a, int tamano){
	int i;
	for(i=0; i<tamano; i++){
		printf("%s\n", a);
	}
}

int tamano(char a[]){
	int tamano = sizeof(a)/sizeof(int);
	return tamano;
}
bool comparaStr (char entrada[],char modelo[]){
int ind = 0;

while (entrada[ind]!='\0' && modelo[ind]!='\0' && entrada[ind] == modelo[ind]) ind++;

if (entrada[ind]!='\0' || modelo[ind]!='\0')
   return false;

return true;
}
