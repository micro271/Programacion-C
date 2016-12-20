/*
		**Funciones que se utilizaran para agregar animes quitar reemplazar y organizar
		
		//
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "anime.h"
#include "funciones.h"

struct ANIME crear_anime(char *bin,char *txt) {
	struct ANIME aux;int i;
	int x;int y;
	system("cls");
	printf("Posicion: \n");
	printf("1.- Primero\n");
	printf("2.- Ultimo\n");
	printf("3.- Seleccionar una posicion\n");
	do {
		printf("Seleccione una opcion: ");
		scanf("%i",&y);
	}while(posicion_De_guardado(y,&aux.posicion,bin,txt));
	do {
		system("cls");
		printf("Posicion: %i\n",aux.posicion);
		printf("Nombre (0 para salir): ");fflush(stdin);
		fgets(aux.nombre,49,stdin);
		arreglar_fgets(aux.nombre);
		arreglar_espacios(aux.nombre);
		agregar_mayus(aux.nombre);
	}while(anime_existente(bin,aux.nombre));
	
	system("cls");
	printf("Posicion: %i\n",aux.posicion);
	printf("Nombre: %s\n",aux.nombre);
	printf("Autor/Mangaka: ");fflush(stdin);
	fgets(aux.mangaka,29,stdin);
	arreglar_fgets(aux.mangaka);
	arreglar_espacios(aux.mangaka);
	agregar_mayus(aux.mangaka);
	system("cls");
	printf("Nombre: %s\n",aux.nombre);
	printf("Autor/Mangaka: %s\n",aux.mangaka);
	strcpy(aux.genero,"");
	do {
		system("cls");
		printf("Posicion: %i\n",aux.posicion);
		printf("Nombre: %s\n",aux.nombre);
		printf("Autor/Mangaka: %s\n",aux.mangaka);
		printf("Genero: %s",aux.genero);
		printf("\n1.- Romance");
		printf("\n2.- Drama");
		printf("\n3.- Comedia");
		printf("\n4.- Harem");
		printf("\n5.- Psicologico");
		printf("\n6.- Musical");
		printf("\n7.- Fantasia");
		printf("\n8.- Super poderes");
		printf("\n9.- Magia");
		printf("\n10.- Ciencia ficcion");
		printf("\n11.- Ecchi");
		printf("\n12.- Hentai");
		printf("\n13.- Recuerdos de la vida");
		printf("\n14.- Mecha");
		printf("\n15.- Accion");
		printf("\n16.- Aventura");
		printf("\n17.- Deportes");
		printf("\n18.- Escolares");
		printf("\n19.- Gore");
		printf("\n20.- Horror");
		printf("\n21.- Lucha");
		printf("\n22.- Militar");
		printf("\n23.- Historico");
		printf("\n24.- Parodia");
		printf("\n0.- Salir\n");
		printf("Elija una opcion: ");fflush(stdin);
		scanf("%i",&x);
	}while(agregar_genero(aux.genero,x));
	return aux;
}

bool insertar_anime(char *bin,struct ANIME aux) {
	FILE *binario = fopen(bin,"ab");
	if(fwrite(&aux,sizeof(struct ANIME),1,binario) != 1) {
		fclose(binario);
		return true;
	}
	fclose(binario);
	return false;
}

bool imprimir_anime(char *txt) {
	FILE *fp = fopen(txt,"rt");
	if(fp == NULL) {
		return true;
	}
	fseek(fp,0,SEEK_END);
	if(ftell(fp) == 0) {
		fclose(fp);
		return true;
	}
	else {
		int c;
		fseek(fp,0,SEEK_SET);
		while ((c = fgetc(fp)) != EOF) {
			printf("%c",c);
		}
		fclose(fp);
		return false;
	}
}

int posicion_De_guardado(int y,int *posicion,char *bin,char *txt) {
	int bit,pos;
	FILE *fp = fopen(bin,"r");
	if(fp == NULL) {
		switch(y) {
			case 1:*posicion = 1;return 0;
			case 2:*posicion = 1;return 0;
			default:return 1;
		}
	}
	else {
		fseek(fp,0,SEEK_END);
		bit = ftell(fp);
		if(bit == 0) {
			switch(y) {
				case 1:*posicion = 1;return 0;
				case 2:*posicion = 1;return 0;
				default:return 1;
			}
		}
		else {
			int k;
			int i;struct ANIME *aux;
			pos = bit/sizeof(struct ANIME);
			switch(y) {
				case 1:*posicion = 1;
					fseek(fp,0,SEEK_SET);
					aux = (struct ANIME *)malloc(sizeof(struct ANIME)*pos);
					fread(aux,sizeof(struct ANIME),pos,fp);
					for(i = 0; i < pos; i++) {
						(aux+i)->posicion++;
					}
					system("pause");
					fclose(fp);
					fp = fopen(bin,"wb");
					fwrite(aux,sizeof(struct ANIME),pos,fp);
					free(aux);fclose(fp);
					return 0;
				case 2:*posicion = pos+1;return 0;
				case 3:system("cls");
					if(imprimir_anime(txt))printf("\tNo hay animes registrados\n");
					printf("Posicion: ");fflush(stdin);
					scanf("%i",&k);
					if(k <= 1) {
						*posicion = 1;
						fseek(fp,0,SEEK_SET);
						aux = (struct ANIME *)malloc(sizeof(struct ANIME)*pos);
						fread(aux,sizeof(struct ANIME),pos,fp);
						for(i = 0; i < pos; i++) {
							(aux+i)->posicion++;
						}
						fclose(fp);
						fp = fopen(bin,"wb");
						fwrite(aux,sizeof(struct ANIME),pos,fp);
						free(aux);fclose(fp);
						return 0;
					}
					else if(k >= pos+1) {
						*posicion = pos+1;
						return 0;
					}
					else{
						*posicion = k;
						aux = (struct ANIME *)malloc(sizeof(struct ANIME)*pos);
						fseek(fp,0,SEEK_SET);
						fread(aux,sizeof(struct ANIME),pos,fp);
						for(i = 0; i < pos; i++) {
							if((aux+i)->posicion >= k) {
								(aux+i)->posicion++;
							}
						}
						fclose(fp);
						fp = fopen(bin,"wb");
						fwrite(aux,sizeof(struct ANIME),pos,fp);
						free(aux);fclose(fp);
						return 0;
					}
				default:return 1;
			}
		}
	}
}
bool organizar_animes(char *bin,char *txt) {
	FILE *binario = fopen(bin,"rb");
	if(binario == NULL) {
		printf("Error al habrir el archibo %s",bin);
		return true;
	}
	struct ANIME *aux,aux_dos;
	int bits;int i;int k;int pos;int n;
	fseek(binario,0,SEEK_END);
	bits = ftell(binario);
	n = bits/sizeof(struct ANIME);
	fseek(binario,0,SEEK_SET);
	aux = (struct ANIME *)malloc(sizeof(struct ANIME)*n);
	fread(aux,sizeof(struct ANIME),n,binario);
	fclose(binario);
	
	if(bits == 0) {
		free(aux);
		return true;
	}
	for(i = 0; i < n; i++) {
		
		for(k = i; (aux+k)->posicion < (aux+(k-1))->posicion && k > 0; k--) {			
			strncpy(aux_dos.nombre,(aux+k)->nombre,strlen((aux+k)->nombre)+1);
			strncpy(aux_dos.genero,(aux+k)->genero,strlen((aux+k)->genero)+1);
			strncpy(aux_dos.mangaka,(aux+k)->mangaka,strlen((aux+k)->mangaka)+1);
			aux_dos.posicion = (aux+k)->posicion;
			
			strncpy((aux+k)->nombre,(aux+(k-1))->nombre,strlen((aux+(k-1))->nombre)+1);
			strncpy((aux+k)->genero,(aux+(k-1))->genero,strlen((aux+(k-1))->genero)+1);
			strncpy((aux+k)->mangaka,(aux+(k-1))->mangaka,strlen((aux+(k-1))->mangaka)+1);
			(aux+k)->posicion = (aux+(k-1))->posicion;
			
			strncpy((aux+(k-1))->nombre,aux_dos.nombre,strlen(aux_dos.nombre)+1);
			strncpy((aux+(k-1))->genero,aux_dos.genero,strlen(aux_dos.genero)+1);
			strncpy((aux+(k-1))->mangaka,aux_dos.mangaka,strlen(aux_dos.mangaka)+1);
			(aux+(k-1))->posicion = aux_dos.posicion;
		}
	}
	insertar_anime_txt(aux,txt,n);
	free(aux);
	return false;
}

void insertar_anime_txt(struct ANIME *aux,char *txt,int p) {
	FILE *fp = fopen(txt,"wt");
	int i = 0;
	while(i < p) {
		fprintf(fp,"%i.- Nombre: %s\t\tGenero: %s \t\tMangaka: %s\n",(aux+i)->posicion,(aux+i)->nombre,(aux+i)->genero,(aux+i)->mangaka);
		i++;
	}
	fclose(fp);
}

bool anime_existente(char *bin,char *txt) {
	FILE *fp = NULL;
	fp = fopen(bin,"rb");
	if (fp == NULL) {
		return false;
	}
	else {
		struct ANIME *aux;int i;
		fseek(fp,0,SEEK_END);
		int bit = ftell(fp)/sizeof(struct ANIME);
		aux = (struct ANIME *)malloc(sizeof(struct ANIME)*bit);
		if(aux == NULL) {
			printf("\nNo hay espacio en memoria\n");exit(EXIT_FAILURE);
		}
		fseek(fp,0,SEEK_SET);
		fread(aux,sizeof(struct ANIME),bit,fp);
		fclose(fp);
		for (i = 0; i < bit; i++) {
			if(strcmp((aux+i)->nombre,txt) == 0) {
				free(aux);
				return true;
			}
		}
		free(aux);
		return false;
	}
}

int modificar_anime(char *bin,char *txt) {
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		return 1;
	}
	struct ANIME *aux;
	char nombre[50];
	int bits,cont,i,opc,pos_n,m,opc_2,pos_new;
	fseek(fp,0,SEEK_END);
	bits = ftell(fp);
	cont = ftell(fp)/sizeof(struct ANIME);
	fseek(fp,0,SEEK_SET);
	if(bits == 0) {
		fclose(fp);
		return 1;
	}
	system("cls");
	imprimir_anime(txt);printf("\n");
	printf("Nombre: ");fflush(stdin);
	fgets(nombre,49,stdin);
	arreglar_fgets(nombre);
	arreglar_espacios(nombre);
	agregar_mayus(nombre);
	printf("Nombre: %s",nombre);
	aux = (struct ANIME *)malloc(sizeof(struct ANIME)*cont);
	if(aux == NULL) {
		printf("\nNo hay espacio en memoria\n");exit(EXIT_FAILURE);
	}
	fread(aux,sizeof(struct ANIME),cont,fp);
	fclose(fp);
	i = 0;
	pos_n = 0;
	while(i < cont) {
		if(strcmp((aux+i)->nombre,nombre) == 0) {
			m = i;
			pos_n++;
			break;
		}
		i++;
	}
	if(pos_n == 0) {
		free(aux);
		fclose(fp);
		return 1;
	}
	do {
		system("cls");
		imprimir_anime(txt);printf("\n");
		printf("Posicion: %i\n",(aux+m)->posicion);
		printf("Nombre: %s\n",(aux+m)->nombre);
		printf("Genero: %s\n",(aux+m)->genero);
		printf("Mangaka: %s\n\n",(aux+m)->mangaka);
		printf("1.- Posicion\n");
		printf("2.- Nombre\n");
		printf("3.- Genero\n");
		printf("4.- Mangaka\n");
		printf("0.- Volver y Guardar datos\n");
		printf("Opcion: ");fflush(stdin);
		scanf("%i",&opc_2);
		if(opc_2 == 1) {
			system("cls");
			imprimir_anime(txt);printf("\n");
			do {
				printf("Elige una posicion: ");fflush(stdin);
				scanf("%i",&pos_new);
			}while(pos_new < 1 || pos_new > cont);
			
			for(i = 0; i < cont; i++) {
				if((aux+i)->posicion > (aux+m)->posicion) {
					(aux+i)->posicion--;
				}
			}
			(aux+m)->posicion = -1;
			for(i = 0; i < cont; i++) {
				if((aux+i)->posicion >= pos_new) {
					(aux+i)->posicion++;
				}
			}
			(aux+m)->posicion = pos_new;	
		}
		else if(opc_2 == 2) {
			system("cls");
			printf("Nombre actual: %s\n",(aux+m)->nombre);
			printf("Nombre nuevo: ");fflush(stdin);
			fgets(nombre,49,stdin);
			arreglar_fgets(nombre);
			arreglar_espacios(nombre);
			agregar_mayus(nombre);
			strncpy((aux+m)->nombre,nombre,strlen(nombre)+1);
		}
		else if(opc_2 == 3) {
			int x;
			strcpy((aux+m)->genero,"");
			do {
				system("cls");
				printf("Nombre: %s\n",(aux+m)->nombre);
				printf("Genero: %s",(aux+m)->genero);
				printf("\n1.- Romance");
				printf("\n2.- Drama");
				printf("\n3.- Comedia");
				printf("\n4.- Harem");
				printf("\n5.- Psicologico");
				printf("\n6.- Musical");
				printf("\n7.- Fantasia");
				printf("\n8.- Super poderes");
				printf("\n9.- Magia");
				printf("\n10.- Ciencia ficcion");
				printf("\n11.- Ecchi");
				printf("\n12.- Hentai");
				printf("\n13.- Recuerdos de la vida");
				printf("\n14.- Mecha");
				printf("\n15.- Accion");
				printf("\n16.- Aventura");
				printf("\n17.- Deportes");
				printf("\n18.- Escolares");
				printf("\n19.- Gore");
				printf("\n20.- Horror");
				printf("\n21.- Lucha");
				printf("\n22.- Militar");
				printf("\n23.- Historico");
				printf("\n24.- Parodia");
				printf("\n0.- Salir\n");
				printf("Elija una opcion: ");fflush(stdin);
				scanf("%i",&x);
			}while(agregar_genero((aux+m)->genero,x));
		}
		else if(opc_2 == 4) {
			system("cls");
			printf("Mangaka -actual: %s\n",(aux+m)->mangaka);
			printf("Mangaka -nuevo: ");fflush(stdin);
			fgets(nombre,49,stdin);
			arreglar_fgets(nombre);
			arreglar_espacios(nombre);
			agregar_mayus(nombre);
			strncpy((aux+m)->mangaka,nombre,strlen(nombre)+1);
		}
		else if(opc_2 == 0) {
			fp = fopen(bin,"wb");
			fwrite(aux,sizeof(struct ANIME),cont,fp);
			free(aux);
			fclose(fp);
			break;
		}
		else {
			opc_2 = 10;
		}
	}while(opc_2 != 0);
	return 0;
}

int eliminar_anime(char *bin,char *txt) {
	FILE *fp_bin = fopen(bin,"rb"),*fp_txt = NULL;
	if(fp_bin == NULL) {
		return 3;
	}
	struct ANIME *anime,*aux_anime,aux;
	int bits,cont,i,k,m;
	char nombre[50],preg;
	fseek(fp_bin,0,SEEK_END);
	bits = ftell(fp_bin);
	cont = bits/sizeof(struct ANIME);
	if(bits == 0) {
		fclose(fp_bin);
		return 3;
	}
	fseek(fp_bin,0,SEEK_SET);
	anime = (struct ANIME *)malloc(sizeof(struct ANIME)*cont);
	fread(anime,sizeof(struct ANIME),cont,fp_bin);
	fclose(fp_bin);//CERRAMOS AQUI EL FICHERO YA QUE NO LO NECESIATMOS MAS
	imprimir_anime(txt);printf("\n");
	printf("Nombre (0 para salir): ");fflush(stdin);
	fgets(nombre,49,stdin);
	if(nombre[0] == '0' && nombre[1] == '\n') {
		free(anime);
		return 0;
	}
	arreglar_fgets(nombre);
	arreglar_espacios(nombre);
	agregar_mayus(nombre);
	m = -1;
	for(i = 0; i < cont; i++) {
		if(strcmp((anime+i)->nombre,nombre) == 0) {
			m = i;system("pause");
			break;
		}
	}
	if(m == -1) {
		free(anime);
		return 1;
	}
	do {
		printf("Quiere eliminar el anime \"%s\" (s/n): ",(anime+m)->nombre);fflush(stdin);
		scanf("%c",&preg);
		preg = tolower(preg);
	}while(preg != 'n' && preg != 's');
	if(preg == 'n') {
		free(anime);return 0;
	}
	k = 0;aux_anime = NULL;
	for(i = 0; i < cont; i++) {
		if((anime+i)->posicion != (anime+m)->posicion) {
			aux_anime = (struct ANIME *)realloc(aux_anime,sizeof(struct ANIME)*(k+1));
			if(aux_anime == NULL) {
				printf("\nNo hay espacio en memoria\n\n");exit(EXIT_FAILURE);
			}
			strncpy( (aux_anime+k)->nombre, (anime+i)->nombre, strlen( (anime+i)->nombre ) +1);
			strncpy( (aux_anime+k)->genero, (anime+i)->genero, strlen( (anime+i)->genero ) +1);
			strncpy( (aux_anime+k)->mangaka, (anime+i)->mangaka, strlen( (anime+i)->mangaka ) +1);
			(aux_anime+k)->posicion = (anime+i)->posicion;
			k++;
		}
	}
	if(aux_anime == NULL) {
		fp_bin = fopen(bin,"wb");
		fclose(fp_bin);
		free(anime);
		fp_txt = fopen(txt,"wt");
		fclose(fp_txt);
		return 0;
	}
	cont--;
	for(i = 0; i < cont; i++) {
		if((aux_anime+i)->posicion > (anime+m)->posicion) {
			(aux_anime+i)->posicion--;
		}
	}
	free(anime);anime = NULL;//LIBERAMOS LA MEMORIA Y LO COLOCAMOS EN NULL
	if(cont > 1) {
		for(i = 0; i < cont; i++) {
			for(k = i; (aux_anime+k)->posicion < (aux_anime+(k-1))->posicion && k > 0; k--) {
				strncpy( aux.nombre, (aux_anime+(k-1))->nombre, strlen( (aux_anime+(k-1))->nombre ) +1);
				strncpy( aux.genero, (aux_anime+(k-1))->genero, strlen( (aux_anime+(k-1))->genero ) +1);
				strncpy( aux.mangaka, (aux_anime+(k-1))->mangaka, strlen( (aux_anime+(k-1))->mangaka ) +1);
				aux.posicion = (aux_anime+(k-1))->posicion;
				
				strncpy( (aux_anime+(k-1))->nombre, (aux_anime+k)->nombre, strlen( (aux_anime+k)->nombre ) +1);
				strncpy( (aux_anime+(k-1))->genero, (aux_anime+k)->genero, strlen( (aux_anime+k)->genero ) +1);
				strncpy( (aux_anime+(k-1))->mangaka, (aux_anime+k)->mangaka, strlen( (aux_anime+k)->mangaka ) +1);
				(aux_anime+(k-1))->posicion = (aux_anime+k)->posicion;
				
				strncpy( (aux_anime+k)->nombre, aux.nombre, strlen(aux.nombre) +1);
				strncpy( (aux_anime+k)->genero, aux.genero, strlen(aux.genero) +1);
				strncpy( (aux_anime+k)->mangaka, aux.mangaka, strlen(aux.mangaka) +1);
				(aux_anime+k)->posicion = aux.posicion;
			}
		}
	}
	fp_bin = fopen(bin,"wb+");
	fwrite(aux_anime,sizeof(struct ANIME),cont,fp_bin);
	fclose(fp_bin);
	fp_txt = fopen(txt,"wt");
	for(i = 0; i < cont; i++) {
		fprintf(fp_txt,"%i.- Nombre: %s\t\tGenero: %s \t\tMangaka: %s\n",(aux_anime+i)->posicion,(aux_anime+i)->nombre,(aux_anime+i)->genero,(aux_anime+i)->mangaka);
	}
	fclose(fp_txt);
	free(aux_anime);
	return 0;
}

bool buscar_anime(char *bin,char *txt,int n) {
	if(n != 1 && n != 2) {
		return true;
	}
	struct ANIME *anime,*anime_aux,aux;
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		system("cls");
		printf("No hay animes registrados\n\n");
		return false;
	}
	int bits,cont,i,k,g,a,h,l;char nombre[50],genero[30];
	fseek(fp,0,SEEK_END);
	bits = ftell(fp);
	cont = bits/sizeof(struct ANIME);
	anime = (struct ANIME *)malloc(sizeof(struct ANIME)*cont);
	if(anime == NULL) {
		printf("No hay espacio en memoria\n\n");
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	fseek(fp,0,SEEK_SET);
	fread(anime,sizeof(struct ANIME),cont,fp);
	fclose(fp);
	
	if(n == 2) {
		system("cls");
		printf("Ingrese el nombre del anime, 0 para salir\n");
		printf("Nombre: ");fflush(stdin);
		fgets(nombre,49,stdin);
		if(nombre[0] == '0' && nombre[1] == '\n') {
			free(anime);
			return false;
		}
		arreglar_fgets(nombre);
		arreglar_espacios(nombre);
		agregar_mayus(nombre);
		for(i = 0; i < cont; i++) {
			if(strcmp( (anime+i)->nombre, nombre ) == 0) {
				system("cls");
				printf("Posicion: %i\n",(anime+i)->posicion);
				printf("Nombre: %s\n",(anime+i)->nombre);
				printf("Genero: %s\n",(anime+i)->genero);
				printf("Mangaka: %s\n",(anime+i)->mangaka);
				break;
			}
		}
	}
	else if(n == 1) {
		do {
			anime_aux = NULL;
			a = 0;
			system("cls");
			printf("1.- Romance");
			printf("\n2.- Drama");
			printf("\n3.- Comedia");
			printf("\n4.- Harem");
			printf("\n5.- Psicologico");
			printf("\n6.- Musical");
			printf("\n7.- Fantasia");
			printf("\n8.- Super poderes");
			printf("\n9.- Magia");
			printf("\n10.- Ciencia ficcion");
			printf("\n11.- Ecchi");
			printf("\n12.- Hentai");
			printf("\n13.- Recuerdos de la vida");
			printf("\n14.- Mecha");
			printf("\n15.- Accion");
			printf("\n16.- Aventura");
			printf("\n17.- Deportes");
			printf("\n18.- Escolares");
			printf("\n19.- Gore");
			printf("\n20.- Horror");
			printf("\n21.- Lucha");
			printf("\n22.- Militar");
			printf("\n23.- Historico");
			printf("\n24.- Parodia");
			printf("\n0.- Salir\n\n");
			printf("Opcion: ");fflush(stdin);
			scanf("%i",&g);
			switch(g) {
				case 0: break;
				case 1:strcpy(genero,"Romance");g = 1;break;
				case 2:strcpy(genero,"Drama");g = 1;break;
				case 3:strcpy(genero,"Comedia");g = 1;break;
				case 4:strcpy(genero,"Harem");g = 1;break;
				case 5:strcpy(genero,"Psicologico");g = 1;break;
				case 6:strcpy(genero,"Musical");g = 1;break;
				case 7:strcpy(genero,"Fantasia");g = 1;break;
				case 8:strcpy(genero,"Super poderes");g = 1;break;
				case 9:strcpy(genero,"Magia");g = 1;break;
				case 10:strcpy(genero,"Ciencia ficcion");g = 1;break;
				case 11:strcpy(genero,"Ecchi");g = 1;break;
				case 12:strcpy(genero,"Hentai");g = 1;break;
				case 13:strcpy(genero,"Recuerdos de la vida");g = 1;break;
				case 14:strcpy(genero,"Mecha");g = 1;break;
				case 15:strcpy(genero,"Accion");g = 1;break;
				case 16:strcpy(genero,"Aventura");g = 1;break;
				case 17:strcpy(genero,"Deportes");g = 1;break;
				case 18:strcpy(genero,"Escolares");g = 1;break;
				case 19:strcpy(genero,"Gore");g = 1;break;
				case 20:strcpy(genero,"Horror");g = 1;break;
				case 21:strcpy(genero,"Lucha");g = 1;break;
				case 22:strcpy(genero,"Militar");g = 1;break;
				case 23:strcpy(genero,"Historia");g = 1;break;
				case 24:strcpy(genero,"Parodia");g = 1;break;
				default: g = 10;
			}
			if(g == 1) {
				for(i = 0; i < cont; i++) {
					if(strstr((anime+i)->genero,genero) != NULL) {
						anime_aux = (struct ANIME *)realloc(anime_aux,sizeof(struct ANIME)*(a+1));
						strncpy( (anime_aux+a)->nombre, (anime+i)->nombre, strlen( (anime+i)->nombre ) +1);
						strncpy( (anime_aux+a)->genero, (anime+i)->genero, strlen( (anime+i)->genero ) +1);
						strncpy( (anime_aux+a)->mangaka, (anime+i)->mangaka, strlen( (anime+i)->mangaka ) +1);
						(anime_aux+a)->posicion = (anime+i)->posicion;
						a++;
					}
				}
				if(a == 0) {
					printf("\nNo hay ningun anime con el genero %s",genero);
					g = 0;
				}
				else {
					for(i = 0; i < a; i++) {
						for(h = i; (anime_aux+h)->posicion < (anime_aux+(h-1))->posicion && h > 0; h--) {
							strncpy( aux.nombre, (anime_aux+h)->nombre, strlen( (anime_aux+h)->nombre ) +1);
							strncpy( aux.genero, (anime_aux+h)->genero, strlen( (anime_aux+h)->genero ) +1);
							strncpy( aux.mangaka, (anime_aux+h)->mangaka, strlen( (anime_aux+h)->mangaka ) +1);
							aux.posicion = (anime_aux+h)->posicion;
							
							strncpy( (anime_aux+h)->nombre, (anime_aux+(h-1))->nombre, strlen( (anime_aux+(h-1))->nombre ) +1);
							strncpy( (anime_aux+h)->genero, (anime_aux+(h-1))->genero, strlen( (anime_aux+(h-1))->genero ) +1);
							strncpy( (anime_aux+h)->mangaka, (anime_aux+(h-1))->mangaka, strlen( (anime_aux+(h-1))->mangaka +1) );
							(anime_aux+h)->posicion = (anime_aux+(h-1))->posicion;
							
							strncpy( (anime_aux+(h-1))->nombre, aux.nombre, strlen( aux.nombre ) +1);
							strncpy( (anime_aux+(h-1))->genero, aux.genero, strlen( aux.genero ) +1);
							strncpy( (anime_aux+(h-1))->mangaka, aux.mangaka, strlen( aux.mangaka ) +1);
							(anime_aux+(h-1))->posicion = aux.posicion;
						}
					}
					do {
						system("cls");
						for(i = 0; i < a; i++) {
							printf("Posicion: %i\tNombre: %s\t\tGenero: %s\t\tMangaka: %s\n",(anime_aux+i)->posicion,(anime_aux+i)->nombre,(anime_aux+i)->genero,(anime_aux+i)->mangaka);
						}
						printf("\n1.- Atras\n");
						printf("2.- Volver al inicio\n");
						printf("Opcion: ");fflush(stdin);
						scanf("%i",&l);
					}while(l != 1 && l != 2);
					switch(l) {
						case 1: break;
						case 2: 
							g = 0;system("cls");
							break;
					}									
					free(anime_aux);
					anime_aux = NULL;
				}
			}
		}while(g != 0);
		free(anime);
		return false;
	}
}
