#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ANIME {
	char nombre[50];
	char genero[100];
	short int temporada;
	struct {
		char temporada[20];
		short int anio;
	}estreno;
};

struct NODO {
	struct ANIME anime;
	struct NODO *izq;
	struct NODO *der;
};

struct ARBOL{
	struct NODO *raiz;
	int length;
};

typedef struct ANIME Anime;
typedef struct NODO Nodo;
typedef struct ARBOL Arbol;
char *strmin(char *str);//AUXILIAR
Arbol *crearArbol(void);
void destruirArbol(Arbol *arbol);
Nodo *crearNodo(Anime anime);
void destruirNodo(Nodo *nodo);
void insertar(Arbol *arbol,Anime anime);

int main(int argc,char **argv) {
	Arbol *arbol = crearArbol();
	Anime anime;
	strcpy(anime.nombre,"Clannad");
	strcpy(anime.genero,"Drama,Romance");
	strcpy(anime.estreno.temporada,"Otonio");
	anime.estreno.anio = 2007;
	anime.temporada = 1;
	insertar(arbol,anime);
	
	strcpy(anime.nombre,"Clannad After story");
	strcpy(anime.genero,"Drama,Romance");
	strcpy(anime.estreno.temporada,"Otonio");
	anime.estreno.anio = 2008;
	anime.temporada = 2;
	insertar(arbol,anime);
	return 0;
}
Arbol *crearArbol(void) {
	Arbol *arbol = (Arbol *)malloc(sizeof(Arbol));
	arbol->raiz = NULL;
	arbol->length = 0;
	return arbol;
}

void destruirArbol(Arbol *arbol) {
	if(arbol->raiz) {
		//LOADING...
	}
}

Nodo *crearNodo(Anime anime) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->anime.nombre,anime.nombre,strlen(anime.nombre)+1);
	strncpy(nodo->anime.genero,anime.genero,strlen(anime.genero)+1);
	strncpy(nodo->anime.estreno.temporada,anime.estreno.temporada,strlen(anime.estreno.temporada)+1);
	nodo->anime.estreno.anio = anime.estreno.anio;
	nodo->anime.temporada = anime.temporada;
	nodo->der = nodo->izq = NULL;
	return nodo;
}

void destruirNodo(Nodo *nodo) {
	nodo->izq = nodo->der = NULL;
	free(nodo);
}
void insertar(Arbol *arbol,Anime anime) {
	Nodo *nodo = crearNodo(anime);
	if(!arbol->raiz) {
		arbol->raiz = nodo;
	} else {
		Nodo *puntero = arbol->raiz;
		int flag = 1;
		enum {
			INVIERNO,
			PRIMAVERA,
			VERANO,
			OTONIO
		};
		int aux_anime;
		int aux_nodo;
		char *temp_anime = NULL;
		char *temp_nodo = NULL;
		
		while(flag){
			if(puntero->anime.estreno.anio < anime.estreno.anio) {
				if(puntero->der) {
					puntero = puntero->der;
				} else {
					flag = 0;
					puntero->der = nodo;
				}
			} else if(puntero->anime.estreno.anio > anime.estreno.anio){
				if(puntero->izq) {
					puntero = puntero->izq;
				} else {
					puntero->izq = nodo;
					flag = 0;
				}
			} else {
				aux_anime = -1;
				aux_nodo = -1;
				temp_anime = strmin(anime.estreno.temporada);
				temp_nodo = strmin(puntero->anime.estreno.temporada);
				if(strcmp(temp_anime,"invierno") == 0) {
					aux_anime = INVIERNO;
				} else if(strcmp(temp_anime,"primavera") == 0) {
					aux_anime = PRIMAVERA;
				} else if(strcmp(temp_anime,"verano") == 0) {
					aux_anime = VERANO;
				} else {
					aux_anime = OTONIO;
				}
				if(strcmp(temp_nodo,"invierno") == 0) {
					aux_nodo = INVIERNO;
				} else if(strcmp(temp_nodo,"primavera") == 0) {
					aux_nodo = PRIMAVERA;
				} else if(strcmp(temp_nodo,"verano") == 0) {
					aux_nodo = VERANO;
				} else {
					aux_nodo = OTONIO;
				}
				
				free(temp_anime);free(temp_nodo);
				if(aux_anime == aux_nodo) {
					if(strcmp(anime.nombre,puntero->anime.nombre) == 1) {
						if(puntero->der) {
							puntero = puntero->der;
						} else {
							puntero->der = nodo;
							flag = 0;
						}
					} else {
						if(puntero->izq) { 
							puntero = puntero->izq;
						} else {
							puntero->izq = nodo;
							flag = 0;
						}
					}
				} else {
					if(aux_anime > aux_nodo) {
						if(puntero->der) {
							puntero = puntero->der;
						} else {
							puntero->der = nodo;
							flag = 0;
						}
					} else {
						if(puntero->izq) {
							puntero = puntero->izq;
						} else {
							puntero->izq = nodo;
							flag = 0;
						}
					}
				}
			}
		}
	}
}

char *strmin(char *str) {
	if(*str != '\0' && str != NULL) {
		char *aux = (char *)malloc(sizeof(char)*(strlen(str)+1));
		int i = 0;
		while(str[i] != '\0') {
			aux[i] = tolower(str[i]);
			i++;
		}
		aux[i] = '\0';
		return aux;
	} else {
		return NULL;
	}
}
