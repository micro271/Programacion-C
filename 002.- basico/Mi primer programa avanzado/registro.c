/*
	**AQUI SE ENCONTRARAN LAS FUNCIONES QUE SE ENCAGARAN DE
	AGREGAR MODIFICAR CREAR Y ELIMINAR ELEMENTOS
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "registro.h"
void new_reg(char *bin,char *tipo) {
	int cont,i;
	FILE *fp = NULL;
	Reg *nuevo_reg,*aux;
	if( (nuevo_reg = crear_reg(tipo,bin)) != NULL) {
		if( (fp = fopen(bin,"rb")) == NULL) {
			nuevo_reg->pos = 1;
			add_reg(nuevo_reg,1,bin);
			free(nuevo_reg);
		}
		else {
			cont = length_reg(fp,NULL);
			if(cont == 0) {nuevo_reg->pos = 1;add_reg(nuevo_reg,1,bin);free(nuevo_reg);}
			else {
				if((aux = (Reg *)malloc(sizeof(Reg)*cont)) == NULL) {
					system("cls");printf("No hay espacio en memoria\n");system("pause");exit(EXIT_FAILURE);
				}
				do {
					system("cls");
					view_all(bin);
					printf("\nTipo: %s\n",nuevo_reg->tipo);
					printf("Nombre: %s\n",nuevo_reg->nombre);
					printf("Genero: %s\n",nuevo_reg->genero);
					printf("Autor: %s\n",nuevo_reg->autor);
					printf("Posicion: ");fflush(stdin);
					if(!scanf("%i",&nuevo_reg->pos)) {nuevo_reg->pos = -1;}
				}while(nuevo_reg->pos < 1 || nuevo_reg->pos > cont+1);
				
				system("cls");
				printf("\nTipo: %s\n",nuevo_reg->tipo);
				printf("Nombre: %s\n",nuevo_reg->nombre);
				printf("Genero: %s\n",nuevo_reg->genero);
				printf("Autor: %s\n",nuevo_reg->autor);
				printf("Posicion: %i\n",nuevo_reg->pos);			
				fread(aux,sizeof(Reg),cont,fp);fclose(fp);
				for(i = 0; i < cont; i++) {
					if((aux+i)->pos >= nuevo_reg->pos) {
						(aux+i)->pos++;
					}
				}
				if((aux = (Reg *)realloc(aux,sizeof(Reg)*(cont+1))) == NULL) {
					system("cls");printf("No hay espacio en memoria\n");system("pause");exit(EXIT_FAILURE);
				}
				strncpy( (aux+cont)->nombre, nuevo_reg->nombre, strlen( nuevo_reg->nombre ) +1);
				strncpy( (aux+cont)->genero, nuevo_reg->genero, strlen( nuevo_reg->genero ) +1);
				strncpy( (aux+cont)->tipo, nuevo_reg->tipo, strlen( nuevo_reg->tipo ) +1);
				strncpy( (aux+cont)->autor, nuevo_reg->autor, strlen( nuevo_reg->autor ) +1);
				(aux+cont)->pos = nuevo_reg->pos;free(nuevo_reg);
				reorganizar_reg(aux,cont+1);
				add_reg(aux,cont+1,bin);
			}
		}
	}
	free(aux);
}
void reorganizar_reg(Reg *aux,int n) {
	int i,j;
	Reg aux_2;
	for(i = 0; i < n; i++) {
		for(j = i; (aux+j)->pos < (aux+(j-1))->pos && j > 0; j--) {
			strncpy( aux_2.nombre, (aux+j)->nombre, strlen( (aux+j)->nombre ) +1);
			strncpy( aux_2.genero, (aux+j)->genero, strlen( (aux+j)->genero ) +1);
			strncpy( aux_2.tipo, (aux+j)->tipo, strlen( (aux+j)->tipo ) +1);
			strncpy( aux_2.autor, (aux+j)->autor, strlen( (aux+j)->autor ) +1);
			aux_2.pos = (aux+j)->pos;
			
			strncpy( (aux+j)->nombre, (aux+(j-1))->nombre, strlen( (aux+(j-1))->nombre ) +1);
			strncpy( (aux+j)->genero, (aux+(j-1))->genero, strlen( (aux+(j-1))->genero ) +1);
			strncpy( (aux+j)->tipo, (aux+(j-1))->tipo, strlen( (aux+(j-1))->tipo ) +1);
			strncpy( (aux+j)->autor, (aux+(j-1))->autor, strlen( (aux+(j-1))->autor ) +1);
			(aux+j)->pos = (aux+(j-1))->pos;
			
			strncpy( (aux+(j-1))->nombre, aux_2.nombre, strlen( aux_2.nombre ) +1);
			strncpy( (aux+(j-1))->genero, aux_2.genero, strlen( aux_2.genero ) +1);
			strncpy( (aux+(j-1))->tipo, aux_2.tipo, strlen( aux_2.tipo ) +1);
			strncpy( (aux+(j-1))->autor, aux_2.autor, strlen( aux_2.autor ) +1);
			(aux+(j-1))->pos = aux_2.pos;
		}
	}
}
int length_reg(FILE *fp,char *bin) {
	int cont;FILE *aux;
	if(fp != NULL) {
		fseek(fp,0,SEEK_END);
		if((cont = ftell(fp)) == 0) {return 0;}
		fseek(fp,0,SEEK_SET);
		return cont/sizeof(Reg);
	} 
	else {
		if( (aux = fopen(bin,"rb")) != NULL) {
			fseek(aux,0,SEEK_END);
			if( (cont = ftell(aux)) == 0) {return 0;}
			fclose(aux);
			return cont/sizeof(Reg);
		}
		else {return -1;}
	}
}
Reg *crear_reg(char *tipo,char *bin) {
	Reg *nuevo = (Reg *)malloc(sizeof(Reg));
	int x,acc,i;
	int pos_g = 1,acc_g; //VARIABLES QUE SE UTILIZARAN PARA SELECCIONAR LOS GENEROS
	char c,f,*nombre_aux = NULL;int cont_name = 0;//ESTAS VARIABLES CREADAS PARA COLOCAR EL NOMBRE
	strncpy( nuevo->tipo, tipo, strlen(tipo) +1);
	do {
		system("cls");
		printf("ENTER para continuar - ESC para salir\n");fflush(stdin);c = getch();
	}while(c != 27 && c != 13);
	if(c == 27) {free(nuevo);return NULL;}
	do {
		system("cls");
		printf("Tipo: %s\n",nuevo->tipo);
		printf("Nombre: ");fflush(stdin);fgets(nuevo->nombre,29,stdin);
		arreglar_fgets(nuevo->nombre);arreglar_espacios(nuevo->nombre);
	}while(strlen( nuevo->nombre ) == 0);
	
	do {
		system("cls");
		printf("Tipo: %s\n",nuevo->tipo);printf("Nombre: %s\n",nuevo->nombre);
		printf("Autor/Mangaka: ");fflush(stdin);fgets(nuevo->autor,19,stdin);
		arreglar_fgets(nuevo->autor);arreglar_espacios(nuevo->autor);
	 }while(strlen( nuevo->autor ) == 0);
		
	strcpy(nuevo->genero,"");
	do {
		system("cls");
		printf("Tipo: %s\n",nuevo->tipo);printf("Nombre: %s\n",nuevo->nombre);printf("Autor/Mangaka: %s\n",nuevo->autor);
		printf("Genero: %s",nuevo->genero);
		if(pos_g == 1) {
			printf("\n1.- Romance");
			printf("\n2.- Yuri");
			printf("\n3.- Drama");
			printf("\n4.- Comedia");
			printf("\n5.- Harem");
			printf("\n6.- Yaoi");
			printf("\n7.- Demonios");
			printf("\n8.- Psicologico");
			printf("\n9.- Musical");
		}
		else if(pos_g == 2) {
			printf("\n1.- Fantasia");
			printf("\n2.- Super poderes");
			printf("\n3.- Magia");
			printf("\n4.- Ciencia ficcion");
			printf("\n5.- Ecchi");
			printf("\n6.- Hentai");
			printf("\n7.- Recuerdos de la vida");
			printf("\n8.- Mecha");
			printf("\n9.- Accion");
		}
		else if(pos_g == 3) {
			printf("\n1.- Aventura");
			printf("\n2.- Deportes");
			printf("\n3.- Escolares");
			printf("\n4.- Gore");
			printf("\n5.- Horror");
			printf("\n6.- Lucha");
			printf("\n7.- Militar");
			printf("\n8.- Historico");
			printf("\n9.- Parodia");	
		}
		else if(pos_g == 4) {
			printf("\n.- Artes marciales");
		}
		if(pos_g > 1 && pos_g < 4) {printf("\n\n%c Anterior\tSiguiente %c",60,62);}
		else if(pos_g == 1) {printf("\n\nSiguiente %c",62);}
		else if(pos_g == 4) {printf("\n\n%c Anterior",60);}
		
		fflush(stdin);acc_g = getch();
		if(acc_g == -32) {f = getch();}
		
		if(acc_g == 13 || acc_g == 9) {break;}
		else if(acc_g == 77 || acc_g == 100 || acc_g == 68) {
			pos_g++;
			if(pos_g > 4) {pos_g = 1;}
		}
		else if(acc_g == 75 || acc_g == 97 || acc_g == 65) {
			pos_g--;
			if(pos_g < 1) {pos_g = 4;}
		}
		else if(isdigit(acc_g)) {
			if(pos_g == 1) {
				switch(acc_g) {
					case '1':x = 1;break;
					case '2':x = 2;break;
					case '3':x = 3;break;
					case '4':x = 4;break;
					case '5':x = 5;break;
					case '6':x = 6;break;
					case '7':x = 7;break;
					case '8':x = 8;break;
					case '9':x = 9;break;
				}
				agregar_genero(nuevo->genero,x);
			}
			else if (pos_g == 2) {
				switch(acc_g) {
					case '1':x = 10;break;
					case '2':x = 11;break;
					case '3':x = 12;break;
					case '4':x = 13;break;
					case '5':x = 14;break;
					case '6':x = 15;break;
					case '7':x = 16;break;
					case '8':x = 17;break;
					case '9':x = 18;break;
				}
				agregar_genero(nuevo->genero,x);
			}
			else if(pos_g == 3) {
				switch(acc_g) {
					case '1':x = 19;break;
					case '2':x = 20;break;
					case '3':x = 21;break;
					case '4':x = 22;break;
					case '5':x = 23;break;
					case '6':x = 24;break;
					case '7':x = 25;break;
					case '8':x = 26;break;
					case '9':x = 27;break;
				}
				agregar_genero(nuevo->genero,x);
			}
			else if(pos_g == 4) {
				switch(acc_g) {
					case '1':x = 28;agregar_genero(nuevo->genero,x);break;
				}
			}
		}
	}while(pos_g != 13 && pos_g != 9);
	return nuevo;
}
void add_reg(Reg *aux,int cont,char *bin) {
	FILE *fp = fopen(bin,"wb");
	fwrite(aux,sizeof(Reg),cont,fp);
	fclose(fp);
}
void eliminar_elemento(char *bin) {
	int cont,pos;
	char f;
	cont = length_reg(NULL,bin);
	if(cont > 0) {
		do {
			system("cls");
			view_all(bin);
			fflush(stdin);if( !scanf("%i",&pos) ) {pos = -1;}
		}while(pos < 1 && pos > cont);
		delete_element(bin,pos);
	}
	else {
		do {
			system("cls");
			printf("No hay nada registrado - ENTER para volver\n");fflush(stdin);
			f = getch();
		}while(f != 13);
	}
}
void delete_element(char *bin,int pos){
	int i,cont,cont_2 = 0,m,acc;
	FILE *fp = fopen(bin,"rb");
	Reg *aux,*aux_2;
	cont = length_reg(fp,NULL);
	if( (aux = (Reg *)malloc(sizeof(Reg)*cont)) == NULL) {
		system("cls");printf("NO HAY ESPACIO EN MEMORIA\n");system("pause");exit(EXIT_FAILURE);
	}
	fread(aux,sizeof(Reg),cont,fp);fclose(fp);
	for(i = 0; i < cont; i++) {
		if(pos == (aux+i)->pos) {
			m = i;
		}
	}
	do {
		printf("Desea eliminar: \n");
		print_reg((aux+m),1);
		printf("ESC para volver - ENTER para continuar\n");fflush(stdin);
		acc = getch();
	}while(acc != 27 && acc != 13);
	if(acc == 13) {
		aux_2 = (Reg *)malloc(sizeof(Reg)*(cont-1));
		for(i = 0; i < cont; i++) {
			if((aux+i)->pos != (aux+m)->pos) {
				if((aux+i)->pos > (aux+m)->pos) {(aux+i)->pos--;}
				strncpy( (aux_2+cont_2)->nombre, (aux+i)->nombre, strlen( (aux+i)->nombre ) +1);
				strncpy( (aux_2+cont_2)->genero, (aux+i)->genero, strlen( (aux+i)->genero ) +1);
				strncpy( (aux_2+cont_2)->tipo, (aux+i)->tipo, strlen( (aux+i)->tipo ) +1);
				strncpy( (aux_2+cont_2)->autor, (aux+i)->autor, strlen( (aux+i)->autor ) +1);
				(aux+cont_2)->pos = (aux+i)->pos;
				cont_2++;
			}
		}
		add_reg(aux_2,cont_2+1,bin);
		free(aux_2);
	}
	free(aux);
}
void print_reg(Reg *aux,int cont) {
	int i;
	for(i = 0; i < cont ; i++) {
		printf("%i. Tipo: %s \tNombre: %s \tAutor: %s \tGenero: %s\n",(aux+i)->pos,(aux+i)->tipo,(aux+i)->nombre,(aux+i)->autor,(aux+i)->genero);
	}
}
bool view_all(char *bin) {//CON ESTA FUNCION VEREMOS TODO EN PANTALLA
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {return false;}
	int cont,i;Reg *aux = NULL;
	if((cont = length_reg(fp,NULL)) == 0) {return false;}
	aux = (Reg *)malloc(sizeof(Reg)*cont);
	fread(aux,sizeof(Reg),cont,fp);fclose(fp);
	print_reg(aux,cont);
	free(aux);
	return true;
}

bool view_tipo(char *bin,char *tipo) {
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		return false;
	}
	Reg *el;
	int i,cont,cont_2;
	if( (cont = length_reg(fp,NULL) ) <= 0) {fclose(fp);return false;}
	el = (Reg *)malloc(sizeof(Reg)*cont);
	fread(el,sizeof(Reg),cont,fp);
	fclose(fp);//CERRAMOS EL FICHERO Q NO VAMOS A USAR MAS
	cont_2 = 0;
	for(i = 0; i < cont; i++) {
		if(strcmp((el+i)->tipo,tipo) == 0) {
			printf("%i.- Nombre %s\t Genero: %s\t Mangaka: %s\n",(el+i)->pos,(el+i)->nombre,(el+i)->genero,(el+i)->autor);
			cont_2++;
		}
	}
	free(el);
	if(cont_2 == 0) {
		return false;
	}
	return true;
}


bool view_genero(char *bin,char *g){
	FILE *fp = fopen(bin,"rb");
	if(fp == NULL) {
		return false;
	}
	Reg *el;
	int i,cont,cont_2,bits,opc;char genero[30];
	if( (cont = length_reg(fp,NULL)) <= 0) {fclose(fp);return false;}
	fread(el,sizeof(Reg),cont,fp);
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
			printf("%i.-\t Nombre %s \t Genero: %s \t Mangaka: %s\n",(el+i)->pos,(el+i)->nombre,(el+i)->genero,(el+i)->autor);
			cont_2++;
		}
	}
	free(el);
	if(cont_2 == 0) {
		return false;
	}
	return true;
}

void generar_txt(char *bin) {
	FILE *fp_bin = NULL,*fp_txt = NULL;char nombre[34];char fin[] = ".txt";
	Reg *aux;
	int i,j,k,len,cont,cont_2,acc;
	int entrar = 0;
	bool bucle = true;
	if( (fp_bin = fopen(bin,"rb")) == NULL) {
		system("cls");
		printf("No hay nada registrado\n");
	}
	else {
		do {
			system("cls");
			printf("Nombre del archivo: ");fflush(stdin);
			fgets(nombre,29,stdin);arreglar_fgets(nombre);
			i = 0;
			while(nombre[i] != '\0') {
				if(isspace(nombre[i])) {
					for(j = i; nombre[j] != '\0'; j++) {
						nombre[j] = nombre[j+1];
					}
					continue;
				}
				i++;
			}
			if(i != 0) {
				len = i;cont = 0;
				for(i = 0; i < len; i++) {
					if(isalnum(nombre[i]) || nombre[i] == '-' || nombre[i] == '_') {cont++;}
				}
				if(strlen(nombre) == cont) {bucle = false;strcat(nombre,fin);}
			}
			else {
				strcpy(nombre,"Registro.txt");bucle = false;
			}
		}while(bucle);
		
		if( (fp_bin = fopen(bin,"rb")) != NULL) {
			k = 0;
			cont_2 = length_reg(fp_bin,NULL);
			if(cont_2 <= 0) {fclose(fp_bin);}
			else {
				entrar++;
				aux = (Reg *)malloc(sizeof(Reg) * cont_2);
				fread(aux,sizeof(Reg),cont_2,fp_bin);fclose(fp_bin);
				fp_txt = fopen(nombre,"wb");
				do {
					system("cls");
					printf("Se genero un archivo de texto con el contenido: \n\n");
					for(i = 0; i < cont_2; i++) {
						if(k == 0) {
							fprintf(fp_txt,"%i. Tipo: %s \t Nombre: %s \t Genero: %s \t Autor/Mangaka: %s\n",(aux+i)->pos,(aux+i)->tipo,(aux+i)->nombre,(aux+i)->genero,(aux+i)->autor);
						}
						fprintf(stdout,"%i. Tipo: %s \t Nombre: %s \t Genero: %s \t Autor/Mangaka: %s\n",(aux+i)->pos,(aux+i)->tipo,(aux+i)->nombre,(aux+i)->genero,(aux+i)->autor);
					}
					k++;
					printf("\nPresione ESC para volver\t");fflush(stdin);
					acc = getch();
				}while(acc != 27);
				fclose(fp_txt);free(aux);
			}
		}
	}
	if(entrar == 0) {
		do {
			printf("No hay nada registrado\n");
			printf("\nPresiona ESC para voler\n");fflush(stdin);
			acc = getch();
		}while(acc != 27);
	}
}

bool anime_existente(char *nombre,char *tipo,char *bin) {
	
}

