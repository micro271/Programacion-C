#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PELICULA {
	char nombre[50];
	char genero[100];
	short int lanzamiento;
};

struct NODO {
	struct PELICULA pelicula;
	struct NODO *siguiente;
	struct NODO *anterior;
};

struct LISTA {
	struct NODO *cabeza;
	short int longitud;
};

typedef struct PELICULA Pelicula;
typedef struct NODO Nodo;
typedef struct LISTA Lista;

Lista *crearLista(void);
void destruirLista(Lista *lista);
Nodo *crearNodo(Pelicula pelicula);
void destruirNodo(Nodo *eliminar);
void insertarInicio(Lista *lista,Pelicula pelicula);
void eliminarInicio(Lista *lista);
void insertarFinal(Lista *lista,Pelicula pelicula);
void eliminarFinal(Lista *lista);
void insertar(int n,Lista *lista,Pelicula pelicula);
void eliminar(int n,Lista *lista);
Pelicula *obtener(int n,Lista *lista);
int main(int argc,char **argv) {
	int i;
	Lista *lista = crearLista();
	Pelicula pelicula,*aux;
	strcpy(pelicula.nombre, "harry potter y las reliquias de la muerte parte 1");
	strcpy(pelicula.genero, "Aventura, Familiar, Fantastico");
	pelicula.lanzamiento = 2010;
	insertarFinal(lista,pelicula);
	
	strcpy(pelicula.nombre, "Godzila resurge");
	strcpy(pelicula.genero, "Accion, Ciencia Ficcion");
	pelicula.lanzamiento = 2016;
	insertarInicio(lista,pelicula);
	
	strcpy(pelicula.nombre, "Doctor Strange: Hechicero Supremo");
	strcpy(pelicula.genero, "Accion, Aventura, Fantástico");
	pelicula.lanzamiento = 2016;
	insertar(3,lista,pelicula);
	i = 0;
	while((aux = obtener(i,lista))) {
		printf("%i) Nombre: %s\n",i,aux->nombre);
		printf("%i) Genero: %s\n",i,aux->genero);
		printf("%i) Lanzamiento: %hi\n\n",i,aux->lanzamiento);
		i++;
	}
	return 0;
}

Lista *crearLista(void) {
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	lista->cabeza = NULL;
	lista->longitud = 0;
	return lista;
}
void destruirLista(Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminar = NULL;
		while(lista->cabeza) {
			eliminar = lista->cabeza;
			lista->cabeza = eliminar->siguiente;
			if(lista->cabeza) {
				lista->cabeza->anterior = NULL;
			}
			destruirNodo(eliminar);
		}
	}
	free(lista);
}
Nodo *crearNodo(Pelicula pelicula) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->pelicula.nombre , pelicula.nombre , strlen( pelicula.nombre ) + 1);
	strncpy(nodo->pelicula.genero , pelicula.genero , strlen( pelicula.genero ) + 1);
	nodo->pelicula.lanzamiento = pelicula.lanzamiento;
	nodo->siguiente = NULL;
	nodo->anterior = NULL;
	return nodo;
}
void destruirNodo(Nodo *eliminar) {
	free(eliminar);
}
void insertarInicio(Lista *lista,Pelicula pelicula) {
	Nodo *nodo = crearNodo(pelicula);
	if(!lista->cabeza) {
		lista->cabeza = nodo;
	} else {
		nodo->siguiente = lista->cabeza;
		lista->cabeza->anterior = nodo;
		lista->cabeza = nodo;
	}
	lista->longitud++;
}
void insertarFinal(Lista *lista,Pelicula pelicula) {
	Nodo *nodo = crearNodo(pelicula);
	if(!lista->cabeza) {
		lista->cabeza = nodo;
	} else {
		Nodo *puntero = lista->cabeza;
		while(puntero->siguiente) {
			puntero->siguiente;
		}
		puntero->siguiente = nodo;
		nodo->anterior = puntero;
	}
	lista->longitud++;
}
void insertar(int n,Lista *lista,Pelicula pelicula) {
	Nodo *nodo = crearNodo(pelicula);
	if(lista->cabeza) {
		if(n == 0) {
			lista->cabeza->anterior = nodo;
			nodo->siguiente = lista->cabeza;
			lista->cabeza = nodo;
		} else {
			int posicion = 0;
			Nodo *puntero = lista->cabeza;
			while(posicion < n-1 && puntero->siguiente) {
				puntero = puntero->siguiente;
				posicion++;
			}
			if(puntero->siguiente) {
				puntero->siguiente->anterior = nodo;
				nodo->siguiente = puntero->siguiente;
				nodo->anterior = puntero;
			} else {
				puntero->siguiente = nodo;
				nodo->anterior = puntero;
			}
		}
	} else {
		lista->cabeza = nodo;
	}
	lista->longitud++;
}
void eliminar(int n,Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminar = NULL;
		if(n == 0) {
			eliminar = lista->cabeza;
			lista->cabeza = eliminar->siguiente;
			lista->cabeza->anterior = eliminar->anterior;
			eliminar->siguiente = NULL;
			destruirNodo(eliminar);
		} else {
			int posicion = 0;
			Nodo *puntero = lista->cabeza;
			while(posicion < n && puntero->siguiente) {
				puntero = puntero->siguiente;
				posicion++;
			}
			if(posicion == n) {
				eliminar = puntero;
				if(eliminar->siguiente) {
					eliminar->siguiente->anterior = eliminar->anterior;
					eliminar->anterior->siguiente = eliminar->siguiente;
				} else {
					eliminar->anterior->siguiente = NULL;
					eliminar->siguiente = NULL;
				}
				destruirNodo(eliminar);
			}
		}
		lista->longitud--;
	}
}
void eliminarFinal(Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminar = NULL;
		if(!lista->cabeza->siguiente) {
			eliminar = lista->cabeza;
			lista->cabeza = NULL;
		} else {
			Nodo *eliminar = lista->cabeza;
			while(eliminar->siguiente) {
				eliminar = eliminar->siguiente;
			}
			eliminar->anterior->siguiente = NULL;
			eliminar->anterior = NULL;
		}
		destruirNodo(eliminar);
	}
}

void eliminarInicio(Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminar = lista->cabeza;
		if(!lista->cabeza->siguiente) {
			lista->cabeza = NULL;
		} else {
			lista->cabeza = eliminar->siguiente;
			lista->cabeza->anterior = NULL;
			eliminar->siguiente = NULL;
		}
		destruirNodo(eliminar);
	}
}
Pelicula *obtener(int n,Lista *lista) {
	if(!lista->cabeza) {
		return NULL;
	} else if(n < lista->longitud){
		int posicion = 0;
		Nodo *devolver = lista->cabeza;
		while(posicion < n && devolver->siguiente) {
			devolver = devolver->siguiente;
			posicion++;
		}
		if(posicion == n) {
			return &devolver->pelicula;
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}
