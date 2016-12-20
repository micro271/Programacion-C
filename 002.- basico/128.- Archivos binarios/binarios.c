#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct cumples
{
	char nombre[30];
	int edad;
}cumples;
cumples *add_cumple(int *k);char *add_memory();
void add_binario(cumples *m,int k);
void number_of_files(const int k);
void print_to_stdout(cumples *n,int k);
int main(int argc,char **argv)
{
	cumples *family = NULL;int k = 1,i;
	family = add_cumple(&k);
	number_of_files(k);
	print_to_stdout(family,k);
	add_binario(family,k);
	
	for(i = 0; i < k; i++)
	{
		free(family->nombre);
	}
	free(family);
	return EXIT_SUCCESS;
}

cumples *add_cumple(int *k)
{
	cumples *aux;int pos = 0;char preg;
	aux = (cumples *)malloc(sizeof(cumples)*(*k));
	do
	{
		printf("Nombre: ");fflush(stdin);
		gets(&(aux+pos)->nombre);
		printf("Edad: ");fflush(stdin);
		scanf("%i",&(aux+pos)->edad);
		do
		{
			printf("Desea Agregar otro cumpleaños (S-N): ");fflush(stdin);
			scanf("%c",&preg);
			preg = toupper(preg);
		}while(preg != 'S' && preg != 'N');
		if(preg == 'S')
		{
			(*k)++;pos++;
			aux = (cumples *)realloc(aux,sizeof(cumples)*(*k));
		}
	}while(preg == 'S');
	
	return aux;
}

void add_binario(cumples *m,int k)
{
	FILE *fp = NULL;
	fp = fopen("Listado.dat","ab");
	if(fp == NULL)exit(EXIT_FAILURE);
	
	fwrite(m,sizeof(cumples),k,fp);
	fclose(fp);
}

void print_to_stdout(cumples *n,int k)
{
	int i;printf("\n");
	for(i = 0; i < k; i++)
		printf("Nombre: %s, Edad: %i\n",(n+i)->nombre,(n+i)->edad);
}
void number_of_files(const int k)
{
	int *x;
	FILE *fp = fopen("files/cont.dat","r w b");
	if(fp == NULL)
	{
		printf("HUBO UN ERROR EN MEMORIA");
	}
	if(fread(x,sizeof(int),1,fp) != NULL)
	{
		
	}
}


