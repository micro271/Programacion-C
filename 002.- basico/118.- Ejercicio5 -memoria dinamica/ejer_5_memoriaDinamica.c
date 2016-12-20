/*
	**Reservar espacio en memoria dinámica para un nombre, y luego liberar la memoria utilizada con free.
*/

#include<stdio.h>
#include"stdlib.h"
#include<string.h>
int main()
{
	char nombre[20];
	unsigned int i, longitud;
	fprintf(stdout,"Digite su nombre: ");
	fflush(stdin);
	fgets(nombre,18,stdin);
	longitud = strlen(nombre);
	fprintf(stdout,"%i\n",longitud);
	fprintf(stdout,"%i\n",longitud*sizeof(char));

	char *nombre_d = (char *)malloc((longitud+1)*sizeof(char));
	for(i = 0; nombre[i] != '\0'; i++)
	{
		nombre_d[i] = nombre[i];
		printf("%i\n",i);
	}
	nombre_d[i] = '\0';	
	fprintf(stdout,"%s\n",nombre_d);
	
	free(nombre_d);
	
	fprintf(stdout,"%s\n",nombre_d);
	system("pause");
	return 0;
}
