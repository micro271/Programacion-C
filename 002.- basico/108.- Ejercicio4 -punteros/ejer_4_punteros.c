/*
	 Determinar si un número es primo o no; con puteros y además indicar en que posición de memoria se guardó 
	 el número.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,contador = 0,i;
	int *n_p = &n;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&n);
	

	for(i = *n_p; i > 0; i--)
	{
		if(*n_p%i == 0)
		{
			contador++;
		}
	}
	if(contador == 2)
	{
		printf("El numero %i es primo\n",*n_p);
	}
	else printf("El numero %i no es primo\n",*n_p);
	printf("Posicion de memoria\t-> %p",n_p);
	return 0;
}
