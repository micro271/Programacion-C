/*
	 Pedir su nombre al usuario y devolver el número de vocales que hay;
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void vocales(char *);
int main(void)
{
	char nombre[30];
	printf("Digite su apellido: ");
	fflush(stdin);
	fgets(nombre,30,stdin);
	
	vocales(&nombre[0]);	
	system("pause");
	return 0;
}

void vocales(char *s)
{
	int i, cont = 0;
	for(i = 0; s[i] != '\0'; i++)
	{
		s[i] = tolower(s[i]);
	}
	printf("%s\n",s);
	for(i = 0; s[i] != '\0'; i++)
	{
		switch(s[i])
		{
			case 'a': cont++;break;
			case 'e': cont++;break;
			case 'i': cont++;break;
			case 'o': cont++;break;
			case 'u': cont++;break;
		}
	}
	printf("La cantidad e bocales que tiene el string es %i\n",cont);
}
