/*
	**Ordenamiento por seleccion
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	size_t largo;
	printf("Digite cuantos elementos decea ingresar: ");
	fflush(stdin);
	scanf("%i",&largo);
	int oXS[largo];
	int i;
	for(i = 0; i < largo; i++)
	{
		printf("El valor de oXS[%i]\t->",i);
		fflush(stdin);
		scanf("%i",&oXS[i]);
	}
	int n,aux,m;
	for(i = 0; i < largo; i++)
	{
		for(n = i+1; n < largo; n++)
		{
			if(oXS[n] > oXS[i])
			{
				aux = oXS[n];
				oXS[n] = oXS[i];
				oXS[i] = aux;
			}
		}
	}
	printf("\n\n");
	for(i = 0; i < largo; i++)
	{
		printf("El valor de oXS[%i]\t->\t%i\n",i,oXS[i]);
	}
	system("pause");
	return 0;
}
