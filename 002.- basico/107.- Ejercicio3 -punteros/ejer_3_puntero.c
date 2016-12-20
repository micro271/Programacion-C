/*
	 Imprimir el alfabeto en mayúscula con Punteros
*/

#include<stdio.h>

int main()
{
	char letra;
	char * letra_p = &letra;
	for(letra = 'A'; letra <= 'Z'; letra++)
	{
		if(letra == 'Z')
		{
			printf("%c",*letra_p);
		}
		else printf("%c, ",*letra_p);
	}
	return 0;
}
