#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i,k;
	char nombre[10];
	do
	{
		printf("Escriba su nombre: ");
		fflush(stdin);
		gets(nombre);
	}while(strlen(nombre) > 9);
	
	printf("%s,%i\n	",nombre,strlen(nombre));
	char* nombre_p = (char* )malloc(sizeof(char)*strlen(nombre)+1);	//CON PUNTERO
	memmove(nombre_p,nombre,strlen(nombre)+1);
	printf("\n%s COMO ESTAS CAMPEON\n",nombre_p);
	
	char nombre_n[strlen(nombre)+1];
	memmove(nombre_n,nombre,strlen(nombre)+1);
	printf("%s, %i",nombre_n,strlen(nombre_n));
	return 0;
}
