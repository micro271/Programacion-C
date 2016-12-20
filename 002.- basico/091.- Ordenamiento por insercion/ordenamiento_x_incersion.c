/*
	**Ordenamiento por insercion	-> es una manera muy natural de ordenar para un ser humano 
	y peude usarse para ordenar un mazo de cartas numeradas de forma arbitraria. Requiere O(n2)
	operadores para ordenar una lista de n elementos 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	size_t largo;
	do
	{
		printf("Digite la cantidad de elementos que decea ingresar: ");
		fflush(stdin);
		scanf("%i",&largo);
	}while(largo < 0);
	
	int matriz[largo];
	int i;
	for(i = 0; i < largo; i++)
	{
		printf("Digite el elemento matriz[%i]\t->\t",i);
		fflush(stdin);
		scanf("%i",&matriz[i]);
	}
	for(i = 0; i < largo; i++)
	{
		printf("matriz[%i]\t->\t%i\n",i,matriz[i]);
	}
	printf("\t\nmi ordenamiento incersion");
	int m,aux,pos;
	for(i = 0; i < largo; i++)
	{
		aux = matriz[i];
		for(m = i; m > 0 && aux > matriz[m-1]; m--)
		{
			matriz[m] = matriz[m-1];
			matriz[m-1] = aux;
		}
	}
		
	printf("\n");
	for(i = 0; i < largo; i++)
	{
		printf("matriz[%i]\t->\t%i\n",i,matriz[i]);
	}
	
	


	system("pause");
	return 0;
}
