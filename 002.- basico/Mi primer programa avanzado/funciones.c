/*
	AQUIS E ENCONTRARAN LAS FUNCIONES ESTANDAR O GENERALES QUE SE UTILIZARAN
	EN TODO EL PROGRAMA COMO EL MENU.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "registro.h"
#include "funciones.h"
//MENU PRINCIPAL DEL PROGRAMA
void menu(char *bin) {
	int submenu = 0,acc,f,acc_fn,pos_submenu = 1,pos = 1,salir = 0;
	bool entrar = true;char tipo[12],txt[30];
	do {
		f=0;
		system("cls");
		//POSICION 1 DEL MENU PRINCIPAL VER UN LISTADO
		if(pos == 1) {printf("%c  Ver listado\n\r",62);}
		else {printf("1. Ver listado\n\r");}
				//POSICION 1 DEL MENU PRINCIPAL VER LISTADO > SUBMENU VER UN LISTADO EN EPECIFICO 
				if(submenu == 1 && pos == 1) {
					if(pos_submenu == 1) {printf("\t%c  Ver todo el listado\n",62);}
					else {printf("\t1. Ver todo el listado\n",62);}
					
					if(pos_submenu == 2) {printf("\t%c  Ver solo mangas\n",62);}
					else {printf("\t2. Ver solo mangas\n");}
					
					if(pos_submenu == 3) {printf("\t%c  Ver solo animes\n",62);}
					else {printf("\t3. Ver solo animes\n");}
					
					if(pos_submenu == 4) {printf("\t%c  Ver solo manhwas\n",62);}
					else {printf("\t4. Ver solo manhwas\n");}
					
					if(pos_submenu == 5) {printf("\t%c  Ver solo doujinshis\n",62);}
					else {printf("\t5. Ver solo doujinshis\n");}
					
					if(pos_submenu == 6) {printf("\t%c  Por genero\n",62);}
					else {printf("\t6. Por genero\n");}
				}
		//POSICION 2 SEL MENU PRINCIPAL AGREGAR ALGUN TIPO
		if(pos == 2) {printf("%c  Agregar\n\r",62);} 
		else {printf("2. Agregar\n\r");}
		
				if(submenu == 1 && pos == 2) {
					if(pos_submenu == 1) {printf("\t%c  Anime\n",62);}
					else {printf("\t1. Anime\n");}
					
					if(pos_submenu == 2) {printf("\t%c  Manga\n",62);}
					else {printf("\t2. Manga\n");}
					
					if(pos_submenu == 3) {printf("\t%c  Manhwa\n",62);}
					else {printf("\t3. Manhwa\n");}
					
					if(pos_submenu == 4) {printf("\t%c  Doujinshi\n",62);}
					else {printf("\t4. Doujinshi\n");}
				}
		if(pos == 3) {printf("%c  Modificar tipo\n",62);}
		else {printf("3. Modificar tipo\n");}
				
				if(submenu == 1 && pos == 2) {/*EN ESPERA*/}

		
		if(pos == 4) {printf("%c  Eliminar elemento\n",62);}
		else {printf("4. Eliminar elemento\n");}
				//NO TENEMOS SUBMENU
			
		if(pos == 5) {printf("%c  Generar archivo txt\n",62);}
		else {printf("5. Generar archivo txt\n");}
		
		//ENTRAREMOS AQUI MIENTRAS ESTE PERMITIDO
		if(entrar) {
			fflush(stdin);acc = getch();if(acc == 224) {f = getch();}
			if(acc == 115 || acc == 83 || f == 80) {//VAJAMOS EL PUNTERO EN EL LISTADO
				if(submenu == 0) {
					pos++;
					if(pos > 5) {pos = 1;}
				}
				else {
					pos_submenu++;
					if(pos == 1 && submenu == 1) {if(pos_submenu > 6) {pos_submenu = 1;}}
					if(pos == 2 && submenu == 1) {if(pos_submenu > 4) {pos_submenu = 1;}}
				}
			}
			else if(f == 72 || acc == 119 || acc == 87) {//SUBIMOS EL PUNTERO EN EL LISTADO
				if(submenu == 0) {
					pos--;
					if(pos < 1) {pos = 5;}
				}
				else {
					pos_submenu--;
					if(pos == 1 && submenu == 1) {if(pos_submenu < 1) {pos_submenu = 6;}}
					if(pos == 2 && submenu == 1) {if(pos_submenu < 1) {pos_submenu = 4;}}
				}
			}
			else if(f == 75 || acc == 97 || acc == 65 || acc == 27) {//VOLVEMOS PARA ATRAS EN EL LISTADO
				if(submenu == 0 && acc == 27) {salir = 1;}
				else if(pos == 1 || pos == 2 || pos == 4) {if(submenu == 1) {submenu--;pos_submenu = 1;}}
			}
			else if(acc == 13 || acc == 100 || acc == 68 || f == 77) {//HABRIMOS EL SUBMENU
				if(pos == 1 || pos == 2) {
					if(submenu < 2) {submenu++;}
					if(submenu == 2) {entrar = false;}
				}
				else if(pos == 4 || pos == 5) {submenu++;entrar = false;}
			}
		}
		//SUB MENU && POS 1
		if(submenu == 2 && pos == 1) {
			if(pos_submenu == 1) {
				do {
					system("cls");
					if(!view_all(bin)) {printf("No hay nada registrado\n");}
					printf("\nENTER para volver");
					fflush(stdin);acc_fn = getch();
				}while(acc_fn != 13);
				submenu--;
				entrar = true;
			}
			else if(pos_submenu >= 2 && pos_submenu < 6) {
				if(pos_submenu == 2) {strcpy(tipo,"Manga");}
				else if(pos_submenu == 3) {strcpy(tipo,"Anime");}
				else if(pos_submenu == 4) {strcpy(tipo,"Manhwa");}
				else if(pos_submenu == 5) {strcpy(tipo,"Doujinshi");}
				do {
					system("cls");
					if(!view_tipo(bin,tipo)) {printf("No hay %ss registrado\n",tipo);}
					printf("\nENTER para volver");
					fflush(stdin);acc_fn = getch();
				}while(acc_fn != 13);
				submenu--;
				entrar = true;
			}
			else {//FALTA COLOCAR LA FUNCION DE LA POSICION 6
			}
		}
		else if(submenu == 2 && pos == 2) {
			if(pos_submenu == 1) {strcpy(tipo,"Anime");}
			else if(pos_submenu == 2) {strcpy(tipo,"Manga");}
			else if(pos_submenu == 3) {strcpy(tipo,"Manhwa");}
			else if(pos_submenu == 4) {strcpy(tipo,"Doujinshi");}
			new_reg(bin,tipo);
			entrar = true;
			submenu--;
		}
		else if(submenu == 1 && pos == 4) {
			eliminar_elemento(bin);
			entrar = true;
			submenu--;
		}
		else if(submenu == 1 && pos == 5) {
			system("cls");
			generar_txt(bin);
			entrar = true;submenu--;
		}
	}while(salir != 1);
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
