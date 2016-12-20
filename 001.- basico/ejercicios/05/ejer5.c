#include <stdio.h>

int main(void)
{
	int numeros[8];
	int i;
	int suma;
	printf("Ingresa 8 numeros separados: \n");
	i = 0;
	while(i < 8)
	{
		printf("Ingresa elnumero de la posicion %i: ",i);
		fflush(stdin);
		scanf("%i",&numeros[i]);
		fflush(stdin);
		i++;
	}
	suma = 0;
	for(i = 0; i <= 8; i++)
	{
		suma += numeros[i];
	}
	printf("La suma de todos los numeros es: %d",suma);
	return 0;
}
