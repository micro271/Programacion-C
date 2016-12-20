/*
	**Metodo burbuja	->	Es un sencillo algoritmo de ordenamiento. Funciona revisando
	cada elemento de la lista que va a ser ordenada con el siguiente, cambiandolos de
	posicion si estan en un orden equiboco. Es necesario revisar varias veces las listas hasta
	que no se necesiten mas intercambios, lo cual significa que la lista esta ordenada.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	size_t largo;
	printf("Digite la cantidad de numeros que quieres ordenar: ");
	scanf("%i",&largo);
	int array[largo],i,n;
	for(i = 0; i < largo; i++)
	{
		printf("Digite el valor de la array[%i]\t->\t ",i);
		fflush(stdin);
		scanf("%i",&array[i]);
	}
	
	for(i = 0; i < largo; i++)
	{
		printf("array[%i]\t->\t%i\n",i,array[i]);
	}
	//mayor a menor
	int c,aux;
	for(i = 0; i < largo; i++)
	{
		for(c = 1; c < largo; c++)
		{
			if(array[c] >= array[c-1])
			{
				aux = array[c];
				array[c] = array[c-1];
				array[c-1] = aux;
			}
		}
	}
	
	printf("\n\tVamos a ordenar de menor a mayor\n");
	for(i = 0; i < largo; i++)
	{
		printf("array[%i]\t->\t%i\n",i,array[i]);
	}
	
	system("pause");
	return 0;
}





