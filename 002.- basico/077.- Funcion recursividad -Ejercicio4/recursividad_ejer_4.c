/* Invertir un numero entero con recursividad */

#include<stdio.h>
int invertir(int n);
int main()
{
	int n;
	do{
		printf("Digite un numero: ");
		fflush(stdin);
		scanf("%i",&n);
	}while(n < 0);
	
	invertir(n);
	return 0;
}
/*
100 % 10 = 1;
10 % 10 = 0;
0 % 10 = 0;

*/
int invertir(int n)
{
	printf("%i",n%10);
	//Case base
	if(n > 10)
	{
		invertir(n/10);
	}
}
