/*Hace run progama que imprima la suma de todos los numeros pares que hay desde 1
hasta n y diga cuantos numeros hay*/


#include <stdio.h>

int main()
{
	int i, num, cont = 0, suma = 0;
	
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%i",&num);
	
	for(i = 1; i <= num; i++)
	{
		if(num%2==0)
		{
			suma += i;
			cont++;
		}
	}
	printf("la suma de los numeros pares es: %i y la cantidad de numeros sumados es: %i",suma,cont);
	
	return 0;
}
