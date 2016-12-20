#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ANIME {
	char nombre[50];
	char genero[100];
	char tipo[10];
	char temporada[10];
	short int anio;
}Anime;

typedef struct NODO {
	struct ANIME anime;
	struct NODO *izq;
	struct NODO *der;
	struct NODO *padre;
}Nodo,Arbol;

static char *__strmin__(char *str);
static void __append__(Arbol **nodo,Anime anime,Arbol *padre);
void insert(Arbol **arbol,Anime anime);
Nodo *crearNodo(Anime anime,Nodo *padre);
void destruirNodo(Nodo *nodo);
int existe(Arbol *arbol,char *nombre);
static Nodo *__maximo__(Nodo *izq);
static void __reemplazar__(Nodo *nodo,Nodo *nuevo);
static void __remove__(Nodo *nodo);
void eliminar(Arbol *arbol,char *nombre);

int main(int argc,char **argv) {
	Arbol *arbol = NULL;
	Anime anime;
	strcpy(anime.nombre,"Kimi ni todoke");
	strcpy(anime.genero,"Escolaes,Romance");
	strcpy(anime.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.anio = 2009;
	insert(&arbol,anime);
	
	strcpy(anime.nombre,"Clannad");
	strcpy(anime.genero,"Drama,Romanc");
	strcpy(anime.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.anio = 2007;
	insert(&arbol,anime);
	
	strcpy(anime.nombre,"Clannad after story");
	strcpy(anime.genero,"Drama,Romanc,Fantasia");
	strcpy(anime.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.anio = 2008;
	insert(&arbol,anime);
	
}
Nodo *crearNodo(Anime anime,Nodo *padre) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->anime.nombre,anime.nombre,strlen(anime.nombre)+1);
	strncpy(nodo->anime.genero,anime.genero,strlen(anime.nombre)+1);
	strncpy(nodo->anime.temporada,anime.temporada,strlen(anime.temporada)+1);
	strncpy(nodo->anime.tipo,anime.tipo,strlen(anime.tipo));
	nodo->anime.anio = anime.anio;
	nodo->padre = padre;
	nodo->izq = nodo->der = NULL;
	return nodo;
}
void destruirNodo(Nodo *nodo) {
	nodo->padre = nodo->izq = nodo->der = NULL;
	free(nodo);
}
static char * __strmin__(char *str) {
	if(str != NULL) {
		char *tmp = (char *)malloc(sizeof(char)*(strlen(str)+1));
		int i=0;
		while(str[i] != '\0' && str[i] != '\n') {
			tmp[i] = tolower(str[i]);
			i++;
		}
		tmp[i] = '\0';
		return tmp;
	} else {
		return NULL;
	}
}
static void __append__(Arbol **nodo,Anime anime,Arbol *padre){
	int comp = 0;
	if(*nodo != NULL) {
		char *nombre_nodo = __strmin__((*nodo)->anime.nombre);
		char *nombre_anime = __strmin__(anime.nombre);
		comp = strcmp(nombre_anime,nombre_nodo);
		free(nombre_nodo);free(nombre_anime);
	}else if (*nodo == NULL) {
		*nodo = crearNodo(anime,padre);
	} 
	
	if (comp == 1) {
		__append__(&((*nodo)->der),anime,*nodo);
	} else if (comp == -1){
		__append__(&((*nodo)->izq),anime,*nodo);
	}
}
void insert(Arbol **arbol,Anime anime) {
	if(existe(*arbol,anime.nombre) == 0) { 
		__append__(arbol,anime,NULL);
	}
}

int existe(Arbol *arbol,char *nombre) {
	if(arbol && nombre) {
		char *nombre_arbol_aux = __strmin__(arbol->anime.nombre);
		char *nombre_anime_aux = __strmin__(nombre);
		int comp = strcmp(nombre_anime_aux,nombre_arbol_aux);
		free(nombre_anime_aux);free(nombre_arbol_aux);
		if(comp == 0) {
			return 1;
		} else if(comp == 1) {
			return existe(arbol->der,nombre);
		} else {
			return existe(arbol->izq,nombre);
		}
	} else{
		return 0;
	}
}
static void __reemplazar__(Nodo *nodo,Nodo *nuevo) {
	if(nodo->padre) {
		if(nodo->padre->izq == nodo) {
			nodo->padre->izq = nuevo;
		} else if(nodo->padre->der == nodo) {
			nodo->padre->izq = nuevo;
		}
	}
	if(nuevo) {
		nuevo->padre = nodo->padre;
	}
}
static Nodo *__maximo__(Nodo *izq) {
	if(izq->der) {
		__maximo__(izq->der);
	} else {
		return izq;
	}
}
static void __remove__(Nodo *nodo) {
	if(nodo->izq && nodo->der) {
		Nodo *maximo = __maximo__(nodo);
		strncpy(nodo->anime.nombre,maximo->anime.nombre,strlen(maximo->anime.nombre)+1);
		strncpy(nodo->anime.genero,maximo->anime.genero,strlen(maximo->anime.genero)+1);
		strncpy(nodo->anime.temporada,maximo->anime.temporada,strlen(maximo->anime.temporada)+1);
		strncpy(nodo->anime.tipo,maximo->anime.temporada,strlen(maximo->anime.tipo)+1);
		nodo->anime.anio = maximo->anime.anio;
		__remove__(maximo);
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
void eliminar(Arbol *arbol,char *nombre) {
	if(nombre && arbol) {
		char *aux_nombre_anime = __strmin__(nombre);
		char *aux_nombre_anime_arbol = __strmin__(arbol->anime.nombre);
		int comp = strcmp(aux_nombre_anime,aux_nombre_anime_arbol);
		free(aux_nombre_anime);free(aux_nombre_anime_arbol);
		if(comp == 0) {
			__remove__(arbol);
		} else if(comp == 1) {
			eliminar(arbol->der,nombre);
		} else {
			eliminar(arbol->izq,nombre);
		}
	}
	
}
