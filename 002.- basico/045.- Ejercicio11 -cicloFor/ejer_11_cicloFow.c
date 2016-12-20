//Suma de factoriales

#include<stdio.h>

int main()
{
	int i,num,suma = 0;
	printf("Ingrese el numero: ");
	fflush(stdin);
	scanf("%i",&num);
	if(num < 0) printf("El factorial debe ser un entero\n");
	while(num < 0)
	{
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("%i",&num);
	}
	
	for(i = 0; i <= num; i++)
	{
		suma += i;
	}
	
	printf("El factorial de %i es: %i",num,suma);
	
	return 0;
}
