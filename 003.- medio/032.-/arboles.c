#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ESTRENO {
	char temporada[10];
	short int anio;
};

typedef struct ANIME {
	char nombre[50];
	char genero[50];
	char tipo[10];
	struct ESTRENO estreno;
}Anime;

typedef struct NODO {
	struct ANIME anime;
	struct NODO *izq;
	struct NODO *der;
	struct NODO *padre;
}Nodo;

typedef struct NODO Arbol;
static char *__strmin__(char *str);
static void __insert__(Arbol **arbol,Anime anime,Arbol *padre);
void insert(Arbol **arbol,Anime anime);
Nodo *crearNodo(Anime anime,Nodo *padre);
void destruirNodo(Nodo *nodo);
int existe(Arbol *arbol,Anime *anime);
static void __reemplazar__(Nodo *reemplazar,Nodo *nuevoNodo);
static void __eliminar__(Arbol *nodo);
static Nodo *__maximo__(Nodo *nodo);
void eliminar(Arbol *arbol,Anime *anime);
void inorden(Nodo *nodo);

int main(int argc,char **argv) {
	Arbol *arbol = NULL;
	Anime anime,*aux;
	strcpy(anime.nombre,"Clannad after story");
	strcpy(anime.genero,"Drama,Romanc,Fantasia");
	strcpy(anime.estreno.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.estreno.anio = 2008;
	insert(&arbol,anime);							inorden(arbol);printf("\n");
	
	strcpy(anime.nombre,"Clannad");
	strcpy(anime.genero,"Drama,Romanc");
	strcpy(anime.estreno.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.estreno.anio = 2007;
	insert(&arbol,anime);							inorden(arbol);printf("\n");
	
	
	strcpy(anime.nombre,"Suki te ii na yo");
	strcpy(anime.genero,"Escolaes,Romanc");
	strcpy(anime.estreno.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.estreno.anio = 2007;
	insert(&arbol,anime);							inorden(arbol);printf("\n");
	
	strcpy(anime.nombre,"Hundred");
	strcpy(anime.genero,"Ciencia ficcion,Romanc");
	strcpy(anime.estreno.temporada,"Winter");
	strcpy(anime.tipo,"Anime");
	anime.estreno.anio = 2016;
	insert(&arbol,anime);							inorden(arbol);printf("\n");
	
	strcpy(anime.nombre,"Kimi ni todoke");
	strcpy(anime.genero,"Escolaes,Romanc");
	strcpy(anime.estreno.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.estreno.anio = 2009;
	insert(&arbol,anime);							inorden(arbol);printf("\n");
	
	strcpy(anime.nombre,"Clannad");
	strcpy(anime.genero,"Drama,Romanc");
	strcpy(anime.estreno.temporada,"utumn");
	strcpy(anime.tipo,"Anime");
	anime.estreno.anio = 2007;
	eliminar(arbol,&anime);							inorden(arbol);printf("\n");

	return 0;
}
Nodo *crearNodo(Anime anime,Nodo *padre) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->izq = nodo->der = NULL;
	strncpy(nodo->anime.nombre,anime.nombre,strlen(anime.nombre)+1);
	strncpy(nodo->anime.genero,anime.genero,strlen(anime.genero)+1);
	strncpy(nodo->anime.estreno.temporada,anime.estreno.temporada,strlen(anime.estreno.temporada)+1);
	strncpy(nodo->anime.tipo,anime.tipo,strlen(anime.tipo)+1);
	nodo->anime.estreno.anio = anime.estreno.anio;
	nodo->padre = padre;
	return nodo;
}
void destruirNodo(Nodo *nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;
	nodo->padre = NULL;
	free(nodo);
}
static char *__strmin__(char *str) {
	char *aux = (char *)malloc(sizeof(char)*(strlen(str)+1));
	int i = 0;
	if(*str != '\0' && str != NULL && *str != '\n') {
		while (str[i] != '\0') {
			aux[i] = tolower(str[i]);
			i++;
		}
		aux[i] = '\0';
		return aux;
	} else {
		return NULL;
	}
}
static void __insert__(Arbol **arbol,Anime anime,Arbol *padre) {
	if(*arbol == NULL) {
		*arbol = crearNodo(anime,padre);
	} else if((*arbol)->anime.estreno.anio > anime.estreno.anio) {
		__insert__(&((*arbol)->izq),anime,*arbol);
	} else if((*arbol)->anime.estreno.anio < anime.estreno.anio) {
		__insert__(&((*arbol)->der),anime,*arbol);
	} else {
		char *temp_arbol = __strmin__((*arbol)->anime.estreno.temporada);
		char *temp_anime = __strmin__(anime.estreno.temporada);
		int aux_temp_arbol;
		int aux_temp_anime;
		if(temp_arbol == NULL) {
			aux_temp_arbol = -1;
		} else if(strcmp(temp_arbol,"winter") == 0) {
			aux_temp_arbol = 0;
		} else if(strcmp(temp_arbol,"spring") == 0) {
			aux_temp_arbol = 1;
		} else if(strcmp(temp_arbol,"summer") == 0) {
			aux_temp_arbol = 2;
		} else if(strcmp(temp_arbol,"utumn") == 0) {
			aux_temp_arbol = 3;
		} else {
			aux_temp_arbol = -1;
		}
		
		if(temp_anime == NULL) {
			aux_temp_anime = -1;
		} else if(strcmp(temp_anime,"winter") == 0) {
			aux_temp_anime = 0;
		} else if(strcmp(temp_anime,"sprnig") == 0) {
			aux_temp_anime = 1;
		} else if(strcmp(temp_anime,"summer") == 0) {
			aux_temp_anime = 2;
		} else if(strcmp(temp_anime,"utumn") == 0) {
			aux_temp_anime = 3;
		} else {
			aux_temp_anime = -1;
		}
		free(temp_anime);free(temp_arbol);
		if(aux_temp_anime != -1 && aux_temp_arbol != -1) {
			if(aux_temp_anime > aux_temp_arbol) {
				__insert__(&((*arbol)->der),anime,*arbol);
			} else if(aux_temp_anime < aux_temp_arbol) {
				__insert__(&((*arbol)->izq),anime,*arbol);
			}
		}
		if(aux_temp_anime == aux_temp_arbol || (aux_temp_arbol == -1 || aux_temp_anime == -1)) {
			if(strcmp(anime.nombre,(*arbol)->anime.nombre) == 1) {
				__insert__(&((*arbol)->der),anime,*arbol);
			} else {
				__insert__(&((*arbol)->izq),anime,*arbol);
			}
		}
	}
}
void insert(Arbol **arbol,Anime anime) {
	if(existe(*arbol,&anime) != 1) {
		__insert__(arbol,anime,NULL);
	}
}
int existe(Arbol *arbol,Anime *anime) {
	if(arbol != NULL) {
		char *aux_anime_nombre = __strmin__(anime->nombre);
		char *aux_arbol_nombre = __strmin__(arbol->anime.nombre);
		if(strcmp(aux_anime_nombre,aux_arbol_nombre) == 0) {
			free(aux_arbol_nombre);free(aux_anime_nombre);
			return 1;
		}
		free(aux_arbol_nombre);free(aux_anime_nombre);		
		if(anime->estreno.anio > arbol->anime.estreno.anio) {
			return existe(arbol->der,anime);
		} else if(anime->estreno.anio < arbol->anime.estreno.anio) {
			return existe(arbol->izq,anime);
		} else {
			char *temp_arbol = __strmin__(arbol->anime.estreno.temporada);
			char *temp_anime = __strmin__(anime->estreno.temporada);
			int aux_temp_arbol;
			int aux_temp_anime;
			if(strcmp(temp_arbol,"winter") == 0) {
				aux_temp_arbol = 0;
			} else if(strcmp(temp_arbol,"spring") == 0) {
				aux_temp_arbol = 1;
			} else if(strcmp(temp_arbol,"summer") == 0) {
				aux_temp_arbol = 2;
			} else if(strcmp(temp_arbol,"utumn") == 0) {
				aux_temp_arbol = 3;
			} else {
				aux_temp_arbol = -1;
			}
			
			if(strcmp(temp_anime,"winter") == 0) {
				aux_temp_anime = 0;
			} else if(strcmp(temp_anime,"sprnig") == 0) {
				aux_temp_anime = 1;
			} else if(strcmp(temp_anime,"summer") == 0) {
				aux_temp_anime = 2;
			} else if(strcmp(temp_anime,"utumn") == 0) {
				aux_temp_anime = 3;
			} else {
				aux_temp_anime = -1;
			}
			free(temp_anime);free(temp_arbol);
			if(aux_temp_anime != -1 && aux_temp_arbol != -1) {
				if(aux_temp_anime > aux_temp_arbol) {
					return existe(arbol->der,anime);
				} else if(aux_temp_anime < aux_temp_arbol) {
					return existe(arbol->izq,anime);
				}
			}
			if(aux_temp_anime == aux_temp_arbol || (aux_temp_arbol == -1 || aux_temp_anime == -1)) {
				if(strcmp(anime->nombre,arbol->anime.nombre) == 1) {
					return existe(arbol->der,anime);
				} else {
					return existe(arbol->izq,anime);
				}
			}
		}
	} else {
		return 0;
	}
}

static Nodo *__maximo__(Nodo *nodo) {
	if(nodo->der) {
		return __maximo__(nodo->der);
	} else {
		return nodo;
	}
}
static void __reemplazar__(Nodo *reemplazar,Nodo *nuevoNodo) {
	if(reemplazar->padre) {
		if(reemplazar->padre->der == reemplazar) {
			reemplazar->padre->der = nuevoNodo;
		} else if(reemplazar->padre->izq == reemplazar) {
			reemplazar->padre->izq = nuevoNodo;
		}
	}
	if(nuevoNodo) {
		nuevoNodo->padre = reemplazar->padre;
	}
}
static void __eliminar__(Arbol *nodo) {
	if(nodo->der && nodo->izq) {
		Nodo *maximo = __maximo__(nodo->izq);
		strncpy(nodo->anime.nombre,maximo->anime.nombre,strlen(maximo->anime.nombre)+1);
		strncpy(nodo->anime.genero,maximo->anime.genero,strlen(maximo->anime.genero)+1);
		strncpy(nodo->anime.estreno.temporada,maximo->anime.estreno.temporada,strlen(maximo->anime.estreno.temporada)+1);
		strncpy(nodo->anime.tipo,maximo->anime.tipo,strlen(maximo->anime.tipo)+1);
		nodo->anime.estreno.anio = maximo->anime.estreno.anio;
		__eliminar__(maximo);
	} else if(nodo->izq) {
		__reemplazar__(nodo,nodo->izq);
		destruirNodo(nodo);
	system("pause");
	} else if(nodo->der) {
		__reemplazar__(nodo,nodo->der);
		destruirNodo(nodo);
	} else {
		__reemplazar__(nodo,NULL);
		destruirNodo(nodo);
	}
}

void eliminar(Arbol *arbol,Anime *anime) {
	if(arbol != NULL) {
		char *aux_anime_nombre = __strmin__(anime->nombre);
		char *aux_arbol_nombre = __strmin__(arbol->anime.nombre);
		if(aux_anime_nombre != NULL && aux_arbol_nombre != NULL) {
			if(strcmp(aux_anime_nombre,aux_arbol_nombre) != 0) {
				if(aux_anime_nombre != NULL) free(aux_arbol_nombre);
				if(aux_arbol_nombre != NULL) free(aux_anime_nombre);
				if(anime->estreno.anio > arbol->anime.estreno.anio) {
					eliminar(arbol->der,anime);
				} else if(anime->estreno.anio < arbol->anime.estreno.anio) {
					eliminar(arbol->izq,anime);
				} else {
					char *temp_arbol = __strmin__(arbol->anime.estreno.temporada);
					char *temp_anime = __strmin__(anime->estreno.temporada);
					int aux_temp_arbol;
					int aux_temp_anime;
					if(temp_arbol == NULL) {
						aux_temp_arbol = -1;
					} else if(strcmp(temp_arbol,"winter") == 0) {
						aux_temp_arbol = 0;
					} else if(strcmp(temp_arbol,"spring") == 0) {
						aux_temp_arbol = 1;
					} else if(strcmp(temp_arbol,"summer") == 0) {
						aux_temp_arbol = 2;
					} else if(strcmp(temp_arbol,"utumn") == 0) {
						aux_temp_arbol = 3;
					} else {
						aux_temp_arbol = -1;
					}
					
					if(temp_anime == NULL) {
						aux_temp_anime = -1;
					} else if(strcmp(temp_anime,"winter") == 0) {
						aux_temp_anime = 0;
					} else if(strcmp(temp_anime,"sprnig") == 0) {
						aux_temp_anime = 1;
					} else if(strcmp(temp_anime,"summer") == 0) {
						aux_temp_anime = 2;
					} else if(strcmp(temp_anime,"utumn") == 0) {
						aux_temp_anime = 3;
					} else {
						aux_temp_anime = -1;
					}
					free(temp_anime);free(temp_arbol);
					if(aux_temp_anime != -1 && aux_temp_arbol != -1) {
						if(aux_temp_anime > aux_temp_arbol) {
							eliminar(arbol->der,anime);
						} else if(aux_temp_anime < aux_temp_arbol) {
							eliminar(arbol->izq,anime);
						}
					}
					if(aux_temp_anime == aux_temp_arbol || (aux_temp_arbol == -1 || aux_temp_anime == -1)) {
						if(strcmp(anime->nombre,arbol->anime.nombre) == 1) {
							eliminar(arbol->der,anime);
						} else {
							eliminar(arbol->izq,anime);
						}
					}
				}
			} else {
				if(aux_anime_nombre != NULL) free(aux_arbol_nombre);
				if(aux_arbol_nombre != NULL) free(aux_anime_nombre);
				__eliminar__(arbol);
			}
		} else {
			return;
		}
	}
}
void inorden(Nodo *nodo) {
	if(nodo != NULL) {
		printf("( ");
		inorden(nodo->izq);
		printf(" {%s} ",nodo->anime.nombre);
		inorden(nodo->der);
		printf(" )");
	} else {
		printf(" - ");
	}
}

