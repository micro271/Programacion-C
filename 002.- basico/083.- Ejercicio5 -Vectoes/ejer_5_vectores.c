/*Realizar un programa que lea un array, el sexo de los n estudiantes del curso de algoritmos 
y que determine cuantos nombres y mujeres se encuentran en el grupo , suponiendo que los datos
son extraidos alumno por alumno*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void minusculas(char * n);
int main()
{
	int i, alumnos;
	int varon = 0;
	int femenino = 0;
	char sexo[30];
	do
	{
		printf("Digite el numero de alumnos en la clase: ");
		fflush(stdin);
		scanf("%i",&alumnos);
	}while(alumnos < 0);
	
	for(i = 0; i < alumnos; i++)
	{
		printf("\n%i. Digite el sexo del alumn@: ",i+1);
		fflush(stdin);
		gets(sexo);
		minusculas(sexo);
		if(strcmp(sexo,"masculino") == 0)
		{
			varon++;
		}
		else if(strcmp(sexo,"femenino") == 0)
		{
			femenino++;
		}
	}
	
	printf("El total de varones es: %i\n",varon);
	printf("El total de mujeres es: %i",femenino);
	return 0;
}

void minusculas(char * n)
{
	int i = 0;
	while(n[i] != '\0')
	{
		n[i] = tolower(n[i]);
		i++;
	}
}



