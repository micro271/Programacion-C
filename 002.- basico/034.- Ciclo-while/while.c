/*
	**Ciclo while;
	
	while(condicional)
	{
		Codigo
	}
*/

#include <stdio.h>


int main()
{
	int i = -5;
	printf("\t\tCreciente\n");
	while(i <= 5)
	{
		printf("\t%i.",i);
		i++;
	}
	
	printf("\n\t\tDecreciente\n");
	int a = 5;
	while(a >= -5)
	{
		printf("\t%i",a);
		a--;
	}
	return 0;
}

