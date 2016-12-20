#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
	void *n = calloc(20,sizeof(char));
	char *nombre;
	nombre = (int *)n;
	fprintf(stdout,"Digite su nombre: ");
	fgets(nombre,19,stdin);
	void *new_n = realloc(nombre,sizeof(char)*(strlen(nombre)+1));
	nombre = (int *)new_n;

	fprintf(stdout,"Nombre ingresado: %s\n",nombre);
	int i;
	for(i = 0; nombre[i] != '\0'; i++)
	{
		if(isalnum(nombre[i]))
		{
			if(isalpha(nombre[i]))
			{
				fprintf(stdout,"El elemento '%c' es alfanumerico y alfabetico\n",nombre[i]);
			}
			else
			{
				fprintf(stdout,"El elemento '%c' es alfanumerico\n",nombre[i]);
			}
		}
	}
	free(nombre);
	system("pause");
	return 0;
}
