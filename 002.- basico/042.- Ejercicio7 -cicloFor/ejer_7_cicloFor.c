//Suma de los 10 primeros numeros pares

#include<stdio.h>

int main()
{
	int i,suma = 0;
	
	for(i = 0; i <= 100; i+=2)
	{
		suma += i;
	}
	printf("la suma de los 10 primeros numeros pares es: %i",suma);
	
	return 0;
}
