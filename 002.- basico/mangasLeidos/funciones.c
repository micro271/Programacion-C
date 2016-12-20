/*
		**Aqui se encontraran las funciones estandar que se utilizaran en el programa
		como el menu y correccion de cadenas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>
#include "funciones.h"
#include "funciones_manga.h"

void menu(char *bin) {
	int opc,opc_1,opc_3;int k;
	char tipo[10],txt[15];
	do {
		system("cls");
		printf("1.- Ver listado de anime/manga\n");
		printf("2.- Agregar anime/manga\n");
		printf("3.- Modificar anime/manga\n");
		printf("4.- Eliminar anime/manga\n");
		printf("5.- Generar archivo de texto\n");
		printf("0.- Salir\n");
		printf("Opcion: ");fflush(stdin);
		if(scanf("%i",&opc) == 0)//SCAN F RETORNA UN 0 O NEGATIVO SI HUBO UNA FALLA, 0 SI SE INTRODUJO UN CARACTER
			opc = -1;
		switch(opc) {
			case 1:
				do {
					system("cls");
					printf("1.- Ver todo el listado\n");
					printf("2.- Ver solo mangas\n");
					printf("3.- Ver solo animes\n");
					printf("4.- Ver solo manhwas\n");
					printf("5.- Por genero\n");
					printf("6.- Volver\n");
					printf("Opcion: ");fflush(stdin);
					if(scanf("%i",&opc_1) == 0)
						opc_1 = -1;
					switch(opc_1) {
						case 1:system("cls");
							if(!mostrar_todo(bin))
								printf("No hay nada registrado\n");
							break;
						case 2:strcpy(tipo,"Manga");break;
						case 3:strcpy(tipo,"Anime");opc_1 = 2;break;
						case 4:strcpy(tipo,"Manhwa");opc_1 = 2;break;
						case 5:mostrar_genero(bin);break;
						case 6:break;
					}
					if(opc_1 == 2) {
						system("cls");
						if(!mostrar(bin,tipo))
							printf("No hay %ss registrados\n",tipo);
					}
					if(opc_1 >= 1 && opc_1 <= 5) {
						printf("\n1.- Volver\n");
						printf("2.- Salir\n");
						do {
							printf("Opcion: ");fflush(stdin);
							if(scanf("%i",&opc_3) == 0)
								opc_3 = -1;
						}while(opc_3 != 1 && opc_3 != 2);
						switch(opc_3) {
							case 1:break;
							case 2: opc_1 = 6;break;
						}
					}
				}while(opc_1 != 6);
				break;
				case 2:
					do {
						system("cls");
						printf("1.- Manga\n");
						printf("2.- Manhwa\n");
						printf("3.- Anime\n");
						printf("\n4.- volver\n");
						printf("Opcion: ");fflush(stdin);
						if(!scanf("%i",&opc_1))
							opc_1 = -1;
						switch(opc_1) {
							case 1: strcpy(tipo,"Manga");break;
							case 2: strcpy(tipo,"Manhwa");break;
							case 3: strcpy(tipo,"Anime");break;
						}
						if(opc_1 <= 3 && opc_1 >= 1 ) {
							if(crear(bin,tipo) == 1)
								opc_1 = 4;
						}
					}while(opc_1 != 4);
					break;
				case 3:break;
				case 4:
					if(!eliminar_tipo(bin))	{
						printf("No hay animes registrados\n\n");
					}
					system("cls");
					break;
				case 5:
					do {
						system("cls");
						printf("1.- Todo lo registrado\n");
						printf("2.- Solo manga\n");
						printf("3.- Solo anime\n");
						printf("4.- Solo manhwa\n");
						printf("5.- Volver\n");
						if(!scanf("%i",&opc_1))
							opc_1 = 0;
						switch(opc_1) {
							case 1:
								strcpy(txt,"listado.txt");
								system("cls");
								if(!generar_lista(bin,txt)) {
									printf("No hay nada registrado\n");
								}
								else {
									printf("Se a generado el listado con el nombre %s\n",txt);
								}
								break;
							case 2:
								strcpy(txt,"Mangas.txt");
								strcpy(tipo,"Manga");
								break;
							case 3:
								strcpy(txt,"Animes.txt");
								strcpy(tipo,"Anime");
								break;
							case 4:
								strcpy(txt,"Manhwas.txt");
								strcpy(tipo,"Manhwa");
								break;
							case 5:break;
						}
						if(opc_1 > 1 && opc_1 < 5) {
							system("cls");
							if(!generar_tipo(bin,txt,tipo)) {
								printf("No hay %s registrado\n",tipo);
							}
							else {
								printf("Se a generado el listado con el nombre %s\n",txt);
							}
						}
						if(opc_1 != 5) {
							printf("\n1.- Volver\n");
							printf("2.- Salir\n");
							do {
								printf("Opcion: ");fflush(stdin);
								if(!scanf("%i",&opc_3))
									opc_3 = 0;
							}while(opc_3 != 1 && opc_3 != 2);
							if(opc_3 == 2) {
								opc_1 = 5;
							}
						}
					}while(opc_1 != 5);					
					break;
					
		}
	}while(opc != 0);
}

void arreglar_fgets(char *txt) {
	int i;i = 0;
	while(*(txt+i) != '\n') {
		i++;
	}
	*(txt+i) = '\0';
}
void arreglar_espacios(char *txt) {
	int i,k;i = 0;
	while(isspace(*(txt))) {
		for(k = 0; *(txt+k) != '\0'; k++) {
			*(txt+k) = *(txt+(k+1));
		}
	}
	i = 0;
	while(*(txt+i) != '\0') {
		if( isspace(*(txt+i)) && isspace(*(txt+(i-1))) ) {
			for(k = i; *(txt+k) != '\0'; k++) {
				*(txt+k) = *(txt+(k+1));
			}
			continue;
		}
		i++;
	}
	while( *(txt+i) == '\0' && isspace(*(txt+(i-1))) ) {
		*(txt+(i-1)) = '\0';
		i--;
	}
}

bool anime_existente(char *nombre,char *tipo,char *bin) {
	FILE *fp = fopen(bin,"rb");
	char nombre_2[strlen(nombre)+2];
	strncpy(nombre_2,nombre,strlen(nombre)+1);
	if(fp == NULL)
		return false;
	int cont,cont_2,i,k;
	struct MANGA_ANIME *aux;
	fseek(fp,0,SEEK_END);
	cont = ftell(fp)/sizeof(struct MANGA_ANIME);
	if(cont == 0) {
		fclose(fp);
		return false;
	}
	fseek(fp,0,SEEK_SET);
	aux = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
	fread(aux,sizeof(struct MANGA_ANIME),cont,fp);
	fclose(fp);
	cont_2 = 0;
	for(i = 0; *(nombre_2+i) != '\0'; i++) {
		*(nombre_2+i) = tolower(*(nombre_2+i));
	}
	for(i = 0; i < cont; i++) {
		for(k = 0; (aux+i)->nombre[k] != '\0'; k++) {
			(aux+i)->nombre[k] = tolower((aux+i)->nombre[k]);
		}
	}
	for(i = 0; i < cont; i++) {
		if( (strcmp( (aux+i)->nombre, nombre_2 ) == 0) && (strcmp((aux+i)->tipo,tipo) == 0)) {
			cont_2++;break;
		}
	}
	free(aux);
	if(cont_2 == 1)
		return true;
	return false;
}


int agregar_genero(char *str,int pos) {
	char genero[25];int i;char genero_dos[25];int k;
	switch(pos)
	{
		case 1:strcpy(genero,", Romance");break;
		case 2:strcpy(genero,", Yuri");break;
		case 3:strcpy(genero,", Drama");break;
		case 4:strcpy(genero,", Comedia");break;
		case 5:strcpy(genero,", Harem");break;
		case 6:strcpy(genero,", Yaoi");break;
		case 7:strcpy(genero,", Demonios");break;
		case 8:strcpy(genero,", Psicologico");break;
		case 9:strcpy(genero,", Musical");break;
		case 10:strcpy(genero,", Fantasia");break;
		case 11:strcpy(genero,", Super poderes");break;
		case 12:strcpy(genero,", Magia");break;
		case 13:strcpy(genero,", Ciencia ficcion");break;
		case 14:strcpy(genero,", Ecchi");break;
		case 15:strcpy(genero,", Hentai");break;
		case 16:strcpy(genero,", Recuerdos de la vida");break;
		case 17:strcpy(genero,", Mecha");break;
		case 18:strcpy(genero,", Accion");break;
		case 19:strcpy(genero,", Aventura");break;
		case 20:strcpy(genero,", Deportes");break;
		case 21:strcpy(genero,", Escolares");break;
		case 22:strcpy(genero,", Gore");break;
		case 23:strcpy(genero,", Horror");break;
		case 24:strcpy(genero,", Lucha");break;
		case 25:strcpy(genero,", Militar");break;
		case 26:strcpy(genero,", Historico");break;
		case 27:strcpy(genero,", Parodia");break;
		case 28:strcpy(genero,", Artes marciales");break;
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


