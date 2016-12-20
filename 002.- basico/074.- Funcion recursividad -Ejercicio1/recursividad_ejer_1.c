//Serie fibonacci con recursividad

#include<stdio.h>
int fibonacci(int n);
int main()
{
	int num,i;
	printf("Digite el numero de elementos: ");
	fflush(stdin);
	scanf("%i",&num);
	
	for(i == 1; i <= num; i++)
	{
		printf("%i, ",fibonacci(i));
	}
	return 0;
}

/*
	1 1 2 3 5 8..
	fibonacci(1) = 1;
	fibonacci(n) = n;
*/


int fibonacci(int n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return (fibonacci(n-2) + fibonacci(n-1));
	}
	
}
