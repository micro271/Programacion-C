/*
		**Prototypos de las funciones que se utilizaran para los animes
		**ademas de organizarlos y eliminarlos.
*/

#ifndef __ANIMES__FUNCIONES__H__
#define	__ANIMES__FUNCIONES__H__
#include <stdbool.h>
typedef struct ANIME {
	char nombre[50];
	char genero[300];
	char mangaka[30];
	int posicion;
}Anime;

//Creamos una funcion que retornna un tipo struct ANIME 
struct ANIME crear_anime(char *bin,char *txt);
//Insertamos el anime en el fichero binario
bool insertar_anime(char *bin,struct ANIME aux);
//Insertar ANIME EN EL ARCHIVO TXT
void insertar_anime_txt(struct ANIME *aux,char *txt,int p);
//ORGANIZAMOS EL ANIME DEPENDIENDO SE SU POSICION DE MENOR A MAYOR DE FORMA INSERCION
bool organizar_animes(char *bin,char *txt);
//IMPRIMIMOS TODO LO QUE TENEMOS GUARDADO EN EL ARCHIVO TEXTUAL
bool imprimir_anime(char *txt);
//POSICION EN DONDE GUARDAR EL ANIME
int posicion_De_guardado(int y,int *posicion,char *bin,char *txt);
//Verificamos si dicho nombre se encuentra en el listado RETORNA FALSO SI NO EXISTE Y TRUE EN CASO CONTRARIO
bool anime_existente(char *bin,char *txt);
//ESTA FUNCION MODIFICA UN ANIME RETORNA 1 SI HUBO UN PROBLEMA YA SEA QUE NO HAYGA NADA O NO EXISTA AUN  Y 0 SI HUBO EXITO
int modificar_anime(char *bin,char *txt);
//ESTA FUNCION ELIMINA UN ANIME RETORNA 1 SI EL ANIME NO EXISTE Y 0 DE FORMA CONTRARIA
int eliminar_anime(char *bin,char *txt);
//BUSCAMOS EL UN ANIME EN ESPECIFICO
bool buscar_anime(char *bin,char *txt,int n);
#endif /*__ANIMES__FUNCIONES__H__*/
