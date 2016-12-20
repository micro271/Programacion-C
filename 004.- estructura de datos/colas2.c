#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct PEDIDO {
	int id_producto;
	float precio;
};

struct NODO {
	struct PEDIDO pedido;
	struct NODO *siguiente;
};

struct COLA {
	struct NODO *primero;
	struct NODO *ultimo;
	int length;
};

typedef struct PEDIDO Pedido;
typedef struct NODO Nodo;
typedef struct COLA Cola;

Cola *crearCola(void);
void destruirCola(Cola *cola);
Nodo *crearNodo(Pedido pedido);
void destruirNodo(Nodo *nodo);
void encolar(Cola *cola,Pedido pedido);
Pedido *despachar(Cola *cola);
int main(int argc,char **argv) {
	Cola *cola = crearCola();
	int i;
	Pedido pedido,*aux;
	for(i = 0; i < 10; i++) {
		pedido.id_producto = 783 + rand() % ((9813 + 1) - 1);
		pedido.precio = (50 + rand() % ((25000 + 1) - 1)) + .75;
		encolar(cola,pedido);
	}
	i = 0;
	while((aux = despachar(cola))) {
		printf("%i) id_producto: %i\n",i+1,aux->id_producto);
		printf("%i) precio: %.2f\n\n",i+1,aux->precio);
		free(aux);
		i++;
	}
	return 0;
}

Cola *crearCola(void) {
	Cola *cola = (Cola *)malloc(sizeof(Cola));
	cola->length = 0;
	cola->ultimo = cola->primero = NULL;
	return cola;
}

Nodo *crearNodo(Pedido pedido) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->pedido.id_producto = pedido.id_producto;
	nodo->pedido.precio = pedido.precio;
	nodo->siguiente = NULL;
	return nodo;
}

void destruirCola(Cola *cola) {
	if(cola->primero) {
		Nodo *eliminar = cola->primero;
		while(eliminar) {
			cola->primero = eliminar->siguiente;
			destruirNodo(eliminar);
			eliminar = cola->primero;
			if(!eliminar) {
				cola->ultimo = NULL;
			}
		}
	}
	free(cola);
}

void destruirNodo(Nodo *nodo) {
	free(nodo);
}

void encolar(Cola *cola,Pedido pedido) {
	Nodo *nodo = crearNodo(pedido);
	if(!cola->primero) {
		cola->primero = nodo;
		cola->ultimo = nodo;
	} else {
		cola->ultimo->siguiente = nodo;
		cola->ultimo = nodo;
	}
}

Pedido *despachar(Cola *cola) {
	if(cola->primero) {
		Nodo *eliminar = cola->primero;
		Pedido *pedido = (Pedido *)malloc(sizeof(Pedido));
		pedido->id_producto = eliminar->pedido.id_producto;
		pedido->precio = eliminar->pedido.precio;
		cola->primero = eliminar->siguiente;
		destruirNodo(eliminar);
		return pedido;
	} else {
		return NULL;
	}
}
