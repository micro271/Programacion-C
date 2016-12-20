#include <stdio.h>

int main(void)
{
	char cadena[40];
	char cadena2[40];
	printf("Ingresa tu anime faborito: ");
	fflush(stdin);
	scanf("%[^\n]s",&cadena);
	printf("\nLa cadena es %s\n",cadena);
	
	printf("Ingresa otra cadena: ");
	fflush(stdin);
	gets(cadena2);
	printf("\n La cadena es: %s",cadena2);
	
	return 0;
}
