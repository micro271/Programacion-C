/*
	Comprobar si un n�mero es par o impar, y se�alar la posici�n de memoria donde se est� guardando 
	el n�mero. Con punteros.
*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n,* n_p;
	n_p = &n;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&n);
	if(n % 2 == 0)
	{
		printf("El numero %i\t-> es par\n",*n_p);
	}
	else printf("El numero %i\t-> es impar\n",*n_p);
	printf("Posicion de memoria\t-> %p\n",n_p);
	
	system("pause");
	return 0;
}
