/*Sumar 2 matrices, pidiendo al usuario el numero de filas y columnas, ademas perirle
los elementos de cada matriz, luego mostrar el resultado*/


#include<stdio.h>

int main()
{
	size_t filas1;
	size_t colum1;
	printf("Cuantas filas decea en su matriz numero 1?: ");
	scanf("%i",&filas1);
	printf("Cuantas columnas decea en su matriz numero1?: ");
	fflush(stdin);
	scanf("%i",&colum1);
	
	size_t filas2;
	size_t colum2;
	printf("Cuantas filas decea en su matriz numero 2?: ");
	scanf("%i",&filas2);
	printf("Cuantas columnas decea en su matriz numero2?: ");
	fflush(stdin);
	scanf("%i",&colum2);
	
	int matriz1[colum1][filas1],matriz2[colum2][filas2];
	
	printf("\tIngrese los valores de su primera matriz\n");
	int c = 0,f;
	for(f = 0; f <= filas1; f++)
	{
		if(f == filas1)
		{
			f = 0;
			if(c == colum1-1)
			{
				break;
			}
			else c++;
		}
		printf("Ingrese el valor de matriz1[%i][%i]: ",c,f);
		fflush(stdin);
		scanf("%i",&matriz1[c][f]);
	}
	
	printf("\tIngrese los valores de la segunda matriz\n");
	c = 0;
	for(f = 0; f <= filas2; f++)
	{
		if(f == filas2)
		{
			f = 0;
			if(c == colum2-1)
			{
				break;
			}
			else c++;
		}
		printf("Ingrese el valor de matriz2[%i][%i]: ",c,f);
		fflush(stdin);
		scanf("%i",&matriz2[c][f]);
	}
	
	c = 0;
	for(f = 0; f <= filas1; f++)
	{
		if(f == filas1)
		{
			f = 0;
			if(c == colum1-1)
			{
				break;
			}
			else c++;
		}
		printf("El valor de matriz1[%i][%i]\t->\t%i\n",c,f,matriz1[c][f]);
	}
	
	c = 0;
	printf("\n");
	for(f = 0; f <= filas1; f++)
	{
		if(f == filas1)
		{
			f = 0;
			if(c == colum1-1)
			{
				break;
			}
			else c++;
		}
		printf("El valor de matriz2[%i][%i]\t->\t%i\n",c,f,matriz2[c][f]);

	}
	return 0;
}
