#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ANIME {				//ESTRUCTURA ANIME
	char nombre[40];		//NOMBRE DEL ANIME
	char genero[100];		//GENERO DEL ANIME
	short int temporada;	//CANTIDAD DE TEMPORADAS
};

struct NODO{				//ESTRUCTURA NODO PRINCIPAL
	struct ANIME anime;		//GUARDAMOS UN ANIME
	struct NODO *siguiente;	//APUNTAMOS A UN SIGUIENTE NODO
};

struct LISTA {				//ESTRUCTURA LISTA
	struct NODO *cabeza;	//APUNTAMOS AL PRIMER ELEMENTO DE LA LISTA
	struct NODO *ultimo;	//APUNTAMOS AL ULTIMO ELEMENTOS DE LA LISTA
};

typedef struct ANIME Anime;		//ALIAS DE LA ESTRUCTURA ANIME
typedef struct NODO Nodo;		//ALIAS DE LA ESTRUCTURA NODO
typedef struct LISTA Lista;		//ALIAS DE LA ESTRUCTURA LISTA
//CREAMOS LA LISTA
Lista *crearLista(void);
//DESTRUIMOS UNA LISTA
void *destruirLista(Lista *lista);
//CREAMOS UN NUEVO NODO
Nodo *crearNodo(Anime anime);
//DESTRUIR UN NODO
void destruirNodo(Nodo *nodo);
//AGREGAR AL INICIO
void agregarInicio(Lista *lista,Anime anime);
//ELIMINAMOS EL INICIO
void eliminarInicio(Lista *lista);
//AGREGAMOS AL FINCL
void agregarFinal(Lista *lista,Anime anime);
//ELIMINAMOS EL ULTIMO ELEMENTO
void eliminarFinal(Lista *lista);
//AGREGAMOS EN UNA DETERMINADA POSICION
void insertar(int n,Lista *lista,Anime anime);
//ELIMINAR EL ELEMENTO N
void eliminar(int n,Lista *lista);
//OBTENEMOS UN ANIME
Anime *obtener(int n,Lista *lista);
int main(int argc,char **argv) {
	int i;
	Lista *lista = crearLista();
	Anime anime,*aux;
	
	
	strcpy(anime.nombre , "Clannad");
	strcpy(anime.genero , "Romance,Deama,Fantasia");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Clannad After Story");
	strcpy(anime.genero , "Romance,Deama");
	anime.temporada = 2;
	agregarFinal(lista,anime);;
	
	strcpy(anime.nombre , "Suki tte ii na yo");
	strcpy(anime.genero , "Romance");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Air");
	strcpy(anime.genero , "Drama,recuerdos de la vida");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Kimi ni todoke");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 1;
	agregarFinal(lista,anime);
	
	strcpy(anime.nombre , "Kimi ni todoke 2");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 2;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Hiyokoi");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 0;
	agregarFinal(lista,anime);
	
	strcpy(anime.nombre , "Koe no katachi");
	strcpy(anime.genero , "Romance,Escolar,Drama");
	anime.temporada = 0;
	agregarFinal(lista,anime);
	
	strcpy(anime.nombre , "Kimi no na wa");
	strcpy(anime.genero , "Romance,Fantasia");
	anime.temporada = 0;
	agregarFinal(lista,anime);
	
	strcpy(anime.nombre , "Nisekoi");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Nisekoi 2");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 2;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Aoi hana");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Sasameki kono");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Danmachi");
	strcpy(anime.genero , "Fantasia,Aventura");
	anime.temporada = 1;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Asagao to kase-san");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	agregarFinal(lista,anime);
	
	strcpy(anime.nombre , "Con el tiempo llegare tuya");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Everyday lily");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Gokujou Drops");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	agregarInicio(lista,anime);
	
	strcpy(anime.nombre , "Hanjuku joshi");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	agregarFinal(lista,anime);
	
	strcpy(anime.nombre , "Ouji-sama nante irana");
	strcpy(anime.genero , "Romance,Escolar,Yuri");
	anime.temporada = 0;
	agregarFinal(lista,anime);
	
	eliminarInicio(lista);
	eliminarFinal(lista);
	
	strcpy(anime.nombre , "Chicha na mune no tokimeki");
	strcpy(anime.genero , "Romance,Escolar");
	anime.temporada = 1;
	insertar(0,lista,anime);
	eliminar(7,lista);
	
	strcpy(anime.nombre , "Ano natsu no matteru");
	strcpy(anime.genero , "Romance,Escolar,Ciencia ficcion,Comedia");
	anime.temporada = 1;
	insertar(7,lista,anime);
	eliminarFinal(lista);
	eliminarInicio(lista);
	i = 0;
	while((aux = obtener(i,lista))) {
		printf("%i) Nombre: %s\n",i,aux->nombre);
		printf("%i) Genero: %s\n",i,aux->genero);
		printf("%i) Temporada: %hi\n\n",i,aux->temporada);
		i++;
	}
	return 0;
}
Lista *crearLista(void) {
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	if(lista != NULL) {
		lista->cabeza = NULL;
		lista->ultimo = NULL;
	}
	return lista;
}
void *destruirLista(Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminado = NULL;
		while(lista->cabeza) {
			eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			free(eliminado);
		}
		lista->ultimo = NULL;
	}
	free(lista);
}
Nodo *crearNodo(Anime anime) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->anime.nombre , anime.nombre, strlen(anime.nombre) + 1);
	strncpy(nodo->anime.genero , anime.genero, strlen(anime.genero) + 1);
	nodo->anime.temporada = anime.temporada;
	nodo->siguiente = NULL;
	return nodo;
}
void destruirNodo(Nodo *nodo) {
	free(nodo);
}
void agregarInicio(Lista *lista,Anime anime) {
	Nodo *nodo = crearNodo(anime);
	if(!lista->cabeza) {
		lista->cabeza = nodo;
		lista->ultimo = nodo;
	} else if(!lista->cabeza->siguiente) {
		lista->ultimo = lista->cabeza;
		lista->cabeza = nodo;
		nodo->siguiente = lista->ultimo;
	} else {
		nodo->siguiente = lista->cabeza;
		lista->cabeza = nodo;
	}
}
void agregarFinal(Lista *lista,Anime anime) {
	Nodo *nodo = crearNodo(anime);
	if(!lista->cabeza) {
		lista->cabeza = nodo;
		lista->ultimo = nodo;
	}
	if(!lista->cabeza->siguiente) {
		lista->cabeza->siguiente = nodo;
		lista->ultimo = nodo;
	} else {
		lista->ultimo->siguiente = nodo;
		lista->ultimo = nodo;
	}
}

