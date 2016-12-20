/*Realizar un programa que permita leer una cadena de caracteres y que debuelva el numero de caracteres que 
dicha cadena e imprima la dicha cadena al reves*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct strings{
	
}prop_str;

int cantidad_de_letras(char *palabra);
int al_revez(char *cadena);
int main()
{
	char nombre[20];
	printf("Digite su nombre: ");
	fflush(stdin);
	gets(nombre);
	
	printf("%i\n",len(nombre));
	
	printf("%s",al_revez(nombre));
	return 0;
}

int al_revez(char *cadena)
{
	int i,x = 0;
	char cNueva[20];
	for(i = len(cadena) - 1; i >= -1; i--)
	{
		if(i == -1)
		{
			cNueva[x] = '\0';
			break;
		}
		cNueva[x] = cadena[i];
		x++;
	}
	return cNueva;
}

int len(char *palabra)
{
	int i = 0;
	while(palabra[i] != '\0')
	{
		if(palabra[i] != '\0')
		{
			i++;
		}
		else i--;
	}
	return i;
}















