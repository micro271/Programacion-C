#include <stdio.h>
#include <stdlib.h>
typedef struct NODO {
	int numero;
	struct NODO *izq;
	struct NODO *der;
	struct NODO *padre;
}Nodo;

typedef struct Arbol{
	struct NODO *raiz;
	int length;
}Arbol;

Arbol *crearArbol(void);

Nodo *crearNodo(int numero,Nodo *padre);
static void __insertar__(Nodo **nodo,int numero,Nodo *padre);
void insertar(Arbol *arbol,int numero);
void destruirNodo(Nodo *nodo);
int existe(Nodo *nodo,int numero);
Nodo *obtener(Nodo *nodo,int numero);
void eliminar(Nodo *nodo,int numero);
static void __reemplazar__(Nodo *reemp,Nodo *nuevoNodo);
static void __eliminar__(Nodo *nodo);
static Nodo *__maximo__(Nodo *nodo);

int main(int argc,char **argv) {
	Arbol *arbol = crearArbol();
	insertar(arbol,10);
	insertar(arbol,3);
	insertar(arbol,15);
	insertar(arbol,7);
	eliminar(arbol->raiz,10);
	Nodo *aux = obtener(arbol->raiz,10);
	return 0;
}

Arbol *crearArbol(void) {
	Arbol *arbol = (Arbol * )malloc(sizeof(Arbol));
	arbol->raiz = NULL;
	arbol->length = 0;
	return arbol;
}

Nodo *crearNodo(int numero,Nodo *padre) {
	Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
	nuevoNodo->numero = numero;
	nuevoNodo->izq = nuevoNodo->der = NULL;
	nuevoNodo->padre = padre;
	return nuevoNodo;
}

static void __insertar__(Nodo **nodo,int numero,Nodo *padre) {
	if(*nodo == NULL) {
		*nodo = crearNodo(numero,padre);
	} else if(numero > (*nodo)->numero) {
		__insertar__(&((*nodo)->der),numero,*nodo);
	} else if(numero < (*nodo)->numero) {
		__insertar__(&((*nodo)->izq),numero,*nodo);
	}
}
void insertar(Arbol *arbol,int numero) {
	__insertar__(&(arbol->raiz),numero,NULL);
}
void destruirNodo(Nodo *nodo) {
	nodo->izq = nodo->der = nodo->padre = NULL;
	free(nodo);
}
int existe(Nodo *nodo,int numero) {
	if(nodo == NULL) {
		return 0;
	} else if(nodo->numero == numero) {
		return 1;
	} else if(nodo->numero > numero) {
		return existe(nodo->izq,numero);
	} else if(nodo->numero < numero) {
		return existe(nodo->der,numero);
	}
}

Nodo *obtener(Nodo *nodo,int numero) {
	if(nodo == NULL) {
		return NULL;
	} else if(nodo->numero > numero) {
		return obtener(nodo->izq,numero);
	} else if(nodo->numero < numero) {
		return obtener(nodo->der,numero);
	} else {
		return nodo;
	}
}
static Nodo *__maximo__(Nodo *nodo) {
	if(nodo->der == NULL) {
		return nodo;
	} else {
		return __maximo__(nodo->der);
	}
}
static void __reemplazar__(Nodo *reemp,Nodo *nuevoNodo) {
	if(reemp->padre) {
		if(reemp->padre->izq == reemp) {
			reemp->padre->izq = nuevoNodo;
		} else if(reemp->padre->der == reemp) {
			reemp->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo) {
		nuevoNodo->padre = reemp->padre;
	}
}
static void __eliminar__(Nodo *nodo) {
	if(nodo->izq && nodo->der) {
		Nodo *maximo = __maximo__(nodo->izq);
		nodo->numero = maximo->numero;
		__eliminar__(maximo);
	} else if(nodo->izq) {
		__reemplazar__(nodo,nodo->izq);
		destruirNodo(nodo);
	} else if(nodo->der) {
		__reemplazar__(nodo,nodo->der);
		destruirNodo(nodo);
	} else {
		__reemplazar__(nodo,NULL);
		destruirNodo(nodo);
	}
}
void eliminar(Nodo *nodo,int numero) {
	if(nodo->numero == numero) {
		__eliminar__(nodo);
	} else if(nodo->numero < numero) {
		eliminar(nodo->der,numero);
	} else if(nodo->numero < numero) {
		eliminar(nodo->izq,numero);
	}
}
