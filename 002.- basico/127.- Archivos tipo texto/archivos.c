#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct persona
{
	char nombre[30];
	char apellido[30];
	int edad;	
}p;
p *add_struct(int *n_elements);//AGREGAMOS LOS VALORES Y LA ASIGNACION DE MEMORIA
char *read();
void add_my_file(p *pe,int *n);
void read_my_file();
int main(int argc,char **argv)
{
	p *I;int n_elements = 1,i;
	I = add_struct(&n_elements);
	printf("%i",n_elements);
	add_my_file(I,&n_elements);
	read_my_file();
	
	free(I);
	
	return EXIT_SUCCESS;
}
void read_my_file()
{	
	FILE *fp = NULL;
	fp = fopen("yo.txt","r");
	int c;
	printf("\n");
	while(!feof(fp))
	{
		c = fgetc(fp);
		printf("%c",c);
	}
	/*
		while(c = fgetc(fp) != EOF)		EOF ES EL VALOR DADO CUANDO SE LLEGA AL FINAL DEL ARCHIVO
		{
			printf("%c",c);
		}
	*/
}


void add_my_file(p *pe,int *n)
{
	int i;
	FILE *my_file = NULL;
	my_file = fopen("yo.txt","at");
	for(i = 0; i < *n; i++)
		fprintf(my_file,"Nombre: %s, Apellido: %s, Edad: %i\n",(pe+i)->nombre,(pe+i)->apellido,(pe+i)->edad);
	fclose(my_file);
}

p *add_struct(int *n_elements)
{
	p *I = NULL;char preg;int n = 1,pos = 0;
	I = (p *)malloc(sizeof(p)*(*n_elements));
	if(I == NULL)
	{
		printf("\nError al asignar memoria\n");exit(EXIT_FAILURE);
	}
	do
	{
		printf("Nombre: ");fflush(stdin);
		gets(&(I+pos)->nombre);
		printf("Apellido: ");fflush(stdin);
		gets(&(I+pos)->apellido);
		printf("Edad: ");fflush(stdin);
		scanf("%i",&(I+pos)->edad);
		do
		{
			printf("Desea agregar otra persona (S/N): ");fflush(stdin);
			scanf("%c",&preg);
			preg = toupper(preg);
		}while(preg != 'S' && preg != 'N');
		if(preg == 'S')
		{
			pos++;(*n_elements)++;
			I = (p *)realloc(I,sizeof(p)*(*n_elements));
			if(I == NULL)
			{
				printf("\nNo se pudo asignar la memoria\n");exit(EXIT_FAILURE);
			}
		}
	}while(preg == 'S');
	return I;	
}

