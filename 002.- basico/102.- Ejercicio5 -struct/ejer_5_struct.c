/*
	Hacer 2 estructuras una llamada promedio que tendrá los siguientes miembros: nota1, nota2, nota3;
	y otro llamada alumno que tendrá los siguientes miembros: nombre, sexo, edad; 
	hacer que la estructura promedio este anidada en la estructura alumno, luego pedir todos los
	datos para un alumno, luego calcular su promedio, y por ultimo imprimir todos sus datos incluidos el
	promedio.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	int nota1;
	int nota2;
	int nota3;	
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
	alumno a1;
	pedir(&a1);
	imprimir(&a1);
	system("pause");
	return 0;
}
void imprimir(alumno *a)
{
	int promedio;
	printf("\tLos datos del alumno son:\n");
	printf("Nombre: %s\n",a->nombre);
	printf("Sexo: %s\n",a->sexo);
	printf("Edad: %i\n",a->edad);
	printf("Nota 1: %i\n",a->nota.nota1);
	printf("Nota 2: %i\n",a->nota.nota2);
	printf("Nota 3: %i\n",a->nota.nota3);
	promedio = (a->nota.nota1 + a->nota.nota2 +a->nota.nota3)/3;
	printf("Promedio: %i\n",promedio);
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
	}while(a->edad < 0 && a->edad > 80);
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
}









