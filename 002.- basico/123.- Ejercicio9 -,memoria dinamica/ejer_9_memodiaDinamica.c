//Reservar un espacio de memoria con callor para una cadena de caracteres
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	void *n = calloc(50,sizeof(char));
	char *nombre = (char *)n;
	fprintf(stdout,"Nombre: ");
	fgets(nombre,49,stdin);
	void *new_n = realloc(nombre,strlen(nombre)+1);
	nombre = (char *)new_n;
	
	fprintf(stdout,"%s",nombre);
	system("pause");
	return 0;
}
