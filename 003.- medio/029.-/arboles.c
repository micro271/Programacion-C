#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NODO {
	int numero;
	struct NODO *izq;
	struct NODO *der;
	struct NODO *padre;
}Nodo;

typedef struct ARBOL {
	struct NODO *raiz;
}Arbol;

Arbol *crearArbol(void);
Nodo *crearNodo(int numero,Nodo *padre);
void insertar(Arbol *arbol,int numero);
void preorden(Nodo *nodo);
void inorden(Nodo *nodo);
void postorden(Nodo *nodo);
Nodo *obtener(Nodo *nodo,int valor);
void eliminar(Nodo *nodo,int numero);
void destruirNodo(Nodo *nodo);

int main(int argc,char **argv) {
	Arbol *arbol = crearArbol();
	Nodo *aux;
	insertar(arbol,10);				inorden(arbol->raiz);printf("\n");
	insertar(arbol,11);				inorden(arbol->raiz);printf("\n");
	insertar(arbol,3);				inorden(arbol->raiz);printf("\n");
	insertar(arbol,7);				inorden(arbol->raiz);printf("\n");
	insertar(arbol,13);				inorden(arbol->raiz);printf("\n");
	insertar(arbol,3);				inorden(arbol->raiz);printf("\n");
	eliminar(arbol->raiz,10);		inorden(arbol->raiz);printf("\n");
	aux = obtener(arbol->raiz,10);
	return 0;
}

Arbol *crearArbol(void) {
	Arbol *arbol = (Arbol *)malloc(sizeof(Arbol));
	arbol->raiz = NULL;
	return arbol;
}
Nodo *crearNodo(int numero,Nodo *padre) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->numero = numero;
	nodo->izq = nodo->der = NULL;
	nodo->padre = padre;
	return nodo;
}
void destruirNodo(Nodo *nodo) {
	nodo->izq = nodo->der = NULL;
	free(nodo);
}
static void insertarNodo(Nodo **nodo,int numero,Nodo *padre) {
	if(*nodo == NULL) {
		*nodo = crearNodo(numero,padre);
	} else {
		if(numero > (*nodo)->numero) {
			insertarNodo(&(*nodo)->der,numero,*nodo);
		} else {
			insertarNodo(&(*nodo)->izq,numero,*nodo);
		}
	}
}
void insertar(Arbol *arbol,int numero) {
	insertarNodo(&arbol->raiz,numero,NULL);
}
void preorden(Nodo *nodo) {
	if(nodo != NULL) {
		printf("%i\n",nodo->numero);
		preorden(nodo->izq);
		preorden(nodo->der);
	}	
}
void inorden(Nodo *nodo) {
	if(nodo != NULL){
		printf("( ");
		inorden(nodo->izq);
		if(nodo->padre != NULL) {
			printf(" %i {%i} ",nodo->numero,nodo->padre->numero);
		} else {
			printf(" %i {//} ",nodo->numero);
		}
		inorden(nodo->der);
		printf(" )");
	} else {
		printf(" - ");
	}
}
void postorden(Nodo *nodo) {
	if(nodo != NULL) {
		postorden(nodo->izq);
		postorden(nodo->der);
		printf("%i\n",nodo->numero);
	}
}
Nodo *obtener(Nodo *nodo,int valor) {
	if(nodo == NULL) {
		return NULL;
	} else if(nodo->numero == valor) {
		return nodo;
	} else if(valor > nodo->numero) {
		return obtener(nodo->der,valor);
	} else {
		return obtener(nodo->der,valor);
	}
}
static void reemplazar(Nodo *nodo,Nodo *nuevoNodo) {
	if(nodo->padre) {
		if(nodo->numero == nodo->padre->izq->numero) {
			nodo->padre->izq = nuevoNodo;
		} else if(nodo->numero == nodo->padre->der->numero) {
			nodo->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo) {
		nuevoNodo->padre = nodo->padre;
	}
}

static Nodo *minimo(Nodo *nodo) {
	if(nodo == NULL) {
		return nodo;
	} else if(nodo->izq) {
		return minimo(nodo->izq);
	} else {
		return nodo;
	}
} 
static void eliminarNodo(Nodo *nodo) {
	if(nodo->izq && nodo->der) {
		Nodo *_minimo = minimo(nodo->der);
		nodo->numero = _minimo->numero;
		eliminarNodo(_minimo);
	} else if(nodo->izq) {
		reemplazar(nodo,nodo->izq);
		destruirNodo(nodo);
	} else if(nodo->der) {
		reemplazar(nodo,nodo->der);
		destruirNodo(nodo);
	} else {
		reemplazar(nodo,NULL);
		destruirNodo(nodo);
	}
}

void eliminar(Nodo *nodo,int numero) {
	if(nodo == NULL) {
		return;
	} else if(numero > nodo->numero) {
		eliminar(nodo->der,numero);
	} else if(numero < nodo->numero) {
		eliminar(nodo->izq,numero);
	} else {
		eliminarNodo(nodo);
	}
}
