/*
	**AQUI SE ENCUENTRAN LAS FUNCIONES QUE SE UTILIZARAN
	DE MANERA GLOBAL EN NUESTRO PROGRAMA DE REGISTRO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "funciones_hobbi.h"
void menu(char *bin) {
	char c;int pos = 1,pos_submenu = 1;
	bool sub_menu = false,subsub_menu = false,mostrar = true,bucle = true;
	do {
		system("cls");
		system("color F0");
		//OPCION 1 LISTADO DE ANIMES MANGA
		if (pos == 1 && mostrar) {printf("%c  Ver listado de anime/manga\n",62);}
		else if(mostrar) {printf("1. Ver listado de anime/manga\n");}
			//SUBMENU DE LA OPCION 1 LISTADO DE ANIME/MANGA
		if(pos == 1 && sub_menu && mostrar) {
			if(pos_submenu == 1 && mostrar) {printf("\t%c  Ver todo el listado\n",62);}
			else if(mostrar) {{printf("\t1. Ver todo el listado\n");}};
			
			if(pos_submenu == 2 && mostrar) {printf("\t%c Ver solo mangas\n",62);}
			else if(mostrar) {printf("\t2. Ver solo mangas\n");}
			
			if(pos_submenu == 3 && mostrar) {printf("\t%c  Ver solo animes\n",62);}
			else if(mostrar) {printf("\t3. Ver solo animes\n");}
			
			if(pos_submenu == 4 && mostrar) {printf("\t%c Ver solo manhwas\n",62);}
			else if(mostrar) {printf("\t4. Ver solo manhwas\n");}
			
			if(pos_submenu == 5 && mostrar) {printf("\t%c  Por genero\n",62);}
			else if(mostrar){printf("\t5. Por genero\n");}
		}
		
		
		//OPCION 2 CREAR Y AGREGAR TIPO
		if (pos == 2 && mostrar) {printf("%c  Agregar anime/manga\n",62);}
		else if(mostrar) {printf("2. Agregar anime/manga\n");}
			//SUBMENU DE LA OPCION 2 CREAR Y AGREGAR TIPO
		if(pos == 2 && sub_menu && mostrar) {
			
		}
		
		//OPCION 3 MODIFICAR TIPO
		if(pos == 3 && mostrar) {printf("%c  Modificar anime/manga\n",62);}
		else if(mostrar) {printf("3. Modificar anime/manga\n");}
			//SUBMENU DE MODIFICAR TIPO
		if(pos == 3 && sub_menu && mostrar) {
			
		}
		
		
		//OPCION 4 ELIMINAR ANIME/MANGA
		if(pos == 4 && mostrar) {printf("%c Eliminar anime/manga\n",62);}
		else if(mostrar) {printf("4. Eliminar anime/manga\n");}
			//SUBMENU DE LA OPCIONN 4 ELIMINAR TIPO
		if(pos == 4 && sub_menu && mostrar) {
			submenu(bin,pos);
		}
		
		//OPCION 5 GENERAR ARCHIVO DE TEXTO
		if(pos == 5 && mostrar) {printf("%c  Generar archivo de texto\n",62);}
		else if(mostrar) {printf("5. Generar archivo de texto\n");}
		if(pos == 5 && sub_menu && mostrar) {
			
		}
		
		if(mostrar) {c = getch();}
		if( (c == 72 || c == 119 || c == 87) && mostrar) {
			if(!sub_menu) {
				pos--;
				if(pos < 1){pos = 5;}
			}
			else {
				pos_submenu--;
				if(pos == 1) { if(pos_submenu < 1) {pos_submenu = 5;} }
			}
		}
		else if( (c == 80 || c == 115 || c == 83) && mostrar) {
			if(!sub_menu) {
				pos++;
				if(pos > 5) {pos = 1;}
			}
			else {
				pos_submenu++;
				if(pos == 1) { if(pos_submenu > 5) {pos_submenu = 1;} }
			}
		}
		else if( (c == 100 || c == 68 || c == 77) && mostrar) {
			if(!sub_menu) {sub_menu = true;}
			else if(!subsub_menu) {subsub_menu = true;}
		}
		else if( (c == 27 && sub_menu || subsub_menu) && mostrar) {
			if(sub_menu) {sub_menu = false;}
			else {subsub_menu = false;}
		}
		else if(mostrar && c == 27) {bucle = false;}
		
		if(!mostrar) {mostrar = true;}
	}while(bucle);
}
void submenu(char *bin,int n) {
//	int pos = 0;char c;
//	int opc_1;
//	if(n == 1) {
//		
//		
//		printf("Opcion: ");fflush(stdin);
//		if(scanf("%i",&opc_1) == 0)
//			opc_1 = -1;
//		switch(opc_1) {
//			case 1:system("cls");
//				if(!mostrar_todo(bin))
//					printf("No hay nada registrado\n");
//				break;
//			case 2:strcpy(tipo,"Manga");break;
//			case 3:strcpy(tipo,"Anime");opc_1 = 2;break;
//			case 4:strcpy(tipo,"Manhwa");opc_1 = 2;break;
//			case 5:mostrar_genero(bin);break;
//			case 6:break;
//		}
//		if(opc_1 == 2) {
//			system("cls");
//			if(!mostrar(bin,tipo))
//				printf("No hay %ss registrados\n",tipo);
//		}
//		if(opc_1 >= 1 && opc_1 <= 5) {
//			printf("\n1.- Volver\n");
//			printf("2.- Salir\n");
//			do {
//				printf("Opcion: ");fflush(stdin);
//				if(scanf("%i",&opc_3) == 0)
//					opc_3 = -1;
//			}while(opc_3 != 1 && opc_3 != 2);
//			switch(opc_3) {
//				case 1:break;
//				case 2: opc_1 = 6;break;
//			}
//		}
//	}	
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
