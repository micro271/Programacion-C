/*
	Hacer una estructura llamada alumno, en la cual contendra los siguientes miembros: nombre, edad,
	promedio, Pedir datos al usuario para 3 alumnos, comprobar cual de los 3 alumnos tiene el mejro
	promedio y posteriormente imprimir los datos del alumno
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char nombre[20];
	unsigned int edad;
	unsigned int promedio;
}alumno;
void pedir(alumno *a);
void imprimir(alumno a);
int main()
{
	int i;
	alumno a[3];
	for(i = 0; i < 3; i++)
	{
		if(i != 0) printf("\n\n");
		pedir(&a[i]);
	}
	if(a[0].promedio > a[1].promedio && a[0].promedio > a[2].promedio)
	{
		imprimir(a[0]);
	}
	else if(a[1].promedio > a[2].promedio && a[1].promedio > a[0].promedio)
	{
		imprimir(a[1]);
	}
	else if(a[2].promedio > a[0].promedio && a[2].promedio > a[1].promedio)
	{
		imprimir(a[2]);
	}
	system("pause");
	return 0;
}

void pedir(alumno *a)
{
	int i;
	printf("Nombre y Apellido: ");
	fflush(stdin);
	gets(a->nombre);
	for(i = 0; i <= strlen(a->nombre); i++)
	{
		if(i == 0) a->nombre[0] = toupper(a->nombre[0]);
		if(a->nombre[i] == ' ')
		{
			a->nombre[i+1] = toupper(a->nombre[i+1]);
		}
	}
	
	do
	{
		printf("Edad: ");
		fflush(stdin);
		scanf("%u",&a->edad);
		if(a->edad < 0) printf("no existen edades negativas\n");
		else if(a->edad > 100) printf("ya deberias estar muerto\n");
	}while(a->edad < 0 && a->edad > 100);
	
	int todas_las_eval = 0;
	int promedio;
	unsigned int largo_parciales;
	
	char preg;
	do{
		printf("Ya tienes el promedio de tu estado academico (S/N)?: ");
		fflush(stdin);
		scanf("%c",&preg);
		preg = tolower(preg);
	}while(preg != 's' && preg != 'n');
	
	if(preg == 's')
	{
		do
		{
			printf("Digite el promedio: ");
			fflush(stdin);
			scanf("%u",&a->promedio);
		}while(a->promedio < 0 || a->promedio > 100);
	}
	else if(preg == 'n')
	{
		do{
			printf("Cuantos parciales tuviste?: ");
			fflush(stdin);
			scanf("%u",&largo_parciales);
		}while(largo_parciales < 0 || largo_parciales > 5);
		
		int parciales[largo_parciales];
		for(i = 0; i < largo_parciales; i++)
		{
			do{
				printf("Parcial %i nota: ",i+1);
				fflush(stdin);
				scanf("%i",&parciales[i]);
			}while(parciales[i] < 0 && parciales[i] > 100);
		}
		for(i = 0; i < largo_parciales; i++)
		{
			todas_las_eval += parciales[i];
		}
		promedio = todas_las_eval/largo_parciales;
		a->promedio = promedio;
	}
}

void imprimir(alumno a)
{
	printf("\tDatos del alumno con mayor promedio\n");
	printf("Nombre\t->\t%s\n",a.nombre);
	printf("Edad\t->\t%u\n",a.edad);
	printf("promedio\t->\t%u\n",a.promedio);
}
