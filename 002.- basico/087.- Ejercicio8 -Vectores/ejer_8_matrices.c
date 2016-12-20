/*Hacer una matriz del tipo entera de 2 * , llenarla de numeros y luego copiar todo su contenido
hacia otra matriz*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m1[2][2],m2[2][2];
	int f, c = 0;
	printf("Digite los valores que quiera guardar en nuestra matriz\n");
	for(f = 0; f < 3; f++)
	{
		if(f == 2)
		{
			f = 0;
			if(c == 1)
			{
				break;
			}
			else c++;
		}
		
		printf("Digite el valor que desea guardar en [%i],[%i]: ",c,f);
		fflush(stdin);
		scanf("%i",&m1[c][f]);
	}
	
	for(c = 0; c < 2 ; c++)
	{
		for(f = 0; f < 2 ; f++)
		{
			printf("El valor de la matriz m1[%i][%i] es\t->\t%i\n",c,f,m1[c][f]);
		}
	}
	f = 0;
	c = 0;
	for(f = 0; f <= 2; f++)
	{
		if(f == 2)
		{
			f = 0;
			if(c == 1)
			{
				break;
			}
			else c++;
		}
		m2[c][f] = m1[c][f];
	}
	f = 0;
	c = 0;
	printf("\n\n");
	for(c = 0; c < 2; c++)
	{
		for(f = 0; f < 2; f++)
		{
			printf("El valor de la matriz m2[%i][%i] es\t->\t%i\n",c,f,m2[c][f]);
		}
	}
}
