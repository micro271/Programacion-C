#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MANGA {
	char nombre[50];
	char genero[100];
}Manga;

typedef struct NODO {
	struct MANGA manga;
	struct NODO *siguiente;
}Nodo;

typedef struct LISTA {
	struct NODO *cabeza;
	struct NODO *ultimo;
	short int longitud;
}Lista;

Lista *crearLista(void);
void destruirLista(Lista *lista);
Nodo *crearNodo(Manga manga);
void destruirNodo(Nodo *nodo);
void insertarUltimo(Lista *lista,Manga manga);
void insertarInicio(Lista *lista,Manga manga);
void insertar(int n,Lista *lista,Manga manga);
Manga *obtener(int n,Lista *lista);
int main(int argc,char **argv) {
	int i;
	Lista *lista = crearLista();
	Manga manga,*aux;
	strcpy(manga.nombre , "Maho Shojo Madoka Magika");
	strcpy(manga.genero , "Fantasia,Drama,Escolar");
	insertarUltimo(lista,manga);
	
	strcpy(manga.nombre , "Kimi ni todoke");
	strcpy(manga.genero , "Escolar,Romance");
	insertarUltimo(lista,manga);
	
	strcpy(manga.nombre , "Kimi ni todoke 2");
	strcpy(manga.genero , "Escolar,Romance");
	insertarInicio(lista,manga);
	
	strcpy(manga.nombre , "Nisekoi");
	strcpy(manga.genero , "Escolar,Romance");
	insertar(0,lista,manga);
	i = 0;
	while((aux = obtener(i,lista))) {
		printf("%i) Nombre: %s\n",i,aux->nombre);
		printf("%i) Genero: %s\n\n",i,aux->genero);
		i++;
	}
	return 0;
}

Lista *crearLista(void) {
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	lista->ultimo = lista->cabeza = NULL;
	lista->longitud = 0;
	return lista;
}
void destruirLista(Lista *lista) {
	Nodo *eliminar = NULL;
	while(lista->cabeza) {
		eliminar = lista->cabeza;
		lista->cabeza = eliminar->siguiente;
		eliminar->siguiente = NULL;
		destruirNodo(eliminar);
	}
	free(lista);
}
Nodo *crearNodo(Manga manga) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->manga.genero , manga.genero , strlen( manga.genero ) + 1);
	strncpy(nodo->manga.nombre , manga.nombre , strlen( manga.nombre ) + 1);
	nodo->siguiente = NULL;
	return nodo;
}

void destruirNodo(Nodo *nodo) {
	free(nodo);
}

void insertarUltimo(Lista *lista,Manga manga){
	Nodo *nodo = crearNodo(manga);
	if(lista->cabeza == NULL) {
		lista->cabeza = nodo;
		lista->ultimo = nodo;
		nodo->siguiente = lista->cabeza;
	} else if(lista->cabeza->siguiente == NULL){
		lista->cabeza->siguiente = nodo;
		lista->ultimo = nodo;
		nodo->siguiente = lista->cabeza;
	} else {
		lista->ultimo->siguiente = nodo;
		lista->ultimo = nodo;
		nodo->siguiente = lista->cabeza;
	}
	lista->longitud++;
}
void insertarInicio(Lista *lista,Manga manga) {
	Nodo *nodo = crearNodo(manga);
	if(lista->cabeza == NULL) {
		lista->cabeza = nodo;
		lista->ultimo = nodo;
		nodo->siguiente = lista->cabeza;
	} else if(lista->cabeza->siguiente == NULL) {
		lista->cabeza->siguiente = nodo;
		nodo->siguiente = lista->cabeza;
		lista->ultimo = lista->cabeza;
		lista->cabeza = nodo;
	} else {
		nodo->siguiente = lista->cabeza;
		lista->cabeza = nodo;
	}
	lista->longitud++;
}

void insertar(int n,Lista *lista,Manga manga) {
	Nodo *nodo = crearNodo(manga);
	if(n >= 0) {
		if(lista->cabeza == NULL) {
			lista->cabeza = nodo;
			nodo->siguiente = nodo;
			lista->ultimo = nodo;
		} else {
			if(n == 0) {
				if(lista->cabeza->siguiente == NULL) {
					nodo->siguiente = lista->cabeza;
					lista->cabeza->siguiente = nodo;
					lista->ultimo = lista->cabeza;
					lista->cabeza = nodo;
				} else {
					nodo->siguiente = lista->cabeza;
					lista->cabeza = nodo;
				}
			} else {
				int posicion = 0;
				Nodo *puntero = lista->cabeza;
				while(posicion < n-1 && puntero != lista->ultimo) {
					puntero = puntero->siguiente;
					posicion++;
				}
				if(puntero == lista->ultimo) {
					puntero->siguiente = nodo;
					nodo->siguiente = lista->cabeza;
					lista->ultimo = nodo;
				} else {
					nodo->siguiente = puntero->siguiente;
					puntero->siguiente = nodo;
				}
			}
		}
		lista->longitud++;
	}
}

Manga *obtener(int n,Lista *lista) {
	if(lista->cabeza) {
		if(n == 0) {
			return &lista->cabeza->manga;
		} else if(n < lista->longitud) {
			int posicion = 0;
			Nodo *puntero = lista->cabeza;
			while(posicion < n && puntero->siguiente) {
				puntero = puntero->siguiente;
				posicion++;
			}
			if(posicion == n) {
				return &puntero->manga;
			}
		}
	}
	return NULL;
}
