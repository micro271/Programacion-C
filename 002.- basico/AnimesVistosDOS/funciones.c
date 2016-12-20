/*
		**Funciones que se utilizaran a lo largo del programa
		**ya sea para comodar letras coloca mayusculas y eliminar errores
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funciones.h"
#include "anime.h"

void menu(char *bin,char *txt) {
	struct ANIME anime;int opc,modificar,opc_2,opc_3,opc_4,eliminar,n;
	bool opc_search;
	do {
		printf("Que decea hacer\n");
		printf("1.- Ver listado de anime\n");
		printf("2.- Agregar anime\n");
		printf("3.- Modigicar anime\n");
		printf("4.- Eliminar anime\n");
		printf("5.- Buscar anime\n");
		printf("0.- Salir\n");
		printf("Opcion: ");fflush(stdin);
		scanf("%i",&opc);
		
		switch(opc) {
			case 1:
				system("cls");
				if(imprimir_anime(txt)) {
					printf("No hay ningun anime registrado\n\n");
					break;
				}
				printf("\n1.- Volver\n");
				printf("0.- Salir\n");
				do {
					printf("Opcion: ");fflush(stdin);
					scanf("%i",&opc_2);
				}while(opc_2 != 1 && opc_2 != 0);
				
				switch(opc_2) {
					case 1:system("cls");break;
					case 0:opc = 0;break;
				}
				break;
			case 2:
				anime = crear_anime(bin,txt);
				if(insertar_anime(bin,anime)) {
					printf("\nA ocurrido un error, no se pudo guardar el anime \n");
				}
				if(organizar_animes(bin,txt)) {
					printf("\nNo hay animes registrados o el archivo no existe\n");		
				}
				system("cls");
				break;
			case 3:
				modificar = modificar_anime(bin,txt);
				if(modificar == 1) {					
					printf("\nEl anime no existe o no hay animes registrados\n");
				}
				else if(modificar == 0) {
					if(organizar_animes(bin,txt)) {
						printf("\nNo hay animes registrados o el archivo no existe\n");	
					}
				}
				system("cls");
				break;
			case 4:
				system("cls");
				eliminar = eliminar_anime(bin,txt);
				if(eliminar == 1) {
					printf("El anime no existe\n\n");
				}
				else if(eliminar == 0) {
					system("cls");
				}
				else if(eliminar == 3) {
					system("cls");
					printf("No hay animes registrados\n\n");
				}
				break;
			case 5:
				do {
					system("cls");
					printf("1.- Genero\n");
					printf("2.- Nombre\n");
					printf("Opcion: ");fflush(stdin);
					scanf("%i",&n);
					opc_search = buscar_anime(bin,txt,n);
				}while(opc_search);
				system("cls");
				break;
			case 0:break;
			default: opc = 10;break;
		}
	}while(opc != 0);
	if(opc == 0) {
		system("exit");
	}
}

void arreglar_fgets(char *str) {
	int i = 0;
	while (*(str+i) != '\n') {
		i++;
	}
	*(str+i) = '\0';
}
void arreglar_espacios(char *str) {
	int i,k;
	while(isspace(*str)) {
		for(i = 0; i < strlen(str); i++) {
			*(str+i) = str[i+1];
		}
	}
	i = 0;
	while (*(str+i) != '\0') {
		if (isspace(*(str+i)) && isspace(*(str+(i-1))) ) {
			for (k = i; k < strlen(str); k++) {
				str[k] = str[k+1];
			}
			continue;
		}
		i++;
	}
	while(*(str+i) == '\0' && isspace(*(str+(i-1))) ) {
		*(str+(i-1)) = '\0';
		i--;
	}
}
void agregar_mayus(char *str) {
	int i,k;i = 0;
	*str = toupper(*str);
	while (str[i] != '\0') {
		if (isspace(str[i-1]) && isalpha(str[i]) ) {
			str[i] = toupper(str[i]);
		}
		i++;
	}
}

int agregar_genero(char *str,int pos) {
	char genero[25];int i;char genero_dos[25];int k;
	switch(pos)
	{
		case 1:strcpy(genero,", Romance");break;
		case 2:strcpy(genero,", Drama");break;
		case 3:strcpy(genero,", Comedia");break;
		case 4:strcpy(genero,", Harem");break;
		case 5:strcpy(genero,", Psicologico");break;
		case 6:strcpy(genero,", Musical");break;
		case 7:strcpy(genero,", Fantasia");break;
		case 8:strcpy(genero,", Super poderes");break;
		case 9:strcpy(genero,", Magia");break;
		case 10:strcpy(genero,", Ciencia ficcion");break;
		case 11:strcpy(genero,", Ecchi");break;
		case 12:strcpy(genero,", Hentai");break;
		case 13:strcpy(genero,", Recuerdos de la vida");break;
		case 14:strcpy(genero,", Mecha");break;
		case 15:strcpy(genero,", Accion");break;
		case 16:strcpy(genero,", Aventura");break;
		case 17:strcpy(genero,", Deportes");break;
		case 18:strcpy(genero,", Escolares");break;
		case 19:strcpy(genero,", Gore");break;
		case 20:strcpy(genero,", Horror");break;
		case 21:strcpy(genero,", Lucha");break;
		case 22:strcpy(genero,", Militar");break;
		case 23:strcpy(genero,", Historico");break;
		case 24:strcpy(genero,", Parodia");break;
		case 0:return 0;
		default: return 1;
	}
	k = 0;
	for(i = 0; genero[i] != '\0'; i++) {
		if(isalpha(genero[i])) {
			genero_dos[k] = genero[i];
			if (genero[i+1] == '\0') {
				genero_dos[k+1] = '\0';break;
			}
			k++;
		}
	}
	
	if(strstr(str,genero_dos) != NULL) {
		return 1;
	}
	
	for(i = 0; i <= strlen(str); i++) {
		if (str[i] == '.') {
			str[i] = '\0';
		}
	}
	
	strcat(str,genero);
	while(isspace(*str) || *str == ',')
	{
		for(i = 0; i <= strlen(str); i++)
		{
			*(str+i) = *(str+(i+1));
		}
	}
	i = 0;
	while (str[i] != '\0') {
		i++;
	}
	str[i] = '.';
	str[i+1] = '\0';
	return pos;
}
