/*Hacer un programa que muestre una tabla de multiplicacion hasta el 20 de 1 numero cualquiera en pantalla 
, el numero se pedira en el programa principal. Usar procedimiento*/

#include<stdio.h>
void tablaMult(int num);
int main()
{
	int num;
	printf("\tQue tabla de multiplicar quiere saber?\n");
	do
	{
		printf("\nDigite que tabla quiere saber: ");
		fflush(stdin);
		scanf("%i",&num);
	}while(num < 0);
	tablaMult(num);
	return 0;
}

void tablaMult(int num)
{
	int i,tabla;
	for(i = 1; i <= 10; i++)
	{
		tabla = num * i;
		printf("%i x %i = %i\n",num,i,tabla);
	}
}















