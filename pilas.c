#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ANIME {
	char nombre[50];
	char genero[100];
	short int temporada;
}Anime;

typedef struct NODO {
	struct ANIME anime;
	struct NODO *anterior;
}Nodo;

typedef struct PILA {
	struct NODO *cima;
	struct NODO *base;
	short int length;
}Pila;

Pila *crearPila(void);
void destruirPila(Pila *pila);
Nodo *crearNodo(Anime anime);
void destruirNodo(Nodo *nodo);
void apilar(Pila *pila,Anime anime);
Anime *desapilar(Pila *pila);

int main(int argc,char **argv) {
	Pila *pila = crearPila();
	Anime anime,*TMP;
	
	strcpy(anime.nombre , "Clannad");
	strcpy(anime.genero , "Romance,Deama,Fantasia");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Clannad After Story");
	strcpy(anime.genero , "Romance,Deama");
	anime.temporada = 2;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Suki tte ii na yo");
	strcpy(anime.genero , "Romance");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Air");
	strcpy(anime.genero , "Drama,recuerdos de la vida");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Kimi ni todoke");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Kimi ni todoke 2");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 2;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Hiyokoi");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Koe no katachi");
	strcpy(anime.genero , "Romance,Escolar,Drama");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Kimi no na wa");
	strcpy(anime.genero , "Romance,Fantasia");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Nisekoi");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Nisekoi 2");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 2;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Aoi hana");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Sasameki kono");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Danmachi");
	strcpy(anime.genero , "Fantasia,Aventura");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Asagao to kase-san");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Con el tiempo llegare tuya");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Everyday lily");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Gokujou Drops");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Hanjuku joshi");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Ouji-sama nante irana");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Chicha na mune no tokimeki");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 1;
	apilar(pila,anime);
	
	strcpy(anime.nombre , "Ano natsu no matteru");
	strcpy(anime.genero , "Romance,Escolar,Ciencia ficcion,Comedia");
	anime.temporada = 1;
	apilar(pila,anime);
	
	while((TMP = desapilar(pila))) {
		printf("%i) Nombre: %s\n",pila->length,TMP->nombre);
		printf("%i) Genero: %s\n",pila->length,TMP->genero);
		printf("%i) Temporada: %hi\n\n",pila->length,TMP->temporada);
		free(TMP);
	}
	
	
	return 0;
}

Pila *crearPila(void) {
	Pila *pila = (Pila *)malloc(sizeof(Pila));
	pila->cima = NULL;
	pila->base = NULL;
	pila->length = 0;
	return pila;
}

void destruirPila(Pila *pila) {
	if(pila->cima) {
		Nodo *eliminar = pila->cima;
		while(eliminar) {
			pila->cima = eliminar->anterior;
			eliminar->anterior = NULL;
			destruirNodo(eliminar);
			eliminar = pila->cima;
			if(!eliminar)
				pila->base = NULL;
		}
	}
	free(pila);
}
Nodo *crearNodo(Anime anime) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->anime.genero,anime.genero,strlen(anime.genero)+1);
	strncpy(nodo->anime.nombre,anime.nombre,strlen(anime.nombre)+1);
	nodo->anime.temporada = anime.temporada;
	nodo->anterior = NULL;
	return nodo;
}

void destruirNodo(Nodo *nodo) {
	free(nodo);
}

void apilar(Pila *pila,Anime anime) {
	Nodo *nodo = crearNodo(anime);
	if(!pila->cima) {
		pila->cima = nodo;
		nodo->anterior = NULL;
		pila->base = nodo;
	} else {
		nodo->anterior = pila->cima;
		pila->cima = nodo;
	}
	pila->length++;
}
Anime *desapilar(Pila *pila) {
	if(pila->cima) {
		Nodo *eliminar = pila->cima;
		Anime *anime = (Anime *)malloc(sizeof(Anime));
		strncpy(anime->nombre,eliminar->anime.nombre,strlen(eliminar->anime.nombre)+1);
		strncpy(anime->genero,eliminar->anime.genero,strlen(eliminar->anime.genero)+1);
		anime->temporada = eliminar->anime.temporada;
		if(!eliminar->anterior) {
			pila->cima = pila->base = NULL;
		} else {
			pila->cima = eliminar->anterior;
		}
		destruirNodo(eliminar);
		pila->length--;
		return anime;
	}
	return NULL;
}
