/*
		**Aqui se encuentra los prototypos de las funciones que se utilizaran de manera global
		en el programa
*/

#ifndef _FUNCIONES_H_GLOBAL_
#define _FUNCIONES_H_GLOBAL_

//AQUI COLOCAREMOS EL MENU PRINCIPAL
void menu(char *bin);
//EN ESTA FUNCION SE ENCONTRARAN LAS FUNCIONES
void submenu(char *bin,int n);
//CON ESTA FUNCION VERIFICAMOS SI EL ANIME MANGA SE ENCUENTRA YA CREADO
bool anime_existente(char *nombre,char *tipo,char *bin);
//CON ESTA FUNCION CORREGIMOS EL SALTO DE LINEA DEL FGETS
void arreglar_fgets(char *txt);
//ESTA FUNCION ELIMINA LOS ESPACIOS INNECESARIOS
void arreglar_espacios(char *txt);
#endif/*_FUNCIONES_H_GLOBAL_*/
