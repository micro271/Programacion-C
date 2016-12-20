/*Crear un programa que tenga un array de 100 numeros aleatorios entre el 1 y el 1000.
Una vez creado organizarlo de tal manera que almacene los numeros pares en un array y los impares en otro array*/

#include<stdio.h>
#include<time.h>



int main()
{
	int x;
	srand(time(NULL));
	
	int vector_par[100],contador_par = 0;
	int vector_impar[100],contador_impar = 0;
	
	while(contador_par < 99 || contador_impar < 99)
	{
		x = 0 + rand() % ((1000 + 1) - 1);
		if(x%2 == 0)
		{
			if(contador_par == 100)
			{
				continue;
			}
			else
			{
				vector_par[contador_par] = x;
				contador_par++;
			}
		}
		else if(x%2 != 0)
		{
			if(contador_impar == 100)
			{
				continue;
			}
			else
			{
				vector_impar[contador_impar] = x;
				contador_impar++;
			}			
		}
	}
	int i;
	
	for(i = 0; i < 100; i++)
	{
		printf("%i\t->\t%i\n",vector_par[i],vector_par[i]%2);
	}
	printf("\n");
	for(i = 0; i < 100; i++)
	{
		printf("%i\t->\t%i\n",vector_impar[i],vector_impar[i]%2);
	}
	
	return 0;
}


