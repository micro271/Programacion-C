/*
	Realizar un programa en c que lea un arreglo de estructura los datos de n empleados y que imprima
	los datos del empleado con el mayor y menor salario
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	char nombre[30];
	int edad;
	unsigned int salario;
}empleados_t;
void pedir(empleados_t * e,int i);
void imprimir(empleados_t e);
int main()
{
	unsigned int largo;
	do
	{
		printf("Digite la cantidad de empleados que deceas registrar: ");
		fflush(stdin);
		scanf("%u",&largo);
	}while(largo < 0 && largo > 20);
	empleados_t empleado[largo];
	int i;
	for(i = 0; i < largo; i++)
	{
		printf("\n");
		pedir(&empleado[i],i+1);
	}
	
	int salarios[largo];
	for(i = 0; i < largo; i++)
	{
		salarios[i] = empleado[i].salario;
	}
	int n,aux;
	for(i = 0; i < largo; i++)
	{
		aux = salarios[i];
		for(n = i; n > 0 && aux > salarios[n-1]; n--)
		{
			salarios[n] = salarios[n-1];
			salarios[n-1] = aux;
		}
	}
	
	for(i = 0; i < largo; i++)
	{
		if(salarios[0] == empleado[i].salario)
		{
			printf("\n\tEl empelado con el salario mas alto es\n");
			imprimir(empleado[i]);
		}
		else if(salarios[largo-1] == empleado[i].salario)
		{
			printf("\n\tEl empelado con el salario mas bajo es\n");
			imprimir(empleado[i]);
		}
	}
	system("pause");
	return 0;
}
void imprimir(empleados_t e)
{
	printf("Nombre: %s\n",e.nombre);
	printf("Edad: %i\n",e.edad);
	printf("Salario: %u\n",e.salario);
}
void pedir(empleados_t * e, int i)
{
	char preg;
	int n;
	do
	{
		printf("\tRegistre los datos del empleado %i\n",i);
		printf("Nombre: ");
		fflush(stdin);
		gets(e->nombre);
		for(n = 0; n < strlen(e->nombre); n++)
		{
			if(n == 0)
			{
				e->nombre[n] = toupper(e->nombre[n]);
			}
			if(e->nombre[n] == ' ')
			{
				e->nombre[n+1] = toupper(e->nombre[n+1]);
			}
		}
		do
		{
			printf("Edad: ");
			fflush(stdin);
			scanf("%i",&e->edad);
		}while(e->edad < 0 && e->edad > 80);
		
		do
		{
			printf("Salario: ");
			fflush(stdin);
			scanf("%u",&e->salario);
		}while(e->salario < 0);
		
		do
		{
			printf("Desea modificar los datos? (S/N): ");
			fflush(stdin);
			scanf("%c",&preg);
			preg = tolower(preg);
		}while(preg != 's' && preg != 'n');
	}while(preg != 'n');
	
}
