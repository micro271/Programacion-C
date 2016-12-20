#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct PELICULA {
	char nombre[50];
	char genero[50];
	short int estreno;	
}Pelicula;

typedef struct NODO {
	Pelicula pelicula;
	struct NODO *siguiente;
}Nodo;

typedef struct NODO Lista;

Nodo *crearNodo(Pelicula pelicula);
void destruirNodo(Nodo *nodo);
void insertarPrincipio(Lista **lista,Pelicula pelicula);
void insertarFinal(Lista **lista,Pelicula pelicula);
void insertar(int inicio,int destino,Lista **lista,Pelicula pelicula);
void eliminarPrincipio(Lista **lista);
void eliminarFinal(Lista **lista);

int main(int argc,char **argv) {
	Lista *lista = NULL;
	Pelicula pelicula;
	strcpy(pelicula.nombre,"HARRY POTTER");
	strcpy(pelicula.genero,"Fantasia");
	pelicula.estreno = 2001;
	insertarPrincipio(&lista,pelicula);
	
	strcpy(pelicula.nombre,"HARRY POTTER 2");
	strcpy(pelicula.genero,"Fantasia");
	pelicula.estreno = 2004;
	insertarPrincipio(&lista,pelicula);
		
	strcpy(pelicula.nombre,"HARRY POTTER 3");
	strcpy(pelicula.genero,"Fantasia");
	pelicula.estreno = 2004;
	insertarFinal(&lista,pelicula);
	
	strcpy(pelicula.nombre,"HARRY POTTER 6");
	strcpy(pelicula.genero,"Fantasia");
	pelicula.estreno = 2007;
	insertar(0,1,&lista,pelicula);
	eliminarFinal(&lista);
	while(lista) {
		printf("%s\n",lista->pelicula.nombre);
		lista = lista->siguiente;
	}
	return 0;
}

Nodo *crearNodo(Pelicula pelicula) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->pelicula.nombre,pelicula.nombre,strlen(pelicula.nombre)+1);
	strncpy(nodo->pelicula.nombre,pelicula.nombre,strlen(pelicula.nombre)+1);
	nodo->pelicula.estreno = pelicula.estreno;
	nodo->siguiente = NULL;
	return nodo;
}
void insertarPrincipio(Lista **lista,Pelicula pelicula) {
	Nodo *nodo = crearNodo(pelicula);
	if(*lista == NULL) {
		*lista = nodo;
	} else {
		nodo->siguiente = *lista;
		*lista = nodo;
	}
}
void insertarFinal(Lista **lista,Pelicula pelicula) {
	if(*lista == NULL) {
		*lista = crearNodo(pelicula);
	} else {
		insertarFinal(&(*lista)->siguiente,pelicula);
	}
}
void insertar(int inicio,int destino,Lista **lista,Pelicula pelicula) {
	if(*lista == NULL) {
		*lista = crearNodo(pelicula);
	} else if(inicio >= 0 && inicio <= destino) {
		if(destino == 0) {
			Nodo *nodo =crearNodo (pelicula);
			nodo->siguiente = *lista;
			*lista = nodo;
		}else if(inicio == destino-1) {
			Nodo *nodo = crearNodo(pelicula);
			nodo->siguiente = (*lista)->siguiente;
			(*lista)->siguiente = nodo;
		} else {
			insertar(inicio+1,destino,&(*lista)->siguiente,pelicula);
		}
	}
}
void destruirNodo(Nodo *nodo) {
	free(nodo);
}

void eliminarPrincipio(Lista **lista) {
	if(*lista != NULL) {
		Nodo *eliminar = (*lista);
		(*lista) = eliminar->siguiente;
		destruirNodo(eliminar);
	}
}

void eliminarFinal(Lista **lista) {
	if((*lista)->siguiente->siguiente == NULL) {
		(*lista)->siguiente = NULL;
		destruirNodo((*lista)->siguiente);
	} else if((*lista)->siguiente == NULL){
		destruirNodo(*lista);
		*lista = NULL;
	} else {
		eliminarFinal(&(*lista)->siguiente);
	}
}
