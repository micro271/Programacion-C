/*
	Utilizar las 2 estructuras del problema 5, pero ahora pedir los datos para N alumnos,
	y calcular cuál de todos tiene el mejor promedio, e imprimir sus datos.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	int nota1;
	int nota2;
	int nota3;	
	int promedio;
}promedio_a;

typedef struct{
	char nombre[30];
	char sexo[10];
	int edad;
	promedio_a nota;
}alumno;

void pedir(alumno *a);
void imprimir(alumno *a);
int main(void)
{
	int i,n;
	unsigned int largo;
	do
	{
		printf("Cuantos alumnos deceas registrar: ");
		fflush(stdin);
		scanf("%u",&largo);
	}while(largo < 0 && largo > 30);
	
	alumno a[largo];
	
	for(i = 0; i < largo; i++)
	{
		pedir(&a[i]);
	}
	int promedio[largo],aux;
	for(i = 0; i < largo; i++)
	{
		promedio[i] = (a[i].nota.nota1 + a[i].nota.nota2 +a[i].nota.nota3)/3;
	}
	
	for(i = 0; i < largo; i++)
	{
		for(n = i + 1; n < largo; n++)
		{
			if(promedio[i] < promedio[n])
			{
				aux = promedio[i];
				promedio[i] = promedio[n];
				promedio[n] = aux;
			}
		}
	}
	
	for(i = 0; i < largo; i++)
	{
		if(promedio[0] == a[i].nota.promedio)
		{
			imprimir(&a[i]);
		}
	}
	system("pause");
	return 0;
}
void imprimir(alumno *a)
{
	int promedio;
	printf("\n\tLos datos del alumno son:\n");
	printf("Nombre: %s\n",a->nombre);
	printf("Sexo: %s\n",a->sexo);
	printf("Edad: %i\n",a->edad);
	printf("Nota 1: %i\n",a->nota.nota1);
	printf("Nota 2: %i\n",a->nota.nota2);
	printf("Nota 3: %i\n",a->nota.nota3);
	printf("Promedio: %i\n",a->nota.promedio);
}
void pedir(alumno *a)
{
	int i;
	printf("Nombre: ");
	fflush(stdin);
	gets((*a).nombre);
	for(i = 0; i < strlen(a->nombre); i++)
	{
		if(i == 0 && a->nombre[i] != ' ')
		{
			a->nombre[i] = toupper(a->nombre[i]);
		}
		if(a->nombre[i] == ' ')
		{
			a->nombre[i+1] = toupper(a->nombre[i+1]);
		}
	}
	
	do
	{
		printf("Sexo: ");
		fflush(stdin);
		gets(a->sexo);
		for(i = 0; i < strlen(a->sexo); i++)
		{
			a->sexo[i] = toupper(a->sexo[i]);
		}
	}while(strcmp(a->sexo,"MASCULINO") != 0 && strcmp(a->sexo,"FEMENINO") != 0);
	
	do
	{
		printf("Edad: ");
		fflush(stdin);
		scanf("%i",&a->edad);
		if(a->edad < 0)
		{
			printf("Si usted tiene %i años no deberia existir aun\n",a->edad);
		}
		else if(a->edad > 80)
		{
			printf("Si usted tiene %i años deberia preocuparse mas por escribir el testamento\n",a->edad);
		}
	}while(a->edad < 0 && a->edad > 80 );
	printf("Digite su nota como 100 la nota mas alta\n");
	do
	{
		printf("1 Nora: ");
		fflush(stdin);
		scanf("%i",&a->nota.nota1);
		if(a->nota.nota1 < 0)
		{
			printf("No hay notas negativas, si no sos un burro\n");
		}
		else if(a->nota.nota1 > 100)
		{
			printf("No hay notas mayores a 100\n");
		}
	}while(a->nota.nota1 > 0 && a->nota.nota1 > 100);
	
	do
	{
		printf("2 Nora: ");
		fflush(stdin);
		scanf("%i",&a->nota.nota2);
		if(a->nota.nota2 < 0)
		{
			printf("No hay notas negativas, si no sos un burro\n");
		}
		else if(a->nota.nota2 > 100)
		{
			printf("No hay notas mayores a 100\n");
		}
	}while(a->nota.nota2 > 0 && a->nota.nota2 > 100);
	
	do
	{
		printf("3 Nora: ");
		fflush(stdin);
		scanf("%i",&a->nota.nota3);
		if(a->nota.nota3 < 0)
		{
			printf("No hay notas negativas, si no sos un burro\n");
		}
		else if(a->nota.nota3 > 100)
		{
			printf("No hay notas mayores a 100\n");
		}
	}while(a->nota.nota3 > 0 && a->nota.nota3 > 100);
	
	a->nota.promedio = (a->nota.nota1 + a->nota.nota2 +a->nota.nota3)/3;
}
