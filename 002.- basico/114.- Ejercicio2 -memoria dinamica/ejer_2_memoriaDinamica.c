/*
	Pedir una cadena de caracteres al usuario, posteriormente utilizar malloc para reservar memoria 
	para esa cadena de caracteres
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char nombre[20], * p_nombre;
	unsigned int longitud;
	printf("Digite su nombre: ");
	fflush(stdin);
	fgets(nombre,20,stdin);
	
	longitud = strlen(nombre);
	p_nombre = (char *)malloc((longitud+1)*sizeof(char));
	
	fprintf(stdout,"%s\n",p_nombre);
	
	system("pause");
	return 0;
}










