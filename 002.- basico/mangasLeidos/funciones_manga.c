/*
		**Aqui se encontrara la funciones que llevara a cabo el programa orientado al manga con respecto a
		la eliminacion modificacion e implementacion de mangas del programa hacia el fichero
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "funciones.h"
#include "funciones_manga.h"

bool mostrar_todo(char *bin) {
	FILE *fp = fopen(bin,"rb");int i;
	if(fp == NULL) {
		return false;
	}
	struct MANGA_ANIME *el;
	int bits,cont;
	fseek(fp,0,SEEK_END);
	bits = ftell(fp);
	if(bits == 0) {
		fclose(fp);
		return false;
	}
	fseek(fp,0,SEEK_SET);
	cont = bits/sizeof(struct MANGA_ANIME);
	el = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
	fread(el,sizeof(struct MANGA_ANIME),cont,fp);
	fclose(fp);//CERRAMOS EL FICHERO
	for(i = 0; i < cont; i++) {
		printf("%i.- Tipo: %s\t Nombre: %s\t Genero: %s\t Mangaka: %s\n",(el+i)->posicion,(el+i)->tipo,(el+i)->nombre,(el+i)->genero,(el+i)->autor);
	}
	return true;
}


bool mostrar(char *bin,char *tipo) {
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		return false;
	}
	struct MANGA_ANIME *el;
	int i,bits,cont,cont_2;
	fseek(fp,0,SEEK_END);
	bits = ftell(fp);
	if(bits == 0) {
		fclose(fp);return false;
	}
	cont = bits/sizeof(struct MANGA_ANIME);
	el = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
	fseek(fp,0,SEEK_SET);
	fread(el,sizeof(struct MANGA_ANIME),cont,fp);
	fclose(fp);//CERRAMOS EL FICHERO Q NO VAMOS A USAR MAS
	cont_2 = 0;
	for(i = 0; i < cont; i++) {
		if(strcmp((el+i)->tipo,tipo) == 0) {
			printf("%i.- Nombre %s\t Genero: %s\t Mangaka: %s\n",(el+i)->posicion,(el+i)->nombre,(el+i)->genero,(el+i)->autor);
			cont_2++;
		}
	}
	free(el);
	if(cont_2 == 0) {
		return false;
	}
	return true;
}

bool mostrar_genero(char *bin){
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		return false;
	}
	struct MANGA_ANIME *el;
	int i,cont,cont_2,bits,opc;char genero[30];
	fseek(fp,0,SEEK_END);
	bits = ftell(fp);
	if(bits == 0) {
		fclose(fp);
		return false;
	}
	cont = bits/sizeof(struct MANGA_ANIME);
	fseek(fp,0,SEEK_SET);
	fread(el,sizeof(struct MANGA_ANIME),cont,fp);
	fclose(fp);//CERRAMOS EL FICHERO QUE YA NO SE UTILIZARA
	do {
		system("cls");
		printf("\n1.- Romance");
		printf("\n2.- Yuri");
		printf("\n3.- Drama");
		printf("\n4.- Comedia");
		printf("\n5.- Harem");
		printf("\n6.- Yaoi");
		printf("\n7.- Demonios");
		printf("\n8.- Psicologico");
		printf("\n9.- Musical");
		printf("\n10.- Fantasia");
		printf("\n11.- Super poderes");
		printf("\n12.- Magia");
		printf("\n13.- Ciencia ficcion");
		printf("\n14.- Ecchi");
		printf("\n15.- Hentai");
		printf("\n16.- Recuerdos de la vida");
		printf("\n17.- Mecha");
		printf("\n18.- Accion");
		printf("\n19.- Aventura");
		printf("\n20.- Deportes");
		printf("\n21.- Escolares");
		printf("\n22.- Gore");
		printf("\n23.- Horror");
		printf("\n24.- Lucha");
		printf("\n25.- Militar");
		printf("\n26.- Historico");
		printf("\n27.- Parodia");
		printf("\n28.- Artes marciales");
		printf("Opcion: ");fflush(stdin);
		scanf("%i",&opc);
		switch(opc) {
			case 1:strcpy(genero,"Romance");break;
			case 2:strcpy(genero,"Yuri");break;
			case 3:strcpy(genero,"Drama");break;
			case 4:strcpy(genero,"Comedia");break;
			case 5:strcpy(genero,"Harem");break;
			case 6:strcpy(genero,"Yaoi");break;
			case 7:strcpy(genero,"Demonios");break;
			case 8:strcpy(genero,"Psicologico");break;
			case 9:strcpy(genero,"Musical");break;
			case 10:strcpy(genero,"Fantasia");break;
			case 11:strcpy(genero,"Super poderes");break;
			case 12:strcpy(genero,"Magia");break;
			case 13:strcpy(genero,"Ciencia ficcion");break;
			case 14:strcpy(genero,"Ecchi");break;
			case 15:strcpy(genero,"Hentai");break;
			case 16:strcpy(genero,"Recuerdos de la vida");break;
			case 17:strcpy(genero,"Mecha");break;
			case 18:strcpy(genero,"Accion");break;
			case 19:strcpy(genero,"Aventura");break;
			case 20:strcpy(genero,"Deportes");break;
			case 21:strcpy(genero,"Escolares");break;
			case 22:strcpy(genero,"Gore");break;
			case 23:strcpy(genero,"Horror");break;
			case 24:strcpy(genero,"Lucha");break;
			case 25:strcpy(genero,"Militar");break;
			case 26:strcpy(genero,"Historico");break;
			case 27:strcpy(genero,"Parodia");break;
			case 28:strcpy(genero,"Artes marciales");break;
			default: opc = 0;
		}		
	}while(opc == 0);
	cont_2 = 0;
	for(i = 0; i < cont; i++) {
		if( strstr( (el+i)->genero,genero ) != NULL) {
			printf("%i.-\t Nombre %s \t Genero: %s \t Mangaka: %s\n",(el+i)->posicion,(el+i)->nombre,(el+i)->genero,(el+i)->autor);
			cont_2++;
		}
	}
	free(el);
	if(cont_2 == 0) {
		return false;
	}
	return true;
}

int crear(char *bin,char *tipo) {
	FILE *fp = fopen(bin,"rb");
	struct MANGA_ANIME nuevo;
	int x,i,p,cont;
	fseek(fp,0,SEEK_END);
	cont = ftell(fp)/sizeof(struct MANGA_ANIME);
	fclose(fp);//cerramos el fichero	
	strncpy( nuevo.tipo, tipo, strlen(tipo) +1);
	do {
		system("cls");
		printf("Coloque 0 para volver\n");
		printf("Nombre: ");fflush(stdin);
		fgets(nuevo.nombre,29,stdin);
		arreglar_fgets(nuevo.nombre);
		arreglar_espacios(nuevo.nombre);
		if(nuevo.nombre[0] == '0' && nuevo.nombre[1] == '\0') {
			return 0;break;
		}
	}while( strlen( nuevo.nombre ) == 0 || anime_existente(nuevo.nombre,nuevo.tipo,bin));

	system("cls");
	printf("Posicion\n");
	printf("1.- Primero\n");
	printf("2.- Ultimo\n");
	printf("3.- Elegir una posicion\n\n");
	printf("0.- Salir\n");
	do {
		printf("Opcion: ");fflush(stdin);
		if(!scanf("%i",&p))
			p = -1;
	}while(p < 0 || p > 3);
	if(p == 4)return 0;
	switch(p) {
		case 0: return 1;break;
		case 1: nuevo.posicion = 1;break;
		case 2: nuevo.posicion = cont+1;break;
		case 3:
			system("cls");
			if(!mostrar_todo(bin))
				printf("No hay animes registrados\n\n");
			do {
				printf("Posicion: ");fflush(stdin);
				if(!scanf("%i",&nuevo.posicion))
					p = -1;
			}while(nuevo.posicion < 1 || nuevo.posicion > cont+1);
			break;
	}
	strcpy(nuevo.genero,"");
	do {
		system("cls");
		printf("Tipo: %s\n",nuevo.tipo);
		printf("Posicion: %i\n",nuevo.posicion);
		printf("Nombre: %s\n",nuevo.nombre);
		printf("Autor/Mangaka: %s\n",nuevo.autor);
		printf("Genero: %s",nuevo.genero);
		printf("\n1.- Romance");
		printf("\n2.- Yuri");
		printf("\n3.- Drama");
		printf("\n4.- Comedia");
		printf("\n5.- Harem");
		printf("\n6.- Yaoi");
		printf("\n7.- Demonios");
		printf("\n8.- Psicologico");
		printf("\n9.- Musical");
		printf("\n10.- Fantasia");
		printf("\n11.- Super poderes");
		printf("\n12.- Magia");
		printf("\n13.- Ciencia ficcion");
		printf("\n14.- Ecchi");
		printf("\n15.- Hentai");
		printf("\n16.- Recuerdos de la vida");
		printf("\n17.- Mecha");
		printf("\n18.- Accion");
		printf("\n19.- Aventura");
		printf("\n20.- Deportes");
		printf("\n21.- Escolares");
		printf("\n22.- Gore");
		printf("\n23.- Horror");
		printf("\n24.- Lucha");
		printf("\n25.- Militar");
		printf("\n26.- Historico");
		printf("\n27.- Parodia");
		printf("\n28.- Artes marciales");
		printf("\n0.- Salir\n");
		printf("Elija una opcion: ");fflush(stdin);
		if(!scanf("%i",&x))
			x = -1;
	}while(agregar_genero(nuevo.genero,x));
	insertar_tipo(&nuevo,bin);
}

void insertar_tipo(struct MANGA_ANIME *nuevo,char *bin) {
	FILE *fp = fopen(bin,"rb");
	struct MANGA_ANIME *aux,aux_2;
	int cont,i,k;
	if(fp == NULL) {
		fp = fopen(bin,"wb");
		fwrite(nuevo,sizeof(struct MANGA_ANIME),1,fp);
		fclose(fp);
	}
	else {
		fseek(fp,0,SEEK_END);
		cont = ftell(fp)/sizeof(struct MANGA_ANIME);
		if(cont == 0) {
			fclose(fp);fp = fopen(bin,"wb");
			fwrite(nuevo,sizeof(struct MANGA_ANIME),1,fp);
			fclose(fp);
		}
		else {
			aux = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
			fseek(fp,0,SEEK_SET);
			fread(aux,sizeof(struct MANGA_ANIME),cont,fp);
			fclose(fp);//VAMOS A CERRAR EL FICHERO
			for(i = 0; i < cont; i++) {
				if((aux+i)->posicion >= nuevo->posicion) {
					(aux+i)->posicion++;
				}
			}
			aux = (struct MANGA_ANIME *)realloc(aux,sizeof(struct MANGA_ANIME)*(cont+1));
			strncpy( (aux+cont)->nombre, nuevo->nombre, strlen( nuevo->nombre ) +1);
			strncpy( (aux+cont)->genero, nuevo->genero, strlen( nuevo->genero ) +1);
			strncpy( (aux+cont)->autor, nuevo->autor, strlen( nuevo->autor ) +1);
			strncpy( (aux+cont)->tipo, nuevo->tipo, strlen( nuevo->tipo ) +1);
			(aux+cont)->posicion = nuevo->posicion;
			
			for(i = 0; i < cont+1; i++) {
				for(k = i; (aux+k)->posicion < (aux+(k-1))->posicion && k > 0; k--) {
					strncpy( aux_2.nombre, (aux+k)->nombre, strlen( (aux+k)->nombre ) +1);
					strncpy( aux_2.genero, (aux+k)->genero, strlen( (aux+k)->genero ) +1);
					strncpy( aux_2.tipo, (aux+k)->tipo, strlen( (aux+k)->tipo ) +1);
					strncpy( aux_2.autor, (aux+k)->autor, strlen( (aux+k)->autor ) +1);
					aux_2.posicion = (aux+k)->posicion;
					
					strncpy( (aux+k)->nombre, (aux+(k-1))->nombre, strlen( (aux+(k-1))->nombre ) +1);
					strncpy( (aux+k)->genero, (aux+(k-1))->genero, strlen( (aux+(k-1))->genero ) +1);
					strncpy( (aux+k)->tipo, (aux+(k-1))->tipo, strlen( (aux+(k-1))->tipo ) +1);
					strncpy( (aux+k)->autor, (aux+(k-1))->autor, strlen( (aux+(k-1))->autor ) +1);
					(aux+k)->posicion = (aux+(k-1))->posicion;
					
					strncpy( (aux+(k-1))->nombre, aux_2.nombre, strlen(aux_2.nombre) +1);
					strncpy( (aux+(k-1))->genero, aux_2.genero, strlen(aux_2.genero) +1);
					strncpy( (aux+(k-1))->tipo, aux_2.tipo, strlen(aux_2.tipo) +1);
					strncpy( (aux+(k-1))->autor, aux_2.autor, strlen(aux_2.autor) +1);
					(aux+(k-1))->posicion = aux_2.posicion;
				}
			}
			fp = fopen(bin,"wb");
			fwrite(aux,sizeof(struct MANGA_ANIME),cont+1,fp);
			fclose(fp);free(aux);
		}
	}
}

bool eliminar_tipo(char *bin) {
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		return false;
	}
	int m,i,k,cont;char opc;
	struct MANGA_ANIME *aux,*aux_2;
	fseek(fp,0,SEEK_END);
	cont = ftell(fp)/sizeof(struct MANGA_ANIME);
	if(cont == 0) {
		fclose(fp);
		return false;
	}
	aux = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
	aux_2 = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*(cont-1));
	if(aux == NULL || aux_2 == NULL) {
		if(aux != NULL) {
			free(aux);
		}
		else if(aux_2 != NULL) {
			free(aux_2);
		}
		fclose(fp);
		printf("No hay espacio en memoria");exit(EXIT_FAILURE);
	}
	fseek(fp,0,SEEK_SET);
	fread(aux,sizeof(struct MANGA_ANIME),cont,fp);
	fclose(fp);//CERRAMOS EL FICHERO
	do {
		system("cls");
		mostrar_todo(bin);
		printf("Posicion: ");fflush(stdin);
		if(!scanf("%i",&m)) {
			m = -1;
		}
	}while(m < 1 || m > cont);
	m--;
	do{
		printf("Desea eliminar el anime\"%s\"(S/N): ",(aux+m)->nombre);fflush(stdin);
		scanf("%c",&opc);
	}while(opc != 's' && opc != 'n');
	if(opc == 'n') {
		free(aux);free(aux_2);
		return true;	
	}
	k = 0;
	for(i = 0; i < cont; i++) {
		if((aux+i)->posicion != (aux+m)->posicion) {
			if((aux+i)->posicion > (aux+m)->posicion) {
				(aux+i)->posicion--;
			}
			strncpy( (aux_2+k)->nombre, (aux+i)->nombre, strlen( (aux+i)->nombre ) +1);
			strncpy( (aux_2+k)->genero, (aux+i)->genero, strlen( (aux+i)->genero ) +1);
			strncpy( (aux_2+k)->tipo, (aux+i)->tipo, strlen( (aux+i)->tipo ) +1);
			strncpy( (aux_2+k)->autor, (aux+i)->autor, strlen( (aux+i)->autor ) +1);
			(aux_2+k)->posicion = (aux+i)->posicion;
			k++;
		}
	}
	free(aux);
	fp = fopen(bin,"wb");
	fwrite(aux_2,sizeof(struct MANGA_ANIME),cont-1,fp);
	fclose(fp);free(aux_2);
	return true;
}

bool generar_lista(char *bin,char *txt) {
	FILE *fp_bin = fopen(bin,"rb"),*fp_txt;
	if(fp_bin == NULL) {
		return false;
	}
	int i,k,cont;
	struct MANGA_ANIME *aux;
	fseek(fp_bin,0,SEEK_END);
	cont = ftell(fp_bin)/sizeof(struct MANGA_ANIME);
	if(cont == 0) {
		fclose(fp_bin);fclose(fp_txt);
		return false;
	}
	fp_txt = fopen(txt,"wt");
	fseek(fp_bin,0,SEEK_SET);
	aux = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
	if(aux == NULL) {
		fclose(fp_bin);fclose(fp_txt);
		printf("No hay espacio en memoria");exit(EXIT_FAILURE);
	}
	fread(aux,sizeof(struct MANGA_ANIME),cont,fp_bin);
	fclose(fp_bin);
	for(i = 0; i < cont; i++) {
		fprintf(fp_txt,"%i.- Tipo: %s\t\tNombre: %s\t\tGenero: %s\t\tAutor/Mangaka: %s\n",(aux+i)->posicion,(aux+i)->tipo,(aux+i)->nombre,(aux+i)->genero,(aux+i)->autor);
	}
	free(aux);fclose(fp_txt);
	return true;
}

bool generar_tipo(char *bin,char *txt,char *tipo) {
	FILE *fp_bin = fopen(bin,"rb"),*fp_txt;
	if(fp_bin == NULL) {
		return false;
	}
	struct MANGA_ANIME *aux;
	int i,cont,cont_2;
	fseek(fp_bin,0,SEEK_END);
	cont = ftell(fp_bin)/sizeof(struct MANGA_ANIME);
	if(cont == 0) {
		fclose(fp_bin);fclose(fp_txt);
		return false;
	}
	fseek(fp_bin,0,SEEK_SET);
	aux = (struct MANGA_ANIME *)malloc(sizeof(struct MANGA_ANIME)*cont);
	fread(aux,sizeof(struct MANGA_ANIME),cont,fp_bin);
	fclose(fp_bin);//CERRAMOS EL FICHERO
	cont_2 = 0;
	for(i = 0; i < cont; i++) {
		if(strcmp( (aux+i)->tipo, tipo ) == 0) {
			cont_2++;break;
		}
	}
	if(cont_2 == 0) {
		free(aux);
		return false;
	}
	fp_txt = fopen(txt,"wt");
	for(i = 0; i < cont; i++) {
		if(strcmp( (aux+i)->tipo, tipo ) == 0) {
			fprintf(fp_txt,"%i.- Tipo: %s\t\tNombre: %s\t\tGenero: %s\t\tAutor/Mangaka: %s\n",(aux+i)->posicion,(aux+i)->tipo,(aux+i)->nombre,(aux+i)->genero,(aux+i)->autor);
			cont_2++;
		}
	}
	fclose(fp_txt);free(aux);
	return true;
}

