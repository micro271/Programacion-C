/*
	**Reservar memoria dinámica para una cadena de caracteres de 10 espacios, luego utilizar realloc 
	para ampliar la memoria dinámica a 30 espacios
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *nombre,*nombre_completo;
	nombre = (char *)calloc(10,sizeof(char));
	if(nombre == NULL)
	{
		fprintf(stdout,"No hay espacio en memoria\n");
	}
	else
	{
		fprintf(stdout,"Se asigno a la memoria exitosamente\n");
	}
	
	strcpy(nombre,"Manuel");
	fprintf(stdout,"nombre: %s\n",nombre);
	nombre_completo = realloc(nombre,sizeof(char)*30);
	strcat(nombre_completo," Matias Zelaya");
	
	fprintf(stdout,"nombre: %s\n",nombre_completo);
	free(nombre_completo);
	system("pause");
	return 0;
}
