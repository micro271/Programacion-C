/*
		**Funciones que se utilizaran a lo largo del programa
		**ya sea para comodar letras coloca mayusculas y eliminar errores
		
		**PROTOTYPOS DE LAS FUNCIONES
*/

#ifndef __FUNCIONES__H__
#define __FUNCIONES__H__

//ELIMINAMOS EL ERROR DEL FGETS AL COLOCAR UN \n EN VEZ DE UN \0
void arreglar_fgets(char *str);
//Agregamos las respectivas mayusculas que corresponde a los nombres de los mangakas y el anime
void agregar_mayus(char *str);
//Agregamos los generos de los animes dependiendo de la posicion q elijan
int agregar_genero(char *str,int pos);//ESTA FUNCION RETORNARA 0 PARA SALIR DEL BUCLE
//ARREGLAMOS LOS ESPACIOS INNECESARIOS QUE HABRIA EN LOS CHAT
void arreglar_espacios(char *str);
//MENU PARA HACER LAS DISTINTAS FUNCIONES
void menu(char *bin,char *txt);
#endif /* __FUNCIONES__H__*/


