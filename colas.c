#include <stdio.h>
#include <stdlib.h>

typedef struct PEDIDO{
	int id_producto;	
	float precio;
}Pedido;

typedef struct NODO {
	struct PEDIDO pedido;
	struct NODO *siguiente;
}Nodo;

typedef struct COLA {
	struct NODO *primero;
	struct NODO *ultimo;
	int length;
}Cola;

Cola *crearCola(void);
void destruirCola(Cola *cola);
Nodo *crearNodo(Pedido pedido);
void destruirNodo(Nodo *eliminar);
void encolar(Cola *cola,Pedido pedido);
Pedido *consultar(Cola *cola);
void eliminar(Cola *cola);

int main(int argc,char **argv) {
	Cola *cola = crearCola();
	Pedido pedido,*aux;
	pedido.id_producto = 9314;
	pedido.precio = 3245.50;
	encolar(cola,pedido);
	aux = consultar(cola);
	printf("Id: %i\n",aux->id_producto);
	printf("Precio: $%.2f",aux->precio);
	return 0;	
}

Cola *crearCola(void) {
	Cola *cola = (Cola *)malloc(sizeof(Cola));
	cola->primero = NULL;
	cola->ultimo = NULL;
	cola->length = 0;
	return cola;
}

void destruirCola(Cola *cola) {
	while(cola->primero != NULL) {
		eliminar(cola);
	}
	cola->ultimo = NULL;
	free(cola);
}

Nodo *crearNodo(Pedido pedido) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->pedido.id_producto = pedido.id_producto;
	nodo->pedido.precio = pedido.precio;
	nodo->siguiente = NULL;
	return nodo;
}

void destruirNodo(Nodo *eliminar) {
	free(eliminar);
}
void encolar(Cola *cola,Pedido pedido) {
	Nodo *nodo = crearNodo(pedido);
	if(cola->primero == NULL) {
		cola->primero = nodo;
		cola->ultimo = nodo;
	} else {
		cola->ultimo->siguiente = nodo;
		cola->ultimo = nodo;
	}
	cola->length++;
}
Pedido *consultar(Cola *cola) {
	if(cola->primero == NULL) {
		return NULL;
	} else {
		return &cola->primero->pedido;
	}
}
void eliminar(Cola *cola) {
	if(cola->primero != NULL) {
		Nodo *eliminar = cola->primero;
		cola->primero = eliminar->siguiente;
		destruirNodo(eliminar);
		if(cola->primero == NULL) {
			cola->ultimo = NULL;
		}
	}
}
