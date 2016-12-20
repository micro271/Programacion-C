#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
	int dia;//DIA DEL ESTRENO
	int mes;//MES DEL ESTRENO
	int anio;//AÑO DEL ESTRENO
}estreno;

typedef struct
{
	char nombre[40];	//Nombre
	char genero[100];	//Genero
	char mangaka[40];
	char getDay[100];	//Guardamos la fecha especificada
	estreno fecha;		//Desde aqui generamos la fecha especificada
}anime;
void print_anime();
anime *add_anime(int *cont);//LE ASIGNAMOS LA MEMORIA Y LOS VALORES
void corregir_string(char *aux,size_t len);//CORREGIMOS EL SALTO DE LINEA X EL FIN DEL STRING QUE PROBOCA LA FUNCION FGETS

int main(int argc,char **argv)
{
	int k,cont = 0;//CONT PARA SABER CUANTOS ESTRUCTS SE AN CREADO;
	anime *my_anime = NULL;

	printf("Que decea hacer:\n\n");
	printf("1. Agregar anime\n");
	printf("2. Ver anime\n");
	do
	{
		printf("Digite su opcion: ");fflush(stdin);
		fscanf(stdin,"%i",&k);
	}while(k != 1 && k != 2);
	
	switch(k)
	{
		case 1: system("cls");my_anime = add_anime(&cont);break;
		case 2: system("cls");print_anime();break;
	}
	
	free(my_anime);
	return EXIT_SUCCESS;
}


anime *add_anime(int *cont)
{
	anime *aux = NULL;int k = 0;char preg;
	aux = (anime *)malloc(sizeof(anime));
	if(aux == NULL)
	{
		printf("\nHubo un error al asignar memoria\n");
		exit(EXIT_FAILURE);
	}
	
	do
	{
		(*cont)++;
		
		printf("\Nombre del anime: ");fflush(stdin);//PEDIMOS EL NOMBRE
		fgets((aux+k)->nombre,39,stdin);//GUARDAMOS EL NOMBRE
		corregir_string(&(aux+k)->nombre,strlen((aux+k)->nombre));//CORREGIMOS EL SALTO DE LINEA POR EL FIN DE STRING
		
		printf("Mangaka: ");fflush(stdin);
		fgets((aux+k)->mangaka,39,stdin);
		corregir_string(&(aux+k)->mangaka,strlen((aux+k)->mangaka));
		
		printf("Genero: ");fflush(stdin);//PEDIMOS EL GENERO
		fgets((aux+k)->genero,99,stdin);//GUARDAMOS EL GENERO
		corregir_string(&(aux+k)->genero,strlen((aux+k)->genero));//CORREGIMOS EL SALTO DE LINEA POR EL FIN DE STRING
		
		printf("Digite la fecha que se estreno el anime: \n");
		do
		{
			printf("Mes: ");fflush(stdin);//PEDIMOS EL MES
			fscanf(stdin,"%i",&(aux+k)->fecha.mes);//ASIGNAMOS EL MES
		}while((aux+k)->fecha.mes < 1 || (aux+k)->fecha.mes > 12);//QUE NO ASIGNEN UN MES INXISTENTE
		

		if((aux+k)->fecha.mes == 2)
		{
			do
			{
				printf("Dia: ");fflush(stdin);//PEDIMOS EL DIA
				fscanf(stdin,"%i",&(aux+k)->fecha.dia);//ASIGNAMOS EL DIA
			}while((aux+k)->fecha.dia < 1 || (aux+k)->fecha.dia > 29);
		}
		else
		{
			do
			{
				printf("Dia: ");fflush(stdin);//PEDIMOS EL DIA
				fscanf(stdin,"%i",&(aux+k)->fecha.dia);//ASIGNAMOS EL DIA
			}while((aux+k)->fecha.dia < 1 || (aux+k)->fecha.dia > 31);//QUE NO ASIGNEN UN DIA INEXISTENTE
		}
		
		
		do
		{
			printf("Anio: ");fflush(stdin);//PEDIMOS EL AÑO
			fscanf(stdin,"%i",&(aux+k)->fecha.anio);//ASIGNAMOS EL AÑO
		}while((aux+k)->fecha.anio < 1995 || (aux+k)->fecha.anio > 2016);//QUE NO SEA UN AÑO MENOR A 1995 Y SUPERIOR A 2016
		
		
		do
		{
			printf("\nDesea agregar otro anime (S/N): ");fflush(stdin);
			scanf("%c",&preg);
			preg = toupper(preg);
		}while(preg != 'S' && preg != 'N');
		
		if(preg == 'S')
		{
			k++;
			aux = (anime *)realloc(aux,sizeof(anime)*(k+1));
			if(aux == NULL)
			{
				printf("\nHubo un error al realizar la redimencion de memoria\n");
				exit(EXIT_FAILURE);
			}
		}
	}while(preg == 'S');
	
	return aux;
}

void add_to_bin(anime *m,FILE *bin,size_t len)
{
	return fwrite(m,sizeof(anime),len,bin) == 1;
}


void corregir_string(char *aux,size_t len)//FUNCION PARA CORREGIR EL SALTO DE LINEA DEL FGETS, LEN ES LA CANTIDAD DE CARACTER QUE SE ENCUENTRAN DENTRO Y AUX COMO PUNTERO AL STRING SOLICITADO
{
	int i;
	for(i = 0; i <= len; i++)//CONDICION DESDE LA POSICION 0 DEL STRING HASTA LA POSICION FINAL + 1 EN DONDE SE ENCUENTRA EL CARACTER ESPECIAL DE SALTO DE LINEA
	{
		if(*(aux+i) == '\n')
		{
			*(aux+i) = '\0';break;
		}
		else
		{
			if(i == 0 || (i > 0 && isspace(*(aux+(i-1)))) )
			{
				*(aux+i) = toupper(*(aux+i));
			}
		}
	}
}









