/*
		**Aqui se encontraran las funciones estandar ajenas a la funcion que llevara a cabo
		el programa. Aqui se encontraran los prototipos de las funciones para mejorar el aspecto 
		arreglo de espacios innecesarios y mayusculas
*/

#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
//AQUI SE ENCONTRARA EL MENU QUE PROPORCIONARA TODAS LAS FUNCIONES Q LLEVARA EL PROGRAMA
void menu(char *bin);
//CON ESTA FUNCION VERIFICAMOS SI EL ANIME MANGA SE ENCUENTRA YA CREADO
bool anime_existente(char *nombre,char *tipo,char *bin);
//CON ESTA FUNCION CORREGIMOS EL SALTO DE LINEA DEL FGETS
void arreglar_fgets(char *txt);
//ESTA FUNCION ELIMINA LOS ESPACIOS INNECESARIOS
void arreglar_espacios(char *txt);
#endif /*_FUNCIONES_H_*/
