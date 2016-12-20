/*
	** Funcion recursiva	-> una funcion recursiva es una funcion que se llama a si misma
	
	1. Caseo base;
	2. Caso recursiva;
	
	a(x)
	{
		if(n == 1)
		{
			return n;
		}
		else
		{
			a(x--);	
		}
	}
*/

//Factorial
#include<stdio.h>
long factorial(int n);

int main()
{
	int numero;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&numero);
	
	printf("El factorial del numero es: %li \n",factorial(numero));
	return 0;
}


/*
4! = 4*3!
3! = 3*2!
2! = 2*1!
1! = 1
*/

long factorial(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	else
	{
		return (n*factorial(n-1));
	}
}









