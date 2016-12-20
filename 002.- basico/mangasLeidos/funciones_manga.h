/*
		**Aqui se encontraran los prototypos de las funciones que se utilizaran para agregar modificar
		y eliminar mangas del programa. 
*/

#ifndef _FUNCIONES_MANGA_H
#define _FUNCIONES_MANGA_H
struct MANGA_ANIME {
	char nombre[30];
	char autor[30];
	char genero[300];
	char tipo[10];
	int posicion;
};
//MOSTRAMOS TODOS SEA ANIME O MANGA
bool mostrar_todo(char *bin);
//CON ESTA FUNCION MOSTRAMOS LOS MANGAS ANIMES O MANHWAS DEPENDIENDO DE QUE TIOP
bool mostrar(char *bin,char *tipo);
//CON ESTA FUNCION MOSTRAMOS LOS ANIMES DEPENDIENDO DEL GENERO
bool mostrar_genero(char *bin);
//CON ESTA FUNCION CREAMOS YA SEA MANGA MANHWAS O ANIME
int crear(char *bin,char *tipo);
//INSERTAMOS EL MANGA EN EL FICHERO BIN
void insertar_tipo(struct MANGA_ANIME *nuevo,char *bin);
//CON ESTA FUNCION ELIMINAMOS UN ANIME O MANGA O MANHWA
bool eliminar_tipo(char *bin);
//CON ESTA FUNCION GUARDAMOS EL LISTADO DE ANIMES EN UN ARCHIVO TEXTO
bool generar_lista(char *bin,char *txt);
//CON ESTA FUNCION GUARDAMOS UN TIOP EN ESPECIFICO EN UN ARCHIVO TEXTO
bool generar_tipo(char *bin,char *txt,char *tipo);
#endif /*_FUNCIONES_MANGA_H*/
