/*
	 Determinar si un n�mero es primo o no; con puteros y adem�s indicar en que posici�n de memoria se guard� 
	 el n�mero.
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
