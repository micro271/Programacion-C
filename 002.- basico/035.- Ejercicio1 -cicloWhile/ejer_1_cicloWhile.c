//Suma los n primeros numeros

#include<stdio.h>

int main()
{
	int numero,cont,suma = 0;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&numero);
	
	cont = 0;
	while(cont <= numero)
	{
		suma += cont;
		cont++;
	}
	printf("La suma es de: %i",suma);
	return 0;
}
