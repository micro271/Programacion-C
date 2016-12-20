#include<stdio.h>

int main(void)
{
	size_t largo;
	printf("Cuantos numeros quieres ingresar ");
	fflush(stdin);
	scanf("%i",&largo);
	fflush(stdin);
	int numeros[largo];
	int i;
	int suma;
	printf("Ingresa los numeros que quieres sumar \n");
	for(i = 0; i < largo;i++)
	{
		printf("Ingresa el numero de la posicion %i: ",i);
		fflush(stdin);
		scanf("%d",&numeros[i]);
		fflush(stdin);
	}
	i = 0;
	while(i < largo)
	{
		printf("\nEl numero de la posicion %i que elegiste es: %d \n",i,numeros[i]);
		i++;
	}
	suma = 0;
	for(i = 0; i < largo; i++)
	{
		suma += numeros[i];
	}
	printf("\nLa suma de todos los numeros es: %d",suma);
}
