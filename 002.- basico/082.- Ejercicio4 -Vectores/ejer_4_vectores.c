/*Hacer 2 arrays de cadenas de caracteres, almacena dos nombres cada uno dentro de su respectova variable, y 
luego intercambiar el contenido de las variables*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void intercambiar(char *n1, char *n2);

int main()
{
	char nombre1[20],nombre2[20];
	printf("Digite el primer nombre: ");
	fflush(stdin);
	gets(nombre1);
	
	printf("Digite el segundo nombre: ");
	fflush(stdin);
	gets(nombre2);
	
	printf("nombre1\t->\t%s\n",nombre1);
	printf("nombre2\t->\t%s\n",nombre2);
	
	intercambiar(nombre1,nombre2);
	
	printf("nombre1\t->\t%s\n",nombre1);
	printf("nombre2\t->\t%s\n",nombre2);
	return 0;
}

void intercambiar(char *n1, char *n2)
{
	char nombre_intermediario[20];
	int i = 0;
	while(n1[i] != '\0')
	{
		nombre_intermediario[i] = n1[i];
		i++;
	}
	
	i = 0;
	while(n2[i] != '\0')
	{
		n1[i] = n2[i];
		i++;
	}
	
	i = 0;
	while(nombre_intermediario[i] != '\0')
	{
		n2[i] = nombre_intermediario[i];
		i++;
	}
}













