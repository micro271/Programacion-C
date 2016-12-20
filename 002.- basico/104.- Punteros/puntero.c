#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char **nombres;
	int *miembros;
}family;

int main(int argc,char **argv)
{
	int i;
	
	//RSERVAR MEMORIA PARA UN INT
	int *puntero_int = NULL;
	puntero_int = (int *)malloc(sizeof(int));
	*puntero_int = 125;
	printf("*puntero_int(ANTES DE LIBERAR): %i\n",*puntero_int);
	free(puntero_int);
	printf("*puntero_int(DESPUES DE LIBERAR): %i\n\n",*puntero_int);
	
	
	//RESERVAR MEMORIA PARA UN VECTOR
	int *puntero_vector = NULL;
	puntero_vector = (int *)malloc(5*sizeof(int));
	for(i = 0; i < 5; i++)
		*(puntero_vector+i) = i * 5;
	printf("\nANTES DE LIBERAR puntero_vector:\n");
	for(i = 0; i < 5; i++)
		printf("*(puntero_vector+%i): %i\n",i,*(puntero_vector+i));
	printf("\n\nDRESPUES DE LIBERAR puntero_vector\n");
	free(puntero_vector);
	for(i = 0; i < 5; i++)
		printf("*(puntero_vector+%i): %i\n",i,*(puntero_vector+i));
		


	/*			STRINGS			*/
	char *str;
	str = (char *)malloc(20*sizeof(char));
	strcpy(str,"HOLA MUNDO");//NO SE PUEDE GUARDAR STRING COMO STR = "HOLA MUNDO"; ESTO DARIA A UN ERROR;
	printf("\nstr(ANTES DE LIBERAR): %s",str);
	free(str);
	printf("\nstr(DESPUES DE LIBERAR): %s",str);
	
	
	/*			MATRICES			*/
	int **elementos = NULL;int x;
	elementos = (int **)malloc(sizeof(int *)*5);
	
	for(i = 0; i < 5; i++)
		*(elementos+i) = (int *)malloc(sizeof(int)*3);
	
	for(i = 0; i < 5; i++)
		for(x = 0; x < 3; x++)
			*(*(elementos+i)+x) = 10;
	
	printf("\n\nMATRICES ANTES DE LIBERAR:");
	for(i = 0; i < 5; i++)
		for(x = 0; x < 3; x++)
		{
			if(x == 0)
				printf("\n%i , ",*(*(elementos+i)+x));
			else if(x == 1)
				printf("%i, ",*(*(elementos+i)+x));
			else
				printf(" %i\n",*(*(elementos+i)+x));
		}
	for(i = 4; i >= 0; i--)
		free(*(elementos+i));
		
	free(elementos);
	printf("\n\nMATRICES DESPUES DE LIBERAR:");
	for(i = 0; i < 5; i++)
		for(x = 0; x < 3; x++)
		{
			if(x == 0)
				printf("\n%i , ",*(*(elementos+i)+x));
			else if(x == 1)
				printf("%i, ",*(*(elementos+i)+x));
			else
				printf(" %i\n",*(*(elementos+i)+x));
		}
	
	return EXIT_SUCCESS;
}


