void insertar(int n,Lista *lista,Anime anime) {
	Nodo *nodo = crearNodo(anime);
	if (!lista->cabeza) {
		lista->cabeza = nodo;
		lista->ultimo = nodo;
	} else {
		if(n == 0) {
			nodo->siguiente = lista->cabeza;
			lista->cabeza = nodo;
		} else {
			int posicion = 0;
			Nodo *puntero = lista->cabeza;
			while (posicion < n-1 && puntero->siguiente) {
				puntero = puntero->siguiente;
				posicion++;
			}
			if(puntero->siguiente){
				nodo->siguiente = puntero->siguiente;
				puntero->siguiente = nodo;
			} else {
				nodo->siguiente = puntero->siguiente;
				lista->ultimo = nodo;
				puntero->siguiente = nodo;
			}
		}
	}
}

Anime *obtener(int n,Lista *lista) {
	if(lista->cabeza) {
		int posicion = 0;
		Nodo *puntero = lista->cabeza;
		while(posicion < n && puntero->siguiente) {
			puntero = puntero->siguiente;
			posicion++;
		}
		if(posicion != n) {
			return NULL;
		} else {
			return &puntero->anime;
		}
	} else{
		return NULL;
	}
}

void eliminarInicio(Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminar = lista->cabeza;
		if(eliminar->siguiente) {
			lista->cabeza = eliminar->siguiente;
			eliminar->siguiente = NULL;
		}
		else {
			lista->cabeza = NULL;
			lista->ultimo = NULL;
		}
		destruirNodo(eliminar);
	}
}

void eliminarFinal(Lista *lista) {
	if(lista->ultimo) {
		Nodo *eliminar = lista->ultimo;
		if(lista->cabeza->siguiente) {
			Nodo *puntero = lista->cabeza;
			while(puntero->siguiente != eliminar) {
				puntero = puntero->siguiente;
			}
			puntero->siguiente = eliminar->siguiente;
			lista->ultimo = puntero;
		} else {
			lista->cabeza = NULL;
			lista->ultimo = NULL;
		}
		destruirNodo(eliminar);
	}
}

void eliminar(int n,Lista *lista) {
	if(lista->cabeza) {
		Nodo *eliminar = NULL;
		if(n == 0) {
			eliminar = lista->cabeza;
			lista->cabeza = eliminar->siguiente;
			destruirNodo(eliminar);
		} else {
			Nodo *puntero = lista->cabeza;
			int posicion = 0;
			while(posicion < n-1 && puntero->siguiente) {
				puntero = puntero->siguiente;
				posicion++;
			}
			if(posicion == n-1 && puntero->siguiente) {
				if((eliminar = puntero->siguiente) != lista->ultimo) {
					puntero->siguiente = eliminar->siguiente;
				} else {
					lista->ultimo = puntero;
				}
				eliminar->siguiente = NULL;
				destruirNodo(eliminar);
			}
		}
	}
}
